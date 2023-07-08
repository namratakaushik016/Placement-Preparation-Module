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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
    int count = 0;
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }
    if (count < k) {
        return head; // Not enough nodes, return the original list
    }

    // Reverse the first k nodes
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    curr = head;
    count = 0;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Connect the reversed group with the next reversed group
    if (next) {
        head->next = reverseKGroup(next, k);
    }

    return prev;
    }
};