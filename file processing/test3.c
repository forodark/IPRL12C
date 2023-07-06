#include <stdio.h>

void main(void)

{

        FILE *outputf;
        char outputfilename[40];
        char ch;
        int i;
        float f;
        double d;

        // initialize variables
        ch = 'A';
        i = 100;
        f = 88.3;
        d = 3.1416;

 

        // ask for filename, open text file for output

        printf("Input name of output text file: ");

        scanf("%s", outputfilename);

        

        outputf = fopen(outputfilename, "w");

 

  // output formatted data onto text file

	fprintf(outputf, "ch = %c\n", ch);
	fprintf(outputf, "i = %d\n", i);
	fprintf(outputf, "f = %f\n", f);
	fprintf(outputf, "d = %lf\n", d);
	fprintf(outputf, "Goodbye!\n"); 

	printf("Program run successfully. Please check %s", outputfilename);
	fclose(outputf);
}
