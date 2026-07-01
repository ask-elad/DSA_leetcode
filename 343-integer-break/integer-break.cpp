class Solution {
public:
    long long rec(int n){
        if(n == 1 || n == 0) return 1;
        if(n == 2) return 2;

        long long ans1 = 1;
        long long ans2 = 1;
        ans1 = ans1 * 2 * rec(n - 2);
        ans2 = ans2 * 3 * rec(n - 3);

        return max(ans1, ans2);
    }
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        return rec(n);
    }
};