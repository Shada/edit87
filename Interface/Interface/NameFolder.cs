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
    public partial class NameFolder : Form
    {
TreeNode tn;

		public NameFolder(ref TreeNode _tn)
		{
			InitializeComponent();
			tn = _tn;
			txb_newName.Text = _tn.Text;
		}

		private void btn_change_Click(object sender, EventArgs e)
		{
			tn.Text = txb_newName.Text;
			this.Close();
		}

		private void txb_newName_KeyPress(object sender, KeyPressEventArgs e)
		{
			if (e.KeyChar == 13)
			{
				tn.Text = txb_newName.Text;
				this.Close();
			}
		}
    }
}
