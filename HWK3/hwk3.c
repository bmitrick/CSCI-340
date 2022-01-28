#include <stdio.h>

int main(int argc, char *argv[]){
	//Accept a command (with parameters) as a paremeter
	//Fork creating a new process
	//Execute the command passed as the parameter printing the results
	//
	//EX: ./hwk3 ls -1
	//
	//Your program would fork, then execute the ‘ls -l’ command and
	//display its output (a listing of the current directory).
	

	//Pull command from argv
	char *command[argc-1];

	for(int i = 1; i < argc; i++){
		command[i-1] = argv[i];
	}
	
	/*
	 * Check that command array contains all the command elements and
	 * only the command elements
	for(int i =0; i < argc-1; i++){
		printf("Element %d in command is: %s\n", i, command[i]);
	} 
	*/

	return 0;
}
