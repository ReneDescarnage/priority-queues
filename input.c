#include <stdio.h>
#include <stdlib.h>

#define N_SAMPLES 10000
#define CHAR_TO_READ 255

// /* function declaration */
// void read_data(char* filepath, double* data_array);
// void save_data(char* filepath, double* data_array);

// int main(void) {
//   // Allocate memory for storing data (we want to allocate on stack or heap?)
//   // double **distribution = (double **)malloc(sizeof(double*)*N_SAMPLES);
//   // if (words==NULL)
//   //     {
//   //     fprintf(stderr,"Out of memory (1).\n");
//   //     exit(1);
//   //     }

//   // Allocate some space for putting our data etc...
//   double samples[N_SAMPLES];
//   char* filepath = "samples/triangular.txt" ;

//   //Read in the data from file
//   read_data(filepath, samples);

//   // Test to print out some values...
//   int j;
//   for(j = 0; j < 30; j++)
//       printf("%f\n", samples[j]);

// } // END OF MAIN

void read_data(char* filepath, double* data_array) {
  char buff[CHAR_TO_READ];
  char *end;
  double num;
  FILE *fp;


  fp = fopen(filepath, "r");
  if (fp == NULL)
      {
      fprintf(stderr,"Error opening file.\n");
      exit(2);
      }

  // Read all data into our data structure on stack
  int i;
  for (i=0;1;i++) {
    // Reads a line from the file byte by byte...Max CHAR_TO_READ bytes in a single line
    // Regard it as a null terminated string
    //If null, then we have reached the EOF. So lets break.
    if (fgets(buff, CHAR_TO_READ, fp) == NULL)
      break;
    // Else lets convert into double and store into data array
    num = strtod(buff, &end);
    data_array[i] = num;

    // Expect character after number to be the newline character...Otherwise error.
    if (*end != '\n'){
      fprintf(stderr,"Error converting string to double.\n");
      printf("Char after num is: %s\n", end);
      exit(2);
    }
  }

  fclose(fp);
}

// Function to save data to a file
void save_data(char* name, double* data_array){
  // TO DO
  return;
}
