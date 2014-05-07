using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ComponentModel;
using System.Drawing;
using System.IO;
using System.Xml;

namespace LevelEditor
{
	public static class Utils
	{
		private static XmlDocument projectFile;
		private static DirectoryInfo projectDirectory;
		private static string projectName;

		public static XmlDocument ProjectFile 
		{ 
			get 
			{
				if (projectFile == null)
				{
					projectFile = new XmlDocument();
				}

				return projectFile; 
			}
			set { projectFile = value; }
		}
		public static DirectoryInfo ProjectDirectory 
		{ 
			get { return projectDirectory; }
			set { projectDirectory = value; }
		}

		public static string ProjectName
		{
			get { return projectName; }
			set { projectName = value; }
		}

		public struct twTag
		{
			public enum Type
			{
				UNDEFINED = -1,
				FOLDER = 0,
				IMAGE = 1,
				MESH = 2,
				SOUND = 3
			}

			public bool modifiable;
			public Type type;
			public string realName;

			public twTag(Type _type, bool _deletable = true, string _realName = "N/A")
			{
				type = _type;
				modifiable = _deletable;
				realName = _realName;
			}
		}

		public static class Imgbase
		{
			private static System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MapEditor));
			private static System.ComponentModel.IContainer components = new System.ComponentModel.Container();

			private static ImageList L_bank, M_bank, S_bank;
			private static int counter = 0;

			public static void Init()
			{
				L_bank = new ImageList(components);
				L_bank.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("il_icons.ImageStream")));
				L_bank.TransparentColor = System.Drawing.Color.Transparent;
				L_bank.ImageSize = new System.Drawing.Size(48, 48);

				M_bank = new ImageList(components);
				M_bank.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("il_icons.ImageStream")));
				M_bank.TransparentColor = System.Drawing.Color.Transparent;
				M_bank.ImageSize = new System.Drawing.Size(24, 24);

				S_bank = new ImageList(components);
				S_bank.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("il_icons.ImageStream")));
				S_bank.TransparentColor = System.Drawing.Color.Transparent;
				S_bank.ImageSize = new System.Drawing.Size(12, 12);
			}

			public static void AddImage(string _imgName, Image _img)
			{
				L_bank.Images.Add(_imgName, _img);
				L_bank.Images.SetKeyName(counter, _imgName);

				M_bank.Images.Add(_imgName, _img);
				M_bank.Images.SetKeyName(counter, _imgName);

				S_bank.Images.Add(_imgName, _img);
				S_bank.Images.SetKeyName(counter, _imgName);
			}

			public static ImageList LargeBank { get { return L_bank; } }
			public static ImageList MediumBank { get { return M_bank; } }
			public static ImageList SmallBank { get { return S_bank; } }
		}
	}
}
