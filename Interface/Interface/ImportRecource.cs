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
		
		string[] allowedImageFormates = new string[] { "png", "jpg", "jpeg", "bmp" };
		string[] allowedmeshFormats = new string[] { "fbx", "obj" };
		TreeNode copyPaste;
		MapEditor edit;

		public ImportRecource(MapEditor _edit)
		{
			InitializeComponent();
			edit = _edit;
			ofd_importResource.Title = "Import Resource";

			tw_fileTree.Nodes.Add((TreeNode)edit.resRoot.Clone());
			tw_fileTree.SelectedNode = tw_fileTree.Nodes[0];
			tw_fileTree.ImageList = Utils.Imgbase.MediumBank;

			ToolStripMenuItem twMenu = new ToolStripMenuItem();

			twMenu.Name = "tsm_cmsMenu";
			twMenu.Text = "Rename";
			twMenu.Click += twMenu_Click;

			cms_treeView.Items.Add(twMenu);
		}

		void twMenu_Click(object sender, EventArgs e)
		{
			TreeNode tn = tw_fileTree.SelectedNode;
			RenameFolder renameFolder = new RenameFolder(ref tn);
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
					TreeNode tn = new TreeNode(txb_fileName.Text, 1, 1);
					tn.Tag = new Utils.twTag(Utils.twTag.Type.IMAGE);
					tw_fileTree.SelectedNode.Nodes.Add(tn);
				}
				else if (allowedmeshFormats.Contains(tmp[tmp.Length - 1]))
				{
					//Mesh formats
				}
			}
		}

		private void btn_createFolder_Click(object sender, EventArgs e)
		{
			TreeNode tn = new TreeNode("New folder", 0, 0);
			tn.Tag = new Utils.twTag(Utils.twTag.Type.FOLDER);
			RenameFolder renameFolder = new RenameFolder(ref tn);
			renameFolder.Show();
			tw_fileTree.SelectedNode.Nodes.Add(tn);
			tw_fileTree.SelectedNode.Expand();
		}

		private void btn_import_Click(object sender, EventArgs e)
		{
			edit.updateTWRes(tw_fileTree.Nodes[0]);
			this.Close();
		}

		private void btn_renameFile_Click(object sender, EventArgs e)
		{
			tw_fileTree.SelectedNode.Text = txb_fileName.Text;
		}

		private void tw_fileTree_AfterSelect(object sender, TreeViewEventArgs e)
		{
			tw_fileTree.SelectedNode = e.Node;

			Utils.twTag twt = (Utils.twTag)tw_fileTree.SelectedNode.Tag;

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
			Utils.twTag twt = (Utils.twTag)tw_fileTree.SelectedNode.Tag;

			if (e.Button == MouseButtons.Right && twt.deletable)
			{
				cms_treeView.Show(tw_fileTree, e.Location);
			}			
		}

		private void btn_removeFolder_Click(object sender, EventArgs e)
		{
			Utils.twTag twt = (Utils.twTag)tw_fileTree.SelectedNode.Tag;

			if (tw_fileTree.SelectedNode.Nodes.Count != 0)
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

			tw_fileTree.SelectedNode.Remove();
			tw_fileTree.SelectedNode = tw_fileTree.Nodes[0];
		}

		private void tw_fileTree_ItemDrag(object sender, ItemDragEventArgs e)
		{
			if (e.Button == MouseButtons.Left)
			{
				DoDragDrop(e.Item, DragDropEffects.Move);
			}
			else if (e.Button == MouseButtons.Right)
			{
				DoDragDrop(e.Item, DragDropEffects.Copy);
			}
		}

		private void tw_fileTree_DragEnter(object sender, DragEventArgs e)
		{
			e.Effect = e.AllowedEffect;
		}

		private void tw_fileTree_DragOver(object sender, DragEventArgs e)
		{
			Point p = tw_fileTree.PointToClient(new Point(e.X, e.Y));
			tw_fileTree.SelectedNode = tw_fileTree.GetNodeAt(p);
		}

		private void tw_fileTree_DragDrop(object sender, DragEventArgs e)
		{
			Point p = tw_fileTree.PointToClient(new Point(e.X, e.Y));
			TreeNode ttn = tw_fileTree.GetNodeAt(p);
			TreeNode dtn = (TreeNode)e.Data.GetData(typeof(TreeNode));

			if (!dtn.Equals(ttn) && !ContainsNode(dtn, ttn))
			{
				if (e.Effect == DragDropEffects.Move)
				{
					dtn.Remove();
					ttn.Nodes.Add(dtn);
				}
				else if (e.Effect == DragDropEffects.Copy)
				{
					ttn.Nodes.Add((TreeNode)dtn.Clone());
				}

				ttn.Expand();
			}
		}

		private bool ContainsNode(TreeNode n1, TreeNode n2)
		{
			if (n2.Parent == null) return false;
			if (n2.Parent.Equals(n1)) return true;

			return ContainsNode(n1, n2.Parent);
		}

		private void tw_fileTree_KeyDown(object sender, KeyEventArgs e)
		{
			if (e.Control && e.KeyCode == Keys.C)
			{
				copyPaste = tw_fileTree.SelectedNode;
			}
		}

		private void tw_fileTree_KeyUp(object sender, KeyEventArgs e)
		{

			if (e.Control && e.KeyCode == Keys.V)
			{
				tw_fileTree.SelectedNode.Nodes.Add((TreeNode)copyPaste.Clone());
				tw_fileTree.SelectedNode.Expand();
			}
		}
	}
}
