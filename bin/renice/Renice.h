#ifndef __BIN_RENICE_RENICE_H
#define __BIN_RENICE_RENICE_H

#include <POSIXApplication.h>

class Renice : public POSIXApplication
{
    public:

    /**
     *
     * @param argc argument count
     * @param argv argument values
     */
    Renice(int argc, char ** argv);

	//destructor
	virtual ~Renice();

    /* 
     * Execute the application.
     * @return Result code
     */
    virtual Result exec();
};

#endif

