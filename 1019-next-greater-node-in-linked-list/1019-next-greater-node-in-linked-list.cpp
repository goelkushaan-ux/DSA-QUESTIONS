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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevnode = nullptr;
        ListNode* currentnode = head;
        ListNode* nextnode = head;

        while (nextnode != nullptr) {
            nextnode = nextnode->next;
            currentnode->next = prevnode;
            prevnode = currentnode;
            currentnode = nextnode;
        }
        return prevnode;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        if (head->next == NULL)
            return {0};
        head = reverseList(head);
        vector<int> ans;
        stack<int> st;

        while (head) {
            while (!st.empty() && st.top() <= head->val)
                st.pop();

            if (st.empty())
                ans.push_back(0);
            else
                ans.push_back(st.top());

            st.push(head->val);
            head = head->next;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};