#include "Tree.hpp"
#include "TreeNode.hpp"

#include <iostream>

bool Tree::search_Node(int data) {
	return search_Node(this->rootnode, data);
}

bool Tree::search_Node(TreeNode* curNode, int data) {
	if (curNode == NULL) return false;

	// ã������ ���� ���� ���̸� true ��ȯ
	if (curNode->getData() == data) return true;
	// ���� ���� �����ͺ��� ������ ������ ���� �̵�
	else if (curNode->getData() < data) return search_Node(curNode->getRight(), data);
	// ���� ���� �����ͺ��� ũ�� ���� ���� �̵�
	return search_Node(curNode->getLeft(), data);
}