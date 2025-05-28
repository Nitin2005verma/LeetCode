class Solution {
public:
    int MOD = 1e9 + 7;

    vector<vector<int>> valid_states;
    unordered_map<int, vector<int>> graph;

    void generateStates(int m, int row = 0, int prevColor = -1, vector<int> curr = {}) {
        if (row == m) {
            valid_states.push_back(curr);
            return;
        }

        for (int color = 0; color < 3; ++color) {
            if (color != prevColor) {
                curr.push_back(color);
                generateStates(m, row + 1, color, curr);
                curr.pop_back();
            }
        }
    }

    bool areCompatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i)
            if (a[i] == b[i]) return false;
        return true;
    }

    int colorTheGrid(int m, int n) {
        generateStates(m);  // generate all valid columns

        int sz = valid_states.size();
        // Map valid_state index to compatible neighbors
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (areCompatible(valid_states[i], valid_states[j])) {
                    graph[i].push_back(j);
                }
            }
        }

        vector<int> dp(sz, 1);  // for column 0, all valid states are allowed
        for (int col = 1; col < n; ++col) {
            vector<int> new_dp(sz, 0);
            for (int curr = 0; curr < sz; ++curr) {
                for (int prev : graph[curr]) {
                    new_dp[curr] = (new_dp[curr] + dp[prev]) % MOD;
                }
            }
            dp = new_dp;
        }

        int total = 0;
        for (int val : dp) {
            total = (total + val) % MOD;
        }

        return total;
    }
};
