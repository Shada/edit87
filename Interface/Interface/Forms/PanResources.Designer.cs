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
			this.tw_resources = new System.Windows.Forms.TreeView();
			this.imageList = new System.Windows.Forms.ImageList(this.components);
			this.btn_importResource = new System.Windows.Forms.Button();
			this.cms = new System.Windows.Forms.ContextMenuStrip(this.components);
			this.toolTipRes = new System.Windows.Forms.ToolTip(this.components);
			this.SuspendLayout();
			// 
			// tw_resources
			// 
			this.tw_resources.AllowDrop = true;
			this.tw_resources.Dock = System.Windows.Forms.DockStyle.Bottom;
			this.tw_resources.ImageIndex = 0;
			this.tw_resources.ImageList = this.imageList;
			this.tw_resources.Location = new System.Drawing.Point(0, 50);
			this.tw_resources.Name = "tw_resources";
			this.tw_resources.SelectedImageIndex = 0;
			this.tw_resources.Size = new System.Drawing.Size(200, 200);
			this.tw_resources.TabIndex = 4;
			this.tw_resources.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.tw_resources_ItemDrag);
			this.tw_resources.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tw_resources_AfterSelect);
			this.tw_resources.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.tw_resources_NodeMouseClick);
			this.tw_resources.DragDrop += new System.Windows.Forms.DragEventHandler(this.tw_resources_DragDrop);
			this.tw_resources.DragEnter += new System.Windows.Forms.DragEventHandler(this.tw_resources_DragEnter);
			this.tw_resources.DragOver += new System.Windows.Forms.DragEventHandler(this.tw_resources_DragOver);
			this.tw_resources.KeyDown += new System.Windows.Forms.KeyEventHandler(this.tw_resources_KeyDown);
			this.tw_resources.KeyUp += new System.Windows.Forms.KeyEventHandler(this.tw_resources_KeyUp);
			this.tw_resources.MouseMove += new System.Windows.Forms.MouseEventHandler(this.tw_resources_MouseMove);
			// 
			// imageList
			// 
			this.imageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList.ImageStream")));
			this.imageList.TransparentColor = System.Drawing.Color.Transparent;
			this.imageList.Images.SetKeyName(0, "folder");
			this.imageList.Images.SetKeyName(1, "img");
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
			// cms
			// 
			this.cms.Name = "cms";
			this.cms.Size = new System.Drawing.Size(61, 4);
			// 
			// PanResources
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(200, 250);
			this.Controls.Add(this.tw_resources);
			this.Controls.Add(this.btn_importResource);
			this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
			this.Name = "PanResources";
			this.Text = "PanResources";
			this.SizeChanged += new System.EventHandler(this.PanResources_SizeChanged);
			this.ResumeLayout(false);

        }

        #endregion

		private System.Windows.Forms.TreeView tw_resources;
        private System.Windows.Forms.Button btn_importResource;
        private System.Windows.Forms.ImageList imageList;
		private System.Windows.Forms.ContextMenuStrip cms;
		private System.Windows.Forms.ToolTip toolTipRes;
    }
}