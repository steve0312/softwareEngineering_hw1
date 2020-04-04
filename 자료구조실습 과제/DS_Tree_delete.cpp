#include "Tree.hpp"
#include "TreeNode.hpp"
#include <iostream>

TreeNode* Tree::delete_Node(int data) {
	return delete_Node(this->rootnode, data);
}

TreeNode* Tree::delete_Node(TreeNode* curNode, int data) {
	// root가 비어있으면 0 반환
	if (curNode == NULL) return 0;
	// 삭제를 위한 체이싱 노드
	TreeNode* par = NULL;

	// 지우고자 하는 값을 찾을 때 까지 이동한다.
	while (curNode && curNode->getData() != data) {
		par = curNode;

		// search를 한줄로 줄인 코드 입니다.
		curNode = curNode->getData() < data ? curNode->getRight() : curNode->getLeft();
	}

	// curNode가 NULL일 때 --> 발견 못했을 때
	if (!curNode) return 0;
	
	// 찾은 노드가 단말노드 일 경우
	if (!curNode->getLeft() && !curNode->getRight()) {

		// 부모가 존재하는 경우 루트노드가 아닐때
		if (par)
		{
			if (par->getRight() == curNode) par->setRight(NULL);
			else par->setLeft(NULL);
		}
		// 루트 노드인 경우
		else rootnode = NULL;
	}

	// 서브 트리가 한쪽만 존재 하는 경우
	else if (!curNode->getLeft() || !curNode->getRight()) {
		// 서브트리의 루트를 찾아낸다.
		TreeNode* nextRoot = curNode->getLeft() ? curNode->getRight() : curNode->getLeft();

		// 루트노드가 아닌경우
		if (par) {
			if (par->getLeft() == curNode)
				par->setLeft(curNode);
			else
				par->setRight(curNode);
		}
		// 루트 노드인 경우 루트 노드로 대체한다.
		else
			par = nextRoot;
	}

	// 서브트리를 양쪽 다 가진경우
	else {
		
		// 왼쪽으로 한칸 이동한 노드를 찾는다. 
		TreeNode* maxNode = curNode->getLeft();
		// 삭제를 담당하기위해 추적하는 부모 노드
		TreeNode* parMaxNode = curNode;

		// 왼쪽 노드중 가장 큰 노드를 찾아낸다.
		while (maxNode->getRight()) {
			parMaxNode = maxNode;
			maxNode = maxNode->getRight();
		}

		// 바꿀 노드의 왼쪽 자식을 바꿀 노드의 부모와 연결시켜준다.
		parMaxNode->setRight(maxNode->getLeft());

		// 삭제할 노드의 왼쪽 노드가 바로 밑 노드인 경우는 왼쪽 자식 노드가 없어야 한다.
		maxNode->setLeft(curNode->getLeft() != maxNode ? curNode->getLeft() : NULL);
		// 기존 노드를 물려받는다.
		maxNode->setRight(curNode->getRight());
		
		// 루트노드인 경우
		if (!par) rootnode = maxNode;
		// 루트노드가 아니라면 탐색한 노드를 이어 붙인다.
		else if (par->getLeft() == curNode) par->setLeft(maxNode);
		else par->setRight(maxNode);
	}

	return curNode;
}