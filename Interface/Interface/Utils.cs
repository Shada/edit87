using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LevelEditor
{
	public class Utils
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

			public bool deletable;
			public Type type;

			public twTag(Type _type, bool _deletable = true)
			{
				type = _type;
				deletable = _deletable;
			}
		}
	}
}
