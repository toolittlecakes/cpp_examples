
#ifndef EXAMPLES_MULTIPLE_INHERITANCE_HPP
#define EXAMPLES_MULTIPLE_INHERITANCE_HPP
namespace multiple_inheritance {

#include<iostream>

    struct A {
    public:
        size_t i = 1;

        A() {
            std::cout << "A default ctor " << std::endl;
        }

        explicit A(size_t i) : i{i} {
            std::cout << "A ctor with arg" << std::endl;
        }

        virtual int foo() {
            return 1;
        }
    };

    struct B : public virtual A {
        B() : A{2} {}

        int foo() override {
            return 2;
        }
    };

    struct C : public virtual A {
        C() : A{3} {}

        int foo() override {
            return 3;
        }

        virtual void bar() {
            std::cout << "bar" << std::endl;
        }
    };

    struct D : public B, public C {
        D() = default;

        // D must have own foo override, because doesn't know which one should use
        int foo() override {
            return B::foo();
        }

    };

    int main() {
        D d; // A default
        C c; // A with arg == 3


        std::cout << d.foo() << std::endl; // B realisation
        std::cout << d.C::foo() << std::endl; // explicit C realization

        C *c_ptr = &d;
        B *b_ptr = &d;
        A *a_ptr = &d;

        std::cout << std::endl;


        std::cout << "D:" << (size_t) &d << std::endl; // start
        std::cout << "B:" << (size_t) b_ptr << std::endl; // 8 B (or 4 for x32 architecture)
        std::cout << "C:" << (size_t) c_ptr << std::endl; // 8 B (or 4 for x32 architecture)
        std::cout << "A:" << (size_t) a_ptr << std::endl; // 16 B (or 8 for x32 architecture)
        std::cout << "_:" << (size_t) (&d + 1) << std::endl; // end

//    memory:
//    |B{vtable_ptr D:B}|C{vtable_ptr D:C}|A{vtable_ptr D:A, size_t i}| D{empty} |
//    All vtables has functions overloaded by D.
//    That's why d.foo() == b_ptr->foo() == c_ptr->foo() == a_ptr->foo() == 2
//    But also there is address of bar function in c_ptr->vtable.
//    When you write d.bar() it does something like that: d.C->vtable[1] (index 0 is foo())

        std::cout << std::endl;

//    different vtable adresses
        std::cout << "D vtable:" << *(size_t *) &d << std::endl;
        std::cout << "B vtable:" << *(size_t *) b_ptr << std::endl;
        std::cout << "C vtable:" << *(size_t *) c_ptr << std::endl;
        std::cout << "A vtable:" << *(size_t *) a_ptr << std::endl;

        return 0;
    }
}

#endif //EXAMPLES_MULTIPLE_INHERITANCE_HPP
