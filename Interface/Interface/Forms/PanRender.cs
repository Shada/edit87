using System;
using System.Drawing;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;

namespace LevelEditor
{
    public partial class PanRender : DockContent
    {
		MapEditor editor;

		public PanRender(MapEditor _editor)
        {
            InitializeComponent();
			editor = _editor;
		
			resizeRenderPanel();

			Utils.Graphics.Init();
			Utils.Graphics.Sethandle(drawSurface.Handle, "main");
			Utils.Graphics.gfx.createTerrain(256, 256, 5, false, 0);
			Utils.Graphics.gfx.resizeWindow(this.Size.Width, this.Size.Height);
        }

		public void resizeRenderPanel()
		{
			if (!drawSurface.IsDisposed)
			{
				drawSurface.Bounds = new Rectangle(editor.Bounds.X + this.Bounds.Left + 8,
													editor.Bounds.Y + this.Bounds.Y + 55,
													this.Bounds.Width + 1,
													this.Bounds.Height - 6);

				if (Utils.Graphics.gfx != null)
				Utils.Graphics.gfx.resizeWindow(this.Size.Width, this.Size.Height);
			}
		}

        private void PanRender_Load(object sender, EventArgs e)
        {

        }

        private void PanRender_SizeChanged(object sender, EventArgs e)
        {
			resizeRenderPanel();
        }

		private void PanRender_DockStateChanged(object sender, EventArgs e)
		{
			//Utils.Graphics.Sethandle(drawSurface.Handle, "main");
		}
    }
}
