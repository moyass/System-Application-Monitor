#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;


int CoreTemp(){
	string line;
	FILE *fp = popen("cat /sys/class/hwmon/hwmon1/temp*_input", "r");
	char buffer[BUFSIZ];
	int core_temp = 0; 
	int number_of_cores = 0; 
	int average_core_temp = 0;
	
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

int SocketTemp(){
	//acpitz
	string line;
	FILE *fp = popen("cat /sys/class/hwmon/hwmon0/temp*_input", "r");
	char buffer[BUFSIZ];
	int socket_temp = 0; 
	
	while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

	  stringstream current_temp(buffer);
	  current_temp >> socket_temp;

	}
	pclose(fp);
	socket_temp /= 1000;
	return socket_temp;
	
}

int PackageTemp(){
	//pch_skylake
	string line;
	FILE *fp = popen("cat /sys/class/hwmon/hwmon2/temp*_input", "r");
	char buffer[BUFSIZ];
	int pack_temp = 0; 
	
	while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

	  stringstream current_temp(buffer);
	  current_temp >> pack_temp;

	}
	pclose(fp);
	pack_temp /= 1000;
	return pack_temp;
}

int MaxTemp(){

	string line;
	FILE *fp = popen("cat /sys/class/hwmon/hwmon1/temp*_crit", "r");
	char buffer[BUFSIZ];
	int core_temp = 0; 
	int max_core_temp = 0;
	
	while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {
		stringstream current_temp(buffer);
		current_temp >> core_temp;
		
		if(core_temp > max_core_temp)
			max_core_temp = core_temp;
	}
	return max_core_temp / 1000;
}

int Alarm(){

	int danger_zone = MaxTemp() - 20;

	if(CoreTemp() >= danger_zone) return 1;
	else return 0;

}


int main () {
	cout << "\nCPU temperature information" << endl;
	cout<<setfill('-')<<setw(80)<<"-"<<endl;
	cout << "Average CPU temp (all cores): " << CoreTemp() << " degrees Celcius" << endl;
	cout << "CPU Package temp: " << PackageTemp() << " degrees Celcius" << endl;
	cout << "CPU Socket temp: " << SocketTemp() << " degrees Celcius" << endl;
	cout << "Max CPU temp: " << MaxTemp() << " degrees Celcius" << endl;

	if(Alarm())
		cout << "CPU temp is dangerously high!" << endl;
	else
		cout << "CPU temp is gucci" << endl;
	cout<<setfill('-')<<setw(80)<<"-"<<endl;
	return 0;
}
