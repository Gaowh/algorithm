/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。没有找到输出为0。

如果条件限制了时候输入必须有超过一半的值，则可以不进行后面的检查
如果输入有不符合条件的情况，则在最后必须检查答案是否有效
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		
        if(numbers.size() == 0) return 0;
        int count = 0, i=0, j=0;
        while(j<numbers.size()){
            if(numbers[i] == numbers[j]) count++;
            else count--;
            j++;
            if (count == 0) i=j;
        }
        count=0;
        for(j=0; j<numbers.size(); j++){
            if(numbers[j] == numbers[i]) count++;
        }
        if(count < numbers.size()/2) return 0;
        return numbers[i];
	}
};
