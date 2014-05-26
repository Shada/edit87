using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CookComputing.XmlRpc;
using JetBrains.ProjectModel.Properties.Managed;
using JetBrains.Util;
using WeifenLuo.WinFormsUI.Docking;

namespace LevelEditor
{
    public partial class PanTextures : DockContent
    {
        int lv_TexturesSizeDiff = 12;
		private List<Utils.twTag> tags = new List<Utils.twTag>(); 

        public PanTextures()
        {
	        InitializeComponent();
        }

	    public void initDefTex()
	    {
			string[] defStrings = new[] { "grass", "ground", "lava", "lavag", "sand" };

		    for (int i = 0; i < defStrings.Length; i++)
		    {
			    string file = Utils.ProjectDirectory.FullName + "\\" + defStrings[i] + ".png";
			    Image img = Image.FromFile(file);
			    float fileSize = (float) Math.Round((new FileInfo(file).Length)/1000000.0f, 2);

			    Utils.twTag tag = new Utils.twTag(Utils.twTag.TYPE.IMAGE);
			    tag.addAttribute(Utils.twTagAttribute.dataType.BOOL, "modifiable", true);
			    tag.addAttribute(Utils.twTagAttribute.dataType.STRING, "realname", defStrings[i] + ".png");
			    tag.addAttribute(Utils.twTagAttribute.dataType.STRING, "path", file);
			    tag.addAttribute(Utils.twTagAttribute.dataType.FLOAT, "size", fileSize);
			    tag.addAttribute(Utils.twTagAttribute.dataType.INT, "sizex", img.Width);
			    tag.addAttribute(Utils.twTagAttribute.dataType.INT, "sizey", img.Height);
			    tag.addAttribute(Utils.twTagAttribute.dataType.STRING, "showname", defStrings[i]);

			    textureList.Images.Add(img);
				tags.Add(tag);
			    lv_Textures.Items.Add(new ListViewItem(defStrings[i], i));
		    }
	    }

		public List<Utils.twTag> TexTags 
		{
			get { return tags; }
			set
			{
				tags = value;
				int counter = 0;

				foreach (Utils.twTag tag in tags)
				{
					textureList.Images.Add(Image.FromFile(tag.getAttributeByName<string>("path")));
					lv_Textures.Items.Add(new ListViewItem(tag.getAttributeByName<string>("showname"), counter));
					counter++;
				}
			}
		}

	    public void addImages(Image _img)
		{
			textureList.Images.Add(_img);
			var name = _img.Tag as Utils.twTag;
			lv_Textures.Items.Add(new ListViewItem(name.getAttributeByName<string>("showname"), textureList.Images.Count - 1));
		}

        private void PanTextures_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }
        private void resizeWindow()
        {
            lv_Textures.Size = new Size(Size.Width - lv_TexturesSizeDiff, Size.Height - lv_TexturesSizeDiff - 24);
        }

		private void lv_Textures_SelectedIndexChanged(object sender, EventArgs e)
		{
			var list = lv_Textures.SelectedIndices;
			Utils.Graphics.gfx.setBrushTexture(tags[list[0]].getAttributeByName<string>("path"));
		}
    }
}
