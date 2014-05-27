namespace LevelEditor
{
    partial class PanTextures
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PanTextures));
            this.lv_Textures = new System.Windows.Forms.ListView();
            this.textureList = new System.Windows.Forms.ImageList(this.components);
            this.label8 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lv_Textures
            // 
            this.lv_Textures.LargeImageList = this.textureList;
            this.lv_Textures.Location = new System.Drawing.Point(6, 32);
            this.lv_Textures.Name = "lv_Textures";
            this.lv_Textures.Size = new System.Drawing.Size(180, 141);
            this.lv_Textures.SmallImageList = this.textureList;
            this.lv_Textures.TabIndex = 31;
            this.lv_Textures.UseCompatibleStateImageBehavior = false;
            this.lv_Textures.SelectedIndexChanged += new System.EventHandler(this.lv_Textures_SelectedIndexChanged);
            // 
            // textureList
            // 
            this.textureList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("textureList.ImageStream")));
            this.textureList.TransparentColor = System.Drawing.Color.Transparent;
            this.textureList.Images.SetKeyName(0, "dirt.png");
            this.textureList.Images.SetKeyName(1, "grass.png");
            this.textureList.Images.SetKeyName(2, "rock.png");
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(7, 8);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(46, 13);
            this.label8.TabIndex = 32;
            this.label8.Text = "Texture:";
            // 
            // PanTextures
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(184, 182);
            this.Controls.Add(this.lv_Textures);
            this.Controls.Add(this.label8);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "PanTextures";
            this.Text = "PanTextures";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.PanTextures_FormClosing);
            this.SizeChanged += new System.EventHandler(this.PanTextures_SizeChanged);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

		private System.Windows.Forms.ListView lv_Textures;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ImageList textureList;
    }
}