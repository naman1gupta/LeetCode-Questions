class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        if (n < 5) return {};

        set<pair<int, int>> played;
        vector<int> gamesCount(n, 0);

        vector<vector<int>> schedule;

        int prevA = -1, prevB = -2;
        for (int game = 0; game < n * (n - 1); ++game) {
            int minSum = 4 * n;
            int A = -1, B = -2;

            for (int i = 0; i < n; ++i) {
                if (i == prevA || i == prevB) continue;

                for (int j = 0; j < n; ++j) {
                    if (j == i || j == prevA || j == prevB) continue;
                    if (played.find({i, j}) != played.end()) continue;

                    if (gamesCount[i] + gamesCount[j] < minSum) {
                        A = i;
                        B = j;
                        minSum = gamesCount[i] + gamesCount[j];
                    }
                }
            }

            schedule.push_back({A, B});

            played.insert({A, B});
            gamesCount[A]++;
            gamesCount[B]++;
            prevA = A;
            prevB = B;
        }

        return schedule;
    }
};