#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//GLOBAL DATA
char *exitCode = "exit";

void displayError(){
  char error_message[30] = "An error has occurred\n";
  write(STDERR_FILENO, error_message, strlen(error_message));
}

void execute(char *line){
  //printf("user input %s \n", line);

  char* str;
  str = (char*)malloc(strlen(line));
  strcpy(str, line);

  //printf("user str %s \n", str);

  char delim[] = " ";

  char *ptr = strtok(str, delim);

  int argNums = 0;
  while (ptr != NULL){
    argNums++;
    //printf("input = %s \n", ptr);
    ptr = strtok(NULL, delim);
  }

  strcpy(str, line);
  //printf("%s \n", str);
  ptr = strtok(str, delim);
  char *args[argNums + 1];
  int i = 0;
  while (ptr != NULL){
    //printf("input %d = %s \n", i, ptr);
    args[i] = ptr;
    i++;
    ptr = strtok(NULL, delim);
  }
  args[i] = NULL;

  execv(args[0], args);
}

void interactiveMode(){
  printf("ccsh> ");

  char *line = NULL;
  size_t len = 0;

  getline(&line, &len, stdin);

  //Trim the \n from the line
  line[strcspn(line, "\n")] = 0;

  //If the command entered is the exit code, exit the program
  if(strcmp(line, exitCode) == 0){
    exit(0);
  }

  pid_t pid = fork();

  if (pid < 0){
    printf("error in fork");
    exit(0);
  }
  else if (pid == 0) {
    execute(line);
  }
  else{
    wait(NULL);
    interactiveMode();
  }
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
    interactiveMode();
  } else {
    //If the user does input a file name, the shell enters batch mode & passes the file name to the batch mode terminal
    char *batchFile = argv[1];

    batchMode(batchFile);
  }

  return 0;
}
