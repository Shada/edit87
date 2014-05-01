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
        public PanResources()
        {
            InitializeComponent();
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
    }
}
