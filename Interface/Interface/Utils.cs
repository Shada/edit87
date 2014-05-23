﻿using System;
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

				public PanelStruct(DockContent _panel, string _name)
				{
					m_panel = _panel;
					m_name = _name;
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
			}

			private static List<PanelStruct> panels = new List<PanelStruct>();

			public static void addPanel(DockContent _panel, string _name)
			{
				panels.Add(new PanelStruct(_panel, _name));
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

			public static void destroy()
			{
				foreach (PanelStruct p in panels)
				{
					if (p.Panel != null)
						p.Panel.Close();
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

			public static void Sethandle(IntPtr _handle, string _name)
			{
				graphics.setHandle(_handle, _name);
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
