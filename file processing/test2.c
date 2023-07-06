#include <stdio.h>

 

void main(void)

{
        FILE *inputf;
        FILE *outputf;
        char inputfilename[40];
        char outputfilename[40];
        int c;

 printf("Input name of input text file:");
        scanf("%s", inputfilename);
        // open input file 
        if ( (inputf = fopen(inputfilename, "r")) == NULL)
        {

           printf("ERROR: %s cannot be opened.\n", inputfilename);

           exit(1);
        }
        printf("Input name of output text file: ");

        scanf("%s", outputfilename);


        // open output file

        outputf = fopen(outputfilename, "w");

 

        // read one character at a time from input file,

        // output character onto the output file

        while ( (c = fgetc(inputf)) != EOF ) 

           fputc(c, outputf);

 

 fclose(inputf);

 fclose(outputf);

}
