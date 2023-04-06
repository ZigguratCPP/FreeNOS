About {#mainpage}
=====


Contributors
=======

The FreeNOS code has been written from scratch by Niek Linnenbank.
People who contributed to this FreeNOS fork are:

* Mason Nash (SkeltalFlamingo): led renice implementation, provided VSCode
* Anthony Seward (Aseward1005): Implemented priority levels
* Together we worked on renice and adding the -l flag to ps

There is a bug (feature) when using renice to prioritize something above priority level 3. 
Because priorities are 3 by default, the renice command stalls when using it to assign a priority higher than itself after the scheduler is called.

Rather than modifying ProcessClient, we wrote a new syscall, prioritizepid, as ProcessClient seems to only gather information about the process, not change anything about it.

The process resembled sleep much more closely than ps.

The ML algorithm was used for scheduling; partially for extra credit, mostly because it was easier.

Priority Implementation Video:
https://youtu.be/f0smF176JdI
