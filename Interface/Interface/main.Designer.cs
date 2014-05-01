namespace LevelEditor
{
	partial class MapEditor
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MapEditor));
            WeifenLuo.WinFormsUI.Docking.DockPanelSkin dockPanelSkin1 = new WeifenLuo.WinFormsUI.Docking.DockPanelSkin();
            WeifenLuo.WinFormsUI.Docking.AutoHideStripSkin autoHideStripSkin1 = new WeifenLuo.WinFormsUI.Docking.AutoHideStripSkin();
            WeifenLuo.WinFormsUI.Docking.DockPanelGradient dockPanelGradient1 = new WeifenLuo.WinFormsUI.Docking.DockPanelGradient();
            WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient1 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
            WeifenLuo.WinFormsUI.Docking.DockPaneStripSkin dockPaneStripSkin1 = new WeifenLuo.WinFormsUI.Docking.DockPaneStripSkin();
            WeifenLuo.WinFormsUI.Docking.DockPaneStripGradient dockPaneStripGradient1 = new WeifenLuo.WinFormsUI.Docking.DockPaneStripGradient();
            WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient2 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
            WeifenLuo.WinFormsUI.Docking.DockPanelGradient dockPanelGradient2 = new WeifenLuo.WinFormsUI.Docking.DockPanelGradient();
            WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient3 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
            WeifenLuo.WinFormsUI.Docking.DockPaneStripToolWindowGradient dockPaneStripToolWindowGradient1 = new WeifenLuo.WinFormsUI.Docking.DockPaneStripToolWindowGradient();
            WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient4 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
            WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient5 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
            WeifenLuo.WinFormsUI.Docking.DockPanelGradient dockPanelGradient3 = new WeifenLuo.WinFormsUI.Docking.DockPanelGradient();
            WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient6 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
            WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient7 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newProjectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.layoutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importPreferencesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportPreferencesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importBrushesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.undoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.redoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.prefrencesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsShortcutsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.brushToolsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.haalpPleaseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.shortcutPanel = new System.Windows.Forms.Panel();
            this.btn_export = new System.Windows.Forms.Button();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.cb_history = new System.Windows.Forms.ComboBox();
            this.btn_load = new System.Windows.Forms.Button();
            this.btn_save = new System.Windows.Forms.Button();
            this.btn_redo = new System.Windows.Forms.Button();
            this.btn_undo = new System.Windows.Forms.Button();
            this.mainDockPanel = new WeifenLuo.WinFormsUI.Docking.DockPanel();
            this.menuStrip.SuspendLayout();
            this.shortcutPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip
            // 
            this.menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.viewToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip.Location = new System.Drawing.Point(0, 0);
            this.menuStrip.Name = "menuStrip";
            this.menuStrip.Size = new System.Drawing.Size(1264, 24);
            this.menuStrip.TabIndex = 5;
            this.menuStrip.Text = "menuStrip";
            this.menuStrip.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.menuStrip_ItemClicked);
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newProjectToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.loadToolStripMenuItem,
            this.exportToolStripMenuItem,
            this.layoutToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newProjectToolStripMenuItem
            // 
            this.newProjectToolStripMenuItem.Name = "newProjectToolStripMenuItem";
            this.newProjectToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.newProjectToolStripMenuItem.Text = "New Project";
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.saveToolStripMenuItem.Text = "Save";
            // 
            // saveAsToolStripMenuItem
            // 
            this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
            this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.saveAsToolStripMenuItem.Text = "Save as";
            // 
            // loadToolStripMenuItem
            // 
            this.loadToolStripMenuItem.Name = "loadToolStripMenuItem";
            this.loadToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.loadToolStripMenuItem.Text = "Load";
            // 
            // exportToolStripMenuItem
            // 
            this.exportToolStripMenuItem.Name = "exportToolStripMenuItem";
            this.exportToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.exportToolStripMenuItem.Text = "Export";
            // 
            // layoutToolStripMenuItem
            // 
            this.layoutToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.importPreferencesToolStripMenuItem,
            this.exportPreferencesToolStripMenuItem});
            this.layoutToolStripMenuItem.Name = "layoutToolStripMenuItem";
            this.layoutToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.layoutToolStripMenuItem.Text = "Layout";
            // 
            // importPreferencesToolStripMenuItem
            // 
            this.importPreferencesToolStripMenuItem.Name = "importPreferencesToolStripMenuItem";
            this.importPreferencesToolStripMenuItem.Size = new System.Drawing.Size(174, 22);
            this.importPreferencesToolStripMenuItem.Text = "import preferences";
            this.importPreferencesToolStripMenuItem.Click += new System.EventHandler(this.importPreferencesToolStripMenuItem_Click);
            // 
            // exportPreferencesToolStripMenuItem
            // 
            this.exportPreferencesToolStripMenuItem.Name = "exportPreferencesToolStripMenuItem";
            this.exportPreferencesToolStripMenuItem.Size = new System.Drawing.Size(174, 22);
            this.exportPreferencesToolStripMenuItem.Text = "export preferences";
            this.exportPreferencesToolStripMenuItem.Click += new System.EventHandler(this.exportPreferencesToolStripMenuItem_Click);
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.importBrushesToolStripMenuItem,
            this.undoToolStripMenuItem,
            this.redoToolStripMenuItem,
            this.prefrencesToolStripMenuItem});
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(39, 20);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // importBrushesToolStripMenuItem
            // 
            this.importBrushesToolStripMenuItem.Name = "importBrushesToolStripMenuItem";
            this.importBrushesToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.importBrushesToolStripMenuItem.Text = "Import tool";
            // 
            // undoToolStripMenuItem
            // 
            this.undoToolStripMenuItem.Name = "undoToolStripMenuItem";
            this.undoToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.undoToolStripMenuItem.Text = "Undo";
            // 
            // redoToolStripMenuItem
            // 
            this.redoToolStripMenuItem.Name = "redoToolStripMenuItem";
            this.redoToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.redoToolStripMenuItem.Text = "Redo";
            // 
            // prefrencesToolStripMenuItem
            // 
            this.prefrencesToolStripMenuItem.Name = "prefrencesToolStripMenuItem";
            this.prefrencesToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.prefrencesToolStripMenuItem.Text = "Prefrences";
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolsShortcutsToolStripMenuItem,
            this.brushToolsToolStripMenuItem});
            this.viewToolStripMenuItem.Name = "viewToolStripMenuItem";
            this.viewToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.viewToolStripMenuItem.Text = "View";
            // 
            // toolsShortcutsToolStripMenuItem
            // 
            this.toolsShortcutsToolStripMenuItem.Checked = true;
            this.toolsShortcutsToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.toolsShortcutsToolStripMenuItem.Name = "toolsShortcutsToolStripMenuItem";
            this.toolsShortcutsToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
            this.toolsShortcutsToolStripMenuItem.Text = "Tools shortcuts";
            this.toolsShortcutsToolStripMenuItem.Click += new System.EventHandler(this.toolsShortcutsToolStripMenuItem_Click_1);
            // 
            // brushToolsToolStripMenuItem
            // 
            this.brushToolsToolStripMenuItem.Checked = true;
            this.brushToolsToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.brushToolsToolStripMenuItem.Name = "brushToolsToolStripMenuItem";
            this.brushToolsToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
            this.brushToolsToolStripMenuItem.Text = "Brush Tools";
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.haalpPleaseToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(44, 20);
            this.helpToolStripMenuItem.Text = "Help";
            // 
            // haalpPleaseToolStripMenuItem
            // 
            this.haalpPleaseToolStripMenuItem.Name = "haalpPleaseToolStripMenuItem";
            this.haalpPleaseToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
            this.haalpPleaseToolStripMenuItem.Text = "Haalp please!";
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
            this.aboutToolStripMenuItem.Text = "About";
            // 
            // shortcutPanel
            // 
            this.shortcutPanel.Controls.Add(this.btn_export);
            this.shortcutPanel.Controls.Add(this.cb_history);
            this.shortcutPanel.Controls.Add(this.btn_load);
            this.shortcutPanel.Controls.Add(this.btn_save);
            this.shortcutPanel.Controls.Add(this.btn_redo);
            this.shortcutPanel.Controls.Add(this.btn_undo);
            this.shortcutPanel.Location = new System.Drawing.Point(0, 24);
            this.shortcutPanel.Name = "shortcutPanel";
            this.shortcutPanel.Size = new System.Drawing.Size(1264, 38);
            this.shortcutPanel.TabIndex = 10;
            // 
            // btn_export
            // 
            this.btn_export.ImageIndex = 0;
            this.btn_export.ImageList = this.imageList1;
            this.btn_export.Location = new System.Drawing.Point(69, 5);
            this.btn_export.Name = "btn_export";
            this.btn_export.Size = new System.Drawing.Size(25, 25);
            this.btn_export.TabIndex = 18;
            this.btn_export.Text = "E";
            this.btn_export.UseVisualStyleBackColor = true;
            // 
            // imageList1
            // 
            this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList1.Images.SetKeyName(0, "export.png");
            this.imageList1.Images.SetKeyName(1, "load.png");
            this.imageList1.Images.SetKeyName(2, "redo.png");
            this.imageList1.Images.SetKeyName(3, "save.png");
            this.imageList1.Images.SetKeyName(4, "undo.png");
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
            this.cb_history.Location = new System.Drawing.Point(100, 8);
            this.cb_history.Name = "cb_history";
            this.cb_history.Size = new System.Drawing.Size(121, 21);
            this.cb_history.TabIndex = 17;
            // 
            // btn_load
            // 
            this.btn_load.ImageIndex = 1;
            this.btn_load.ImageList = this.imageList1;
            this.btn_load.Location = new System.Drawing.Point(38, 5);
            this.btn_load.Name = "btn_load";
            this.btn_load.Size = new System.Drawing.Size(25, 25);
            this.btn_load.TabIndex = 16;
            this.btn_load.UseVisualStyleBackColor = true;
            // 
            // btn_save
            // 
            this.btn_save.ImageIndex = 3;
            this.btn_save.ImageList = this.imageList1;
            this.btn_save.Location = new System.Drawing.Point(7, 5);
            this.btn_save.Name = "btn_save";
            this.btn_save.Size = new System.Drawing.Size(25, 25);
            this.btn_save.TabIndex = 15;
            this.btn_save.UseVisualStyleBackColor = true;
            // 
            // btn_redo
            // 
            this.btn_redo.ImageIndex = 2;
            this.btn_redo.ImageList = this.imageList1;
            this.btn_redo.Location = new System.Drawing.Point(258, 5);
            this.btn_redo.Name = "btn_redo";
            this.btn_redo.Size = new System.Drawing.Size(25, 25);
            this.btn_redo.TabIndex = 14;
            this.btn_redo.Text = "R";
            this.btn_redo.UseVisualStyleBackColor = true;
            // 
            // btn_undo
            // 
            this.btn_undo.ImageIndex = 4;
            this.btn_undo.ImageList = this.imageList1;
            this.btn_undo.Location = new System.Drawing.Point(227, 5);
            this.btn_undo.Name = "btn_undo";
            this.btn_undo.Size = new System.Drawing.Size(25, 25);
            this.btn_undo.TabIndex = 13;
            this.btn_undo.Text = "U";
            this.btn_undo.UseVisualStyleBackColor = true;
            // 
            // mainDockPanel
            // 
            this.mainDockPanel.ActiveAutoHideContent = null;
            this.mainDockPanel.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.mainDockPanel.DockBackColor = System.Drawing.SystemColors.ControlDark;
            this.mainDockPanel.Location = new System.Drawing.Point(0, 60);
            this.mainDockPanel.Name = "mainDockPanel";
            this.mainDockPanel.Size = new System.Drawing.Size(1264, 628);
            dockPanelGradient1.EndColor = System.Drawing.SystemColors.ControlLight;
            dockPanelGradient1.StartColor = System.Drawing.SystemColors.ControlLight;
            autoHideStripSkin1.DockStripGradient = dockPanelGradient1;
            tabGradient1.EndColor = System.Drawing.SystemColors.Control;
            tabGradient1.StartColor = System.Drawing.SystemColors.Control;
            tabGradient1.TextColor = System.Drawing.SystemColors.ControlDarkDark;
            autoHideStripSkin1.TabGradient = tabGradient1;
            dockPanelSkin1.AutoHideStripSkin = autoHideStripSkin1;
            tabGradient2.EndColor = System.Drawing.SystemColors.ControlLightLight;
            tabGradient2.StartColor = System.Drawing.SystemColors.ControlLightLight;
            tabGradient2.TextColor = System.Drawing.SystemColors.ControlText;
            dockPaneStripGradient1.ActiveTabGradient = tabGradient2;
            dockPanelGradient2.EndColor = System.Drawing.SystemColors.Control;
            dockPanelGradient2.StartColor = System.Drawing.SystemColors.Control;
            dockPaneStripGradient1.DockStripGradient = dockPanelGradient2;
            tabGradient3.EndColor = System.Drawing.SystemColors.ControlLight;
            tabGradient3.StartColor = System.Drawing.SystemColors.ControlLight;
            tabGradient3.TextColor = System.Drawing.SystemColors.ControlText;
            dockPaneStripGradient1.InactiveTabGradient = tabGradient3;
            dockPaneStripSkin1.DocumentGradient = dockPaneStripGradient1;
            tabGradient4.EndColor = System.Drawing.SystemColors.ActiveCaption;
            tabGradient4.LinearGradientMode = System.Drawing.Drawing2D.LinearGradientMode.Vertical;
            tabGradient4.StartColor = System.Drawing.SystemColors.GradientActiveCaption;
            tabGradient4.TextColor = System.Drawing.SystemColors.ActiveCaptionText;
            dockPaneStripToolWindowGradient1.ActiveCaptionGradient = tabGradient4;
            tabGradient5.EndColor = System.Drawing.SystemColors.Control;
            tabGradient5.StartColor = System.Drawing.SystemColors.Control;
            tabGradient5.TextColor = System.Drawing.SystemColors.ControlText;
            dockPaneStripToolWindowGradient1.ActiveTabGradient = tabGradient5;
            dockPanelGradient3.EndColor = System.Drawing.SystemColors.ControlLight;
            dockPanelGradient3.StartColor = System.Drawing.SystemColors.ControlLight;
            dockPaneStripToolWindowGradient1.DockStripGradient = dockPanelGradient3;
            tabGradient6.EndColor = System.Drawing.SystemColors.GradientInactiveCaption;
            tabGradient6.LinearGradientMode = System.Drawing.Drawing2D.LinearGradientMode.Vertical;
            tabGradient6.StartColor = System.Drawing.SystemColors.GradientInactiveCaption;
            tabGradient6.TextColor = System.Drawing.SystemColors.ControlText;
            dockPaneStripToolWindowGradient1.InactiveCaptionGradient = tabGradient6;
            tabGradient7.EndColor = System.Drawing.Color.Transparent;
            tabGradient7.StartColor = System.Drawing.Color.Transparent;
            tabGradient7.TextColor = System.Drawing.SystemColors.ControlDarkDark;
            dockPaneStripToolWindowGradient1.InactiveTabGradient = tabGradient7;
            dockPaneStripSkin1.ToolWindowGradient = dockPaneStripToolWindowGradient1;
            dockPanelSkin1.DockPaneStripSkin = dockPaneStripSkin1;
            this.mainDockPanel.Skin = dockPanelSkin1;
            this.mainDockPanel.TabIndex = 22;
            // 
            // MapEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1264, 682);
            this.Controls.Add(this.mainDockPanel);
            this.Controls.Add(this.shortcutPanel);
            this.Controls.Add(this.menuStrip);
            this.IsMdiContainer = true;
            this.Name = "MapEditor";
            this.Text = "Map Editor";
            this.Load += new System.EventHandler(this.MapEditor_Load);
            this.Resize += new System.EventHandler(this.MapEditor_Resize);
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.shortcutPanel.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

        private System.Windows.Forms.MenuStrip menuStrip;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newProjectToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem importBrushesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem undoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem redoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem prefrencesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsShortcutsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem brushToolsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem haalpPleaseToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem layoutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem importPreferencesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportPreferencesToolStripMenuItem;
        private System.Windows.Forms.Panel shortcutPanel;
        private System.Windows.Forms.Button btn_export;
        private System.Windows.Forms.ComboBox cb_history;
        private System.Windows.Forms.Button btn_load;
        private System.Windows.Forms.Button btn_save;
        private System.Windows.Forms.Button btn_redo;
        private System.Windows.Forms.Button btn_undo;
        private System.Windows.Forms.ImageList imageList1;
        private WeifenLuo.WinFormsUI.Docking.DockPanel mainDockPanel;



    }
}

