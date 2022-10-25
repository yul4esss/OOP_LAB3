#include <iostream>
#include <string>

using namespace std;

class Calendar {


public:

	int day;
	int month;
	int year;
	string event;

	//�����������
	Calendar() {

		cout << "\n������ ����: ";
		cin >> day;
		cout << "������ �����: ";
		cin >> month;
		cout << "������ ��: ";
		cin >> year;

		//�������� ��������
		try {
			if ((day > 31) || (month > 12) || (year > 2023))
				throw 1;
			if ((day < 0) || (month < 0) || (year < 0))
				throw 2;
		}

		catch (int error) {
			if (error == 1) {
				cout << "������� ���� ��-�������" << endl;
				exit(0);
			}

			if (error == 2) {
				cout << "�� �������� ������ ���� ����� �� ����" << endl;
				exit(0);
			}
		}
	}

	//����������� ���������
	Calendar(const Calendar& data) {
		this->day = data.day;
		this->month = data.month;
		this->year = data.year;
		cout << "����: " << data.day << "." << data.month << "." << data.year << endl;
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
				cout << "���� �������� �� �������� ���������" << endl;
				exit(0);
			}

			if (error == 2) {
				cout << "�� �������� ������ ���� ����� �� ����" << endl;
				exit(0);
			}
		}
		cout << "����: " << day << "." << month << "." << year << endl;
	}

	//�������������� +=
	Calendar& operator += (int number) {
		day += number;
		month += number;
		year += number;
		if (day > 31) {
			cout << "���� �������� 31" << endl;
		}
		else if (month > 12) {
			cout << "̳���� �������� 12" << endl;
		}
		else if (year > 2023) {
			cout << "г� �������� 2023" << endl;
		}
		else if ((day < 31) || (month < 12) || (year < 2023)) {
			cout << "���� ����: " << day << "." << month << "." << year << endl;
		}
		return *this;
	}

	//�������������� -=
	Calendar& operator -= (int number) {
		day -= number;
		month -= number;
		year -= number;
		if (day < 0) {
			cout << "���� ������ �� 0" << endl;
		}
		else if (month < 0) {
			cout << "̳���� ������ �� 0" << endl;
		}
		else if (year < 0) {
			cout << "г� ������ �� 0" << endl;
		}
		else if ((day < 31) || (month < 12) || (year < 2023)) {
			cout << "���� ����: " << day << "." << month << "." << year << endl;
		}
		return *this;
	}

	//�������������� =
	Calendar& operator = (const Calendar& data) {
		this->day = data.day;
		this->month = data.month;
		this->year = data.year;
		cout << "�������� ����: " << data.day << "." << data.month << "." << data.year << endl;
		return *this;
	}

	//�������������� ==
	bool operator == (const Calendar& data) {
		return this->day == data.day;
		return this->month == data.month;
		return this->year == data.year;
	}

	//�������������� !=
	bool operator != (const Calendar& data) {
		return this->day != data.day;
		return this->month != data.month;
		return this->year != data.year;
	}

	//�������������� >
	bool operator > (const Calendar& data) {
		return (this->day, this->month, this->year) > (data.day, data.month, data.year);
	}

	//�������������� <
	bool operator < (const Calendar& data) {
		return (this->day, this->month, this->year) < (data.day, data.month, data.year);
	}

	//�������������� >=
	bool operator >= (const Calendar& data) {
		return (this->day, this->month, this->year) >= (data.day, data.month, data.year);
	}

	//�������������� <=
	bool operator <= (const Calendar& data) {
		return (this->day, this->month, this->year) <= (data.day, data.month, data.year);
	}

	void FindDay() {
		int n;
		cin >> n;
		if ((day == n) || (month == n) || (year == n)) {
			cout << "����: " << day << "." << month << "." << year << endl;
		}
		else {
			cout << "���� ���� ����" << endl;
		}
	}

	void FindDay(int findDay, int findMonth, int findYear) {
		if ((day == findDay) && (month == findMonth) && (year == findYear)) {
			cout << "����: " << day << "." << month << "." << year << endl;
		}
		else {
			cout << "���� ���� � ����� ����" << endl;
		}
	}

};

