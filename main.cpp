/*
 * Copyright (c) 2010-2016 Stephane Poirier
 *
 * stephane.poirier@oifii.org
 *
 * Stephane Poirier
 * 3532 rue Ste-Famille, #3
 * Montreal, QC, H2X 2L1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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