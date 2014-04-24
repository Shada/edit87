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
            System.Windows.Forms.ListViewItem listViewItem7 = new System.Windows.Forms.ListViewItem(new string[] {
            "Dirt",
            "Test"}, 0);
            System.Windows.Forms.ListViewItem listViewItem8 = new System.Windows.Forms.ListViewItem("Grass", 1);
            System.Windows.Forms.ListViewItem listViewItem9 = new System.Windows.Forms.ListViewItem("Rock", 2);
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MapEditor));
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem(new string[] {
            "B1",
            "Test"}, 0);
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem("B2", 1);
            System.Windows.Forms.ListViewItem listViewItem3 = new System.Windows.Forms.ListViewItem("B3", 2);
            this.tc_Tools = new System.Windows.Forms.TabControl();
            this.tp_Map = new System.Windows.Forms.TabPage();
            this.btn_importTexture = new System.Windows.Forms.Button();
            this.btn_importBrush = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
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
            this.label1 = new System.Windows.Forms.Label();
            this.tp_Objects = new System.Windows.Forms.TabPage();
            this.menuStrip = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveAsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exportToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.importBrushesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.undoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.redoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolsShortcutsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.haalpPleaseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.label3 = new System.Windows.Forms.Label();
            this.tw_objects = new System.Windows.Forms.TreeView();
            this.btn_undo = new System.Windows.Forms.Button();
            this.btn_redo = new System.Windows.Forms.Button();
            this.btn_load = new System.Windows.Forms.Button();
            this.cb_history = new System.Windows.Forms.ComboBox();
            this.btn_export = new System.Windows.Forms.Button();
            this.btn_save = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.btn_TextureBrush = new System.Windows.Forms.Button();
            this.btn_TerrainBrush = new System.Windows.Forms.Button();
            this.il_icons = new System.Windows.Forms.ImageList(this.components);
            this.tc_Tools.SuspendLayout();
            this.tp_Map.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nud_BrushSize)).BeginInit();
            this.menuStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // tc_Tools
            // 
            this.tc_Tools.Controls.Add(this.tp_Map);
            this.tc_Tools.Controls.Add(this.tp_Objects);
            this.tc_Tools.Location = new System.Drawing.Point(1052, 58);
            this.tc_Tools.Name = "tc_Tools";
            this.tc_Tools.SelectedIndex = 0;
            this.tc_Tools.Size = new System.Drawing.Size(200, 660);
            this.tc_Tools.TabIndex = 1;
            // 
            // tp_Map
            // 
            this.tp_Map.Controls.Add(this.btn_importTexture);
            this.tp_Map.Controls.Add(this.btn_importBrush);
            this.tp_Map.Controls.Add(this.label5);
            this.tp_Map.Controls.Add(this.numericUpDown1);
            this.tp_Map.Controls.Add(this.label4);
            this.tp_Map.Controls.Add(this.label2);
            this.tp_Map.Controls.Add(this.label8);
            this.tp_Map.Controls.Add(this.label7);
            this.tp_Map.Controls.Add(this.lv_Textures);
            this.tp_Map.Controls.Add(this.label6);
            this.tp_Map.Controls.Add(this.nud_BrushSize);
            this.tp_Map.Controls.Add(this.lw_Brush);
            this.tp_Map.Controls.Add(this.btn_TextureBrush);
            this.tp_Map.Controls.Add(this.btn_TerrainBrush);
            this.tp_Map.Controls.Add(this.label1);
            this.tp_Map.Location = new System.Drawing.Point(4, 22);
            this.tp_Map.Name = "tp_Map";
            this.tp_Map.Padding = new System.Windows.Forms.Padding(3);
            this.tp_Map.Size = new System.Drawing.Size(192, 634);
            this.tp_Map.TabIndex = 0;
            this.tp_Map.Text = "Map";
            this.tp_Map.UseVisualStyleBackColor = true;
            // 
            // btn_importTexture
            // 
            this.btn_importTexture.Location = new System.Drawing.Point(96, 313);
            this.btn_importTexture.Name = "btn_importTexture";
            this.btn_importTexture.Size = new System.Drawing.Size(90, 23);
            this.btn_importTexture.TabIndex = 30;
            this.btn_importTexture.Text = "Import texture";
            this.btn_importTexture.UseVisualStyleBackColor = true;
            // 
            // btn_importBrush
            // 
            this.btn_importBrush.Location = new System.Drawing.Point(96, 140);
            this.btn_importBrush.Name = "btn_importBrush";
            this.btn_importBrush.Size = new System.Drawing.Size(90, 23);
            this.btn_importBrush.TabIndex = 29;
            this.btn_importBrush.Text = "Import brush";
            this.btn_importBrush.UseVisualStyleBackColor = true;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(3, 87);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(30, 13);
            this.label5.TabIndex = 28;
            this.label5.Text = "Size:";
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(62, 85);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(50, 20);
            this.numericUpDown1.TabIndex = 27;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(3, 13);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(40, 13);
            this.label4.TabIndex = 26;
            this.label4.Text = "Terrain";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(59, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(43, 13);
            this.label2.TabIndex = 25;
            this.label2.Text = "Texture";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(3, 318);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(46, 13);
            this.label8.TabIndex = 24;
            this.label8.Text = "Texture:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(3, 145);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(37, 13);
            this.label7.TabIndex = 23;
            this.label7.Text = "Brush:";
            // 
            // lv_Textures
            // 
            this.lv_Textures.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem7,
            listViewItem8,
            listViewItem9});
            this.lv_Textures.LargeImageList = this.il_textures;
            this.lv_Textures.Location = new System.Drawing.Point(6, 342);
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
            this.label6.Location = new System.Drawing.Point(3, 113);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(49, 13);
            this.label6.TabIndex = 21;
            this.label6.Text = "Intensity:";
            // 
            // nud_BrushSize
            // 
            this.nud_BrushSize.Location = new System.Drawing.Point(62, 111);
            this.nud_BrushSize.Name = "nud_BrushSize";
            this.nud_BrushSize.Size = new System.Drawing.Size(50, 20);
            this.nud_BrushSize.TabIndex = 20;
            // 
            // lw_Brush
            // 
            this.lw_Brush.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1,
            listViewItem2,
            listViewItem3});
            this.lw_Brush.LargeImageList = this.il_terrainBrushes;
            this.lw_Brush.Location = new System.Drawing.Point(6, 166);
            this.lw_Brush.Name = "lw_Brush";
            this.lw_Brush.Size = new System.Drawing.Size(180, 141);
            this.lw_Brush.SmallImageList = this.il_terrainBrushes;
            this.lw_Brush.TabIndex = 15;
            this.lw_Brush.UseCompatibleStateImageBehavior = false;
            // 
            // il_terrainBrushes
            // 
            this.il_terrainBrushes.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("il_terrainBrushes.ImageStream")));
            this.il_terrainBrushes.TransparentColor = System.Drawing.Color.Transparent;
            this.il_terrainBrushes.Images.SetKeyName(0, "b1.png");
            this.il_terrainBrushes.Images.SetKeyName(1, "b2.png");
            this.il_terrainBrushes.Images.SetKeyName(2, "b3.png");
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(1, 3);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 25);
            this.label1.TabIndex = 1;
            // 
            // tp_Objects
            // 
            this.tp_Objects.Location = new System.Drawing.Point(4, 22);
            this.tp_Objects.Name = "tp_Objects";
            this.tp_Objects.Padding = new System.Windows.Forms.Padding(3);
            this.tp_Objects.Size = new System.Drawing.Size(192, 634);
            this.tp_Objects.TabIndex = 1;
            this.tp_Objects.Text = "Objects";
            this.tp_Objects.UseVisualStyleBackColor = true;
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
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.saveToolStripMenuItem,
            this.saveAsToolStripMenuItem,
            this.loadToolStripMenuItem,
            this.exportToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // saveToolStripMenuItem
            // 
            this.saveToolStripMenuItem.Name = "saveToolStripMenuItem";
            this.saveToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.saveToolStripMenuItem.Text = "Save";
            // 
            // saveAsToolStripMenuItem
            // 
            this.saveAsToolStripMenuItem.Name = "saveAsToolStripMenuItem";
            this.saveAsToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.saveAsToolStripMenuItem.Text = "Save as";
            // 
            // loadToolStripMenuItem
            // 
            this.loadToolStripMenuItem.Name = "loadToolStripMenuItem";
            this.loadToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.loadToolStripMenuItem.Text = "Load";
            // 
            // exportToolStripMenuItem
            // 
            this.exportToolStripMenuItem.Name = "exportToolStripMenuItem";
            this.exportToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.exportToolStripMenuItem.Text = "Export";
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.importBrushesToolStripMenuItem,
            this.undoToolStripMenuItem,
            this.redoToolStripMenuItem});
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
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(144, 22);
            this.aboutToolStripMenuItem.Text = "About";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(562, 376);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(159, 25);
            this.label3.TabIndex = 5;
            this.label3.Text = "3D view of map";
            // 
            // tw_objects
            // 
            this.tw_objects.Location = new System.Drawing.Point(12, 58);
            this.tw_objects.Name = "tw_objects";
            this.tw_objects.Size = new System.Drawing.Size(200, 660);
            this.tw_objects.TabIndex = 6;
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
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::gränssnitt.Properties.Resources.bg;
            this.pictureBox1.Location = new System.Drawing.Point(218, 58);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(828, 660);
            this.pictureBox1.TabIndex = 4;
            this.pictureBox1.TabStop = false;
            // 
            // btn_TextureBrush
            // 
            this.btn_TextureBrush.BackgroundImage = global::gränssnitt.Properties.Resources.brush1;
            this.btn_TextureBrush.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btn_TextureBrush.Location = new System.Drawing.Point(62, 29);
            this.btn_TextureBrush.Name = "btn_TextureBrush";
            this.btn_TextureBrush.Size = new System.Drawing.Size(50, 50);
            this.btn_TextureBrush.TabIndex = 5;
            this.btn_TextureBrush.UseVisualStyleBackColor = true;
            this.btn_TextureBrush.Click += new System.EventHandler(this.btn_TextureBrush_Click);
            // 
            // btn_TerrainBrush
            // 
            this.btn_TerrainBrush.BackgroundImage = global::gränssnitt.Properties.Resources.brush1;
            this.btn_TerrainBrush.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.btn_TerrainBrush.Location = new System.Drawing.Point(6, 29);
            this.btn_TerrainBrush.Name = "btn_TerrainBrush";
            this.btn_TerrainBrush.Size = new System.Drawing.Size(50, 50);
            this.btn_TerrainBrush.TabIndex = 2;
            this.btn_TerrainBrush.UseVisualStyleBackColor = true;
            this.btn_TerrainBrush.Click += new System.EventHandler(this.btn_TerrainBrush_Click);
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
            // MapEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1264, 730);
            this.Controls.Add(this.btn_export);
            this.Controls.Add(this.cb_history);
            this.Controls.Add(this.btn_load);
            this.Controls.Add(this.btn_save);
            this.Controls.Add(this.btn_redo);
            this.Controls.Add(this.btn_undo);
            this.Controls.Add(this.tw_objects);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.menuStrip);
            this.Controls.Add(this.tc_Tools);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MainMenuStrip = this.menuStrip;
            this.Name = "MapEditor";
            this.Text = "Map Editor";
            this.tc_Tools.ResumeLayout(false);
            this.tp_Map.ResumeLayout(false);
            this.tp_Map.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nud_BrushSize)).EndInit();
            this.menuStrip.ResumeLayout(false);
            this.menuStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TabControl tc_Tools;
		private System.Windows.Forms.MenuStrip menuStrip;
		private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
		private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
		private System.Windows.Forms.PictureBox pictureBox1;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TabPage tp_Map;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TabPage tp_Objects;
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
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Button btn_importTexture;
        private System.Windows.Forms.Button btn_importBrush;
        private System.Windows.Forms.ImageList il_textures;
        private System.Windows.Forms.ImageList il_icons;

	}
}

