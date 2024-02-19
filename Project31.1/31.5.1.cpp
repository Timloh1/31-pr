#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Toy
{

private:

	string name = "";

public:

	Toy(string _name) : name(_name) {};

	string getName() { 
		return name;
	}

};

class Dog
{

private:

	string name = "";
	int age = 0;
	shared_ptr<Toy> lovelyToy = nullptr;

public:

	shared_ptr<Toy> getToyPtr() {
		return lovelyToy;
	}

	Dog(string _name, int _age, shared_ptr<Toy> _lovelyToy) : name(_name), lovelyToy(_lovelyToy)
	{
		if (_age < 30 && _age >= 0) {
			age = _age;
		}
		else {
			age = 0;
		}
	}

	void getToy(shared_ptr<Toy> _lovelyToy, vector <shared_ptr<Dog>> dogs)
	{
		
		bool value = false;

		for (int i = 0; i < dogs.size(); ++i)
		{
			if (dogs[i]->getToyPtr() == _lovelyToy) {
				value = true;
				break;
			}
		}

		if (lovelyToy == _lovelyToy) {
			cout << "I already have this toy" << endl;
		}
		else if (value) {
			cout << "Another dog is playing with this toy" << endl;
		}
		else if (lovelyToy == nullptr) {
			lovelyToy = _lovelyToy;
		}
		else {
			cout << "The dog has another toy" << endl;
		}
	
	}

	void dropToy() {

		if (lovelyToy == nullptr) {
			cout << "Nothing to drop" << endl;
		}
		else {
			lovelyToy.reset();
			lovelyToy = nullptr;
		}

	}

};

int main() {
	
	vector <shared_ptr<Dog>> dogs;
	vector <shared_ptr<Toy>> toys;

	for (int i = 0; i < 5; ++i)
	{
		string name = "dog" + to_string(i + 1);
		string nameToy = "toy" + to_string(i + 1);
		int age = i + 5;

		toys.resize(i + 1);
		dogs.resize(i + 1);

		toys[i] = make_shared<Toy>(nameToy);
		dogs[i] = make_shared<Dog>(name, age, toys[i]);
	}

	dogs[3]->dropToy();
	dogs[0]->dropToy();
	dogs[2]->dropToy();
	dogs[0]->dropToy();
	dogs[4]->dropToy();

	dogs[0]->getToy(toys[1], dogs);
	dogs[1]->getToy(toys[1], dogs);
	dogs[4]->getToy(toys[0], dogs);

	for (int i = 0; i < 5; ++i)
	{
		cout << toys[i].use_count() - 1 << endl;
	}

	for (int i = 0; i < 5; ++i)
	{
		cout << dogs[i]->getToyPtr().use_count()  << endl;
	}
	
}
