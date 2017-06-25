/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition( ListNode* head, int x ) {
        ListNode dummy1( -1 ), dummy2( -1 );
        ListNode* cur = head, *p1 = &dummy1, *p2 = &dummy2;
        while ( cur ) {
            if ( cur->val < x ) {
                p1->next = cur;
                p1 = p1->next;
            } else {
                p2->next = cur;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        p2->next = NULL;
        p1->next = dummy2.next;
        
        return dummy1.next;
    }
};