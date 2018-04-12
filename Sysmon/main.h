#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include "unistd.h"
#include "limits.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <dirent.h>
#include <vector>
#include <proc/readproc.h>
#include <sys/types.h>
#include <signal.h>
#include <string>


// CPU Temperature
int CoreTemp();
int SocketTemp();
int MaxTemp();
int PackageTemp();
int MaxTemp();
int Alarm();

// Battery.cc
int  CurrentBrightness();
int  MaxBrightness();
int  ChargeInfo();
void Powersave_Battery();
void Performace_Battery();
int  BatteryLow();
int GetBatteryPercentage();

// CPU Frequency
int  CurrentFreq();
int  CPUFrequencyMax();
int  CPUFrequencyMin();
void Powersaver_CPU_FREQ();
void Performance_CPU_FREQ();

// Get System Information
std::string GetKernelVersion();
std::string GetHostName();
std::string GetPlatformName();
std::string GetDistroName();
std::string GetCPUName();
std::string GetTotalMemory();
std::string GetTotalStorage();
double CurrentMemoryUsage();
double CurrentCPUUsage();


typedef struct MemoryHistory {
  /* Delta between multiple memory usages */
  int old = 0;
  int older = 0;
  int oldest = 0;

} MemoryHistory;

typedef struct statstruct_proc {
  int           pid;                      /** The process id. **/
  char          exName [_POSIX_PATH_MAX]; /** The filename of the executable **/
  char          state; /** 1 **/          /** R is running, S is sleeping,
                                            D is sleeping in an uninterruptible wait,
                                            Z is zombie, T is traced or stopped **/
  unsigned      euid,                      /** effective user id **/
                egid;                      /** effective group id */
  int           ppid;                     /** The pid of the parent. **/
  int           pgrp;                     /** The pgrp of the process. **/
  int           session;                  /** The session id of the process. **/
  int           tty;                      /** The tty the process uses **/
  int           tpgid;                    /** (too long) **/
  unsigned int	flags;                    /** The flags of the process. **/
  unsigned int	minflt;                   /** The number of minor faults **/
  unsigned int	cminflt;                  /** The number of minor faults with childs **/
  unsigned int	majflt;                   /** The number of major faults **/
  unsigned int  cmajflt;                  /** The number of major faults with childs **/
  int           utime;                    /** user mode jiffies **/
  int           stime;                    /** kernel mode jiffies **/
  int		        cutime;                   /** user mode jiffies with childs **/
  int           cstime;                   /** kernel mode jiffies with childs **/
  int           counter;                  /** process's next timeslice **/
  int           priority;                 /** the standard nice value, plus fifteen **/
  unsigned int  timeout;                  /** The time in jiffies of the next timeout **/
  unsigned int  itrealvalue;              /** The time before the next SIGALRM is sent to the process **/
  int           starttime; /** 20 **/     /** Time the process started after system boot **/
  unsigned int  vsize;                    /** Virtual memory size **/
  unsigned int  rss;                      /** Resident Set Size **/
  unsigned int  anonrss;                  /** From /proc/PID/status */
  unsigned int  rlim;                     /** Current limit in bytes on the rss **/
  unsigned int  startcode;                /** The address above which program text can run **/
  unsigned int	endcode;                  /** The address below which program text can run **/
  unsigned int  startstack;               /** The address of the start of the stack **/
  unsigned int  kstkesp;                  /** The current value of ESP **/
  unsigned int  kstkeip;                 /** The current value of EIP **/
  int		        signal;                   /** The bitmap of pending signals **/
  int           blocked; /** 30 **/       /** The bitmap of blocked signals **/
  int           sigignore;                /** The bitmap of ignored signals **/
  int           sigcatch;                 /** The bitmap of catched signals **/
  unsigned int  wchan;  /** 33 **/        /** (too long) **/
  int		        sched, 		  /** scheduler **/
                sched_priority;		  /** scheduler priority **/
  MemoryHistory mh;

} procinfo;

typedef struct statusstruct_proc {
  char          exName [_POSIX_PATH_MAX]; /** The filename of the executable **/
  unsigned int  rssAnon;
} procInfoStatus;

enum MemType {
    RSS,VM,SHR, PID
};


int get_proc_info(pid_t pid, procinfo * pinfo);

#endif // MAIN_H
