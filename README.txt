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
100 axial cuts for each fuel rod.

TB_tallyserver is an input deck creator for OpenMC, capabel of creating the
input files necessary to define the Hoogenboom-Martin TB model.

When run, the following files are created in the current working
directory. Note that the files are fairly large (~338MB total).

->    geometry.xml
->    tallies.xml

The geometry.xml file defines 636,240 infinite cylinder cells representing
all of the 10 radial regions of each fuel cell.

The tallies.xml file defines a mesh covering the entire reactor zone,
with 100 regions along the z-axis, as well as specifying each of the
636,240 cells as separate tallies. This results in a grand total of
63,624,000 tally spaces.

Considering approximately 33 fuel nuclides, each with 6 reaction types, and
the size of a tally object being 24 bytes, the total tally data can be
calculated as:

	Tally Data = 63,624,000 tallies x 24 bytes/tally x 33 nucs x 6 XS's
	           = 281.6 GB
	           = 0.27  TB

Note that there is also a "Large" version of the TB tallyserver corresponding
to the Hoogenboom-Martin "Large" reactor model. This increases the number
of nuclides from 33 to 320. See details below for running the larger model.

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

Configuration-----------------------------------------------------------------

	When you compile and run the tb.c code, it will automatically call a
	script to update the relevant xml reader files. This script is the
	"update.py" script. You will need to edit this script to set the
	absolute path to the openmc template subdirectory, as well as your
	settings directory path. 

	# Absolte path of templates directory
	templates_path = '/home/jtramm/openmc/src/templates'

Compilation-------------------------------------------------------------------

	To compile TB_tallyserver with default settings, use the following
	command:

	>$ make

Running TB_tallyserver--------------------------------------------------------

	To run TB_tallyserver with default settings, use the following command:

	>$ ./tb

	This program is also capabale of generating smaller models, representing
	a smaller portion of the total number of fuel assemblies in the reactor.
	This feature may be useful for testing purposes. Pass in as a command
	line argument the desired number of fuel assemblies to print. i.e.,:

	>$ ./tb 1

	Note that the program will enforce the number of assemblies to be
	between 1 and 241. I.e., 1 <= n_assemblies <= 241

Running TB_tallyserver Large--------------------------------------------------

	There is also a "large" version of this code that tracks more nuclides.
	This model is more anagolous to the "H-M Large" model. The nuclide count
	is increased from 33 to 320. Due to limitations in the OpenMC XML reader
	read-in procedures, nuclides are split up between multiple tally
	declarations, greatly increasing the size of the tallies.xml file (as
	well as the read-in time for an OpenMC run).

	Memory usage can be calculated under the "Large" model as follows:
	
	Tally Data = 63,624,000 tallies x 24 bytes/tally x 320 nucs x 6 XS's
	           = 2,730 GB
	           = 2.67  TB
	
	To run the Large model, you will also need to update the materials.xml
	file in your benchmark settings directory to accomodate the higher
	number of nuclides. This can be done by compying the included
	"materials_large.xml" file included with the program into the settings
	directory, replacing the standard "materials.xml" file (note - you
	should back up the original materials.xml file). 
	
	To generate the Large models filse, launch TB Tallyserver with the
	following command:

	>$ ./tb 241 Large

==============================================================================
Updating OpenMC
==============================================================================

The update.py script (launched automatically when running tb.c), will
update several of the xml reader template files (without doing this, OpenMC
would take weeks to read in the full geometry/tally files).

Once you've run tb.c successfully, simply compile OpenMC.

Note: If you do a "dist clean" in the OpenMC src directory, you will have
to re-run tb.c to replace the updated files.

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
