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
		cout <<"Дело."<<i<< "\n" << "Название:" << affairs[i].name << "\n" << "Приоритет : " << affairs[i].prioriti
			<< "\n"<< "Описание:" << affairs[i].description << "\n"<<"Дата:" << affairs[i].data<< "\n"<< "время:" << affairs[i].time << endl;
		cout << "--------------------------------------------------------------------"<< endl;
	}
}

void vvod( Work affairs[], int amount)
{
	setlocale(LC_ALL, "");
	for (int i = 0; i < amount; i++)
	{
		cout << "Название: ";
		cin >> affairs[i].name;
		cout << "Приоритет: ";
		cin >> affairs[i].prioriti;
		cout << "Описание: ";
		cin >> affairs[i].description;
		cout << "Дата:";
		cin >> affairs[i].data;
		cout << "Dремя исполения: ";
		cin >> affairs[i].time;
		cout << endl;
	}
}

void VvodElement(Work affairs[], int amount, int index)
{
	while (whiles)
	{
		
		cout << "Выберите поле которое хотите изменить: 1 - Название. 2 - Приоритет. 3 - Описание. 4 - Дата. 5 - Время. 6 - Все поля. 7 - Выход" << endl;
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
		cout << "Меню заполнения дел:\n 1- Дела на день \t 2. Дела на неделю \t 3. Дела на месяц \t 4. Выход" << endl;
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
		cout << "Меню отображения дел:\n 1- Дела за день \t 2. Дела за неделю \t 3. Дела за месяц \t 4. Выход" << endl;
		cin >> choice;

		switch (choice)
		{

		case 1:
		{
			cout << "Желаете ли отсортировать данные ? 1-да, 2-нет";
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

			cout << "Желаете ли отсортировать данные ? 1-да, 2-нет";
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
			cout << "Желаете ли отсортировать данные ? 1-да, 2-нет";
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
		cout << "Меню редактирования дел:\n 1- Дела за день \t 2. Дела за неделю \t 3. Дела за месяц \t 4. Выход" << endl;
		cin >> choice;

		switch (choice)
		{

		case 1:
		{
			cout << "Меню редактирования дел за день:\n 1- Добавить \t 2. Удалить \t 3. Изменить поля \t 4. Выход" << endl;
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
				cout << "Укажите индекс для удаления дела" << endl;
				cin >> ind;
				deleteAffairs(affairsForDay, worksDay, ind);
				system("cls");
				break;
			}
			case 3:
			{
				cout << "Укажите индекс для редактирования дела" << endl;
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
			cout << "Меню редактирования за неделю:\n 1- Добавить \t 2. Удалить \t 3. Изменить поля \t 4. Выход" << endl;
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
				cout << "Укажите индекс для удаления дела" << endl;
				cin >> ind;
				deleteAffairs(affairsForWeek, worksWeek, ind);
				system("cls");
				break;
			}
			case 3:
			{
				cout << "Укажите индекс для редактирования дела" << endl;
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
			cout << "Меню редактирования дел за месяц:\n 1- Добавить \t 2. Удалить \t 3. Изменить поля \t 4. Выход" << endl;
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
				cout << "Укажите индекс для удаления дела" << endl;
				cin >> ind;
				deleteAffairs(affairsForMonth, worksMonth, ind);
				system("cls");
				break;
			}
			case 3:
			{
				cout << "Укажите индекс для редактирования дела" << endl;
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

	cout << "Меню навигации: 1-Меня создания. 2-Меню отображения. 3-Меню редактирования. 4-Выход с программы " << endl;
	
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

