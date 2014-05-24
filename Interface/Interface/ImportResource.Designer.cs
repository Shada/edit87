namespace LevelEditor
{
    partial class ImportResource
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
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ImportResource));
			this.btn_renameFile = new System.Windows.Forms.Button();
			this.tw_fileTree = new System.Windows.Forms.TreeView();
			this.imageList = new System.Windows.Forms.ImageList(this.components);
			this.btn_import = new System.Windows.Forms.Button();
			this.txb_fileName = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.txb_input = new System.Windows.Forms.TextBox();
			this.btn_browse = new System.Windows.Forms.Button();
			this.pb_preView = new System.Windows.Forms.PictureBox();
			this.ofd_importResource = new System.Windows.Forms.OpenFileDialog();
			this.cms_treeView = new System.Windows.Forms.ContextMenuStrip(this.components);
			((System.ComponentModel.ISupportInitialize)(this.pb_preView)).BeginInit();
			this.SuspendLayout();
			// 
			// btn_renameFile
			// 
			this.btn_renameFile.Location = new System.Drawing.Point(223, 66);
			this.btn_renameFile.Name = "btn_renameFile";
			this.btn_renameFile.Size = new System.Drawing.Size(75, 23);
			this.btn_renameFile.TabIndex = 22;
			this.btn_renameFile.Text = "Rename";
			this.btn_renameFile.UseVisualStyleBackColor = true;
			this.btn_renameFile.Click += new System.EventHandler(this.btn_renameFile_Click);
			// 
			// tw_fileTree
			// 
			this.tw_fileTree.AllowDrop = true;
			this.tw_fileTree.ImageIndex = 0;
			this.tw_fileTree.ImageList = this.imageList;
			this.tw_fileTree.Location = new System.Drawing.Point(17, 92);
			this.tw_fileTree.Name = "tw_fileTree";
			this.tw_fileTree.SelectedImageIndex = 0;
			this.tw_fileTree.Size = new System.Drawing.Size(281, 324);
			this.tw_fileTree.TabIndex = 19;
			this.tw_fileTree.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.tw_fileTree_ItemDrag);
			this.tw_fileTree.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tw_fileTree_AfterSelect);
			this.tw_fileTree.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.tw_fileTree_NodeMouseClick);
			this.tw_fileTree.DragDrop += new System.Windows.Forms.DragEventHandler(this.tw_fileTree_DragDrop);
			this.tw_fileTree.DragEnter += new System.Windows.Forms.DragEventHandler(this.tw_fileTree_DragEnter);
			this.tw_fileTree.DragOver += new System.Windows.Forms.DragEventHandler(this.tw_fileTree_DragOver);
			this.tw_fileTree.KeyDown += new System.Windows.Forms.KeyEventHandler(this.tw_fileTree_KeyDown);
			this.tw_fileTree.KeyUp += new System.Windows.Forms.KeyEventHandler(this.tw_fileTree_KeyUp);
			// 
			// imageList
			// 
			this.imageList.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList.ImageStream")));
			this.imageList.TransparentColor = System.Drawing.Color.Transparent;
			this.imageList.Images.SetKeyName(0, "folder");
			this.imageList.Images.SetKeyName(1, "img");
			// 
			// btn_import
			// 
			this.btn_import.Location = new System.Drawing.Point(579, 422);
			this.btn_import.Name = "btn_import";
			this.btn_import.Size = new System.Drawing.Size(75, 23);
			this.btn_import.TabIndex = 18;
			this.btn_import.Text = "Import";
			this.btn_import.UseVisualStyleBackColor = true;
			this.btn_import.Click += new System.EventHandler(this.btn_import_Click);
			// 
			// txb_fileName
			// 
			this.txb_fileName.Location = new System.Drawing.Point(17, 66);
			this.txb_fileName.Name = "txb_fileName";
			this.txb_fileName.Size = new System.Drawing.Size(200, 20);
			this.txb_fileName.TabIndex = 17;
			this.txb_fileName.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txb_fileName_KeyPress);
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(14, 50);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(35, 13);
			this.label2.TabIndex = 16;
			this.label2.Text = "Name";
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(14, 11);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(23, 13);
			this.label1.TabIndex = 15;
			this.label1.Text = "File";
			// 
			// txb_input
			// 
			this.txb_input.Location = new System.Drawing.Point(17, 27);
			this.txb_input.Name = "txb_input";
			this.txb_input.Size = new System.Drawing.Size(556, 20);
			this.txb_input.TabIndex = 14;
			// 
			// btn_browse
			// 
			this.btn_browse.Location = new System.Drawing.Point(579, 25);
			this.btn_browse.Name = "btn_browse";
			this.btn_browse.Size = new System.Drawing.Size(75, 23);
			this.btn_browse.TabIndex = 13;
			this.btn_browse.Text = "Browse";
			this.btn_browse.UseVisualStyleBackColor = true;
			this.btn_browse.Click += new System.EventHandler(this.btn_browse_Click);
			// 
			// pb_preView
			// 
			this.pb_preView.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
			this.pb_preView.Image = global::Interface.Properties.Resources.noPreview;
			this.pb_preView.InitialImage = null;
			this.pb_preView.Location = new System.Drawing.Point(304, 66);
			this.pb_preView.Name = "pb_preView";
			this.pb_preView.Size = new System.Drawing.Size(350, 350);
			this.pb_preView.TabIndex = 21;
			this.pb_preView.TabStop = false;
			// 
			// ofd_importResource
			// 
			this.ofd_importResource.FileName = "openFileDialog1";
			// 
			// cms_treeView
			// 
			this.cms_treeView.Name = "cms_treeView";
			this.cms_treeView.Size = new System.Drawing.Size(61, 4);
			// 
			// ImportResource
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(668, 456);
			this.Controls.Add(this.btn_renameFile);
			this.Controls.Add(this.pb_preView);
			this.Controls.Add(this.tw_fileTree);
			this.Controls.Add(this.btn_import);
			this.Controls.Add(this.txb_fileName);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.txb_input);
			this.Controls.Add(this.btn_browse);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Name = "ImportResource";
			this.Text = "ImportResource";
			((System.ComponentModel.ISupportInitialize)(this.pb_preView)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

		private System.Windows.Forms.Button btn_renameFile;
		private System.Windows.Forms.PictureBox pb_preView;
        private System.Windows.Forms.TreeView tw_fileTree;
        private System.Windows.Forms.Button btn_import;
        private System.Windows.Forms.TextBox txb_fileName;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txb_input;
        private System.Windows.Forms.Button btn_browse;
        private System.Windows.Forms.OpenFileDialog ofd_importResource;
        private System.Windows.Forms.ContextMenuStrip cms_treeView;
        private System.Windows.Forms.ImageList imageList;
    }
}