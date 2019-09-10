logParse:	logParse.o
		gcc -o logParse logParse.o

logParse.o:	logParse.c
		gcc -g -c dt.c

.PHONY: 	clean
clean:
		/bin/rm -f *.o *~ apppel.2
