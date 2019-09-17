#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
//subset function
bool isSubsetSum(int set[], int n, int sum){
	
	if(sum == 0)
		return true;
	if(n == 0 && sum != 0)
		return false;
	
	if(set[n-1] > sum)
		return isSubsetSum(set, n-1, sum);
	
	return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}
int main(int argc, char **argv)
{
	//File and getopt variables
	int option;
	char *inFile, *outFile;
	//Defaulst values if not given
	inFile = "input.dat";
	outFile = "output.dat";
	
	/*int set[] = {3,24,4,12,5,2};
 * 	int sum = 9;
 * 	int n = sizeof(set) / sizeof(set[0]);
 * 	if(isSubsetSum(set,n,sum) == true)
 * 		printf("Found a subset with given sum\n");
 * 	else
 * 		printf("No subset with given sum");*/
	
	//getopt statement
	while((option = getopt(argc, argv, "hi:o:t:")) != -1)
	{
		switch(option){
			
			case 'h':
				printf("\tI'm here to help\n");
				printf("***********************\n");
				printf("-h brings up the help menu\n");
				printf("-i allows you to specify your own input file. Default is 'input.dat'\n");
				printf("-o allows you to specify your own output file. Default is 'output.dat'\n");
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
	//Code to open files
	FILE *ifPtr = fopen(inFile, "r");
	FILE *ofPtr = fopen(outFile, "w");
	
	//if input file doesn't exist, throw an error.
	if(ifPtr == NULL){
		perror("logParse.c: Error: ");	
		exit(EXIT_FAILURE);
	}
	//if output file doens't exist, throw an error
	if(ofPtr == NULL){
		perror("logParse.c: Error: ");
		exit(EXIT_FAILURE);
	}
	//variables to get the numbers from the files
	char str[60];
	const char s[2] = " ";
	char *token;
	char *sum;
	int num, cNum;
	//loop counters
	int i, j;
	//Flag for child
	int counter;
	int set[100];
	
	//gets the first line of the input file
	fgets(str, 60, ifPtr);
	
	token = strtok(str, s);
	//converts the first number to an int to be processed by for loop
	num = atoi(token);
	
	//PID string converting variables
	char pidString[10];
	char endString[100];
	
	//parent and child variables
	int pid, status, childPID, fNum;
	
	//Goes into loop based on the first number grabbed
	for(i = 0; i < num; i++){
		//Gets second line of input
		fgets(str, 60, ifPtr);
		pid = fork();
		//if fork fails
		if(pid < 0){
			perror("logParse.c: Error: ");
		}
		else if(pid != 0){	//parent
			fgets(str, 60, ifPtr);
			//suspends execution of current process until a child specified by pid argument has changed state
			waitpid(pid, &status, 0);
			//for printing all child pids
			sprintf(pidString, "%d ", pid);
			strcat(endString, pidString);
		}
		else {	//child
			//fprintf(ofPtr, "%d ", getpid());
			counter = 0;
			
			sum = strtok(str, s);
			cNum = atoi(sum);
			
			printf("%s\n", sum);
			fgets(str, 60, ifPtr);
			
			sum = strtok(str, s);
			//here is where we'll put the subset code
			printf("%s\n", sum);	

			/*Need to figure out how to take in a line, throw it into an array so we can use it for the subset function.*/
			while(counter < cNum){
				//fscanf(ifPtr, "%d ", &set);
				fNum = atoi(sum);
				//set[fNum];
				//printf("%s \n", sum);
				counter++;
				sum = strtok(NULL,s);
				printf("%s ", sum);
				//printf("%d\n", set[fNum]);
			}
			//printf("%d\n", set[fNum]);
			fprintf(ofPtr, "\n");
			exit(1);
		}
	}
	fprintf(ofPtr, "All the children were: %s\n", endString);
	fprintf(ofPtr, "Parent PID: %d\n", getpid());
	
	//Don't forget to close your files!
	fclose(ofPtr);
	fclose(ifPtr);
	exit(EXIT_SUCCESS);
return 0;
}
			


	
