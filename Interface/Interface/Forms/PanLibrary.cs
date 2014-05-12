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

namespace LevelEditor
{
    public partial class PanLibrary : DockContent
    {
        int twObjectsSizeDiff = 12;
		TreeNode copyPaste;
		public TreeNode libraryRoot;

        public PanLibrary()
        {
            InitializeComponent();
        }

		public void init(TreeNode _rootNode)
		{
			libraryRoot = _rootNode;

			Utils.twTag tag = new Utils.twTag(Utils.twTag.TYPE.FOLDER);
			tag.addAttribute(Utils.twTagAttribute.dataType.BOOL, "modifiable", false);

			libraryRoot.Tag = tag;
			tw_objects.Nodes.Add(libraryRoot);

			ToolStripMenuItem twMenuCreateFolder = new ToolStripMenuItem();

			twMenuCreateFolder.Name = "tsm_cmsMenuCreateFolder";
			twMenuCreateFolder.Text = "New folder";
			twMenuCreateFolder.Click += twMenu_ClickCreateFolder;

			cms.Items.Add(twMenuCreateFolder);

			ToolStripMenuItem twMenuRename = new ToolStripMenuItem();

			twMenuRename.Name = "tsm_cmsMenuRename";
			twMenuRename.Text = "Rename";
			twMenuRename.Click += twMenu_ClickRename;

			cms.Items.Add(twMenuRename);

			ToolStripMenuItem twMenuRemove = new ToolStripMenuItem();

			twMenuRemove.Name = "tsm_cmsMenuRemove";
			twMenuRemove.Text = "Remove";
			twMenuRemove.Click += twMenu_ClickRemove;

			cms.Items.Add(twMenuRemove);
		}

		public TreeNode getRootNode()
		{
			return tw_objects.Nodes[0];
		}

		private void twMenu_ClickRemove(object sender, EventArgs e)
		{
			Utils.twTag twt = (Utils.twTag)tw_objects.SelectedNode.Tag;

			if (tw_objects.SelectedNode.Nodes.Count != 0)
			{
				DialogResult res = MessageBox.Show("The selected folder is not empty!\nDo you want to continue?", "Warning!", MessageBoxButtons.YesNo);

				if (res == DialogResult.No)
				{
					return;
				}
			}

			tw_objects.SelectedNode.Remove();
			tw_objects.SelectedNode = tw_objects.Nodes[0];
		}

		private void twMenu_ClickRename(object sender, EventArgs e)
		{
			TreeNode tn = tw_objects.SelectedNode;
			NameFolder renameFolder = new NameFolder(ref tn);
			renameFolder.Show();
		}

		private void twMenu_ClickCreateFolder(object sender, EventArgs e)
		{
			TreeNode tn = new TreeNode("New folder", 0, 0);

			Utils.twTag tag = new Utils.twTag(Utils.twTag.TYPE.FOLDER);
			tag.addAttribute(Utils.twTagAttribute.dataType.BOOL, "modifiable", false);

			tn.Tag = tag;
			NameFolder renameFolder = new NameFolder(ref tn);
			renameFolder.Show();
			tw_objects.SelectedNode.Nodes.Add(tn);
			tw_objects.SelectedNode.Expand();
		}

        private void PanLibrary_SizeChanged(object sender, EventArgs e)
        {
			tw_objects.Size = new Size(Size.Width - twObjectsSizeDiff - 20, tw_objects.Height);
        }

		private void tw_objects_DragDrop(object sender, DragEventArgs e)
		{
			Point p = tw_objects.PointToClient(new Point(e.X, e.Y));
			TreeNode ttn = tw_objects.GetNodeAt(p);
			TreeNode dtn = (TreeNode)e.Data.GetData(typeof(TreeNode));

			if(ttn == null)
			{
				ttn = tw_objects.Nodes[0];
			}

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

		private void tw_objects_DragEnter(object sender, DragEventArgs e)
		{
			e.Effect = e.AllowedEffect;
		}

		private void tw_objects_DragOver(object sender, DragEventArgs e)
		{
			if (tw_objects.Nodes.Count == 0)
			{
				init(new TreeNode(Utils.ProjectName, 0, 0));
			}

			Point p = tw_objects.PointToClient(new Point(e.X, e.Y));
			tw_objects.SelectedNode = tw_objects.GetNodeAt(p);

			if (tw_objects.SelectedNode == null)
			{
				tw_objects.SelectedNode = tw_objects.Nodes[0];
			}
		}

		private void tw_objects_ItemDrag(object sender, ItemDragEventArgs e)
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

		private void tw_objects_KeyDown(object sender, KeyEventArgs e)
		{
			if (e.Control && e.KeyCode == Keys.C)
			{
				copyPaste = tw_objects.SelectedNode;
			}
		}

		private void tw_objects_KeyUp(object sender, KeyEventArgs e)
		{
			if (e.Control && e.KeyCode == Keys.V)
			{
				tw_objects.SelectedNode.Nodes.Add((TreeNode)copyPaste.Clone());
				tw_objects.SelectedNode.Expand();
			}
		}

		private void tw_objects_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
		{
			tw_objects.SelectedNode = e.Node;
			Utils.twTag twt = (Utils.twTag)tw_objects.SelectedNode.Tag;

			if (e.Button == MouseButtons.Right)
			{
				if (twt.getAttributeByName<bool>("modifiable"))
				{
					cms.Items[1].Enabled = true;
					cms.Items[2].Enabled = true;
					cms.Show(tw_objects, e.Location);
				}
				else
				{
					cms.Items[1].Enabled = false;
					cms.Items[2].Enabled = false;
					cms.Show(tw_objects, e.Location);
				}
			}
		}

		private bool ContainsNode(TreeNode n1, TreeNode n2)
		{
			if (n2.Parent == null) return false;
			if (n2.Parent.Equals(n1)) return true;

			return ContainsNode(n1, n2.Parent);
		}

		private void tw_objects_AfterSelect(object sender, TreeViewEventArgs e)
		{
			tw_objects.SelectedNode = e.Node;
		}

    }
}
