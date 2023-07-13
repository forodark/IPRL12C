#include <stdio.h>
#include <stdlib.h>
#include "../glencrypt.h"


void series1F2();
void series2F2();
void example3F2();
void exercise1F2();
void exercise2F2();
void exercise3F2();
void exercise4F2();

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void f2_series1() {
	series1F2(5);
}

void f2_series2() {
	series2F2(5);
}

void series1F2(int n) {
	if (n > 0) {
		printf("n = %d\n", n);
		series1F2(n - 1);
	}
}


void series2F2(int n) {
	if (n > 0) {
		series2F2(n - 1);
		printf("n = %d\n", n);
	}
}


void visitF2(struct node *p) {
	// The visitF2 operation can be any operation, depending on the application.
	// In this example, we simply print the value of the data.
	printf("data = %d\n", p->data);
}

void preOrderF2(struct node *p) {
	if (p != NULL) {
		visitF2(p);
		preOrderF2(p->left);
		preOrderF2(p->right);
	}
}

void inOrderF2(struct node *p) {
	if (p != NULL) {
		inOrderF2(p->left);
		visitF2(p);
		inOrderF2(p->right);
	}
}

void postOrderF2(struct node *p) {
	if (p != NULL) {
		postOrderF2(p->left);
		postOrderF2(p->right);
		visitF2(p);
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

void example3F2() {
	struct node* root = createTree();

	printf("Preorder:\n");
	preOrderF2(root);

	printf("\nInorder:\n");
	inOrderF2(root);

	printf("\nPostorder:\n");
	postOrderF2(root);
}

int mysteryF2(int x, int y) {
    if (y == 0)
        return x;
    else
        return mysteryF2(y, x % y);
}

void exercise1F2() {
    printf("mystery(10, 25) = %d\n", mysteryF2(10, 25));
}

void BLIPF2(int n) {
    if (n != 0) {
        printf("BLIP = %d\n", n);
        BLIPF2(n - 1);
    }
}

void BLAPF2(int n) {
    if (n != 0) {
        BLIPF2(n);
        BLAPF2(n - 1);
    }
}

void exercise2F2() {
    BLAPF2(4);
}

int fibonacciF2(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return fibonacciF2(n - 1) + fibonacciF2(n - 2);
}

void exercise3F2() {
    int n = 6;
    int result = fibonacciF2(n);
    printf("fibonacci(%d) = %d\n", n, result);
}

int ackermannF2(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ackermannF2(m - 1, 1);
    else
        return ackermannF2(m - 1, ackermannF2(m, n - 1));
}

void exercise4F2() {
    printf("ackermann(0, 10) = %d\n", ackermannF2(0, 10));

    printf("ackermann(1, 2) = %d\n", ackermannF2(1, 2));

    printf("ackermann(2, 1) = %d\n", ackermannF2(2, 1));

    printf("ackermann(3, 0) = %d\n", ackermannF2(3, 0));
}

