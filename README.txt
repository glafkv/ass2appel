Assignment 2
By: Gabi Appel
Due: 9/19/19

Purpose: 
	The purpose of this program is to become familiar with using shared memory and creating multiple processes. Also to become familiar with getopt, perror, and fork().

How to Run:
	
	make				//to compile
	./logParse -h			//to show the help menu
	./logParse -i <inputfile>	//To specify the input file that we're getting. The default is "input.dat"
	./logParse -o <outputfile>	//To specify the output file that we're sending it to. The default is "output.dat"
	./logParse -t <n>		//To specify the maximum duration the code should run. The default is 10 seconds.	
	make clean			//To erase all the object and executable files.

Problems:
	I was able to get the subset sum functions working with a built in array, but when I tried to put it in the child and grab numbers from the file, it would stall. So all this really does is print out the PIDs for everything. I couldn't figure out how to finish this. Oh and I didn't get to the timer part. 
