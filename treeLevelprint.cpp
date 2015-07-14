/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode *root) {
		
        vector<int> Res;
        if(!root) return Res;
        
        queue<TreeNode *> tmpQ;
        tmpQ.push(root);
        while(!tmpQ.empty()){
            TreeNode *tmpNode = tmpQ.front();
            tmpQ.pop();
            
            Res.push_back(tmpNode->val);
            if(tmpNode->left) tmpQ.push(tmpNode->left);
            if(tmpNode->right) tmpQ.push(tmpNode->right);
        }
       	return Res;
	}
};
