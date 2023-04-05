#include <FreeNOS/User.h>
#include "sys/priority.h"
#include "sys/types.h"
#include <errno.h>

unsigned int prioritizepid(pid_t pid, int priority) {
    
    ProcessInfo info; 
    
    if (ProcessCtl(pid, InfoPID, (Address) &info) != API::Success)
    {
        return 1;
    }

    info.priority = priority;


    if (ProcessCtl(pid, SetPriority, (Address) &info) != API::Success)
    {
        return 2;
    }

    //done
    return 0;

}