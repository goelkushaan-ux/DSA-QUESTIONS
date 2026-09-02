class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;
        int start, end;
        bool inserted = false;

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0])
                ans.push_back(intervals[i]);
            else if (newInterval[1] < intervals[i][0]) {
                if (!inserted) {
                    ans.push_back(newInterval);
                    inserted = true;
                }
                ans.push_back(intervals[i]);
            } else {
                start = min(newInterval[0], intervals[i][0]);
                end = max(newInterval[1], intervals[i][1]);
                newInterval[0] = start;
                newInterval[1] = end;
            }
        }
        if (!inserted)
            ans.push_back(newInterval);
        return ans;
    }
};