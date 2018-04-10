#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

        //bash script
        //sudo echo VALUE > /sys/class/backlight/intel_backlight/brightness

#define CURRENT "cat /sys/class/backlight/intel_backlight/brightness"
#define MIN "cat /sys/class/backlight/intel_backlight/bl_power"
#define MAX "cat /sys/class/backlight/intel_backlight/max_brightness"

#define CHARGE "cat /sys/class/power_supply/BAT0/charge_now"
#define FULL "cat /sys/class/power_supply/BAT0/charge_full"

int BrightnessInfo(int state){
	if(state == 0) FILE *fp = popen(CURRENT, "r");
	else if(state == 1) FILE *fp = popen(MIN, "r");
	else FILE *fp = popen(MAX, "r");
	
	string line;
	char buffer[BUFSIZ];
	int brightness;
	
	while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {
	  stringstream current(buffer);
	  current >> brightness;
	}
	
	pclose(fp);
	return brightness;
	
}

int Set(char brightness){
	//'l' low
	//'m' mid
	//'h' high

	string line;
	FILE *fp = popen(CURRENT, "w");
	char buffer[BUFSIZ];
	int low = StateInfo(1);
	int mid = StateInfo(2)/2;
	int high = StateInfo(2);
	return 0;
}

int ChargeInfo(int check){

	if(check == 0) FILE *fp = popen(CHARGE, "r");
	else FILE *fp = popen(FULL, "r");

        string line;
        char buffer[BUFSIZ];
        int charge;

        while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {
          stringstream current(buffer);
          current >> charge;
        }

        pclose(fp);
        return charge;
}

int BatteryLow(){
	int low = ChargeInfo(1)/60;
	if(ChargeInfo(0) <= low){
		return 1;
	}
	return 0;
}

int main () {
	cout << "\nScreen Brightness information" << endl;
	cout<<setfill('-')<<setw(80)<<"-"<<endl;
	cout << "Current: " << BrightnessInfo(0) << endl;
	cout << "Min: " << BrightnessInfo(1) << endl;
	cout << "Max: " << BrightnessInfo(2) << endl;
	cout << "Set: " << Set('m') << endl;
	cout<<setfill('-')<<setw(80)<<"-"<<endl;
        cout << "\nBattery information" << endl;

	return 0;
}
