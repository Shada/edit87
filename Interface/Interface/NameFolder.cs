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
	public partial class RenameFolder : Form
	{
		TreeNode tn;

		public RenameFolder(ref TreeNode _tn)
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
	}
}
