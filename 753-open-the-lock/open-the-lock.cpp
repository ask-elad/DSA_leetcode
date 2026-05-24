#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> children(string init){
        vector<string> ans;

        for(int i = 0; i < init.size(); i++) {
            string ahead = init;
            string behind = init;

            if(init[i] == '0'){
                ahead[i] = '1';
                behind[i] = '9';
            }
            else if(init[i] == '9'){
                ahead[i] = '0';
                behind[i] = '8';
            }
            else{
                ahead[i] = init[i] + 1;
                behind[i] = init[i] - 1;
            }

            ans.push_back(ahead);
            ans.push_back(behind);
        }

        return ans;
    }

    int bfs(string s, unordered_map<string, bool>& mpp, string target){
        queue<pair<string,int>> q;
        unordered_set<string> vis;

        q.push({s,0});
        vis.insert(s);

        while(!q.empty()) {
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(curr == target) return steps;

            vector<string> more = children(curr);

            for(auto child : more){
                if(vis.find(child) == vis.end() && mpp.find(child) == mpp.end()){
                    q.push({child, steps + 1});
                    vis.insert(child);
                }
            }
        }

        return -1;
    }

    int openLock(vector<string>& deadends, string target) {

        unordered_map<string, bool> dead;
        for(auto s : deadends){
            dead[s] = true;
        }

        if(dead.find("0000") != dead.end()) return -1;

        string init = "0000";
        return bfs(init, dead, target);
    }
};