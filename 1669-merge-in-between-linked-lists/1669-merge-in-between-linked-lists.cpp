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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list1, *x=list1;
        for (int i = 1;x!=NULL && temp != NULL; i++) {
            if (i == a) {
                x = temp->next;
                temp->next = list2;
            } else if(i<a)
                temp = temp->next;
            if (i == b)
                break;
            else
                x = x->next;
        }
        while (list2->next != NULL)
            list2 = list2->next;
        list2->next = x->next;
        return list1;
    }
};