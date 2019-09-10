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
	while((option = getopt(argc, argv, "hi:o:")) != -1)
	{
		switch(option){
		
			case 'h':
				printf("\tI'm here to help!\n");
				printf("**************************\n");
				printf("-h brings up the help menu\n");
				printf("-i allows you to add your own input file. Default is 'input.dat'\n");
				printf("-o allows you to add your own output file. Default is 'output.dat'\n");
				exit(0);
			case 'i':
				inFile = optarg;
				break;
			case 'o':
				outFile = optarg;
				break;
			default:
				printf("Error\n");
				exit(EXIT_FAILURE);
		}
	}
	
