//使用了文件sstream中的stringstream 
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main(){
	int x[2];
	ifstream fin;
	fin.open("text.txt");
	if(!fin){
		cout<<"文件打开失败"<<endl;
		exit(1);
	}
	cout<<"文件打开成功"<<endl;
	
	stringstream ss;
	string str;
	getline(fin,str);
	ss<<str;
	int i=0;
	while(!ss.eof()){
		ss>>x[i];//实现了string转换成int 
		i++;
	}
	
	cout<<"请输入两个数字："<<endl;
	//cin>>x[0]>>x[1];
	cout<<"x[0]="<<x[0]<<",x[1]="<<x[1]<<endl;
	cout<<"这两个数字的和为："<<x[0]+x[1]<<endl;
	return 0;
}
