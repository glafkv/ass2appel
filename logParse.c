#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char **argv)
{

	//File and getopt variables
	int option; 
	char *inFile;
	char *outFile;
	
	//Default values if not given
	inFile = "input.dat";
	outFile = "output.dat";

	//getopt statement
	while((option = getopt(argc, argv, "hi:o:t:")) != -1)
	{
		switch(option){
		
			case 'h':
				printf("\tI'm here to help!\n");
				printf("**************************\n");
				printf("-h brings up the help menu\n");
				printf("-i allows you to add your own input file. Default is 'input.dat'\n");
				printf("-o allows you to add your own output file. Default is 'output.dat'\n");
				printf("-t allows you to specify the maximum duration the code should run. Default is 10 seconds\n");
				exit(0);
			case 'i':
				inFile = optarg;
				break;
			case 'o':
				outFile = optarg;
				break;
			//case 't':
				
			default:
				printf("Error\n");
				exit(EXIT_FAILURE);
		}
	}
	

	//Code to open the files
	FILE *ifPtr = fopen(inFile, "r");
	FILE *ofPtr = fopen(outFile, "a");

	//if the input file doesn't exist, throw an error.
	if(ifPtr == NULL){
		perror("logParse.c: Error: ");
		exit(EXIT_FAILURE);
	}
	
	//if the output file doesn't exist, throw an error.
	if(ofPtr == NULL){
		perror("logParse.c: Error: ");
		exit(EXIT_FAILURE);	
	}

	//Variables to get the numbers from the files.
	char str[60];
	const char s[2] = " ";
	char *token;
	char *cToken;
	int num, cNum;
	//loop counters
	int i, j;
	//Flag for child
	int counter;

	//Gets the first line of the input file
	fgets(str, 60, ifPtr);
	
	token = strtok(str, s);
	printf("%s\n", token);
	//Converts the first number to an int to be processed by the for loop
	num = atoi(token);
	
	//pid string coverting variables
	char pidString[10];
	char endString[100];
	
	//parent and child variables
	int pid, status, childPID, fNum;
	

	//Here we need to go into a loop that does everything else.
	//Will need to think about this more tomorrow.



	//Don't forget to close your files!
	fclose(ofPtr);
	fclose(ifPtr);
	exit(EXIT_SUCCESS);
return 0;
}	
