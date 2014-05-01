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
        public PanLibrary()
        {
            InitializeComponent();
        }

        private void PanLibrary_Load(object sender, EventArgs e)
        {

        }

        private void PanLibrary_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }

        private void resizeWindow()
        {
            panel_Left.Size = new Size(Size.Width - twObjectsSizeDiff, Size.Height - twObjectsSizeDiff);
            tw_objects.Size = new Size(Size.Width - twObjectsSizeDiff - 20, tw_objects.Height);
        }

    }
}
