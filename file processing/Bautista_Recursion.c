#include <stdio.h>
#include <stdlib.h>
#include "glencrypt.h"

void showMenu();
void series1();
void series2();
void example3();
void exercise1();
void exercise2();
void exercise3();
void exercise4();

struct node {
  int data;
  struct node *left;
  struct node *right;
};

int main() {
	showMenu();
	return 0;
}


void showMenu() {
    while(1) {
    	int choice;
    	printf("Exercises on Recursion\n");
		printLine(0);
		printf("[1] Example 1: Series 1\n");
		printf("[2] Example 2: Series 2\n");
		printf("[3] Example 3: Binary Traversal\n");
		printf("[4] Exercise 1: Mystery\n");
		printf("[5] Exercise 2: BLIP BLAP\n");
		printf("[6] Exercise 3: Fibonacci\n");
		printf("[7] Exercise 4: Ackermann\n");	    
		printf("[0] Exit\n");
		printLine(0);
		input(Int, "Enter choice: ", &choice);
		printLine(0);
		switch (choice) {
			case 1:
            	series1(5);
				printLine(0);
				break;
			case 2:
            	series2(5);
				printLine(0);
				break;
			case 3:
				example3();
				printLine(0);
				break;
			case 4:
				exercise1();
				printLine(0);
				break;
			case 5:
				exercise2();
				printLine(0);
				break;
			case 6:
				exercise3();
				printLine(0);
				break;
			case 7:
				exercise4();
				printLine(0);
				break;
			case 0:
				printf("Exiting Program...\n");
				exit (0);	
				break;
			default:
				printf("Invalid choice.\n");
		}
		
		waitEnter();
		system("cls");
	}
}

void series1(int n) {
	if (n > 0) {
		printf("n = %d\n", n);
		series1(n - 1);
	}
}


void series2(int n) {
	if (n > 0) {
		series2(n - 1);
		printf("n = %d\n", n);
	}
}


void visit(struct node *p) {
	// The visit operation can be any operation, depending on the application.
	// In this example, we simply print the value of the data.
	printf("data = %d\n", p->data);
}

void preOrder(struct node *p) {
	if (p != NULL) {
		visit(p);
		preOrder(p->left);
		preOrder(p->right);
	}
}

void inOrder(struct node *p) {
	if (p != NULL) {
		inOrder(p->left);
		visit(p);
		inOrder(p->right);
	}
}

void postOrder(struct node *p) {
	if (p != NULL) {
		postOrder(p->left);
		postOrder(p->right);
		visit(p);
	}
}

struct node* createNode(int data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

struct node* createTree() {
	struct node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	return root;
}

void example3() {
	struct node* root = createTree();

	printf("Preorder:\n");
	preOrder(root);

	printf("\nInorder:\n");
	inOrder(root);

	printf("\nPostorder:\n");
	postOrder(root);
}

int mystery(int x, int y) {
    if (y == 0)
        return x;
    else
        return mystery(y, x % y);
}

void exercise1() {
    printf("mystery(10, 25) = %d\n", mystery(10, 25));
}

void BLIP(int n) {
    if (n != 0) {
        printf("BLIP = %d\n", n);
        BLIP(n - 1);
    }
}

void BLAP(int n) {
    if (n != 0) {
        BLIP(n);
        BLAP(n - 1);
    }
}

void exercise2() {
    BLAP(4);
}

int fibonacci(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void exercise3() {
    int n = 6;
    int result = fibonacci(n);
    printf("fibonacci(%d) = %d\n", n, result);
}

int ackermann(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ackermann(m - 1, 1);
    else
        return ackermann(m - 1, ackermann(m, n - 1));
}

void exercise4() {
    printf("ackermann(0, 10) = %d\n", ackermann(0, 10));

    printf("ackermann(1, 2) = %d\n", ackermann(1, 2));

    printf("ackermann(2, 1) = %d\n", ackermann(2, 1));

    printf("ackermann(3, 0) = %d\n", ackermann(3, 0));
}

