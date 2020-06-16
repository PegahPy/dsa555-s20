#include "bst.h"

int main(void){
	BST<int> tree;
	tree.insert(15);
	tree.insert(5);
	tree.insert(25);
	tree.insert(10);
	tree.insert(1);
	tree.insert(28);

	tree.printInOrder();
	tree.printPreOrder();
	tree.printBreadthFirst();
}