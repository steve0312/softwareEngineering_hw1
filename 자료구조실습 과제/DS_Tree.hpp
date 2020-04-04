
#ifndef TREE_H 
#define TREE_H 
#include "TreeNode.hpp" 
#include <list>

class Tree {
public:
	Tree();
	Tree(int data);
	void insert(int data);
	void display();

	std::list <int> myList;
	// list for test

	//
	bool search_Node(int data);
	TreeNode* delete_Node(int data);
	//
private:
	void display(TreeNode *curNode);
	TreeNode *rootnode;

	//
	bool search_Node(TreeNode *curNode, int data);
	TreeNode* delete_Node(TreeNode *curNode, int data);
	//
};
#endif