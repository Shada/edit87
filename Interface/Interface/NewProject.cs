using System;
using System.Text;
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

			Utils.ProjectDirectory = Directory.CreateDirectory(folder);

			File.Copy(Environment.CurrentDirectory + "\\..\\textures\\grass.png", Utils.ProjectDirectory.FullName + "\\grass.png");
			File.Copy(Environment.CurrentDirectory + "\\..\\textures\\ground.png", Utils.ProjectDirectory.FullName + "\\ground.png");
			File.Copy(Environment.CurrentDirectory + "\\..\\textures\\lava.png", Utils.ProjectDirectory.FullName + "\\lava.png");
			File.Copy(Environment.CurrentDirectory + "\\..\\textures\\lavag.png", Utils.ProjectDirectory.FullName + "\\lavag.png");
			File.Copy(Environment.CurrentDirectory + "\\..\\textures\\sand.png", Utils.ProjectDirectory.FullName + "\\sand.png");

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
				writer.WriteStartElement("resources");
				writer.WriteEndElement(); //RESOURCES
				writer.WriteStartElement("library");
				writer.WriteEndElement(); //LIBRARY
				writer.WriteStartElement("textures");
				writer.WriteEndElement(); //TEXTURES
                writer.WriteEndElement(); //ROOT
                writer.WriteEndDocument();
            }

			Utils.ProjectFile.Load(folder + "\\" + txb_projectName.Text + ".xml");
			Utils.ProjectName = txb_projectName.Text;
			edit.initPanels();
			edit.saveProject();
			
            Close();
        }
	}
}
