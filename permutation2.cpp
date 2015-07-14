/*
题目描述

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。按字典序打印出该字符串中字符的所有排列。

这个版本并虽然输出了所有的全排列，但是没有按照正确的顺序输出来

看题目的意思是要求按照排列的大小输出来

class Solution {
	
    vector<string> Perm;
    void Swap(char &a ,char &b){
        char tmp = a;
        a = b;
        b =tmp;
    }
    void iterPerm(string &str, int s ,int n){
        if(s == n) Perm.push_back(str);
        else {
            for (int i=s; i<=n ;i++){
                if(i!=s) {
                    while((str[i] == str[s]) && i<=n) i++;
                    if(i>n) break;
                }
                Swap(str[i], str[s]);
                iterPerm(str, s+1, n);
                Swap(str[i], str[s]);
            }
        }
    }
public:
	vector<string> Permutation(string str) {
		iterPerm(str, 0 ,str.size()-1);
        return Perm;
	}
};*/
class Solution {
	
    vector<string> Perm;
    void iterPerm(string &str, int s ,int n){
        if(s == n) Perm.push_back(str);
        else {
            for (int i=s; i<=n ;i++){
                if(i!=s) {
                    while((str[i] == str[s]) && i<=n) i++;
                    if(i>n) break;
                }
                char tmp = str[i];
                str.erase(i,1);
                str.insert(str.begin()+s, tmp);
                iterPerm(str, s+1, n);
                str.erase(s,1);
                str.insert(str.begin()+i, tmp);
            }
        }
    }
public:
	vector<string> Permutation(string str) {
		iterPerm(str, 0 ,str.size()-1);
        return Perm;
	}
};