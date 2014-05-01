using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.IO.Compression;
using System.Xml;

//using wrapperns;

namespace LevelEditor
{
	public partial class MapEditor : Form
	{
        // Umm... cant use this yet for some reason
        //public wrapperns.GraphicsCommunicator graphics;
        int windowWidth, windowHeight;
		public XmlDocument projectFile = new XmlDocument();
		public DirectoryInfo projectDirectory;
		public TreeNode resRoot = new TreeNode("Root", 0, 0);
		
		public MapEditor()
		{
			InitializeComponent();
            windowWidth = Size.Width;
            windowHeight = Size.Height;
			resRoot.Tag = new Utils.twTag(Utils.twTag.Type.FOLDER, false);			
			tw_resources.Nodes.Add(resRoot);

			Utils.Imgbase.Init();

			Utils.Imgbase.AddImage("folder", global::Interface.Properties.Resources.folder);
			Utils.Imgbase.AddImage("image", global::Interface.Properties.Resources.image);
			
			lw_Brush.LargeImageList = Utils.Imgbase.MediumBank;
			lv_Textures.LargeImageList = Utils.Imgbase.MediumBank;
			tw_resources.ImageList = Utils.Imgbase.MediumBank;
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
			hideToolsMenu(sender);
        }

        private void MapEditor_Resize(object sender, EventArgs e)
        {
			resizeWindow();
        }

		private void newProjectToolStripMenuItem_Click(object sender, EventArgs e)
		{
			NewProject project = new NewProject(this);
			project.Show();
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			MessageBox.Show("This is not yet implemented you tool!", "FUCK FACE!", MessageBoxButtons.OK, MessageBoxIcon.Error);
		}

		private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
		{
			MessageBox.Show("This is not yet implemented you tool!", "FUCK FACE!", MessageBoxButtons.OK, MessageBoxIcon.Error);
		}

		private void loadToolStripMenuItem_Click(object sender, EventArgs e)
		{
			loadProject();
		}

		private void exportToolStripMenuItem_Click(object sender, EventArgs e)
		{
			export();
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

		private void lw_Brush_SelectedIndexChanged(object sender, EventArgs e)
		{

		}

		private void btn_importResource_Click(object sender, EventArgs e)
		{
			ImportRecource res = new ImportRecource(this);
			res.Show();
		}

		private void nud_brushIntensity_ValueChanged(object sender, EventArgs e)
		{

		}

		private void tw_resources_AfterSelect(object sender, TreeViewEventArgs e)
		{

		}

		#region logic

		public void updateTWRes(TreeNode _tn)
		{
			tw_resources.Nodes.Clear();
			tw_resources.Nodes.Add((TreeNode)_tn.Clone());
			resRoot = tw_resources.Nodes[0];
		}

		private void export()
		{
			DialogResult res = sfd_export.ShowDialog();

			if (res == DialogResult.OK)
			{
				ZipFile.CreateFromDirectory(projectDirectory.FullName, sfd_export.FileName + ".zip", CompressionLevel.Fastest, true);
			}
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

		private void loadProject()
		{
			DialogResult res = ofd_load.ShowDialog();

			if (res == DialogResult.OK)
			{
				string file = ofd_load.FileName;
				string[] checkDirs = new string[] { "maps", "brushes", "resources" };
				string[] path = file.Split('\\');
				string dir = "";

				for (int i = 0; i < path.Length - 1; i++)
				{
					dir += path[i] + "\\";
				}

				dir = dir.Remove(dir.Length - 1);

				projectFile.Load(file);
				projectDirectory = new DirectoryInfo(dir);

				DirectoryInfo[] dirs = projectDirectory.GetDirectories();

				int dirCounter = 0;

				foreach (DirectoryInfo di in dirs)
				{
					foreach (string s in checkDirs)
					{
						if (di.Name == s)
						{
							dirCounter++;
						}
					}
				}

				if (dirCounter != 3)
				{
					MessageBox.Show("The selected working directory doesn't contains the required directories", "No can do!", MessageBoxButtons.OK, MessageBoxIcon.Error);
					projectDirectory = null;
					projectFile = null;
					return;
				}
			}
		}

		#endregion

#if DEBUG
		private void MapEditor_FormClosing(object sender, FormClosingEventArgs e)
		{
			try
			{
				projectDirectory.Delete(true);
			}
			catch(Exception _ex)
			{
				Console.WriteLine(_ex.Message);
			}
		}
#endif
	}
}
