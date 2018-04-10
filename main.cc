// Latest working version

#include "main.h"
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


/* Lists all directories in the provided directory */
vector<pid_t> listDir(const string& path)
{
    DIR *dir;
    struct dirent *ent;

    pid_t current;

    vector<pid_t> listofprocs;

    if((dir = opendir (path.c_str())) != NULL)
        while ((ent = readdir (dir)) != NULL)
            if(sscanf(ent->d_name, "%d%*c", &current) == 1)
                listofprocs.push_back(current);



    closedir (dir);
    return listofprocs;
}


int GetAllProcsInfo(procinfo *tProcInfo, vector<pid_t> *procs, bool display){
    for (pid_t pid : *procs){
        get_proc_info(pid, tProcInfo);

        if(display){
        cout << tProcInfo -> pid << setw(6) 
            << "  :" << setw(30) <<  tProcInfo -> exName 
            << setw(20) << tProcInfo -> rss
            << setw(20) << tProcInfo -> vsize 
            << endl;


        /** LOGIC
         * Get the value in the first loop and store it in old
         * in the second loop we compare that last value of old
         * memory old history.
         * 
         */
        if (strcmp(tProcInfo -> exName, "a.out") == 0){
            cout << tProcInfo -> exName << " under PID " << tProcInfo -> pid 
                 << " is using " << tProcInfo -> vsize / 1024 << " KB" << endl;
        }
        }



        /*
        if (tProcInfo -> mh.old < tProcInfo -> vsize) {
            cout << "Process " << tProcInfo -> exName << " seems to be increasing rapidly. old = " <<
            tProcInfo -> mh.old << " new = "<< tProcInfo -> vsize << endl;
            tProcInfo -> mh.old = tProcInfo -> vsize;
        } else {
            tProcInfo -> mh.old = tProcInfo -> vsize;
        }
        */
    }

}



int main (int argc, char *argv[]){

    /* Store proc information
     * structure defined in header file */
    procinfo tProcInfo;

    /* Vector to store all the processes from /proc/ */
    vector<pid_t> procs;
 
    cout << "Total Process Count " << procs.size() << endl;
    cout << "Process PID  " << setw(6) << setw(20) <<  "COMMAND NAME" 
             << setw(20) << "RSS" << setw(20) << "VmSize" << endl;


    while (1){
        procs = listDir("/proc/");
        GetAllProcsInfo(&tProcInfo, &procs, 1);

        sleep(10);
        system("clear");
    }
    

    return 1;
}