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
        }//hָ���µ�ͷ���
        while(q->next!=h){
            q=q->next;
        }
        h->next=q;//����ͷָ��ĺ�� 
        while(q!=pHead){
            while(p->next!=q){
                p=p->next;
            } 
            q->next=p;//����q���ĺ�� 
            q=p;
            p=pHead;
        }
        q->next=NULL;
        return h;
    }
};
