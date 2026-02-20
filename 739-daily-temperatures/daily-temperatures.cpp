class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();

        stack<pair<int,int>>st;
        vector<int> ans(n);
        ans[n-1] = 0;

        st.push({t[n-1] , n-1});
        for(int i =n-2; i>=0; i--){
            pair<int,int>temp;
            temp.first = t[i];
            temp.second = i;

            while(!st.empty() && t[i] >= st.top().first){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top().second - i;
                st.push({t[i], i});
            }else{
                ans[i] = 0;
                st.push({t[i], i});
            }
        }
        return ans;
    }
};