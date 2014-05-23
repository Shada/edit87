namespace LevelEditor
{
    partial class PanBrushes
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem(new string[] {
            "B1",
            "Test"}, 0);
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem("B2", 1);
            System.Windows.Forms.ListViewItem listViewItem3 = new System.Windows.Forms.ListViewItem("B3", 2);
            System.Windows.Forms.ListViewItem listViewItem4 = new System.Windows.Forms.ListViewItem("B4", 3);
            System.Windows.Forms.ListViewItem listViewItem5 = new System.Windows.Forms.ListViewItem("B5", 4);
            System.Windows.Forms.ListViewItem listViewItem6 = new System.Windows.Forms.ListViewItem("B6", 5);
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PanBrushes));
            this.lw_Brush = new System.Windows.Forms.ListView();
            this.brushList = new System.Windows.Forms.ImageList(this.components);
            this.nud_BrushSize = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.btn_importBrush = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.nud_brushIntensity = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.btn_TextureBrush = new System.Windows.Forms.Button();
            this.btn_TerrainBrush = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.nud_BrushSize)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nud_brushIntensity)).BeginInit();
            this.SuspendLayout();
            // 
            // lw_Brush
            // 
            this.lw_Brush.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1,
            listViewItem2,
            listViewItem3,
            listViewItem4,
            listViewItem5,
            listViewItem6});
            this.lw_Brush.LargeImageList = this.brushList;
            this.lw_Brush.Location = new System.Drawing.Point(12, 161);
            this.lw_Brush.Name = "lw_Brush";
            this.lw_Brush.Size = new System.Drawing.Size(159, 169);
            this.lw_Brush.TabIndex = 32;
            this.lw_Brush.UseCompatibleStateImageBehavior = false;
            // 
            // brushList
            // 
            this.brushList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("brushList.ImageStream")));
            this.brushList.TransparentColor = System.Drawing.Color.Transparent;
            this.brushList.Images.SetKeyName(0, "circle.png");
            this.brushList.Images.SetKeyName(1, "diag01.png");
            this.brushList.Images.SetKeyName(2, "spots01.png");
            this.brushList.Images.SetKeyName(3, "square.png");
            this.brushList.Images.SetKeyName(4, "thinHorizontal.png");
            this.brushList.Images.SetKeyName(5, "thinVertical.png");
            // 
            // nud_BrushSize
            // 
            this.nud_BrushSize.Location = new System.Drawing.Point(62, 77);
            this.nud_BrushSize.Name = "nud_BrushSize";
            this.nud_BrushSize.Size = new System.Drawing.Size(50, 20);
            this.nud_BrushSize.TabIndex = 33;
            this.nud_BrushSize.ValueChanged += new System.EventHandler(this.nud_BrushSize_ValueChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(3, 105);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(49, 13);
            this.label6.TabIndex = 34;
            this.label6.Text = "Intensity:";
            // 
            // btn_importBrush
            // 
            this.btn_importBrush.Location = new System.Drawing.Point(41, 132);
            this.btn_importBrush.Name = "btn_importBrush";
            this.btn_importBrush.Size = new System.Drawing.Size(90, 23);
            this.btn_importBrush.TabIndex = 40;
            this.btn_importBrush.Text = "Import brush";
            this.btn_importBrush.UseVisualStyleBackColor = true;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(3, 137);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(37, 13);
            this.label7.TabIndex = 35;
            this.label7.Text = "Brush:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(3, 79);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(30, 13);
            this.label5.TabIndex = 39;
            this.label5.Text = "Size:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(59, 5);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(43, 13);
            this.label2.TabIndex = 36;
            this.label2.Text = "Texture";
            // 
            // nud_brushIntensity
            // 
            this.nud_brushIntensity.Location = new System.Drawing.Point(62, 103);
            this.nud_brushIntensity.Name = "nud_brushIntensity";
            this.nud_brushIntensity.Size = new System.Drawing.Size(50, 20);
            this.nud_brushIntensity.TabIndex = 38;
            this.nud_brushIntensity.ValueChanged += new System.EventHandler(this.nud_brushIntensity_ValueChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(3, 5);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(40, 13);
            this.label4.TabIndex = 37;
            this.label4.Text = "Terrain";
            // 
            // btn_TextureBrush
            // 
            this.btn_TextureBrush.BackgroundImage = global::Interface.Properties.Resources.brush;
            this.btn_TextureBrush.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btn_TextureBrush.Location = new System.Drawing.Point(62, 21);
            this.btn_TextureBrush.Name = "btn_TextureBrush";
            this.btn_TextureBrush.Size = new System.Drawing.Size(50, 50);
            this.btn_TextureBrush.TabIndex = 31;
            this.btn_TextureBrush.UseVisualStyleBackColor = true;
            // 
            // btn_TerrainBrush
            // 
            this.btn_TerrainBrush.BackgroundImage = global::Interface.Properties.Resources.brush;
            this.btn_TerrainBrush.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btn_TerrainBrush.Location = new System.Drawing.Point(6, 21);
            this.btn_TerrainBrush.Name = "btn_TerrainBrush";
            this.btn_TerrainBrush.Size = new System.Drawing.Size(50, 50);
            this.btn_TerrainBrush.TabIndex = 30;
            this.btn_TerrainBrush.UseVisualStyleBackColor = true;
            // 
            // PanBrushes
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(183, 342);
            this.Controls.Add(this.btn_TextureBrush);
            this.Controls.Add(this.btn_TerrainBrush);
            this.Controls.Add(this.lw_Brush);
            this.Controls.Add(this.nud_BrushSize);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.btn_importBrush);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.nud_brushIntensity);
            this.Controls.Add(this.label4);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "PanBrushes";
            this.Text = "PanBrushes";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.PanBrushes_FormClosing);
            this.SizeChanged += new System.EventHandler(this.PanBrushes_SizeChanged);
            ((System.ComponentModel.ISupportInitialize)(this.nud_BrushSize)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nud_brushIntensity)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_TextureBrush;
        private System.Windows.Forms.Button btn_TerrainBrush;
        private System.Windows.Forms.ListView lw_Brush;
        private System.Windows.Forms.NumericUpDown nud_BrushSize;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button btn_importBrush;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown nud_brushIntensity;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ImageList brushList;
    }
}