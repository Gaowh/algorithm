/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

题目没有要求是按顺序输出前K个数

这里用的方法是递归的快排划分，知道找到下标k-1

时间复杂度是 n(lgk)

还有另外的方法是堆排序的方法
*/

class Solution {
	void Swap(int &a, int &b){
        int tmp = a;
        a = b; 
        b = tmp;
    }
    int partition(vector<int> &in, int l, int r){
        int i = l-1;
        for(int j=l; j<r; j++){
            if(in[j] <= in[r]) Swap(in[++i], in[j]);    
        }
        Swap(in[++i], in[r]);
        return i;
    }
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		
        int n = input.size();
        vector<int> LeastK;
        if(n==0 || k>n || k==0) return LeastK;
        int key = partition(input, 0, n-1);
        while(key != k-1){
            if(key < k-1) key = partition(input, key+1, n-1);
            else key = partition(input, 0, key-1);
        }
        for(int i = 0; i<=key; i++){
            LeastK.push_back(input[i]);
        }
        return LeastK;
	}
};
