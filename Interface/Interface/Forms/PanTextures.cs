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
    public partial class PanTextures : DockContent
    {
        int lv_TexturesSizeDiff = 12;
		List<Image> FullImages = new List<System.Drawing.Image>();

        public PanTextures()
        {
            InitializeComponent();
        }

		public void addImages(Image _img)
		{
			FullImages.Add(_img);
			textureList.Images.Add(_img);
			lv_Textures.Update();
		}

        private void PanTextures_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }
        private void resizeWindow()
        {
            lv_Textures.Size = new Size(Size.Width - lv_TexturesSizeDiff, Size.Height - lv_TexturesSizeDiff - 24);
        }

        private void PanTextures_FormClosing(object sender, FormClosingEventArgs e)
        {
            Utils.Panels.removePanel(this.GetType().ToString());
        }
    }
}
