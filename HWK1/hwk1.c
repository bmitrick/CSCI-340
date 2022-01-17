#include <stdio.h>

int main(int argc, char *argv[]){
	printf("Addresses of the given inputs are as follows...");

	for(int i = 1; i < argc; i ++){
		printf("\n<%p>", &argv[i]);
	}
	
	printf("\n");

	return 0;
}
