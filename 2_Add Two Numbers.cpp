class Solution {
public:
    ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 ) {
        ListNode dummy( -1 );
        ListNode* p = &dummy;
        
        int carry = 0;
        while ( l1 || l2 || carry ) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            p->next = new ListNode( sum % 10 );
            carry = sum / 10;
            p = p->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummy.next;
    }
};

class Solution:
# @return a ListNode
def addTwoNumbers(self, l1, l2):
    carry = 0
    root = n = ListNode(0)
    while l1 or l2 or carry:
        v1 = v2 = 0
        if l1:
            v1 = l1.val
            l1 = l1.next
        if l2:
            v2 = l2.val
            l2 = l2.next
        carry, val = divmod(v1+v2+carry, 10)
        n.next = ListNode(val)
        n = n.next
    return root.next