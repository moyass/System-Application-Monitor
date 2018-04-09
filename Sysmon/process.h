#ifndef PROCESS_H
#define PROCESS_H

#include <string.h>
#include <iostream>
#include "main.h"

#define MAX_HISTORY 1000

using namespace std;

class Process  {

    string processName = "";
    pid_t currentPID = 0;

    vector<double> currentRSS;
    vector<double> currentVM;
    vector<double> currentSHR;

public:
    void setName (string name){
        processName = name;
    }

    string getName (){
        return processName;
    }

    pid_t getPID(){
        return currentPID;
    }

    void insert(MemType type, double value){
        switch(type){
        case RSS:
            currentRSS.push_back(value);
            break;
        case VM:
            currentVM.push_back(value);
            break;
        case SHR:
            currentSHR.push_back(value);
            break;
        case PID:
            currentPID = value;
            break;
        }
    }

    bool WithinRange(MemType type, double value){
        switch(type){
            case RSS:
                return range(currentRSS.back(), value);
                break;
            case VM:
                for (double s: currentVM){
                    cout << s << "," ;
                }
                break;
            case SHR:
                for (double s: currentSHR){
                    cout << s << "," ;
                }
                break;
        }
    }


    int compare(MemType type, double value ){
        // Model the data points
        return 1;
    }


    void printOutValues(MemType type){
        switch(type){
            case RSS:
                for (double s: currentRSS){
                    cout << s << "," ;
                }
                break;
            case VM:
                for (double s: currentVM){
                    cout << s << "," ;
                }
                break;
            case SHR:
                for (double s: currentSHR){
                    cout << s << "," ;
                }
                break;
        }
    }


private:

    bool range(double oldValue, double newValue){
        if((newValue / oldValue ) > 1)
            return true;
        else
            return false;
    }

    void resize(){
        // resize array once we are at max history
        // remove first 100 items and shift back
        // find a better way of doing this
    }

};

#endif // PROCESS_H
