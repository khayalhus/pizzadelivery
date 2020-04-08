#include <iostream>
#include "orderlist.h" // contains OrderList class file, which includes Order class file, which includes Pizza class file

using namespace std;

int main() {
	int choice = 0; // stores the chosen operation by the user
	OrderList * list = new OrderList(); // creates the Linked List which will store all orders
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
			cin.ignore(10000, '\n'); // Prevents string input from making the program going into infinite loop
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
