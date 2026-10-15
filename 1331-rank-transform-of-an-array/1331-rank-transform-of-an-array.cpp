class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        map<int, int> a;
        sort(temp.begin(), temp.end());
        int rank = 1;
        for (int i = 0; i < arr.size(); i++)
            if (a.find(temp[i]) == a.end())
                a[temp[i]] = rank++;
        for (int i = 0; i < arr.size(); i++)
            temp[i] = a[arr[i]];
        return temp;
    }
};