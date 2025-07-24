        for(int i = 0; i < n; i++) {
            if(a[i] % num == 0) {
                count += a[i] / num;
            } else {
                count += a[i] / num + 1;
            }
        int n = a.size();
        int count = 0;
class Solution {
public:
    bool isPossible(vector<int> a, int num, int threshold) {