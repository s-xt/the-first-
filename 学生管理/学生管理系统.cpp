#include<iostream>
#include<fstream>
#include<stdlib>
#include<string.h>
using namespace std;

struct Info{
	char num[20];//ѧ��
	char name[8];//����
	char phone[16];//�绰
	char adres[40];//סַ
	float mark;//����
	char other[100];//������Ϣ
	char book;//ѧ��֤ԤԼ
	Info *next; 
};

static int N;

class Stu{//������ 
protected:
	Info *person;
	fstream people;
public:
	Stu();
	virtual Info *SearNum(char *)=0;//��ѧ�Ų���ѧ����Ϣ�����麯��             �� 
	void creat();//��������                                                    �� 
	bool operator>(const Info *);//����>��������Ƚϳɼ��ߵ�
	friend void InputOne(Info *p1);//��Ԫ���� 
	~Stu(); //                                                                 �� 
};
class Show:public Stu{
public:
	void ShowOne(Info *);//��ʾָ����ѧ����Ϣ
	void ShowAll();//��ʾ����ѧ������Ϣ
	void ListNum();//��ѧ���������
	void ListMark();//������ߵ��������
	Info *SearNum(char *);//
	void Apply(char *);//ѧ��֤��
	void Book(char *);//ѧ��֤ԤԼ
	void Change(char *);//��Ϣ����/�޸�
	void GoodBad(char *);//�������¼�� 
};

Stu::Stu(){
	N=0;
	person=new Info;//�ڴ涯̬���� 
	people.open("PeoInfo.txt",ios::in | ios::out | ios::binary);
	if(!people){
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		exit(0); 
	}
	/*
	if(people.fail()){
		cout<<"�����ļ�PeoInfo.txt����"<<endl;
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
	people.write((char *)p1,sizeof(*p1));//����������ļ���������ӵ�ѧ����Ϣ������� 
	head=NULL;
	while(GoOn=='Y'||GoOn=='y'){
		n++;
		if(n==1){//��ӵ�һ����� 
			head=p1;
		}
		else{
			p2->next=p1;
		}
		p2=p1;
		cout<<"�Ƿ�������룿 Y/N:"<<endl;
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


