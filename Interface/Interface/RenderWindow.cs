using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LevelEditor
{
    public partial class RenderWindow : Form
    {
        public RenderWindow()
        {
            InitializeComponent();
			this.Visible = true;
        }

        private void RenderWindow_Load(object sender, EventArgs e)
        {

        }

        private void RenderWindow_Activated(object sender, EventArgs e)
        {
            this.Owner.Activate();
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
    }
}
