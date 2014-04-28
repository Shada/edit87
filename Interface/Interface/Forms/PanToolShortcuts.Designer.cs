namespace LevelEditor
{
    partial class PanToolShortcuts
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
            this.btn_export = new System.Windows.Forms.Button();
            this.cb_history = new System.Windows.Forms.ComboBox();
            this.btn_load = new System.Windows.Forms.Button();
            this.btn_save = new System.Windows.Forms.Button();
            this.btn_redo = new System.Windows.Forms.Button();
            this.btn_undo = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btn_export
            // 
            this.btn_export.ImageIndex = 0;
            this.btn_export.Location = new System.Drawing.Point(70, 9);
            this.btn_export.Name = "btn_export";
            this.btn_export.Size = new System.Drawing.Size(25, 25);
            this.btn_export.TabIndex = 18;
            this.btn_export.Text = "E";
            this.btn_export.UseVisualStyleBackColor = true;
            // 
            // cb_history
            // 
            this.cb_history.FormattingEnabled = true;
            this.cb_history.Items.AddRange(new object[] {
            "Heerp",
            "Deerp",
            "Heerp",
            "Deerp",
            "Heerp",
            "Deerp"});
            this.cb_history.Location = new System.Drawing.Point(101, 12);
            this.cb_history.Name = "cb_history";
            this.cb_history.Size = new System.Drawing.Size(121, 21);
            this.cb_history.TabIndex = 17;
            // 
            // btn_load
            // 
            this.btn_load.ImageIndex = 1;
            this.btn_load.Location = new System.Drawing.Point(39, 9);
            this.btn_load.Name = "btn_load";
            this.btn_load.Size = new System.Drawing.Size(25, 25);
            this.btn_load.TabIndex = 16;
            this.btn_load.UseVisualStyleBackColor = true;
            // 
            // btn_save
            // 
            this.btn_save.ImageIndex = 3;
            this.btn_save.Location = new System.Drawing.Point(8, 9);
            this.btn_save.Name = "btn_save";
            this.btn_save.Size = new System.Drawing.Size(25, 25);
            this.btn_save.TabIndex = 15;
            this.btn_save.UseVisualStyleBackColor = true;
            // 
            // btn_redo
            // 
            this.btn_redo.ImageIndex = 2;
            this.btn_redo.Location = new System.Drawing.Point(259, 9);
            this.btn_redo.Name = "btn_redo";
            this.btn_redo.Size = new System.Drawing.Size(25, 25);
            this.btn_redo.TabIndex = 14;
            this.btn_redo.Text = "R";
            this.btn_redo.UseVisualStyleBackColor = true;
            // 
            // btn_undo
            // 
            this.btn_undo.ImageIndex = 4;
            this.btn_undo.Location = new System.Drawing.Point(228, 9);
            this.btn_undo.Name = "btn_undo";
            this.btn_undo.Size = new System.Drawing.Size(25, 25);
            this.btn_undo.TabIndex = 13;
            this.btn_undo.Text = "U";
            this.btn_undo.UseVisualStyleBackColor = true;
            // 
            // PanToolShortcuts
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(289, 38);
            this.Controls.Add(this.btn_export);
            this.Controls.Add(this.cb_history);
            this.Controls.Add(this.btn_load);
            this.Controls.Add(this.btn_save);
            this.Controls.Add(this.btn_redo);
            this.Controls.Add(this.btn_undo);
            this.Name = "PanToolShortcuts";
            this.Text = "PanToolShortcuts";
            this.Load += new System.EventHandler(this.PanToolShortcuts_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btn_export;
        private System.Windows.Forms.ComboBox cb_history;
        private System.Windows.Forms.Button btn_load;
        private System.Windows.Forms.Button btn_save;
        private System.Windows.Forms.Button btn_redo;
        private System.Windows.Forms.Button btn_undo;
    }
}