#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main(int argc, char *argv[]) {
  FILE *input_file;
  FILE *output_file;
  int line_number = 0;   // the line number of the current line read from input_file
  char *next_field;  // ptr to the next field extracted from the current line
  char line[MAX_LINE_SIZE+1]; // ptr to the current input line

  // check and make sure we have the proper number of arguments
  if (argc != 3) {
    fprintf(stderr, "usage: %s input_file output_file\n", argv[0]);
    exit(1);
  }
  
  // open the input file and make sure that it is opened properly
  input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    perror(argv[1]);
    exit(1);
  }

  // open the output file and make sure that it is opened properly
  output_file = fopen(argv[2], "w");
  if (output_file == NULL) {
    perror(argv[2]);
    exit(1);
  }

  // read the file one line at a time. iterate through each line using strtok
  // and print each field, prefixed with the current line number
  while (1) {
    fgets(line, MAX_LINE_SIZE, input_file); // read the line from input_file

    // if we've reached the end of the input_file, break out of the loop
    if (feof(input_file))  
      break;

    // increment the line number because we are starting a new line
    line_number++;

    // initialize next_field to point to the first field on the line
    next_field = strtok(line, " \n");
    
    // iterate through the fields on the line until we have exhausted them. strtok
    // will return NULL when there are no more fields to be read
    while (next_field != NULL) {
      // write the current field to the output file
      fprintf(output_file, "%d: %s\n", line_number, next_field);

      // get the next word on the line--remember to pass NULL as the first argument
      // because only the first call to strtok on each line should receive a pointer
      // to line
      next_field = strtok(NULL, " \n");
    }
  }
  // remember to close all files when we are done
  fclose(input_file);
  fclose(output_file);
}