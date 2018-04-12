#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "main.h"

using namespace std;


#define GETCPU "\
#!/bin/bash \n\
cpuName=$(lscpu | sed -nr '/Model name/ s/.*:\s*(.*) @ .*/\1/p' | sed ':a;s/  / /;')\n\
echo $cpuName \
"

string GetTotalStorage(){
    string line;
    FILE *fp = popen("df | grep '^/dev/[hs]d' | awk '{s+=$2} END {print s/1048576}'", "r");

    char buffer[BUFSIZ];

    while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

      stringstream contents(buffer);
      contents >> line;

    }
    pclose(fp);
    return line.append(" GB");
}

string GetTotalMemory(){
    string line;
    FILE *fp = popen("awk '/MemTotal/ { printf \"%.2f\", $2/1024/1024 }' /proc/meminfo", "r");

    char buffer[BUFSIZ];

    while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

      stringstream contents(buffer);
      contents >> line;

    }
    pclose(fp);
    return line.append(" GB");
}

string GetCPUName(){
    string line;
    double value;
    FILE *fp = popen("grep -m 1 \"model name\" /proc/cpuinfo | cut -d: -f2 | sed -e 's/.*:\s*(.*)@.*/\1/p' | sed -e 's/$// '|sed -e 's/^[ \t]*//' | tr -d '\n'", "r");

    char buffer[BUFSIZ];

    while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

      stringstream contents(buffer);
      contents >> line;

    }
    pclose(fp);
    return buffer;
}

double CurrentCPUUsage(){
      string line;
      double value;
      FILE *fp = popen("top -d 0.5 -b -n2 | grep \"Cpu(s)\"|tail -n 1 | awk '{print $2 + $4}'", "r");
      char buffer[BUFSIZ];

      while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

        stringstream contents(buffer);
        contents >> value;
        //cout << value << endl;

      }
      pclose(fp);
      return value;
}

double CurrentMemoryUsage(){
        string line;
        double value;
        FILE *fp = popen("free | grep Mem | awk '{print $3/$2 * 100.0}'", "r");
        char buffer[BUFSIZ];

        while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

          stringstream contents(buffer);
          contents >> value;

        }
        pclose(fp);
        return value;
}

string GetKernelVersion(){
        string line;
        FILE *fp = popen("uname -r", "r");
        char buffer[BUFSIZ];

        while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

          stringstream contents(buffer);
          contents >> line;

        }
        pclose(fp);
        return line;
}

string GetHostName(){
        string line;
        FILE *fp = popen("uname -n", "r");
        char buffer[BUFSIZ];
        while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

          stringstream contents(buffer);
          contents >> line;

        }
        pclose(fp);
        return line;
}

string GetPlatformName(){
        string line;
        FILE *fp = popen("uname -m", "r");
        char buffer[BUFSIZ];

        while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

          stringstream contents(buffer);
          contents >> line;

        }
        pclose(fp);
        return line;
}


string GetDistroName(){
        string line;
        FILE *fp = popen("cat /etc/issue |awk '{print $1 "  " $2 "  " $3}'", "r");
        char buffer[BUFSIZ];

        while ( fgets( buffer, BUFSIZ, fp ) != NULL ) {

          stringstream contents(buffer);
          contents >> line;

        }
        pclose(fp);
        return line;
}
