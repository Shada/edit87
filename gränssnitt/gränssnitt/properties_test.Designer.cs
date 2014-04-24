namespace LevelEditor
{
	partial class properties_test
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
			this.PG_test = new System.Windows.Forms.PropertyGrid();
			this.SuspendLayout();
			// 
			// PG_test
			// 
			this.PG_test.Location = new System.Drawing.Point(12, 12);
			this.PG_test.Name = "PG_test";
			this.PG_test.Size = new System.Drawing.Size(260, 238);
			this.PG_test.TabIndex = 0;
			// 
			// properties_test
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(284, 262);
			this.Controls.Add(this.PG_test);
			this.Name = "properties_test";
			this.Text = "properties_test";
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.PropertyGrid PG_test;
	}
}