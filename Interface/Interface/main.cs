using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Xml;
using System.Diagnostics;
using WeifenLuo.WinFormsUI.Docking;
using System.Globalization;

using Microsoft.DirectX;

using wrap;

namespace LevelEditor
{
    //public struct ToolViewOption
    //{
    //    string toolName; //tool name without the "levelEditor." part
    //    ToolStripMenuItem toolMenuItem = null;

    //    public ToolViewOption(string _toolName, ToolStripMenuItem _menuItem)
    //    {
    //        this.toolMenuItem = _menuItem;
    //        this.toolName = _toolName;
    //        IDockContent panel = Utils.Panels.getpanelByName("LevelEditor." + _toolName);
    //        if (panel == null || panel.DockHandler.IsHidden)
    //            toolMenuItem.Checked = false;
    //        else
    //            toolMenuItem.Checked = true;
    //    }
    //}

	public partial class MapEditor : Form
    {
        public const string activeLayoutName = "PanelLayout.xml";

        private bool forwardKey, backwardKey, leftKey, rightKey, leftMouseDown, rightMouseDown;

		private int mousePosX, mousePosY, windowWidth, windowHeight;

        DeserializeDockContent deserializeDockContent;
        public TreeNode resourcesRoot = new TreeNode("Root", 0, 0);

		public MapEditor()
		{
            this.KeyPreview = true;

			InitializeComponent();
            createStandardControls();

			//brushSize = (int)nud_BrushSize.Value;
			//brushIntensity = (int)nud_brushIntensity.Value;

			windowWidth = Size.Width;
			windowHeight = Size.Height;

            deserializeDockContent = new DeserializeDockContent(Utils.Panels.getpanelByName);

            mainDockPanel.LoadFromXml(activeLayoutName, deserializeDockContent);

            timer1.Interval = 20;
            timer1.Start();
		}

		public void initPanels()
		{
			PanResources res = (PanResources)Utils.Panels.getpanelByName("LevelEditor.PanResources");
			res.init(new TreeNode(Utils.ProjectName, 0, 0));

			PanLibrary lib = (PanLibrary)Utils.Panels.getpanelByName("LevelEditor.PanLibrary");
			lib.init(new TreeNode(Utils.ProjectName, 0, 0));

			saveToolStripMenuItem.Enabled = true;
			saveAsToolStripMenuItem.Enabled = true;
			exportToolStripMenuItem.Enabled = true;
		}

        private void createStandardControls()
        {
			Utils.Panels.addPanel(new PanBrushes(),     typeof(PanBrushes).ToString(),      brushToolsToolStripMenuItem);
			Utils.Panels.addPanel(new PanTextures(),    typeof(PanTextures).ToString(),     texturesToolToolStripMenuItem);
			Utils.Panels.addPanel(new PanResources(),   typeof(PanResources).ToString(),    resourcesToolToolStripMenuItem);
			Utils.Panels.addPanel(new PanRender(this),  typeof(PanRender).ToString(),       null);
			Utils.Panels.addPanel(new PanLibrary(),     typeof(PanLibrary).ToString(),      libraryToolStripMenuItem);
			Utils.Panels.addPanel(new PanProperties(),  typeof(PanProperties).ToString(),   propertiesToolStripMenuItem);
        }

		#region events
		private void btn_TerrainBrush_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void btn_TextureBrush_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void lv_Textures_SelectedIndexChanged(object sender, EventArgs e)
		{
            NO();
		}

        private void toolsShortcutsToolStripMenuItem_Click(object sender, EventArgs e)
        {
			hideToolsMenu(sender);
        }

        private void MapEditor_Resize(object sender, EventArgs e)
        {
			resizeWindow();
        }

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			saveProject();
		}

		private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void loadToolStripMenuItem_Click(object sender, EventArgs e)
		{
			loadProject();
		}

		private void exportToolStripMenuItem_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void importBrushesToolStripMenuItem_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void undoToolStripMenuItem_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void redoToolStripMenuItem_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void prefrencesToolStripMenuItem_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void haalpPleaseToolStripMenuItem_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
		{
			About ab = new About();
			ab.Show();
        }

		private void tw_objects_AfterSelect(object sender, TreeViewEventArgs e)
		{
            NO();
		}

		private void nud_BrushSize_ValueChanged(object sender, EventArgs e)
		{
            NO();
		}

