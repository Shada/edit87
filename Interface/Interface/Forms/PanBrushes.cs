﻿using System;
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
    public partial class PanBrushes : DockContent
    {
        private int lw_BrushSizeDiff = 12;
		private int brushSize, brushIntensity;

		public int BrushSize { get { return brushSize; } }
		public int BrushIntensity { get { return brushIntensity; } }

        public PanBrushes()
        {
            InitializeComponent();
        }

        private void PanBrushes_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }
        private void resizeWindow()
        {
            lw_Brush.Size = new Size(Size.Width - lw_BrushSizeDiff, Size.Height - lw_BrushSizeDiff - 150);
        }

		private void nud_BrushSize_ValueChanged(object sender, EventArgs e)
		{
			NumericUpDown send = (NumericUpDown)sender;
			brushSize = (int)send.Value;
		}

		private void nud_brushIntensity_ValueChanged(object sender, EventArgs e)
		{
			NumericUpDown send = (NumericUpDown)sender;
			brushIntensity = (int)send.Value;
		}

        private void PanBrushes_FormClosing(object sender, FormClosingEventArgs e)
        {
            Utils.Panels.removePanel(this.GetType().ToString());
        }
    }
}
