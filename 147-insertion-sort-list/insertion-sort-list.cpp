class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode * dummy=new ListNode(0,head);
       
        ListNode * prev=head;
        ListNode * curr=head->next;

        while(curr)
        {
            if(curr->val >= prev->val)
            {
                prev=curr;
                curr=curr->next;
                continue;
            }
            
            //Finding the position to insert a node
            ListNode*temp=dummy;
            while(curr->val > temp->next->val)
            {
                temp=temp->next;
            }

            //Linking the nodes
            prev->next=curr->next;          
            curr->next=temp->next;
            temp->next=curr;

            //moving pointer to next
            curr=prev->next;
            
        }


        return dummy->next;


    }
};