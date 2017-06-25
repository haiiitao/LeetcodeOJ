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
    ListNode* deleteDuplicates( ListNode* head ) {
        if ( !head )
            return NULL;
            
        ListNode dummy(-1);
        ListNode* prev = &dummy, *cur = head;
        dummy.next = head;
        while ( cur && cur->next ) {   
            bool has_dup = false;
            if ( cur->val == cur->next->val ){ // find duplicate nodes
                has_dup = true;
                int dup = cur->val;
                while ( cur && cur->val == dup ) { // clean up all duplicate nodes
                   ListNode* tmp = cur->next;
                   delete cur;
                   cur = tmp;
                }
            }
            if ( has_dup ) {
                prev->next = cur;
            } else {
                prev = cur;
                cur = cur ? cur->next : NULL;
            }
         
        }
        return dummy.next;
    }
};