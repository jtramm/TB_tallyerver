all:
	gcc -std=c99 -Wall -o tb tb.c
clean:
	rm -f tb geometry.xml tallies.xml
edit:
	vim tb.c
