#include <stdio.h>

 

void main(void)

{

        FILE *inputf;
        char inputfilename[40];
        char ch;
        int i;
        float f;
        double d;
        char mystr[40];

 

 

        // ask for filename, open text file for input
        printf("Input name of put text file: ");
        scanf("%s", inputfilename);

        inputf = fopen(inputfilename, "w");

  // input formatted data from text file
	
	fscanf(inputf, "%c", &ch);
	fscanf(inputf, "%d", &i);
	fscanf(inputf, "%f", &f);
	fscanf(inputf, "%lf", &d);
	fscanf(inputf, "%s", mystr); 

 

  // output data – use fprintf()

  // note that the output can also be done using printf()

 fprintf(stdout, "ch = %c\n", ch);

 fprintf(stdout, "i = %d\n", i);

 fprintf(stdout, "f = %f\n", f);

 fprintf(stdout, "d = %lf\n", d);

 fprintf(stdout, "mystr = %s\n", mystr);

 

 

 fclose(inputf);

}
