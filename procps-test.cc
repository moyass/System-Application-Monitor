#include <stdio.h>
#include <stdlib.h>
#include <proc/readproc.h>
#include <string.h>
#include <iostream>
#include <malloc.h>

using namespace std;



int main (){
    PROCTAB* proc = openproc(PROC_FILLMEM | PROC_FILLSTAT | PROC_FILLSTATUS);
    
    proc_t proc_info;
    
    memset(&proc_info, 0, sizeof(proc_info));


    while (readproc(proc, &proc_info) != NULL) {
        fprintf(stdout, "%20s: \t%5d\t%5ld\n",
                proc_info.cmd, proc_info.suid,
                proc_info.vm_size);
    }

    cout << "size of proc " << sizeof(proc) << "\n";
    cout << "size of proc_info " << sizeof(proc_info) << "\n";

    closeproc(proc);


    return 1;

}