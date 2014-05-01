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
            this.panel_Left = new System.Windows.Forms.Panel();
            this.tw_objects = new System.Windows.Forms.TreeView();
            this.panel_Left.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel_Left
            // 
            this.panel_Left.AutoScroll = true;
            this.panel_Left.Controls.Add(this.tw_objects);
            this.panel_Left.Location = new System.Drawing.Point(5, 5);
            this.panel_Left.Name = "panel_Left";
            this.panel_Left.Size = new System.Drawing.Size(211, 616);
            this.panel_Left.TabIndex = 33;
            // 
            // tw_objects
            // 
            this.tw_objects.Location = new System.Drawing.Point(0, 0);
            this.tw_objects.Name = "tw_objects";
            this.tw_objects.Size = new System.Drawing.Size(144, 612);
            this.tw_objects.TabIndex = 6;
            // 
            // PanLibrary
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(247, 621);
            this.Controls.Add(this.panel_Left);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "PanLibrary";
            this.Text = "PanLibrary";
            this.Load += new System.EventHandler(this.PanLibrary_Load);
            this.SizeChanged += new System.EventHandler(this.PanLibrary_SizeChanged);
            this.panel_Left.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel_Left;
        private System.Windows.Forms.TreeView tw_objects;

    }
}