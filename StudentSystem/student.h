#pragma once
#include<iostream>
# include <fstream>  
# include <string.h> 
using namespace std;
class  Student
{
public:
	char name[20];     //����
	char id[10];       //ѧ��
	int c_score;       //C++  
	int java_score;    //java  
	int ios_score;     //IOS
	int total_score;   //�ܷ� 
	Student * Next;
	void Input()
	{
		cout << "\t\t������ѧ����������";  cin >> name;
		cout << "\t\t������ѧ����ѧ�ţ�";  cin >> id;
		cout << "\t\t��������ѧ�γ̵ĳɼ���";  cin >> c_score;
		cout << "\t\t������Ӣ��γ̵ĳɼ���";  cin >> java_score;
		cout << "\t\t�����������γ̵ĳɼ���";  cin >> ios_score;
		total_score = c_score + java_score + ios_score ;
	}
	void ReadFile(istream & is)
	{
		is >> name >> id >> c_score >> java_score >> ios_score  >> total_score;
	}
	void Show()
	{
		/*cout << "����:" << name << endl 
			<< "ѧ��:" << id << endl 
			<< "C++:" << c_score << endl
			<< "Java:" << java_score << endl
			<< "IOS��" << ios_score << endl 
			<< "C#:" << csharp_score << endl 
			<< "�ܳɼ�:" << total_score << endl << endl << endl;*/
		cout << "\t����\tѧ��\t��ѧ\tӢ��\t�����\t�ܳɼ�\t" << endl << "\t"
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
		cout << "���������ַ�����������";
		getchar(); getchar();
	}
	void AddItem()
	{
		End->Input();
		End->Next = new Student; 
		End = End->Next;
		cout << "��ӳɹ�!" << endl;
		cout << "���������ַ�����������";
		getchar();
	}

private:
	Student * Head, *End;
	ifstream in;
	ofstream out;
	Student *FindItem(char * name)
	{
		for (Student * p = Head; p->Next != End; p = p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�  
			if (!strcmp(p->Next->name, name))return p;
		return NULL;
	}
	Student *FindID(char * id)
	{
		for (Student * p = Head; p->Next != End; p = p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�  
			if (!strcmp(p->Next->id, id))return p;
		return NULL;
	}

};
