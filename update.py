#!/usr/bin/python
import subprocess
import shutil
import os

# Absolte path of the geometry_t.f90 and tallies_t.f90 files
templates_path = '../templates'

# Sets the size of the H-M Benchmark
HMSize = 'small'

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

line = "   allocate(cell_("+cells+"))\n"
contents.insert(665, line)
line = "   allocate(surface_("+surfaces+"))\n"
contents.insert(667, line)

f = open(templates_path+"/geometry_t.f90", "w")
contents = "".join(contents)
f.write(contents)
f.close()


# Update tally File

f = open("tallies_t.f90", "r")
contents = f.readlines()
f.close()

line = "   allocate(tally_("+tallies+"))\n"
contents.insert(650, line)

f = open(templates_path+"/tallies_t.f90", "w")
contents = "".join(contents)
f.write(contents)
f.close()

# Delete old .f90 extensions (.F90 is required for preprocessor to work)

#if os.path.exists(templates_path+"/geometry_t.f90") :
#	os.remove(templates_path+"/geometry_t.f90")

#if os.path.exists(templates_path+"/tallies_t.f90") :
#	os.remove(templates_path+"/tallies_t.f90")

print "Updated xml reader files written to openmc/src/templates directory successfully"

# Figures out which materials file to use

if HMSize == 'small' :
	shutil.copy2('materials_small.xml', 'materials.xml')
else :
	shutil.copy2('materials_large.xml', 'materials.xml')

