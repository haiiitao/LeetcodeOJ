/**
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.

 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *rand;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode* copyRandomList( RandomListNode* head ) {
        for ( RandomListNode* cur = head; cur; ) {
            RandomListNode *new_node = new RandomListNode( cur->label );
            new_node->next = cur->next;
            cur->next = new_node;
            cur = new_node->next;
        }
        
        for ( RandomListNode* cur = head; cur; ) {
            if ( cur->random )
                cur->next->random = cur->random->next;
            
            cur = cur->next->next;
        }
        
    
        RandomListNode dummy( -1 );
        for ( RandomListNode* cur = head, *new_cur = &dummy; cur; ) {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        
        return dummy.next;
    }
};