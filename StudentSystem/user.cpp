#include "stdafx.h"
#include<iostream>
#include"student.h"
int main()
{
	int x, i = 0;
	bool quit = false;
	cout << endl << endl;
	cout << "\t\tWelcome To Student Achievement Management System." << endl << endl << endl;
	Studentinfo Grade;
	cout << "\t\t按任意键开始……";
	getchar();
	while (!quit)
	{
		system("cls");
		Grade.ShowMenu();
		cin >> x;
		switch (x)
		{
		case 0:quit = true; break;
		case 1:Grade.AddItem(); break;
		case 2:Grade.Display(); break;
		case 3:Grade.Sort(); break;
		case 4:Grade.Find(); break;
		case 5:Grade.RemoveItem(); break;
		case 6:Grade.ModifyItem(); break;
		}
	}
	return 0;
}
