/*
 *     这道题是找出数组中出现超过了三分之一的数字
 *     另外一道题是寻找数组中超过了一半的数字
 *
 *     寻找超过了一半的数字时，每次从数组中去掉两个不同的数字
 *
 *     所以这道题应该每次去掉三个不同的数字 ，最后检查剩下的数字是否超过了三分之一就ok了
 * 
 *
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0, cnt2=0;
        int a, b;
        for(int i=0; i<nums.size(); i++){
            if(cnt1 == 0 || nums[i] == a){
                cnt1++;
                a = nums[i];
            }
            else if(cnt2 == 0 || nums[i] == b){
                cnt2++;
                b = nums[i];
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == a) cnt1++;
            else if(nums[i] == b) cnt2++;
        }
        vector<int> Res;
        if(cnt1 > nums.size()/3) Res.push_back(a);
        if(cnt2 > nums.size()/3) Res.push_back(b);
        return Res;
    }
};
