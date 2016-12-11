////////////////////////////////////////////////////////////////
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
//
//
//2012dec09, creation for generating chuck files and batch files
//			 for each propellerhead recycle output .wav files.
//
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
////////////////////////////////////////////////////////////////

#include <string>
#include <fstream>
#include <vector>

#include <iostream>
#include <sstream>
using namespace std;
//#include <stdlib.h>

#include <ctime>
#include <windows.h>


int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	///////////////////////////////////////
	//load samples.txt into string vector
	///////////////////////////////////////
	vector<string> samplefilenames;
	ifstream ifs("samples.txt");
	string temp;
	while(getline(ifs,temp))
		samplefilenames.push_back(temp);

	///////////////////////////////////////
	//load periods.txt into string vector
	///////////////////////////////////////
	vector<string> periods;
	ifstream ifs2("periods.txt");
	string temp2;
	while(getline(ifs2,temp2))
		periods.push_back(temp2);

	vector<string>::iterator it2;
	vector<string>::iterator it3;
	for ( it2=samplefilenames.begin() ; it2 < samplefilenames.end(); it2++ )
	{
		for ( it3=periods.begin() ; it3 < periods.end(); it3++ )
		{
			//////////////////
			//execute cmd line
			//////////////////
			string quote;
			quote = "\"";
			string command = "spichuckandbatchfilegenerator " + quote + *it2 + quote + " " + *it3;
			cout << command << "\n";
			system(command.c_str());
		}
	}
}