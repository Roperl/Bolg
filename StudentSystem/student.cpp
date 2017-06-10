// StudentSystem.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "student.h"
//构造函数
Studentinfo::Studentinfo()
{
	Head = new Student;
	Head->Next = new Student;
	End = Head->Next;
	in.open("sort.dat");
	if (!in)
		cout << "\t\t此系统还没有数据，请先录入数据！！" << endl;
	else
	{
		while (!in.eof())
		{
			End->ReadFile(in);
			if (End->name[0] == '\0')break;
			End->Next = new Student;
			End = End->Next;
		}
		in.close();
		cout << "\t\t读取学生信息成功!" << endl;
	}
} 
//析构函数
Studentinfo::~Studentinfo()
{
	Save();
	for (Student * temp; Head->Next != End;)
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head, End;
}
//功能菜单
void Studentinfo::ShowMenu()
{
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "*********************         学生成绩管理系统      ****************************" << endl;
	cout << "---------------------                     Written by:                           " << endl;
    cout << "                                                     Roper                      " << endl<<endl;
	cout << "---------------------          1.添加学生成绩        ---------------------------" << endl;
	cout << "---------------------          2.显示学生成绩        ---------------------------" << endl;
	cout << "---------------------          3.排序统计成绩        ---------------------------" << endl;
	cout << "---------------------          4.查找学生成绩        ---------------------------" << endl;
	cout << "---------------------          5.删除学生成绩        ---------------------------" << endl;
	cout << "---------------------          6.修改学生信息        ---------------------------" << endl;
	cout << "---------------------          0.安全退出系统        ---------------------------" << endl;

	cout << "\n\t\t\n\t\t请选择：";
}

//查找
void Studentinfo::Find()
{
	char name[10], id[10];
	int x;
	Student * p = NULL;
	cout << "\n\t\t*********************************\n";
	cout << "\t\t※ 1.按学生的姓名查找\n\t\t※ 2.按学生学号查找";
	cout << "\n\t\t*********************************\n请选择：";
	cin >> x;
	switch (x)
	{
	case 1: {cout << "\t\t请输入要查找的学生的姓名："; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "输入任意字符！继续……";
			getchar();
		}
		else
		{
			cout << "\t\t没有找到该姓名的学生！" << '\n' << endl;
			cout << "输入任意字符！继续……";
			getchar();
		}
	}break;
	case 2:
	{
		cout << "\t\t请输入要查找的学生的学号："; cin >> id;
		if (p = FindID(id))
		{
			p->Next->Show();
			cout << "输入任意字符！继续……";
			getchar();
		}
		else
		{
			cout << "\t\t没有找到该学好的学生！" << '\n' << endl;
			cout << "输入任意字符！继续……";
			getchar();
		}
	}break;
	}

}
//修改信息 
void Studentinfo::ModifyItem()     
{
	char name[20];
	Student * p = NULL;
	cout << "\t\t请输入要修改的人的姓名:"; cin >> name;
	if (p = FindItem(name))
	{
		cout << "\t\t已找到学生的信息，请输入新的信息!" << endl;
		p->Next->Input();
		cout << "修改成功！" << endl;
		cout << "输入任意字符！继续……";
		getchar();
	}
	else
	{
		cout << "\t\t没有找到!" << endl;
		cout << "输入任意字符！继续……";
		getchar();
	}
}

// 删除信息
void Studentinfo::RemoveItem()           
{
	char name[20];
	Student * p = NULL, *temp = NULL;
	cout << "\t\t请输入要删除的学生的姓名:" << endl; cin >> name;
	if (p = FindItem(name))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t\t删除成功!" << endl;
		cout << "输入任意字符！继续……";
		getchar();
	}
	else
	{
		cout << "\t\t没有找到!" << endl;
		cout << "输入任意字符！继续……";
		getchar();
	}
}

//交换两个combox变量的数据域 
void Studentinfo::Swap(Student *p1, Student *p2)  
{
	Student *temp = new Student;
	strcpy_s(temp->name, p1->name);
	strcpy_s(temp->id, p1->id);
	temp->c_score = p1->c_score;
	temp->java_score = p1->java_score;
	temp->ios_score = p1->ios_score;
	temp->total_score = p1->total_score;

	strcpy_s(p1->name, p2->name);
	strcpy_s(p1->id, p2->id);
	p1->c_score = p2->c_score;
	p1->java_score = p2->java_score;
	p1->ios_score = p2->ios_score;
	p1->total_score = p1->total_score;

	strcpy_s(p2->name, temp->name);
	strcpy_s(p2->id, temp->id);
	p2->c_score = temp->c_score;
	p2->java_score = temp->java_score;
	p2->ios_score = temp->ios_score;
	p2->total_score = temp->total_score;
}
//统计当前链表的记录总数，返回一个整数 
int Studentinfo::ListCount() 
{
	if (!Head)
		return 0;
	int n = 0;
	for (Student * p = Head->Next; p != End; p = p->Next)
	{
		n++;
	}
	return n;
}
//对当前链表进行排序  
void Studentinfo::Sort()  
{
	cout << "Sorting..." << endl;
	Student *p = NULL, *p1 = NULL, *k = NULL;
	int n = Studentinfo::ListCount();
	if (n<2)
		return;
	for (p = Head->Next; p != End; p = p->Next)
		for (k = p->Next; k != End; k = k->Next)
		{
			if (p->total_score>k->total_score)
			{
				Studentinfo::Swap(p, k);
			}
		}
	cout << "排序完成！" << endl;
	getchar();
	return;
}
//存储
void Studentinfo::Save()
{
	out.open("sort.dat");
	for (Student *p = Head->Next; p != End; p = p->Next)
		out << p->name << "\t" 
		<< p->id << "\t" 
		<< p->c_score << "\t"
		<< p->java_score << "\t" 
		<< p->ios_score << "\t" 
		<< p->total_score << '\n';
	out.close();
}
