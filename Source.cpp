#include <iostream>
#include <string>

using namespace std;

class Pet {
protected:
    string name;
    int age;  
    double weight;

public:
    Pet(const string& name, int age, double weight) : name(name), age(age), weight(weight) {}

    virtual void Sound() const {
        cout << "Unknown animal sound." << endl;
    }

    virtual void Show() const {
        cout << "Name: " << name << ", Age: " << age << " years, Weight: " << weight << " kg" << endl;
    }

    virtual void Type() const {
        cout << "Unknown animal type." << endl;
    }

    virtual ~Pet() {}
};

class Dog : public Pet {
    string breed;

public:
    Dog(const string& name, int age, double weight, const string& breed): Pet(name, age, weight), breed(breed) {}

    void Sound() const {
        cout << name << " says: Woof!" << endl;
    }

    void Type() const {
        cout << name << " is a Dog of breed: " << breed << endl;
    }

    void Show() const {
        Pet::Show();
        cout << "Breed: " << breed << endl;
    }
};

class Cat : public Pet {
    string color;

public:
    Cat(const string& name, int age, double weight, const string& color)
        : Pet(name, age, weight), color(color) {}

    void Sound() const {
        cout << name << " says: Meow!" << endl;
    }

    void Type() const {
        cout << name << " is a Cat of color: " << color << endl;
    }

    void Show() const {
        Pet::Show();
        cout << "Color: " << color << endl;
    }
};

class Parrot : public Pet {
    string favorite_food; 

public:
    Parrot(const string& name, int age, double weight, const string& favorite_food): Pet(name, age, weight), favorite_food(favorite_food) {}

    void Sound() const {
        cout << name << " says: Squawk!" << endl;
    }

    void Type() const {
        cout << name << " is a Parrot." << endl;
    }

    void Show() const {
        Pet::Show(); 
        cout << "Favorite food: " << favorite_food << endl;
    }
};

class Hamster : public Pet {
    bool is_nocturnal; 

public:
    Hamster(const string& name, int age, double weight, bool is_nocturnal): Pet(name, age, weight), is_nocturnal(is_nocturnal) {}

    void Sound() const {
        cout << name << " says: Squeak!" << endl;
    }

    void Type() const {
        cout << name << " is a Hamster." << endl;
    }

    void Show() const {
        Pet::Show();
        cout << "Is nocturnal: " << (is_nocturnal ? "Yes" : "No") << endl;
    }
};

int main() {
    Pet* pets[] = {
        new Dog("Buddy", 3, 20.5, "Golden Retriever"),
        new Cat("Whiskers", 2, 4.3, "Black"),
        new Parrot("Polly", 5, 1.2, "Seeds"),
        new Hamster("Nibbles", 1, 0.3, true)
    };

    for (int i = 0; i < 4; ++i) {
        pets[i]->Show();
        pets[i]->Type();
        pets[i]->Sound();
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete pets[i];
    }

    return 0;
}