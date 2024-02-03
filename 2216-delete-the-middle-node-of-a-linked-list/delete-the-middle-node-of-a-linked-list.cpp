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
    ListNode* deleteMiddle(ListNode* head)
    {
        int countNodes=0;

        ListNode * current=head;
        while(current!=nullptr)
        {
            countNodes++;
            current=current->next;
        }  

        int middleNode=countNodes/2;

        if(countNodes==1)
        {
            return nullptr;
        }

        if(countNodes==2)
        {
            head->next=nullptr;
            return head;
        }

        //handle all the remaining cases here
        current=head;
        int index=0;
        ListNode * prev=nullptr;

        while(index!=middleNode)
        {
            index++;
            prev=current;
            current=current->next;
        }
        prev->next=current->next;

        return head;





    }
};