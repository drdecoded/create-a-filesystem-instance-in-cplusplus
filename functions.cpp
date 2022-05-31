#include <iostream>
#include <direct.h>
#include <algorithm>
#include "datadistributor.h"
using namespace std;
string gl_currentPath;
string gl_folderPath;
string gl_metaFilePath;
string gl_singleFilePath;


string getPath(string output)
{
	char tmp[256];
	_getcwd(tmp, 256);
	output = tmp;
	replace(output.begin(), output.end(), '\\', '/');
	return output;
}

string gl_loadPath()
{
	gl_currentPath = getPath(gl_currentPath);
	gl_folderPath = (gl_currentPath + "/folder/");
	gl_metaFilePath = (gl_folderPath + "metafile.save");
	gl_singleFilePath = (gl_folderPath + gl_userinput + ".save");
	return gl_currentPath, gl_folderPath, gl_metaFilePath, gl_singleFilePath;
}

void createDir()
{
	string outpath;
	outpath = getPath(outpath); // output if folder couldnt be created @outpath
	bool createDir = true;
	while (_mkdir("folder") && createDir == true)
	{
		if (errno == EEXIST)
		{
			cout << "folder already exists!";
			createDir = false;
		}
		else
		{
			cout << "ERROR: cannot create folder 'include' in path " << outpath;
		}
	}
	return;
}

int clearT()
{
	return system("cls"); // clear terminal
}