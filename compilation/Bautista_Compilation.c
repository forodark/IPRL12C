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

#include "./midterm/M1.c"
#include "./midterm/M2.c"
#include "./midterm/M3.c"

#include "./finals/F1.c"
#include "./finals/F2.c"
#include "./finals/F3.c"
#include "./finals/F4.c"
#include "./finals/F5.c"
#include "./finals/Bautista_FPQuiz.c"

void showMenuMain();
void showMenuP();
void showMenuM();
void showMenuF();
void showMenuP1();
void showMenuP2();
void showMenuM1();
void showMenuM2();
void showMenuM3();
void showMenuF1();
void showMenuF2();
void showMenuF3();
void showMenuF4();
void showMenuF5();

//All external programs
void LRT() {runProgram("prelim/LRT/", "Bautista_LRT.exe");}
void ATMv4() {runProgram("midterm/ATMv4/", "Bautista_ATMv4.exe");}
void ATMv7() {runProgram("finals/ATMv7.2/", "Bautista_ATMv7.2.exe");}


//I updated all the names in the menus so that its more descriptive of the functionality

int main() { //main function only calls the main menu, the main loop is located there
	showMenuMain();
	exitProgram();
	return 0;
}

void showMenuMain() {//main menu contains the main screen where you can branch out from
	menu main_menu[] = {
		{"Prelim", showMenuP},
		{"Midterm", showMenuM},
		{"Finals", showMenuF},
		END_MENU
	};

	showMenu("Machine Exercise Compilation\nby Glen Angelo Bautista", main_menu);
}

void showMenuP() { //menu for prelim exercises
	menu prelim_menu[] = {
		{"1D Arrays", showMenuP1},
		{"2D Arrays", showMenuP2},
		{"ME1 - Sum/Product", ME1},
		{"ME2 - Charge Calculator", ME2},
		{"LRT Fare Calculator", LRT},
		END_MENU
	};

	showMenu("Prelim Machine Exercises", prelim_menu);
}

void showMenuM() { //menu for midterm exercises
	menu midterm_menu[] = {
		{"Pointers Examples", showMenuM1},
		{"Pointers Exercises", showMenuM2},
		{"Structures Examples", showMenuM3},
		{"ATMv4 (Structures)", ATMv4},
		END_MENU
	};

	showMenu("Midterm Machine Exercises", midterm_menu);
}


void showMenuF() { //menu for finals exercises
	menu finals_menu[] = {
		{"File Processing", showMenuF1},
		{"Recursion", showMenuF2},
		{"File Processing Machine Problems 1-2", showMenuF3},
		{"File Processing Quiz", FPQuiz},
		{"File Processing Machine Problems 3-4", showMenuF4},
		{"File Processing Activity - July 6", showMenuF5},
		{"ATMv7.2 (File-Based)", ATMv7},
		END_MENU
	};

	showMenu("Finals Machine Exercises", finals_menu);
}

void showMenuP1() { //menu for prelim exercises subcategory 1
	menu prelims_submenu_1[] = {
		{"Initialize Array", exercise1P1},
		{"Initialize Custom Array Size", exercise2P1},
		{"Get Min Value", exercise3P1},
		{"Sum of Array", exercise4P1},
		{"Count Negative Numbers", exercise5P1},
		{"Test if Value Exists", exercise6P1},
		{"Copy Array", exercise7P1},
		{"Copy Array Reverse Order", exercise8P1},
		{"Test if Arrays are Equal", exercise9P1},
		END_MENU
	};

	showMenu("Exercises on 1D Array", prelims_submenu_1);
}

void showMenuP2() { //menu for prelim exercises subcategory 2
	menu prelims_submenu_2[] = {
		{"Initializing 2D Array", exercise1P2},
		{"Input Values", exercise2P2},
		{"Print 2D Array", exercise3P2},
		{"Count Negative Numbers", exercise4P2},
		{"Print Diagonal", exercise5P2},
		{"Sum of Row", exercise6P2},
		{"Sum of Column", exercise7P2},
		{"Add 2D Arrays", exercise8P2},
		END_MENU
	};

	showMenu("Exercises on 2D Array", prelims_submenu_2);
}



