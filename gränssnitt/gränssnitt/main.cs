using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LevelEditor
{
	public partial class MapEditor : Form
	{		
		public MapEditor()
		{
			InitializeComponent();
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

                tw_objects.Location = new Point(tw_objects.Location.X, tw_objects.Location.Y - 34);
                pictureBox1.Location = new Point(pictureBox1.Location.X, pictureBox1.Location.Y - 34);
                tc_Tools.Location = new Point(tc_Tools.Location.X, tc_Tools.Location.Y - 34);

                tw_objects.Size = new Size(tw_objects.Size.Width, tw_objects.Size.Height + 34);
                pictureBox1.Size = new Size(pictureBox1.Size.Width, pictureBox1.Size.Height + 34);
                tc_Tools.Size = new Size(tc_Tools.Size.Width, tc_Tools.Size.Height + 34);
            }
            else
            {
                item.CheckState = CheckState.Checked;

                tw_objects.Size = new Size(tw_objects.Size.Width, tw_objects.Size.Height - 34);
                pictureBox1.Size = new Size(pictureBox1.Size.Width, pictureBox1.Size.Height - 34);
                tc_Tools.Size = new Size(tc_Tools.Size.Width, tc_Tools.Size.Height - 34);

                tw_objects.Location = new Point(tw_objects.Location.X, tw_objects.Location.Y + 34);
                pictureBox1.Location = new Point(pictureBox1.Location.X, pictureBox1.Location.Y + 34);
                tc_Tools.Location = new Point(tc_Tools.Location.X, tc_Tools.Location.Y + 34);                

                btn_save.Visible = true;
                btn_load.Visible = true;
                btn_export.Visible = true;
                btn_undo.Visible = true;
                btn_redo.Visible = true;
                cb_history.Visible = true;
            }
        }
	}
}
