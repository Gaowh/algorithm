/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。
______________________________________________
|			      |                  |        |
 small than root  | large than root  |  root  |
|_________________|__________________|________|
*/

class Solution {
	bool isPostorder(const vector<int> &v, int l , int r){
        
        if( l==r || l+1 == r) return true;
        
        int root = v[r], i=l, mid;
        
        while(i<r && v[i]<root) i++;
        mid  = i;
        
        while(i < r && v[i] > root) i++;
        if(i != r) return false;
        
        if(mid == r || mid == l) return isPostorder(v, l ,r-1);
        else  return (isPostorder(v, l, mid-1) && (isPostorder(v, mid, r-1)) );

   }
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.size() == 0) return false;
        else return isPostorder(sequence, 0, sequence.size()-1);
	}
};
