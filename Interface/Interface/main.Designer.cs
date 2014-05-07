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
			WeifenLuo.WinFormsUI.Docking.DockPanelSkin dockPanelSkin3 = new WeifenLuo.WinFormsUI.Docking.DockPanelSkin();
			WeifenLuo.WinFormsUI.Docking.AutoHideStripSkin autoHideStripSkin3 = new WeifenLuo.WinFormsUI.Docking.AutoHideStripSkin();
			WeifenLuo.WinFormsUI.Docking.DockPanelGradient dockPanelGradient7 = new WeifenLuo.WinFormsUI.Docking.DockPanelGradient();
			WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient15 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
			WeifenLuo.WinFormsUI.Docking.DockPaneStripSkin dockPaneStripSkin3 = new WeifenLuo.WinFormsUI.Docking.DockPaneStripSkin();
			WeifenLuo.WinFormsUI.Docking.DockPaneStripGradient dockPaneStripGradient3 = new WeifenLuo.WinFormsUI.Docking.DockPaneStripGradient();
			WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient16 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
			WeifenLuo.WinFormsUI.Docking.DockPanelGradient dockPanelGradient8 = new WeifenLuo.WinFormsUI.Docking.DockPanelGradient();
			WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient17 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
			WeifenLuo.WinFormsUI.Docking.DockPaneStripToolWindowGradient dockPaneStripToolWindowGradient3 = new WeifenLuo.WinFormsUI.Docking.DockPaneStripToolWindowGradient();
			WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient18 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
			WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient19 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
			WeifenLuo.WinFormsUI.Docking.DockPanelGradient dockPanelGradient9 = new WeifenLuo.WinFormsUI.Docking.DockPanelGradient();
			WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient20 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
			WeifenLuo.WinFormsUI.Docking.TabGradient tabGradient21 = new WeifenLuo.WinFormsUI.Docking.TabGradient();
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
			this.resetToDefaultToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
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
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.ofd_loadProject = new System.Windows.Forms.OpenFileDialog();
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
			this.newProjectToolStripMenuItem.Click += new System.EventHandler(this.newProjectToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this.saveToolStripMenuItem.Enabled = false;
			this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
			this.saveToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.saveToolStripMenuItem.Text = "Save";
			this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this.saveAsToolStripMenuItem.Enabled = false;
			this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
			this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.saveAsToolStripMenuItem.Text = "Save as";
			this.saveAsToolStripMenuItem.Click += new System.EventHandler(this.saveAsToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this.loadToolStripMenuItem.Name = "loadToolStripMenuItem";
			this.loadToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
			this.loadToolStripMenuItem.Text = "Load";
			this.loadToolStripMenuItem.Click += new System.EventHandler(this.loadToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this.exportToolStripMenuItem.Enabled = false;
			this.exportToolStripMenuItem.Name = "exportToolStripMenuItem";
			this.exportToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.exportToolStripMenuItem.Text = "Export";
			this.exportToolStripMenuItem.Click += new System.EventHandler(this.exportToolStripMenuItem_Click);
			// 
			// layoutToolStripMenuItem
			// 
			this.layoutToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.importPreferencesToolStripMenuItem,
            this.exportPreferencesToolStripMenuItem,
            this.resetToDefaultToolStripMenuItem});
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
			// resetToDefaultToolStripMenuItem
			// 
			this.resetToDefaultToolStripMenuItem.Name = "resetToDefaultToolStripMenuItem";
			this.resetToDefaultToolStripMenuItem.Size = new System.Drawing.Size(174, 22);
			this.resetToDefaultToolStripMenuItem.Text = "Reset to default";
			this.resetToDefaultToolStripMenuItem.Click += new System.EventHandler(this.resetToDefaultToolStripMenuItem_Click);
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
			this.undoToolStripMenuItem.Enabled = false;
			this.undoToolStripMenuItem.Name = "undoToolStripMenuItem";
			this.undoToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
			this.undoToolStripMenuItem.Text = "Undo";
			// 
			// redoToolStripMenuItem
			// 
			this.redoToolStripMenuItem.Enabled = false;
			this.redoToolStripMenuItem.Name = "redoToolStripMenuItem";
			this.redoToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
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
			this.toolsShortcutsToolStripMenuItem.Click += new System.EventHandler(this.toolsShortcutsToolStripMenuItem_Click);
			// 
			// brushToolsToolStripMenuItem
			// 
			this.brushToolsToolStripMenuItem.Checked = true;
			this.brushToolsToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
			this.brushToolsToolStripMenuItem.Name = "brushToolsToolStripMenuItem";
			this.brushToolsToolStripMenuItem.Size = new System.Drawing.Size(155, 22);
			this.brushToolsToolStripMenuItem.Text = "Brush Tools";
			this.brushToolsToolStripMenuItem.Click += new System.EventHandler(this.brushToolsToolStripMenuItem_Click);
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
			dockPanelGradient7.EndColor = System.Drawing.SystemColors.ControlLight;
			dockPanelGradient7.StartColor = System.Drawing.SystemColors.ControlLight;
			autoHideStripSkin3.DockStripGradient = dockPanelGradient7;
			tabGradient15.EndColor = System.Drawing.SystemColors.Control;
			tabGradient15.StartColor = System.Drawing.SystemColors.Control;
			tabGradient15.TextColor = System.Drawing.SystemColors.ControlDarkDark;
			autoHideStripSkin3.TabGradient = tabGradient15;
			dockPanelSkin3.AutoHideStripSkin = autoHideStripSkin3;
			tabGradient16.EndColor = System.Drawing.SystemColors.ControlLightLight;
			tabGradient16.StartColor = System.Drawing.SystemColors.ControlLightLight;
			tabGradient16.TextColor = System.Drawing.SystemColors.ControlText;
			dockPaneStripGradient3.ActiveTabGradient = tabGradient16;
			dockPanelGradient8.EndColor = System.Drawing.SystemColors.Control;
			dockPanelGradient8.StartColor = System.Drawing.SystemColors.Control;
			dockPaneStripGradient3.DockStripGradient = dockPanelGradient8;
			tabGradient17.EndColor = System.Drawing.SystemColors.ControlLight;
			tabGradient17.StartColor = System.Drawing.SystemColors.ControlLight;
			tabGradient17.TextColor = System.Drawing.SystemColors.ControlText;
			dockPaneStripGradient3.InactiveTabGradient = tabGradient17;
			dockPaneStripSkin3.DocumentGradient = dockPaneStripGradient3;
			tabGradient18.EndColor = System.Drawing.SystemColors.ActiveCaption;
			tabGradient18.LinearGradientMode = System.Drawing.Drawing2D.LinearGradientMode.Vertical;
			tabGradient18.StartColor = System.Drawing.SystemColors.GradientActiveCaption;
			tabGradient18.TextColor = System.Drawing.SystemColors.ActiveCaptionText;
			dockPaneStripToolWindowGradient3.ActiveCaptionGradient = tabGradient18;
			tabGradient19.EndColor = System.Drawing.SystemColors.Control;
			tabGradient19.StartColor = System.Drawing.SystemColors.Control;
			tabGradient19.TextColor = System.Drawing.SystemColors.ControlText;
			dockPaneStripToolWindowGradient3.ActiveTabGradient = tabGradient19;
			dockPanelGradient9.EndColor = System.Drawing.SystemColors.ControlLight;
			dockPanelGradient9.StartColor = System.Drawing.SystemColors.ControlLight;
			dockPaneStripToolWindowGradient3.DockStripGradient = dockPanelGradient9;
			tabGradient20.EndColor = System.Drawing.SystemColors.GradientInactiveCaption;
			tabGradient20.LinearGradientMode = System.Drawing.Drawing2D.LinearGradientMode.Vertical;
			tabGradient20.StartColor = System.Drawing.SystemColors.GradientInactiveCaption;
			tabGradient20.TextColor = System.Drawing.SystemColors.ControlText;
			dockPaneStripToolWindowGradient3.InactiveCaptionGradient = tabGradient20;
			tabGradient21.EndColor = System.Drawing.Color.Transparent;
			tabGradient21.StartColor = System.Drawing.Color.Transparent;
			tabGradient21.TextColor = System.Drawing.SystemColors.ControlDarkDark;
			dockPaneStripToolWindowGradient3.InactiveTabGradient = tabGradient21;
			dockPaneStripSkin3.ToolWindowGradient = dockPaneStripToolWindowGradient3;
			dockPanelSkin3.DockPaneStripSkin = dockPaneStripSkin3;
			this.mainDockPanel.Skin = dockPanelSkin3;
			this.mainDockPanel.TabIndex = 22;
			// 
			// timer1
			// 
			this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
			// 
			// ofd_loadProject
			// 
			this.ofd_loadProject.FileName = "openFileDialog1";
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
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MapEditor_FormClosing);
			this.Load += new System.EventHandler(this.MapEditor_Load);
			this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MapEditor_KeyDown);
			this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.MapEditor_KeyUp);
			this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.MapEditor_MouseDown);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MapEditor_MouseMove);
			this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.MapEditor_MouseUp);
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
        private System.Windows.Forms.ToolStripMenuItem resetToDefaultToolStripMenuItem;
        private System.Windows.Forms.Timer timer1;
		private System.Windows.Forms.OpenFileDialog ofd_loadProject;



    }
}

