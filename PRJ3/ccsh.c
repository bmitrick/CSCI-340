#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>

//GLOBAL DATA
char *exitCode = "exit";
char *path;

void displayError(){
  char error_message[30] = "An error has occurred\n";
  write(STDERR_FILENO, error_message, strlen(error_message));
}

char * trimLine(char *inputLine){
  char *line = strdup(inputLine);

  //Transform all tabs and \n to be spaces
  int sizeOfLine = strlen(line);

  for(int i = 0; i < sizeOfLine; i++){
    if (line[i]== '\t' || line[i] == '\n'){
      line[i] = ' ';
    }
  }

  //Trim all leading spaces
  int leadingSpaces = 0;

  while(line[leadingSpaces] == ' '){
    leadingSpaces++;
  }

  line = line + leadingSpaces;

  //Trim all trailing spaces
  int trailingSpaces = 0;
  while(line[sizeOfLine-trailingSpaces-1] == ' '){
    trailingSpaces++;
  }

  int lenOfStringWithoutTrailingSpaces = sizeOfLine - trailingSpaces;

  line[lenOfStringWithoutTrailingSpaces] = '\0';

  //printf("line = %s \n", line);

  return line;
}

void execute(char *line){
  char *lineDup = trimLine(line);

  //Create an array of arguments based on the input line
  char *string, *found;
  string = strdup(lineDup);

  int argNums = 0;
  while ((found = strsep(&string," ")) != NULL){
    if(strcmp(found, "") != 0){
      argNums++;
    }
  }

  string = strdup(lineDup);
  char *args[argNums + 1];
  int i = 0;
  while ((found = strsep(&string," ")) != NULL){
    if(strcmp(found, "") != 0){
      args[i] = found;
      i++;
    }
  }
  args[i] = NULL;


  char *pathString, *currPath;
  pathString = strdup(path);
  while ((currPath = strsep(&pathString," ")) != NULL){
    char *holderForCommand = args[0];

    char *attemptPath = strdup(currPath);
    char *temp = attemptPath;
    strcat(temp, "/");
    strcat(temp, args[0]);
    args[0] = temp;

    if(access(args[0], X_OK) == 0){
      execv(args[0], args);

      exit(0);
    }

    args[0] = holderForCommand;
  }

  displayError();
  exit(0);
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


  char *lineDup = strdup(line);
  char *command = strsep(&lineDup," ");

  if(strcmp(command, "path") == 0){
    path = line+5;
    interactiveMode();
  }

  else if (strcmp(command, "cd") == 0){
    char *directory = strsep(&lineDup," ");
    char *next = strsep(&lineDup," ");

    if(next != NULL || directory == NULL){
      displayError();
    } else {
      if (chdir(directory) != 0){
        displayError();
      }
    }

    interactiveMode();
  }

  else {
    char *hasAnd = strstr(line, "&");

    if (hasAnd){
      lineDup = strdup(line);
      int numCommands = 0;
      while (strsep(&lineDup, "&") != NULL){
        numCommands++;
      }

      lineDup = strdup(line);
      char *commands[numCommands];
      for(int i = 0; i < numCommands; i++){
        commands[i] = strsep(&lineDup, "&");
      }

      //Run each command in parallel
      int pids[numCommands];
      for(int i = 0; i < numCommands; i++){
        pid_t pid = fork();
        pids[i] = pid;

        if (pid < 0){
          printf("error in fork");
          exit(0);
        }
        else if (pid == 0) {
          execute(commands[i]);
        }
      }

      for(int i = 0; i < numCommands; i++){
        waitpid(pids[i], 0, 0);
      }

      interactiveMode();

    }
    else {
      pid_t pid = fork();

      if (pid < 0){
        printf("error in fork");
        exit(0);
      }
      else if (pid == 0) {
        execute(line);
      }
      else{
        waitpid(pid, 0, 0);
        interactiveMode();
      }
    }
  }
}

void batchMode(char *fileName){
  //printf("You have entered batch mode");

  //Open file
  FILE *file = fopen(fileName, "r");

  //Double check file was actually opened
  assert(file);

  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  //executes the file line by line
  while ((read = getline(&line, &len, file)) != -1){
    //Trim the \n from the line
    line[strcspn(line, "\n")] = 0;

    //If the command entered is the exit code, exit the program
    if(strcmp(line, exitCode) == 0){
      exit(0);
    }

    char *lineDup = strdup(line);
    char *command = strsep(&lineDup," ");

    if(strcmp(command, "path") == 0){
      path = line+5;
    }

    else if (strcmp(command, "cd") == 0){
      char *directory = strsep(&lineDup," ");
      char *next = strsep(&lineDup," ");

      if(next != NULL || directory == NULL){
        displayError();
      } else {
        if (chdir(directory) != 0){
          displayError();
        }
      }
    }

    else {
      char *hasAnd = strstr(line, "&");

      if (hasAnd){
        char *lineDup = strdup(line);
        int numCommands = 0;
        while (strsep(&lineDup, "&") != NULL){
          numCommands++;
        }

        lineDup = strdup(line);
        char *commands[numCommands];
        for(int i = 0; i < numCommands; i++){
          commands[i] = strsep(&lineDup, "&");
        }

        //Run each command in parallel
        int pids[numCommands];
        for(int i = 0; i < numCommands; i++){
          pid_t pid = fork();
          pids[i] = pid;

          if (pid < 0){
            printf("error in fork");
            exit(0);
          }
          else if (pid == 0) {
            execute(commands[i]);
          }
        }

        for(int i = 0; i < numCommands; i++){
          waitpid(pids[i], 0, 0);
        }
      }
      else {
        pid_t pid = fork();

        if (pid < 0){
          printf("error in fork");
          exit(0);
        }
        else if (pid == 0) {
          execute(line);
        }
        else{
          waitpid(pid, 0, 0);
        }
      }
    }
  }

  fclose(file);

  exit(0);
}

int main(int argc, char *argv[]){
  path = "/bin";

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
