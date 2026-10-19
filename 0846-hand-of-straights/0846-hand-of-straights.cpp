class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        map<int, int> temp;
        for (auto a : hand)
            temp[a]++;
        int n = hand.size();
        while (n != 0) {
            int a = temp.begin()->first;
            int count = 0;
            while (count < groupSize) {
                if (temp[a] < 1)
                    return false;
                temp[a]--;
                if (temp[a] == 0)
                    temp.erase(a);
                a++;
                count++;
                n--;
            }
        }
        return true;
    }
};