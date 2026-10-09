#include <iostream>
using namespace std;

class Date {
	int day;
	int month;
	int year;
public:
	Date() { day = 0; month = 0; year = 0; }
	Date(int d, int m, int y) { day = d; month = m; year = y; }

	void print() {
		cout << "Day: " << day << "\nMonth: " << month << "\nYear: " << year << endl << endl;
	}

	//ПЕРЕГРУЗКИ ОПЕРАЦІЙ
	
	//Date - Date = ... (в днях)
	int operator-(const Date& obj2) {
		int days1 = year * 12 * 30 + month * 30 + day;
		int days2 = obj2.getYear() * 12 * 30 + obj2.getMonth() * 30 + obj2.getDay();
		return days1 - days2;
	}
	//Date + Date = ... (в днях)
	int operator+(const Date& obj2) {
		int days1 = year * 12 * 30 + month * 30 + day;
		int days2 = obj2.getYear() * 12 * 30 + obj2.getMonth() * 30 + obj2.getDay();
		return days1 + days2;
	}
	//Date + кількість днів = ... (новий Date)
	Date operator+(int d) {
		if (d < 30) {
			return Date(day + d, month, year);
		}
		else {
			int m = d / 30;
			d = d % 30;
			if (m < 12) {
				return Date(day + d, month + m, year);
			}
			else {
				int y = m / 12;
				m = m % 12;
				return Date(day + d, month + m, year + y);
			}
		}
	}
	//Date - кількість днів = ... (новий Date)
	Date operator+(int d) {
		if (d < day) {
			return Date(day - d, month, year);
		}
		else {
			int m = d / 30;
			d = d % 30;
			if (m < month) {
				return Date(day - d, month - m, year);
			}
			else {
				int y = m / 12;
				m = m % 12;
				return Date(day - d, month - m, year - y);
			}
		}
	}

	//ПЕРЕГРУЗКИ СКОРОЧЕНИХ ФОРМ
	
	//Date += кількість днів = ... (змінити даний Date)
	Date operator+(int d) {
		if (d < 30) {
			day += d;
			return *this;
		}
		else {
			int m = d / 30;
			d = d % 30;
			if (m < 12) {
				day + d;
				month + m;
				return *this;
			}
			else {
				int y = m / 12;
				m = m % 12;
				day += d;
				month += m;
				year += y;
				return *this;
			}
		}
	}
	//Date -= кількість днів = ... (змінити даний Date)
	Date operator+(int d) {
		if (d < day) {
			day -= d;
			return *this;
		}
		else {
			int m = d / 30;
			d = d % 30;
			if (m < month) {
				day -= d;
				month -= m;
				return *this;
			}
			else {
				int y = m / 12;
				m = m % 12;
				day -= d;
				month -= m;
				year -= y;
				return *this;
			}
		}
	}

	//ПЕРЕГРУЗКИ УНАРНИХ ОПЕРАЦІЙ
	Date& operator++() // ++a
	{
		day += 1;
		return *this;
	}
	Date operator++(int) // a++
	{
		Date res = *this;
		day += 1;
		return res;
	}
	Date& operator--() // --a
	{
		day -= 1;
		return *this;
	}
	Date operator--(int) // a--
	{
		Date res = *this;
		day -= 1;
		return res;
	}

	//ПЕРЕГРУЗКИ ПОРІВНЯНЬ
	bool operator>(Date& obj2)
	{
		if (year > obj2.year) {
			return true;
		}
		else if (year == obj2.year) {
			if (month > obj2.month) {
				return true;
			}
			else if (month == obj2.month) {
				if (day > obj2.day) {
					return true;
				}
			}
		}
		return false;
	}
	bool operator<(Date& obj2)
	{
		if (year < obj2.year) {
			return true;
		}
		else if (year == obj2.year) {
			if (month < obj2.month) {
				return true;
			}
			else if (month == obj2.month) {
				if (day < obj2.day) {
					return true;
				}
			}
		}
		return false;
	}
	bool operator>=(Date& obj2)
	{
		if (year == obj2.year) {
			if (month > obj2.month) {
				return true;
			}
			else {
				if (month == obj2.month) {
					if (day >= obj2.day) {
						return true;
					}
				}
			}
		}
		else if (year > obj2.year) {
			return true;
		}
		return false;
	}
	bool operator<=(Date& obj2)
	{
		if (year == obj2.year) {
			if (month < obj2.month) {
				return true;
			}
			else {
				if (month == obj2.month) {
					if (day <= obj2.day) {
						return true;
					}
				}
			}
		}
		else if (year < obj2.year) {
			return true;
		}
		return false;
	}
	bool operator==(Date& obj2)
	{
		if (year == obj2.year && month == obj2.month && day == obj2.day) {
			return true;
		}
		return false;
	}
	bool operator!=(Date& obj2)
	{
		if (year != obj2.year || month != obj2.month || day != obj2.day) {
			return true;
		}
		return false;
	}

	//GETTERS
	int getDay()const { return day; }
	int getMonth()const { return month; }
	int getYear()const { return year; }
	//SETTERS
	void setDay(int d) { day = d; }
	void setMonth(int m) { month = m; }
	void setYear(int y) { year = y; }
};

int main()
{
	//Date d1(3, 3, 2026);
	//Date d2(2, 1, 2026);
	//Date d3(1, 1, 2026);
	//d1.print();
	//d2.print();
	//cout << "-- RES OF SUBTRACTION: " << d1 - d2 << endl << endl << endl; //ð³çíèööÿ â 61 äåíü (2 ì³ñÿö³ é 1 äåíü)

	//d2.print();
	//d3.print();
	//cout << "-- RES OF SUBTRACTION: " << d2 - d3 << endl << endl << endl; //ð³çíèöÿ â 1 äåíü

	//Date dRes = d3 + 3;
	//d3.print();
	//cout << "-- RES OF + 3:\n";
	//dRes.print(); //Day: 1 + 3 = 4
	//cout << "-- RES OF ANOTHER + 31:\n";
	//dRes = dRes + 31;
	//dRes.print(); //Month: 1 + 1 = 2; Day: 4 + 1 = 5
	//cout << "-- RES OF ANOTHER + 391:\n";
	//dRes = dRes + 391;
	//dRes.print(); //Year: 2026 + 1 = 2027; Month: 2 + 1 = 3; Day: 5 + 1 = 6;
	return 0;
}