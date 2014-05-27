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

namespace LevelEditor
{
    public partial class ImportResource : Form
    {
        string[] allowedImageFormates = new string[] { "png", "jpg", "jpeg", "bmp" };
		string[] allowedmeshFormats = new string[] { "fbx", "obj" };
		string fileRealName = "";
		TreeNode copyPaste, newNode;
		PanResources res;

        public ImportResource()
		{
			InitializeComponent();
			res = (PanResources)Utils.Panels.getpanelByName("LevelEditor.PanResources");

			ofd_importResource.Title = "Import Resource";

			tw_fileTree.Nodes.Add((TreeNode)res.resourcesRoot.Clone());
            tw_fileTree.SelectedNode = tw_fileTree.Nodes[0];

            ToolStripMenuItem twMenuCreateFolder = new ToolStripMenuItem();

            twMenuCreateFolder.Name = "tsm_cmsMenuCreateFolder";
            twMenuCreateFolder.Text = "New folder";
            twMenuCreateFolder.Click += twMenu_ClickCreateFolder;

            cms_treeView.Items.Add(twMenuCreateFolder);

			ToolStripMenuItem twMenuRename = new ToolStripMenuItem();

			twMenuRename.Name = "tsm_cmsMenuRename";
			twMenuRename.Text = "Rename";
			twMenuRename.Click += twMenu_ClickRename;

			cms_treeView.Items.Add(twMenuRename);

			ToolStripMenuItem twMenuRemove = new ToolStripMenuItem();

			twMenuRemove.Name = "tsm_cmsMenuRemove";
			twMenuRemove.Text = "Remove";
			twMenuRemove.Click += twMenu_ClickRemove;

			cms_treeView.Items.Add(twMenuRemove);			
		}

		private void twMenu_ClickRename(object sender, EventArgs e)
		{
			TreeNode tn = tw_fileTree.SelectedNode;
			NameFolder renameFolder = new NameFolder(ref tn);
			renameFolder.Show();
		}

        private void twMenu_ClickRemove(object sender, EventArgs e)
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

			tw_fileTree.SelectedNode.Remove();
			tw_fileTree.SelectedNode = tw_fileTree.Nodes[0];
		}

        private void twMenu_ClickCreateFolder(object sender, EventArgs e)
        {
            TreeNode tn = new TreeNode("New folder", 0, 0);

			Utils.twTag tag = new Utils.twTag(Utils.twTag.TYPE.FOLDER);
			tag.addAttribute(Utils.twTagAttribute.dataType.BOOL, "modifiable", true);

			tn.Tag = tag;
            NameFolder renameFolder = new NameFolder(ref tn);
            renameFolder.Show();
            tw_fileTree.SelectedNode.Nodes.Add(tn);
            tw_fileTree.SelectedNode.Expand();
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
				fileRealName = txb_fileName.Text;

				if (allowedImageFormates.Contains(tmp[tmp.Length - 1])) //IMAGE
				{
					Image img = Image.FromFile(txb_input.Text);
					pb_preView.Image = new Bitmap(img, new Size(350, 350));
					float fileSize = (float)Math.Round((new FileInfo(txb_input.Text).Length) / 1000000.0f, 2);
					newNode = new TreeNode(txb_fileName.Text, 1, 1);

					Utils.twTag tag = new Utils.twTag(Utils.twTag.TYPE.IMAGE);
					tag.addAttribute(Utils.twTagAttribute.dataType.BOOL, "modifiable", true);
					tag.addAttribute(Utils.twTagAttribute.dataType.STRING, "realname", fileRealName);
					tag.addAttribute(Utils.twTagAttribute.dataType.FLOAT, "size", fileSize);
					tag.addAttribute(Utils.twTagAttribute.dataType.INT, "sizex", img.Width);
					tag.addAttribute(Utils.twTagAttribute.dataType.INT, "sizey", img.Height);
					tag.addAttribute(Utils.twTagAttribute.dataType.STRING, "showname", txb_fileName.Text);

					newNode.Tag = tag;
					tw_fileTree.SelectedNode.Nodes.Add(newNode);
                    tw_fileTree.SelectedNode.Expand();
					tw_fileTree.SelectedNode = newNode;
				}
				else if (allowedmeshFormats.Contains(tmp[tmp.Length - 1])) //MESH
				{

				}
			}
		}

		private void btn_import_Click(object sender, EventArgs e)
		{
			try
			{
				File.Copy(txb_input.Text, Utils.ProjectDirectory.FullName + "\\" + fileRealName);
			}
			catch
			{ 
			}			

			Utils.twTag t = (Utils.twTag)newNode.Tag;
			t.addAttribute(Utils.twTagAttribute.dataType.STRING, "showname", txb_fileName.Text);
			newNode.Tag = t;

			if (t.Type == Utils.twTag.TYPE.IMAGE)
			{
				PanTextures tex = (PanTextures)Utils.Panels.getpanelByName("LevelEditor.PanTextures");

				Image img = Image.FromFile(Utils.ProjectDirectory.FullName + "\\" + fileRealName);
				img.Tag = t;
				tex.addImages(img);
			}

			res.updateTWRes(tw_fileTree.Nodes[0]);
			Close();
		}

		private void btn_renameFile_Click(object sender, EventArgs e)
		{
			tw_fileTree.SelectedNode.Text = txb_fileName.Text;
		}

		private void tw_fileTree_AfterSelect(object sender, TreeViewEventArgs e)
		{
			tw_fileTree.SelectedNode = e.Node;
		}

		private void tw_fileTree_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
		{
			tw_fileTree.SelectedNode = e.Node;
			Utils.twTag twt = (Utils.twTag)tw_fileTree.SelectedNode.Tag;

			if (e.Button == MouseButtons.Right)
			{
				if (twt.getAttributeByName<bool>("modifiable"))
				{
					cms_treeView.Items[1].Enabled = true;
					cms_treeView.Items[2].Enabled = true;
					cms_treeView.Show(tw_fileTree, e.Location);
				}
				else
				{
					cms_treeView.Items[1].Enabled = false;
					cms_treeView.Items[2].Enabled = false;
					cms_treeView.Show(tw_fileTree, e.Location);
				}
			}			
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

        private void txb_fileName_KeyPress(object sender, KeyPressEventArgs e)
        {
            Utils.twTag tag = (Utils.twTag)tw_fileTree.SelectedNode.Tag;

            if (e.KeyChar == 13 && tag.getAttributeByName<bool>("modifiable"))
            {
                tw_fileTree.SelectedNode.Text = txb_fileName.Text;
            }
        }
    }
}
