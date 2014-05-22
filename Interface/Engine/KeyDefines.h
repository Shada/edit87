#pragma once

/* define shortcut keybindings */

typedef std::pair<unsigned int,bool>		KeyBinding;		// key state (variable)

// state bindings
enum class Key
{
	NO_STATE		= 666,
	STATE_ROTATE	= 'R',
	STATE_MOVE		= 'M',
	STATE_SCALE		= 'T',
	STATE_PLACE		= 'N',
	STATE_TERRAIN	= 'Z',
	STATE_FOLLOW_TERRAIN = 'F',
	STATE_ELEVATE = 'E',
	STATE_LOWER = 'Q',
};
