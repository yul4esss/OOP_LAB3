#include <iostream>
#include <string>

using namespace std;

class Calendar {


public:

	int day;
	int month;
	int year;
	string event;

	//конструктор
	Calendar() {

		cout << "\nВведіть день: ";
		cin >> day;
		cout << "Введіть місяць: ";
		cin >> month;
		cout << "Введіть рік: ";
		cin >> year;

		//виняткові ситуації
		try {
			if ((day > 31) || (month > 12) || (year > 2023))
				throw 1;
			if ((day < 0) || (month < 0) || (year < 0))
				throw 2;
		}

		catch (int error) {
			if (error == 1) {
				cout << "Задайте дату по-людськи" << endl;
				exit(0);
			}

			if (error == 2) {
				cout << "Всі значення повинні бути більші за нуль" << endl;
				exit(0);
			}
		}
	}

	//конструктор копіювання
	Calendar(const Calendar& data) {
		this->day = data.day;
		this->month = data.month;
		this->year = data.year;
		cout << "Дата: " << data.day << "." << data.month << "." << data.year << endl;
	}

	void Print() {
		try {
			if ((day > 31) || (month > 12) || (year > 2023))
				throw 1;
			if ((day < 0) || (month < 0) || (year < 0))
				throw 2;
		}

		catch (int error) {
			if (error == 1) {
				cout << "Дата перевищує всі міжнародні стандарти" << endl;
				exit(0);
			}

			if (error == 2) {
				cout << "Всі значення повинні бути більші за нуль" << endl;
				exit(0);
			}
		}
		cout << "Дата: " << day << "." << month << "." << year << endl;
	}

	//перевантаження +=
	Calendar& operator += (int number) {
		day += number;
		month += number;
		year += number;
		if (day > 31) {
			cout << "День перевищує 31" << endl;
		}
		else if (month > 12) {
			cout << "Місяць перевищує 12" << endl;
		}
		else if (year > 2023) {
			cout << "Рік перевищує 2023" << endl;
		}
		else if ((day < 31) || (month < 12) || (year < 2023)) {
			cout << "Нова дата: " << day << "." << month << "." << year << endl;
		}
		return *this;
	}

	//перевантаження -=
	Calendar& operator -= (int number) {
		day -= number;
		month -= number;
		year -= number;
		if (day < 0) {
			cout << "День менший за 0" << endl;
		}
		else if (month < 0) {
			cout << "Місяць менший за 0" << endl;
		}
		else if (year < 0) {
			cout << "Рік менший за 0" << endl;
		}
		else if ((day < 31) || (month < 12) || (year < 2023)) {
			cout << "Нова дата: " << day << "." << month << "." << year << endl;
		}
		return *this;
	}

	//перевантаження =
	Calendar& operator = (const Calendar& data) {
		this->day = data.day;
		this->month = data.month;
		this->year = data.year;
		cout << "Присвоєна дата: " << data.day << "." << data.month << "." << data.year << endl;
		return *this;
	}

	//перевантаження ==
	bool operator == (const Calendar& data) {
		return this->day == data.day;
		return this->month == data.month;
		return this->year == data.year;
	}

	//перевантаження !=
	bool operator != (const Calendar& data) {
		return this->day != data.day;
		return this->month != data.month;
		return this->year != data.year;
	}

	//перевантаження >
	bool operator > (const Calendar& data) {
		return (this->day, this->month, this->year) > (data.day, data.month, data.year);
	}

	//перевантаження <
	bool operator < (const Calendar& data) {
		return (this->day, this->month, this->year) < (data.day, data.month, data.year);
	}

	//перевантаження >=
	bool operator >= (const Calendar& data) {
		return (this->day, this->month, this->year) >= (data.day, data.month, data.year);
	}

	//перевантаження <=
	bool operator <= (const Calendar& data) {
		return (this->day, this->month, this->year) <= (data.day, data.month, data.year);
	}

	void FindDay() {
		int n;
		cin >> n;
		if ((day == n) || (month == n) || (year == n)) {
			cout << "Дата: " << day << "." << month << "." << year << endl;
		}
		else {
			cout << "Немає такої дати" << endl;
		}
	}

