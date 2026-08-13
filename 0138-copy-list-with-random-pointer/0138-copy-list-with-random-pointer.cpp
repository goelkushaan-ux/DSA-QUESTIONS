/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return head;
        Node* temp = head;
        while (temp != NULL) {
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = temp->next->next;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->random == NULL)
                temp->next->random = NULL;
            else
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node* copyHead = head->next;
        Node* original = head;
        Node* copy = copyHead;
        while (original != NULL) {
            original->next = original->next->next;
            if (copy->next != NULL)
                copy->next = copy->next->next;
            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};