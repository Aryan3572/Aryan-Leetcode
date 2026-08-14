class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        int left = 0;
        int result = 0;

        for(int right = 0; right < s.size();right++)
        {
            freq[s[right] - 'a']++;

            while(freq[s[right] - 'a'] > 2)
            {
                freq[s[left] - 'a']--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};