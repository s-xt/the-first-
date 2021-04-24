#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

struct Score{
	int yuwen;
	int shuxue;
	int yingyu;
	int zongfen;
};
struct Student{
	char name[10];//����
	char sex[5];//�Ա�
	int num;//ѧ��
	Score score;//�ɼ� 
	Student *next;
};
Student *head=NULL;//��һ��ѧ����Ϣ 
int w=0;//ѧ������ 

void input();
void find();
void del();
void alt();
void show();
void exit();

int main(){
	int i;//ѡ�� 
	char x;
	cout<<setw(50)<<"��ӭ����ѧ������ϵͳ��"<<endl<<endl;
	cout<<setw(45)<<"1 ���ѧ����Ϣ"<<endl<<endl;
	cout<<setw(45)<<"2 ��ѯѧ����Ϣ"<<endl<<endl;
	cout<<setw(45)<<"3 ɾ��ѧ����Ϣ"<<endl<<endl;
	cout<<setw(45)<<"4 �޸�ѧ����Ϣ"<<endl<<endl;
	cout<<setw(45)<<"5 ��ʾѧ����Ϣ"<<endl<<endl;
	cout<<setw(41)<<"0 �˳�ϵͳ"<<endl; 
	cout<<"��ѡ��";
	cin>>i;
	switch(i){
		case 1:{
			input();
			break;
		}
		case 2:{
			//find();
			break;
		}
		case 3:{
			//del();
			break;
		}
		case 4:{
			//alt();
			break;
		}
		case 5:{
			show();
			break;
		}
		case 0:{
			//exit();
			break;
		}
		default:{
			cout<<"����������󣬰�������������˵���"<<endl;
			getchar();
			getchar();
			system("cls");
			main();
			break;
		}
	}
	return 0;
}

void input(){
	int n;
	Student *p,*q;
	char name[10],sex[5];
	int num;
	cout<<"������Ҫ��ӵ�ѧ��������"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		Student *newstu=new Student;
		if(newstu==NULL){
			cout<<"�ڴ����ʧ�ܣ�"<<endl;
			exit(1);
		}
		w++;			
		cout<<"�������"<<i<<"��Ҫ��ӵ�ͬѧ��Ϣ��"<<endl;
		cout<<"���������ͬѧ���������Ա�ѧ�ţ��м��ÿո��������"<<endl;
		cin>>newstu->name>>newstu->sex>>newstu->num;
		cout<<endl<<"���������ͬѧ�ĳɼ���"<<endl;
		cout<<"����ͬѧ�����ģ���ѧ��Ӣ��ɼ��ֱ�Ϊ��"<<endl;
		cin>>newstu->score.yuwen>>newstu->score.shuxue>>newstu->score.yingyu;
		newstu->score.zongfen=newstu->score.shuxue+newstu->score.yingyu+newstu->score.yuwen;
		if(head==NULL){
			head=newstu;
			head->next=NULL;
		}
		else{
			p=head;
			if(p->score.zongfen>=newstu->score.zongfen){
				Student *t=head;
				head=newstu;
				head->next=t;
			}
			else{
				while(p!=NULL&&p->score.zongfen<newstu->score.zongfen){//��ѧ���ܳɼ��Ĵ�С�������� 
					q=p;
					p=p->next;
				}			
				newstu->next=p;
				q->next=newstu;					
			}
		}
	}
	cout<<"����ѧ����Ϣ¼������ɣ��밴������������˵���";
	getchar();
	getchar();
	system("cls");
	main();
}

void show(){
	Student *p=head;
	for(int i=1;i<=w;i++){
		cout<<"��"<<i<<"��ͬѧ������Ϣ���£�"<<endl;
		cout<<"������"<<p->name<<" �Ա�"<<p->sex<<" ѧ�ţ�"<<p->num<<endl;
		cout<<"����ͬѧ�ɼ�������£�"<<endl;
		cout<<"��ѧ��"<<p->score.shuxue<<" ���ģ�"<<p->score.yuwen<<" Ӣ�"<<p->score.yingyu<<" �ܷ֣�"<<p->score.zongfen<<endl<<endl;
		p=p->next;
	}
	cout<<"����ѧ����Ϣ��ӡ��ɣ��밴������������˵���";
	getchar();
	getchar();
	system("cls");
	main();
}
