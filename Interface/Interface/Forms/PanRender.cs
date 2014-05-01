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
    public partial class PanRender : DockContent
    {
        int pb_sceneSizeDiff = 0;
        public PanRender()
        {
            InitializeComponent();
        }

        private void PanRender_Load(object sender, EventArgs e)
        {

        }

        private void PanRender_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }
        private void resizeWindow()
        {
            pb_scene.Size = new Size(Size.Width - pb_sceneSizeDiff, Size.Height - pb_sceneSizeDiff);
        }
    }
}
