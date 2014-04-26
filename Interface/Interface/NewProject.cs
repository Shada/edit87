using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace LevelEditor
{
	public partial class NewProject : Form
	{
		public NewProject()
		{
			InitializeComponent();
		}

		private void btn_browseDirectory_Click(object sender, EventArgs e)
		{
			DialogResult res = fbd_workingDirectory.ShowDialog();

			if (res == DialogResult.OK)
			{
				txb_workingDirectory.Text = fbd_workingDirectory.SelectedPath;				
			}
		}

		private void btn_createParoject_Click(object sender, EventArgs e)
		{
			string folder = txb_workingDirectory.Text + "\\" + txb_projectName.Text;

			if (Directory.Exists(folder))
			{
				MessageBox.Show("The working directory you have selected already exists", "No can do!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
				return;
			}

			DirectoryInfo di = Directory.CreateDirectory(folder);
		}
	}
}
