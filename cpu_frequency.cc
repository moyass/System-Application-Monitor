#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <main.h>
using namespace std;

// check quick : lscpu | grep -i mhz
// set max manually: cpupower frequency-set -u new_int


#define POWERSAVER_CPU_FREQ "\
#/bin/bash \n\
sudo -A cpupower frequency-set -g powersave \n\
"

#define PERFORMANCE_CPU_FREQ "\
#/bin/bash \n\
sudo -A cpupower frequency-set -g performance \n\
"

//frequency file paths
#define MAX "cat /sys/devices/system/cpu/cpufreq/policy0/cpuinfo_max_freq"
#define MIN "cat /sys/devices/system/cpu/cpufreq/policy0/cpuinfo_min_freq"
#define CURRENT "cat /sys/devices/system/cpu/cpufreq/policy*/scaling_cur_freq"


int CPUFrequencyMax(){
	string line;
	FILE *fp = popen(MAX, "r");
	char buffer[BUFSIZ];
	int max_freq = 0; 
	
	while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

	  stringstream contents(buffer);
	  contents >> max_freq;

	}
	pclose(fp);
	max_freq /= 1000;
	return max_freq;
	
}

int CPUFrequencyMin(){
	string line;
	FILE *fp = popen(MIN, "r");
	char buffer[BUFSIZ];
	int min_freq = 0; 
	
	while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

	  stringstream contents(buffer);
	  contents >> min_freq;

	}
	pclose(fp);
	min_freq /= 1000;
	return min_freq;
	
}

int CurrentFreq(){
	string line;
	FILE *fp = popen(CURRENT, "r");
	char buffer[BUFSIZ];
	int freq = 0; 
	int number_of_cores = 0; 
	int average_freq = 0;
	
	while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

	  stringstream current(buffer);
	  current >> freq;
	  average_freq += freq;
	  number_of_cores++;

	}
	pclose(fp);

	//convert to MHz and average all cores
	average_freq /= number_of_cores * 1000;
	return average_freq;

}

void Powersaver_CPU_FREQ(){ popen(POWERSAVER_CPU_FREQ, "r"); }
void Performance_CPU_FREQ(){ popen(PERFORMANCE_CPU_FREQ, "r"); }

/*
int main () {

	cout << "\nCPU frequency information" << endl;
	cout<<setfill('-')<<setw(80)<<"-"<<endl;
	cout << "Max CPU freq: " << Max() << " MHz" << endl;
	cout << "Min CPU freq: " << Min() << " MHz" << endl;
	
	cout << "Current CPU freq: " << CurrentFreq() << " MHz" << endl;
	cout << "Switch to Powersaver Mode " << endl;
	Powersaver();
	cout << "Current CPU freq: " << CurrentFreq() << " MHz" << endl;
	cout << "Switch to Performance Mode " << endl;
	Performance();
	cout << "Current CPU freq: " << CurrentFreq() << " MHz" << endl;
	
	cout<<setfill('-')<<setw(80)<<"-"<<endl;
	return 0;
}
*/
