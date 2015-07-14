/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
输入一个二叉树，重构起镜像二叉树

方法:
	递归的交换每个节点的左右节点，知道节点不为nullptr

*/
class Solution {
	void SwapVal(TreeNode *node){
            TreeNode * tmp = node->left;
            node->left = node->right;
            node->right = tmp;
    }
public:
	void Mirror(TreeNode *pRoot) {
		if(!pRoot) return;
        
        SwapVal(pRoot);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
	}
};