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

		public void update(Utils.twTag _tagInfo)
		{
			PropertyMesh m = new PropertyMesh();
			m.Position = new Vector3(45,42,86);
			m.PolygonCount = uint.MaxValue;
			m.RealName = _tagInfo.getAttributeByName<string>("realname");
			m.Rotation = new Vector3(67,86,12);
			m.Scale = new Vector3(98,36,74);
			m.ShowName = _tagInfo.getAttributeByName<string>("showname");
			pg_object.SelectedObject = m;
		}

        private void PanProperties_Load(object sender, EventArgs e)
        {

        }

        private void resizeWindow()
        {
            pg_object.Size = new Size(Size.Width - pgTestSizeDiff, Size.Height - pgTestSizeDiff);
        }

        private void PanProperties_Resize(object sender, EventArgs e)
        {
            //resizeWindow();
        }

        private void PanProperties_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }

        private void PanProperties_FormClosing(object sender, FormClosingEventArgs e)
        {
            Utils.Panels.removePanel(this.GetType().ToString());
        }
    }
}
