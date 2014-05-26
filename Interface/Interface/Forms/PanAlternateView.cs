using System;
using System.Drawing;
using System.Windows.Forms;
using WeifenLuo.WinFormsUI.Docking;

namespace LevelEditor
{
    public partial class PanAlternateView : DockContent
    {
        MapEditor editor;
        private IntPtr win;

        public PanAlternateView(MapEditor _editor)
        {
            InitializeComponent();

            editor = _editor;
            win = drawSurface.Handle;

            Utils.Graphics.Addhandle(win, "minimap", drawSurface.Size.Width, drawSurface.Size.Height);
        }

        public void resizeRenderPanel()
        {
            if (!drawSurface.IsDisposed)
            {
                drawSurface.Bounds = new Rectangle( editor.Bounds.X + this.Bounds.Left + 8,
                                                    editor.Bounds.Y + this.Bounds.Y + 55,
                                                    this.Bounds.Width + 1,
                                                    this.Bounds.Height - 6);

                if (Utils.Graphics.gfx != null && drawSurface.Size.Width != 0)
                    Utils.Graphics.gfx.resizeWindow(drawSurface.Size.Width, drawSurface.Size.Height, "minimap");
            }
        }

        private void PanAlternateView_DockStateChanged(object sender, EventArgs e)
        {
            if (drawSurface.Handle != win)
            {
                win = drawSurface.Handle;
                Utils.Graphics.gfx.updateHandle(win, "minimap", drawSurface.Size.Width, drawSurface.Size.Height);
            }
        }

        private void PanAlternateView_SizeChanged(object sender, EventArgs e)
        {
            resizeRenderPanel();
        }
    }
}
