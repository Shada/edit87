namespace Interface.Forms
{
    partial class PanAlternateView
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
            this.drawSurface = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // drawSurface
            // 
            this.drawSurface.Dock = System.Windows.Forms.DockStyle.Fill;
            this.drawSurface.Location = new System.Drawing.Point(0, 0);
            this.drawSurface.Name = "drawSurface";
            this.drawSurface.Size = new System.Drawing.Size(284, 262);
            this.drawSurface.TabIndex = 1;
            // 
            // PanAlternateView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.drawSurface);
            this.Name = "PanAlternateView";
            this.Text = "PanAlternateView";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel drawSurface;
    }
}