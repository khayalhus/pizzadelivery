#include <string>

using namespace std;

class Pizza {
	string name;
	string size;
	string * ingredients;
	string crust_type;
	Pizza * next;
public:
	Pizza() {
		this->size = "medium";
		this->crust_type = "normal";
		this->ingredients = new string [6];
		this->ingredients[0] = "mozarella";
		this->next = NULL;
	}
	Pizza(string size, string crust_type, int pizza_type) {
		this->size = size;
		this->crust_type = crust_type;
		this->ingredients = new string [6];
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
		this->ingredients = new string [6];
		cout << "Please enter the number of the ingredient you want to remove from your pizza." << endl;
		for(int i = 0; i < 6; i++) {
			this->ingredients[i] = object_in.ingredients[i];
			cout << i+1 << ". " << this->ingredients[i] << endl;
		}
		cout << "Press 0 to save it." << endl;
		int num;
		cin >> num;
		while(num != 0) {
			this->remove(num);
			cin >> num;
		}
		this->next = NULL;
	}
	~Pizza() {
		delete [] ingredients;
	}
	void remove(int num) {
		this->ingredients[num-1] = "";
	}
	void print() {
		cout << this->name << "(";
		for (int i = 0; i < 6; i++) {
			if (ingredients[i] != "") {
				cout << this->ingredients[i] << ", ";
			}
		}
		cout << ")" << endl;
		cout << "size: " << this->size << ", crust: " << this->crust_type << endl << endl;
	}
	void setNext(Pizza * nextpizza) {
		this->next = nextpizza;
	}
	Pizza * getNext() {
		return this->next;
	}
	string getSize () {
		return this->size;
	}
};
