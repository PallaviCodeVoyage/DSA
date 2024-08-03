while(cur)
        {
            nextnode=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextnode;
            
        }//way 1 of reversing ll
//eg:->5->6->7

//way 2
ListNode* reverseLL(ListNode* node) {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* last = reverseLL(node->next);
        node->next->next = node;
        node->next = NULL;
        return last;
    }

//making  function and returning the pointer of the last node whic will now be hed imagination sir

/*point 3:because in case of odd no of ll there are more element in frst half*/
