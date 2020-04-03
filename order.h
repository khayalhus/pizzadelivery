#include "pizza.h"

using namespace std;

class Order {
    string customer;
    Pizza * pizzas;
    int * drink;
    Order * next;
    public:
    Order(string customer, Pizza * pizzas) {
        this->customer = customer;
        this->pizzas = pizzas;
        this->next = NULL;
        this->drink = new int[4];
        for (int i = 0; i < 4; i++) {
            drink[i] = 0;
        }
    }
    Order(string customer, Pizza * pizzas, int * drink) {
        this->customer = customer;
        this->pizzas = pizzas;
        this->drink = drink;
        this->next = NULL;
    }
    ~Order() {
        delete [] pizzas;
        delete [] drink;
    }
    void printOrder(){
        cout << "------------" << endl;
        cout << "Name : " << this->customer << endl << endl;
        Pizza * traverse = pizzas;
        while (traverse != NULL) {
            traverse->print();
            traverse = traverse->getNext();
        }
        if (this->drink[0] != 0) {
            cout << this->drink[0] << " cola, ";
        }
        if (this->drink[1] != 0) {
            cout << this->drink[1] << " soda, ";
        }
        if (this->drink[2] != 0) {
            cout << this->drink[2] << " ice tea, ";
        }
        if (this->drink[3] != 0) {
            cout << this->drink[3] << " fruit juice, ";
        }
        cout << endl << "------------" << endl;
    }
    double getPrice() {
        double totalPrice = 0.0;
        Pizza * traverse = pizzas;
        while (traverse != NULL) {
            if (traverse->getSize().compare("small") == 0) {
                totalPrice += 15;
            } else if (traverse->getSize().compare("medium") == 0) {
                totalPrice += 20;
            } else if (traverse->getSize().compare("big") == 0) {
                totalPrice += 25;
            }
            traverse = traverse->getNext();
        }
        totalPrice += drink[0] * 4;
        totalPrice += drink[1] * 2;
        totalPrice += drink[2] * 3;
        totalPrice += drink[3] * 3.5;
        return totalPrice;
    }
	void setNext(Order * nextorder) {
		this->next = nextorder;
	}
	Order * getNext() {
		return this->next;
	}
    string getName() {
        return customer;
    }
};
