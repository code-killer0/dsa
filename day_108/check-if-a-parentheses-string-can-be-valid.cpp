class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) {
            return false;
        }

        stack<int> open, open_close;

        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                open_close.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else {
                if (!open.empty()) {
                    open.pop();
                } else if (!open_close.empty()) {
                    open_close.pop();
                } else {
                    return false;
                }
            }
        }

        while (!open.empty() && !open_close.empty() && open.top() < open_close.top()) {
            open.pop();
            open_close.pop();
        }

        return open.empty();
    }
};
