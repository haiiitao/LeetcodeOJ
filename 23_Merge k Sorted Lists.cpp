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
    ListNode *mergeKLists( vector<ListNode*> &lists ) {
        if ( lists.empty() ) 
            return NULL;
        
        return mergeSort( lists, 0, lists.size() - 1 );
    }
    
    ListNode* mergeSort(vector<ListNode*>& lists, int begin, int end ) {
        if ( begin == end ) 
            return lists[begin];
            
        int mid = (begin + end) / 2;
        ListNode* leftList = mergeSort( lists, begin, mid );
        ListNode* rightList = mergeSort( lists, mid + 1, end );
        
        return mergeTwoLists( leftList, rightList );
    }

private:
    ListNode* mergeTwoLists( ListNode* l1, ListNode* l2 ) {
        ListNode dummy( -1 );
        ListNode* cur = &dummy;
        for ( ; l1 && l2; cur = cur->next ) {
            int val1 = l1->val, val2 = l2->val;
            if ( val1 >= val2 ) {
                cur->next = l2;
                l2 = l2->next;
            } else {
                cur->next = l1;
                l1 = l1->next;                
            }
        }
        cur->next = l1 ? l1 : l2;
        return dummy.next;
    }
};