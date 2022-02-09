#include <stdio.h>
#include <dirent.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct process{
	int pid;					//the process id
	int ppid;					//the parent process id
	int vsize;				//the size of the virtual address space
	char comm[255];		//the name of the executable
};

/*
* Builds a new process based on a passed in PID
*/
struct process *processBuilder(char *pid){
	//printf("checkpoint 1 for PID %s\n", pid);

	char path[10000];
	strcat(path, "/proc/");
	strcat(path, pid);
	strcat(path, "/stat");

	//printf("checkpoint 2 for PID %s\n", pid);

	//open file
	FILE *stat = fopen(path, "r");

	//printf("checkpoint 3 for PID %s\n", pid);

	//verify file is open
	if (stat == NULL){
		printf("ERROR IN OPENING FILE WITH PATH %s\n", path);
	}

	//Will only reach this point if the file is for sure open
	//printf("checkpoint 4 for PID %s\n", pid);

	//allocate space for a new process
	struct process *proc = malloc(sizeof(struct process));

	//pulls all needed data from the stat file
	fscanf(stat, "%d", &(proc->pid));	//Sets the PID of the new process to the PID from the stat file

	char temp[255];
	fscanf(stat, "%s", temp);//Sets the comm of the new process to the comm from the stat file
	strcat(proc->comm, temp);

	char skip[255];
	fscanf(stat, "%s", skip); 					//Skips unneeded info

	fscanf(stat, "%d", &(proc->ppid));//Sets the PPID of the new process to the PPID from the stat file

	for(int i =0; i<18; i++){
		fscanf(stat, "%s", skip);//Skips a lot of unneeded info
	}

	fscanf(stat, "%d", &(proc->vsize));//Sets the vsize of the new process to the vsize from the stat file

	//printf("(%d) %s, %d\n", (proc->pid),proc->comm, (proc->vsize));
	//Close file
	fclose(stat);

	//printf("checkpoint 5 for PID %s\n", pid);

	memset(path, 0, 10000);

	return proc;
}

/**
* Prints the data regarding a passed in process
*/
void printProc(struct process *proc){
	printf("(%d) %s, %d\n", proc->pid, proc->comm, proc->vsize);
}

/**
 * Prints the children of a process and their children and so on until it hits the bottom of the nest
 */
void printChildren(struct process *parentProc, struct process* allProcs, int numProcs, int indent){
	for(int i = 0; i < numProcs; i++){
		struct process *proc = &allProcs[i];

		//Finds all the children processes
		if(proc->ppid == parentProc->pid){
			//Adds in indent
			for(int j = 0; j < indent; j++){
				printf("    ");
			}

			//Prints child process
			printProc(proc);

			//Failsafe to prevent infinite loops
			if (indent <= numProcs){
				//Find and print the children of the child found
				printChildren(proc, allProcs, numProcs, indent + 1);
			}

		}
	}
}


int main(void){

	//Step 1: find how many processes there are
	int numProc = 0;

	struct dirent *directoryEntry;	//pointer for directory entry

	DIR *directory = opendir("/proc");

	//Verify that the directory was opened
	assert(directory != NULL);

	while ((directoryEntry = readdir(directory)) != NULL){

		//Gets name of directory as a char array
		char* dirName = directoryEntry->d_name;

		//Checks if the directory name is a number (checking if it is a process
		char fLetter = dirName[0];
		if(isdigit(fLetter)){
			numProc++;
		}
	}

	closedir(directory);

	//printf("%d\n", numProc);


	//Step 2: make an array of all the processes
	//Make the array
	struct process* allProcs = malloc(numProc * sizeof(struct process));


	//Step 3: populate array with processes
	int processIndex = 0;

	directory = opendir("/proc");

	//Verify that the directory was opened
	assert(directory != NULL);

	while ((directoryEntry = readdir(directory)) != NULL){

		//Gets name of directory as a char array
		char* dirName = directoryEntry->d_name;

		//Checks if the directory name is a number (checking if it is a process
		char fLetter = dirName[0];
		if(isdigit(fLetter)){
				allProcs[processIndex] = *processBuilder(dirName);
				//printProc(processBuilder(dirName));
				processIndex++;
		}
	}

	//Step 4: print data in tree format
	for(int i = 0; i < numProc; i++){
		struct process *proc = &allProcs[i];

		if (proc->ppid == 0){
			printProc(proc);
			printChildren(proc, allProcs, numProc, 1);
		}
	}


	return 0;
}
