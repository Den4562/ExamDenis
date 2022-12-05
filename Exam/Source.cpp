#include<iostream>
#include <string>
#include<Windows.h> 

using namespace std;
struct Work
{
	string name;
	int prioriti;
	string description;
	string data;
	string time;

};
 int ind = 0;
 int worksDay = 2;
 int worksWeek = 2;
 int worksMonth = 2;
 int choice = 0;
 bool whiles = true;
 Work* affairsForDay = new Work[worksDay]{};
 Work* affairsForWeek = new Work[worksWeek]{};
 Work* affairsForMonth = new Work[worksMonth]{};

void show(const Work affairs[], int amount)
{
	
	for (int i = 0; i < amount; i++)
	{
		cout <<"����."<<i<< "\n" << "��������:" << affairs[i].name << "\n" << "��������� : " << affairs[i].prioriti
			<< "\n"<< "��������:" << affairs[i].description << "\n"<<"����:" << affairs[i].data<< "\n"<< "�����:" << affairs[i].time << endl;
		cout << "--------------------------------------------------------------------"<< endl;
	}
}

void vvod( Work affairs[], int amount)
{
	setlocale(LC_ALL, "");
	for (int i = 0; i < amount; i++)
	{
		cout << "��������: ";
		cin >> affairs[i].name;
		cout << "���������: ";
		cin >> affairs[i].prioriti;
		cout << "��������: ";
		cin >> affairs[i].description;
		cout << "����:";
		cin >> affairs[i].data;
		cout << "D���� ���������: ";
		cin >> affairs[i].time;
		cout << endl;
	}
}

void VvodElement(Work affairs[], int amount, int index)
{
	while (whiles)
	{
		
		cout << "�������� ���� ������� ������ ��������: 1 - ��������. 2 - ���������. 3 - ��������. 4 - ����. 5 - �����. 6 - ��� ����. 7 - �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cin>>affairs[index].name;
			break;
		}
		case 2:
		{
			cin>>affairs[index].prioriti;
			break;
		}
		case 3:
		{
			cin>>affairs[index].description;
			break;
		}
		case 4:
		{
			cin>>affairs[index].data;
			break;
		}
		case 5:
		{
			cin>>affairs[index].time;
			break;
		}

		case 6:
		{
			cin >> affairs[index].name;
			cin >> affairs[index].prioriti;
			cin >> affairs[index].description;
			cin >> affairs[index].data;
			cin >> affairs[index].time;
			break;
		}

		}
		if (choice == 7)
		{
			break;
			system("cls");
		}
	}
	
}

void deleteAffairs(Work*& affairs, int& amount, int Index) 
{
	Work* newArray = new Work[amount--];
	for (int i = 0, j = 0; i < amount; i++, j++)
	{
		if (Index == i)
		{
			j++;
		}
		newArray[i] = affairs[j];
		
	}
	delete[]affairs; 
	affairs = newArray;
	
	
}

void AddAffairs(Work*& affairs, int& amount) 
{
	Work* newArray = new Work[amount+1];
	for (int i = 0, j = 0; i < amount; i++)
	{
		newArray[i] = affairs[i];
		
	}
	delete[]affairs; 
	affairs = newArray; 
	amount++;
}

void sortirovka(Work* arr, int amount) {
	for (int i = 0; i < amount; ++i) {
		for (int j = amount - 1; j > i; --j) {
			if (arr[j].prioriti < arr[j - 1].prioriti) {
				arr[j].name.swap(arr[j - 1].name);
				arr[j].description.swap(arr[j - 1].description);
				arr[j].data.swap(arr[j - 1].data);
				arr[j].time.swap(arr[j - 1].time);
				swap(arr[j].prioriti, arr[j - 1].prioriti);
			}
		}
	}
}

void createAffairs()
{
	while (whiles)
	{
		cout << "���� ���������� ���:\n 1- ���� �� ���� \t 2. ���� �� ������ \t 3. ���� �� ����� \t 4. �����" << endl;
		cin >> choice;
		switch (choice)
		{

		case 1:
		{
			vvod(affairsForDay, worksDay);
			system("cls");
			break;
		}
		case 2:
		{
			vvod(affairsForWeek, worksWeek);
			system("cls");
			break;
		}

		case 3:
		{
			vvod(affairsForMonth, worksMonth);
			system("cls");
			break;
		}

		}

		if (choice == 4)
		{
			system("cls");
			break;
		}
	}
}

