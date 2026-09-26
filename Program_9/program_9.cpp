#include <iostream>

class Animal {
public:
    virtual void sound() const {
        std::cout << "Animal makes a sound\n";
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() const override {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void sound() const override {
        std::cout << "Cat meows\n";
    }
};

class Cow : public Animal {
public:
    void sound() const override {
        std::cout << "Cow moos\n";
    }
};

int main() {
    Dog dog;
    Cat cat;
    Cow cow;

    Animal* animal = &dog;
    animal->sound();

    animal = &cat;
    animal->sound();

    animal = &cow;
    animal->sound();

    return 0;
}