		private void btn_importBrush_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void lw_Brush_SelectedIndexChanged(object sender, EventArgs e)
		{
            NO();
		}

		private void btn_importTexture_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void btn_importResource_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void nud_brushIntensity_ValueChanged(object sender, EventArgs e)
		{
            NO();
		}

		private void tw_resources_AfterSelect(object sender, TreeViewEventArgs e)
		{
            NO();
		}

		private void MapEditor_Load(object sender, EventArgs e)
		{
			mapEditorLoad();
		}

		private void mainDockPanel_ActiveContentChanged(object sender, EventArgs e)
		{
			NO();
		}

		private void toolsShortcutsToolStripMenuItem_Click_1(object sender, EventArgs e)
		{
			hideToolsMenu(sender);
		}

		private void brushToolsToolStripMenuItem_Click(object sender, EventArgs e)
		{
            toggleDisplayMenuItems( typeof(PanBrushes) );
		}

		private void resetToDefaultToolStripMenuItem_Click(object sender, EventArgs e)
		{
			panelLayoutReset();
		}

		private void MapEditor_FormClosing(object sender, FormClosingEventArgs e)
		{
			mainDockPanel.SaveAsXml(activeLayoutName);
		}

		private void newProjectToolStripMenuItem_Click(object sender, EventArgs e)
		{
			NewProject project = new NewProject(this);
			project.Show();
		}

		private void MapEditor_MouseUp(object sender, MouseEventArgs e)
		{
			mapEditorMouseUp(e);
		}

		private void MapEditor_MouseMove(object sender, MouseEventArgs e)
		{
			mousePosX = e.X;
			mousePosY = e.Y;
		}

		private void MapEditor_MouseDown(object sender, MouseEventArgs e)
		{
			mapEditorMouseDown(e);
		}

		private void MapEditor_KeyDown(object sender, KeyEventArgs e)
		{
			mapEditorKeyDown(e);
		}

		private void MapEditor_KeyUp(object sender, KeyEventArgs e)
		{
			mapEditorKeyUp(e);
		}

		private void timer1_Tick(object sender, EventArgs e)
		{
			timerTick();
		}

		private void exportPreferencesToolStripMenuItem_Click(object sender, EventArgs e)
		{
			mainDockPanel.SaveAsXml(activeLayoutName);
		}

		private void importPreferencesToolStripMenuItem_Click(object sender, EventArgs e)
		{
			importPrefrences();
		}

		#endregion

		#region non-events

		private void mapEditorMouseDown(MouseEventArgs e)
		{
			if (!rightMouseDown || !leftMouseDown)
			{
				if (!leftMouseDown && e.Button == System.Windows.Forms.MouseButtons.Left)
					leftMouseDown = true;
				else if (!rightMouseDown && e.Button == System.Windows.Forms.MouseButtons.Right)
					rightMouseDown = true;
			}
		}

		private void mapEditorMouseUp(MouseEventArgs e)
		{
			if (rightMouseDown || leftMouseDown)
			{
				if (leftMouseDown && e.Button == System.Windows.Forms.MouseButtons.Left)
					leftMouseDown = false;
				else if (rightMouseDown && e.Button == System.Windows.Forms.MouseButtons.Right)
					rightMouseDown = false;
			}
		}

		private void mapEditorLoad()
		{
			DeserializeDockContent ddc = new DeserializeDockContent(Utils.Panels.getpanelByName);
			mainDockPanel.LoadFromXml(activeLayoutName, ddc);
		}

		private void mapEditorKeyDown(KeyEventArgs e)
		{
			switch (e.KeyCode)
			{
				case Keys.W: forwardKey = true; break;
				case Keys.S: backwardKey = true; break;
				case Keys.A: leftKey = true; break;
				case Keys.D: rightKey = true; break;
			}
		}

		private void mapEditorKeyUp(KeyEventArgs e)
		{
			switch (e.KeyCode)
			{
				case Keys.W: forwardKey = false; break;
				case Keys.S: backwardKey = false; break;
				case Keys.A: leftKey = false; break;
				case Keys.D: rightKey = false; break;
			}
		}

