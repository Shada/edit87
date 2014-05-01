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
    public partial class PanProperties : DockContent
    {
        int pgTestSizeDiff = 12;
        public PanProperties()
        {
            InitializeComponent();
        }

        private void PanProperties_Load(object sender, EventArgs e)
        {

        }

        private void resizeWindow()
        {
            PG_test.Size = new Size(Size.Width - pgTestSizeDiff, Size.Height - pgTestSizeDiff);
        }

        private void PanProperties_Resize(object sender, EventArgs e)
        {
            //resizeWindow();
        }

        private void PanProperties_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }
    }
}
