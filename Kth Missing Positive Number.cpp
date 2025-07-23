class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int n = a.size();
        int j = 0;
        for (int i = 1; ; i++) {  
            if (k == 0) return i - 1;
            if (j < n && i == a[j]) {
                j++;
            } else {
                k--;
            }
        }
        return -1; 
    }
};