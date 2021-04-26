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

static int N;//学生人数 

class Stu{//抽象类 
protected:
	Info *person;
	fstream people;
public:
	Stu();//                                                                   √ 
	virtual Info *SearNum(char *)=0;//按学号查找学生信息，纯虚函数  
	void creat();//创建链表                                                    √ 
	bool operator>(const Info *);//重载>运算符，比较成绩高低                   √ 
	friend void InputOne(Info *p1);//友元函数                                  √ 
	~Stu(); //                                                                 √ 
};
class Show:public Stu{
public:
	void ShowOne(Info *);//显示指定的学生信息                                  √ 
	void ShowAll();//显示所有学生的信息                                        √ 
	void ListNum();//按学号排序输出
	void ListMark();//按绩点高低排序输出
	Info *SearNum(char *);//                                                   √ 
	void Apply(char *);//学籍证明                                              √ 
	void Book(char *);//学生证预约                                             √ 
	void Change(char *);//信息更改/修改
	void GoodBad(char *);//奖惩情况录入                                        √ 
};

//Stu中的相关函数定义 
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
	Info *p1,*p2;//p1是新建结点，p2指向尾结点 
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
bool Stu::operator>(const Info *right){
	if(person->mark > right->mark){
		return true;
	}
	return false;
} 
void InputOne(Info *p1){
	cout<<endl<<"请输入下面的数据！"<<endl;
	cout<<"学号："<<endl;
	cin.getline(p1->num,20);
	cout<<"姓名："<<endl;
	cin.getline(p1->name,8);
	cout<<"电话："<<endl;
	cin.getline(p1->phone,16);
	cout<<"住址："<<endl;
	cin.getline(p1->adres,40);
	cout<<"绩点："<<endl;
	cin>>p1->mark;
	cin.ignore();
	cout<<"备注："<<endl;
	cin.getline(p1->other,100);
	cout<<"学生证预约办理？ Y/N:";
	cin>>p1->book;
	cin.ignore();
	N++; 
}

