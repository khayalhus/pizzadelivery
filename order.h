#include "pizza.h"

using namespace std;

class Order {
    string customer;
    Pizza * pizzas;
    string * drink;
    int amountOfDrink;
    public:
    Order(string customer, Pizza * pizzas) {
        this->customer = customer;
        this->pizzas = pizzas;
    }
    Order(string customer, Pizza * pizzas, string * drink) {
        this->customer = customer;
        this->pizzas = pizzas;
        this->drink = drink;
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
};
