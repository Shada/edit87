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
using wrap;

namespace LevelEditor
{
    public partial class PanRender : DockContent
    {
		private bool renderWindowActivated = true;

		MapEditor editor;

		public PanRender(MapEditor _editor)
        {
            InitializeComponent();
			editor = _editor;
		
			resizeRenderPanel();

			//if (drawSurface.IsHandleCreated)
			//{
			Utils.Graphics.Init();
			Utils.Graphics.Sethandle(drawSurface.Handle, "main");
			//}
			//else
			//{
			//	renderWindowActivated = false;
			//}

			if (renderWindowActivated)
			{
				Utils.Graphics.gfx.createTerrain(256, 256, 5, false, 0);
			}
        }

		public bool RenderActive
		{
			get { return renderWindowActivated; }
		}

		public void resizeRenderPanel()
		{
			if (!drawSurface.IsDisposed)
			{
				drawSurface.Bounds = new Rectangle(editor.Bounds.X + this.Bounds.Left + 8,
													editor.Bounds.Y + this.Bounds.Y + 55,
													this.Bounds.Width + 1,
													this.Bounds.Height - 6);
			}
		}

        private void PanRender_Load(object sender, EventArgs e)
        {

        }

        private void PanRender_SizeChanged(object sender, EventArgs e)
        {
			resizeRenderPanel();
        }
    }
}
