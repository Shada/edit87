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
    public partial class PanRender : DockContent
    {
        public PanRender()
        {
            InitializeComponent();
        }

        private void PanRender_Load(object sender, EventArgs e)
        {

        }

        private void PanRender_SizeChanged(object sender, EventArgs e)
        {
            resizeWindow();
        }
        private void resizeWindow()
        {
        }
    }
}
