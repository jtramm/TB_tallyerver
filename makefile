all:
	gcc -std=c99 -Wall -o tb tb.c
clean:
	rm -f tb test.xml
edit:
	vim tb.c
