class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> st;
        int total = 0;

        for(int i = 0; i < operations.size(); i++) {

            if(operations[i] == "+") {

                int fir = st.top();
                st.pop();

                int sec = st.top();

                st.push(fir);
                st.push(sec + fir);
            }

            else if(operations[i] == "C") {
                st.pop();
            }

            else if(operations[i] == "D") {

                int temp = st.top() * 2;
                st.push(temp);
            }

            else {
                st.push(stoi(operations[i]));
            }
        }
        
        while(!st.empty()) {

            total = total + st.top();
            st.pop();
        }

        return total;
    }
};