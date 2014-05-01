namespace LevelEditor
{
	partial class ImportRecource
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
			this.ofd_importResource = new System.Windows.Forms.OpenFileDialog();
			this.btn_browse = new System.Windows.Forms.Button();
			this.txb_input = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.txb_fileName = new System.Windows.Forms.TextBox();
			this.btn_import = new System.Windows.Forms.Button();
			this.tw_fileTree = new System.Windows.Forms.TreeView();
			this.btn_createFolder = new System.Windows.Forms.Button();
			this.btn_renameFile = new System.Windows.Forms.Button();
			this.cms_treeView = new System.Windows.Forms.ContextMenuStrip(this.components);
			this.pb_preView = new System.Windows.Forms.PictureBox();
			this.btn_removeFolder = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.pb_preView)).BeginInit();
			this.SuspendLayout();
			// 
			// ofd_importResource
			// 
			this.ofd_importResource.FileName = "openFileDialog1";
			// 
			// btn_browse
			// 
			this.btn_browse.Location = new System.Drawing.Point(577, 23);
			this.btn_browse.Name = "btn_browse";
			this.btn_browse.Size = new System.Drawing.Size(75, 23);
			this.btn_browse.TabIndex = 0;
			this.btn_browse.Text = "Browse";
			this.btn_browse.UseVisualStyleBackColor = true;
			this.btn_browse.Click += new System.EventHandler(this.btn_browse_Click);
			// 
			// txb_input
			// 
			this.txb_input.Location = new System.Drawing.Point(15, 25);
			this.txb_input.Name = "txb_input";
			this.txb_input.Size = new System.Drawing.Size(556, 20);
			this.txb_input.TabIndex = 1;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(12, 9);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(23, 13);
			this.label1.TabIndex = 2;
			this.label1.Text = "File";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(12, 48);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(35, 13);
			this.label2.TabIndex = 3;
			this.label2.Text = "Name";
			// 
			// txb_fileName
			// 
			this.txb_fileName.Location = new System.Drawing.Point(15, 64);
			this.txb_fileName.Name = "txb_fileName";
			this.txb_fileName.Size = new System.Drawing.Size(200, 20);
			this.txb_fileName.TabIndex = 4;
			// 
			// btn_import
			// 
			this.btn_import.Location = new System.Drawing.Point(577, 420);
			this.btn_import.Name = "btn_import";
			this.btn_import.Size = new System.Drawing.Size(75, 23);
			this.btn_import.TabIndex = 7;
			this.btn_import.Text = "Import";
			this.btn_import.UseVisualStyleBackColor = true;
			this.btn_import.Click += new System.EventHandler(this.btn_import_Click);
			// 
			// tw_fileTree
			// 
			this.tw_fileTree.AllowDrop = true;
			this.tw_fileTree.Location = new System.Drawing.Point(15, 90);
			this.tw_fileTree.Name = "tw_fileTree";
			this.tw_fileTree.Size = new System.Drawing.Size(281, 324);
			this.tw_fileTree.TabIndex = 8;
			this.tw_fileTree.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.tw_fileTree_ItemDrag);
			this.tw_fileTree.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tw_fileTree_AfterSelect);
			this.tw_fileTree.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.tw_fileTree_NodeMouseClick);
			this.tw_fileTree.DragDrop += new System.Windows.Forms.DragEventHandler(this.tw_fileTree_DragDrop);
			this.tw_fileTree.DragEnter += new System.Windows.Forms.DragEventHandler(this.tw_fileTree_DragEnter);
			this.tw_fileTree.DragOver += new System.Windows.Forms.DragEventHandler(this.tw_fileTree_DragOver);
			this.tw_fileTree.KeyDown += new System.Windows.Forms.KeyEventHandler(this.tw_fileTree_KeyDown);
			this.tw_fileTree.KeyUp += new System.Windows.Forms.KeyEventHandler(this.tw_fileTree_KeyUp);
			// 
			// btn_createFolder
			// 
			this.btn_createFolder.Location = new System.Drawing.Point(15, 420);
			this.btn_createFolder.Name = "btn_createFolder";
			this.btn_createFolder.Size = new System.Drawing.Size(130, 23);
			this.btn_createFolder.TabIndex = 9;
			this.btn_createFolder.Text = "Create folder";
			this.btn_createFolder.UseVisualStyleBackColor = true;
			this.btn_createFolder.Click += new System.EventHandler(this.btn_createFolder_Click);
			// 
			// btn_renameFile
			// 
			this.btn_renameFile.Location = new System.Drawing.Point(221, 64);
			this.btn_renameFile.Name = "btn_renameFile";
			this.btn_renameFile.Size = new System.Drawing.Size(75, 23);
			this.btn_renameFile.TabIndex = 11;
			this.btn_renameFile.Text = "Rename";
			this.btn_renameFile.UseVisualStyleBackColor = true;
			this.btn_renameFile.Click += new System.EventHandler(this.btn_renameFile_Click);
			// 
			// cms_treeView
			// 
			this.cms_treeView.Name = "cms_treeView";
			this.cms_treeView.Size = new System.Drawing.Size(61, 4);
			// 
			// pb_preView
			// 
			this.pb_preView.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
			this.pb_preView.Image = global::Interface.Properties.Resources.noPreview;
			this.pb_preView.Location = new System.Drawing.Point(302, 64);
			this.pb_preView.Name = "pb_preView";
			this.pb_preView.Size = new System.Drawing.Size(350, 350);
			this.pb_preView.TabIndex = 10;
			this.pb_preView.TabStop = false;
			// 
			// btn_removeFolder
			// 
			this.btn_removeFolder.Location = new System.Drawing.Point(164, 420);
			this.btn_removeFolder.Name = "btn_removeFolder";
			this.btn_removeFolder.Size = new System.Drawing.Size(130, 23);
			this.btn_removeFolder.TabIndex = 12;
			this.btn_removeFolder.Text = "Remove folder";
			this.btn_removeFolder.UseVisualStyleBackColor = true;
			this.btn_removeFolder.Click += new System.EventHandler(this.btn_removeFolder_Click);
			// 
			// ImportRecource
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(668, 456);
			this.Controls.Add(this.btn_removeFolder);
			this.Controls.Add(this.btn_renameFile);
			this.Controls.Add(this.pb_preView);
			this.Controls.Add(this.btn_createFolder);
			this.Controls.Add(this.tw_fileTree);
			this.Controls.Add(this.btn_import);
			this.Controls.Add(this.txb_fileName);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.txb_input);
			this.Controls.Add(this.btn_browse);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Name = "ImportRecource";
			this.Text = "Import Recource";
			((System.ComponentModel.ISupportInitialize)(this.pb_preView)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.OpenFileDialog ofd_importResource;
		private System.Windows.Forms.Button btn_browse;
		private System.Windows.Forms.TextBox txb_input;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox txb_fileName;
		private System.Windows.Forms.Button btn_import;
		private System.Windows.Forms.TreeView tw_fileTree;
		private System.Windows.Forms.Button btn_createFolder;
		private System.Windows.Forms.PictureBox pb_preView;
		private System.Windows.Forms.Button btn_renameFile;
		private System.Windows.Forms.ContextMenuStrip cms_treeView;
		private System.Windows.Forms.Button btn_removeFolder;
	}
}