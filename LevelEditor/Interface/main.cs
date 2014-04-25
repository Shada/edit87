using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

//using wrapperns;

namespace LevelEditor
{
	public partial class MapEditor : Form
	{
        // Umm... cant use this yet for some reason
        //public wrapperns.GraphicsCommunicator graphics;
        int windowWidth, windowHeight;

		public MapEditor()
		{
			InitializeComponent();
            windowWidth = Size.Width;
            windowHeight = Size.Height;
		}

		private void button1_Click(object sender, EventArgs e)
		{
			properties_test test = new properties_test();
			test.Show();
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

                panel_Left.Location = new Point(panel_Left.Location.X, panel_Left.Location.Y - 34);
                pb_scene.Location = new Point(pb_scene.Location.X, pb_scene.Location.Y - 34);

                panel_Left.Size = new Size(panel_Left.Size.Width, panel_Left.Size.Height + 34);
                pb_scene.Size = new Size(pb_scene.Size.Width, pb_scene.Size.Height + 34);
            }
            else
            {
                item.CheckState = CheckState.Checked;

                panel_Left.Size = new Size(panel_Left.Size.Width, panel_Left.Size.Height - 34);
                pb_scene.Size = new Size(pb_scene.Size.Width, pb_scene.Size.Height - 34);

                panel_Left.Location = new Point(panel_Left.Location.X, panel_Left.Location.Y + 34);
                pb_scene.Location = new Point(pb_scene.Location.X, pb_scene.Location.Y + 34);                

                btn_save.Visible = true;
                btn_load.Visible = true;
                btn_export.Visible = true;
                btn_undo.Visible = true;
                btn_redo.Visible = true;
                cb_history.Visible = true;
            }
        }

        private void MapEditor_Resize(object sender, EventArgs e)
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
	}
}
