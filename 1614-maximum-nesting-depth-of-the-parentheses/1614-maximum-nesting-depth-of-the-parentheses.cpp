class Solution {
public:
    int maxDepth(string s) {
        int nested = 0;
        int ans = 0;

        for(char ch : s)
        {
            if(ch == '(') nested++;

            else if(ch == ')') nested--;

            ans = max(ans,nested);
        }
        return ans;
    }
};