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
using System.Xml;

namespace LevelEditor
{
	public partial class NewProject : Form
	{
        MapEditor edit;

        public NewProject(MapEditor _edit)
        {
            InitializeComponent();

            edit = _edit;
            //projectFile = _projectFile;
            //projectDirectory = _projectDirectory;
            mtxb_mapSizeX.ValidatingType = typeof(uint);
            mtxb_mapSizeY.ValidatingType = typeof(uint);
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
            uint X, Y;

            if (Directory.Exists(folder))
            {
                MessageBox.Show("The working directory you have selected already exists", "No can do!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            try
            {
                X = (uint)mtxb_mapSizeX.ValidateText();
            }
            catch
            {
                MessageBox.Show("The X value for map size is invalid", "No can do!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            try
            {
                Y = (uint)mtxb_mapSizeY.ValidateText();
            }
            catch
            {
                MessageBox.Show("The Y value for map size is invalid", "No can do!", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            edit.projectDirectory = Directory.CreateDirectory(folder);
			//Directory.CreateDirectory(folder + "\\brushes");
			//Directory.CreateDirectory(folder + "\\resources");
			//Directory.CreateDirectory(folder + "\\maps");

            using (XmlTextWriter writer = new XmlTextWriter(folder + "\\" + txb_projectName.Text + ".xml", Encoding.UTF8))
            {
                writer.Formatting = Formatting.Indented;
                writer.Indentation = 4;

                writer.WriteStartDocument();
                writer.WriteStartElement("root");

                writer.WriteStartElement("header");
                writer.WriteElementString("projectName", txb_projectName.Text);

                writer.WriteStartElement("size");
                writer.WriteElementString("X", X.ToString());
                writer.WriteElementString("Y", Y.ToString());
                writer.WriteEndElement(); //SIZE
                writer.WriteEndElement(); //HEADER
                writer.WriteEndElement(); //ROOT
                writer.WriteEndDocument();
            }

            edit.projectFile.Load(folder + "\\" + txb_projectName.Text + ".xml");
			edit.projectName = txb_projectName.Text;
			edit.initPanels();
			
            this.Close();
        }
	}
}
