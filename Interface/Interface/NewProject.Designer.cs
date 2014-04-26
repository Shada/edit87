namespace LevelEditor
{
	partial class NewProject
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
			this.label1 = new System.Windows.Forms.Label();
			this.btn_browseDirectory = new System.Windows.Forms.Button();
			this.txb_projectName = new System.Windows.Forms.TextBox();
			this.mtxb_mapSizeX = new System.Windows.Forms.MaskedTextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.txb_workingDirectory = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.mtxb_mapSizeY = new System.Windows.Forms.MaskedTextBox();
			this.fbd_workingDirectory = new System.Windows.Forms.FolderBrowserDialog();
			this.btn_createParoject = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(12, 9);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(35, 13);
			this.label1.TabIndex = 0;
			this.label1.Text = "Name";
			// 
			// btn_browseDirectory
			// 
			this.btn_browseDirectory.Location = new System.Drawing.Point(197, 62);
			this.btn_browseDirectory.Name = "btn_browseDirectory";
			this.btn_browseDirectory.Size = new System.Drawing.Size(75, 23);
			this.btn_browseDirectory.TabIndex = 1;
			this.btn_browseDirectory.Text = "Browse";
			this.btn_browseDirectory.UseVisualStyleBackColor = true;
			this.btn_browseDirectory.Click += new System.EventHandler(this.btn_browseDirectory_Click);
			// 
			// txb_projectName
			// 
			this.txb_projectName.Location = new System.Drawing.Point(15, 25);
			this.txb_projectName.Name = "txb_projectName";
			this.txb_projectName.Size = new System.Drawing.Size(100, 20);
			this.txb_projectName.TabIndex = 2;
			this.txb_projectName.Text = "test";
			// 
			// mtxb_mapSizeX
			// 
			this.mtxb_mapSizeX.Location = new System.Drawing.Point(41, 103);
			this.mtxb_mapSizeX.Mask = "000";
			this.mtxb_mapSizeX.Name = "mtxb_mapSizeX";
			this.mtxb_mapSizeX.Size = new System.Drawing.Size(40, 20);
			this.mtxb_mapSizeX.TabIndex = 3;
			this.mtxb_mapSizeX.Text = "512";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(12, 48);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(90, 13);
			this.label2.TabIndex = 4;
			this.label2.Text = "Working directory";
			// 
			// txb_workingDirectory
			// 
			this.txb_workingDirectory.Location = new System.Drawing.Point(15, 64);
			this.txb_workingDirectory.Name = "txb_workingDirectory";
			this.txb_workingDirectory.Size = new System.Drawing.Size(176, 20);
			this.txb_workingDirectory.TabIndex = 5;
			this.txb_workingDirectory.Text = "C:\\Users\\Ossian\'\\Desktop";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(12, 87);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(27, 13);
			this.label3.TabIndex = 6;
			this.label3.Text = "Size";
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(12, 106);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(14, 13);
			this.label4.TabIndex = 7;
			this.label4.Text = "X";
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(12, 132);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(14, 13);
			this.label5.TabIndex = 9;
			this.label5.Text = "Y";
			// 
			// mtxb_mapSizeY
			// 
			this.mtxb_mapSizeY.Location = new System.Drawing.Point(41, 129);
			this.mtxb_mapSizeY.Mask = "000";
			this.mtxb_mapSizeY.Name = "mtxb_mapSizeY";
			this.mtxb_mapSizeY.Size = new System.Drawing.Size(40, 20);
			this.mtxb_mapSizeY.TabIndex = 8;
			this.mtxb_mapSizeY.Text = "512";
			// 
			// btn_createParoject
			// 
			this.btn_createParoject.Location = new System.Drawing.Point(197, 127);
			this.btn_createParoject.Name = "btn_createParoject";
			this.btn_createParoject.Size = new System.Drawing.Size(75, 23);
			this.btn_createParoject.TabIndex = 10;
			this.btn_createParoject.Text = "Create";
			this.btn_createParoject.UseVisualStyleBackColor = true;
			this.btn_createParoject.Click += new System.EventHandler(this.btn_createParoject_Click);
			// 
			// NewProject
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 161);
			this.Controls.Add(this.btn_createParoject);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.mtxb_mapSizeY);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.txb_workingDirectory);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.mtxb_mapSizeX);
			this.Controls.Add(this.txb_projectName);
			this.Controls.Add(this.btn_browseDirectory);
			this.Controls.Add(this.label1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Name = "NewProject";
			this.Text = "New Project";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Button btn_browseDirectory;
		private System.Windows.Forms.TextBox txb_projectName;
		private System.Windows.Forms.MaskedTextBox mtxb_mapSizeX;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox txb_workingDirectory;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.MaskedTextBox mtxb_mapSizeY;
		private System.Windows.Forms.FolderBrowserDialog fbd_workingDirectory;
		private System.Windows.Forms.Button btn_createParoject;
	}
}