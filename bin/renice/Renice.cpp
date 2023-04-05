#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/priority.h>
#include "Renice.h"

Renice::Renice(int argc, char **argv)
	: POSIXApplication(argc, argv)
{
	parser().setDescription("Wait for a background process to complete");
    parser().registerFlag('n', "priority", "specify the scheduling priority to be used for the process");
	parser().registerPositional("PRIORITY", "Set the process to this priority");
    parser().registerPositional("PROCESSID", "Specify the process to be reniced");
}

Renice::~Renice()
{}

Renice::Result Renice::exec()
{
	pid_t process_id = atoi(arguments().get("PROCESSID"));
    int priority = atoi(arguments().get("PRIORITY"));
	int wstatus; //we don't really care about the why it was completed for now, just that it completes

	//on failure
	if (prioritizepid(process_id, priority, &wstatus, 0) == -1)
	{
		
		return IOError;
	}

	//on success
	return Success;
}

