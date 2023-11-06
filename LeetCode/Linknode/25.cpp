// https://leetcode.com/problems/reverse-nodes-in-k-group/
int lengthOfLinkedList(ListNode* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    
    ListNode* pre = dummyHead;
    ListNode* cur;
    ListNode* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
    }