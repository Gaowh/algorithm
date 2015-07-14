/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5


解法：每次进入while循环判断
		1、当前节点是最后一个节点
        2、如果不是最后一个节点
        	1）当前节点的下一个节点的值时候和当前的不相等
            2）当前节点的下一个节点的值和当前节点的值相等

*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode *newHead = new ListNode(-1);
        ListNode *pre = newHead;
        ListNode *now = pHead;
     	while(now){
            int val = now->val;
            if(!now->next) {
                pre->next = now;
                return newHead->next;
            }
            else if (now->next->val != val){
                pre->next = now;
                pre = pre->next;
                now = now->next;
                pre->next = nullptr;
            }
            else {
                while(now->next && val == now->next->val)
                    now = now->next;
                now = now->next;
            }
        }
        return newHead->next;
	}
};
