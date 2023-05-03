#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;
string get_random_fio();
string get_random_phone();
string get_random_address();
int get_random_number();
int sum_date(string str);

string surnames[10] = { "Байдина" , "Куртагина" , "Ковина", "Басалаев", "Сычихин", "Рыжов", "Кильдяев", "Коннов", "Мурин","Яцута" };
string names[10] = { "Ирина" , "Марина" , "Татьяна", "Александр", "Олег", "Дмитрий", "Владислав", "Игорь", "Денис","Евгений" };
string patronymic[10] = { "Федоровна" , "Владимировна" , "Павловна", "Васильевич", "Георгевич", "Олегович", "Валерьевич", "Александрович", "Дмитриевич","Андонович" };
string phones[10] = { "79234757342","7514675321","79647890456","79863214007","73425673457","73246784567","79822326507","79030080305","79320093411","74531334456" };
string address[10] = { "ул. Ленина 22","ул. Крианова 23"," ул. Маяковского 59","ул. Победы 1","ул. Дружбы 8","ул. Крисанова 55","ул. Чернышевского 17","ул. Садовая 6","ул. Подлесная 93","ул. Строителей 42" };
int collision_count = 0;

struct Staff
{
	Staff()
	{
		fio = "NULL";
		phone = "NULL";
		address = "NULL";
	}
	string fio;
	string phone;
	string address;
};

struct hash_table
{
	Staff* arr;
	hash_table(int size)
	{
		arr = new Staff[size];
	}
	void add(Staff tmp, int size);
	void pop(string delete_phone, int size);
	void search_index(string phone, int size);
};

Staff create_random_human()
{
	Staff tmp;
	tmp.fio = get_random_fio();
	tmp.phone = get_random_phone();
	tmp.address = get_random_address();
	return tmp;
}

int hashFunction(string str, int size)
{
	int sum = 0; int a = 0;
	for (int i = 0; i < str.length(); i++)
	{
		a = str[i];
		sum += a;
	}
	sum = sum % size;
	return sum;
}

void hash_table::add(Staff tmp, int size)
{
	int idx = hashFunction(tmp.phone, size);
	int hash = idx;
	if (arr[idx].fio == "NULL")
	{
		arr[idx] = tmp;
		return;
	}
	else
	{
		while (idx < size)
		{
			if (arr[idx].fio == "NULL")
			{
				arr[idx] = tmp;
				return;
			}
			idx++;
			collision_count++;
		}
		if (idx >= size)
		{
			idx = 0;
			collision_count++;
			while (idx < hash)
			{
				if (arr[idx].fio == "NULL")
				{
					arr[idx] = tmp;
					return;
				}
				idx++;
				collision_count++;
			}
		}
	}
}

void hash_table::pop(string delete_phone, int size)
{
	int idx = hashFunction(delete_phone, size);
	int hash = idx;
	if (arr[idx].phone == delete_phone)
	{
		arr[idx] = Staff();
		return;
	}
	else
	{
		while (idx < size)
		{
			if (arr[idx].phone == delete_phone)
			{
				arr[idx] = Staff();
				return;
			}
			idx++;
		}
		if (idx >= size)
		{
			idx = 0;
			while (idx < hash)
			{
				if (arr[idx].phone == delete_phone)
				{
					arr[idx] = Staff();
					return;
				}
				idx++;
			}
		}
	}
}

void hash_table::search_index(string phone, int size)
{
	int idx = hashFunction(phone, size);
	int hash = idx;
	while (arr[idx].phone != phone && idx < size)
	{
		idx++;
	}
	if (idx >= size)
	{
		idx = 0;
		while (arr[idx].phone != phone && idx < hash)
		{
			idx++;
		}
		if (idx >= hash)
		{
			cout << " Номер телефона сотрудника" << phone << " нет " << endl;
		}
	}
	else
	{
		cout << "Номер телефона сотрудника " << phone << " находится по индексу " << idx << endl;
	}
}

void fill_arr_of_random_staffs(Staff* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = create_random_human();
	}
}

void show(Staff tmp)
{
	cout << "ФИО: " << tmp.fio << endl;
	cout << "Номер телефона: " << tmp.phone << endl;
	cout << "Адрес проживания: " << tmp.address << endl;
}

void print_arr_of_humans(Staff* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		show(arr[i]);
	}
}

void show_hash_table(hash_table* table, int size)
{
	for (int i = 0; i < size; i++)
	{
		show(table->arr[i]);
	}
}

int sum_date(string str)
{
	return stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
}

string get_random_fio()
{
	return (surnames[get_random_number()] + ' ' + names[get_random_number()] + ' ' + patronymic[get_random_number()]);
}

string get_random_phone()
{
	return phones[get_random_number()];
}

string get_random_address()
{
	return address[get_random_number()];
}

int get_random_number()
{
	return rand() % 10;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int size;
	string phone;
	cout << "Введите количество элементов в массиве (не менее 100)" << endl;
	cin >> size;
	Staff* arr = new Staff[size];
	hash_table table(size);
	fill_arr_of_random_staffs(arr, size);
	for (int i = 0; i < size; i++)
	{
		table.add(arr[i], size);
	}
	show_hash_table(&table, size);
	cout << endl << endl;
	cout << "Введите данные для удаления" << endl;
	cin >> phone;
	cout << endl;
	table.search_index(phone, size);
	cout << endl << endl;
	show_hash_table(&table, size);
	cout << endl << endl;
	cout << "Введите данные для удаления" << endl;
	cin >> phone;
	table.pop(phone, size);
	cout << endl << endl;
	show_hash_table(&table, size);
	cout << endl << endl;
	cout << "Количество колизий:  " << collision_count << endl;
	delete[] arr;
	return 0;
}