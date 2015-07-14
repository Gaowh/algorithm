/*
    全排列的递归方法:
        简单地说：就是第一个数分别以后面的数进行交换

        E=[1,2,3,4]
        perm(1,2,3,4) = [1,perm(2,3,4)] + [2, perm(1,3,4)]+ [3, perm(1,2,4)]+[4,perm(1,2,3)] ;
        
        然后依次递归(只列出perm(2,3,4)：
            perm(2,3,4) = [2, perm(3,4)] + [3,perm(2,4)] + [4,perm(2,3)]
                        = [2,3,4] + [2,4,3] +    [3,2,4]+[3,4,2] +  [4,2,3]+[4,3,2]
*/

class Solution {
     vector<vector<int> > perm;    
     void Swap(int &a, int &b){
         int tmp = a;
         a = b;
         b =tmp;
     }
     void permiterate(vector<int> &nums, int s, int n){
         if(s == n) perm.push_back(nums);
         else {
             for (int i=s; i<=n; i++){
                 Swap(nums[i], nums[s]);
                 permiterate(nums, s+1, n);
                 Swap(nums[i], nums[s]);
             }
         }
     }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        permiterate(nums, 0, nums.size()-1);
        return perm;
    }
};