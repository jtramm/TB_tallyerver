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

The goal of the TB tallyserver project is to simulate the Hoogenboom-Martin
reactor with separate tally bins for 10 concentric radial regions and
500 axial cuts for each fuel rod.

TB_tallyserver is an input deck creator for OpenMC, capabel of creating the
input files necessary to define the Hoogenboom-Martin TB model.

When run, the following files are created in the current working
directory. Note that the files are fairly large (~90MB total).

->    geometry.xml
->    tallies.xml

The geometry.xml file defines 636,240 infinite cylinder cells representing
all of the 10 radial regions of each fuel cell.

The tallies.xml file defines a mesh covering the entire reactor zone,
with 500 regions along the z-axis, as well as specifying each of the
636,240 cells as separate tallies. This results in a grand total of
318,120,000 tally spaces.

Considering approximately 33 fuel nuclides, each with 6 reaction types, and
the size of a tally object being 32 bytes, the total tally data can be
calculated as:

	Tally Data = 318,120,000 tallies x 32 bytes/tally x 33 nucs x 6 XS's
	           = 1.83 TB

==============================================================================
Quick Start Guide
==============================================================================

Download----------------------------------------------------------------------

	Download of the TB_tallyserver source files are available from our
	github repository (https://github.com/jtramm/TB_tallyerver).

	The repository can be downloaded with the following command:
	
	>$ git clone git://github.com/jtramm/TB_tallyerver.git	

	To begin use of the code, you will have to navigate to
	the src directory:

	>$ cd TB_tallyserver

Compilation-------------------------------------------------------------------

	To compile TB_tallyserver with default settings, use the following
	command:

	>$ make

Running XSBench---------------------------------------------------------------

	To run TB_tallyserver with default settings, use the following command:

	>$ ./tb

==============================================================================
Theoretical Basis
==============================================================================

This basis for this reactor model, including specifications for the
geometry, material selection, and nuclide distribution, is specified in
the Hoogenboom-Martin reactor model, as described in the paper below:

J.E. Hoogenboom, W.R. Martin, B. Petrovic, “The Monte Carlo performance
benchmark test aims, specifications and first results,” International
Conference on Mathematics and Computational Methods Applied to Nuclear
Science and Engineering, Rio de Janeiro, Brazil (2011).
