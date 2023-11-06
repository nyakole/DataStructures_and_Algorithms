//https://leetcode.com/problems/palindrome-linked-list/
ListNode* reverse(ListNode* ptr) {
    ListNode* pre=NULL;
    ListNode* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head, *entry=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=reverse(slow->next);
       // slow=slow->next;
        while(slow!=NULL){
            cout<<head->val<<" "<<slow->val<<endl;
            if(head->val!=slow->val) return false;
            slow=slow->next;
            head=head->next;
        }

        return true;
    