#include <string>

using namespace std;

class Pizza {
	string name; // stores pizza name
	string size; // stores size of pizza
	string * ingredients; // dynamic array of ingredients in pizza
	string crust_type; // crust type of pizza
	Pizza * next; // next pizza in the order
public:
	Pizza() { // default constructor
		this->size = "medium";
		this->crust_type = "normal";
		this->ingredients = new string [6]; // dynamic array of strings was used for ingredients, because all pizza types contain 6 ingredients
		this->ingredients[0] = "mozarella";
		this->next = NULL;
	}
	Pizza(string size, string crust_type, int pizza_type) { // constructor for first pizza
		this->size = size;
		this->crust_type = crust_type;
		this->ingredients = new string [6];	// dynamic array of strings was used for ingredients, because all pizza types contain 6 ingredients
		this->next = NULL;
		switch (pizza_type)
		{
		case 1:
			this->name = "Chicken Pizza";
			this->ingredients[0] = "mozarella";
			this->ingredients[1] = "chicken";
			this->ingredients[2] = "mushroom";
			this->ingredients[3] = "corn";
			this->ingredients[4] = "onion";
			this->ingredients[5] = "tomato";
			break;
		case 2:
			this->name = "Broccoli Pizza";
			this->ingredients[0] = "mozarella";
			this->ingredients[1] = "broccoli";
			this->ingredients[2] = "pepperoni";
			this->ingredients[3] = "olive";
			this->ingredients[4] = "corn";
			this->ingredients[5] = "onion";
			break;
		case 3:
			this->name = "Sausage Pizza";
			this->ingredients[0] = "mozarella";
			this->ingredients[1] = "sausage";
			this->ingredients[2] = "tomato";
			this->ingredients[3] = "olive";
			this->ingredients[4] = "mushroom";
			this->ingredients[5] = "corn";
			break;
		default:
			break;
		}
	}
	Pizza(const Pizza &object_in) {
		this->name = object_in.name;
		this->size = object_in.size;
		this->crust_type = object_in.crust_type;
		this->ingredients = new string [6];	// dynamic array of strings was used for ingredients, because all pizza types contain 6 ingredients
		cout << "Please enter the number of the ingredient you want to remove from your pizza." << endl;
		for(int i = 0; i < 6; i++) {
			this->ingredients[i] = object_in.ingredients[i]; // copy the ingredients' name from the first pizza
			cout << i+1 << ". " << this->ingredients[i] << endl;
		}
		cout << "Press 0 to save it." << endl;
		int num; // the number of ingredient desired to be removed
		while (true) {
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n'); // prevents infinite loop when string input is entered
				cout << "Invalid input" << endl;
				continue;
			}
			if ( num == 0 ) {
				break; // finishes operation
			}
			if (num > 0 && num < 7 ) {
				this->remove(num); // removes the desired ingredient
			} else {
				cout << "Invalid input" << endl;
			}
		}
		this->next = NULL;
	}
	~Pizza() {
		delete [] ingredients; // free dynamically allocated memory
	}
	void remove(int num) {
		this->ingredients[num-1] = ""; // "removes" the ingredient by equalizing it to an empty string
	}
	void print() {
		cout << this->name << "(";
		for (int i = 0; i < 6; i++) {
			if (ingredients[i] != "") { // if ingredient is not removed, print it
				cout << this->ingredients[i] << ", ";
			}
		}
		cout << ")" << endl;
		cout << "size: " << this->size << ", crust: " << this->crust_type << endl << endl;
	}
	void setNext(Pizza * nextpizza) {
		this->next = nextpizza; // links pizzas
	}
	Pizza * getNext() {
		return this->next;
	}
	string getSize () {
		return this->size;
	}
};
