          /|
         / |          
     (m)/  |
       /   |
      /    |
     /     |
    /(l)   |
	   |
	   |     /(r)
	   |    /
	   |   /(m)
	   |  /
	   | /
	   |/
	   
	思想如上图， 每次求mid时可能出现的两种情况
	分两种情况讨论：
		1）当target大于mid的值
			1、当mid出现在右边且target大于最右边的值
			2、出去1中的情况
			
		2）当target小于mid的值
			1、当mid出现在左边且target 小于 最左边的值
			2、除去1中的另外情况
		3）target == mid 时直接返回
		
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return -1;
        
        int l = 0, r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
           
            if(target > nums[mid]){
                if(nums[mid] < nums[r] && target > nums[r])
                    r = mid-1;
                else l = mid+1;
            }
            else if(target < nums[mid]){
                if(nums[mid] > nums[r] && target < nums[l])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }  
        return -1;
    }
};
