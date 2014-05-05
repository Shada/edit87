﻿using System;
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
using WeifenLuo.WinFormsUI.Docking;

using wrap;

namespace LevelEditor
{
	public partial class MapEditor : Form
	{
        public const string activeLayoutName = "PanelLayout.xml";

        bool saveLayout = true;
        wrap.GraphicsCommunicator graphics;
        int windowWidth, windowHeight;
        public XmlDocument projectFile = new XmlDocument();
        public DirectoryInfo projectDirectory;
        DeserializeDockContent deserializeDockContent;
        public TreeNode resourcesRoot = new TreeNode("Root", 0, 0);

        DockContent[] panels    = new DockContent[10];
        string[] panelStrings   = new string[10];       //the string names of the panel class types

		public MapEditor()
		{
            graphics = new GraphicsCommunicator(this.Handle);
			InitializeComponent();
            createStandardControls();

            windowWidth = Size.Width;
            windowHeight = Size.Height;

            deserializeDockContent = new DeserializeDockContent(GetContentFromPersistString);
            mainDockPanel.LoadFromXml(activeLayoutName, deserializeDockContent);
		}
        private void createStandardControls()
        {
            panels[0] = new PanBrushes();
            panelStrings[0] = typeof(PanBrushes).ToString();

            panels[1] = new PanTextures();
            panelStrings[1] = typeof(PanTextures).ToString();

            panels[2] = new PanResources();
            panelStrings[2] = typeof(PanResources).ToString();

            panels[3] = new PanRender();
            panelStrings[3] = typeof(PanRender).ToString();

            panels[4] = new PanLibrary();
            panelStrings[4] = typeof(PanLibrary).ToString();

            panels[5] = new PanProperties();
            panelStrings[5] = typeof(PanProperties).ToString();
        }
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
            NO();
		}

		private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
		{
            NO();
		}

		private void loadToolStripMenuItem_Click(object sender, EventArgs e)
		{
            NO();
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
            NO();
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

        private static void NO()
        {
            MessageBox.Show("This is not yet implemented you tool!", "FUCK FACE!", MessageBoxButtons.OK, MessageBoxIcon.Error);
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
                mainDockPanel.Size = new Size(mainDockPanel.Size.Width, mainDockPanel.Size.Height - 34);

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

        private void toggleDisplay(DockContent panel)
        {
            if (!panel.IsDisposed)
            {
                if (panel.IsHidden)
                    panel.IsHidden = false;
                else
                    panel.Hide();
            }
            else
            {
                panel = new PanBrushes();
                panel.Show(mainDockPanel, DockState.Float);
                panel.DockHandler.FloatPane.DockTo(mainDockPanel.DockWindows[DockState.DockRight]);
            }
            
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
                for (int i = 0; i < panels.Length; i++)
                {
                    if(panels[i] != null)
                        panels[i].Close();
                }
            }
        }

        private void MapEditor_Load(object sender, EventArgs e)
        {
            DeserializeDockContent ddc = new DeserializeDockContent(GetContentFromPersistString);
            mainDockPanel.LoadFromXml(activeLayoutName, ddc);
        }

        private void menuStrip_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void exportPreferencesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            mainDockPanel.SaveAsXml(activeLayoutName);
        }

        private void importPreferencesToolStripMenuItem_Click(object sender, EventArgs e)
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
        }

        private IDockContent GetContentFromPersistString(string persistString)
        {
            for (uint i = 0; i < panels.Length; i++)
                if (persistString == panelStrings[i])
                    return panels[i];
            return null;
        }

        private void mainDockPanel_ActiveContentChanged(object sender, EventArgs e)
        {

        }

        private void toolsShortcutsToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            hideToolsMenu(sender);
        }

        private void brushToolsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toggleDisplay(panels[0]);
        }

        private void resetToDefaultToolStripMenuItem_Click(object sender, EventArgs e)
        {
            mainDockPanel.SuspendLayout(true);
            closeAllDocuments();
            createStandardControls();

            mainDockPanel.DockRightPortion = 200;
            mainDockPanel.DockLeftPortion = 215;

            panels[0].Show(mainDockPanel, DockState.DockRight);
            panels[1].Show(panels[0].Pane, DockAlignment.Bottom, 0.62);
            panels[2].Show(panels[1].Pane, DockAlignment.Bottom, 0.50);
            panels[3].Show(mainDockPanel, DockState.Document);
            panels[4].Show(mainDockPanel, DockState.DockLeft);
            panels[5].Show(panels[4].Pane, DockAlignment.Bottom, 0.50);

            mainDockPanel.ResumeLayout(true, true);
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
	}
}
