class Solution {
public:
    ListNode* oddEvenList( ListNode* head ) {
        ListNode Odd( -1 ), Even( -1 );
        ListNode* p = head, *pOdd = &Odd, *pEven = &Even;
        
        while ( p ) {
            pOdd->next = p;
            pOdd = p;
            p = p->next;
            if ( p ) {
                pEven->next = p;
                pEven = p;
                p = p->next;
            }
        }
        pEven->next = NULL;
        pOdd->next = Even.next;
        return head;
    }
};