int main() {


	setlocale(LC_ALL, "Ukrainian");

	//���������� ��'���� �����

	Calendar d[3];

	int i;

	cout << "\n���� ����" << endl;

	for (i = 0; i < 3; i++) {
		d[i].Print();
	}

	cout << "\n������ 1, ���� ������ �������� ���� �� 0 - ���� �" << endl;


	int num;
	int choice = 0;

	int innerChoice = 0;


	cin >> choice;


	if (choice == 1) {
		for (i = 0; i < 3; i++) {
			cout << "�������� ���� " << i + 1 << "? 1-���, 0-�" << endl;
			cin >> innerChoice;
			if (innerChoice == 1) {
				cout << "������ ����� �� ��� �������� ����:" << endl;
				cin >> num;
				if (num > 0) {
					d[i] += num;
				}
				else if ((d[i].day > 31) || (d[i].month > 12) || (d[i].year > 2023)) {
					cout << "���� �������� �� �������� ���������" << endl;
				}
			}
			if (innerChoice == 0) {
				cout << " " << endl;
			}
		}
	}
	if (choice == 0) {
		cout << "\n������� �� ���������� �����: " << endl;
	}

	cout << "������ 1, ���� ������ �������� ���� �� 0 - ���� �" << endl;
	cin >> choice;

	if (choice == 1) {
		for (i = 0; i < 3; i++) {
			cout << "�������� ���� ��� " << i + 1 << " ? 1-���, 0-�" << endl;
			cin >> innerChoice;
			if (innerChoice == 1) {
				cout << "������ ����� �� ��� �������� ����: " << endl;
				cin >> num;
				if (num > 0) {
					d[i] -= num;
				}
				else if ((d[i].day < 0) || (d[i].month < 0) || (d[i].year < 0)){
					cout << "�� �������� ������ ���� ����� �� ����" << endl;
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

	cout << "���� ����" << endl;
	for (i = 0; i < 3; i++) {
		d[i].Print();
	}

	for (i = 0; i < 3; i++) {
		cout << "\n������ �����, ������ � ��� "<< i + 1 << endl;
		d[i].FindDay();
	}

	cout << "\n������������ �������������� ������" << endl;
	for (i = 0; i < 1; i++) {
		d[i].FindDay(12, 3, 2004);
	}
	
	//��������� ���

	bool compare1 = d[0] > d[1];
	bool compare2 = d[1] > d[2];
	bool compare3 = d[2] > d[1];
	bool compare4 = d[0] < d[1];


	cout << " " << endl;
	cout << "���� 1 ����� �� ���� 2 (1-���, 0-�): " << compare1 << endl;
	cout << "���� 2 ����� �� ���� 3 (1-���, 0-�): " << compare2 << endl;
	cout << "���� 3 ����� �� ���� 2 (1-���, 0-�): " << compare3 << endl;
	cout << "���� 2 ����� �� ���� 1 (1-���, 0-�):  " << compare4 << endl;

	bool rivno1 = d[0] == d[1];
	bool rivno2 = d[1] == d[2];
	bool rivno3 = d[2] == d[1];
	bool rivno4 = d[0] == d[1];
	
	cout << " " << endl;
	cout << "���� 1 �������� � ����� 2 (1-���, 0-�): " << rivno1 << endl;
	cout << "���� 2 �������� � ����� 3 (1-���, 0-�): " << rivno1 << endl;
	cout << "���� 3 �������� � ����� 2 (1-���, 0-�): " << rivno1 << endl;
	cout << "���� 2 �������� � ����� 1 (1-���, 0-�): " << rivno1 << endl;

	return 0;
}