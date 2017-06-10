#pragma once
#include<iostream>
# include <fstream>  
# include <string.h> 
using namespace std;
class  Student
{
public:
	char name[20];     //姓名
	char id[10];       //学号
	int c_score;       //C++  
	int java_score;    //java  
	int ios_score;     //IOS
	int total_score;   //总分 
	Student * Next;
	void Input()
	{
		cout << "\t\t请输入学生的姓名：";  cin >> name;
		cout << "\t\t请输入学生的学号：";  cin >> id;
		cout << "\t\t请输入数学课程的成绩：";  cin >> c_score;
		cout << "\t\t请输入英语课程的成绩：";  cin >> java_score;
		cout << "\t\t请输入计算机课程的成绩：";  cin >> ios_score;
		total_score = c_score + java_score + ios_score ;
	}
	void ReadFile(istream & is)
	{
		is >> name >> id >> c_score >> java_score >> ios_score  >> total_score;
	}
	void Show()
	{
		/*cout << "姓名:" << name << endl 
			<< "学号:" << id << endl 
			<< "C++:" << c_score << endl
			<< "Java:" << java_score << endl
			<< "IOS：" << ios_score << endl 
			<< "C#:" << csharp_score << endl 
			<< "总成绩:" << total_score << endl << endl << endl;*/
		cout << "\t姓名\t学号\t数学\t英语\t计算机\t总成绩\t" << endl << "\t"
			<< name << "\t"
			<< id << "\t"
			<< c_score << "\t"
			<< java_score << "\t"
			<< ios_score << "\t"
			<< total_score << "\t" << endl << endl;
	}

};
class Studentinfo
{
public:
	Studentinfo();
	~Studentinfo();
	void ShowMenu();
	void Find();
	void Save();
	void ModifyItem();
	void RemoveItem();
	void Swap(Student *, Student *);
	void Sort();
	//void Unpass();  
	int ListCount();
	//void Average();  
	void Display()
	{
		for (Student * p = Head->Next; p != End; p = p->Next)
			p->Show();
		cout << "输入任意字符！继续……";
		getchar(); getchar();
	}
	void AddItem()
	{
		End->Input();
		End->Next = new Student; 
		End = End->Next;
		cout << "添加成功!" << endl;
		cout << "输入任意字符！继续……";
		getchar();
	}

private:
	Student * Head, *End;
	ifstream in;
	ofstream out;
	Student *FindItem(char * name)
	{
		for (Student * p = Head; p->Next != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空  
			if (!strcmp(p->Next->name, name))return p;
		return NULL;
	}
	Student *FindID(char * id)
	{
		for (Student * p = Head; p->Next != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空  
			if (!strcmp(p->Next->id, id))return p;
		return NULL;
	}

};
