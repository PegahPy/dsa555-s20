#include <iostream>
#include "arrqueue.h"

template <typename T>
class BST{

	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		Node(const T& data=T{}, Node* left=nullptr, Node* right=nullptr){
			data_=data;
			left_=left;
			right_=right;
		}
	};

	Node* root_;
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

	//if subtree is empty, create new node for that subtree
	//otherwise, insert based on whether data is smaller
	//or bigger than the value in the root of the subtree
	void insert(subtreeroot,data){

	}
public:
	//creates an empty BST
	BST(){
		root_=nullptr;
	}
	//insert data into the tree   
	void insert(const T& data){

	}
	//inserts data into the tree
	void insertIterative(const T& data){
		if(root_==nullptr){
			root_= new Node(data);
		}
		else{
			bool inserted=false;
			Node* curr=root_;
			while(!inserted){
				if(data < curr->data_){
					//left
					if(curr->left_==nullptr){
						curr->left_=new Node(data);
						inserted=true;
					}
					else{
						curr=curr->left_;
					}
				}
				else{
					if(curr->right_==nullptr){
						curr->right_=new Node(data);
						inserted=true;
					}
					else{
						curr=curr->right_;
					}
				}
			}
		}
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
	~BST(){
		destroy(root_);
	}
};






