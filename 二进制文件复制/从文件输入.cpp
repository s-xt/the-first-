//ʹ�����ļ�sstream�е�stringstream 
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main(){
	int x[2];
	ifstream fin;
	fin.open("text.txt");
	if(!fin){
		cout<<"�ļ���ʧ��"<<endl;
		exit(1);
	}
	cout<<"�ļ��򿪳ɹ�"<<endl;
	
	stringstream ss;
	string str;
	getline(fin,str);
	ss<<str;
	int i=0;
	while(!ss.eof()){
		ss>>x[i];//ʵ����stringת����int 
		i++;
	}
	
	cout<<"�������������֣�"<<endl;
	//cin>>x[0]>>x[1];
	cout<<"x[0]="<<x[0]<<",x[1]="<<x[1]<<endl;
	cout<<"���������ֵĺ�Ϊ��"<<x[0]+x[1]<<endl;
	return 0;
}
