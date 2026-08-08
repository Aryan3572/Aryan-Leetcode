class Solution {
public:
    vector<string> letterCombinations(string digits) {

        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string s = "";

        solve(0, digits , s, result , combos);
        return result;
        
    }
    void solve(int index, string digits, string s , vector<string>& result , string combos[])
    {
        if(index == digits.size())
        {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';

        for(int i = 0;i<combos[digit].size();i++)
        {
            solve(index + 1, digits, s + combos[digit][i], result,combos);

        }
    }
};