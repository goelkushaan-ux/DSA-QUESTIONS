class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() <= 2)
            return fruits.size();
        int a = 0, b = -1;
        int lasta=0, lastb;
        int maxi = 1, count = 1;
        for (int i = 1; i < fruits.size(); i++) {
            if (fruits[i] == fruits[a]) {
                count++;
                lasta = i;
            } else if (b == -1) {
                b = i;
                count++;
                lastb = i;
            } else if (fruits[i] == fruits[b]) {
                count++;
                lastb=i;
            } else {
                if (lasta < lastb) {
                    a = lasta + 1;
                    b = i;
                    count = i - a + 1;
                    lasta=i-1;
                    lastb=i;
                } else {
                    a = lastb + 1;
                    b = i;
                    count = i - a + 1;
                    lastb=i;
                }
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};