//Show中的相关函数定义
void Show::ShowOne(Info *p){//显示指定学生信息 
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
	cout<<"学号："<<p->num<<endl;
	cout<<"姓名："<<p->name<<endl;
	cout<<"电话："<<p->phone<<endl;
	cout<<"住址："<<p->adres<<endl;
	cout<<"绩点："<<p->mark<<endl;
	cout<<"备注："<<p->other<<endl;
	cout<<"学生证预约办理 Y/N:"<<p->book<<endl;
	for(int i=0;i<50;i++){
		cout<<'=';
	}	 
} 
void Show::ShowAll(){
	char again;
	fstream showall;
	cout<<endl<<endl<<"*** 下面显示所有学生的信息 ***"<<endl;
	showall.open("PeoInfo.txt",ios::in | ios::binary);
	if(showall.fail()){
		cout<<"打开PeoInfo.txt出错！"<<endl;
		exit(0);
	}
	showall.read((char *)person,sizeof(*person));
	while(!showall.eof()){
		cout<<"学号："<<person->num<<endl;
		cout<<"姓名："<<person->name<<endl;
		cout<<"电话："<<person->phone<<endl;
		cout<<"住址："<<person->adres<<endl;
		cout<<"绩点："<<person->mark<<endl;
		cout<<"备注："<<person->other<<endl;
		cout<<"学生证预约办理 Y/N:"<<person->book<<endl;
		cout<<endl<<"请按回车键，显示下一条信息！"<<endl;
		cin.get(again);
		showall.read((char *)person,sizeof(*person));
	}
	cout<<"显示完毕！"<<endl;
	showall.close();
}
Info *Show::SearNum(char *a){
	Info *p;
	cout<<"开始按学号查找！"<<endl;
	p=person;
	bool record=false;
	while(p!=NULL && !record){
		if(strcmp(p->num,a)==0){
			ShowOne(p);
			return p;
			record=true;//这后边应该都没必要了吧？ 
		}
		p=p->next;
	}
	if(!record){
		cout<<"没有找到相关数据！"<<endl;
	}
	return NULL;
}
/*void Show::ListNum(){//按学号排序输出 
	Info *p1,*p2,*temp,*now;
	int i=0;
	cout<<"开始按学号排序！"<<endl;
	now=person;
	p1=person;
	p2=person->next;
	while(p2 && i++<=N){//i++<=N跟for循环差不多 
		if(strcmp(p2->num,p1->num)>0 && p1==person){//插入到头结点 
			
		}
	}
} */
void Show::Apply(char *a){//开具学籍证明 
	Info *p;
	p=SearNum(a);
	fstream apply;
	apply.open("Apply.txt",ios::out);
	if(apply.fail()){
		cout<<"打开Apply.txt出错！"<<endl;
		exit(1);
	}
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
	cout<<"                    证     明                    "<<endl;
	cout<<"   "<<p->name<<"同学（学号："<<p->num<<"),系我校在校学生。"<<endl;
	cout<<"   特此证明。"<<endl<<endl;
	cout<<"                             东南大学"<<endl<<endl;
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
	apply.close();	 
}
void Show::Book(char *a){//学生证预约办理
	Info *p;
	p=SearNum(a);
	p->book='Y';
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl; 
	cout<<"预约信息已记录！请尽快提交相关证明！"<<endl<<endl;
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
}
void Show::GoodBad(char *a){//学生奖惩情况录入功能
	Info *p;
	p=SearNum(a);
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
	cout<<"请输入该同学的奖惩情况："<<endl;
	cin>>p->other;
	fstream GoodBad;
	GoodBad.open("PeoInfo.txt",ios::out | ios::binary);
	if(GoodBad.fail()){
		cout<<"打开PeoInfo.txt出错！"<<endl
		exit(1);
	} 
	p=person;
	while(p){
		GoodBad.write((char *)p,sizeof(*p));
		p=p->next;
	}
	GoodBad.close();
	cout<<"奖惩情况录入完毕！感谢使用"<<endl<<endl;
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
}

int main(){
	Info *p;
	Show show;
	int want;
	char use='Y';
	char sear[20];
	cout<<"【欢迎使用学生学籍管理系统】\n请先录入要管理的学生信息\n";
	show.creat();
	cout<<"\n学生信息已正常录入，并保存到PeoInfo.txt文件中\n";
	while(use=='y'||use=='Y'){
		cout<<"\n********************学生学籍管理系统********************\n";
		cout<<"请输入要使用功能的数字代码\n";
		cout<<"    【 1】显示全部学生信息\n ";
		cout<<"    【 2】查找指定信息\n ";
		cout<<"    【 3】开具学籍证明\n ";		
		cout<<"    【 4】学生证预约登记\n ";		
		cout<<"    【 5】奖惩信息录入\n ";		
		cout<<"    【 6】按学号排序后输出\n ";		
		cout<<"    【 7】按绩点高低排序输出\n ";		
		cout<<"    【 8】清除数据文件\n ";
		cout<<"    【 9】学生信息更新/修改\n ";		
		cout<<"    【10】作者&版权信息\n ";
		cout<<"**********--Powered By ZL--***************\n";
		cin>>want;
		cin.ignore();
		if(want>10||want<1){
			cout<<"输入有误！请重新输入要使用的功能代码：";
			cin>>want;
			cin.ignore();
		}
		switch(want){
			case 1:{
				show.ShowAll();
				break;
			}
			case 2:{
				cout<<"请输入要查找的学号：";
				cin>>sear;
				p=show.SearNum(sear);
				break;
			}
			case 3:{
				cout<<"请输入要开具学籍证明的学生的学号：";
				cin>>sear;
				show.Apply(sear);
				break;
			}
			case 4:{
				
				break;
			}
		}				
	} 
	return 0;
}


