class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // Store reserved seats for each row
        unordered_map<int, unordered_set<int>> reserved;

        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        int ans = (n - reserved.size()) * 2;

        for (auto &[row, seats] : reserved) {

            bool group1 = true; // seats 2,3,4,5
            bool group2 = true; // seats 4,5,6,7
            bool group3 = true; // seats 6,7,8,9

            for (int seat = 2; seat <= 5; seat++) {
                if (seats.count(seat)) {
                    group1 = false;
                    break;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (seats.count(seat)) {
                    group2 = false;
                    break;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (seats.count(seat)) {
                    group3 = false;
                    break;
                }
            }

            if (group1 && group3) {
                // Two families can sit
                ans += 2;
            }
            else if (group1 || group2 || group3) {
                // Only one family can sit
                ans += 1;
            }
        }

        return ans;
    }
};