#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <limits.h>
//#include "vector.h"
//subset function
//Function one attempt
/*bool isSubsetSum(int set[], int n, int sum){
	
	if(sum == 0)		
		return true;
	
	if(n == 0 && sum != 0)
		return false;
	
	if(set[n-1] > sum)
		return isSubsetSum(set, n-1, sum);
	
	return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}*/
//This works, but it won't work with the child forking nonsense.
void displaySub(int subSet[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ",subSet[i]);
	}
	printf("\n");
}
void subSum(int set[], int subSet[],int n, int subSize, int total, int nodeCount, int sum){
	int j;
	if(total == sum){
		displaySub(subSet, subSize);
		subSum(set, subSet, n, subSize-1, total-set[nodeCount], nodeCount+1, sum);
		return;
	}else{
		for(j = nodeCount; j < n; j++){
			subSet[subSize] = set[j];
			subSum(set, subSet,n,subSize+1,total+set[j],j+1,sum);

		}
	}
}
void find(int set[], int size, int sum){
	int subSet[size];
	//int subSet[size];  //= new int[size];
	subSum(set, subSet, size, 0,0,0, sum);
	//memset(set,0,sizeof(set));
	//delete[] subSet;
}
//Need to figure out how to implement a vector in c
//figure out how to measure the length of a vector
/*void printArr(int arr[], int n, int *v, int sum){
	if(sum == 0){
		int i;
		for(i = 0; i < 9; i++)
			printf("%d ", v[i]);
		printf("\n");
	}
	if(n == 0)
		return;
	
	printArr(arr, n-1, v, sum);
	printArr(arr, n-1, v, sum - arr[n-1]);
}
void vect(int arr[], int n, int sum){
	int *v = (int *)malloc(n * sizeof(int));
	printArr(arr, n, v, sum);
	
	free(v);

}*/
//Doesn't work
/*void subset(int arr[], int l, int r, int sum){
	if(l > r){
		printf("%d ", sum);
		return;
	}
	subset(arr, l+1, r, sum+arr[l]);
	subset(arr, l+1, r, sum);
}*/

int main(int argc, char **argv)
{
	//File and getopt variables
	int option;
	char *inFile, *outFile;
	//Defaulst values if not given
	inFile = "input.dat";
	outFile = "output.dat";
	

	//The functions work while not in the child program. I don't know what else to do.

	/*int arr[] = {8,1,4,5};
  	int sum = 9;
  	
	int size = sizeof(arr) / sizeof(arr[0]);
  	find(arr, size, sum);*/
	//isSubsetSum(arr, o, sum);
	//if(isSubsetSum(arr,o,sum) == true)
  	//	printf("Found a subset with given sum");
  	//else
  	//	printf("No subset with given sum");
	//printf("\n");
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
	char *cToken;
	char *pToken;
	int num, cNum, strNum;
	//loop counters
	int i, j;
	//Flag for child
	int counter;
	int set[100];
	//int k = 0;
	int n;
	
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
	//int x = sizeof(set) / sizeof(set[0]);
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
	
			//suspends execution of current process until a child specified by pid argument has changed state
			waitpid(pid, &status, 0);
		
			//for printing all child pids
			sprintf(pidString, "%d ", pid);
			strcat(endString, pidString);
		}
		else {	//child
			fprintf(ofPtr, "%d ", getpid());
			fprintf(ofPtr, "\n");
			//counter = 0;
			
			//parsing the first number of the line
			//cNum is the sum we're trying to get
			cToken = strtok(str, s);	
			cNum = atoi(cToken);
			printf("%d \n", cNum);
			
			//THIS IS HUGE
			//TAKES IN THE REMAINDER OF THE STRING AND PUTS INTO AN ARRAY THEN PRINTS ARRAY
			printf("Array: ");
			//cToken = strtok(str, s);
			//int size = sizeof(set) / sizeof(set[0]);
						
			while(cToken = strtok(NULL, s)){
				set[n] = atoi(cToken);
				printf("%d ", set[n]);
				
			}
			/*HERE IS MY FUNCTION CALL THAT IS SUPPOSED TO WORK, BUT IS STALLING THE WHOLE PROGRAM*/
			//find(set, size, cNum);
			
			/*cToken = strtok(str, s);
			while(counter < strlen(str)){
				set[n] = atoi(cToken);
				printf("%d ", set[n]);
				counter++;
				cToken = strtok(NULL, s);
			}*/
			//counter = 0;
			/*char* tmp;
			if((tmp = (char*) malloc(sizeof(int) * strlen(str) + 1)) == NULL){
				return -1;
			}
			strcpy(tmp,str);
			int counter = 0;
			char* p = strtok(tmp, s);
			while(p != NULL){
				set[counter++] = atoi(p);
				
				p = strtok(NULL, s);
				//printf("%d ", p);
		}	
			while(counter < strlen(str)){
				printf("%d ", set[counter]);
				counter++;
			}*/
			//printf("%d ", set[counter]);
			//for(i = 0; i < strlen(str); i++){

			//	printf("%d ", set[i]);
				//set[i]++;
		//	}
			//int size = sizeof(set) / sizeof(set[0]);
			//find(set, size, cNum);
		
			printf("\n");
			
			
			exit(0);

			
			
			
		}
		
		
	}

	fprintf(ofPtr, "\n");
	fprintf(ofPtr, "All the children were: %s\n", endString);
	fprintf(ofPtr, "Parent PID: %d\n", getpid());
	
	//Don't forget to close your files!
	fclose(ofPtr);
	fclose(ifPtr);
	exit(EXIT_SUCCESS);
return 0;
}
			


	
