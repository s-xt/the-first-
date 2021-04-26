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

static int N;//ѧ������ 

class Stu{//������ 
protected:
	Info *person;
	fstream people;
public:
	Stu();//                                                                   �� 
	virtual Info *SearNum(char *)=0;//��ѧ�Ų���ѧ����Ϣ�����麯��  
	void creat();//��������                                                    �� 
	bool operator>(const Info *);//����>��������Ƚϳɼ��ߵ�                   �� 
	friend void InputOne(Info *p1);//��Ԫ����                                  �� 
	~Stu(); //                                                                 �� 
};
class Show:public Stu{
public:
	void ShowOne(Info *);//��ʾָ����ѧ����Ϣ                                  �� 
	void ShowAll();//��ʾ����ѧ������Ϣ                                        �� 
	void ListNum();//��ѧ���������
	void ListMark();//������ߵ��������
	Info *SearNum(char *);//                                                   �� 
	void Apply(char *);//ѧ��֤��                                              �� 
	void Book(char *);//ѧ��֤ԤԼ                                             �� 
	void Change(char *);//��Ϣ����/�޸�
	void GoodBad(char *);//�������¼��                                        �� 
};

//Stu�е���غ������� 
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
	Info *p1,*p2;//p1���½���㣬p2ָ��β��� 
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
bool Stu::operator>(const Info *right){
	if(person->mark > right->mark){
		return true;
	}
	return false;
} 
void InputOne(Info *p1){
	cout<<endl<<"��������������ݣ�"<<endl;
	cout<<"ѧ�ţ�"<<endl;
	cin.getline(p1->num,20);
	cout<<"������"<<endl;
	cin.getline(p1->name,8);
	cout<<"�绰��"<<endl;
	cin.getline(p1->phone,16);
	cout<<"סַ��"<<endl;
	cin.getline(p1->adres,40);
	cout<<"���㣺"<<endl;
	cin>>p1->mark;
	cin.ignore();
	cout<<"��ע��"<<endl;
	cin.getline(p1->other,100);
	cout<<"ѧ��֤ԤԼ���� Y/N:";
	cin>>p1->book;
	cin.ignore();
	N++; 
}

