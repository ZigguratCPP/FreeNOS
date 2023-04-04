/*
 * Copyright (C) 2015 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <unistd.h>
//#include <cstring> cstring doesnt exist in freenos apparently
#include <ProcessClient.h>
#include "ProcessList.h"

ProcessList::ProcessList(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Output system process list");
    parser().registerFlag('l', "show_priority", "Show the priority of the processes as well");
}

ProcessList::Result ProcessList::exec()
{
    const ProcessClient process;
    String out;

    // Print header
    out << "\nID  PARENT  USER GROUP STATUS     ";
    
    //for the priority project
    //print priority header if the flag is set
    if (arguments().get("show_priority"))
    {
        out << "Priority ";
    }
    
    //print end of header
    out << "CMD";

    // Loop processes
    for (ProcessID pid = 0; pid < ProcessClient::MaximumProcesses; pid++)
    {
        ProcessClient::Info info;

        const ProcessClient::Result result = process.processInfo(pid, info);
        if (result == ProcessClient::Success)
        {
            DEBUG("PID " << pid << " state = " << *info.textState);

            // Output a line
            const int maxlen = 128;
            char line1[maxlen];
            snprintf(line1, maxlen,
                    "\n%3d %7d %4d %5d %10s ",
                     pid, info.kernelState.parent,
                     0, 0, *info.textState);

            int lenleft = maxlen - len(line1);
            char* line2 = new char[lenleft];
            
            if (arguments().get("show_priority"))
            {
                snprintf(line2, lenleft,
                        "%8d ",
                        info.kernelState.priority);
            }
            
            lenleft = lenleft - len(line2);
            char* line3 = new char[lenleft];
            snprintf(line3, lenleft,
                    "%32s",
                    *info.command);
    
            out << line1 << line2 << line3;
        }
    }
    out << "\n";
    // Output the table
    write(1, *out, out.length());
    return Success;
}

//helper to find the length of a string
int ProcessList::len(char* str)
{
    int len = 0;
    while (str[len] != 0)
    {
        len++;
    }
    
    return len;
}
