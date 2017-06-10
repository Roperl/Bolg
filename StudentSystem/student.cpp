// StudentSystem.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "student.h"
//���캯��
Studentinfo::Studentinfo()
{
	Head = new Student;
	Head->Next = new Student;
	End = Head->Next;
	in.open("sort.dat");
	if (!in)
		cout << "\t\t��ϵͳ��û�����ݣ�����¼�����ݣ���" << endl;
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
		cout << "\t\t��ȡѧ����Ϣ�ɹ�!" << endl;
	}
} 
//��������
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
//���ܲ˵�
void Studentinfo::ShowMenu()
{
	cout << "--------------------------------------------------------------------------------" << endl;
	cout << "*********************         ѧ���ɼ�����ϵͳ      ****************************" << endl;
	cout << "---------------------                     Written by:                           " << endl;
    cout << "                                                     Roper                      " << endl<<endl;
	cout << "---------------------          1.���ѧ���ɼ�        ---------------------------" << endl;
	cout << "---------------------          2.��ʾѧ���ɼ�        ---------------------------" << endl;
	cout << "---------------------          3.����ͳ�Ƴɼ�        ---------------------------" << endl;
	cout << "---------------------          4.����ѧ���ɼ�        ---------------------------" << endl;
	cout << "---------------------          5.ɾ��ѧ���ɼ�        ---------------------------" << endl;
	cout << "---------------------          6.�޸�ѧ����Ϣ        ---------------------------" << endl;
	cout << "---------------------          0.��ȫ�˳�ϵͳ        ---------------------------" << endl;

	cout << "\n\t\t\n\t\t��ѡ��";
}

//����
void Studentinfo::Find()
{
	char name[10], id[10];
	int x;
	Student * p = NULL;
	cout << "\n\t\t*********************************\n";
	cout << "\t\t�� 1.��ѧ������������\n\t\t�� 2.��ѧ��ѧ�Ų���";
	cout << "\n\t\t*********************************\n��ѡ��";
	cin >> x;
	switch (x)
	{
	case 1: {cout << "\t\t������Ҫ���ҵ�ѧ����������"; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "���������ַ�����������";
			getchar();
		}
		else
		{
			cout << "\t\tû���ҵ���������ѧ����" << '\n' << endl;
			cout << "���������ַ�����������";
			getchar();
		}
	}break;
	case 2:
	{
		cout << "\t\t������Ҫ���ҵ�ѧ����ѧ�ţ�"; cin >> id;
		if (p = FindID(id))
		{
			p->Next->Show();
			cout << "���������ַ�����������";
			getchar();
		}
		else
		{
			cout << "\t\tû���ҵ���ѧ�õ�ѧ����" << '\n' << endl;
			cout << "���������ַ�����������";
			getchar();
		}
	}break;
	}

}
//�޸���Ϣ 
void Studentinfo::ModifyItem()     
{
	char name[20];
	Student * p = NULL;
	cout << "\t\t������Ҫ�޸ĵ��˵�����:"; cin >> name;
	if (p = FindItem(name))
	{
		cout << "\t\t���ҵ�ѧ������Ϣ���������µ���Ϣ!" << endl;
		p->Next->Input();
		cout << "�޸ĳɹ���" << endl;
		cout << "���������ַ�����������";
		getchar();
	}
	else
	{
		cout << "\t\tû���ҵ�!" << endl;
		cout << "���������ַ�����������";
		getchar();
	}
}

// ɾ����Ϣ
void Studentinfo::RemoveItem()           
{
	char name[20];
	Student * p = NULL, *temp = NULL;
	cout << "\t\t������Ҫɾ����ѧ��������:" << endl; cin >> name;
	if (p = FindItem(name))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t\tɾ���ɹ�!" << endl;
		cout << "���������ַ�����������";
		getchar();
	}
	else
	{
		cout << "\t\tû���ҵ�!" << endl;
		cout << "���������ַ�����������";
		getchar();
	}
}

//��������combox������������ 
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
//ͳ�Ƶ�ǰ����ļ�¼����������һ������ 
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
//�Ե�ǰ�����������  
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
	cout << "������ɣ�" << endl;
	getchar();
	return;
}
//�洢
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
