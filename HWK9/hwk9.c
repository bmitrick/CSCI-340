#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
/*
a) Read the header
b) Allocate space for the offset array and read the offset array
c) Loop through the offset array, for each entry:
    a. lseek() to the appropriate point in the file
    b. Read the line length field
    c. Read the bytes of the line

EXTRA POINTS:
Another approach is to memory map the file (as Linux does with shared libraries). Instead of reading the file, use
the mmap() function to map the file into memory and process.


Other extra points mentioned in class:
Find out the rationalle behind TATA
*/

/*
What I found about TATA:

I think it has to do with the TATA box in genetics which essentially acts as a marker
for where genetic code start being interpreted. This is similar to the binary
as the TATA marks where we should start interpreting the data
*/

int main(int argc, char *argv[]){
  char *fileName = argv[1];

  //printf("File input = %s \n", fileName);

  //Open file
  int file = open(fileName, O_RDONLY);
  assert(file != -1);

  int pointerPosition = 0;
  /*
  Section 1 - File Header

  The header appears at the beginning of the file. The first 4 bytes of the header contain a file signature
  “TATA”. Immediately following the signature is an integer (4 bytes) giving the number of entries in the
  offset array (the next section)
  */
  //Skip TATA
  pointerPosition += 4;
  int filePointer = lseek(file, pointerPosition, SEEK_SET);


  //Get next 4 bytes and set offset equal to it
  char offsetStr[4];
  read(file, offsetStr, 4);
  pointerPosition += 4;
  int offsetLen = (int) *offsetStr;

  //printf("Offset Array length = %d \n", offsetLen);

  /*
  Section 2 – Offset Array

  Immediately following the header is an array of offsets. Each offset is an integer (4 bytes) that gives the
  offset from the start of the file to the start of each line (the next section).
  */
  int *offsetArray = malloc(offsetLen * sizeof(int));

  for(int i = 0; i < offsetLen; i++){
    filePointer = lseek(file, pointerPosition, SEEK_SET);

    char offset[4];
    read(file, offset, 4);
    pointerPosition += 4;
    int offsetValue = (int) *offset;

    offsetArray[i] = offsetValue;
    //printf("Value %d added at position %d \n", offsetValue, i);
  }

  /*
  Section 3 – Lines of data

  The data in the file is a series of text lines, each preceded by an integer that indicates the length of the
  line (including the size of the integer). Following the length are the bytes of the file line. The lines are not
  terminated by null bytes.
  */

  for(int i = 0; i < offsetLen; i++){
    //Move pointer to start of line
    filePointer = lseek(file, offsetArray[i], SEEK_SET);

    //See how many bytes are in this line
    char lineSize[4];
    read(file, lineSize, 4);
    int lineSizeValue = (int)*lineSize;

    //Move pointer past the size value
    filePointer+=4;

    //Pull the actual line data
    char line[lineSizeValue - 4];
    read(file, line, lineSizeValue - 4);

    //Print the line
    printf("%s \n", line);
  }

  close(file);



  return 0;
}
