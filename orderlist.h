#include <iostream>
#include "order.h"

using namespace std;

class OrderList {
    int n;
    Order * head;
    public:
    OrderList() {
        n = 0;
        head = NULL;
    }
    ~OrderList() {
        delete [] head;
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
        drinkNums = new int[4];
        for (int i = 0; i < 4; i++) {
            drinkNums[i] = 0;
        }
        do {
            cin >> drinkNum;
            if (drinkNum == 0) {
                cout << "Please enter your name:" << endl;
                cin.ignore();
                getline(cin, customer);
                Order * neworder = new Order(customer, headpizza);
                AddToList(neworder);
                cout << "Your order is saved, it will be delivered when it is ready..." << endl;
                neworder->printOrder();
                return;
            } else if (drinkNum == 1) {
                drinkNums[0] += 1;
            } else if (drinkNum == 2) {
                drinkNums[1] += 1;
            } else if (drinkNum == 3) {
                drinkNums[2] += 1;
            } else if (drinkNum == 4) {
                drinkNums[3] += 1;
            } 
        } while (drinkNum != -1);
            cout << "Please enter your name:" << endl;
            cin.ignore();
            getline(cin, customer);
            Order * neworder = new Order(customer, headpizza, drinkNums);
            AddToList(neworder);
            cout << "Your order is saved, it will be delivered when it is ready..." << endl;
            neworder->printOrder();
    }
    void listOrders() {
        if (n == 0) {
            cout << "empty" << endl;
            return;
        }
        Order * traverse = head;
        for (int i = 0; i < n; i++){
            cout << i+1 << endl;
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
    void deliverOrders () {
        if (head == NULL) {
            cout << "No Order" << endl;
            return;
        }
        this->listOrders();
        cout << "Please write the customer name in order to deliver his/her order: ";
        string name;
        Order * traverse = head;
        cin.ignore();
        getline(cin, name);
        while(traverse->getName().compare(name) != 0) {
            traverse = traverse->getNext();
            if (traverse == NULL) {
                cout << "Wrong name" << endl;
                return;
            }
        }
        cout << "Following order is delivering..." << endl;
        traverse->printOrder();
        cout << "Total price: " << traverse->getPrice() << endl;
        char promoConfirm;
        do {
            cout << "Do you have a promotion code? (y/n)" << endl;
            cin >> promoConfirm;
            if (promoConfirm == 'y') {
                cout << "Please enter your code: ";
                string promoInput;
                cin.ignore();
                getline(cin, promoInput);
                if (promoInput.compare("I am a student") == 0) {
                    cout << "Discounted price: " << traverse->getPrice() * 0.9 << endl;
                    this->removeOrder(name);
                    cout << "The order is delivered successfully" << endl;
                    return;
                }
                cout << "Promotion code is not accepted" << endl;
            }
        } while (promoConfirm != 'n');
        this->removeOrder(name);
        cout << "The order is delivered successfully" << endl;
        return;
    }
    void removeOrder(string name) {
        Order * traverse = head;
        Order * tail = head;
        while(traverse->getName().compare(name) != 0) {
            tail = traverse;
            traverse = traverse->getNext();
        }
        if (traverse == head) {
            head = traverse->getNext();
            //delete traverse;
        } else {
            tail->setNext(traverse->getNext());
            //delete traverse;
        }
    }
};