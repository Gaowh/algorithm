解释见doc文件

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 非递归方法：
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur, *precur = nullptr, *aftcur;
        cur = head;
        while(cur){
            aftcur = cur->next;
            cur->next = precur;
            precur = cur;
            cur = aftcur;
        }
        return precur;
    }
};

递归方法：
解析：先递归到最后一个空姐点， 递归的出口是head为空，这时候设置好新的头结点后回到上一层

    每次回到上一层后都将上一层的两个节点翻转就行了
    
class Solution {
    ListNode *newhead;
    void help(ListNode *head, ListNode *prehead){
        if(!head){
            newhead = prehead;
            return;
        }
        help(head->next, head);
        head->next = prehead;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        help(head, nullptr);
        return newhead;
    }
};
