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

#define ALPHANUM "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define NUMERIC "0123456789."
#define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define CHARLIB "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ "
#define DEFAULTKEY "}Pj? THrxT_{Dh^Q.UdrG&s-X'?zaPBJ-2]dyFD23IV9:'&tT%]:}$m@<~[,oT$"
#define KEYGEN "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'()*+,-./:;<=>?@[]^_`{|}~ "

#define MAX_STRING_LENGTH 256

#define STRINGIFY(x) #x

typedef enum {
    Undef,
    Int,
    Double,
    Char,
    Str,
    Bool
} DataType;




//COSMETIC STUFFS
void printLine(int type) { //print lines in different styles
	switch(type) {
		case 0: //normal
			printf("---------------------------------\n");
			break;
		case 1: //fancy
			printf("->->-~-~-~-=-=-=-=-=-=-~-~-~-<-<-\n");
			break;
		case 2: //long
			printf("------------------------------------------------------------------\n");
			break;
		default:
			printf("---------------------------------\n");
			break;
	}
}

//COLOR DEFINITIONS
#define BLACK 0
#define RED FOREGROUND_RED | FOREGROUND_INTENSITY
#define GREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define BLUE FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define MAGENTA FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define CYAN FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY

void printColor(int textColor, const char* format, ...) //printf in color
{
    // Get the current console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Store the current console attributes
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    WORD originalAttrs = consoleInfo.wAttributes;

    // Set the text color
    SetConsoleTextAttribute(hConsole, textColor);
    
    // Print the formatted text
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    
    // Reset the color
    SetConsoleTextAttribute(hConsole, originalAttrs);
}


//MISC

int getCharPos(char* str, char ch) { //locates the position of a character in a string
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

void exitProgram() { //exits program
	system("cls");
	printf("Exiting Program...\n");
	exit(0);	
}

void convertString(void* data, char* type, char* str) { //convert any datatype to string
    if (data == NULL) {
        strcpy(str, "NULL");
    } else if (!strcmp(type, "int")) {
        snprintf(str, MAX_STRING_LENGTH, "%d", *((int*)data));
    } else if (!strcmp(type, "float")) {
        snprintf(str, MAX_STRING_LENGTH, "%f", *((float*)data));
    } else if (!strcmp(type, "double")) {
        snprintf(str, MAX_STRING_LENGTH, "%.2lf", *((double*)data));
    } else if (!strcmp(type, "char*")) {
        snprintf(str, MAX_STRING_LENGTH, "%s", (char*)data);
    } else {
        strcpy(str, "Unknown Type"); // Handle unknown types
    }
}

//Encryption


const char* keyEncrypt(char input[], char key[]) { //custom encryption algorithm that takes a key
    static char output[256];
    int converted_input[256];
    int converted_key[256];
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

const char* keyDecrypt(char input[], char key[]) { //custom decryption algorithm that takes a key
    static char output[256];
    int converted_input[256];
    int converted_key[256];
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


const char* encrypt(char input[]) { //encrypt using default key
    return keyEncrypt(input, DEFAULTKEY);
}

const char* decrypt(char input[]) { //decrypt using default key
    return keyDecrypt(input, DEFAULTKEY);
}


char* generateKey(int length) { //generates a random key
    static int initialized = 0;
    static char key[256];
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


//CHECKS

int isEmpty(const char *input) { //check if string is empty
    size_t len = strlen(input);
    for (size_t i = 0; i < len; i++) {
        if (!isspace(input[i])) {
            return 0;
        }
    }
    return 1;
}


//IMPROVED INPUT

void input(int datatype, char *prompt, void* output) { //input variable of specified datatype
    if (datatype == 0){ //unspecified

    }
    else if (datatype == 1) {
        while(1) {
            printf("%s", prompt);
            char buffer[256];
            int temp;
            fgets(buffer, 256, stdin);
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
    else if (datatype == 2) { //double
        while (1) {
            printf("%s", prompt);
            char buffer[256];
            double temp;
            fgets(buffer, 256, stdin);
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
    else if (datatype == 3) { //char
        while (1) {
            printf("%s", prompt);
            char buffer[256];
            fgets(buffer, 256, stdin);
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

    else if (datatype == 4) { // string
        while(1) {
            printf("%s", prompt);
            char buffer[256];
            fgets(buffer, 256, stdin);
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


    else if (datatype == 5) { //bool (int but accepts y/n/1/0)
        while (1) {
            printf("%s", prompt);
            char buffer[256];
            fgets(buffer, 256, stdin);
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


void inputCustom(char *prompt, void* output, char *accepted) { //input a string, rejects characters not in the accepted string
    while(1) {
        printf("%s", prompt);
        char buffer[256];
        char invalid_char[256];
        memset(invalid_char, '\0', sizeof(invalid_char));
        fgets(buffer, 256, stdin);
        
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


char original_dir[256];

void runProgram(char* path, char* program) { //run a exe program
    getcwd(original_dir, sizeof(original_dir));
    chdir(path); 
    system("cls");
    system(program);
    system("cls");
    chdir(original_dir);
}

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

#define PAGE_LENGTH 7
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
            if(i >= PAGE_LENGTH) {
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

FILE *openFile(const char *path, const char *file_name, const char *mode) {
    char file_path[100];
    snprintf(file_path, sizeof(file_path), "%s%s", path, file_name);
    FILE *input_file = fopen(file_path, mode);
    return input_file;
}

//PRINT TABLE
#define TABLE_COLUMN(TITLE, STRUCT_PTR, MEMBER_NAME, TYPE_ARG) \
    {TITLE, (void**)&(STRUCT_PTR), sizeof(STRUCT_PTR) / sizeof(STRUCT_PTR[0]), \
    offsetof(typeof(*(STRUCT_PTR)), MEMBER_NAME), sizeof(STRUCT_PTR[0]), STRINGIFY(TYPE_ARG)}

typedef struct {
    char* header;
    void** content;
    size_t content_size;  // Change to 'num_elements'
    size_t offset;
    size_t struct_size;  // Add the size of the structure
    char* data_type;     // Add the data type of the column
} table;

#define END_TABLE {NULL, NULL, 0, 0, 0, NULL}

void printTable(table* table) {
    int num_columns = 0;
    while (table[num_columns].header != NULL) {
        num_columns++;
    }

    // Print table headers
    for (int i = 0; i < num_columns; i++) {
        printf("%s\t", table[i].header);
    }
    printf("\n");

    // Print table content
    for (int i = 0; i < table->content_size; i++) {
        for (int j = 0; j < num_columns; j++) {
            char buffer[MAX_STRING_LENGTH];
            convertString((char*)((uintptr_t)table[j].content + table[j].offset) + (i * table[j].struct_size), table[j].data_type, buffer);
            printf("%s\t", buffer);
        }
        printf("\n");
    }
}


#endif
