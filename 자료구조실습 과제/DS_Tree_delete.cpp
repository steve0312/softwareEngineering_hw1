#include "Tree.hpp"
#include "TreeNode.hpp"
#include <iostream>

TreeNode* Tree::delete_Node(int data) {
	return delete_Node(this->rootnode, data);
}

TreeNode* Tree::delete_Node(TreeNode* curNode, int data) {
	// root�� ��������� 0 ��ȯ
	if (curNode == NULL) return 0;
	// ������ ���� ü�̽� ���
	TreeNode* par = NULL;

	// ������� �ϴ� ���� ã�� �� ���� �̵��Ѵ�.
	while (curNode && curNode->getData() != data) {
		par = curNode;

		// search�� ���ٷ� ���� �ڵ� �Դϴ�.
		curNode = curNode->getData() < data ? curNode->getRight() : curNode->getLeft();
	}

	// curNode�� NULL�� �� --> �߰� ������ ��
	if (!curNode) return 0;
	
	// ã�� ��尡 �ܸ���� �� ���
	if (!curNode->getLeft() && !curNode->getRight()) {

		// �θ� �����ϴ� ��� ��Ʈ��尡 �ƴҶ�
		if (par)
		{
			if (par->getRight() == curNode) par->setRight(NULL);
			else par->setLeft(NULL);
		}
		// ��Ʈ ����� ���
		else rootnode = NULL;
	}

	// ���� Ʈ���� ���ʸ� ���� �ϴ� ���
	else if (!curNode->getLeft() || !curNode->getRight()) {
		// ����Ʈ���� ��Ʈ�� ã�Ƴ���.
		TreeNode* nextRoot = curNode->getLeft() ? curNode->getRight() : curNode->getLeft();

		// ��Ʈ��尡 �ƴѰ��
		if (par) {
			if (par->getLeft() == curNode)
				par->setLeft(curNode);
			else
				par->setRight(curNode);
		}
		// ��Ʈ ����� ��� ��Ʈ ���� ��ü�Ѵ�.
		else
			par = nextRoot;
	}

	// ����Ʈ���� ���� �� �������
	else {
		
		// �������� ��ĭ �̵��� ��带 ã�´�. 
		TreeNode* maxNode = curNode->getLeft();
		// ������ ����ϱ����� �����ϴ� �θ� ���
		TreeNode* parMaxNode = curNode;

		// ���� ����� ���� ū ��带 ã�Ƴ���.
		while (maxNode->getRight()) {
			parMaxNode = maxNode;
			maxNode = maxNode->getRight();
		}

		// �ٲ� ����� ���� �ڽ��� �ٲ� ����� �θ�� ��������ش�.
		parMaxNode->setRight(maxNode->getLeft());

		// ������ ����� ���� ��尡 �ٷ� �� ����� ���� ���� �ڽ� ��尡 ����� �Ѵ�.
		maxNode->setLeft(curNode->getLeft() != maxNode ? curNode->getLeft() : NULL);
		// ���� ��带 �����޴´�.
		maxNode->setRight(curNode->getRight());
		
		// ��Ʈ����� ���
		if (!par) rootnode = maxNode;
		// ��Ʈ��尡 �ƴ϶�� Ž���� ��带 �̾� ���δ�.
		else if (par->getLeft() == curNode) par->setLeft(maxNode);
		else par->setRight(maxNode);
	}

	return curNode;
}