#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/types.h>
#include "Wait.h"

Wait::Wait(int argc, char **argv)
	: POSIXApplication(argc, argv)
{
	parser().setDescription("Wait for a background process to complete");
	parser().registerPositional("PROCESSID", "Wait for the process of the given ID to finish");
}

Wait::~Wait()
{}

Wait::Result Wait::exec()
{
	pid_t process_id = atoi(arguments().get("PROCESSID"));
	int wstatus; //we don't really care about the why it was completed for now, just that it completes

	//on failure
	if (waitpid(process_id, &wstatus, 0) == -1)
	{
		ERROR("failed to wait: " << strerror(errno));
		return IOError;
	}

	//on success
	return Success;
}
