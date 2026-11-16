class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        while (n > k) {
            string a = "";
            int i = 0;
            while (i < n) {
                int sum = 0;
                for (int j = 0; j < k && i < n; j++) {
                    sum += s[i] - '0';
                    i++;
                }
                string temp = "";
                if (sum == 0)
                    temp = "0";
                while (sum > 0) {
                    temp += (sum % 10 + '0');
                    sum /= 10;
                }
                reverse(temp.begin(), temp.end());
                a += temp;
            }
            s = a;
            n = s.size();
        }

        return s;
    }
};