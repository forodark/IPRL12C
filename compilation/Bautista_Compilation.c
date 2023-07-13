//Final Project - Compilation of all outputs
//Bautista, Glen Angelo D

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "glencrypt.h"

#include "./prelim/P1.c"
#include "./prelim/P2.c"
#include "./prelim/ME1.c"
#include "./prelim/ME2.c"
#include "./prelim/Bautista_LRT.c"

#include "./midterm/M1.c"
#include "./midterm/M2.c"
#include "./midterm/Bautista_ATMv4.c"

#include "./finals/F1.c"
#include "./finals/F2.c"
#include "./finals/F3.c"
#include "./finals/F4.c"
#include "./finals/F5.c"
#include "./finals/Bautista_FPQuiz.c"

void exitProgram();
void showMenuMain();
void showMenuP();
void showMenuM();
void showMenuF();
void showMenuP1();
void showMenuP2();
void showMenuM1(int page);
void showMenuM2();
void showMenuF1();
void showMenuF2();
void showMenuF3();
void showMenuF4();
void showMenuF5();



//I updated all the names in the menus so that its more descriptive of the functionality

char original_dir[128];


int main() { //main function only calls the main menu, the main loop is located there
	

	showMenuMain();
	return 0;
}

void exitProgram() { //this is the only function that actually exits the program, every other exits from programs compiled are replaced with a return (back)
	system("cls");
	printf("Exiting Program...\n");
	exit (0);	
}

