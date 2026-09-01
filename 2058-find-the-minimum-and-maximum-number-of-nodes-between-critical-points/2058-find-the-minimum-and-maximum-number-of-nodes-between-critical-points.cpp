/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head->next->next == NULL)
            return {-1, -1};
        int prev = -1, curr = -1;
        int first = -1;
        int i = 1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        ListNode* temp = head;
        while (temp->next != NULL && temp->next->next != NULL) {
            if ((temp->next->next->val < temp->next->val &&
                 temp->val < temp->next->val) ||
                (temp->next->next->val > temp->next->val &&
                 temp->val > temp->next->val)) {
                if (prev == -1) {
                    first = i;
                    prev = i;
                    curr = i;
                } else {
                    prev = curr;
                    curr = i;
                }
            }
            if (prev != -1 && prev != curr) {
                mini = min(curr - prev, mini);
                maxi = max(maxi, curr - first );
            }
            i++;
            temp = temp->next;
        }
        if (first == -1 || curr == prev)
            return {-1, -1};
        return {mini, maxi};
    }
};