		private void panelLayoutReset()
		{
			mainDockPanel.SuspendLayout(true);
			closeAllDocuments();
			createStandardControls();

			mainDockPanel.DockRightPortion = 200;
			mainDockPanel.DockLeftPortion = 215;

			PanBrushes brush = (PanBrushes)Utils.Panels.getpanelByName("LevelEditor.PanBrushes");
			PanTextures texture = (PanTextures)Utils.Panels.getpanelByName("LevelEditor.PanTextures");
			PanResources resources = (PanResources)Utils.Panels.getpanelByName("LevelEditor.PanResources");
			PanRender render = (PanRender)Utils.Panels.getpanelByName("LevelEditor.PanRender");
			PanLibrary library = (PanLibrary)Utils.Panels.getpanelByName("LevelEditor.PanLibrary");
			PanProperties properties = (PanProperties)Utils.Panels.getpanelByName("LevelEditor.PanProperties");

			brush.Show(mainDockPanel, DockState.DockRight);
			texture.Show(brush.Pane, DockAlignment.Bottom, 0.62);
			resources.Show(texture.Pane, DockAlignment.Bottom, 0.50);
			render.Show(mainDockPanel, DockState.Document);
			library.Show(mainDockPanel, DockState.DockLeft);
			properties.Show(library.Pane, DockAlignment.Bottom, 0.50);

            brushToolsToolStripMenuItem.Checked = true;
            texturesToolToolStripMenuItem.Checked = true;
            resourcesToolToolStripMenuItem.Checked = true;
            libraryToolStripMenuItem.Checked = true;
            propertiesToolStripMenuItem.Checked = true;

			mainDockPanel.ResumeLayout(true, true);
		}

		private void importPrefrences()
		{
			//throw new NotImplementedException("yet to be implemented");
			mainDockPanel.SuspendLayout(true);
			closeAllDocuments();
			createStandardControls();

			//string xmlFile = "PanelLayout.xml";
			//Assembly assembly = Assembly.GetAssembly(typeof(MapEditor));
			//Stream xmlStream = assembly.GetManifestResourceStream(xmlFile);
			mainDockPanel.LoadFromXml(activeLayoutName, deserializeDockContent);

			mainDockPanel.ResumeLayout(true, true);

            Utils.Panels.updateToolStrips();
		}

		private void saveProject()
		{
			PanResources res = (PanResources)Utils.Panels.getpanelByName("LevelEditor.PanResources");
			TreeNode tnRes = res.resourcesRoot;

			PanLibrary lib = (PanLibrary)Utils.Panels.getpanelByName("LevelEditor.PanLibrary");
			TreeNode tnLib = lib.libraryRoot;

			XmlNode root = Utils.ProjectFile.DocumentElement;
			XmlNode xmlHeader = Utils.ProjectFile.SelectSingleNode("/root/header");

			XmlNode xmlResources = Utils.ProjectFile.SelectSingleNode("/root/resources");
			root.RemoveChild(xmlResources);

			XmlElement xmlNewResources = Utils.ProjectFile.CreateElement(null, "resources", null);
			root.InsertAfter(xmlNewResources, xmlHeader);

			writeXLMNode(ref xmlNewResources, tnRes);

			XmlNode xmlLibrary = Utils.ProjectFile.SelectSingleNode("/root/library");
			root.RemoveChild(xmlLibrary);

			XmlElement xmlNewLibrary = Utils.ProjectFile.CreateElement(null, "library", null);
			root.InsertAfter(xmlNewLibrary, xmlNewResources);

			writeXLMNode(ref xmlNewLibrary, tnLib);

			Utils.ProjectFile.Save(Utils.ProjectDirectory.FullName + "\\test.xml");
		}

		private void writeXLMNode(ref XmlElement _rootElement, TreeNode _treeNode)
		{
			XmlElement elem = writeXMLNodeHelper(_treeNode);

			if (_treeNode.Nodes.Count > 0)
			{
				foreach (TreeNode tn in _treeNode.Nodes)
				{
					writeXLMNode(ref elem, tn);
				}

				_rootElement.AppendChild(elem);
			}
			else
			{
				_rootElement.AppendChild(elem);
			}
		}

