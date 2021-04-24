#include<iostream>
#include<fstream>
#include<stdlib>
#include<string.h>
using namespace std;

struct Info{
	char num[20];//学号
	char name[8];//姓名
	char phone[16];//电话
	char adres[40];//住址
	float mark;//绩点
	char other[100];//奖惩信息
	char book;//学生证预约
	Info *next; 
};

static int N;

class Stu{//抽象类 
protected:
	Info *person;
	fstream people;
public:
	Stu();
	virtual Info *SearNum(char *)=0;//按学号查找学生信息，纯虚函数             √ 
	void creat();//创建链表                                                    √ 
	bool operator>(const Info *);//重载>运算符，比较成绩高低
	friend void InputOne(Info *p1);//友元函数 
	~Stu(); //                                                                 √ 
};
class Show:public Stu{
public:
	void ShowOne(Info *);//显示指定的学生信息
	void ShowAll();//显示所有学生的信息
	void ListNum();//按学号排序输出
	void ListMark();//按绩点高低排序输出
	Info *SearNum(char *);//
	void Apply(char *);//学籍证明
	void Book(char *);//学生证预约
	void Change(char *);//信息更改/修改
	void GoodBad(char *);//奖惩情况录入 
};

Stu::Stu(){
	N=0;
	person=new Info;//内存动态分配 
	people.open("PeoInfo.txt",ios::in | ios::out | ios::binary);
	if(!people){
		cout<<"文件打开失败！"<<endl;
		exit(0); 
	}
	/*
	if(people.fail()){
		cout<<"创建文件PeoInfo.txt出错！"<<endl;
		exit(0); 
	}
	*/
} 
Stu::~Stu(){
	people.close();
}
Stu::creat(){
	Info *head;
	Info *p1,*p2;
	int n=0;
	char GoOn="Y";
	p1=p2=new Info;
	InputOne(p1);
	people.write((char *)p1,sizeof(*p1));//二进制输出文件，将新添加的学生信息存入磁盘 
	head=NULL;
	while(GoOn=='Y'||GoOn=='y'){
		n++;
		if(n==1){//添加第一个结点 
			head=p1;
		}
		else{
			p2->next=p1;
		}
		p2=p1;
		cout<<"是否继续输入？ Y/N:"<<endl;
		cin>>GoOn;
		cin.ignore();
		if(GoOn!='Y'&&GoOn!='y'){
			people.close();
			break;
		}
		p1=new Info;
		InputOne(p1);
		people.write((char *)p1,sizeof(*p1));
	}
	p2->next=NULL;
}

int main(){
	
	return 0;
}


