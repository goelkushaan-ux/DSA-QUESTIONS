/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL)
            return head;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->child == NULL)
                temp = temp->next;
            else {
                Node* next = temp->next;
                Node* down = temp->child;
                Node* h = flatten(down);
                temp->next = h;
                h->prev = temp;
                temp->child = NULL;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = next;
                if (next != NULL)
                    next->prev = temp;
            }
        }
        return head;
    }
};