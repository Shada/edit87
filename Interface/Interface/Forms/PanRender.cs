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
    public partial class PanRender : Form
    {
        int pb_sceneSizeDiff = 0;
        public PanRender()
        {
            InitializeComponent();
            this.Enabled = false;
            this.Activated += new EventHandler(PanRender_Activated);
        }

        private void PanRender_Activated(object sender, EventArgs e)
        {
            this.Owner.Activate();
        }

        private void PanRender_Load(object sender, EventArgs e)
        {

        }

        protected override void DefWndProc(ref Message m)
        {
            switch (m.Msg)
            {
                case 0x21:
                    m.Result = (IntPtr)0x0003;
                    return;
            }
            base.DefWndProc(ref m);
        }

        private void PanRender_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }
        private void resizeWindow()
        {
        }
    }
}
