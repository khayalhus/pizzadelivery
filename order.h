#include "pizza.h"

using namespace std;

class Order {
    string customer;
    Pizza * pizzas;
    string * drink;
    int amountOfDrink;
    Order * next;
    public:
    Order(string customer, Pizza * pizzas) {
        this->customer = customer;
        this->pizzas = pizzas;
        this->next = NULL;
    }
    Order(string customer, Pizza * pizzas, string * drink) {
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
        
        for (int i = 0; i < amountOfDrink; i++) {
            cout << "1 " << this->drink[i] << ", ";
        }
        cout << endl << "------------" << endl;
    }
    void addDrinkAmount(int amount) {
		this->amountOfDrink = amount;
	}
	void setNext(Order * nextorder) {
		this->next = nextorder;
	}
	Order * getNext() {
		return this->next;
	}
};