		private XmlElement writeXMLNodeHelper(TreeNode _treeNode)
		{
			Utils.twTag tag = (Utils.twTag)_treeNode.Tag;
			XmlElement node = Utils.ProjectFile.CreateElement(null, Convert.ToString(tag.Type).ToLower(), null);

			writeXMLelement("name", "s|" + _treeNode.Text, node);

			foreach (Utils.twTagAttribute twa in tag.Attributes)
			{
				switch (twa.dt)
				{
 					case Utils.twTagAttribute.dataType.BOOL:
						bool b = (bool)twa.val;
						writeXMLelement(twa.name, "b|" + b.ToString(), node);
						break;
					case Utils.twTagAttribute.dataType.CHAR:
						char c = (char)twa.val;
						writeXMLelement(twa.name, "c|" + c.ToString(), node);
						break;
					case Utils.twTagAttribute.dataType.FLOAT:
						float f = (float)twa.val;
						writeXMLelement(twa.name, "f|" + f.ToString(), node);
						break;
					case Utils.twTagAttribute.dataType.INT:
						int i = (int)twa.val;
						writeXMLelement(twa.name, "i|" + i.ToString(), node);
						break;
					case Utils.twTagAttribute.dataType.STRING:
						string s = (string)twa.val;
						writeXMLelement(twa.name, "s|" + s, node);
						break;
				}
			}

			return node;
		}

		private void writeXMLelement(string _elemName, string _elemVal, XmlElement node)
		{
			XmlElement elemTag = Utils.ProjectFile.CreateElement(null, _elemName.ToLower(), null);
			XmlText elemVal = Utils.ProjectFile.CreateTextNode(_elemVal.ToLower());
			elemTag.AppendChild(elemVal);
			node.AppendChild(elemTag);
		}

		private void loadProject()
		{
			ofd_loadProject.Filter = "XML Files (*.xml)|*.xml";
			DialogResult res = ofd_loadProject.ShowDialog();

			if (res == DialogResult.OK)
			{
				//initPanels();
				Utils.ProjectFile.Load(ofd_loadProject.FileName);

				string tmp = ofd_loadProject.FileName;
				int tmpI = tmp.LastIndexOf('\\');
				tmp = tmp.Substring(0, tmpI);

				Utils.ProjectDirectory = new DirectoryInfo(tmp);
				readXML();				
			}
		}

		private void readXML()
		{
			PanResources res = (PanResources)Utils.Panels.getpanelByName("LevelEditor.PanResources");
			PanLibrary lib = (PanLibrary)Utils.Panels.getpanelByName("LevelEditor.PanLibrary");

			XmlNode projName = Utils.ProjectFile.SelectSingleNode("/root/header/projectName");
			Utils.ProjectName = projName.InnerText;

			XmlNode xmlResources = Utils.ProjectFile.SelectSingleNode("/root/resources/folder");
			XmlNode xmlLibrary = Utils.ProjectFile.SelectSingleNode("/root/library/folder");

			TreeNode twResources = new TreeNode(Utils.ProjectName, 0, 0);
			TreeNode twLibrary = new TreeNode(Utils.ProjectName, 0, 0);

			readXMLNode(xmlResources, ref twResources);
			readXMLNode(xmlLibrary, ref twLibrary);

			res.init(twResources);
			lib.init(twLibrary);

			saveToolStripMenuItem.Enabled = true;
			saveAsToolStripMenuItem.Enabled = true;
			exportToolStripMenuItem.Enabled = true;
		}

		private void readXMLNode(XmlNode _xmlNode, ref TreeNode _twNode)
		{
			_twNode = readXMLNodeHelper(_xmlNode);

			if (_xmlNode.HasChildNodes)
			{
				foreach (XmlNode node in _xmlNode.ChildNodes)
				{
					Utils.twTag.TYPE t = getTagType(node);

					if (t == Utils.twTag.TYPE.FOLDER)
					{
						TreeNode tn = new TreeNode();
						readXMLNode(node, ref tn);
						_twNode.Nodes.Add(tn);
					}
					else if(t == Utils.twTag.TYPE.IMAGE)
					{
						TreeNode tn = readXMLNodeHelper(node);
						tn.ImageIndex = 1;
						tn.SelectedImageIndex = 1;
						_twNode.Nodes.Add(tn);
					}
					else if (t == Utils.twTag.TYPE.MESH)
					{
						TreeNode tn = readXMLNodeHelper(node);
						tn.ImageIndex = 1;			//should be changed
						tn.SelectedImageIndex = 1;	//should be changed
						_twNode.Nodes.Add(tn);
					}
					else if (t == Utils.twTag.TYPE.SOUND)
					{
						TreeNode tn = readXMLNodeHelper(node);
						tn.ImageIndex = 1;			//should be changed
						tn.SelectedImageIndex = 1;	//should be changed
						_twNode.Nodes.Add(tn);
					}
				}
			}
			return;
		}

