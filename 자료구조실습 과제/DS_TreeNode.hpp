#ifndef __TREENODE_
#define __TREENODE_
class TreeNode {
public:
	TreeNode();
	TreeNode(int data);

	void setData(int data);
	void setLeft(TreeNode* left);
	void setRight(TreeNode* right);
	int getData ( void );
	TreeNode* getLeft ( void );
	TreeNode* getRight(void);

private:
	int data;
	TreeNode *left;
	TreeNode *right;
};
#endif