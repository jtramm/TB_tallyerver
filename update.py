#!/usr/bin/python
import subprocess
import shutil

# Absolte path of the geometry_t.f90 and tallies_t.f90 files
geometry_path = '/home/jtramm/openmc/tallyserver/openmc/src/templates/geometry_t.f90'
tally_path    = '/home/jtramm/openmc/tallyserver/openmc/src/templates/tallies_t.f90'
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
f = open("geometry_t.f90", "r")
contents = f.readlines()
f.close()

line = "#define NCELLS "+cells+"\n"
contents.insert(0, line)
line = "#define NSUFRACES "+surfaces+"\n"
contents.insert(0, line)

f = open(geometry_path, "w")
contents = "".join(contents)
f.write(contents)
f.close()

# Update tally File

f = open("tallies_t.f90", "r")
contents = f.readlines()
f.close()

line = "#define NTALLIES "+tallies+"\n"
contents.insert(0, line)

f = open(tally_path, "w")
contents = "".join(contents)
f.write(contents)
f.close()

print "Updated xml reader files written to openmc/src/templates directory successfully"

# Move xml files into settings directory
source = 'geometry.xml'
destination = settings_path+"/"+source
shutil.copy2(source, destination)
source = 'tallies.xml'
destination = settings_path+"/"+source
shutil.copy2(source, destination)

print "Input files moved to settings folder"
