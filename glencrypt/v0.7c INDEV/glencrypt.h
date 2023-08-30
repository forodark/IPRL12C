//==================================================================================================================
// ░██████╗░██╗░░░░░███████╗███╗░░██╗░█████╗░██████╗░██╗░░░██╗██████╗░████████╗░░░██╗░░██╗ 
// ██╔════╝░██║░░░░░██╔════╝████╗░██║██╔══██╗██╔══██╗╚██╗░██╔╝██╔══██╗╚══██╔══╝░░░██║░░██║
// ██║░░██╗░██║░░░░░█████╗░░██╔██╗██║██║░░╚═╝██████╔╝░╚████╔╝░██████╔╝░░░██║░░░░░░███████║
// ██║░░╚██╗██║░░░░░██╔══╝░░██║╚████║██║░░██╗██╔══██╗░░╚██╔╝░░██╔═══╝░░░░██║░░░░░░██╔══██║
// ╚██████╔╝███████╗███████╗██║░╚███║╚█████╔╝██║░░██║░░░██║░░░██║░░░░░░░░██║░░░██╗██║░░██║ v0.7c
// ░╚═════╝░╚══════╝╚══════╝╚═╝░░╚══╝░╚════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░░░░░░░╚═╝░░░╚═╝╚═╝░░╚═╝ by Glen Angelo Bautista
//==================================================================================================================
// This is my header file containing a bunch of useful functions that I made to make my life easier. It started out
// containing only encryption features. However, many additions were made. Please explore the file to learn more.
//==================================================================================================================
// Latest Changes (0.7c)
//  - Backwards compatibility for old input() function
// Upcoming Changes
//  - showForm
//      > Issue with adding elements, exceeding memory
//  - Keypress events
//==================================================================================================================

#ifndef GLENCRYPT_H
#define GLENCRYPT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <windows.h>
#include <unistd.h>
#include <stddef.h>
#include <math.h>

//==================================================================================================================
// Global Values (Can be configured)
#define MAX_STRING_LENGTH 256
#define MAX_KEY_LENGTH 256
#define MAX_COMMAND_LENGTH 128
#define MENU_PAGE_LENGTH 7
#define TABLE_PAGE_LENGTH 10
#define MAX_ELEMENTS 256

//==================================================================================================================
// Character list definitions, used for inputCustom()
#define ALPHANUM "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define NUMERIC "0123456789."
#define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Character list definitions, used for encryption/decryption
#define CHARLIB "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ "
#define DEFAULTKEY "}Pj? THrxT_{Dh^Q.UdrG&s-X'?zaPBJ-2]dyFD23IV9:'&tT%]:}$m@<~[,oT$"
#define KEYGEN "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+,-./:;<=>?@[]^_`{|}~ "

//==================================================================================================================
// Function Prototypes (structure based are commented out)
void printLine(int type);
void printLineWidth(int width);
void printColor(int text_color, const char* format, ...);
void printCentered(const char *str, int field_width);
int getCharPos(char* str, char ch);
void waitEnter();
void invalidChoice();
void invalidCustom(char* message, int width);
void exitProgram();
void convertString(void* data, char* type, char* str);
void formatString(void* data, char* type, char* str, char* format);
char* typeFromFormat(char* format);
int extractNumber(const char *str);
const char* keyEncrypt(char input[], char key[]);
const char* keyDecrypt(char input[], char key[]);
const char* encrypt(char input[]);
const char* decrypt(char input[]);
char* generateKey(int length);
int isNumericChar(char ch);
int isEmpty(const char *input);
void input_impl(char* datatype, char *prompt, void* output); // input(datatype, prompt, &output)
void inputCustom(char *prompt, void* output, char *accepted);
void runProgram(char* path, char* program);
void compileRunProgram(const char* path, const char* program);
// void showMenu(char *title, menu* options);
// void showPageMenu(char *title, page_menu* page);
FILE *openFile(const char *path, const char *file_name, const char *mode);
// void printTableFull(char* title, table* table);
// void printTable(char* title, table* table);

