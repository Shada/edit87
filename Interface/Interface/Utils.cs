using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ComponentModel;
using System.Drawing;

namespace LevelEditor
{
	public static class Utils
	{
		public struct twTag
		{
			public enum Type
			{
 				UNDEFINED = -1,
				FOLDER,
				IMAGE,
				MESH,
				SOUND
			}

			public bool modifiable;
			public Type type;

			public twTag(Type _type, bool _deletable = true)
			{
				type = _type;
				modifiable = _deletable;
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
