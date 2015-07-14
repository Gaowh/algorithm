题目描述

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。

当出现特殊情况时，我们还是可以利用二分查找的方法来解决该问题：
	下面的两个股挨着的while，我们可以直接跳过那些和mid相等的元素
	再下面的两个if判断，只处理最简单的情况，这是l, r, mid的元素值已经不相等了
	
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		
        int n = rotateArray.size();
        if(n==0) return 0;
        
        int l = 0, r = n-1;
        while(l<=r){
            
            if(l==r)
                return rotateArray[l];
            int mid = (l+r)/2;
            while((rotateArray[mid] == rotateArray[r]) && r > mid) r--;
            while((rotateArray[mid] == rotateArray[l]) && l < mid ) l++;
          	
            if(rotateArray[mid] < rotateArray[r]){
                r =mid;
            }
            else if (rotateArray[mid] > rotateArray[r]){
                l = mid+1;
            }
        }
	}
};