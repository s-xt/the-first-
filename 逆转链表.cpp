/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead->next==NULL){
            return pHead;
        }
        ListNode *p,*q,*h;
        p=h=q=pHead;
        while(h->next!=NULL){
            h=h->next;
        }//h指向新的头结点
        while(q->next!=h){
            q=q->next;
        }
        h->next=q;//设置头指针的后继 
        while(q!=pHead){
            while(p->next!=q){
                p=p->next;
            } 
            q->next=p;//设置q结点的后继 
            q=p;
            p=pHead;
        }
        q->next=NULL;
        return h;
    }
};
