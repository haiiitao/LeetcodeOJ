class Solution { 
public:
    ListNode* insertionSortList( ListNode* head ) {
        ListNode dummy = ListNode( -1 );
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while ( cur ) {
            if ( cur -> next && cur -> next -> val < cur -> val ) {
                while ( pre -> next && pre -> next -> val < cur -> next -> val )
                    pre = pre -> next;
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_head. */
                pre = &dummy;
            }
            else cur = cur -> next;
        }
        return dummy.next;
    }
};