// reading a text file
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const char *thermal[] = {
"/sys/class/thermal/thermal_zone0/temp", 
"/sys/class/thermal/thermal_zone1/temp", 
"/sys/class/thermal/thermal_zone2/temp", 
"/sys/class/thermal/thermal_zone3/temp"
};

int CoreTemp(){
	string line;
	//average of all 4 core temps
	int average_core_temp = 0;
	int core_temp = 0;
	
	for(int i = 0; i<4; i++){
	
		ifstream core(thermal[i]);
		if (core.is_open())
		{
			while ( getline (core,line) )
			{
			  stringstream current_temp(line);
			  current_temp >> core_temp;
			  average_core_temp += core_temp;
			}
			core.close();
		}

		else cout << "Unable to open file";
	}
	average_core_temp /= 4;
	return average_core_temp;
	
}


int main () {
	
	cout << "Average cpu temp: " << CoreTemp() << endl;
	return 0;
}
