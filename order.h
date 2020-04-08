#include "pizza.h" // contains Pizza class file

using namespace std;

class Order {
    string customer; // stores customer name
    Pizza * pizzas; // stores Linked List for pizzas
    int * drink; // dynamic array of drinks
    Order * next; // next order in list of orders
    public:
    Order(string customer, Pizza * pizzas) {
        this->customer = customer;
        this->pizzas = pizzas;
        this->next = NULL;
        this->drink = new int[4]; // dynamic array of drinks, there are 4 integers, for the 4 types of drinks
        for (int i = 0; i < 4; i++) {
            drink[i] = 0; // initialize the amount of drink for each drink type to 0
        }
    }
    Order(string customer, Pizza * pizzas, int * drink) {
        this->customer = customer;
        this->pizzas = pizzas;
        this->drink = drink;
        this->next = NULL;
    }
    ~Order() {
        Pizza * traverse = pizzas;
        Pizza * temp;
        while (traverse != NULL) {
            temp = traverse;
            traverse = traverse->getNext();
            delete temp; // deletes all Pizzas
        }
        delete [] drink; // frees memory allocted for drinks
        // relinking the Orders in the Linked List is done by the function that calls this constructor
    }
    void printOrder(){
        cout << "------------" << endl;
        cout << "Name : " << this->customer << endl << endl;
        Pizza * traverse = pizzas;
        while (traverse != NULL) {
            traverse->print(); // prints pizzas in linked list
            traverse = traverse->getNext();
        }
        if (this->drink[0] != 0) { // if there is a request for that drink type
            cout << this->drink[0] << " cola, "; // print it
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
                totalPrice += 15;   // price of small pizza
            } else if (traverse->getSize().compare("medium") == 0) {
                totalPrice += 20;   // price of medium pizza
            } else if (traverse->getSize().compare("big") == 0) {
                totalPrice += 25;   // price of big pizza
            }
            traverse = traverse->getNext();
        }
        totalPrice += drink[0] * 4; // price of cola
        totalPrice += drink[1] * 2; // price of soda
        totalPrice += drink[2] * 3; // price of ice tea
        totalPrice += drink[3] * 3.5; // price of fruit juice
        return totalPrice;
    }
	void setNext(Order * nextorder) {
		this->next = nextorder; // links Orders
	}
	Order * getNext() {
		return this->next;
	}
    string getName() {
        return customer;
    }
};
