using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Microsoft.DirectX;

using wrap;

namespace LevelEditor
{
	public partial class MapEditor : Form
	{
        private wrap.GraphicsCommunicator graphics;
        int windowWidth, windowHeight;
        private bool forwardKey, backwardKey, leftKey, rightKey;

		public MapEditor()
		{
            this.KeyPreview = true;
            graphics = new GraphicsCommunicator(this.Handle);
			InitializeComponent();

            timer1.Interval = 33;
            timer1.Start();

            windowWidth = Size.Width;
            windowHeight = Size.Height;
            graphics.createTerrain(256, 256, 5, false);
		}

		private void button1_Click(object sender, EventArgs e)
		{
			properties_test test = new properties_test();
			test.Show();
		}

		private void btn_TerrainBrush_Click(object sender, EventArgs e)
		{
            //MessageBox.Show("this is fuckface");
            graphics.renderScene();
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

		private void btn_save_Click(object sender, EventArgs e)
		{

		}

		private void btn_load_Click(object sender, EventArgs e)
		{

		}

		private void btn_export_Click(object sender, EventArgs e)
		{

		}

		private void cb_history_SelectedIndexChanged(object sender, EventArgs e)
		{

		}

		private void btn_undo_Click(object sender, EventArgs e)
		{

		}

		private void btn_redo_Click(object sender, EventArgs e)
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

			pb_scene.Size = new Size(pb_scene.Size.Width + sizeDifWidth, pb_scene.Size.Height + sizeDifHeight);
			windowWidth = Size.Width;
			windowHeight = Size.Height;
			panel_Right.Location = new Point(panel_Right.Location.X + sizeDifWidth, panel_Right.Location.Y);
			panel_Right.Size = new Size(panel_Right.Size.Width, panel_Right.Size.Height + sizeDifHeight);
			panel_Left.Size = new Size(panel_Left.Size.Width, panel_Left.Size.Height + sizeDifHeight);
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

				tw_objects.Location = new Point(tw_objects.Location.X, tw_objects.Location.Y - 34);
				pb_scene.Location = new Point(pb_scene.Location.X, pb_scene.Location.Y - 34);

				tw_objects.Size = new Size(tw_objects.Size.Width, tw_objects.Size.Height + 34);
				pb_scene.Size = new Size(pb_scene.Size.Width, pb_scene.Size.Height + 34);
			}
			else
			{
				item.CheckState = CheckState.Checked;

				tw_objects.Size = new Size(tw_objects.Size.Width, tw_objects.Size.Height - 34);
				pb_scene.Size = new Size(pb_scene.Size.Width, pb_scene.Size.Height - 34);

				tw_objects.Location = new Point(tw_objects.Location.X, tw_objects.Location.Y + 34);
				pb_scene.Location = new Point(pb_scene.Location.X, pb_scene.Location.Y + 34);

				btn_save.Visible = true;
				btn_load.Visible = true;
				btn_export.Visible = true;
				btn_undo.Visible = true;
				btn_redo.Visible = true;
				cb_history.Visible = true;
			}
		}

        private void MapEditor_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.W:    forwardKey = true;      break;
                case Keys.S:    backwardKey = true;     break;
                case Keys.A:    leftKey = true;         break;
                case Keys.D:    rightKey = true;        break;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (forwardKey) graphics.moveCamera((sbyte)'W');
            else if (backwardKey) graphics.moveCamera((sbyte)'S');
            if (leftKey) graphics.moveCamera((sbyte)'A');
            else if (rightKey) graphics.moveCamera((sbyte)'D');
        }

        private void MapEditor_KeyUp(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.W:    forwardKey = false;     break;
                case Keys.S:    backwardKey = false;    break;
                case Keys.A:    leftKey = false;        break;
                case Keys.D:    rightKey = false;       break;
            }
        }
	}
}
