#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//GLOBAL DATA
char *exitCode = "exit\n";

void execute(char *line){
  printf("%s", line);
}

void interativeMode(){
  printf("ccsh> ");

  char *line = NULL;
  size_t len = 0;

  getline(&line, &len, stdin);

  //If the command entered is the exit code, exit the program
  if(strcmp(line, exitCode) == 0){
    exit(0);
  }

  //Execute line
  execute(line);

  //Call interative mode again to pull new line data
  interativeMode();
}

void batchMode(char *fileName){
  printf("You have entered batch mode");

  //Once everything is over, exit the program
  exit(0);
}

int main(int argc, char *argv[]){
  //See what mode the user has entered
  if(argc == 1){
    //If the user does not input a file name, the shell enters interative mode
    interativeMode();
  } else {
    //If the user does input a file name, the shell enters batch mode & passes the file name to the batch mode terminal
    char *batchFile = argv[1];

    batchMode(batchFile);
  }

  return 0;
}
