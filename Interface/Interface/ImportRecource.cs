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
	public partial class ImportRecource : Form
	{
		TreeNode currNode;
		string[] allowedImageFormates = new string[] { "png", "jpg", "jpeg", "bmp" };
		string[] allowedmeshFormats = new string[] { "fbx", "obj" };

		public ImportRecource()
		{
			InitializeComponent();
			ofd_importResource.Title = "Import Resource";
			currNode = new TreeNode("Root", 1, 1);
			currNode.Tag = new Utils.twTag(Utils.twTag.Type.FOLDER, false);
			tw_fileTree.Nodes.Add(currNode);

			ToolStripMenuItem twMenu = new ToolStripMenuItem();

			twMenu.Name = "tsm_cmsMenu";
			twMenu.Text = "Rename";
			twMenu.Click += twMenu_Click;

			cms_treeView.Items.Add(twMenu);
		}

		void twMenu_Click(object sender, EventArgs e)
		{
			RenameFolder renameFolder = new RenameFolder(ref currNode);
			renameFolder.Show();
		}

		private void btn_browse_Click(object sender, EventArgs e)
		{
			DialogResult res = ofd_importResource.ShowDialog();

			if (res == DialogResult.OK)
			{
				txb_input.Text = ofd_importResource.FileName;
				string[] tmp = ofd_importResource.FileName.Split('\\');
				txb_fileName.Text = tmp[tmp.Length - 1];
				tmp = txb_fileName.Text.Split('.');

				if (allowedImageFormates.Contains(tmp[tmp.Length - 1]))
				{					
					pb_preView.Image = new Bitmap(Image.FromFile(txb_input.Text), new Size(350, 350));
					TreeNode tn = new TreeNode(txb_fileName.Text, 0, 0);
					tn.Tag = new Utils.twTag(Utils.twTag.Type.IMAGE);
					currNode.Nodes.Add(tn);
				}
				else if (allowedmeshFormats.Contains(tmp[tmp.Length - 1]))
				{
					//Mesh formats
				}
			}
		}

		private void btn_createFolder_Click(object sender, EventArgs e)
		{
			TreeNode tn = new TreeNode("New folder", 1, 1);
			tn.Tag = new Utils.twTag(Utils.twTag.Type.FOLDER);
			RenameFolder renameFolder = new RenameFolder(ref tn);
			renameFolder.Show();
			currNode.Nodes.Add(tn);
			currNode.Expand();
		}

		private void btn_import_Click(object sender, EventArgs e)
		{

		}

		private void btn_renameFile_Click(object sender, EventArgs e)
		{
			currNode.Text = txb_fileName.Text;
		}

		private void tw_fileTree_AfterSelect(object sender, TreeViewEventArgs e)
		{
			currNode = e.Node;

			Utils.twTag twt = (Utils.twTag)currNode.Tag;

			if (!twt.deletable)
			{
				btn_removeFolder.Enabled = false;
			}
			else
			{
				btn_removeFolder.Enabled = true;
			}
		}

		private void tw_fileTree_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
		{
			Utils.twTag twt = (Utils.twTag)currNode.Tag;

			if (e.Button == MouseButtons.Right && twt.deletable)
			{
				cms_treeView.Show(tw_fileTree, e.Location);
			}			
		}

		private void btn_removeFolder_Click(object sender, EventArgs e)
		{
			Utils.twTag twt = (Utils.twTag)currNode.Tag;

			if (currNode.Nodes.Count != 0)
			{
				DialogResult res = MessageBox.Show("The selected folder is not empty!\nDo you want to continue?", "Warning!", MessageBoxButtons.YesNo);

				if (res == DialogResult.No)
				{
					return;
				}
			}
			else if (!twt.deletable)
			{
				return;
			}

			currNode.Remove();
			currNode = tw_fileTree.Nodes[0];
		}
	}
}
