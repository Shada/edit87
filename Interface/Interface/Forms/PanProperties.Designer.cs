namespace LevelEditor
{
    partial class PanProperties
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
			this.pg_object = new System.Windows.Forms.PropertyGrid();
			this.SuspendLayout();
			// 
			// pg_object
			// 
			this.pg_object.Location = new System.Drawing.Point(6, 2);
			this.pg_object.Name = "pg_object";
			this.pg_object.Size = new System.Drawing.Size(260, 238);
			this.pg_object.TabIndex = 1;
			// 
			// PanProperties
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 262);
			this.Controls.Add(this.pg_object);
			this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.Name = "PanProperties";
			this.Text = "PanProperties";
			this.Load += new System.EventHandler(this.PanProperties_Load);
			this.SizeChanged += new System.EventHandler(this.PanProperties_SizeChanged);
			this.Resize += new System.EventHandler(this.PanProperties_Resize);
			this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PropertyGrid pg_object;
    }
}