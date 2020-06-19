#include "avl.h"

int main(void){
	AVL<int> tree;
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);

	tree.printInOrder();
	tree.printPreOrder();
	tree.printBreadthFirst();
}