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
	char name[10];//姓名
	char sex[5];//性别
	int num;//学号
	Score score;//成绩 
	Student *next;
};
Student *head=NULL;//第一个学生信息 
int w=0;//学生人数 

void input();
void find();
void del();
void alt();
void show();
void exit();

int main(){
	int i;//选项 
	char x;
	cout<<setw(50)<<"欢迎进入学生管理系统！"<<endl<<endl;
	cout<<setw(45)<<"1 添加学生信息"<<endl<<endl;
	cout<<setw(45)<<"2 查询学生信息"<<endl<<endl;
	cout<<setw(45)<<"3 删除学生信息"<<endl<<endl;
	cout<<setw(45)<<"4 修改学生信息"<<endl<<endl;
	cout<<setw(45)<<"5 显示学生信息"<<endl<<endl;
	cout<<setw(41)<<"0 退出系统"<<endl; 
	cout<<"请选择：";
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
			cout<<"你的输入有误，按任意键返回主菜单！"<<endl;
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
	cout<<"请输入要添加的学生个数："<<endl;
	cin>>n;
	for(int i=1;i<=n;i++){
		Student *newstu=new Student;
		if(newstu==NULL){
			cout<<"内存分配失败！"<<endl;
			exit(1);
		}
		w++;			
		cout<<"请输入第"<<i<<"名要添加的同学信息："<<endl;
		cout<<"请输入该名同学的姓名，性别，学号（中间用空格隔开）："<<endl;
		cin>>newstu->name>>newstu->sex>>newstu->num;
		cout<<endl<<"请输入该名同学的成绩："<<endl;
		cout<<"该名同学的语文，数学，英语成绩分别为："<<endl;
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
				while(p!=NULL&&p->score.zongfen<newstu->score.zongfen){//按学生总成绩的从小到大搭建链表 
					q=p;
					p=p->next;
				}			
				newstu->next=p;
				q->next=newstu;					
			}
		}
	}
	cout<<"新添学生信息录入已完成，请按任意键返回主菜单！";
	getchar();
	getchar();
	system("cls");
	main();
}

void show(){
	Student *p=head;
	for(int i=1;i<=w;i++){
		cout<<"第"<<i<<"名同学基本信息如下："<<endl;
		cout<<"姓名："<<p->name<<" 性别："<<p->sex<<" 学号："<<p->num<<endl;
		cout<<"该名同学成绩情况如下："<<endl;
		cout<<"数学："<<p->score.shuxue<<" 语文："<<p->score.yuwen<<" 英语："<<p->score.yingyu<<" 总分："<<p->score.zongfen<<endl<<endl;
		p=p->next;
	}
	cout<<"所有学生信息打印完成，请按任意键返回主菜单！";
	getchar();
	getchar();
	system("cls");
	main();
}
