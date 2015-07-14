/*struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/*
	输入两颗数  ，  判断第二棵树是否是第一棵树的一个子结构
    这里所说的子结构是根据值来判断的
    
    在二叉树的操作中尽量用递归实现（如果没有强制要求的话，这样来更简洁）
*/
class Solution {
	
    bool isEqual(TreeNode *root1, TreeNode *root2){
       	if(!root2) return true;
       	if(!root1) return false;
        
        if(root1->val == root2->val){
            return isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
        }
        return false;
    }
    
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if(!pRoot1 || !pRoot2) return false;
        bool res;
        if(pRoot1->val == pRoot2->val){
            res = isEqual(pRoot1, pRoot2);
        }
        if(!res){
            res = HasSubtree(pRoot1->left, pRoot2);
        }
        if(!res){
            res = HasSubtree(pRoot1->right, pRoot2);
        }
        return res;
	}
};