		private TreeNode readXMLNodeHelper(XmlNode _xmlNode)
		{
			TreeNode res = new TreeNode(_xmlNode.SelectSingleNode("name").InnerText.Split('|')[1]);
			Utils.twTag tag = new Utils.twTag(getTagType(_xmlNode));

			XmlNodeList list = _xmlNode.ChildNodes;

			for (int child = 0; child < list.Count; child++)
			{
				if (getTagType(list[child]) != Utils.twTag.TYPE.FOLDER)
				{
					string[] vals = list[child].InnerText.Split('|');

					if (vals[0] == "b")
					{
 						bool b = (vals[1] == "false" ? false : true);
						tag.addAttribute(Utils.twTagAttribute.dataType.BOOL, list[child].Name, b);
					}
					else if (vals[0] == "c")
					{
						char c = vals[1].ToCharArray()[0];
						tag.addAttribute(Utils.twTagAttribute.dataType.CHAR, list[child].Name, c);
					}
					else if (vals[0] == "f")
					{
						float f = Convert.ToSingle(vals[1], CultureInfo.CurrentCulture);
						tag.addAttribute(Utils.twTagAttribute.dataType.FLOAT, list[child].Name, f);
					}
					else if (vals[0] == "i")
					{
						int i = Convert.ToInt32(vals[1], CultureInfo.CurrentCulture);
						tag.addAttribute(Utils.twTagAttribute.dataType.INT, list[child].Name, i);
					}
					else if (vals[0] == "s")
					{
						tag.addAttribute(Utils.twTagAttribute.dataType.STRING, list[child].Name, vals[1]);
					}
				}
			}

			res.Tag = tag;

			return res;
		}

		private Utils.twTag.TYPE getTagType(XmlNode _xmlNode)
		{
			if (_xmlNode.Name == "folder")
			{
				return Utils.twTag.TYPE.FOLDER;
			}
			else if (_xmlNode.Name == "image")
			{
				return Utils.twTag.TYPE.IMAGE;
			}
			else if (_xmlNode.Name == "mesh")
			{
				return Utils.twTag.TYPE.MESH;
			}
			else if (_xmlNode.Name == "sound")
			{
				return Utils.twTag.TYPE.SOUND;
			}
			else
			{
				return Utils.twTag.TYPE.UNDEFINED;
			}
		}

		private void timerTick()
		{
			int xDir = forwardKey ? 1 : backwardKey ? -1 : 0;
			int zDir = rightKey ? 1 : leftKey ? -1 : 0;
			bool mouseMove = xDir != 0 || zDir != 0;
			if (mouseMove)
				Utils.Graphics.gfx.moveCamera(xDir, zDir);			

			if (rightMouseDown && !leftMouseDown)
			{
				PanBrushes brush = (PanBrushes)Utils.Panels.getpanelByName("LevelEditor.PanBrushes");
				Utils.Graphics.gfx.rightMouseDown(brush.BrushSize, brush.BrushIntensity);
			}
			else if (leftMouseDown && !rightMouseDown)
			{
				PanBrushes brush = (PanBrushes)Utils.Panels.getpanelByName("LevelEditor.PanBrushes");
				Utils.Graphics.gfx.leftMouseDown(brush.BrushSize, brush.BrushIntensity);
			}				

			if (rightMouseDown || leftMouseDown || mouseMove)
				Utils.Graphics.gfx.renderScene();
		}        

		private void resizeWindow()
		{
            int sizeDifWidth = Size.Width - windowWidth;
            int sizeDifHeight = Size.Height - windowHeight;

            mainDockPanel.Size = new Size(mainDockPanel.Size.Width + sizeDifWidth, mainDockPanel.Size.Height + sizeDifHeight);
            windowWidth = Size.Width;
            windowHeight = Size.Height;

            shortcutPanel.Size = new Size(shortcutPanel.Size.Width + sizeDifWidth, shortcutPanel.Size.Height);

		}

