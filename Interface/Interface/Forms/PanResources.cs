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
        public TreeNode resourcesRoot = new TreeNode("Root", 0, 0);
        public PanResources()
        {
            InitializeComponent();
            resourcesRoot.Tag = new Utils.twTag(Utils.twTag.Type.FOLDER, false);
            tw_resources.Nodes.Add(resourcesRoot);
        }

        private void PanResources_Load(object sender, EventArgs e)
        {

        }

        private void PanResources_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }
        private void resizeWindow()
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
    }
}
