#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main(){
	char ifstream[256],ofstream[256];
	char buff[4096];
	cout<<"����Դ�ļ�����"<<endl;
	cin>>ifstream;
	cout<<"����Ŀ���ļ�����"<<endl;
	cin>>ofstream;
	cout<<"�������"<<endl;
	fstream fin,fout;
	fin.open(ifstream,ios::in | ios::binary );
	if(!fin){
		cout<<"Դ�ļ���ʧ�ܣ�"<<endl;
		exit(1);
	}
	fout.open(ofstream,ios::out | ios::binary);
	if(!fout){
		cout<<"Ŀ���ļ���ʧ�ܣ�"<<endl;
		exit(1);
	}
	int n;
	while(!fin.eof()){
		fin.read(buff,4096);
		n=fin.gcount();
		fout.write(buff,n);
	}
	cout<<"�ѳɹ�����Դ�ļ�"<<ifstream<<"��Ŀ���ļ�"<<ofstream<<endl;
	fin.close();
	fout.close(); 
	return 0;
}
