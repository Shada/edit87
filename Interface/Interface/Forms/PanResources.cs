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
    public partial class PanResources : DockContent
    {
        int tw_resourcesSizeDiff = 12;
        public TreeNode resourcesRoot;
		TreeNode copyPaste;

        public PanResources()
        {
            InitializeComponent();
		}

		public void init(TreeNode _rootNode)
		{
			resourcesRoot = _rootNode;

			Utils.twTag tag = new Utils.twTag(Utils.twTag.TYPE.FOLDER);
			tag.addAttribute(Utils.twTagAttribute.dataType.BOOL, "modifiable", false);

			resourcesRoot.Tag = tag;
			tw_resources.Nodes.Add(resourcesRoot);

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

			toolTipRes.AutomaticDelay = 0;
			toolTipRes.AutoPopDelay = 5000;
			toolTipRes.InitialDelay = 500;
			toolTipRes.ReshowDelay = 100;
			toolTipRes.UseAnimation = true;
			toolTipRes.UseFading = true;
		}

		private void twMenu_ClickRemove(object sender, EventArgs e)
		{
			Utils.twTag twt = (Utils.twTag)tw_resources.SelectedNode.Tag;

			if (tw_resources.SelectedNode.Nodes.Count != 0)
			{
				DialogResult res = MessageBox.Show("The selected folder is not empty!\nDo you want to continue?", "Warning!", MessageBoxButtons.YesNo);

				if (res == DialogResult.No)
				{
					return;
				}
			}

			tw_resources.SelectedNode.Remove();
			tw_resources.SelectedNode = tw_resources.Nodes[0];
		}

		private void twMenu_ClickRename(object sender, EventArgs e)
		{
			TreeNode tn = tw_resources.SelectedNode;
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
			tw_resources.SelectedNode.Nodes.Add(tn);
			tw_resources.SelectedNode.Expand();
		}

        private void PanResources_SizeChanged(object sender, EventArgs e)
        {
			tw_resources.Size = new Size(Size.Width - tw_resourcesSizeDiff, Size.Height - tw_resourcesSizeDiff - 44);
        }

        private void btn_importResource_Click(object sender, EventArgs e)
        {
            ImportResource res = new ImportResource(this);
            res.Show();
        }

        public void updateTWRes(TreeNode _tn)
        {
            tw_resources.Nodes.Clear();
            tw_resources.Nodes.Add((TreeNode)_tn.Clone());
            resourcesRoot = tw_resources.Nodes[0];
        }

		private void tw_resources_AfterSelect(object sender, TreeViewEventArgs e)
		{
			tw_resources.SelectedNode = e.Node;
		}

		private void tw_resources_DragDrop(object sender, DragEventArgs e)
		{
			Point p = tw_resources.PointToClient(new Point(e.X, e.Y));
			TreeNode ttn = tw_resources.GetNodeAt(p);
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

		private void tw_resources_DragEnter(object sender, DragEventArgs e)
		{
			e.Effect = e.AllowedEffect;
		}

		private void tw_resources_DragOver(object sender, DragEventArgs e)
		{
			Point p = tw_resources.PointToClient(new Point(e.X, e.Y));
			tw_resources.SelectedNode = tw_resources.GetNodeAt(p);
		}

		private void tw_resources_ItemDrag(object sender, ItemDragEventArgs e)
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

		private void tw_resources_KeyDown(object sender, KeyEventArgs e)
		{
			if (e.Control && e.KeyCode == Keys.C)
			{
				copyPaste = tw_resources.SelectedNode;
			}
		}

		private void tw_resources_KeyUp(object sender, KeyEventArgs e)
		{
			if (e.Control && e.KeyCode == Keys.V)
			{
				tw_resources.SelectedNode.Nodes.Add((TreeNode)copyPaste.Clone());
				tw_resources.SelectedNode.Expand();
			}
		}

		private void tw_resources_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
		{
			tw_resources.SelectedNode = e.Node;
			Utils.twTag twt = (Utils.twTag)tw_resources.SelectedNode.Tag;

			if (e.Button == MouseButtons.Right)
			{
				if (twt.getAttributeByName<bool>("modifiable"))
				{
					cms.Items[1].Enabled = true;
					cms.Items[2].Enabled = true;
					cms.Show(tw_resources, e.Location);
				}
				else
				{
					cms.Items[1].Enabled = false;
					cms.Items[2].Enabled = false;
					cms.Show(tw_resources, e.Location);
				}				
			}	
		}

		private bool ContainsNode(TreeNode n1, TreeNode n2)
		{
			if (n2.Parent == null) return false;
			if (n2.Parent.Equals(n1)) return true;

			return ContainsNode(n1, n2.Parent);
		}

		private void tw_resources_MouseMove(object sender, MouseEventArgs e)
		{
			TreeNode node = tw_resources.GetNodeAt(e.X, e.Y);

			if (node != null)
			{
				Utils.twTag tag = (Utils.twTag)node.Tag;

				switch (tag.Type)
				{
					case Utils.twTag.TYPE.IMAGE:
						string msg = "Modifiable: " + (tag.getAttributeByName<bool>("modifiable") == false ? "false" : "true") + "\n"
									+ "Real name: " + tag.getAttributeByName<string>("realname") + "\n"
									+ "Size: " + tag.getAttributeByName<float>("size") + " MB\n"
									+ "Dimensions: " + tag.getAttributeByName<int>("sizex") + " X " + tag.getAttributeByName<int>("sizey");


						if (toolTipRes.GetToolTip(tw_resources) != msg)
						{
							msg = "Modifiable: " + (tag.getAttributeByName<bool>("modifiable") == false ? "false" : "true") + "\n"
								+ "Real name: " + tag.getAttributeByName<string>("realname") + "\n"
								+ "Size: " + tag.getAttributeByName<float>("size") + " MB\n"
								+ "Dimensions: " + tag.getAttributeByName<int>("sizex") + " X " + tag.getAttributeByName<int>("sizey");

							toolTipRes.SetToolTip(tw_resources, msg);
						}
					break;
				}
			}
			else
			{
				toolTipRes.SetToolTip(tw_resources, "");
			}
		}
    }
}
