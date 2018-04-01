// reading a text file
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


int CoreTemp(){
	string line;
	FILE *fp = popen("cat /sys/class/thermal/thermal_zone*/temp", "r");
	char buffer[BUFSIZ];
	int core_temp, number_of_cores, average_core_temp;
	
	while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

	  stringstream current_temp(buffer);
	  current_temp >> core_temp;
	  average_core_temp += core_temp;
	  number_of_cores++;

	}
	pclose(fp);
	average_core_temp /= number_of_cores * 1000;
	return average_core_temp;
	
}


int main () {
	
	cout << "Average cpu temp: " << CoreTemp() << " degrees Celcius" << endl;
	return 0;
}
