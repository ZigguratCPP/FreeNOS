#ifndef __LIBPOSIX_PRIORITY_H
#define __LIBPOSIX_PRIORITY_H

#include <Macros.h>
#include "types.h"

/**
 * @brief Wait for a child process to stop or terminate
 *
 * The prioritizepid function changes the priority of the process specified by pid to the value specified by priority.
 *
 * @param pid Process ID of child to wait for.
 * @param priority Priority to set the process to
 *
 * @return 0 if success, 1 if pid not found, 2 if dumb
 */
extern C unsigned int prioritizepid(pid_t pid, int priority);

#endif /* __LIBPOSIX_PRIORITY_H */
