class Solution {
public:
    string converter(string s){
        int n = s.size();

        int lastB = 0;
        int currentB = 0;
        int num = -1;

        string ans = "";

        for(int i =0; i<n; i++){
            if(s[i] == '[') lastB = i;
            if(s[i] == ']'){
                currentB = i;

                int number = 0;
                int k = lastB - 1;

                while(k >= 0 && isdigit(s[k])){
                    number = (s[k] - '0') * pow(10, lastB - 1 - k) + number;
                    k--;
                }

                string mid = s.substr(lastB+1, currentB - lastB -1);
                while(number--){
                    ans = ans+ mid;
                }

                string left = s.substr(0, k + 1);
                string right = s.substr(currentB + 1);

                return left + ans + right;
            }
        }
        return ans;
    }

    bool checkbrackets(string s){
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] == '['){
                return false;
            }
        }
        return true;
    }

    string decodeString(string s) {

        while(!checkbrackets(s)){
            s = converter(s);
        }
        return s;
    }
};