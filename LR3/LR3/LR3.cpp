// LR3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

using namespace std;

#pragma region BusStation
class BusStation
{
public:
	int route;
	string city;
	float time;
public:
	BusStation() { route = 1; city = "Moscow"; time = 9.05; };
	BusStation(int rt, string ct, float t) { route = rt; city = ct; time = t; };
	BusStation(BusStation& B){ route = B.route; city = B.city; time = B.time;}
	~BusStation() {};

	void setRoute(int r) { route = r; };
	void setCity(string c) { city = c; };
	void setTime(float t) { time = t; };

	void getInfo();
	int getRoute() { return route; };
	string getCity() { return city; };
	float getTime() { return time; };
	string getBus(string c) { if (c == city) getInfo(); };

	BusStation& operator = (BusStation obj)
	{
		route = obj.route;
		city = obj.city;
		time = obj.time;
		return *this;
	};
	friend ostream& operator << (ostream& out, const BusStation& obj)
	{
		out << "Маршрут " << obj.route << endl <<
			"Город назначения: " << obj.city << endl <<
			"Время отправления " << obj.time << endl << endl;
		return out;
	}
	friend istream& operator >> (istream& in, BusStation& obj)
	{
		in >> obj.route;
		in >> obj.city;
		in >> obj.time;
		return in;
	}

	bool operator == (BusStation& BS) { return route == BS.route; };
};

void BusStation::getInfo()
{
	cout << "Маршрут " + to_string(route) + ", город назначения: " + city + ", время отправления " + to_string(time) << endl;
};

bool func(int rt, Node<BusStation>* r)
{
	return r->d.route == rt;
}

bool func(string ct, Node<BusStation>* c)
{
	return c->d.city == ct;
}

#pragma endregion

ListNode<BusStation> list;
void createBusStation()
{
	BusStation BS;
	string city;
	int route;
	float time;

	cout << "Set city: ";
	cin >> city;
	BS.setCity(city);

	cout << "Set route: ";
	cin >> route;
	BS.setRoute(route);

	cout << "Set time: ";
	cin >> time;
	BS.setTime(time);
	cout << endl;

	list.AddHead(BS);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	ListNode<int>* N1 = new ListNode<int>();
	N1->AddHead(10); N1->AddHead(7); N1->AddHead(4); N1->AddHead(6);
	N1->AddTail(5); N1->AddTail(-1); N1->AddTail(3); N1->AddTail(-5);

	cout << "Вывод списка с начала: "; 
	N1->ListHead();
	cout << endl;

	cout << "Вывод списка с конца: "; 
	N1->ListTail();
	cout << endl;

	cout << "Вставка узла на 5 место: ";
	N1->AddNode(50, 5);
	N1->ListHead();
	cout << endl;

	cout << "Удаление головы списка: ";
	N1->DeleteHead();
	N1->ListHead();
	cout << endl;

	cout << "Удаление хвоста списка: ";
	N1->DeleteTail();
	N1->ListHead();
	cout << endl;

	cout << "Удаление 3-го элемента списка: ";
	N1->DeleteNode(3);
	N1->ListHead();
	cout << endl;

	cout << "Значение 4-го элемента: " << N1->operator[](4) << endl;
	cout << "Изменение значения 2-го элемента: ";
	N1->setValue(1000, 2);
	N1->ListHead();
	cout << endl;
	
	N1->Clear();
	if (N1->isEmpty())
		cout << "Список пуст" << endl;
	else cout << "Список не пуст" << endl;
	cout << endl;
    

	
	ListNode<float>* N2 = new ListNode<float>();
	N2->AddHead(1.25); N2->AddHead(0.3); N2->AddHead(4.77); N2->AddHead(0.5);
	N2->AddTail(9.5); N2->AddTail(-1.45); N2->AddTail(3.5); N2->AddTail(-5.65);

	cout << "Вывод списка с начала: ";
	N2->ListHead();
	cout << endl;

	cout << "Вывод списка с конца: ";
	N2->ListTail();
	cout << endl;

	cout << "Вставка узла на 4 место: ";
	N2->AddNode(1.111, 4);
	N2->ListHead();
	cout << endl;

	cout << "Удаление головы списка: ";
	N2->DeleteHead();
	N2->ListHead();
	cout << endl;

	cout << "Удаление хвоста списка: ";
	N2->DeleteTail();
	N2->ListHead();
	cout << endl;

	cout << "Удаление 5-го элемента списка: ";
	N2->DeleteNode(5);
	N2->ListHead();
	cout << endl;

	cout << "Значение 3-го элемента: " << N2->operator[](3) << endl;
	cout << "Изменение значения 4-го элемента: ";
	N2->setValue(9.999, 4);
	N2->ListHead();
	cout << endl;

	N2->Clear();
	if (N2->isEmpty())
		cout << "Список пуст" << endl;
	else cout << "Список не пуст" << endl;
	cout << endl;
    

	
	ListNode<string>* N3 = new ListNode<string>();
	N3->AddHead("Tuesday"); N3->AddHead("Monday"); N3->AddHead("Sunday");
	N3->AddTail("Wednesday"); N3->AddTail("Thursday"); N3->AddTail("Saturday");
	
	cout << "Вывод списка с начала: ";
	N3->ListHead();
	cout << endl;

	cout << "Вывод списка с конца: ";
	N3->ListTail();
	cout << endl;

	cout << "Вставка узла на 6 место: ";
	N3->AddNode("Friday", 6);
	N3->ListHead();
	cout << endl;

	cout << "Удаление головы списка: ";
	N3->DeleteHead();
	N3->ListHead();
	cout << endl;

	cout << "Удаление хвоста списка: ";
	N3->DeleteTail();
	N3->ListHead();
	cout << endl;

	cout << "Удаление 4-го элемента списка: ";
	N3->DeleteNode(4);
	N3->ListHead();
	cout << endl;

	cout << "Значение 2-го элемента: " << N3->operator[](2) << endl;
	cout << "Изменение значения 3-го элемента: ";
	N3->setValue("ChangedValue", 3);
	N3->ListHead();
	cout << endl;
	
	N3->Clear();
	if (N3->isEmpty())
		cout << "Список пуст" << endl;
	else cout << "Список не пуст" << endl;
	cout << endl;
	


	//ВАРИАНТ 10
	cout << endl << "ВАРИАНТ 10" << endl;
	int key = 1;
	while (key == 1)
	{
		cout << "Input 1 to create bus stations"
			<< endl << "Input 2 to view bus stations information"
			<< endl << "Input 3 to find by route"
			<< endl << "Input 4 to view all routes to a city" 
			<< endl << "Input 0 to end the program" << endl;
		int k;
		cin >> k;
		switch (k)
		{
		case(0):
			key = 0;
			break;

		case(1):
			int y;
			cout << "How many bus stations do you want to add? ";
			cin >> y;
			while (y != 0)
			{
				createBusStation();
				y--;
			}
			break;

		case(2):
			cout << "Bus stations information: " << endl;
			list.ListTail();
			cout << endl;
			break;

		case(3):
			int x;
			cout << "Input route you want to find: ";
			cin >> x;
			cout << list.operator[](x) << endl;
			//list.BusRoute(func, x);
			//cout << endl;
			break;

		case(4):
			string z;
			cout << "Input city you want to find routes to: ";
			cin >> z;
			list.BusRoute(func, z);
			cout << endl;
			break;
		}
	}

}
