#include <stdio.h>
#include <dirent.h>
#include <assert.h>
#include <ctype.h>

struct process{
	int pid;		//the process id
	int ppid;		//the parent process id
	int vsize;		//the size of the virtual address space
	char comm[100];		//the name of the executable
};

int main(void){
	
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
			printf("%s\n", directoryEntry->d_name);
		
		}	
	}

	closedir(directory);

	return 0;
}
