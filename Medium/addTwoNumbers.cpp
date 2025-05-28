class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 ==nullptr && l2==nullptr)return nullptr;
        if(l1 ==nullptr && l2!=nullptr)return l2;
        if(l1 !=nullptr && l2==nullptr)return l1;
        ListNode*l3= new ListNode();
        ListNode*t1=l1;
        ListNode*t2=l2;
        ListNode*t3=l3;int carry=0;
        while(t1 && t2){
            ListNode*newnode= new ListNode();
            t3->next= newnode;t3=t3->next;
            t3->val = (t1->val +t2->val + carry)%10;
            carry=(t1->val +t2->val + carry)/10;
            t1=t1->next;
            t2=t2->next;
        }
        while(t1){
            ListNode*newnode= new ListNode();
            t3->next= newnode;t3=t3->next;
            t3->val = (t1->val + carry)%10;
            carry=(t1->val  + carry)/10;
            t1=t1->next;
        }
        while(t2){
            ListNode*newnode= new ListNode();
            t3->next= newnode;t3=t3->next;
            t3->val = (t2->val + carry)%10;
            carry=(t2->val + carry)/10;
            t2=t2->next;
        }
        if(carry!=0){
            ListNode*newnode= new ListNode(carry);
            t3->next=newnode;
        }
        return l3->next;;
    }
};
