class Solution {
public:
    void fixit(int id, string &digits, string &ds, vector<string>& ans, vector<string>& check){
        if(ds.size() == digits.size()){
            ans.push_back(ds);
            return;
        }

        string temp = check[id];

        for(char c : temp){
            ds.push_back(c);
            fixit(id+1, digits, ds, ans, check);
            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        vector<string> check = mapping(digits);

        string ds;
        vector<string> ans;

        fixit(0, digits, ds, ans, check);
        return ans;
    }
    vector<string> mapping(string &digits){
        string s = "";
        vector<string> ans;

        for(char a : digits){
            if(a == '2'){
                s = "abc";
                ans.push_back(s);
                s = "";
            }
            else if(a == '3'){
                s = "def";
                ans.push_back(s);
                s = "";
            }
            else if(a == '4'){
                s = "ghi";
                ans.push_back(s);
                s = "";
            }
            else if(a == '5'){
                s = "jkl";
                ans.push_back(s);
                s = "";
            }
            else if(a == '6'){
                s = "mno";
                ans.push_back(s);
                s = "";
            }
            else if(a == '7'){
                s = "pqrs";
                ans.push_back(s);
                s = "";
            }
            else if(a == '8'){
                s = "tuv";
                ans.push_back(s);
                s = "";
            }
            else if(a == '9'){
                s = "wxyz";
                ans.push_back(s);
                s = "";
            }
        }

        return ans;
    }
};