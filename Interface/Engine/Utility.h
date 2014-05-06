#pragma once
#include <string>

// so, I assume both paths are file paths.. 
//I will remove the filename from filepath1 and 
//go from the resulting path to find the relative path to filepath2
std::string combinePaths(std::string filepath1, std::string filepath2) // maybe use const char* instead.. well well.. w/e
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
}