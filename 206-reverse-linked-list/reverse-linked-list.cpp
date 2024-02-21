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
    ListNode* reverseList(ListNode* head) {
        
        if(!head)
        {
            return nullptr;
        }

        ListNode*p=nullptr;
        ListNode*q=nullptr;
        ListNode*r=nullptr;
        q=head;
        r=q->next;

        while(q!=nullptr)
        {
            q->next=p;
            p=q;
            q=r;
            if(r!=nullptr)
                r=r->next;
            
        }
        return p;
    }
};