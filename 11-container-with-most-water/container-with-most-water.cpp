class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int mx = 0;
        int crr = 0;

        int i=0;
        int j =n-1;

        while(j>i){
            crr = (j-i) * min(heights[i],heights[j]);
            mx = max(mx,crr);

            if(heights[i] > heights[j]){
                j--;
            }else{
                i++;
            }
        }
        return mx;
    }
};