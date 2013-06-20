#!/usr/bin/python
import subprocess
import shutil
import os

# Absolte path of the geometry_t.f90 and tallies_t.f90 files
templates_path = '/home/jtramm/openmc/tallyserver/openmc/src/templates'
settings_path = '/home/jtramm/openmc/tallyserver/settings'

# Calculate Number of Cells in Reactor Model Input Files
cmd = "grep '<cell.*id' geometry.xml | wc -l"
num = subprocess.Popen(cmd,shell=True, stdout=subprocess.PIPE).communicate()[0]
lines = num.split('\n')
cells = lines[0]

# Calculate Number of Surfaces in Reactor Model Input Files
cmd = "grep '<surface.*id' geometry.xml | wc -l"
num = subprocess.Popen(cmd,shell=True, stdout=subprocess.PIPE).communicate()[0]
lines = num.split('\n')
surfaces = lines[0]

# Calculate Number of tallies in Reactor Model Input Files
cmd = "grep '<tally.*id' tallies.xml | wc -l"
num = subprocess.Popen(cmd,shell=True, stdout=subprocess.PIPE).communicate()[0]
lines = num.split('\n')
tallies = lines[0]

# Update geometry File
f = open("geometry_t.F90", "r")
contents = f.readlines()
f.close()

line = "#define NCELLS "+cells+"\n"
contents.insert(0, line)
line = "#define NSURFACES "+surfaces+"\n"
contents.insert(0, line)

f = open(templates_path+"/geometry_t.F90", "w")
contents = "".join(contents)
f.write(contents)
f.close()


# Update tally File

f = open("tallies_t.F90", "r")
contents = f.readlines()
f.close()

line = "#define NTALLIES "+tallies+"\n"
contents.insert(0, line)

f = open(templates_path+"/tallies_t.F90", "w")
contents = "".join(contents)
f.write(contents)
f.close()

# Delete old .f90 extensions (.F90 is required for preprocessor to work)

if os.path.exists(templates_path+"/geometry_t.f90") :
	os.remove(templates_path+"/geometry_t.f90")

if os.path.exists(templates_path+"/tallies_t.f90") :
	os.remove(templates_path+"/tallies_t.f90")


print "Updated xml reader files written to openmc/src/templates directory successfully"

# Move xml files into settings directory
source = 'geometry.xml'
destination = settings_path+"/"+source
shutil.copy2(source, destination)
source = 'tallies.xml'
destination = settings_path+"/"+source
shutil.copy2(source, destination)

print "Input files moved to settings folder"
