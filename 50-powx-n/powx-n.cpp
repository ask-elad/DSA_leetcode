class Solution {
public:
    double myPow(double x, int n) {
        double a = 1.0;
        long long N = n; 

        if (x == 0) return 0;  
        if (x == 1 || N == 0) return 1;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        while (N > 0) {
            if (N % 2 == 1) a *= x;
            x *= x;
            N /= 2;
        }

        return a;
    }
};
