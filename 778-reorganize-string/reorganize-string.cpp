class Solution {
public:
    string reorganizeString(string s) {

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        if (maxFreq > (s.size() + 1) / 2) {
            return "";
        }

        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                pq.push({freq[i], 'a' + i});
            }
        }
        
        vector<char> ans(s.size(), ' ');
        int it = 0;

        while(!pq.empty()){
            char j = pq.top().second;
            int f = pq.top().first;

            pq.pop();
            while(f > 0){

                if(it >= s.size()) it = 1;

                ans[it] = j;
                it += 2;
                f--;
            }
        }

        string answer(ans.begin(), ans.end());
        return answer;
    }
};