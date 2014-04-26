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
	public partial class properties_test : Form
	{
		ObjectProperties properties = new ObjectProperties();
		public properties_test()
		{
			InitializeComponent();
			PG_test.SelectedObject = properties;
		}
	}
}
