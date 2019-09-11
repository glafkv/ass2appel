logParse:	logParse.o
		gcc -o logParse logParse.o

logParse.o:	logParse.c
		gcc -g -c logParse.c

.PHONY: 	clean
clean:
		/bin/rm -f *.o *~ apppel.2
