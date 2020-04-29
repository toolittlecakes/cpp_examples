
#ifndef EXAMPLES_VIRTUAL_FUNCTION_HPP
#define EXAMPLES_VIRTUAL_FUNCTION_HPP

#include <string>
#include <iostream>
#include <vector>

namespace virtual_function {
    class Animal {
    protected:
        std::string name;
    public:
        explicit Animal(const std::string& name) : name{name} {}

        virtual void print_name() {
            std::cout << "My name is " << name << std::endl;
        }

        virtual void print_sound() = 0;

        virtual ~Animal() = default;
    };

    class Dog : public Animal {
    public:
        explicit Dog(const std::string& name="Bobik") : Animal{name} {};
        void print_sound() override {
            std::cout << "Gav" << std::endl;
        }
    };

    class Cat : public Animal {
    public:
        explicit Cat(const std::string& name="Barsik") : Animal{name} {};
        void print_sound() override {
            std::cout << "Meu" << std::endl;
        }
        void print_name() override {
            std::cout <<  "I am " << name << ". I came to kill you" << std::endl;
        }
    };


    int main() {
        Cat cat{};
        Dog dog{};
        Cat uncommon_cat {"Begemot"};
        std::vector<Animal*> animals {&cat, &dog, &uncommon_cat};

        for(int i = 0; i < animals.size(); i++) {
            animals[i]->print_sound();
            animals[i]->print_name();
        }


        return 0;
    }


}
#endif //EXAMPLES_VIRTUAL_FUNCTION_HPP
