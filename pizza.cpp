#include <iostream>
#include "orderlist.h"

using namespace std;

int main() {
	int choice = 0;
	OrderList * list = new OrderList();
	while (choice != 4) {
		cout << "Welcome to Unicorn Pizza!" << endl;
		cout << "1. Add an order" << endl;
		cout << "2. List orders" << endl;
		cout << "3. Deliver order" << endl;
		cout << "4. Exit" << endl;
		cout << "Choose what to do: " << endl;
		cin >> choice;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (choice)
		{
		case 1:
		{
			list->takeOrder();
			break;
		}
		case 2:
			list->listOrders();
			break;
		case 3:
			list->deliverOrders();
			break;
		case 4:
			list->close();
			cout << "Goodbye..." << endl;
			break;
		default:
			cout << "Invalid choice." << endl;
			break;
		}
	}
}
