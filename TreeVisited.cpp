

/*

总结下二叉树的三种遍历方法： 前序遍历，中序遍历，后序遍历

首先是递归的遍历方法
*/

//先序遍历 递归方法
void  preOrderDfs(TreeNode * root){
    
    if(!root) return;
    cout<<root->val<<" "<<endl;

    if(root->left) 
	preOrderDfs(root->left);

    if(root->right)
	preOrderDfs(root->right);
}


// 先序遍历 非递归方法
void preOrder_re(TreeNode * root){
    
    stack<TreeNode *> stk;
    TreeNode * now = root;

    while(now || !stk.empty()){
	if(now){
	    cout<<now->val<<" "<<endl;
	    stk.push(now);
	    now = now->left;
	}
	else {
	    now = stk.top();
	    stk.pop();
	    now = now->right;
	}
    }
}

//中序遍历 递归方法
void inOrderDfs(TreeNode * root){
    
    if(!root) return;
    if(root->left)
        inOrderDfs(root->left);
    
    cout << root->val<<" "<<endl;
    
    if(root->right)
	inOrderDfs(root->right);
}

//中序遍历 非递归方法
void inOrder_re(TreeNode * root){
    
    stack<TreeNode * >stk;
    TreeNode * now = root;
    while(now || !stk.empty()){
	if(now){
	    stk.push(now);
	    now = now->left
	}
	else {
	    now = stk.top();
	    stk.pop();
	    cout<<now->val<<" "<<endl;
	    now = now->right;
	}
    }
}

//后序遍历 递归方法
void postOrderDfs(TreeNode * root){
    if(!root) return;

    if(root->left)
	postOrderDfs(root->left);
    if(root->right)
	postOrderDfs(root->right);
    cout<<root->val<<" "<<endl;
}

/*
 在所有的非递归遍历方法中，后续遍历的非递归方法稍微难于前序和中序的方法

 在输出一个节点的值时，必须判断该节点的左右孩子是否已经访问了

    1、左孩子其实不用判断，因为每次因为每访问一个节点时，已经用while将该
	节点左边的孩子都放进了栈内，所以在某个节点出栈时，该节点的左孩子中
	的所有节点都已经出栈（也就是都被访问过了）

    2、判断右孩子是否被访问过有两个方面要考虑
	1）该节点没有右孩子
	2）该节点的右孩子已经访问
	    那么怎么判断一个节点的右节点是否已经访问了呢？
	    我们在每次输出一个节点时记录该节点
	    在到达下一个节点时判断之前记录的节点是否是当前节点的右节点
	    如果是的话就证明该节点的右子树已经遍历完成
 
	    1
           / \
	  2   3
	 / \ / \
	   
	    如上图所示，遍历完节点3时， 记录节点3是上一个输出的节点
	    这时候节点1的左右孩子都遍历完了，当遍历到节点1时，发现节点1存在右孩子
	    但是上一个上一个访问的节点是1的右孩子3，所有证明1的右孩子已经访问完了
	    这时候就可以将1节点输出来了。
	    
	    如果当前处理的节点是1，如果上一个输出的节点是2，证明这时候节点1的左子树访问完了
	    接下来应该访问右子树，而不是输出1节点
 */

//后序遍历  非递归方法
void postOrder_re(TreeNode * root){
    
    stack<TreeNode * > stk;
    TreeNode *now = root;
    TreeNode *pre = nullptr;

    while(now || !stk.empty()){
	
	if(now){
	    stk.push(now);
	    now = now->left;
	}

	else {
	    TreeNode *topstk = stk.top();
	    if(topstk->right && topstk->right != pre){ //存在右子树，并且右子树没有被访问
		now = topstk->right;
	    }

	    else{   
		cout<<topstk->val<<" "<<endl; //没有右子树或者是右子树已经被访问了
		pre = topstk;
		stk.pop();
	    }
	}
    }

}
