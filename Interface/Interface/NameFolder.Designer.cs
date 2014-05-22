namespace LevelEditor
{
    partial class NameFolder
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
			this.btn_change = new System.Windows.Forms.Button();
			this.txb_newName = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// btn_change
			// 
			this.btn_change.Location = new System.Drawing.Point(197, 10);
			this.btn_change.Name = "btn_change";
			this.btn_change.Size = new System.Drawing.Size(75, 23);
			this.btn_change.TabIndex = 4;
			this.btn_change.Text = "OK";
			this.btn_change.UseVisualStyleBackColor = true;
			this.btn_change.Click += new System.EventHandler(this.btn_change_Click);
			// 
			// txb_newName
			// 
			this.txb_newName.Location = new System.Drawing.Point(12, 12);
			this.txb_newName.Name = "txb_newName";
			this.txb_newName.Size = new System.Drawing.Size(179, 20);
			this.txb_newName.TabIndex = 3;
			this.txb_newName.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txb_newName_KeyPress);
			// 
			// NameFolder
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 48);
			this.Controls.Add(this.btn_change);
			this.Controls.Add(this.txb_newName);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Name = "NameFolder";
			this.Text = "NameFolder";
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_change;
        private System.Windows.Forms.TextBox txb_newName;
    }
}