class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i =0;
        
        while(i<n && s[i] == ' ')i++;

        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        long long num = 0;  

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            if (num > (LLONG_MAX / 10)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }

            num = num * 10 + digit;

            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(num * sign);
    }
};