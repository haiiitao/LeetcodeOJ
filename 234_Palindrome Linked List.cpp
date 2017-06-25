/**
 * Description: Given a singly linked list, determine if it is a palindrome.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome( ListNode* head ) {
        int len = 0;
        ListNode *p = head;

        /* get length of the link */
        while ( p ) {
            len++;
            p = p->next;
        }

        /* get next node of middle of link */
        p = head;
        int mid = (len % 2) ? len / 2 + 1 : len / 2;
        for ( int i = 0; i < mid; i++ ) {
            p = p->next;
        }
        
        /* reverse the back of the link */
        ListNode *prev = NULL, *next;
        while ( p ) {
            next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }

        /* jude palindrome */
        p = prev;
        while ( p ) {
            if ( head->val != p->val ) { 
                return false;
            }
            head = head->next;
            p = p->next;
        }
        return true;
    }
};