		private void hideToolsMenu(object sender)
		{
            ToolStripMenuItem item = (ToolStripMenuItem)sender;

            if (item.CheckState == CheckState.Checked)
            {
                item.CheckState = CheckState.Unchecked;

                btn_save.Visible = false;
                btn_load.Visible = false;
                btn_export.Visible = false;
                btn_undo.Visible = false;
                btn_redo.Visible = false;
                cb_history.Visible = false;

                //shortcutPanel.Location = new Point(shortcutPanel.Location.X, shortcutPanel.Location.Y - 34);
                mainDockPanel.Location = new Point(mainDockPanel.Location.X, mainDockPanel.Location.Y - 34);

                //shortcutPanel.Size = new Size(shortcutPanel.Size.Width, shortcutPanel.Size.Height + 34);
                mainDockPanel.Size = new Size(mainDockPanel.Size.Width, mainDockPanel.Size.Height + 34);
            }
            else
            {
                item.CheckState = CheckState.Checked;

                //shortcutPanel.Size = new Size(shortcutPanel.Size.Width, shortcutPanel.Size.Height - 34);
                mainDockPanel.Size = new Size(mainDockPanel.Size.Width, mainDockPanel.Size.Height);

                //shortcutPanel.Location = new Point(shortcutPanel.Location.X, shortcutPanel.Location.Y + 34);
                mainDockPanel.Location = new Point(mainDockPanel.Location.X, mainDockPanel.Location.Y + 34);

                btn_save.Visible = true;
                btn_load.Visible = true;
                btn_export.Visible = true;
                btn_undo.Visible = true;
                btn_redo.Visible = true;
                cb_history.Visible = true;
            }
		}

        private void toggleDisplayMenuItems(Type panelType)
        {
			DockContent panel = (DockContent)Utils.Panels.getpanelByName(panelType.ToString());
            ToolStripMenuItem toolMenuItem = null;
            if (panelType == typeof(PanBrushes))
            {
                toolMenuItem = brushToolsToolStripMenuItem;
            }
            else if (panelType == typeof(PanLibrary))
            {
                toolMenuItem = libraryToolStripMenuItem;
            }
            else if (panelType == typeof(PanProperties))
            {
                toolMenuItem = propertiesToolStripMenuItem;
            }
            else if (panelType == typeof(PanResources))
            {
                toolMenuItem = resourcesToolToolStripMenuItem;
            }
            else if (panelType == typeof(PanTextures))
            {
                toolMenuItem = texturesToolToolStripMenuItem;
            }

            if (panel == null || panel.IsDisposed)
            {
                if (panelType == typeof(PanBrushes))
                {
                    panel = new PanBrushes();
                }
                else if (panelType == typeof(PanLibrary))
                {
                    panel = new PanLibrary();
                }
                else if (panelType == typeof(PanProperties))
                {
                    panel = new PanProperties();
                }
                else if (panelType == typeof(PanResources))
                {
                    panel = new PanResources();
                }
                else if (panelType == typeof(PanTextures))
                {
                    panel = new PanTextures();
                }
                else if (panelType == typeof(PanRender))
                {
                    panel = new PanRender(this);
                }
            }
            else if (!panel.IsDisposed)
            {
                if (panel.IsHidden)
                {
                    panel.IsHidden = false;
                    toolMenuItem.Checked = true;
                }
                else
                {
                    panel.Hide();
                    toolMenuItem.Checked = false;
                }
                return;
            }

            panel.Show(mainDockPanel, DockState.Float);
            Utils.Panels.addPanel(panel, panelType.ToString(), toolMenuItem);
            if(toolMenuItem != null)
                toolMenuItem.Checked = true;
        }

        private void closeAllDocuments()
        {
            if (mainDockPanel.DocumentStyle == DocumentStyle.SystemMdi)
            {
                foreach (Form form in MdiChildren)
                    form.Close();
            }
            else
            {
				Utils.Panels.destroy();
            }
        }

		private void NO()
		{
			MessageBox.Show("This is not yet implemented you tool!", "FUCK FACE!", MessageBoxButtons.OK, MessageBoxIcon.Error);
		}		

		private void MapEditor_Move(object sender, EventArgs e)
		{
			PanRender render = (PanRender)Utils.Panels.getpanelByName("LevelEditor.PanRender");
			render.resizeRenderPanel();
		}

		#endregion

        private void resourcesToolToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toggleDisplayMenuItems(typeof(PanResources));
        }

        private void texturesToolToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toggleDisplayMenuItems(typeof(PanTextures));
        }

        private void libraryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toggleDisplayMenuItems(typeof(PanLibrary));
        }

        private void propertiesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toggleDisplayMenuItems(typeof(PanProperties));
        }
	}
}
