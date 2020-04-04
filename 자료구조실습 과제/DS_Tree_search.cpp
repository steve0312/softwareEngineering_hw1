#include "Tree.hpp"
#include "TreeNode.hpp"

#include <iostream>

bool Tree::search_Node(int data) {
	return search_Node(this->rootnode, data);
}

bool Tree::search_Node(TreeNode* curNode, int data) {
	if (curNode == NULL) return false;

	// 찾으려는 값이 현재 값이면 true 반환
	if (curNode->getData() == data) return true;
	// 현재 값이 데이터보다 작으면 오른쪽 노드로 이동
	else if (curNode->getData() < data) return search_Node(curNode->getRight(), data);
	// 현재 값이 데이터보다 크면 왼쪽 노드로 이동
	return search_Node(curNode->getLeft(), data);
}