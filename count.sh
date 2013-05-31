#!/bin/sh

# A quick script to count up the number of cells/surfaces in the input deck.
# Useful for debugging purposes.

echo cells =
grep '<cell.*id' geometry.xml | wc -l
echo surfaces = 
grep '<surface.*id' geometry.xml | wc -l
echo tallies = 
grep '<tally.*id' tallies.xml | wc -l
