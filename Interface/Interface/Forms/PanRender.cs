using System;
using System.Drawing;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;

namespace LevelEditor
{
    public partial class PanRender : DockContent
    {
		MapEditor editor;
        private IntPtr win;

		public PanRender(MapEditor _editor)
        {
            InitializeComponent();
			editor = _editor;
		
			resizeRenderPanel();

		    win = drawSurface.Handle;

			Utils.Graphics.Init();
            Utils.Graphics.Addhandle(win, "main", this.Size.Width, this.Size.Height);
			Utils.Graphics.gfx.createTerrain(256, 256, 5, false, 0);
        }

		public void resizeRenderPanel()
		{
			if (!drawSurface.IsDisposed)
			{
				drawSurface.Bounds = new Rectangle(editor.Bounds.X + this.Bounds.Left + 8,
													editor.Bounds.Y + this.Bounds.Y + 55,
													this.Bounds.Width + 1,
													this.Bounds.Height - 6);

                if (Utils.Graphics.gfx != null && drawSurface.Size.Width != 0)
                    Utils.Graphics.gfx.resizeWindow(drawSurface.Size.Width, drawSurface.Size.Height);
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
		    if (drawSurface.Handle != win)
		    {
		        win = drawSurface.Handle;
                Utils.Graphics.gfx.updateHandle(win, "main", drawSurface.Size.Width, drawSurface.Size.Height);
		    }
		}
    }
}
