/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。 

解答：
其实只要将数组按照字符串的大小排序然后再输出就ok了

*/

class Solution {
	
    static bool cmp(const int &a, const int &b){
        string str1 = to_string(a);
        string str2 = to_string(b);
        return (str1+str2)<(str2+str1);
    }
public:
	string PrintMinNumber(vector<int> numbers) {
		int n = numbers.size();
        sort(numbers.begin(), numbers.end(), cmp);
        string minNumbers;
        for(int i=0; i<n; i++){
            minNumbers += to_string(numbers[i]);
        }
        return minNumbers;
	}
};
