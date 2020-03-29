#include <iostream>
#include "pizza.h"

using namespace std;

int main() {
	int choice = 0;
	while (choice != 4) {
		printf("Welcome to Unicorn Pizza!\n");
		printf("1. Add an order\n");
		printf("2. List orders\n");
		printf("3. Deliver order\n");
		printf("4. Exit\n");
		printf("Choose what to do: ");
		cin >> choice;
		if (choice == 1) {
			printf("Pizza Menu\n");
			printf("1. Chicken Pizza : mozarella, chicken, mushroom, corn, onion, tomato\n");
			printf("2. Broccoli Pizza : mozarella, broccoli, pepperoni, olive, corn, onion\n");
			printf("3. Sausage Pizza : mozarella, sausage, tomato, olive, mushroom, corn\n");
			printf("0. Back to main menu\n");
			//take input			string size;
			string crust_type;
			int pizza_type;			int amount;			cin >> pizza_type;			if (pizza_type == 0) {				break;			}			printf("Select size: small (15 TL), medium (20 TL), big (25 TL)\n");			cin >> size;			printf("Select crust type: thin, normal, thick\n");			cin >> crust_type;			printf("Enter the amount:");			cin >> amount;			//call constructor Pizza(); iteratively
			//printf("Please enter the number of ingredient you want to remove from your pizza.");
		}
		else if (choice == 2) {

		}
		else if (choice == 3) {

		}
		else if (choice == 4) {
			printf("Goodbye...");
		}
		/*
		switch (choice)
		{
		case 1:
		{
			printf("Pizza Menu\n");
			printf("1. Chicken Pizza : mozarella, chicken, mushroom, corn, onion, tomato\n");
			printf("2. Broccoli Pizza : mozarella, broccoli, pepperoni, olive, corn, onion\n");
			printf("3. Sausage Pizza : mozarella, sausage, tomato, olive, mushroom, corn\n");
			printf("0. Back to main menu\n");
			//take input			string size;
			string crust_type;
			int pizza_type;			cin >> pizza_type;			if (pizza_type == 0) {				break;			}			printf("Select size: small (15 TL), medium (20 TL), big (25 TL)\n");			cin >> size;			printf("Select crust type: thin, normal, thick");			cin >> crust_type;			printf("Enter the amount:");			//call constructor Pizza(); iteratively
			break;
			//printf("Please enter the number of ingredient you want to remove from your pizza.");
		}
		case 2:
			break;
		case 3:
			break;
		case 4:
			printf("Goodbye...");
			break;
		default:
			break;
		}
		*/
	}
}