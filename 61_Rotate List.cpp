/**
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight( ListNode* head, int k ) {
        if ( !head )
            return NULL;
            
        int len = 0;
        ListNode* cur = head, *tail;
        while ( cur ) {
            tail = cur;
            cur = cur->next;
            len++;
        }
        
        k %= len;
        cur = head;
        for ( int i = 0; i < len - k - 1; i++ )
            cur = cur->next;
            
        tail->next = head;
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};