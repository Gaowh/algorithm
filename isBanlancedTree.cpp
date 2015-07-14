/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

对于每一个节点， 保存它的左右孩子的高度，避免出现重复的搜索

*/
class Solution {
	bool help(TreeNode *root , int &deep){
        if(!root){
            deep = 0;
            return true;
        }
        int leftd, rightd; // 用于保存两个孩子的高度
        if(help(root->left, leftd) && help(root->right, rightd)){
            int diff = abs(leftd - rightd);
            if(diff <= 1) {
                deep = 1+max(leftd, rightd);//设置节点的高度
                return true; //当前节点是平衡的
            }
        }
        return false;
    }
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int deep = 0;
        return help(pRoot, deep);
	}
};
