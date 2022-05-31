#include <fstream>
#include <iostream>
#include "datadistributor.h"
using namespace std;
string gl_loadPath();
string getPath(string output);
string gl_userinput;
string gl_filename;
string gl_newPath;
void createDir();
void createFile();
int clearT();
int errMsg = 0;

int main()
{
	createDir(); // creates folder "folder" see function @functions.cpp
	gl_loadPath(); // loads the paths into variables see function @functions.cpp
	do
	{
		clearT();
		if (errMsg == 1)
		{
			cout << "\t\t\t\t\t\t\033[1;31m    file already exists!\033[0m\n\n";
		}
		else if (errMsg == 2)
		{
			cout << "\t\t\t\t\t\t\033[1;31m    please enter a filename!\033[0m\n\n";
		}
		cout << "\t\t\t\t\t\tFilename: ";
		getline(cin, gl_userinput); // takes userinput as filename
		gl_userinput.erase(remove(gl_userinput.begin(), gl_userinput.end(), ' '), gl_userinput.end()); // clears the userinput from spaces
		gl_loadPath();
		if (ifstream(gl_singleFilePath))
		{
			errMsg = 1;
		}
		else if (gl_userinput.empty())
		{
			errMsg = 2;
		}
		else if (ifstream(gl_metaFilePath)) // if the metafile already exists = add new line in file with filename
		{
			createFile();
			fstream writeFile;
			writeFile.open(gl_metaFilePath, fstream::app); // creates the meta file @gl_metaFilePath to read from it.
			if (writeFile.is_open())
			{
				writeFile << gl_userinput + "\n"; // writes and saves the created filename into the metafile.
				writeFile.close();
			}
			clearT();
			gl_newPath = gl_singleFilePath;
			return false;
		}
		else if (!ifstream(gl_metaFilePath)) // if metafile does not exist = create one
		{
			createFile();
			ofstream{ gl_metaFilePath };
			ofstream outFile;
			outFile.open(gl_metaFilePath);
			outFile << gl_userinput + "\n";
			outFile.close();
			clearT();
			gl_newPath = gl_singleFilePath;
			return false;
		}
	} while (true);
	return 0;
}

void createFile()
{
	ofstream outFile;
	gl_filename = gl_userinput + ".save";
	outFile.open(gl_singleFilePath);
	outFile << gl_userinput + "\n" << gl_filename + "\n" << "1337\n" << "1\n";
	outFile.close();
	return;
}
