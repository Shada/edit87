#pragma once

#include <string>
#include <Windows.h>

// so, I assume both paths are file paths.. 
//I will remove the filename from filepath1 and 
//go from the resulting path to find the relative path to filepath2
inline std::string combinePaths(std::string filepath1, std::string filepath2) // maybe use const char* instead.. well well.. w/e
{
	filepath1 = filepath1.substr(0, filepath1.find_last_of('/'));

	while (true)
	{
		if(filepath2[0] == '/') // we do not want to have a / in the beginning
		{
			filepath2 = filepath2.substr(1, filepath2.size());
		}
		else if(filepath2[0] == '.') // either this folder, or one folder up
		{
			if(filepath2[1] == '.') // okay, let's go one folder up "../"
			{
				filepath2 = filepath2.substr(3, filepath2.size());
				filepath1 = filepath1.substr(0, filepath1.find_last_of('/'));
			}
			else // okay, we found a "./". it's starting in this folder. remove that from the path
			{
				filepath2 = filepath2.substr(2, filepath2.size());
			}
		}
		else
		{
			break;
		}
	}
	return filepath1 + "/" + filepath2;
};

inline std::wstring s2ws(const std::string& s)
{
	int len;
    int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
};