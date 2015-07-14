class Solution {
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		int n = pushV.size();
        	int m = popV.size();
        	if( m!=n) return false;
		if( m == 0) return true;
        	stack<int> stk;
        	int pop = 0;
        	for(int i=0; i < n; i++){
            		while(!stk.empty() && stk.top() == popV[pop]){
                		stk.pop();
                		pop++;
            		}
            		if(i<n) stk.push(pushV[i]);
        	}
        	if(stk.empty()) return true;
        	return false;
	}
};
