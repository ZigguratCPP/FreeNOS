#ifndef __BIN_WAIT_WAIT_H
#define __BIN_WAIT_WAIT_H

#include <POSIXApplication.h>

//wait for a background process to finish and return
class Wait : public POSIXApplication
{
	public:
		/* Constructor
		 * @param argc Argument count
		 * @param argv argumant values 
		 */
		Wait(int argc, char **argv);

		//destructor
		virtual ~Wait();

		/* Execute the application
		 *
		 * @return Result code
		 */
		virtual Result exec();
};

#endif
