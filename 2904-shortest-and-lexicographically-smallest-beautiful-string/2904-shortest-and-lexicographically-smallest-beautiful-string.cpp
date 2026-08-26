class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            if (s[right] == '1')
                ones++;

            // Too many 1s -> move left
            while (ones > k) {
                if (s[left] == '1')
                    ones--;

                left++;
            }

            // Exactly k ones.
            // Remove unnecessary leading zeroes.
            while (ones == k && left < right && s[left] == '0') {
                left++;
            }

            // Current window is beautiful
            if (ones == k) {
                string curr = s.substr(left, right - left + 1);

                if (ans == "" ||
                    curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};