//Show�е���غ�������
void Show::ShowOne(Info *p){//��ʾָ��ѧ����Ϣ 
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
	cout<<"ѧ�ţ�"<<p->num<<endl;
	cout<<"������"<<p->name<<endl;
	cout<<"�绰��"<<p->phone<<endl;
	cout<<"סַ��"<<p->adres<<endl;
	cout<<"���㣺"<<p->mark<<endl;
	cout<<"��ע��"<<p->other<<endl;
	cout<<"ѧ��֤ԤԼ���� Y/N:"<<p->book<<endl;
	for(int i=0;i<50;i++){
		cout<<'=';
	}	 
} 
void Show::ShowAll(){
	char again;
	fstream showall;
	cout<<endl<<endl<<"*** ������ʾ����ѧ������Ϣ ***"<<endl;
	showall.open("PeoInfo.txt",ios::in | ios::binary);
	if(showall.fail()){
		cout<<"��PeoInfo.txt����"<<endl;
		exit(0);
	}
	showall.read((char *)person,sizeof(*person));
	while(!showall.eof()){
		cout<<"ѧ�ţ�"<<person->num<<endl;
		cout<<"������"<<person->name<<endl;
		cout<<"�绰��"<<person->phone<<endl;
		cout<<"סַ��"<<person->adres<<endl;
		cout<<"���㣺"<<person->mark<<endl;
		cout<<"��ע��"<<person->other<<endl;
		cout<<"ѧ��֤ԤԼ���� Y/N:"<<person->book<<endl;
		cout<<endl<<"�밴�س�������ʾ��һ����Ϣ��"<<endl;
		cin.get(again);
		showall.read((char *)person,sizeof(*person));
	}
	cout<<"��ʾ��ϣ�"<<endl;
	showall.close();
}
Info *Show::SearNum(char *a){
	Info *p;
	cout<<"��ʼ��ѧ�Ų��ң�"<<endl;
	p=person;
	bool record=false;
	while(p!=NULL && !record){
		if(strcmp(p->num,a)==0){
			ShowOne(p);
			return p;
			record=true;//����Ӧ�ö�û��Ҫ�˰ɣ� 
		}
		p=p->next;
	}
	if(!record){
		cout<<"û���ҵ�������ݣ�"<<endl;
	}
	return NULL;
}
/*void Show::ListNum(){//��ѧ��������� 
	Info *p1,*p2,*temp,*now;
	int i=0;
	cout<<"��ʼ��ѧ������"<<endl;
	now=person;
	p1=person;
	p2=person->next;
	while(p2 && i++<=N){//i++<=N��forѭ����� 
		if(strcmp(p2->num,p1->num)>0 && p1==person){//���뵽ͷ��� 
			
		}
	}
} */
void Show::Apply(char *a){//����ѧ��֤�� 
	Info *p;
	p=SearNum(a);
	fstream apply;
	apply.open("Apply.txt",ios::out);
	if(apply.fail()){
		cout<<"��Apply.txt����"<<endl;
		exit(1);
	}
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
	cout<<"                    ֤     ��                    "<<endl;
	cout<<"   "<<p->name<<"ͬѧ��ѧ�ţ�"<<p->num<<"),ϵ��У��Уѧ����"<<endl;
	cout<<"   �ش�֤����"<<endl<<endl;
	cout<<"                             ���ϴ�ѧ"<<endl<<endl;
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
	apply.close();	 
}
void Show::Book(char *a){//ѧ��֤ԤԼ����
	Info *p;
	p=SearNum(a);
	p->book='Y';
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl; 
	cout<<"ԤԼ��Ϣ�Ѽ�¼���뾡���ύ���֤����"<<endl<<endl;
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
}
void Show::GoodBad(char *a){//ѧ���������¼�빦��
	Info *p;
	p=SearNum(a);
	for(int i=0;i<50;i++){
		cout<<'=';
	}
	cout<<endl<<endl;
	cout<<"�������ͬѧ�Ľ��������"<<endl;
	cin>>p->other;
	fstream GoodBad;
	GoodBad.open("PeoInfo.txt",ios::out | ios::binary);
	if(GoodBad.fail()){
		cout<<"��PeoInfo.txt����"<<endl
		exit(1);
	} 
	p=person;
	while(p){
		GoodBad.write((char *)p,sizeof(*p));
		p=p->next;
	}
	GoodBad.close();
	cout<<"�������¼����ϣ���лʹ��"<<endl<<endl;
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
	cout<<"����ӭʹ��ѧ��ѧ������ϵͳ��\n����¼��Ҫ�����ѧ����Ϣ\n";
	show.creat();
	cout<<"\nѧ����Ϣ������¼�룬�����浽PeoInfo.txt�ļ���\n";
	while(use=='y'||use=='Y'){
		cout<<"\n********************ѧ��ѧ������ϵͳ********************\n";
		cout<<"������Ҫʹ�ù��ܵ����ִ���\n";
		cout<<"    �� 1����ʾȫ��ѧ����Ϣ\n ";
		cout<<"    �� 2������ָ����Ϣ\n ";
		cout<<"    �� 3������ѧ��֤��\n ";		
		cout<<"    �� 4��ѧ��֤ԤԼ�Ǽ�\n ";		
		cout<<"    �� 5��������Ϣ¼��\n ";		
		cout<<"    �� 6����ѧ����������\n ";		
		cout<<"    �� 7��������ߵ��������\n ";		
		cout<<"    �� 8����������ļ�\n ";
		cout<<"    �� 9��ѧ����Ϣ����/�޸�\n ";		
		cout<<"    ��10������&��Ȩ��Ϣ\n ";
		cout<<"**********--Powered By ZL--***************\n";
		cin>>want;
		cin.ignore();
		if(want>10||want<1){
			cout<<"������������������Ҫʹ�õĹ��ܴ��룺";
			cin>>want;
			cin.ignore();
		}
		switch(want){
			case 1:{
				show.ShowAll();
				break;
			}
			case 2:{
				cout<<"������Ҫ���ҵ�ѧ�ţ�";
				cin>>sear;
				p=show.SearNum(sear);
				break;
			}
			case 3:{
				cout<<"������Ҫ����ѧ��֤����ѧ����ѧ�ţ�";
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


