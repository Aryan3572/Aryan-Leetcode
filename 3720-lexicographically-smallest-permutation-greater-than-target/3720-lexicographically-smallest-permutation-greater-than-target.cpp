class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // states[i] = frequency array after using target[0 ... i-1]
        vector<vector<int>> states(n + 1, vector<int>(26));

        states[0] = freq;

        int matched = 0;

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {

            states[i + 1] = states[i];

            int x = target[i] - 'a';

            if (states[i + 1][x] == 0) {
                break;
            }

            states[i + 1][x]--;
            matched++;
        }

        // Backtrack from the last position
        // where target prefix was successfully matched.
        for (int i = matched; i >= 0; i--) {

            // We want to change position i.
            if (i == n)
                continue;

            vector<int> remaining = states[i];

            int targetChar = target[i] - 'a';

            // Find the smallest character > target[i]
            for (int c = targetChar + 1; c < 26; c++) {

                if (remaining[c] == 0)
                    continue;

                // Put this character at position i
                remaining[c]--;

                string ans = target.substr(0, i);

                ans += char('a' + c);

                // Put all remaining characters
                // in sorted order.
                for (int j = 0; j < 26; j++) {
                    ans += string(remaining[j], char('a' + j));
                }

                return ans;
            }
        }

        return "";
    }
};