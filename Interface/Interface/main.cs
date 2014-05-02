using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;

using wrap;

namespace LevelEditor
{
	public partial class MapEditor : Form
	{
        bool saveLayout = true;
        wrap.GraphicsCommunicator graphics;
        int windowWidth, windowHeight;
        DeserializeDockContent deserializeDockContent;

        DockContent[] panels    = new DockContent[10];
        string[] panelStrings   = new string[10];       //the string names of the panel class types

		public MapEditor()
		{
            graphics = new GraphicsCommunicator(this.Handle);
			InitializeComponent();
            windowWidth = Size.Width;
            windowHeight = Size.Height;
            mainDockPanel.DockRightPortion = 200;
            mainDockPanel.DockLeftPortion = 215;

            panels[0] = new PanBrushes();
            panels[0].Show(mainDockPanel, DockState.DockRight);
            panelStrings[0] = typeof(PanBrushes).ToString();

            panels[1] = new PanTextures();
            panels[1].Show(mainDockPanel, DockState.Float);
            panels[1].DockHandler.FloatPane.DockTo(mainDockPanel.DockWindows[DockState.DockRight]);
            panelStrings[1] = typeof(PanTextures).ToString();

            panels[2] = new PanResources();
            panels[2].Show(mainDockPanel, DockState.Float);
            panels[2].DockHandler.FloatPane.DockTo(mainDockPanel.DockWindows[DockState.DockRight]);
            panelStrings[2] = typeof(PanResources).ToString();

            panels[3] = new PanRender();
            panels[3].Show(mainDockPanel, DockState.Document);
            panelStrings[3] = typeof(PanRender).ToString();

            panels[4] = new PanLibrary();
            panels[4].Show(mainDockPanel, DockState.Float);
            panels[4].DockHandler.FloatPane.DockTo(mainDockPanel.DockWindows[DockState.DockLeft]);
            panelStrings[4] = typeof(PanLibrary).ToString();

            panels[5] = new PanProperties();
            panels[5].Show(mainDockPanel, DockState.Float);
            panels[5].DockHandler.FloatPane.DockTo(mainDockPanel.DockWindows[DockState.DockLeft]);
            panelStrings[5] = typeof(PanProperties).ToString();
            deserializeDockContent = new DeserializeDockContent(GetContentFromPersistString);
		}

		private void btn_TerrainBrush_Click(object sender, EventArgs e)
		{

		}

		private void btn_TextureBrush_Click(object sender, EventArgs e)
		{

		}

		private void lv_Textures_SelectedIndexChanged(object sender, EventArgs e)
		{

		}

        private void toolsShortcutsToolStripMenuItem_Click(object sender, EventArgs e)
        {
			hideToolsMenu(sender);
        }

        private void MapEditor_Resize(object sender, EventArgs e)
        {
			resizeWindow();
        }

		private void newProjectToolStripMenuItem_Click(object sender, EventArgs e)
		{
			NewProject project = new NewProject();
			project.Show();
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void loadToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void exportToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void importBrushesToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void undoToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void redoToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void prefrencesToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void haalpPleaseToolStripMenuItem_Click(object sender, EventArgs e)
		{

		}

		private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
		{

        }

		private void tw_objects_AfterSelect(object sender, TreeViewEventArgs e)
		{

		}

		private void nud_BrushSize_ValueChanged(object sender, EventArgs e)
		{

		}

		private void btn_importBrush_Click(object sender, EventArgs e)
		{

		}

		private void lw_Brush_SelectedIndexChanged(object sender, EventArgs e)
		{

		}

		private void btn_importTexture_Click(object sender, EventArgs e)
		{

		}

		private void btn_importResource_Click(object sender, EventArgs e)
		{

		}

		private void nud_brushIntensity_ValueChanged(object sender, EventArgs e)
		{

		}

		private void tw_resources_AfterSelect(object sender, TreeViewEventArgs e)
		{

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

        private void MapEditor_Load(object sender, EventArgs e)
        {
            string xmlFile = "PanelLayout.xml";
            DeserializeDockContent ddc = new DeserializeDockContent(GetContentFromPersistString);
            mainDockPanel.LoadFromXml(xmlFile, ddc);
        }

        private void menuStrip_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void exportPreferencesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string xmlFile = "PanelLayout.xml";
            mainDockPanel.SaveAsXml(xmlFile);
        }

        private void importPreferencesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //throw new NotImplementedException("yet to be implemented");
            string xmlFile = "PanelLayout.xml";
            mainDockPanel.LoadFromXml(xmlFile, deserializeDockContent);
        }

        private IDockContent GetContentFromPersistString(string persistString)
        {
            for (uint i = 0; i < panels.Length-1; i++)
                if (persistString == panelStrings[i])
                    return panels[i];
            return panels[panels.Length-1];
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
	}
}
