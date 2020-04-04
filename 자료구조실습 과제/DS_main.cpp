#include "Tree.hpp"
#include <iostream>

using namespace std;

int main()
{
	cout << "1번 사용자의 DS 과제 수정테스트" << endl;
	Tree tree = Tree();
	tree.insert(50);
	tree.insert(25);
	tree.insert(75);
	tree.insert(100);
	tree.insert(30);
	tree.insert(40);
	tree.insert(10);
	tree.display();
	cout << endl;
	cout << "search 75 : " <<  tree.search_Node(75) << endl;
	cout << "search 15 : " << tree.search_Node(15) << endl;
	cout << tree.delete_Node(75) << endl;
	tree.display();
	cout << endl;
	cout << "search 100 : " << tree.search_Node(100) << endl;

	cout << "2번 사용자의 DS 과제 수정테스트" << endl;

	return 0;
}