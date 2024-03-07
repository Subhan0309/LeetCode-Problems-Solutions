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
    ListNode * merge(ListNode * l1,ListNode * l2)
    {
        if(!l1 && !l2)
        {
            return nullptr;
        }
        ListNode * DN=new  ListNode(0);
        ListNode * current=DN;

        while(l1 && l2)
        {
            if(l1 -> val < l2 -> val)
            {
                current->next=l1;
                current=current->next;
                l1=l1->next;
                
            }
            else
            {
                current->next=l2;
                current=current->next;
                l2=l2->next;
            }
        }

        while(l1)
        {
            current->next=l1;
            current=current->next;
            l1=l1->next;
        }
        while(l2)
        {
            current->next=l2;
            current=current->next;
            l2=l2->next;
        }

        return DN->next;
    }


    ListNode * merging(vector<ListNode*>& lists , int start , int end)
    {
        if(start==end)
        {
            return lists[start];
        }
        int mid=( start + end ) / 2;

        ListNode * l1= merging(lists,start,mid);
        ListNode * l2= merging(lists,mid+1,end);

        return  merge(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0)
        {
            return nullptr;
        }
        if(lists.size()==1)
        {
            return lists[0];
        }


        return merging(lists,0,lists.size()-1);
    }
};