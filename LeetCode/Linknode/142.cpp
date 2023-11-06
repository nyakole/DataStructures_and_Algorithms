// https://leetcode.com/problems/linked-list-cycle-ii/
 ListNode *detectCycle(ListNode *head) {
         ListNode *slow=head, *fast=head, *entry=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) {
                while(slow!=entry){
                    slow=slow->next;
                    entry = entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }