#include <iostream>
#include "order.h"

using namespace std;

class OrderList {
    int n; // amount of active orders
    Order * head; // first order in a linked list of Orders
    public:
    OrderList() {
        n = 0;
        head = NULL;
    }
    ~OrderList() {
        Order * traverse = head;
        Order * temp;
        while (traverse != NULL) {
            temp = traverse;
            traverse = traverse->getNext();
            delete traverse; // deletes all the Orders
        }
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
        int drinkNum; // ID of the desired drink
        int * drinkNums; // dynamic array pointer which holds the amount of ordered drinks
        cin >> pizza_type;
        while (pizza_type != 1 && pizza_type != 2 && pizza_type != 3 && pizza_type != 0) {
            cout << "Not a valid pizza type." << endl; // check input for validity
            cin >> pizza_type;
        }
        if (pizza_type == 0) {
            return; // return to main menu if input is 0
        }
        cout << "Select size: small (15 TL), medium (20 TL), big (25 TL)" << endl;
        cin >> size;
        while (size.compare("small") != 0 && size.compare("medium") != 0 && size.compare("big") != 0) {
            cout << "Not a valid size." << endl; // check input for validity
            cin >> size;
        }
        cout << "Select crust type: thin, normal, thick" << endl;
        cin >> crust_type;
        while (crust_type.compare("thin") != 0 && crust_type.compare("normal") != 0 && crust_type.compare("thick") != 0) {
            cout << "Not a valid crust type" << endl; // check input for validity
            cin >> crust_type;
        }
        cout << "Enter the amount:";
        cin >> amount;
        while (amount < 1) {
            cout << "Amount must be equal to or bigger than 1" << endl;
            if (cin.fail()) { // check if user typed a string in place of int
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout << "Enter the amount:";
            cin >> amount;
        }
        Pizza * headpizza = new Pizza(size, crust_type, pizza_type); // allocate memory for first pizza
        Pizza * tail = headpizza;
        for (int i = 1; i < amount; i++) {
            Pizza * newpizza = new Pizza(*headpizza); // copy details for the newpizza from the first pizza (and aks if customer wants to remove ingredients)
            tail->setNext(newpizza); // link pizzas
            tail = newpizza; // repeat for given amount of times
        }
        
        cout << "Please choose a drink:" << endl;
        cout << "0. no drink" << endl;
        cout << "1. cola 4 TL" << endl;
        cout << "2. soda 2 TL" << endl;
        cout << "3. ice tea 3 TL" << endl;
        cout << "4. fruit juice 3.5 TL" << endl;
        cout << "Press -1 for save your order" << endl;
        drinkNums = new int[4]; // reserve space for 4 integers, because there are 4 drink types (each holds the amount of that drink type)
        for (int i = 0; i < 4; i++) {
            drinkNums[i] = 0; // initialize them to 0
        }
        do {
            cin >> drinkNum;
            if (drinkNum == 0) {
                // discard given drink inputs
                cout << "Please enter your name:" << endl;
                cin.ignore(10000, '\n');
                getline(cin, customer); // get customer name
                Order * neworder = new Order(customer, headpizza); // place the order
                AddToList(neworder); // add the order to the list orders
                cout << "Your order is saved, it will be delivered when it is ready..." << endl;
                neworder->printOrder(); // print the order to the screen
                return;
            } else if (drinkNum == 1) {
                drinkNums[0] += 1; // increment cola
            } else if (drinkNum == 2) {
                drinkNums[1] += 1; // increment soda
            } else if (drinkNum == 3) {
                drinkNums[2] += 1; // increment ice tea
            } else if (drinkNum == 4) {
                drinkNums[3] += 1; // increment fruit juice
            } else {
                cout << "Invalid input" << endl;
            }
        } while (drinkNum != -1);
            // save drinks
            cout << "Please enter your name:" << endl;
            cin.ignore(10000, '\n');
            getline(cin, customer); // get customer name
            Order * neworder = new Order(customer, headpizza, drinkNums); // place the order
            AddToList(neworder); // add the order to the list of orders
            cout << "Your order is saved, it will be delivered when it is ready..." << endl;
            neworder->printOrder(); // print the order to the screen
    }
    void listOrders() {
        // lists orders
        if (n == 0) {
            cout << "empty" << endl;
            return;
        }
        Order * traverse = head;
        for (int i = 0; i < n; i++){
            cout << i+1 << endl;
            traverse->printOrder(); // from top to bottom
            traverse = traverse->getNext();
        }
    }
    void AddToList(Order * neworder) {
        ++n; // increment amount of orders
        if (this->head == NULL) {
            this->head = neworder; // add as first order if list is empty
            return;
        }
        Order * traverse = head;
        while (traverse->getNext() != NULL) {
            traverse = traverse->getNext(); 
        }
        traverse->setNext(neworder); // add in between or as last order
    }
    void deliverOrders () {
        if (head == NULL) {
            cout << "No Order" << endl; // return of there are no orders
            return;
        }
        this->listOrders();
        cout << "Please write the customer name in order to deliver his/her order: ";
        string name;
        Order * traverse = head;
        cin.ignore(10000, '\n');
        getline(cin, name);
        while(traverse->getName().compare(name) != 0) {
            traverse = traverse->getNext(); // search for order
            if (traverse == NULL) {
                cout << "Wrong name" << endl; // return if there is no order under that name
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
                cin.ignore(10000, '\n');
                getline(cin, promoInput); // ask for a discount code
                if (promoInput.compare("I am a student") == 0) { // if correct,
                    cout << "Discounted price: " << traverse->getPrice() * 0.9 << endl; // discout price by %10
                    this->removeOrder(name);
                    cout << "The order is delivered successfully" << endl;
                    return;
                }
                cout << "Promotion code is not accepted" << endl; // if not,
            }
        } while (promoConfirm != 'n'); // ask again
        this->removeOrder(name); // remove the order from the list
        cout << "The order is delivered successfully" << endl;
        return;
    }
    void removeOrder(string name) {
        Order * traverse = head;
        Order * tail = head;
        while(traverse->getName().compare(name) != 0) {
            tail = traverse; // order before the "soon to be deleted" order
            traverse = traverse->getNext(); // find order
        }
        if (traverse == head) { // when deleting head order
            head = traverse->getNext(); // assign next order as head
            --n; // reduce amount of orders by 1
            delete traverse; // delete order
        } else {
            tail->setNext(traverse->getNext()); // assign next order as previous order's next order
            --n; // reduce amount of orders by 1
            delete traverse; // delete order
        }
    }
    void close () {
        Order * traverse = head;
        Order * temp;
        while(traverse != NULL) {
            temp = traverse;
            traverse = traverse->getNext();
            delete temp; // delete all remaining orders from top to bottom
        }
    }
};