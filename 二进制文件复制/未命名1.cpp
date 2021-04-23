#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main(){
	char ifstream[256],ofstream[256];
	char buff[4096];
	cout<<"输入源文件名："<<endl;
	cin>>ifstream;
	cout<<"输入目的文件名："<<endl;
	cin>>ofstream;
	cout<<"输入完毕"<<endl;
	fstream fin,fout;
	fin.open(ifstream,ios::in | ios::binary );
	if(!fin){
		cout<<"源文件打开失败！"<<endl;
		exit(1);
	}
	fout.open(ofstream,ios::out | ios::binary);
	if(!fout){
		cout<<"目的文件打开失败！"<<endl;
		exit(1);
	}
	int n;
	while(!fin.eof()){
		fin.read(buff,4096);
		n=fin.gcount();
		fout.write(buff,n);
	}
	cout<<"已成功复制源文件"<<ifstream<<"到目的文件"<<ofstream<<endl;
	fin.close();
	fout.close(); 
	return 0;
}
