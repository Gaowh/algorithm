/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	TreeNode *help(vector<int> &pre,int ps, int pe, vector<int> & ino, int is,int ie){
		TreeNode *node = new TreeNode(pre[ps]);
		if( pe==ps ) return node;
		int i = is;
		while(ino[i] != pre[ps]) i++;
		if(i != is)   node->left = help(pre,ps+1,ps+i-is, ino, is, i-1);
		if(i != ie)	  node->right = help(pre, ps+i+1-is, pe, ino, i+1, ie );
		return node;
	}
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode * head;
        if(preorder.size()==0) return nullptr;
    	head = help(preorder,0,preorder.size()-1, inorder,0, inorder.size()-1);
    	return head;
    }
};
