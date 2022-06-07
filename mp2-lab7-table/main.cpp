#include <iostream>
#include <clocale>
#include <cstdlib>
#include "ScanTable.h"
#include "SortTable.h"
#include "ArrayHashTable.h"
#include "TreeTable.h"

using namespace std;

void TabMenu(Table* table, int mode, int Count, int keys, int MemSize = 100)
{
	TKey _key;
	TValue _val;
	switch (mode)
	{
	/*case 1:
	{
		table = new ScanTable(MemSize);
		for (int i = 0; i < Count; i++)
		{
			_key = rand() % keys;
			_val = "*";
			_val += to_string(_key);
			_val += "*";
			Record rec(_key,_val);
			table->InsRecord(rec);
		}
		cout << *table << "*------------------*\n" << "Efficiency: " << table->GetEfficiency() << "\n*------------------*\n" << endl;
		table->ClearEfficiency();
		break;
	}*/
	case 2:
	{
		/*table = new SortTable(MemSize);
		for (int i = 0; i < Count; i++)
		{
			_key = rand() % keys;
			_val = "*";
			_val += to_string(_key);
			_val += "*";
			Record rec(_key, _val);
			table->InsRecord(rec);
		}*/
		cout << *table << "*------------------*\n" << "Efficiency: " << table->GetEfficiency() << "\n*------------------*\n" << endl;
		table->ClearEfficiency();
		break;
	}
	case 3:
	{
		table = new ArrayHashTable(MemSize);
		for (int i = 0; i < Count; i++)
		{
			_key = rand() % keys;
			_val = "*";
			_val += to_string(_key);
			_val += "*";
			Record rec(_key, _val);
			table->InsRecord(rec);
		}
		cout << *table << "*------------------*\n" << "Efficiency: " << table->GetEfficiency() << "\n*------------------*\n" << endl;
		table->ClearEfficiency();
		break;
	}
	}
	int op = 10;
	cout <<"Выберите операцию" << endl;
	while (op)
	{
		cout << "1 - поиск\n 2 - вставка\n 3 - удаление\n 4 - печать таблицы\n 0 - выход\n" << endl;
		cin >> op;
		if (op == 1)
		{
			TKey _Key;
			cout << "Введите номер ключа:" << endl;
			cin >> _Key;
			table->ClearEfficiency();
			if (table->FindRecord(_Key))
			{
				cout << "Запись найдена" << endl << "Efficiency: " << table->GetEfficiency() << endl;
			}
			else
			{
				cout << "Запись отсутствует" << endl << "Efficiency: " << table->GetEfficiency() << endl;
			}
			table->ClearEfficiency();
		}
		if (op == 2)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			TValue _Val = "*";
			_Val += to_string(_Key);
			_Val += "*";
			table->ClearEfficiency();
			Record rec(_Key, _Val);
			table->InsRecord(rec);
			cout << "Efficiency: " << table->GetEfficiency() << endl;
			table->ClearEfficiency();
		}
		if (op == 3)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			table->ClearEfficiency();
			table->DelRecord(_Key);
			cout << "Efficiency: " << table->GetEfficiency() << endl;
			table->ClearEfficiency();
		}
		if (op == 4)
		{
			cout << *table << endl;
		}
	}
}

void TreeTabMenu(TreeTable* table, int Count, int keys)
{
	TKey _key;
	TValue _val;
	table = new TreeTable();
	for (int i = 0; i < Count; i++)
	{
		_key = rand() % keys;
		_val = "*";
		_val += to_string(_key);
		_val += "*";
		Record rec(_key, _val);
		table->InsRecord(rec);
	}
	table->GetEfficiency();
	cout << *table << "*------------------*\n" << "Efficiency: " << table->GetEfficiency() << "\n*------------------*\n" << endl;
	table->ClearEfficiency();
	int op = 10;
	cout << "Введите операцию" << endl;
	while (op)
	{
		cout << "1 - поиск, 2 - вставка, 3 - удаление , 4 - печать таблицы, 5 - печать таблицы ярусами, 0 - выход" << endl;
		cin >> op;
		if (op == 1)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			table->ClearEfficiency();
			if (table->FindRecord(_Key))
			{
				cout << "Запись найдена" << endl << "Efficiency: " << table->GetEfficiency() << endl;
			}
			else
			{
				cout << "Запись отсутствует" << endl << "Efficiency: " << table->GetEfficiency() << endl;
			}
			table->ClearEfficiency();
		}
		if (op == 2)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			TValue _Val = "*";
			_Val += to_string(_Key);
			_Val += "*";
			table->ClearEfficiency();
			Record rec(_Key, _Val);
			table->InsRecord(rec);
			cout << "Efficiency: " << table->GetEfficiency() << endl;
			table->ClearEfficiency();
		}
		if (op == 3)
		{
			TKey _Key;
			cout << "Введите ключ:" << endl;
			cin >> _Key;
			table->ClearEfficiency();
			table->DelRecord(_Key);
			cout << "Efficiency: " << table->GetEfficiency() << endl;
			table->ClearEfficiency();
		}
		if (op == 4)
		{
			cout << *table << endl;
		}
		if (op == 5)
		{
			table->DrawTab();
		}
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	/*--------------------------------------------------*/
	Table* table = NULL;
	TreeTable* TreeTab = NULL;
	int mode;
	int Count;
	int keys;
	int MemSize = 0;
	cout << "Выберите тип таблицы:" << endl;
	cout << "ScanTable - 1, SortTable - 2, ArrayHash - 3, TreeTable - 4" << endl;
	cin >> mode;
	if (mode != 4)
	{
		cout << "Введите:" << endl << "Количество записей, диапазон ключей, размер памяти" << endl;
		cin >> Count >> keys >> MemSize;
		TabMenu(table, mode, Count, keys, MemSize);
	}
	else
	{
		cout << "Введите:" << endl << "Количество записей, диапазон ключей" << endl;
		cin >> Count >> keys;
		TreeTabMenu(TreeTab, Count, keys);
	}
	/*--------------------------------------------------*/
	system("pause");
	return 0;
}












