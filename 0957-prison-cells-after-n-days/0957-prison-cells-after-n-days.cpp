class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> state(128);
        unordered_map<int, int> states;
        int x = 0, period, leftover;

        for (int i = 0; i < 8; i++) x |= (cells[i] << (7 - i));
        state[0] = x;
        states[x] = 0;

        int cnt;
        for (cnt = 1; cnt < 128; cnt++) {
            x = state[cnt - 1];
            int y = 0;

            for (int i = 1; i < 7; i++) {
                if (((x >> (i + 1)) & 1) == ((x >> (i - 1)) & 1)) {
                    y |= (1 << i);
                }
            }

            state[cnt] = y;
            if (states.find(y) != states.end()) {
                period = cnt - states[y];
                leftover = states[y];
                break;
            }
            states[y] = cnt;
        }

        if (cnt == 128) {
            return cells;
        }

        int idx = ((n - leftover) % period) + leftover;
        vector<int> ans(8);

        for (int i = 0; i < 8; i++) {
            ans[i] = (state[idx] & (1 << (7 - i))) ? 1 : 0;
        }

        return ans;
    }
};
