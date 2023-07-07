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
          if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* start = head;
    ListNode* end = nullptr;
    ListNode* temp = nullptr;

    while (start != nullptr) {
        temp = start;            // Store start in temp
        start = start->next;     // Move start to the next node
        temp->next = end;        // Set the next pointer of temp to end
        end = temp;              // Move end to temp
    }

    return end;
    }
};