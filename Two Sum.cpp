class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int first = 0;
        int second = 0;
        vector<int> ans;
        unordered_map<int, int> store;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int req = target - a[i];
            if (store.find(req) != store.end()) {
                first = store[req];
                second = i;
                ans.push_back(first);
                ans.push_back(second);
                return ans; 
            }
            if (store.find(req) == store.end()) {
                store[a[i]] = i;
            }
        }
        return ans; 
    }
};