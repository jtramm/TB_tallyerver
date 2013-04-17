==============================================================================
        _____ ____    _        _ _                                    
       |_   _| __ )  | |_ __ _| | |_   _ ___  ___ _ ____   _____ _ __ 
         | | |  _ \  | __/ _` | | | | | / __|/ _ \ '__\ \ / / _ \ '__|
         | | | |_) | | || (_| | | | |_| \__ \  __/ |   \ V /  __/ |   
         |_| |____/___\__\__,_|_|_|\__, |___/\___|_|    \_/ \___|_|   
                 |_____|           |___/                              

==============================================================================
Contact Information
==============================================================================

Organization:     Center for Exascale Simulation of Advanced Reactors (CESAR)
                  Argonne National Laboratory

Development Lead: John Tramm <jtramm@mcs.anl.gov>

==============================================================================
What is TB_tallyserver?
==============================================================================

TB_tallyserver is an input deck creator for OpenMC. It is capable of
generating input files for the Hoogenboom-Martin reactor model.

When run, the following files are generated in the current working
directory.

->    geometry.xml
->    tallies.xml

The files are fairly large (~90MB total).

The goal of the TB tallyserver project is to simulate the Hoogenboom-Martin
reactor with separate tally bins for 10 concentric radial regions and
500 axial cuts for each fuel rod.

The geometry.xml file defines 636,240 infinite cylinder cells representing
all of the 10 radial regions of each fuel cell.

The tallies.xml file defines a mesh covering the entire reactor zone,
with 500 regions along the z-axis, as well as specifying each of the
636,240 cells as separate tallies.

This results in a grand total of 318,120,000 tallies.

Considering approximately 65 nuclides, each with 6 reaction types, and
the size of a tally object being 32 bytes, the total tally data can be
calculated as:

	Tally Data = 318,120,000 tallies x 32 bytes/tally x 65 nucs x 6 XS's
	           = 3.61 TB

==============================================================================
Quick Start Guide
==============================================================================

Download----------------------------------------------------------------------

	Download of the TB_tallyserver.tar file is available from the following
	github page:

	https://github.com/jtramm/TB_tallyerver

	Once downloaded, you can decompress using the following
	command on a linux or Mac OSX system:

	>$ tar -xvf TB_tallyserver.tar

	This will decompress the tar file into a directory called
	TB_tallyserver.

	To begin use of the XSBench code, you will have to navigate to
	the src directory:

	>$ cd TB_tallyserver/src

Compilation-------------------------------------------------------------------

	To compile TB_tallyserver with default settings, use the following
	command:

	>$ make

Running XSBench---------------------------------------------------------------

	To run TB_tallyserver with default settings, use the following command:

	>$ ./tb

==============================================================================
