namespace LevelEditor
{
    partial class PanResources
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PanResources));
            this.label9 = new System.Windows.Forms.Label();
            this.tw_resources = new System.Windows.Forms.TreeView();
            this.btn_importResource = new System.Windows.Forms.Button();
            this.imageList = new System.Windows.Forms.ImageList(this.components);
            this.SuspendLayout();
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(1, 30);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(58, 13);
            this.label9.TabIndex = 5;
            this.label9.Text = "Resources";
            // 
            // tw_resources
            // 
            this.tw_resources.ImageIndex = 0;
            this.tw_resources.ImageList = this.imageList;
            this.tw_resources.Location = new System.Drawing.Point(3, 45);
            this.tw_resources.Name = "tw_resources";
            this.tw_resources.SelectedImageIndex = 0;
            this.tw_resources.Size = new System.Drawing.Size(190, 200);
            this.tw_resources.TabIndex = 4;
            // 
            // btn_importResource
            // 
            this.btn_importResource.Location = new System.Drawing.Point(8, 4);
            this.btn_importResource.Name = "btn_importResource";
            this.btn_importResource.Size = new System.Drawing.Size(180, 23);
            this.btn_importResource.TabIndex = 3;
            this.btn_importResource.Text = "Import resource";
            this.btn_importResource.UseVisualStyleBackColor = true;
            this.btn_importResource.Click += new System.EventHandler(this.btn_importResource_Click);
            // 
            // imageList
            // 
            this.imageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList.ImageStream")));
            this.imageList.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList.Images.SetKeyName(0, "folder");
            this.imageList.Images.SetKeyName(1, "img");
            // 
            // PanResources
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(200, 250);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.tw_resources);
            this.Controls.Add(this.btn_importResource);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "PanResources";
            this.Text = "PanResources";
            this.Load += new System.EventHandler(this.PanResources_Load);
            this.SizeChanged += new System.EventHandler(this.PanResources_SizeChanged);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TreeView tw_resources;
        private System.Windows.Forms.Button btn_importResource;
        private System.Windows.Forms.ImageList imageList;
    }
}