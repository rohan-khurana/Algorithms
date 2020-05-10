class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* prevNode = new ListNode(NULL);
        ListNode* res = prevNode;
        int carry = 0;
	    while (l1||l2||carry!=0)
	    {
    		int sum = 0;
		    if (l1)
			    sum += l1->val;
		    if (l2)
			    sum += l2->val;
		    sum += carry;
		    carry = sum / 10;
		    sum = sum % 10;
		    ListNode* node = new ListNode(sum);
			prevNode->next = node;
			prevNode = node;
            if (l1)
			    l1 = l1->next;
		    if (l2)
			    l2 = l2->next;
		}
        return res->next;
	}
};
