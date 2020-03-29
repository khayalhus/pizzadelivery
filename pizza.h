#include <string>
using namespace std;
class Pizza {
	string name;
	string size;
	string ingredients[6];
	string crust_type;
public:
	Pizza() {
		this->size = "medium";
		this->crust_type = "normal";
		this->ingredients[0] = "mozarella";
	}
	Pizza(string size, string crust_type, int pizza_type) {
		this->size = size;
		this->crust_type = crust_type;
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
};