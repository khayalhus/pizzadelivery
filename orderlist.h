#include <iostream>
#include "order.h"

using namespace std;

class OrderList {
    int n;
    Order * head;
    public:
    OrderList(){
        n = 0;
        head = NULL;
    }
    void takeOrder() {
        cout << "Pizza Menu" << endl;
        cout << "1. Chicken Pizza : mozarella, chicken, mushroom, corn, onion, tomato" << endl;
        cout << "2. Broccoli Pizza : mozarella, broccoli, pepperoni, olive, corn, onion" << endl;
        cout << "3. Sausage Pizza : mozarella, sausage, tomato, olive, mushroom, corn" << endl;
        cout << "0. Back to main menu" << endl;

        string size;
        string crust_type;
        int pizza_type;
        int amount;
        string customer;
        int drinkNum;
        int * drinkNums;
        int numOfDrinks = 0;
        string * drinks;
        cin >> pizza_type;
        if (pizza_type == 0) {
            return;
        }
        cout << "Select size: small (15 TL), medium (20 TL), big (25 TL)" << endl;
        cin >> size;
        cout << "Select crust type: thin, normal, thick" << endl;
        cin >> crust_type;
        cout << "Enter the amount:";
        cin >> amount;
        Pizza * headpizza = new Pizza(size, crust_type, pizza_type);
        Pizza * tail = headpizza;
        for (int i = 1; i < amount; i++) {
            Pizza * newpizza = new Pizza(*headpizza);
            tail->setNext(newpizza);
            tail = newpizza;
        }
        
        cout << "Please choose a drink:" << endl;
        cout << "0. no drink" << endl;
        cout << "1. cola 4 TL" << endl;
        cout << "2. soda 2 TL" << endl;
        cout << "3. ice tea 3 TL" << endl;
        cout << "4. fruit juice 3.5 TL" << endl;
        cout << "Press -1 for save your order" << endl;
        cin >> drinkNum;
        drinkNums = new int[50];
        if (drinkNum != 0) {
            while (drinkNum != -1) {
                drinkNums[numOfDrinks] = drinkNum;
                numOfDrinks += 1;
                cin >> drinkNum;
            }
            drinks = new string [numOfDrinks];
            for (int i = 0; i < numOfDrinks; i++) {
                if (drinkNums[i] == 1) {
                    drinks[i] = "cola";
                } else if (drinkNums[i] == 2) {
                    drinks[i] = "soda";
                } else if (drinkNums[i] == 3) {
                    drinks[i] = "ice tea";
                } else if (drinkNums[i] == 4) {
                    drinks[i] = "fruit juice";
                }
            }
            cout << "Please enter your name:" << endl;
            cin >> customer;
            Order * neworder = new Order(customer, headpizza, drinks);
            neworder->addDrinkAmount(numOfDrinks);
            AddToList(neworder);
            cout << "Your order is saved, it will be delivered when it is ready..." << endl;
            neworder->printOrder();
        } else {
            cout << "Please enter your name:" << endl;
            cin >> customer;
            Order * neworder = new Order(customer, headpizza);
            neworder->addDrinkAmount(0);
            AddToList(neworder);
            cout << "Your order is saved, it will be delivered when it is ready..." << endl;
            neworder->printOrder();
			}
    }
    void listOrders() {
        Order * traverse = head;
        for (int i = 0; i < n; i++){
            traverse->printOrder();
            traverse = traverse->getNext();
        }
    }
    void AddToList(Order * neworder) {
        ++n;
        if (this->head == NULL) {
            this->head = neworder;
            return;
        }
        Order * traverse = head;
        while (traverse->getNext() != NULL) {
            traverse = traverse->getNext();
        }
        traverse->setNext(neworder);
    }
};