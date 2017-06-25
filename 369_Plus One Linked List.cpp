class Solution {
public:
    ListNode* plusOne( ListNode* head ) {
        head = reverse( head );
        ListNode* cur = head, *prev;
        int carry = 1;
        while ( cur && carry ) {
            carry += cur->val;
            cur->val = carry % 10;
            carry /= 10;
            prev = cur;
            cur = cur->next;
        }
        if ( carry )
            prev->next = new ListNode( carry );
            
        return reverse( head );
    }

private: 
    ListNode* reverse( ListNode* head ) {
        ListNode* prev = NULL;
        while ( head ) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};