//==================================================================================================================
// General Macros

// Sample: stringify(123); | Result: "123"
#define stringify(x) #x

// Sample: getDataType(name); | Result: "char*"
#define getDataType(x) _Generic((x), \
    int:     "int", \
    float:   "float", \
    double:  "double", \
    char*:   "char*", \
    void*:   "void*", \
    size_t:  "size_t", \
    int*:    "int*", \
    float*:  "float*", \
    double*: "double*", \
    default: "other")

//==================================================================================================================
// Print Line Functions

// Sample: printLine(0);
void printLine(int type) { //print lines in different styles
	switch(type) {
		case 0: //normal (length: 33)
			printf("---------------------------------\n");
			break;
		case 1: //fancy
			printf("->->-~-~-~-=-=-=-=-=-=-~-~-~-<-<-\n");
			break;
		case 2: //long (length: 66)
			printf("------------------------------------------------------------------\n");
			break;
		default:
			printf("---------------------------------\n");
			break;
	}
}

// Sample: printLineWidth(10); 
void printLineWidth(int width) { //print line with custom width
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

//==================================================================================================================
// Color Macros & Print Functions
#define BLACK 0
#define RED FOREGROUND_RED | FOREGROUND_INTENSITY
#define GREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define BLUE FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define MAGENTA FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define CYAN FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY

// Sample: printColor(RED, "Error %d", number);
void printColor(int text_color, const char* format, ...) //printf in color
{
    // Get the current console handle
    HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Store the current console attributes
    CONSOLE_SCREEN_BUFFER_INFO console_info;
    GetConsoleScreenBufferInfo(h_console, &console_info);
    WORD original_attr = console_info.wAttributes;

    // Set the text color
    SetConsoleTextAttribute(h_console, text_color);
    
    // Print the formatted text
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    
    // Reset the color
    SetConsoleTextAttribute(h_console, original_attr);
}

// Sample: printCentered("Hello", 15); | Result: "     Hello     "
void printCentered(const char *str, int field_width) {
    int str_length = strlen(str);
    int padding = (field_width - str_length) / 2;
    printf("%*s%s%*s", padding, "", str, field_width - padding - str_length, "");
}

//==================================================================================================================
// Miscelaneous Functions

// Sample: getCharPos("Hello", 'e'); | Result: 1
int getCharPos(char* str, char ch) { //locates the first position of a character in a string
    char* pos = strchr(str, ch);
    if (pos == NULL) {
        return -1;
    }
	else {
        return (int)(pos - str);
    }
}

void waitEnter() { //waits for user to press enter
    printf("Press Enter to continue...");
    fflush(stdout);  

    while (getchar() != '\n') {

    }
}

void invalidChoice() { //returns invalid choice
    printColor(RED,"Invalid choice.\n");
    printLine(0);
    waitEnter();
}

// Sample: invalidCustom("Invalid choice", 10);
void invalidCustom(char* message, int width) { //returns invalid choice
    printColor(RED, message);
    printLineWidth(width);
    waitEnter();
}

void exitProgram() { //exits program
	system("cls");
    printLine(0);
	printf("Exiting Program...\n");
    printLine(0);
	exit(0);	
}

// Sample: exitCustom("Exiting... Goodbye!", 20);
void exitCustom(char* message, int width) { //exits program
	system("cls");
    printLineWidth(width);
	printf(message);
    printLineWidth(width);
	exit(0);	
}

//==================================================================================================================
// Data Type & String Formatting Functions

// Sample: convertString(100, "int", output); | Result: "100"
void convertString(void* data, char* type, char* str) { //convert any datatype to string
    if (data == NULL) {
        strcpy(str, "NULL");
    } else if (!strcmp(type, "int")) {
        snprintf(str, MAX_STRING_LENGTH, "%d", *((int*)data));
    } else if (!strcmp(type, "float")) {
        snprintf(str, MAX_STRING_LENGTH, "%f", *((float*)data));
    } else if (!strcmp(type, "double")) {
        snprintf(str, MAX_STRING_LENGTH, "%lf", *((double*)data));
    } else if (!strcmp(type, "char*")) {
        snprintf(str, MAX_STRING_LENGTH, "%s", (char*)data);
    } else {
        strcpy(str, "Unknown Type"); // Handle unknown types
    }
}

// Sample: formatString(100, "float", output, "%.2f"); | Result: "100.00"
void formatString(void* data, char* type, char* str, char* format) { //convert any datatype to string
    if (data == NULL) {
        strcpy(str, "NULL");
    } else if (!strcmp(type, "int")) {
        snprintf(str, MAX_STRING_LENGTH, format, *((int*)data));
    } else if (!strcmp(type, "float")) {
        snprintf(str, MAX_STRING_LENGTH, format, *((float*)data));
    } else if (!strcmp(type, "double")) {
        snprintf(str, MAX_STRING_LENGTH, format, *((double*)data));
    } else if (!strcmp(type, "char*")) {
        snprintf(str, MAX_STRING_LENGTH, format, (char*)data);
    } else {
        strcpy(str, "Unknown Type"); // Handle unknown types
    }
}

// Sample: typeFromFormat("%s"); | Result: "char*"
char* typeFromFormat(char* format) {
    int length = strlen(format);
    int i = 0;

    while (i < length) {
        if (format[i] == '%') {
            i++; // Skip the '%'
            // Skip flags and width field
            while (i < length && (format[i] == '-' || format[i] == '+' || format[i] == ' ' || format[i] == '0' || format[i] == '#' || format[i] == '*')) {
                i++;
            }
            // Skip width field (numeric characters)
            while (i < length && format[i] >= '0' && format[i] <= '9') {
                i++;
            }
            // Check if there is a precision specifier
            if (format[i] == '.') {
                i++; // Skip the '.'
                // Skip precision field (numeric characters)
                while (i < length && format[i] >= '0' && format[i] <= '9') {
                    i++;
                }
            }
            // Check for format specifier characters (e.g., "lf", "f", "d", "s")
            if (i < length && (format[i] == 'l' || format[i] == 'f' || format[i] == 'd' || format[i] == 's')) {
                char specifier[3] = { format[i], '\0', '\0' };
                if (format[i] == 'f') {
                    return "float";
                } else if (format[i] == 'd') {
                    return "int";
                } else if (format[i] == 's') {
                    return "char*";
                }
                if (format[i] == 'l') {
                    specifier[1] = 'l';
                    i++; // Skip the second 'l'
                }
                if (strcmp(specifier, "lf") == 0 || format[i] == 'f') {
                    return "double";
                }
            }
        }
        i++;
    }
    return "unknown";
}

// Sample: extractNumber("abc123.45"); | Result: 123
int extractNumber(const char *str) { // Extracts the first iteration of integers from a string
    // Skip leading whitespaces and non-digit characters
    while (*str && !isdigit(*str)) {
        str++;
    }
    // Extract the numeric part (integral part only)
    int result = 0;
    while (*str && isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result; // Return the extracted number
}


//==================================================================================================================
// Cryptography Functions (glencrypt)

// Sample: keyEncrypt("Hello", "testkey"); | Result: "+sNOI"
const char* keyEncrypt(char input[], char key[]) { //custom encryption algorithm that takes a key
    static char output[MAX_STRING_LENGTH];
    int converted_input[MAX_STRING_LENGTH];
    int converted_key[MAX_KEY_LENGTH];
    int n = strlen(input);
    int m = strlen(key);
    
    char lib[] = CHARLIB;
    
    for(int i = 0; i < n; i++) {
        converted_input[i] = getCharPos(lib, input[i]);
    }
    for(int i = 0; i < m; i++) {
        converted_key[i] = getCharPos(lib, key[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int x = i % m;
        int a = (converted_input[i] + converted_key[x]) % strlen(lib);
        output[i] = lib[a];
    }
    output[n] = '\0'; 
    
    return output;
}

// Sample: keyDecrypt("+sNOI", "testkey"); | Result: "Hello"
const char* keyDecrypt(char input[], char key[]) { //custom decryption algorithm that takes a key
    static char output[MAX_STRING_LENGTH];
    int converted_input[MAX_STRING_LENGTH];
    int converted_key[MAX_KEY_LENGTH];
    int n = strlen(input);
    int m = strlen(key);
    
    char lib[] = CHARLIB;
    
    for(int i = 0; i < n; i++) {
        converted_input[i] = getCharPos(lib, input[i]);
    }
    for(int i = 0; i < m; i++) {
        converted_key[i] = getCharPos(lib, key[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int x = i % m;
        int a = (converted_input[i] - converted_key[x] + strlen(lib)) % strlen(lib);
        output[i] = lib[a];
    }
    output[n] = '\0'; 
    
    return output;
}

// Sample: encrypt("Hello"); | Result: "E$E8n"
const char* encrypt(char input[]) { //encrypt using default key
    return keyEncrypt(input, DEFAULTKEY);
}

// Sample: decrypt("E$E8n"); | Result: "Hello"
const char* decrypt(char input[]) { //decrypt using default key
    return keyDecrypt(input, DEFAULTKEY);
}

// Sample: generateKey(10); | Result: "**********" (10 character random key)
char* generateKey(int length) { //generates a random key
    static int initialized = 0;
    static char key[MAX_KEY_LENGTH];
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    for(int i = 0; i < length; i++) {
        key[i] = KEYGEN[rand() % strlen(KEYGEN)];
    }
    key[length] = '\0';
    return key;
}

//==================================================================================================================
// Check Functions

// Sample: IsNumericChar('a'); | Result: 0
int isNumericChar(char ch) { //check if numeric char or , - +
    return isdigit(ch) || ch == '.' || ch == '-' || ch == '+';
}

// Sample: isEmpty(""); | Result: 1
int isEmpty(const char *input) { //check if string is empty
    size_t len = strlen(input);
    for (size_t i = 0; i < len; i++) {
        if (!isspace(input[i])) {
            return 0;
        }
    }
    return 1;
}

//==================================================================================================================
// Improved Input with error handling and specifiers

// Sample: input(int, "Enter int: ", &output);
// Sample: input(double, "Enter double: ", &output);
#define input(datatype, prompt, output) input_impl(stringify(datatype), prompt, output)

void input_impl(char* datatype, char *prompt, void* output) { //input variable of specified datatype
    if (!strcmp(datatype, "int") || !strcmp(datatype, "Int") || !strcmp(datatype, "INT")) { //int
        while(1) {
            printf("%s", prompt);
            char buffer[MAX_STRING_LENGTH];
            int temp;
            fgets(buffer, MAX_STRING_LENGTH, stdin);
            if (isEmpty(buffer)) {
                printColor(RED,"Invalid input. Input must not be empty.\n");
                printLine(0);
            }
            else {
                char* endptr;
                temp = strtol(buffer, &endptr, 10);
                if (*endptr != '\n' && *endptr != '\0') {
                    printColor(RED,"Invalid input. Input must be an integer.\n");
                    printLine(0);
                }
                else {
                    *(int*)output = temp;
                    return;
                }
            }
        }
    }
    else if (!strcmp(datatype, "double") || !strcmp(datatype, "Double") || !strcmp(datatype, "DOUBLE")) { //double
        while (1) {
            printf("%s", prompt);
            char buffer[MAX_STRING_LENGTH];
            double temp;
            fgets(buffer, MAX_STRING_LENGTH, stdin);
            if (isEmpty(buffer)) {
                printColor(RED,"Invalid input. Input must not be empty.\n");
                printLine(0);
            }
            else {
                int end_ptr;
                if (sscanf(buffer, "%lf%n", &temp, &end_ptr) != 1 || buffer[end_ptr] != '\n') {
                    printColor(RED,"Invalid input. Please enter a valid double.\n");
                    printLine(0);
                }
                else {
                    *(double*)output = temp;
                    return;
                }
            }
        }
    }
    else if (!strcmp(datatype, "char") || !strcmp(datatype, "Char") || !strcmp(datatype, "CHAR")) { //char
        while (1) {
            printf("%s", prompt);
            char buffer[MAX_STRING_LENGTH];
            fgets(buffer, MAX_STRING_LENGTH, stdin);
            if (isEmpty(buffer)) {
                printColor(RED,"Invalid input. Input must not be empty.\n");
                printLine(0);
            }
            else if (strlen(buffer) > 2) {
                printColor(RED,"Invalid input. Input must be a single character.\n");
                printLine(0);
            }
            else {
                *(char*)output = buffer[0];
                return;
            }
        }
    }

    else if (!strcmp(datatype, "str") || !strcmp(datatype, "char*") || !strcmp(datatype, "Str") || !strcmp(datatype, "STR")) { // string
        while(1) {
            printf("%s", prompt);
            char buffer[MAX_STRING_LENGTH];
            fgets(buffer, MAX_STRING_LENGTH, stdin);
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len-1] == '\n') {
                buffer[--len] = '\0';
            }
            if (!isEmpty(buffer)) {
                strcpy((char*)output, buffer);
                return;
            } else {
                printColor(RED,"Invalid input. Input must not be empty.\n");
                printLine(0);
            }
        }
    }


    else if (!strcmp(datatype, "bool") || !strcmp(datatype, "Bool") || !strcmp(datatype, "BOOL")) { //bool (int but accepts y/n/1/0)
        while (1) {
            printf("%s", prompt);
            char buffer[MAX_STRING_LENGTH];
            fgets(buffer, MAX_STRING_LENGTH, stdin);
            if (buffer[0] == 'y' || buffer[0] == 'Y' || buffer[0] == '1') {
                *(int*)output = 1;
                return;
            }
            else if (buffer[0] == 'n' || buffer[0] == 'N' || buffer[0] == '0') {
                *(int*)output = 0;
                return;
            }
            else {
                printColor(RED,"Invalid input. Input must be 'y' or 'n'.\n");
                printLine(0);
            }
        }
    }
    else {
        printColor(RED,"Invalid datatype.\n");
        printLine(0);
    }
}

// Sample: inputCustom("Enter string: ", &str, "abcd1234");
void inputCustom(char *prompt, void* output, char *accepted) { //input a string, rejects characters not in the accepted string
    while(1) {
        printf("%s", prompt);
        char buffer[MAX_STRING_LENGTH];
        char invalid_char[MAX_STRING_LENGTH];
        memset(invalid_char, '\0', sizeof(invalid_char));
        fgets(buffer, MAX_STRING_LENGTH, stdin);
        
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[--len] = '\0';
        }
        
        if (isEmpty(buffer)) {
            printColor(RED,"Invalid input. Input must not be empty.\n");
            printLine(0);
        }
        else {
            int n = strlen(buffer);
            int m = strlen(accepted);
            int x = 0;

            int invalid = 0;

            for(int i=0; i < n; i++) {
                int char_is_valid = 0;
                for(int j=0; j < m; j++) {
                    if (buffer[i] == accepted[j]) {
                        char_is_valid = 1;
                        break;
                    }
                }
                if (!char_is_valid) {
                    invalid = 1;
                    if (!strchr(invalid_char, buffer[i])) {
                        invalid_char[x] = buffer[i];
                        x += 1;
                    }
                }
            }
            invalid_char[x] = '\0';
            if (invalid == 0) {
                strcpy((char*)output, buffer);
                return;
            }
            else {
                printColor(RED,"Invalid input. Input cannot contain '%s'.\n", invalid_char);
                printLine(0);
            }
        }
    }
}

//==================================================================================================================
// Program Run & Compile Functions
char original_dir[MAX_STRING_LENGTH];

// Sample: runProgram("LRT/", "Bautista_LRT.exe");
void runProgram(char* path, char* program) { //run a exe program
    getcwd(original_dir, sizeof(original_dir));
    chdir(path); 
    system("cls");
    system(program);
    system("cls");
    chdir(original_dir);
}

// Sample: compileRunProgram("LRT/", "Bautista_LRT");
void compileRunProgram(const char* path, const char* program) { //compile then run, SLOW AF
    getcwd(original_dir, sizeof(original_dir));
    chdir(path);

    char compile_command[MAX_COMMAND_LENGTH];
    snprintf(compile_command, sizeof(compile_command), "gcc %s.c -o %s.exe", program, program);
    printLine(0);
    printf("Compiling... Please Wait.\n");
    printLine(0);
    system(compile_command);

    char run_command[MAX_COMMAND_LENGTH];
    snprintf(run_command, sizeof(run_command), "%s.exe", program);
    system(run_command);

    system("cls");
    chdir(original_dir);
}

//==================================================================================================================
// Menu Functions

typedef struct {
    char* text;
    void (*function)();
} menu;

#define END_MENU {NULL, NULL}
#define SUBTITLE NULL
#define LINE {"", NULL}

int menu_return = 0;
void showMenu(char *title, menu* options) { //standard menu
    while(1) {
        system("cls");
        printLine(0);
        printf("%s\n", title);
        printLine(0);
        int i = 0;
        int sub_count = 0;
        while (options[i+sub_count].text != NULL) {
            if(options[i+sub_count].function != NULL) {
                printf("[%d] %s\n", i+1, options[i+sub_count].text);
                i++;
            }
            else {
                if(i != 0 || !strcmp(options[i+sub_count].text, "")) {printLine(0);}
                if(strcmp(options[i+sub_count].text, "")) {
                    printf("%s\n", options[i+sub_count].text);
                }
                sub_count++;
            }
        }
        printf("[0] Return\n");
        printLine(0);
        int choice;
        input(Int, "Enter choice: ", &choice);
        if(choice == 0) {
            menu_return = 1;
            return;
        }
        if(choice > i || choice < 0) {
            printColor(RED,"Invalid choice.\n");
            printLine(0);
            waitEnter();
            continue;
        }
        system("cls");
        options[choice-1+sub_count].function();
        if(menu_return != 1) {
            waitEnter();
            system("cls");
        }
        menu_return = 0;
    }
}
/* Sample for showMenu()
// menu test[] = {
//     {"Option 1", function1},
//     {"Option 2", function2},
//     END_MENU
// };
//showMenu("Test Menu", test)
*/


#define END_PAGE_MENU NULL

typedef struct {
    menu *options;
} page_menu;

void showPageMenu(char *title, page_menu* page) { //menu with page support
    int current_page = 0;
    int page_count = 0;
    while (page[page_count].options != NULL) {
        page_count++;
    }
    while(1) {
        system("cls");
        printLine(0);
        printf("%s [%d/%d]\n", title, current_page+1, page_count);
        printLine(0);
        int i = 0;
        int sub_count = 0;
        while (page[current_page].options[i+sub_count].text != NULL) {
            if(i >= MENU_PAGE_LENGTH) {
                printColor(RED, "ERROR: Page Overflow.\n");
                return;
            }

            if(page[current_page].options[i+sub_count].function != NULL) {
                printf("[%d] %s\n", i+1, page[current_page].options[i+sub_count].text);
                i++;
            }
            else {
                if(i != 0 || !strcmp(page[current_page].options[i+sub_count].text, "")) {printLine(0);}
                if(strcmp(page[current_page].options[i+sub_count].text, "")) {
                    printf("%s\n", page[current_page].options[i+sub_count].text);
                }
                sub_count++;
            }
        }
        printLine(0);
		if (current_page > 0) {
			printf("[8] Previous Page\n");
		}
		if (current_page != page_count-1) {
			printf("[9] Next Page\n");
		}
        printf("[0] Return\n");
        printLine(0);
        int choice;
        input(Int, "Enter choice: ", &choice);
        switch(choice) {
            case 8: 
                if (current_page > 0) {	
                    current_page--;				
                    continue;
                }
                else {
                    invalidChoice();
                    continue;
                }
            case 0: menu_return = 1; return;
            case 9: 
                if (current_page != page_count-1) {	
                    current_page++;
                    continue;
                }
                else {
                    invalidChoice();
                    continue;
                }
            default: break;
        }
        
        if((choice > i && choice != 8 && choice != 9 )|| choice < 0) {
            invalidChoice();
            continue;
        }
        system("cls");

        int j = 0; int k = choice;
        do {
            if(page[current_page].options[j].function == NULL) {
                k++;
            }
            j++;
        } while(j != k);
        page[current_page].options[k-1].function();
        
        
        if(menu_return != 1) {
            waitEnter();
            system("cls");
        }
        menu_return = 0;
    }
}
/* Sample for showPageMenu()
// page_menu test[] = {
//     { (menu[]) {
//         {"Option 1", function1},
//         {"Option 2", function2},
//         END_MENU
//     }},
//     {(menu[]) {
//         {"Option 3", function3},
//         {"Option 4", function4},
//         END_MENU
//     }},
//     END_MENU
// };
//showMenu("Test Page Menu", test)
*/

//==================================================================================================================
// File Processing

// Sample: openFile("bin/", "accounts.dat", "rb");
// Note: dont forget to fclose()
FILE *openFile(const char *path, const char *file_name, const char *mode) {
    char file_path[MAX_STRING_LENGTH];
    snprintf(file_path, sizeof(file_path), "%s%s", path, file_name);
    FILE *input_file = fopen(file_path, mode);
    return input_file;
}

//==================================================================================================================
// Table Functions
#define TABLE_COLUMN(TITLE, STRUCT_PTR, MEMBER_NAME, FORMAT_ARG) \
    {TITLE, (void**)&(STRUCT_PTR), sizeof(STRUCT_PTR) / sizeof(STRUCT_PTR[0]), \
    offsetof(typeof(*(STRUCT_PTR)), MEMBER_NAME), sizeof(STRUCT_PTR[0]), FORMAT_ARG}

typedef struct {
    char* header;
    void** content;
    size_t content_size;  // Change to 'num_elements'
    size_t offset;
    size_t struct_size;  // Add the size of the structure
    char* format;     // Add the data type of the column
} table;

#define END_TABLE {NULL, NULL, 0, 0, 0, NULL}

void printTableFull(char* title, table* table) {
    int num_columns = 0;
    while (table[num_columns].header != NULL) {
        num_columns++;
    }

    // Print table title
    int table_width = (num_columns*2)+1;
    for (int i = 0; i < num_columns; i++) {
        table_width += extractNumber(table[i].format);
    }
    printLineWidth(table_width);
    printCentered(title, table_width);
    printf("\n");
    printLineWidth(table_width);

    // Print table headers
    printf("|");
    for (int i = 0; i < num_columns; i++) {
        int column_width = extractNumber(table[i].format) + 1;
        printCentered(table[i].header, column_width);
        printf("|");
    }
    printf("\n");

    // Print table content
    for (int i = 0; i < table->content_size; i++) {
        printf("|");
        for (int j = 0; j < num_columns; j++) {
            char buffer[MAX_STRING_LENGTH];
            formatString((char*)((uintptr_t)table[j].content + table[j].offset) + (i * table[j].struct_size), typeFromFormat(table[j].format), buffer, table[j].format);
            // convertString((char*)((uintptr_t)table[j].content + table[j].offset) + (i * table[j].struct_size), table[j].format, buffer); //this line is killing me
            printf(" %s|", buffer);
        }
        printf("\n");
    }
    printLineWidth(table_width);
}

void printTable(char* title, table* table) {
    int num_columns = 0;
    while (table[num_columns].header != NULL) {
        num_columns++;
    }

    int page = 0; 
    int max_page = ((table->content_size) / TABLE_PAGE_LENGTH);
    int page_row_counter = 0; int table_row_counter = 0;

    while(1) {
        system("cls");
        // Print table title
        int table_width = (num_columns*2)+1;
        for (int i = 0; i < num_columns; i++) {
            table_width += extractNumber(table[i].format);
        }
        printLineWidth(table_width);
        printCentered(title, table_width);
        printf("\n");
        printLineWidth(table_width);

        // Print table headers
        printf("|");
        for (int i = 0; i < num_columns; i++) {
            int column_width = extractNumber(table[i].format) + 1;
            printCentered(table[i].header, column_width);
            printf("|");
        }
        printf("\n");

        // Print table content
        for (; page_row_counter < TABLE_PAGE_LENGTH && table_row_counter < table->content_size; page_row_counter++, table_row_counter++) {
            printf("|");
            for (int j = 0; j < num_columns; j++) {
                char buffer[MAX_STRING_LENGTH];
                formatString((char*)((uintptr_t)table[j].content + table[j].offset) + (table_row_counter * table[j].struct_size), typeFromFormat(table[j].format), buffer, table[j].format);
                // convertString((char*)((uintptr_t)table[j].content + table[j].offset) + (table_row_counter * table[j].struct_size), table[j].format, buffer); //this line is killing me
                printf(" %s|", buffer);
            }
            printf("\n");
        }
        page_row_counter = 0;

        printLineWidth(table_width);

        printf(" Page %d/%d    ", page+1, max_page+1);
        if (page > 0) {
            printf("[8] Previous Page    ");
        }
        if (page != max_page) {
            printf("[9] Next Page    ");
        }
        printf("[0] Return\n");

        printLineWidth(table_width);

        int choice;
        input(Int, "Enter choice: ", &choice);
        switch (choice) {
            case 8:
                if (page > 0) {	
                    page--;
                    table_row_counter = page*TABLE_PAGE_LENGTH;
                    break;
                }
                else {
                    invalidCustom("Invalid choice.", table_width);
                    continue;
                }
                
            case 9:
                if (page != max_page) {	
                    page++;
                    table_row_counter = page*TABLE_PAGE_LENGTH;
                    break;
                }
                else {
                    invalidCustom("Invalid choice.", table_width);
                    continue;
                }
            case 0:
                printLine(2);
                return;
                break;
            default:
                invalidCustom("Invalid choice.", table_width);
                continue; 
        }
    }
}
/* Sample for printTable() & printTableFull()
typedef struct {
    int id;
    char name[20];
} person;
person people[] = {
    {1, "John"},
    {2, "Jane"}
};
table test[] = {
    TABLE_COLUMN("ID", people, id, "%-6d"),
    TABLE_COLUMN("Name", people, name, "%-16s"),
    END_TABLE
};
printTable("Test Table", test);
or
printTableFull("Test Table", test);
*/

//==================================================================================================================
// Form Functions

#define FORM_WIDTH 33

size_t test_size;

void inputForm(char* title, table* table) {
    int num_fields = 0;
    while (table[num_fields].header != NULL) {
        num_fields++;
    }

    // Print form title
    printLineWidth(FORM_WIDTH);
    printCentered(title, FORM_WIDTH);
    printf("\n");
    printLineWidth(FORM_WIDTH);
    
    // Print field prompts
    


    if (test_size == NULL) {
        test_size = table->content_size;
    }

    printf("Size: %zu\n", test_size);

    for (int i = 0; i < num_fields; i++) {
        printf("Enter %s: ", table[i].header);
        
        char *field_datatype = typeFromFormat(table[i].format);

        input_impl(field_datatype, "", (char*)((uintptr_t)table[i].content + table[i].offset) + (test_size * table[i].struct_size));
    }
    test_size++;

    printf("Size: %zu\n", test_size);

    printf("\n");

}

//==================================================================================================================
// The End :))
//==================================================================================================================

#endif
