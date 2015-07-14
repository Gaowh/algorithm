


class Solution {
	
    double help(double base, unsigned int exp){
        if(exp == 0) return 1.0;
        if(exp == 1) return base;
        
        double res = help(base, exp>>1);
        res *= res;
        
        if(exp & 1){
            res *=base;
        }
        return res;
    }
public:
	double Power(double base, int exponent) {
		if(base == 0) return 0;
        
        unsigned int exp = exponent > 0? exponent: -exponent;
        
        double res = help(base, exp);
        res = exponent > 0? (res): (1.0/res);
        return res;
	}
};