	void FindDay(int findDay, int findMonth, int findYear) {
		if ((day == findDay) && (month == findMonth) && (year == findYear)) {
			cout << "Дата: " << day << "." << month << "." << year << endl;
		}
		else {
			cout << "Немає дати з таким днем" << endl;
		}
	}

};

int main() {


	setlocale(LC_ALL, "Ukrainian");

	//оголошення об'єктів класу

	Calendar d[3];

	int i;

	cout << "\nВаші дати" << endl;

	for (i = 0; i < 3; i++) {
		d[i].Print();
	}

	cout << "\nВведіть 1, якщо хочете збільшити дату та 0 - якщо ні" << endl;


	int num;
	int choice = 0;

	int innerChoice = 0;


	cin >> choice;


	if (choice == 1) {
		for (i = 0; i < 3; i++) {
			cout << "Збільшити дату " << i + 1 << "? 1-так, 0-ні" << endl;
			cin >> innerChoice;
			if (innerChoice == 1) {
				cout << "Введіть число на яке збільнити дату:" << endl;
				cin >> num;
				if (num > 0) {
					d[i] += num;
				}
				else if ((d[i].day > 31) || (d[i].month > 12) || (d[i].year > 2023)) {
					cout << "Дата перевищує всі міжнародні стандарти" << endl;
				}
			}
			if (innerChoice == 0) {
				cout << " " << endl;
			}
		}
	}
	if (choice == 0) {
		cout << "\nПерехід до наступного кроку: " << endl;
	}

	cout << "Введіть 1, якщо хочете зменшити дату та 0 - якщо ні" << endl;
	cin >> choice;

	if (choice == 1) {
		for (i = 0; i < 3; i++) {
			cout << "Зменшити дату для " << i + 1 << " ? 1-так, 0-ні" << endl;
			cin >> innerChoice;
			if (innerChoice == 1) {
				cout << "Введіть число на яке зменшити дату: " << endl;
				cin >> num;
				if (num > 0) {
					d[i] -= num;
				}
				else if ((d[i].day < 0) || (d[i].month < 0) || (d[i].year < 0)){
					cout << "Всі значення повинні бути більші за нуль" << endl;
				}
			}
			if (innerChoice == 0) {
				cout << " " << endl;
			}
		}
	}
	if (choice == 0) {
		cout << " " << endl;
	}

	cout << "Ваші дати" << endl;
	for (i = 0; i < 3; i++) {
		d[i].Print();
	}

	for (i = 0; i < 3; i++) {
		cout << "\nВведіть число, шукане в даті "<< i + 1 << endl;
		d[i].FindDay();
	}

	cout << "\nВикористання перевантаження методу" << endl;
	for (i = 0; i < 1; i++) {
		d[i].FindDay(12, 3, 2004);
	}
	
	//порівняння дат

	bool compare1 = d[0] > d[1];
	bool compare2 = d[1] > d[2];
	bool compare3 = d[2] > d[1];
	bool compare4 = d[0] < d[1];


	cout << " " << endl;
	cout << "Дата 1 більша за дату 2 (1-так, 0-ні): " << compare1 << endl;
	cout << "Дата 2 більша за дату 3 (1-так, 0-ні): " << compare2 << endl;
	cout << "Дата 3 більша за дату 2 (1-так, 0-ні): " << compare3 << endl;
	cout << "Дата 2 більша за дату 1 (1-так, 0-ні):  " << compare4 << endl;

	bool rivno1 = d[0] == d[1];
	bool rivno2 = d[1] == d[2];
	bool rivno3 = d[2] == d[1];
	bool rivno4 = d[0] == d[1];
	
	cout << " " << endl;
	cout << "Дата 1 однакова з датою 2 (1-так, 0-ні): " << rivno1 << endl;
	cout << "Дата 2 однакова з датою 3 (1-так, 0-ні): " << rivno1 << endl;
	cout << "Дата 3 однакова з датою 2 (1-так, 0-ні): " << rivno1 << endl;
	cout << "Дата 2 однакова з датою 1 (1-так, 0-ні): " << rivno1 << endl;

	return 0;
}