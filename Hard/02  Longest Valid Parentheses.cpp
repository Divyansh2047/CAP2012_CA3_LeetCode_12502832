class Solution {
public:
    bool isValid(string s, int start, int end) {
        int balance = 0;

        for (int i = start; i <= end; i++) {
            if (s[i] == '(') {
                balance++;
            } else {
                balance--;

                if (balance < 0) {
                    return false;
                }
            }
        }

        return balance == 0;
    }

    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j += 2) {

                if (isValid(s, i, j)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
