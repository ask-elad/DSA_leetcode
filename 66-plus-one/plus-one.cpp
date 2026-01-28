class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        if (digits[0] != 9 && digits[n-1] != 9) {
            digits[n-1] = digits[n-1] + 1;
            return digits;
        }
        
        bool allNine = true;
        for (int i = 0; i < n; i++) {
            if (digits[i] != 9) {
                allNine = false;
                break;
            }
        }
        
        if (allNine) {
            vector<int> ans(n + 1, 0);
            ans[0] = 1;
            return ans;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i] = digits[i] + 1;
                break;
            }
        }
        
        return digits;
    }
};