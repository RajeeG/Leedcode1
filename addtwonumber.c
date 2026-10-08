struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* cur = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;

        int total = v1 + v2 + carry;
        carry = total / 10;

        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = total % 10;
        node->next = NULL;

        cur->next = node;
        cur = node;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return dummy.next;
}