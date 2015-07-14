输入一个整数数组，实现一个函数来调整该数组中数字的顺序
使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分
并保证奇数和奇数，偶数和偶数之间的相对位置不变。

分析：如果没有要求相对位置不变，则采用快排的划分方式最快，也能省空间
      但是要求了相对位置不变，则用另外的方法：
        1、采用插入排序的方式，时间复杂度为O(n2)，如下所示
        2、采用空间换时间的方式，将奇偶存放在另外的辅助数组内，时间复杂度为O(n)，空间复杂度为O(n)

class Solution {
public:
    void reOrderArray(vector<int> &array) {
         
        int n=array.size();
        for(int i=0; i<n; i++){
             
            if(array[i] & 1){
                int tmp = array[i];
                int j=i;
                while(!(array[j-1] & 1) && j>0){
                    array[j] = array[j-1];
                    j--;
                }
                array[j] = tmp;
            }
        }
    }
};
