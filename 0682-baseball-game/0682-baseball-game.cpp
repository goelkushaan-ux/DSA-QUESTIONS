class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> temp;
        int ans = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i][0] == '+') {
                int a = temp.top();
                temp.pop();
                int b = temp.top();
                temp.push(a);
                temp.push(a + b);
            } else if (operations[i][0] == 'D') {
                int a = temp.top();
                temp.push(2 * a);
            } else if (operations[i][0] == 'C')
                temp.pop();
            else {
                int a = 0, sign = 1;
                for (int j = 0; j < operations[i].size(); j++) {
                    if (operations[i][j] == '-')
                        sign = -1;
                    else
                        a = a * 10 + (operations[i][j] - '0');
                }
                a = a * sign;
                temp.push(a);
            }
        }
        while (!temp.empty()) {
            ans += temp.top();
            temp.pop();
        }
        return ans;
    }
};