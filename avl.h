#include <iostream>
#include "arrqueue.h"

template <typename T>
class AVL{

	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		int height_;    //stores the height of the subtree
                        //that the node is root to.
		Node(const T& data=T{}, Node* left=nullptr, Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;
			height_=1;
		}
	};

	Node* root_;

	int height(Node* n) const {
		return (n)?n->height_:0;
	}
	int balance(Node* n) const{
		return height(n->right_)-height(n->left_);
	}
	void updateHeight(Node* n){
		int leftHeight=height(n->left_);
		int rightHeight=height(n->right_);
		n->height_ = 1 + ((leftHeight > rightHeight)?leftHeight:rightHeight);
	}
	void rotateLeft(Node*& APtr){
		Node* BPtr = APtr->right_;
		Node* YPtr = BPtr->left_;
		APtr->right_=YPtr;
		BPtr->left_=APtr;
		APtr=BPtr;
	}
	void rotateRight(Node*& BPtr){
		Node* APtr=BPtr->left_;
		Node* YPtr=APtr->right_;
		BPtr->left_=YPtr;
		APtr->right_=BPtr;
		BPtr=APtr;
	}

	//if subtree is empty, create new node for that subtree
	//otherwise, insert based on whether data is smaller
	//or bigger than the value in the root of the subtree
	void insert(Node*& subtreeroot,const T& data){
		if(subtreeroot==nullptr){
			subtreeroot=new Node(data);
		}
		else{
			if(data < subtreeroot->data_){
				insert(subtreeroot->left_,data);

			}
			else{
				insert(subtreeroot->right_,data);
			}
			int balanceCurrent = balance(subtreeroot);
			if(balanceCurrent >= 2){
				int balanceRight=balance(subtreeroot->right_);
				if(balanceRight == 1){
					rotateLeft(subtreeroot);
					updateHeight(subtreeroot->left_);
					updateHeight(subtreeroot);
				}
				else{
					rotateRight(subtreeroot->right_);
					rotateLeft(subtreeroot);
					updateHeight(subtreeroot->right_);
					updateHeight(subtreeroot->left_);
					updateHeight(subtreeroot);
				}
			}
			else if(balanceCurrent <= -2){
				int balanceLeft=balance(subtreeroot->right_);
				if(balanceLeft == -1){
					rotateRight(subtreeroot);
					updateHeight(subtreeroot->right_);
					updateHeight(subtreeroot);
				}
				else{
					rotateLeft(subtreeroot->left_);
					rotateRight(subtreeroot);
					updateHeight(subtreeroot->right_);
					updateHeight(subtreeroot->left_);
					updateHeight(subtreeroot);
				}

			}
		}
	}

	/* this function prints all the nodes in subtree from smallest to biggest*/
	void printInOrder(const Node* subtreeroot) const{
		if(subtreeroot!=nullptr){
			printInOrder(subtreeroot->left_);
			std::cout << subtreeroot->data_ << " ";
			printInOrder(subtreeroot->right_);
		}
	}

	/* this function prints all the nodes in preorder manner*/
	void printPreOrder(const Node* subtreeroot) const{
		if(subtreeroot!=nullptr){
			std::cout << subtreeroot->data_ << " ";
			printPreOrder(subtreeroot->left_);
			printPreOrder(subtreeroot->right_);
		}
	}

	/* this function prints all the nodes in postorder manner*/
	void printPostOrder(const Node* subtreeroot) const{
		if(subtreeroot!=nullptr){
			printPostOrder(subtreeroot->left_);
			printPostOrder(subtreeroot->right_);
			std::cout << subtreeroot->data_ << " ";
		}
	}
	void destroy(Node* subtreeroot){
		if(subtreeroot!=nullptr){
			destroy(subtreeroot->left_);
			destroy(subtreeroot->right_);
			delete subtreeroot;
		}
	}


public:
	//creates an empty AVL
	AVL(){
		root_=nullptr;
	}
	//insert data into the tree   
	void insert(const T& data){
		insert(root_,data);
	}

	//returns true if a node containing data is in the tree
	bool search(const T& data) const{
		Node* curr=root_;
		bool found=false;
		while(curr && !found){
			if(data == curr->data_){
				found =true;
			}
			else if (data < curr->data_){
				curr=curr->left_;
			}
			else{
				curr=curr->right_;
			}
		}
		return found;
	}

	//prints all the values in the tree
	void printInOrder() const{
		printInOrder(root_);
		std::cout << std::endl;		
	}
	//prints all the values in the tree
	void printPreOrder() const{
		printPreOrder(root_);
		std::cout << std::endl;		
	}
	//prints all the values in the tree
	void printPostOrder() const{
		printPostOrder(root_);
		std::cout << std::endl;		
	}

	//prints all the values in the tree
	void printBreadthFirst() const{
		if(root_){
			Queue<Node*> theQueue;
			theQueue.enqueue(root_);
			while(theQueue.isEmpty() == false){
				Node* curr=theQueue.front();
				theQueue.dequeue();
				std::cout << curr->data_ << " ";
				if(curr->left_)
					theQueue.enqueue(curr->left_);
				if(curr->right_)
					theQueue.enqueue(curr->right_);
			}
		}
		std::cout << std::endl;		

	}

	//destructor is a tree traversal.  Before you get rid of
	//current node you must first get rid of the children
	~AVL(){
		destroy(root_);
	}
};






