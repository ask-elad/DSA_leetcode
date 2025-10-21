class Solution {
public:
    bool isValid(string s) {
        stack<char> a;

        for (auto val : s) {
            if (val == '[' || val == '{' || val == '(') {
                a.push(val);
            } else {
                if (a.empty()) return false; 

                if (abs(a.top() - val) <= 2) {
                    a.pop();
                } else {
                    return false;
                }
            }
        }

        return a.empty();
    }
};
