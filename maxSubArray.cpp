/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？

其实不管数组中是否含有负数都不影响最大字数组的求解结果。
每次记录最大的连续最长的字段和
当某一个段的结果小于0时则丢弃掉就ok了

*/

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int n = array.size();
        if(n == 0) return 0;
        int Res = -0x7fffffff,tmp = 0;
       	for(int i=0; i<n; i++){
            tmp += array[i];
            if(tmp > Res) Res =tmp;
            else if(tmp < 0)
                	tmp = 0;
        }
        return Res;
	}
};
