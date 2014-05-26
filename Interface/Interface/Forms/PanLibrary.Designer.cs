namespace LevelEditor
{
    partial class PanLibrary
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(PanLibrary));
            this.cms = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.tw_objects = new System.Windows.Forms.TreeView();
            this.imageList = new System.Windows.Forms.ImageList(this.components);
            this.SuspendLayout();
            // 
            // cms
            // 
            this.cms.Name = "cms";
            this.cms.Size = new System.Drawing.Size(61, 4);
            // 
            // tw_objects
            // 
            this.tw_objects.AllowDrop = true;
            this.tw_objects.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tw_objects.ImageIndex = 0;
            this.tw_objects.ImageList = this.imageList;
            this.tw_objects.Location = new System.Drawing.Point(0, 0);
            this.tw_objects.Name = "tw_objects";
            this.tw_objects.SelectedImageIndex = 0;
            this.tw_objects.Size = new System.Drawing.Size(247, 621);
            this.tw_objects.TabIndex = 7;
            this.tw_objects.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.tw_objects_ItemDrag);
            this.tw_objects.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tw_objects_AfterSelect);
            this.tw_objects.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.tw_objects_NodeMouseClick);
            this.tw_objects.DragDrop += new System.Windows.Forms.DragEventHandler(this.tw_objects_DragDrop);
            this.tw_objects.DragEnter += new System.Windows.Forms.DragEventHandler(this.tw_objects_DragEnter);
            this.tw_objects.DragOver += new System.Windows.Forms.DragEventHandler(this.tw_objects_DragOver);
            this.tw_objects.KeyDown += new System.Windows.Forms.KeyEventHandler(this.tw_objects_KeyDown);
            this.tw_objects.KeyUp += new System.Windows.Forms.KeyEventHandler(this.tw_objects_KeyUp);
            // 
            // imageList
            // 
            this.imageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList.ImageStream")));
            this.imageList.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList.Images.SetKeyName(0, "folder");
            this.imageList.Images.SetKeyName(1, "img");
            // 
            // PanLibrary
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(247, 621);
            this.Controls.Add(this.tw_objects);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.SystemColors.ControlText;
            this.Name = "PanLibrary";
            this.Text = "Library";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.PanLibrary_FormClosing);
            this.SizeChanged += new System.EventHandler(this.PanLibrary_SizeChanged);
            this.ResumeLayout(false);

        }

        #endregion

		private System.Windows.Forms.ContextMenuStrip cms;
		private System.Windows.Forms.TreeView tw_objects;
		private System.Windows.Forms.ImageList imageList;

    }
}