void showMenuM1() { //menu for midterm exercises subcategory 1, this one has two pages
	page_menu midterm_submenu_1[] = {
		{ (menu[]) {
			{"Pointers:", SUBTITLE},
			{"Array Elements w/ Pointers", example1M1},
			{"Array Elements w/ Pointers 2", example2M1},
			{"Array Elements w/ Pointers Reverse", example3M1},
			{"Array Elements w/o *pa", example4M1},
			{"Pointer Arithmetic", SUBTITLE},
			{"Incrementing Pointers", exampleb1M1},
			{"Incrementing Pointers 2", exampleb2M1},
			{"Incrementing Pointers w/ Loop", exampleb3M1},
			END_MENU
		}},
		{(menu[]) {
			{"Memory Allocation:", SUBTITLE},
			{"Dynamic Memory Allocation", examplec1M1},
			{"Malloc for Multiple Elements", examplec2M1},
			{"Malloc for Multiple Elements 2", examplec3M1},
			{"Other:", SUBTITLE},
			{"Address / Dereferencing", exampled1M1},
			{"Same Address Pointers", exampled2M1},
			{"Swap Memory Contents", exampled3M1},
			END_MENU
		}},
		END_PAGE_MENU
	};
	showPageMenu("Midterm Pointer Examples", midterm_submenu_1);
}

void showMenuM2() { //menu for midterm exercises subcategory 2

	menu midterms_submenu_2[] = {
		{"Pointer Initialization", exercise1M2},
		{"Set Value Using Pointers", exercise2M2},
		{"Sum/Add", exercise3M2},
		{"Get Sum and Average", exercise4M2},
		{"Print Float Array", exercise5M2},
		{"Print Double Array", exercise6M2},
		{"Print Float Array Reverse", exercise7M2},
		{"Print Double Array Reverse", exercise8M2},
		{"Dynamic Malloc Float Array", exercise9M2},
		{"Dynamic Malloc Double Array", exercise10M2},
		END_MENU
	};

	showMenu("Exercises on Pointers", midterms_submenu_2);
}


void showMenuM3() {// menu for m3
	menu midterms_submenu_3[] = {
		{"Point Structure (Direct)", M3example1},
		{"Student Structure (Direct)", M3example2},
		{"Point Structure (Template)", M3example3},
		{"Student Structure (Template)", M3example4},
		END_MENU
	};

	showMenu("Structures Examples", midterms_submenu_3);
}

void showMenuF1() { //menu for finals subcategory 1
	menu finals_submenu_1[] = {
		{"Read Characters From Text File", example1F1},
		{"User Specified Text File", example2F1},
		{"User Specified Text File (stdout)", example3F1},
		{"Copy Text to Another File", example4F1},
		{"Write Formatted Data to Text File", example5F1},
		END_MENU
	};
	showMenu("File Processing Exercises", finals_submenu_1);
}

void showMenuF2() { //menu for finals subcategory 2
	menu finals_submenu_2[] = {
		{"Series 1", f2_series1},
		{"Series 2", f2_series2},
		{"Binary Traversal", example3F2},
		{"Mystery", exercise1F2},
		{"BLIP BLAP", exercise2F2},
		{"Fibonacci", exercise3F2},
		{"Ackermann", exercise4F2},
		END_MENU
	};
	showMenu("Exercises on Recursion", finals_submenu_2);
}

void showMenuF3() { //menu for finals subcategory 3
	menu finals_submenu_3[] = {
		{"MP1 - Write A to Z to Text File", MP1},
		{"MP2 Read Text File", MP2},
		END_MENU
	};
	showMenu("File Processing Machine Problems 1-2", finals_submenu_3);
}

void showMenuF4() { //menu for finals subcategory 4
	menu finals_submenu_4[] = {
		{"MP3 - Numbers n1 to n2", Finals_MP3},
		{"MP4 - Read File", Finals_MP4},
		END_MENU
	};
	showMenu("File Processing Machine Problems 3-4", finals_submenu_4);
}

void showMenuF5() { //menu for finals subcategory 5
	menu finals_submenu_5[] = {
		{"FPVowel - Count number of vowels", FPVowel},
		{"FPFileIdentical - Check if two files are identical", FPFileIdentical},
		END_MENU
	};
	showMenu("File Processing Activity - July 6", finals_submenu_5);
}