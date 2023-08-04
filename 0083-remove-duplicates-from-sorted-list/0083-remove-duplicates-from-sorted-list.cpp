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
    ListNode* deleteDuplicates(ListNode* head) {
        
        //empty list ha to
        if (head==NULL){
            return NULL;
        }
        //non-empty list ha to
        ListNode*curr=head;
        while(curr!=NULL){
            if((curr->next!=NULL) &&curr->val== curr->next->val){
                ListNode*next_next=curr->next->next;
                ListNode*nodetodelete= curr->next;
                delete(nodetodelete);
                curr->next=next_next;
            }
            else//not equal to 
            {
               curr=curr->next; 
            }
        }
        return head;
    }
};