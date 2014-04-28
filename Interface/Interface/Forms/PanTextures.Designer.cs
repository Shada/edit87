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
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem(new string[] {
            "Dirt",
            "Test"}, 0);
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem("Grass", 1);
            System.Windows.Forms.ListViewItem listViewItem3 = new System.Windows.Forms.ListViewItem("Rock", 2);
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PanTextures));
            this.btn_importTexture = new System.Windows.Forms.Button();
            this.lv_Textures = new System.Windows.Forms.ListView();
            this.textureList = new System.Windows.Forms.ImageList(this.components);
            this.label8 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btn_importTexture
            // 
            this.btn_importTexture.Location = new System.Drawing.Point(90, 3);
            this.btn_importTexture.Name = "btn_importTexture";
            this.btn_importTexture.Size = new System.Drawing.Size(90, 23);
            this.btn_importTexture.TabIndex = 33;
            this.btn_importTexture.Text = "Import texture";
            this.btn_importTexture.UseVisualStyleBackColor = true;
            // 
            // lv_Textures
            // 
            this.lv_Textures.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1,
            listViewItem2,
            listViewItem3});
            this.lv_Textures.LargeImageList = this.textureList;
            this.lv_Textures.Location = new System.Drawing.Point(0, 32);
            this.lv_Textures.Name = "lv_Textures";
            this.lv_Textures.Size = new System.Drawing.Size(180, 141);
            this.lv_Textures.TabIndex = 31;
            this.lv_Textures.UseCompatibleStateImageBehavior = false;
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
            this.label8.Location = new System.Drawing.Point(3, 8);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(46, 13);
            this.label8.TabIndex = 32;
            this.label8.Text = "Texture:";
            // 
            // PanTextures
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(181, 174);
            this.Controls.Add(this.btn_importTexture);
            this.Controls.Add(this.lv_Textures);
            this.Controls.Add(this.label8);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "PanTextures";
            this.Text = "PanTextures";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_importTexture;
        private System.Windows.Forms.ListView lv_Textures;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ImageList textureList;
    }
}