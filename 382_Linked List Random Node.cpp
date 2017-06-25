/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution( ListNode* head ) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res;
        ListNode* cur = head;
        int i = 0;
        while ( cur ) {
            if ( rand() % ++i == 0 )
                res = cur->val;
            
            cur = cur->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */