
THIS DOESNT WORK

CC	= gcc
CFLAGS	= -g
TARGET	= logParse
OBJS	= logParse.o
LIB	= logParse.c
$(TARGET):	$(OBJS)
		$(CC) -o $@ $(TARGET) $(OBJS)

$(OBJS):	$(LIB)
		$(CC) -g -c $(LIB)

.c.o:	
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	/bin/rm -f *.o *~ $(LIB) $(TARGET)



