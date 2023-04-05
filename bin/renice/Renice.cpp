#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/priority.h>
#include <sys/types.h>
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


	//on failure
	if (prioritizepid(process_id, priority) != 0)
	{
		ERROR("failed to renice: " << strerror(errno));
		return IOError;
	}

	//on success
	return Success;
}

