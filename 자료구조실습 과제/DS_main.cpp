#include "Tree.hpp"
#include <iostream>

using namespace std;

int main()
{
	Tree tree = Tree();
	tree.insert(50);
	tree.insert(25);
	tree.insert(75);
	tree.insert(100);
	tree.insert(30);
	tree.insert(10);
	tree.display();
	cout << endl;
	cout << "search 50 : " <<  tree.search_Node(50) << endl;
	cout << "search 15 : " << tree.search_Node(15) << endl;
	cout << tree.delete_Node(50) << endl;
	tree.display();
	cout << endl;
	cout << "search 50 : " << tree.search_Node(50) << endl;

	return 0;
}