/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。

解法：
	还是通过与或的方法，先求出单独的两个数的与或
    因为那两个数不相同，所以最后的结果肯定有一位是为1
    可以求出第一个为1的位， 然后用这个为把数组分为两部分进行与或
    
    每一部分得到的结果就是最最终的两个数了
*/

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int n =data.size();
        *num1 = 0;
        *num2 = 0;
        if(n<2) return;
        int res = data[0];
        int firstOne = 0;
        for(int i=1; i<n; i++) res ^= data[i];
        while((res & 0x1) == 0x0){
            firstOne++;
            res = res>>1;
        }
        for(int i=0; i<n; i++){
            if(((data[i]>>firstOne) & 0x1) == 0x1) *num1 ^= data[i];
            else *num2 ^= data[i];
        }
	}
};
