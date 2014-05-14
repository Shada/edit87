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
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem(new string[] {
            "Dirt",
            "Test"}, 0);
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem("Grass", 1);
            System.Windows.Forms.ListViewItem listViewItem3 = new System.Windows.Forms.ListViewItem("Rock", 2);
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MapEditor));
            System.Windows.Forms.ListViewItem listViewItem4 = new System.Windows.Forms.ListViewItem(new string[] {
            "B1",
            "Test"}, 0);
            System.Windows.Forms.ListViewItem listViewItem5 = new System.Windows.Forms.ListViewItem("B2", 1);
            System.Windows.Forms.ListViewItem listViewItem6 = new System.Windows.Forms.ListViewItem("B3", 2);
            this.btn_importTexture = new System.Windows.Forms.Button();
            this.btn_importBrush = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.nud_brushIntensity = new System.Windows.Forms.NumericUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.lv_Textures = new System.Windows.Forms.ListView();
            this.il_textures = new System.Windows.Forms.ImageList(this.components);
            this.label6 = new System.Windows.Forms.Label();
            this.nud_BrushSize = new System.Windows.Forms.NumericUpDown();
            this.lw_Brush = new System.Windows.Forms.ListView();
            this.il_terrainBrushes = new System.Windows.Forms.ImageList(this.components);
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newProjectToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importBrushesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.undoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.redoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.prefrencesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsShortcutsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.haalpPleaseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tw_objects = new System.Windows.Forms.TreeView();
            this.il_icons = new System.Windows.Forms.ImageList(this.components);
            this.cb_history = new System.Windows.Forms.ComboBox();
            this.btn_importResource = new System.Windows.Forms.Button();
            this.tw_resources = new System.Windows.Forms.TreeView();
            this.label9 = new System.Windows.Forms.Label();
            this.panel_Right = new System.Windows.Forms.Panel();
            this.btn_TextureBrush = new System.Windows.Forms.Button();
            this.btn_TerrainBrush = new System.Windows.Forms.Button();
            this.btn_export = new System.Windows.Forms.Button();
            this.btn_load = new System.Windows.Forms.Button();
            this.btn_save = new System.Windows.Forms.Button();
            this.btn_redo = new System.Windows.Forms.Button();
            this.btn_undo = new System.Windows.Forms.Button();
            this.pb_scene = new System.Windows.Forms.PictureBox();
            this.bindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.panel_Left = new System.Windows.Forms.Panel();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.nud_brushIntensity)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nud_BrushSize)).BeginInit();
            this.menuStrip.SuspendLayout();
            this.panel_Right.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb_scene)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).BeginInit();
            this.panel_Left.SuspendLayout();
            this.SuspendLayout();
            // 
            // btn_importTexture
            // 
            this.btn_importTexture.Location = new System.Drawing.Point(98, 305);
            this.btn_importTexture.Name = "btn_importTexture";
            this.btn_importTexture.Size = new System.Drawing.Size(90, 23);
            this.btn_importTexture.TabIndex = 30;
            this.btn_importTexture.Text = "Import texture";
            this.btn_importTexture.UseVisualStyleBackColor = true;
            this.btn_importTexture.Click += new System.EventHandler(this.btn_importTexture_Click);
            // 
            // btn_importBrush
            // 
            this.btn_importBrush.Location = new System.Drawing.Point(98, 132);
            this.btn_importBrush.Name = "btn_importBrush";
            this.btn_importBrush.Size = new System.Drawing.Size(90, 23);
            this.btn_importBrush.TabIndex = 29;
            this.btn_importBrush.Text = "Import brush";
            this.btn_importBrush.UseVisualStyleBackColor = true;
            this.btn_importBrush.Click += new System.EventHandler(this.btn_importBrush_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(5, 79);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(30, 13);
            this.label5.TabIndex = 28;
            this.label5.Text = "Size:";
            // 
            // nud_brushIntensity
            // 
            this.nud_brushIntensity.Location = new System.Drawing.Point(64, 103);
            this.nud_brushIntensity.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nud_brushIntensity.Name = "nud_brushIntensity";
            this.nud_brushIntensity.Size = new System.Drawing.Size(50, 20);
            this.nud_brushIntensity.TabIndex = 27;
            this.nud_brushIntensity.Value = new decimal(new int[] {
            60,
            0,
            0,
            0});
            this.nud_brushIntensity.ValueChanged += new System.EventHandler(this.nud_brushIntensity_ValueChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(5, 5);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(40, 13);
            this.label4.TabIndex = 26;
            this.label4.Text = "Terrain";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(61, 5);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(43, 13);
            this.label2.TabIndex = 25;
            this.label2.Text = "Texture";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(5, 310);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(46, 13);
            this.label8.TabIndex = 24;
            this.label8.Text = "Texture:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(5, 137);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(37, 13);
            this.label7.TabIndex = 23;
            this.label7.Text = "Brush:";
            // 
            // lv_Textures
            // 
            this.lv_Textures.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1,
            listViewItem2,
            listViewItem3});
            this.lv_Textures.LargeImageList = this.il_textures;
            this.lv_Textures.Location = new System.Drawing.Point(8, 334);
            this.lv_Textures.Name = "lv_Textures";
            this.lv_Textures.Size = new System.Drawing.Size(180, 141);
            this.lv_Textures.SmallImageList = this.il_textures;
            this.lv_Textures.TabIndex = 22;
            this.lv_Textures.UseCompatibleStateImageBehavior = false;
            this.lv_Textures.SelectedIndexChanged += new System.EventHandler(this.lv_Textures_SelectedIndexChanged);
            // 
            // il_textures
            // 
            this.il_textures.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("il_textures.ImageStream")));
            this.il_textures.TransparentColor = System.Drawing.Color.Transparent;
            this.il_textures.Images.SetKeyName(0, "dirt.png");
            this.il_textures.Images.SetKeyName(1, "grass.png");
            this.il_textures.Images.SetKeyName(2, "rock.png");
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(5, 105);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(49, 13);
            this.label6.TabIndex = 21;
            this.label6.Text = "Intensity:";
            // 
            // nud_BrushSize
            // 
            this.nud_BrushSize.Location = new System.Drawing.Point(64, 77);
            this.nud_BrushSize.Name = "nud_BrushSize";
            this.nud_BrushSize.Size = new System.Drawing.Size(50, 20);
            this.nud_BrushSize.TabIndex = 20;
            this.nud_BrushSize.Value = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.nud_BrushSize.ValueChanged += new System.EventHandler(this.nud_BrushSize_ValueChanged);
            // 
            // lw_Brush
            // 
            this.lw_Brush.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem4,
            listViewItem5,
            listViewItem6});
            this.lw_Brush.LargeImageList = this.il_terrainBrushes;
            this.lw_Brush.Location = new System.Drawing.Point(8, 158);
            this.lw_Brush.Name = "lw_Brush";
            this.lw_Brush.Size = new System.Drawing.Size(180, 141);
            this.lw_Brush.SmallImageList = this.il_terrainBrushes;
            this.lw_Brush.TabIndex = 15;
            this.lw_Brush.UseCompatibleStateImageBehavior = false;
            this.lw_Brush.SelectedIndexChanged += new System.EventHandler(this.lw_Brush_SelectedIndexChanged);
            // 
            // il_terrainBrushes
            // 
            this.il_terrainBrushes.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("il_terrainBrushes.ImageStream")));
            this.il_terrainBrushes.TransparentColor = System.Drawing.Color.Transparent;
            this.il_terrainBrushes.Images.SetKeyName(0, "b1.png");
            this.il_terrainBrushes.Images.SetKeyName(1, "b2.png");
            this.il_terrainBrushes.Images.SetKeyName(2, "b3.png");
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
            this.menuStrip.TabIndex = 3;
            this.menuStrip.Text = "menuStrip";
            this.menuStrip.Visible = false;
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newProjectToolStripMenuItem,
            this.saveToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.loadToolStripMenuItem,
            this.exportToolStripMenuItem});
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
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.saveToolStripMenuItem.Text = "Save";
            this.saveToolStripMenuItem.Click += new System.EventHandler(this.saveToolStripMenuItem_Click);
            // 
            // saveAsToolStripMenuItem
            // 
            this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
            this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
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
            this.exportToolStripMenuItem.Name = "exportToolStripMenuItem";
            this.exportToolStripMenuItem.Size = new System.Drawing.Size(138, 22);
            this.exportToolStripMenuItem.Text = "Export";
            this.exportToolStripMenuItem.Click += new System.EventHandler(this.exportToolStripMenuItem_Click);
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
            this.importBrushesToolStripMenuItem.Click += new System.EventHandler(this.importBrushesToolStripMenuItem_Click);
            // 
            // undoToolStripMenuItem
            // 
            this.undoToolStripMenuItem.Name = "undoToolStripMenuItem";
            this.undoToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.undoToolStripMenuItem.Text = "Undo";
            this.undoToolStripMenuItem.Click += new System.EventHandler(this.undoToolStripMenuItem_Click);
            // 
            // redoToolStripMenuItem
            // 
            this.redoToolStripMenuItem.Name = "redoToolStripMenuItem";
            this.redoToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.redoToolStripMenuItem.Text = "Redo";
            this.redoToolStripMenuItem.Click += new System.EventHandler(this.redoToolStripMenuItem_Click);
            // 
            // prefrencesToolStripMenuItem
            // 
            this.prefrencesToolStripMenuItem.Name = "prefrencesToolStripMenuItem";
            this.prefrencesToolStripMenuItem.Size = new System.Drawing.Size(134, 22);
            this.prefrencesToolStripMenuItem.Text = "Prefrences";
            this.prefrencesToolStripMenuItem.Click += new System.EventHandler(this.prefrencesToolStripMenuItem_Click);
            // 
            // viewToolStripMenuItem
            // 
            this.viewToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolsShortcutsToolStripMenuItem});
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
            this.haalpPleaseToolStripMenuItem.Click += new System.EventHandler(this.haalpPleaseToolStripMenuItem_Click);
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // tw_objects
            // 
            this.tw_objects.Location = new System.Drawing.Point(4, 5);
            this.tw_objects.Name = "tw_objects";
            this.tw_objects.Size = new System.Drawing.Size(200, 612);
            this.tw_objects.TabIndex = 6;
            this.tw_objects.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tw_objects_AfterSelect);
            // 
            // il_icons
            // 
            this.il_icons.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("il_icons.ImageStream")));
            this.il_icons.TransparentColor = System.Drawing.Color.Transparent;
            this.il_icons.Images.SetKeyName(0, "export.png");
            this.il_icons.Images.SetKeyName(1, "load.png");
            this.il_icons.Images.SetKeyName(2, "redo.png");
            this.il_icons.Images.SetKeyName(3, "save.png");
            this.il_icons.Images.SetKeyName(4, "undo.png");
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
            this.cb_history.Location = new System.Drawing.Point(105, 30);
            this.cb_history.Name = "cb_history";
            this.cb_history.Size = new System.Drawing.Size(121, 21);
            this.cb_history.TabIndex = 11;
            this.cb_history.SelectedIndexChanged += new System.EventHandler(this.cb_history_SelectedIndexChanged);
            // 
            // btn_importResource
            // 
            this.btn_importResource.Location = new System.Drawing.Point(8, 481);
            this.btn_importResource.Name = "btn_importResource";
            this.btn_importResource.Size = new System.Drawing.Size(180, 23);
            this.btn_importResource.TabIndex = 0;
            this.btn_importResource.Text = "Import resource";
            this.btn_importResource.UseVisualStyleBackColor = true;
            this.btn_importResource.Click += new System.EventHandler(this.btn_importResource_Click);
            // 
            // tw_resources
            // 
            this.tw_resources.Location = new System.Drawing.Point(8, 523);
            this.tw_resources.Name = "tw_resources";
            this.tw_resources.Size = new System.Drawing.Size(180, 200);
            this.tw_resources.TabIndex = 1;
            this.tw_resources.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.tw_resources_AfterSelect);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(8, 507);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(58, 13);
            this.label9.TabIndex = 2;
            this.label9.Text = "Resources";
            // 
            // panel_Right
            // 
            this.panel_Right.AutoScroll = true;
            this.panel_Right.Controls.Add(this.label9);
            this.panel_Right.Controls.Add(this.btn_TextureBrush);
            this.panel_Right.Controls.Add(this.btn_importTexture);
            this.panel_Right.Controls.Add(this.btn_TerrainBrush);
            this.panel_Right.Controls.Add(this.tw_resources);
            this.panel_Right.Controls.Add(this.lw_Brush);
            this.panel_Right.Controls.Add(this.nud_BrushSize);
            this.panel_Right.Controls.Add(this.btn_importResource);
            this.panel_Right.Controls.Add(this.label6);
            this.panel_Right.Controls.Add(this.btn_importBrush);
            this.panel_Right.Controls.Add(this.lv_Textures);
            this.panel_Right.Controls.Add(this.label7);
            this.panel_Right.Controls.Add(this.label5);
            this.panel_Right.Controls.Add(this.label8);
            this.panel_Right.Controls.Add(this.label2);
            this.panel_Right.Controls.Add(this.nud_brushIntensity);
            this.panel_Right.Controls.Add(this.label4);
            this.panel_Right.Location = new System.Drawing.Point(1053, 58);
            this.panel_Right.Name = "panel_Right";
            this.panel_Right.Size = new System.Drawing.Size(210, 612);
            this.panel_Right.TabIndex = 31;
            // 
            // btn_TextureBrush
            // 
            this.btn_TextureBrush.BackgroundImage = global::Interface.Properties.Resources.brush;
            this.btn_TextureBrush.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btn_TextureBrush.Location = new System.Drawing.Point(64, 21);
            this.btn_TextureBrush.Name = "btn_TextureBrush";
            this.btn_TextureBrush.Size = new System.Drawing.Size(50, 50);
            this.btn_TextureBrush.TabIndex = 5;
            this.btn_TextureBrush.UseVisualStyleBackColor = true;
            this.btn_TextureBrush.Click += new System.EventHandler(this.btn_TextureBrush_Click);
            // 
            // btn_TerrainBrush
            // 
            this.btn_TerrainBrush.BackgroundImage = global::Interface.Properties.Resources.brush;
            this.btn_TerrainBrush.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btn_TerrainBrush.Location = new System.Drawing.Point(8, 21);
            this.btn_TerrainBrush.Name = "btn_TerrainBrush";
            this.btn_TerrainBrush.Size = new System.Drawing.Size(50, 50);
            this.btn_TerrainBrush.TabIndex = 2;
            this.btn_TerrainBrush.UseVisualStyleBackColor = true;
            this.btn_TerrainBrush.Click += new System.EventHandler(this.btn_TerrainBrush_Click);
            // 
            // btn_export
            // 
            this.btn_export.ImageIndex = 0;
            this.btn_export.ImageList = this.il_icons;
            this.btn_export.Location = new System.Drawing.Point(74, 27);
            this.btn_export.Name = "btn_export";
            this.btn_export.Size = new System.Drawing.Size(25, 25);
            this.btn_export.TabIndex = 12;
            this.btn_export.Text = "E";
            this.btn_export.UseVisualStyleBackColor = true;
            this.btn_export.Click += new System.EventHandler(this.btn_export_Click);
            // 
            // btn_load
            // 
            this.btn_load.ImageIndex = 1;
            this.btn_load.ImageList = this.il_icons;
            this.btn_load.Location = new System.Drawing.Point(43, 27);
            this.btn_load.Name = "btn_load";
            this.btn_load.Size = new System.Drawing.Size(25, 25);
            this.btn_load.TabIndex = 10;
            this.btn_load.UseVisualStyleBackColor = true;
            this.btn_load.Click += new System.EventHandler(this.btn_load_Click);
            // 
            // btn_save
            // 
            this.btn_save.ImageIndex = 3;
            this.btn_save.ImageList = this.il_icons;
            this.btn_save.Location = new System.Drawing.Point(12, 27);
            this.btn_save.Name = "btn_save";
            this.btn_save.Size = new System.Drawing.Size(25, 25);
            this.btn_save.TabIndex = 9;
            this.btn_save.UseVisualStyleBackColor = true;
            this.btn_save.Click += new System.EventHandler(this.btn_save_Click);
            // 
            // btn_redo
            // 
            this.btn_redo.ImageIndex = 2;
            this.btn_redo.ImageList = this.il_icons;
            this.btn_redo.Location = new System.Drawing.Point(263, 27);
            this.btn_redo.Name = "btn_redo";
            this.btn_redo.Size = new System.Drawing.Size(25, 25);
            this.btn_redo.TabIndex = 8;
            this.btn_redo.Text = "R";
            this.btn_redo.UseVisualStyleBackColor = true;
            this.btn_redo.Click += new System.EventHandler(this.btn_redo_Click);
            // 
            // btn_undo
            // 
            this.btn_undo.ImageIndex = 4;
            this.btn_undo.ImageList = this.il_icons;
            this.btn_undo.Location = new System.Drawing.Point(232, 27);
            this.btn_undo.Name = "btn_undo";
            this.btn_undo.Size = new System.Drawing.Size(25, 25);
            this.btn_undo.TabIndex = 7;
            this.btn_undo.Text = "U";
            this.btn_undo.UseVisualStyleBackColor = true;
            this.btn_undo.Click += new System.EventHandler(this.btn_undo_Click);
            // 
            // pb_scene
            // 
            this.pb_scene.BackgroundImage = global::Interface.Properties.Resources.map_placeholder;
            this.pb_scene.Location = new System.Drawing.Point(232, 58);
            this.pb_scene.Name = "pb_scene";
            this.pb_scene.Size = new System.Drawing.Size(816, 612);
            this.pb_scene.TabIndex = 4;
            this.pb_scene.TabStop = false;
            this.pb_scene.Visible = false;
            // 
            // panel_Left
            // 
            this.panel_Left.AutoScroll = true;
            this.panel_Left.Controls.Add(this.tw_objects);
            this.panel_Left.Location = new System.Drawing.Point(12, 58);
            this.panel_Left.Name = "panel_Left";
            this.panel_Left.Size = new System.Drawing.Size(221, 612);
            this.panel_Left.TabIndex = 32;
            // 
            // timer1
            // 
            this.timer1.Interval = 33;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // MapEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1264, 682);
            this.Controls.Add(this.panel_Left);
            this.Controls.Add(this.panel_Right);
            this.Controls.Add(this.btn_export);
            this.Controls.Add(this.cb_history);
            this.Controls.Add(this.btn_load);
            this.Controls.Add(this.btn_save);
            this.Controls.Add(this.btn_redo);
            this.Controls.Add(this.btn_undo);
            this.Controls.Add(this.pb_scene);
            this.Controls.Add(this.menuStrip);
            this.MainMenuStrip = this.menuStrip;
            this.MinimumSize = new System.Drawing.Size(1280, 720);
            this.Name = "MapEditor";
            this.Text = "Map Editor";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MapEditor_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.MapEditor_KeyUp);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.MapEditor_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MapEditor_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.MapEditor_MouseUp);
            this.Resize += new System.EventHandler(this.MapEditor_Resize);
            ((System.ComponentModel.ISupportInitialize)(this.nud_brushIntensity)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nud_BrushSize)).EndInit();
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            this.panel_Right.ResumeLayout(false);
            this.panel_Right.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb_scene)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).EndInit();
            this.panel_Left.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

        private System.Windows.Forms.MenuStrip menuStrip;
		private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
		private System.Windows.Forms.PictureBox pb_scene;
		private System.Windows.Forms.TreeView tw_objects;
		private System.Windows.Forms.Button btn_TerrainBrush;
		private System.Windows.Forms.Button btn_TextureBrush;
		private System.Windows.Forms.ListView lw_Brush;
		private System.Windows.Forms.ImageList il_terrainBrushes;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.NumericUpDown nud_BrushSize;
		private System.Windows.Forms.ListView lv_Textures;
		private System.Windows.Forms.Label label8;
		private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ToolStripMenuItem importBrushesToolStripMenuItem;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.ToolStripMenuItem haalpPleaseToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.Button btn_undo;
        private System.Windows.Forms.Button btn_redo;
        private System.Windows.Forms.Button btn_save;
        private System.Windows.Forms.Button btn_load;
        private System.Windows.Forms.ComboBox cb_history;
        private System.Windows.Forms.Button btn_export;
        private System.Windows.Forms.ToolStripMenuItem saveToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem saveAsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exportToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem undoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem redoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem viewToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem toolsShortcutsToolStripMenuItem;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.NumericUpDown nud_brushIntensity;
        private System.Windows.Forms.Button btn_importTexture;
        private System.Windows.Forms.Button btn_importBrush;
        private System.Windows.Forms.ImageList il_textures;
        private System.Windows.Forms.ImageList il_icons;
        private System.Windows.Forms.Button btn_importResource;
        private System.Windows.Forms.TreeView tw_resources;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ToolStripMenuItem prefrencesToolStripMenuItem;
        private System.Windows.Forms.Panel panel_Right;
        private System.Windows.Forms.BindingSource bindingSource1;
		private System.Windows.Forms.ToolStripMenuItem newProjectToolStripMenuItem;
		private System.Windows.Forms.Panel panel_Left;
        private System.Windows.Forms.Timer timer1;

	}
}

