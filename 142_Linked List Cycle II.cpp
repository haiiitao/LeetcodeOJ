/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle( ListNode* head ) {
        ListNode* fast = head;
        ListNode* slow1 = head;
        while ( fast && fast->next ) {
            fast = fast->next->next;
            slow1 = slow1->next;
            if ( fast == slow1 ) {
                ListNode* slow2 = head;
                while ( slow2 != slow1 ) {
                    slow1= slow1->next;
                    slow2 = slow2->next;
                }
                return slow2;
            }
        }
        return NULL;
    }
};