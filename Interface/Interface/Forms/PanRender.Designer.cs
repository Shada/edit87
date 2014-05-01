namespace LevelEditor
{
    partial class PanRender
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
            this.pb_scene = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.pb_scene)).BeginInit();
            this.SuspendLayout();
            // 
            // pb_scene
            // 
            this.pb_scene.BackgroundImage = global::Interface.Properties.Resources.map_placeholder;
            this.pb_scene.Location = new System.Drawing.Point(-2, -2);
            this.pb_scene.Name = "pb_scene";
            this.pb_scene.Size = new System.Drawing.Size(1500, 993);
            this.pb_scene.TabIndex = 5;
            this.pb_scene.TabStop = false;
            // 
            // PanRender
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1615, 960);
            this.Controls.Add(this.pb_scene);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "PanRender";
            this.Text = "PanRender";
            this.Load += new System.EventHandler(this.PanRender_Load);
            this.SizeChanged += new System.EventHandler(this.PanRender_SizeChanged);
            ((System.ComponentModel.ISupportInitialize)(this.pb_scene)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pb_scene;
    }
}