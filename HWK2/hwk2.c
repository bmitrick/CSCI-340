#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	//pull first arg given to be used as size of mem block
	char *input = argv[1];
	int size = atoi(input);

	//Allocate block of memory based on given size
	int *pointerToMem = malloc(size* sizeof(int));

	//Set block to all zeros
	memset(pointerToMem, 0, size);

	//Print address of memory block
	printf("address of memory block: <%p>", pointerToMem);

	//Print contents of memory block in hex
	for(int *i = pointerToMem; i < pointerToMem + size; i++){
		printf("\nvalue at address %p: %x", i, *i);
	}

	printf("\n");

	//Free mem block

	free(pointerToMem);

	return 0;
};

struct listItem {
        int pid;                        //Process ID

        //Process Context
        int *instructionPointer;        //Instruction pointer
        int *stackPointer;              //Stack pointer
        int reg1;                       //Register1
        int reg2;                       //Register2
        int AX;                         //AX
        int BX;                         //BX

        //Process Status
        //Whichever of the following variables has a nonzero value is the state the process is currently in
        int initializing;
        int running;
        int suspended;
        int ready;
        int terminated;
};