void showAffairs()
{
	while (whiles)
	{
		cout << "���� ����������� ���:\n 1- ���� �� ���� \t 2. ���� �� ������ \t 3. ���� �� ����� \t 4. �����" << endl;
		cin >> choice;

		switch (choice)
		{

		case 1:
		{
			cout << "������� �� ������������� ������ ? 1-��, 2-���";
			cin >> choice;
			if (choice == 1)
			{
				sortirovka(affairsForDay, worksDay);
				show(affairsForDay, worksDay);
				
			}
			else
			{
				show(affairsForDay, worksDay);
			}

			break;
		}
		case 2:
		{

			cout << "������� �� ������������� ������ ? 1-��, 2-���";
			cin >> choice;
			if (choice == 1)
			{
				sortirovka(affairsForWeek, worksWeek);
				show(affairsForWeek, worksWeek);
				
			}
			else
			{
				show(affairsForWeek, worksWeek);
			}

			break;
		}

		case 3:
		{
			cout << "������� �� ������������� ������ ? 1-��, 2-���";
			cin >> choice;
			if (choice == 1)
			{
				sortirovka(affairsForMonth, worksMonth);
				show(affairsForMonth, worksMonth);
				
			}
			else
			{
				show(affairsForMonth, worksMonth);
			}
			break;
		}

		}

		if (choice == 4)
		{
			system("cls");
			break;
		}
	}
}

void redactorAffairs()
{
	while (whiles)
	{
		cout << "���� �������������� ���:\n 1- ���� �� ���� \t 2. ���� �� ������ \t 3. ���� �� ����� \t 4. �����" << endl;
		cin >> choice;

		switch (choice)
		{

		case 1:
		{
			cout << "���� �������������� ��� �� ����:\n 1- �������� \t 2. ������� \t 3. �������� ���� \t 4. �����" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{

				AddAffairs(affairsForDay, worksDay);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "������� ������ ��� �������� ����" << endl;
				cin >> ind;
				deleteAffairs(affairsForDay, worksDay, ind);
				system("cls");
				break;
			}
			case 3:
			{
				cout << "������� ������ ��� �������������� ����" << endl;
				cin >> ind;
				VvodElement(affairsForDay, worksDay, ind);
				system("cls");
				break;
			}


			}
			if (choice == 4)
				system("cls");
			break;
		}

		case 2:
		{
			cout << "���� �������������� �� ������:\n 1- �������� \t 2. ������� \t 3. �������� ���� \t 4. �����" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{

				AddAffairs(affairsForWeek, worksWeek);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "������� ������ ��� �������� ����" << endl;
				cin >> ind;
				deleteAffairs(affairsForWeek, worksWeek, ind);
				system("cls");
				break;
			}
			case 3:
			{
				cout << "������� ������ ��� �������������� ����" << endl;
				cin >> ind;
				VvodElement(affairsForWeek, worksWeek, ind);
				system("cls");
				break;
			}


			}
			if (choice == 4)
				system("cls");
			break;
		}

		case 3:
		{
			cout << "���� �������������� ��� �� �����:\n 1- �������� \t 2. ������� \t 3. �������� ���� \t 4. �����" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{

				AddAffairs(affairsForMonth, worksMonth);
				system("cls");
				break;
			}
			case 2:
			{
				cout << "������� ������ ��� �������� ����" << endl;
				cin >> ind;
				deleteAffairs(affairsForMonth, worksMonth, ind);
				system("cls");
				break;
			}
			case 3:
			{
				cout << "������� ������ ��� �������������� ����" << endl;
				cin >> ind;
				VvodElement(affairsForMonth, worksMonth, ind);
				system("cls");
				break;
			}

			}
			if (choice == 4)
				system("cls");
			break;
		}
		}

		if (choice == 4)
		{
			system("cls");
			break;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russia");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
skip:

	createAffairs();

skip2:

	showAffairs();

skip3:

	redactorAffairs();

	cout << "���� ���������: 1-���� ��������. 2-���� �����������. 3-���� ��������������. 4-����� � ��������� " << endl;
	
	int way=0;
	cin >> way;
	if (way==1)
	{
		goto skip;
	}
	else if (way==2)
	{
		goto skip2;
	}
	else if (way == 3)
	{
		goto skip3;
	}
	else
		system("cls");
	return 0;
}

