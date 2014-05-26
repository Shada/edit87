using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ComponentModel;
using System.Drawing;
using System.IO;
using System.Xml;
using System.Globalization;
using WeifenLuo.WinFormsUI.Docking;
using wrap;

namespace LevelEditor
{
	public static class Utils
	{
		private static XmlDocument projectFile;
		private static DirectoryInfo projectDirectory;
		private static string projectName;

		public static XmlDocument ProjectFile 
		{ 
			get 
			{
				if (projectFile == null)
				{
					projectFile = new XmlDocument();
				}

				return projectFile; 
			}
			set { projectFile = value; }
		}
		public static DirectoryInfo ProjectDirectory 
		{ 
			get { return projectDirectory; }
			set { projectDirectory = value; }
		}
		public static string ProjectName
		{
			get { return projectName; }
			set { projectName = value; }
		}

		public static class Panels
		{
			public struct PanelStruct
			{
				private DockContent m_panel;
				private string m_name;
                private ToolStripMenuItem m_toolMenuItem;

				public PanelStruct(DockContent _panel, string _name, ToolStripMenuItem _toolMenuItem)
				{
					m_panel = _panel;
					m_name = _name;
                    m_toolMenuItem = _toolMenuItem;
				}

				public DockContent Panel
				{
					get { return m_panel; }
					set { m_panel = value; }
				}

				public string Name
				{
					get { return m_name; }
					set { m_name = value; }
				}

                public ToolStripMenuItem toolMenuItem
                {
                    get { return m_toolMenuItem; }
                    set { m_toolMenuItem = value; }
                }
			}

			private static List<PanelStruct> panels = new List<PanelStruct>();

			public static void addPanel(DockContent _panel, string _name, ToolStripMenuItem _toolMenuItem)
			{
				panels.Add(new PanelStruct(_panel, _name, _toolMenuItem));
			}

			public static IDockContent getpanelByName(string _name)
			{
				foreach (PanelStruct p in panels)
				{
					if (p.Name == _name)
					{
						return p.Panel;
					}
				}

				return null;
			}

            public static void updateToolStrips()
            {
                foreach (PanelStruct p in panels)
                {
                    if (p.Panel != null && p.toolMenuItem != null)
                    {
                        if (!p.Panel.IsDisposed)
                            p.toolMenuItem.Checked = true;
                        else
                            p.toolMenuItem.Checked = false;
                    }
                }
            }

            public static void removePanel(string _name)
            {
                for (int i = panels.Count - 1; i >= 0; i--)
                {
                    if (_name == panels[i].Name)
                    {
                        panels[i].toolMenuItem.Checked = false;
                        panels.RemoveAt(i);
                    }
                }
            }

            public static void destroy()
			{
                for (int i = panels.Count-1; i >= 0 ; i--)
                {
                    if (panels[i].Panel != null)
                    {
                        //panels[i].toolMenuItem.Checked = false;
                        panels[i].Panel.Close();
                    }
                }

				panels.Clear();
			}
		}

		public static class Graphics
		{
			private static wrap.GraphicsCommunicator graphics;

			public static void Init()
			{
				graphics = new GraphicsCommunicator();
			}

			public static void Addhandle(IntPtr _handle, string _name, int _width, int _height)
			{
				graphics.addHandle(_handle, _name, _width, _height);
			}

			public static wrap.GraphicsCommunicator gfx
			{
				get { return graphics; }
			}
		}

		public class twTagAttribute
		{
			public enum dataType
			{
				UNDEFINED,
 				STRING,
				INT,
				FLOAT,
				BOOL,
				CHAR
			}

			public dataType dt;
			public object val;
			public string name;

			public twTagAttribute(dataType _dt, string _name, object _val)
			{
				dt = _dt;
				name = _name;
				val = _val;
			}

			public twTagAttribute()
			{
				dt = dataType.UNDEFINED;
				val = null;
				name = "N/A";
			}
		}

		public class twTag
		{
			public enum TYPE
			{
				UNDEFINED,
				FOLDER,
				IMAGE,
				MESH,
				SOUND
			}

			private TYPE type;
			private List<twTagAttribute> attributes;

			public twTag(TYPE _type)
			{
				type = _type;
				attributes = new List<twTagAttribute>();
			}

			public TYPE Type { get { return type; } }

			public List<twTagAttribute> Attributes { get { return attributes; } }

			public void addAttribute(twTagAttribute.dataType _dt, string _name, object _val)
			{
				attributes.Add(new twTagAttribute(_dt, _name, _val));
			}

			public T getAttributeByName<T>(string _name)
			{
				twTagAttribute tag = new twTagAttribute();

				foreach (twTagAttribute ta in attributes)
				{
					if (ta.name == _name)
					{
						tag = ta;
						break;
					}
				}

				return (T)tag.val;
			}
		}
	}
}
