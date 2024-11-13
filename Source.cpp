#include <iostream>
#include <string>

using namespace std;

class Pet {
protected:
    string name;
    int age;

public:
    Pet(string name, int age) : name(name), age(age) {}

    virtual void showInfo() const {
        cout << "Undefined" << endl;
    }
};

class Dog : public Pet {
    string breed;

public:
    Dog(string name, int age, string breed) : Pet(name, age), breed(breed) {}

    void showInfo() const {
        cout << "Dog\nName: " << name << "\nAge: " << age << " years\nBreed: " << breed << endl;
    }
};

class Cat : public Pet {
    string color;

public:
    Cat(string name, int age, string color) : Pet(name, age), color(color) {}

    void showInfo() const {
        cout << "Cat\nName: " << name << "\nAge: " << age << " years\nColor: " << color << endl;
    }
};

class Parrot : public Pet {
    string species;

public:
    Parrot(string name, int age, string species) : Pet(name, age), species(species) {}

    void showInfo() const {
        cout << "Parrot\nName: " << name << "\nAge: " << age << " years\nSpecies: " << species << endl;
    }
};

class Hamster : public Pet {
    double weight;

public:
    Hamster(string name, int age, double weight) : Pet(name, age), weight(weight) {}

    void showInfo() const {
        cout << "Hamster\nName: " << name << "\nAge: " << age << " years\nWeight: " << weight << " kg" << endl;
    }
};

int main() {
    Pet* pets[4];

    pets[0] = new Dog("Buddy", 5, "Golden Retriever");
    pets[1] = new Cat("Whiskers", 3, "Gray");
    pets[2] = new Parrot("Polly", 2, "Macaw");
    pets[3] = new Hamster("Nibbles", 1, 0.25);

    for (int i = 0; i < 4; i++) {
        pets[i]->showInfo(); 
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete pets[i];
    }

    return 0;
}