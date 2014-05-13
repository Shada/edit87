using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;
using System.Globalization;

namespace LevelEditor
{
	class Vector3Converter : ExpandableObjectConverter
	{
		public override bool CanConvertTo(ITypeDescriptorContext context, Type destinationType)
		{
			if (destinationType == typeof(Vector3))
			{
				return true;
			}

			return base.CanConvertTo(context, destinationType);
		}

		public override object ConvertTo(ITypeDescriptorContext context, CultureInfo culture, object value, Type destinationType)
		{
			if (destinationType == typeof(string) && value is Vector3)
			{
				Vector3 v3 = (Vector3)value;

				return "X: " + v3.X + ", Y: " + v3.Y + ", Z: " + v3.Z;
			}

			return base.ConvertTo(context, culture, value, destinationType);
		}

		public override bool CanConvertFrom(ITypeDescriptorContext context, Type sourceType)
		{
			if (sourceType == typeof(Vector3))
			{
				return true;
			}

			return base.CanConvertFrom(context, sourceType);
		}

		public override object ConvertFrom(ITypeDescriptorContext context, CultureInfo culture, object value)
		{
			if (value is string)
			{
				try
				{
					string s = (string)value;
					string[] sArr = s.Split(',');
					float[] res = new float[3];

					for (int i = 0; i < 3; i++)
					{
						string[] tmpArr = sArr[i].Split(':');
						string tmpS = tmpArr[1].Trim();
						res[i] = Convert.ToSingle(tmpS, culture);
					}

					return new Vector3(res[0], res[1], res[2]);
				}
				catch
				{
					throw new ArgumentException("Can not convert '" + (string)value + "' to type Vector3");
				}
			}

			return base.ConvertFrom(context, culture, value);
		}
	}

	class Vector3 
	{
		private float x,y,z;

		public Vector3(float _x, float _y, float _z)
		{
			x = _x;
			y = _y;
			z = _z;
		}

		public Vector3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		public float X
		{
			get { return x; }
			set { x = value; }
		}

		public float Y
		{
			get { return y; }
			set { y = value; }
		}

		public float Z
		{
			get { return z; }
			set { z = value; }
		}
	}


	class PropertyBase
	{
		private string showName, realName;
		private Vector3 position, scale, rotation;

		public string ShowName
		{
			get { return showName; }
			set { showName = value; }
		}

		public string RealName
		{
			get { return realName; }
			set { realName = value; }
		}

		[TypeConverterAttribute(typeof(Vector3Converter))]
		public Vector3 Position
		{
			get { return position; }
			set { position = value; }
		}

		[TypeConverterAttribute(typeof(Vector3Converter))]
		public Vector3 Scale
		{
			get { return scale; }
			set { scale = value; }
		}

		[TypeConverterAttribute(typeof(Vector3Converter))]
		public Vector3 Rotation
		{
			get { return rotation; }
			set { rotation = value; }
		}
	}
}
