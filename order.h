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
    void printOrder(){
        cout << "------------" << endl;
        cout << "Name : " << this->customer << endl << endl;
        Pizza * traverse = pizzas;
        while (traverse != NULL) {
            traverse->print();
            traverse = traverse->getNext();
        }
        cout << this->drink[0] << " cola, ";
        cout << this->drink[1] << " soda, ";
        cout << this->drink[2] << " ice tea, ";
        cout << this->drink[3] << " fruit juice";
        cout << endl << "------------" << endl;
    }
	void setNext(Order * nextorder) {
		this->next = nextorder;
	}
	Order * getNext() {
		return this->next;
	}
};
