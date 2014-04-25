using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace LevelEditor
{
	class ObjectProperties
	{
		private string m_name;

		[Category("Object Settings")]
		[Description("Set the name of the object")]	
		public string Name
		{
			get { return m_name; }
			set { m_name = value; }
		}

		private int m_count;
		[Category("Object Settings")]
		[Description("Set the count of something")] 
		public int Count 
		{
			get { return m_count; }
			set { m_count = value; }
		}

		private Color m_color;
		[Category("Object Settings")]
		[Description("Set the color of the object")] 
		public Color Color
		{
			get { return m_color; }
			set { m_color = value; }
		}

		private bool m_enabled;
		[Category("Object Settings")]
		[Description("Set if the object is enabled")] 
		public bool Enabled
		{
			get { return m_enabled; }
			set { m_enabled = value; }
		}
	}
}
