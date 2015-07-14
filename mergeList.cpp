/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

合并连个排序的链表：

1、递归的方法
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        
        ListNode *newhead = pHead1->val < pHead2->val ? pHead1:pHead2;
        
		if(pHead1->val < pHead2->val){
            pHead1->next = Merge(pHead1->next, pHead2);
        }
        else{
            pHead2->next = Merge(pHead1, pHead2->next);
        }
        
        return newhead;
	}
};

2、非递归的方法
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
        if(!pHead1 && pHead2) return pHead2;
        if(!pHead2 && pHead1) return pHead1;
        
		ListNode *newHead = nullptr;
        ListNode *ptr;
        
        
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                
                if(newHead == nullptr) {
                    newHead = pHead1;
                    ptr = newHead;
                }
                else {
                    ptr->next = pHead1;
                    ptr = ptr->next;

                }
                pHead1 = pHead1->next; 
            }
            
            else {
              	if(newHead == nullptr) {
                    newHead = pHead2;
                    ptr = newHead;
                }
                else {
                    ptr->next = pHead2;
                    ptr = ptr->next;
                }
                pHead2 = pHead2->next;
            }
        }
        if(pHead1) ptr->next = pHead1;
        if(pHead2) ptr->next = pHead2;
        return newHead;
	}
};


