/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
*/

//返回链表中的倒数第K个节点
//
//让一个节点先向前走K步， 然后另外一个节点从头结点和之前的一个节点往后走
//
//当然必要的边界条件必须要判断


class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if(!pListHead || k==0) return nullptr;
        
        ListNode *prev = pListHead; 
        while(k>1 && prev->next != nullptr){
            prev = prev->next;
            k--;
        }
        if(k>1) return nullptr;
        
        ListNode *kthNode = pListHead;
        while(prev->next){
            prev = prev->next;
            kthNode = kthNode->next;
        }
        return kthNode;
	}
};
