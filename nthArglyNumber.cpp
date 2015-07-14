/*

题目描述
把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

解法：
如下

*/

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if(index <= 0) return 0;
        int m2 = 0, m3 = 0, m5 = 0;
        int nowIndex = 1;
        int *argly = new int[index];
        argly[0] = 1;
        while(nowIndex < index){
            argly[nowIndex] = min(min(argly[m2]*2, argly[m3]*3), argly[m5]*5);
            while(argly[m2]*2 <= argly[nowIndex]) m2++;
            while(argly[m3]*3 <= argly[nowIndex]) m3++;
            while(argly[m5]*5 <= argly[nowIndex]) m5++;
            nowIndex++;
        }
        return argly[nowIndex-1];
	}
};