void showMenuMain() {//main menu contains the main screen where you can branch out from
    while(1) {
		system("cls");
		printLine(0);
		printf("Machine Exercise Compilation\n");
		printf("by Glen Angelo Bautista\n");
		printLine(0);
	    printf("[1] Prelim\n");
	    printf("[2] Midterm\n");
	    printf("[3] Finals\n");
		printf("[0] Exit\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	showMenuP();
				printLine(0);
				break;
			case 2:
            	showMenuM();
				printLine(0);
				break;
			case 3:
				showMenuF();
				printLine(0);
				break;
			case 0:
				exitProgram();
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
	}
}

void showMenuP() { //menu for prelim exercises
    while(1) {
		system("cls");
		printLine(0);
		printf("Prelim Machine Exercises\n");
		printLine(0);
	    printf("[1] 1D Arrays\n");
	    printf("[2] 2D Arrays\n");
	    printf("[3] ME1 - Sum/Product\n");
	    printf("[4] ME2 - Charge Calculator\n");
	    printf("[5] LRT Fare Calculator\n");
	    printf("[0] Return\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	showMenuP1();
				break;
			case 2:
            	showMenuP2();
				break;
			case 3:
				ME1();
				break;
			case 4:
				ME2();
				break;
			case 5:
				LRT();
				break;
			case 0:
				showMenuMain();
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
	}
}
void showMenuM() { //menu for midterm exercises
    while(1) {
		system("cls");
		printLine(0);
		printf("Midterm Machine Exercises\n");
		printLine(0);
	    printf("[1] Pointers Examples\n");
	    printf("[2] Pointers Exercises\n");
	    printf("[3] ATMv4 (Structures)\n");
		printf("[0] Return\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	showMenuM1(1);
				break;
			case 2:
            	showMenuM2();
				break;
			case 3:
				ATMv4();
				break;
			case 0:
				showMenuMain();
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
	}
}
void showMenuF() { //menu for finals exercises
    while(1) {
		system("cls");
		printLine(0);
		printf("Finals Machine Exercises\n");
		printLine(0);
	    printf("[1] File Processing\n");
	    printf("[2] Recursion\n");
	    printf("[3] File Processing Machine Problems 1-2\n");
	    printf("[4] File Processing Quiz\n");
		printf("[5] File Processing Machine Problems 3-4\n");
		printf("[6] File Processing Activity - July 6\n");
		printf("[7] ATMv7.2 (File-Based)\n");
		printf("[0] Return\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	showMenuF1();
				break;
			case 2:
            	showMenuF2();
				break;
			case 3:
				showMenuF3();
				break;
			case 4:
				FPQuiz();
				break;
			case 5:
				showMenuF4();
				break;
			case 6:
				showMenuF5();
				break;
			case 7:
				chdir("finals/ATMv7.2/"); 
				system("cls");
				system("Bautista_ATMv7.2.exe");
				chdir(original_dir);
				break;
			case 0:
				showMenuMain();
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
	}
}

void showMenuP1() { //menu for prelim exercises subcategory 1
	system("cls");
    while(1) {
    	printLine(0);
		printf("Exercises on 1D Array\n");
		printLine(0);
	    printf("[1] Initialize Array\n");
	    printf("[2] Initialize Custom Array Size\n");
	    printf("[3] Get Min Value\n");
	    printf("[4] Sum of Array\n");
	    printf("[5] Count Negative Numbers\n");
	    printf("[6] Test if Value Exists\n");
	    printf("[7] Copy Array\n");
	    printf("[8] Copy Array Reverse Order\n");
	    printf("[9] Test if Arrays are Equal\n");   
		printf("[0] Return\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
	        case 1:
	            exercise1P1();
	            break;
	        case 2:
	            exercise2P1();
	            break;
	        case 3:
	            exercise3P1();
	            break;
	        case 4:
	            exercise4P1();
	            break;
	        case 5:
	            exercise5P1();
	            break;
	        case 6:
	            exercise6P1();
	            break;
	        case 7:
	            exercise7P1();
	            break;
	        case 8:
	            exercise8P1();
	            break;
	        case 9:
	            exercise9P1();
	            break;
			case 0:
				showMenuP();
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
	waitEnter();
	system("cls");
	}
}

void showMenuP2() { //menu for prelim exercises subcategory 2
	system("cls");
    while(1) {
    	printLine(0);
		printf("Exercises on 2D Array\n");
		printLine(0);
	    printf("[1] Initializing 2D Array\n");
	    printf("[2] Input values\n");
	    printf("[3] Print 2D Array\n");
	    printf("[4] Count Negative Numbers\n");
	    printf("[5] Print Diagonal\n");
	    printf("[6] Sum of Row\n");
	    printf("[7] Sum of Column\n");
	    printf("[8] Add 2D Arrays\n");
		printf("[0] Return\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
            case 1:
                exercise1P2();
                break;
            case 2:
                exercise2P2();
                break;
            case 3:
                exercise3P2();
                break;
            case 4:
                exercise4P2();
                break;
            case 5:
                exercise5P2();
                break;
            case 6:
                exercise6P2();
                break;
            case 7:
                exercise7P2();
                break;
            case 8:
                exercise8P2();
                break;
			case 0:
				showMenuP();
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
	waitEnter();
	system("cls");
	}
}

void showMenuM1(int page) { //menu for midterm exercises subcategory 1, this one has two pages
	system("cls");
	switch(page) {
		case 1: {
		    while(1) {
		    	printLine(0);
				printf("Midterm Pointer Examples [1/2]\n");
				printLine(0);
				printf("Pointers:\n");
			    printf("[1] Array Elements w/ Pointers\n");
			    printf("[2] Array Elements w/ Pointers 2\n");
			    printf("[3] Array Elements w/ Pointers Reverse\n");
			    printf("[4] Array Elements w/o *pa\n");
			    printLine(0);
			    printf("Pointer Arithmetic:\n");
			    printf("[5] Incrementing Pointers\n");
			    printf("[6] Incrementing Pointers 2\n");
			    printf("[7] Incrementing Pointers w/ Loop\n");
			    printLine(0);
			    printf("[9] Next Page\n");
				printf("[0] Return\n");
			    printLine(0);
		    	int choice;
				input(Int, "Enter choice: ", &choice);
				system("cls");
				printLine(0);
				switch (choice) {
					case 1:
		            	example1M1();
						printLine(0);
						break;
					case 2:
		            	example2M1();
						printLine(0);
						break;
					case 3:
						example3M1();
						printLine(0);
						break;
					case 4:
						example4M1();
						printLine(0);
						break;
					case 5:
						exampleb1M1();
						printLine(0);
						break;
					case 6:
						exampleb2M1();
						printLine(0);
						break;
					case 7:
						exampleb3M1();
						printLine(0);
						break;
					case 9:
						showMenuM1(2);
					case 0:
						showMenuM();
						break;
					default:
						printf("Invalid choice.\n");
						waitEnter();
				}
				waitEnter();
				system("cls");
			}
			
			break;
			
		}
		
		case 2: {
		    while(1) {
		    	printLine(0);
				printf("Midterm Pointer Examples [2/2]\n");
				printLine(0);
			    printf("Memory Allocation:\n");
			    printf("[1] Dynamic Memory Allocation\n");
			    printf("[2] Malloc for Multiple Elements\n");
			    printf("[3] Malloc for Multiple Elements 2\n");
				printLine(0);
			    printf("Other:\n");
			    printf("[4] Address / Dereferencing\n");
			    printf("[5] Same Address Pointers\n");
			    printf("[6] Swap Memory Contents\n");
				printLine(0);
				printf("[9] Previous Page\n");
				printf("[0] Return\n");
			    printLine(0);
		    	int choice;
				input(Int, "Enter choice: ", &choice);
				system("cls");
				printLine(0);
				switch (choice) {
					case 1:
						examplec1M1();
						printLine(0);
						break;
					case 2:
						examplec2M1();
						printLine(0);
						break;
					case 3:
						examplec3M1();
						printLine(0);
						break;
					case 4:
						exampled1M1();
						printLine(0);
						break;
					case 5:
						exampled2M1();
						printLine(0);
						break;
					case 6:
						exampled3M1();
						printLine(0);
						break;
					case 9:
						showMenuM1(1);
					case 0:
						showMenuM();	
						break;
					default:
						printf("Invalid choice.\n");
						waitEnter();
				}
				waitEnter();
				system("cls");
			}
			break;
		}
		default:
			exit(0);
	}
	

}

void showMenuM2() { //menu for midterm exercises subcategory 2
	system("cls");
    while(1) {
    	printLine(0);
		printf("Exercises on Pointers\n");
		printLine(0);
	    printf("[1] Pointer Initialization\n");
	    printf("[2] Set Value Using Pointers\n");
	    printf("[3] Sum/Add\n");
	    printf("[4] Get Sum and Average\n");
	    printf("[5] Print Float Array\n");
	    printf("[6] Print Double Array\n");
	    printf("[7] Print Float Array Reverse\n");
	    printf("[8] Print Double Array Reverse\n");
	    printf("[9] Dynamic Malloc Float Array\n");
	    printf("[10] Dynamic Malloc Double Array\n");	    
		printf("[0] Return\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	exercise1M2();
				printLine(0);
				break;
			case 2:
            	exercise2M2();
				printLine(0);
				break;
			case 3:
				exercise3M2();
				printLine(0);
				break;
			case 4:
				exercise4M2();
				printLine(0);
				break;
			case 5:
				exercise5M2();
				printLine(0);
				break;
			case 6:
				exercise6M2();
				printLine(0);
				break;
			case 7:
				exercise7M2();
				printLine(0);
				break;
			case 8:
				exercise8M2();
				printLine(0);
				break;
			case 9:
				exercise9M2();
				printLine(0);
				break;
			case 10:
				exercise10M2();
				printLine(0);
				break;
			case 0:
				showMenuM();
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
	waitEnter();
	system("cls");
	}
}

void showMenuF1() { //menu for finals subcategory 1
	system("cls");
    while(1) {
    	int choice;
    	printLine(0);
		printf("Examples on File Processing\n");
		printLine(0);
	    printf("[1] Read Characters From Text File\n");
	    printf("[2] User Specified Text File\n");
	    printf("[3] User Specified Text File (stdout)\n");
	    printf("[4] Copy Text to Another File\n");
	    printf("[5] Write Formatted Data to Text File\n");;	    
		printf("[0] Return\n");
	    printLine(0);
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch(choice) {
			case 1:
            	example1F1();
				printLine(0);
				break;
			case 2:
            	example2F1();
				printLine(0);
				break;
			case 3:
				example3F1();
				printLine(0);
				break;
			case 4:
				example4F1();
				printLine(0);
				break;
			case 5:
				example5F1();
				printLine(0);
				break;
			case 0:
				showMenuF();
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
		waitEnter();
		system("CLS");
	}
}


void showMenuF2() { //menu for finals subcategory 2
	system("cls");
    while(1) {
    	int choice;
    	printLine(0);
    	printf("Exercises on Recursion\n");
		printLine(0);
		printf("[1] Series 1\n");
		printf("[2] Series 2\n");
		printf("[3] Binary Traversal\n");
		printf("[4] Mystery\n");
		printf("[5] BLIP BLAP\n");
		printf("[6] Fibonacci\n");
		printf("[7] Ackermann\n");	    
		printf("[0] Return\n");
		printLine(0);
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	series1F2(5);
				printLine(0);
				break;
			case 2:
            	series2F2(5);
				printLine(0);
				break;
			case 3:
				example3F2();
				printLine(0);
				break;
			case 4:
				exercise1F2();
				printLine(0);
				break;
			case 5:
				exercise2F2();
				printLine(0);
				break;
			case 6:
				exercise3F2();
				printLine(0);
				break;
			case 7:
				exercise4F2();
				printLine(0);
				break;
			case 0:
				showMenuF();	
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
		
		waitEnter();
		system("cls");
	}
}

void showMenuF3() { //menu for finals subcategory 3
	system("cls");
    while(1) {
    	int choice;
    	printLine(0);
    	printf("File Processing Machine Problems 1-2\n");
		printLine(0);
		printf("[1] MP1 - Write A to Z to Text File\n");
		printf("[2] MP2 Read Text File\n");    
		printf("[0] Return\n");
		printLine(0);
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	MP1(5);
				printLine(0);
				break;
			case 2:
            	MP2(5);
				printLine(0);
				break;
			case 0:
				showMenuF();	
				break;
			default:
				printf("Invalid choice.\n");
				waitEnter();
		}
		
		waitEnter();
		system("cls");
	}
}

void showMenuF4() { //menu for finals subcategory 4
	system("cls");
    while(1) {
		printLine(0);
		printf("File Processing Machine Problems 3-4\n");
		printLine(0);
	    printf("[1] MP3 - Numbers n1 to n2\n");
	    printf("[2] MP4 - Read File\n");
		printf("[0] Return\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	Finals_MP3();
				printLine(0);
				break;
			case 2:
            	Finals_MP4();
				printLine(0);
				break;
			case 0:
				showMenuF();
				break;
			default:
				printColor(RED, "Invalid choice.\n");
				waitEnter();
		}
	waitEnter();
	system("cls");
	}
}

void showMenuF5() { //menu for finals subcategory 5
	system("cls");
	while(1) {
		printLine(0);
		printf("File Processing Activity - July 6\n");
		printLine(3);
	    printf("[1] FPVowel - Count number of vowels\n");
	    printf("[2] FPFileIdentical - Check if two files are identical\n");
		printf("[0] Return\n");
	    printLine(0);
    	int choice;
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	FPVowel();
				printLine(0);
				break;
			case 2:
            	FPFileIdentical();
				printLine(0);
				break;
			case 0:
				showMenuF();
				break;
			default:
				printColor(RED, "Invalid choice.\n");
				waitEnter();
		}
	waitEnter();
	system("cls");
	}
}