#include <stdio.h>   // For snprintf
#include <stdlib.h>  // For system
#include <unistd.h>  // For getcwd, chdir, and access
#include "glencrypt.h"

void compileRunProgram(const char* path, const char* program) { //compile then run, SLOW AF
    getcwd(original_dir, sizeof(original_dir));
    chdir(path);

    char compile_command[256];
    snprintf(compile_command, sizeof(compile_command), "gcc %s.c -o %s.exe", program, program);
    printLine(0);
    printf("Compiling... Please Wait.\n");
    printLine(0);
    system(compile_command);

    char run_command[256];
    snprintf(run_command, sizeof(run_command), "%s.exe", program);
    system(run_command);

    system("cls");
    chdir(original_dir);
}

int main() {
    compileRunProgram("LRT/", "Bautista_LRT");
    return 0;
}