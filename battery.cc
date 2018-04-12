#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

#define POWERSAVER_BATTERY "\
#!/bin/bash\n\
MAX_BRIGHTNESS=$(cat /sys/class/backlight/intel_backlight/max_brightness)\n\
mid=`echo \"$MAX_BRIGHTNESS * 0.25\" | bc -l`\n\
printf '%0.0f' \"$mid\" > /sys/class/backlight/intel_backlight/brightness\n\
"

#define PERFORMANCE_BATTERY "\
#!/bin/bash\n\
MAX_BRIGHTNESS=$(cat /sys/class/backlight/intel_backlight/max_brightness)\n\
mid=`echo \"$MAX_BRIGHTNESS * 0.25\" | bc -l`\n\
printf '%0.0f' \"$MAX_BRIGHTNESS\" > /sys/class/backlight/intel_backlight/brightness\n\
"


#define CURRENT "cat /sys/class/backlight/intel_backlight/brightness"
//#define MIN "cat /sys/class/backlight/intel_backlight/bl_power"
#define MIN 0 //all screens turn off
#define MAX "cat /sys/class/backlight/intel_backlight/max_brightness"

#define BACKLIGHT "cat /sys/class/leds/mmc0::"
#define CHARGE "cat /sys/class/power_supply/BAT0/charge_now"
#define FULL "cat /sys/class/power_supply/BAT0/charge_full"
#define GET_BATTERY_PERCENTAGE "${PWD}/battery-percentage.sh"

int GetBatteryPercentage(){
    FILE *fp = popen(GET_BATTERY_PERCENTAGE,"r");

    string line;
    char buffer[BUFSIZ];
    int brightness;

    while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {
      stringstream max(buffer);
      max >> brightness;
    }

    pclose(fp);
    return brightness;

}

int CurrentBrightness(){
	FILE *fp = popen(CURRENT, "r");
	
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

int MaxBrightness(){

	FILE *fp = popen(MAX, "r");
	
	string line;
	char buffer[BUFSIZ];
	int brightness;
	
	while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {
	  stringstream max(buffer);
	  max >> brightness;
	}
	
	pclose(fp);
	return brightness;
}

void Powersave_Battery(){popen(POWERSAVER_BATTERY, "r");}
void Performace_Battery(){popen(PERFORMANCE_BATTERY, "r");}

int ChargeInfo(){

	FILE *fp = popen(CHARGE, "r");

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
	int low = ChargeInfo()/85;
	if(ChargeInfo() <= low){
		return 1;
	}
	return 0;
}

/*
int main () {

    cout << "\nScreen Brightness information" << endl;
    cout<<setfill('-')<<setw(80)<<"-"<<endl;
    cout << "Current: " << CurrentBrightness() << endl;
    cout << "Max: " << MaxBrightness() << endl;
    Powersaver();
    cout << "Current: " << CurrentBrightness() << endl;
    Performance();
    cout << "Current: " << CurrentBrightness() << endl;
    cout<<setfill('-')<<setw(80)<<"-"<<endl;
    cout << "\nBattery information" << endl;
    cout << "Current Charge: " << ChargeInfo() << endl;
	
    if(BatteryLow()) Powersaver();
	
    return 0;
}
*/
