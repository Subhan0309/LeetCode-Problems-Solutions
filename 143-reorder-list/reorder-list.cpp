class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        // Find the middle node
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode* p = nullptr;
        ListNode* q = slow->next;
        slow->next = nullptr; // break the list into two parts

        while (q) {
            ListNode* temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }

        // Merge the two lists
        ListNode* curr1 = head;
        ListNode* curr2 = p;

        while (curr1 && curr2) {
            ListNode* temp1 = curr1->next;
            ListNode* temp2 = curr2->next;
            curr1->next = curr2;
            curr2->next = temp1;
            curr1 = temp1;
            curr2 = temp2;
        }
    }
};
