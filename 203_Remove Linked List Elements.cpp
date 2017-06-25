/**
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements( ListNode* head, int val ) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        while ( head ) {
            if ( head->val == val ) {
                ListNode* t = head->next;
                delete head;
                head = t;
                prev->next = t;
            } else {
                prev = head;
                head = head->next;
            }
        }
        return dummy.next;
    }
};