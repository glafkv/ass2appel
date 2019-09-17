CC	= gcc
CFLAGS	= -g
TARGET	= logParse
OBJS	= logParse.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

logParse.o: logParse.c
	$(CC) $(CFLAGS) -c logParse.c

.PHONY: clean
clean:
	/bin/rm -f *.o $(TARGET)



