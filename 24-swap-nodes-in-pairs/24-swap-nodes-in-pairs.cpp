/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **p  = &head;
        ListNode *a, *b;
        while((a=*p) && (b=a->next)){
            a->next = b->next;
            b->next = a;
            *p = b;
            p = &(a->next);
        }
        return head;
    }
};