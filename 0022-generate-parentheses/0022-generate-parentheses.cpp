class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        solve(0 , 0, n, curr, result);
        
        return result;
    }
    void solve(int open, int close, int n,string &curr,  vector<string>& result)
    {
       if(curr.length() == 2 * n)
       {
            result.push_back(curr);
            return;
       }

       if(open < n)
       {
            curr.push_back('(');
            solve(open + 1, close, n,curr , result);
            curr.pop_back();
       }

       if(close < open)
       {
            curr.push_back(')');
            solve(open , close + 1, n, curr, result);
            curr.pop_back();
       }
    }
};