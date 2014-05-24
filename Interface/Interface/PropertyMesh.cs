using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace LevelEditor
{
	class PropertyMesh : PropertyBase
	{
		private uint polygonCount;
		private Image texture;

		public uint PolygonCount
		{
			get { return polygonCount; }
			set { polygonCount = value; }
		}

		public Image Texture
		{
			get { return texture; }
			set { texture = value; }
		}
	}
}
