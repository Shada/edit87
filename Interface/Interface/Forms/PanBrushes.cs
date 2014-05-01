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
    public partial class PanBrushes : DockContent
    {
        int lw_BrushSizeDiff = 12;
        public PanBrushes()
        {
            InitializeComponent();
        }

        private void PanBrushes_Load(object sender, EventArgs e)
        {
        }

        private void PanBrushes_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }
        private void resizeWindow()
        {
            lw_Brush.Size = new Size(Size.Width - lw_BrushSizeDiff, Size.Height - lw_BrushSizeDiff - 150);
        }
    }
}
