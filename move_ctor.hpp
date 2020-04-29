
#ifndef EXAMPLES_MOVE_CTOR_HPP
#define EXAMPLES_MOVE_CTOR_HPP

#include <iostream>

namespace move_ctor {
    struct A {
        int value = 0;
        A() {
            std::cout << "A def ctor" << std::endl;
        }
        A(const A& other) :value{other.value} {
            std::cout << "A copy ctor" << std::endl;
        }
        A(A&& other)  noexcept : value{std::move(other.value)} {
            std::cout << "A move ctor" << std::endl;
        }
    };


    struct B {
        A value{};
        B() {
            std::cout << "B def ctor" << std::endl;
        }
        B(const B& other) :value{other.value} {
            std::cout << "B copy ctor" << std::endl;
        }
        B(B&& other)  noexcept : value{std::move(other.value)} {
            std::cout << "B move ctor" << std::endl;
        }


        explicit B(A other_value): value{std::move(other_value)} {}
    };



    int main() {

        B b0; // def
        B b1{b0}; // copy A, copy B
        B b2{std::move(b1)}; // move A, move B

        std::cout << std::endl;
        A a{};
        B b3{a}; // copy A
        B b4{std::move(a)}; // move A (double move: first move to other_value aka B ctor arg,
                            // second from other_value to A value ctor

        B b5{A{}}; // def A, move A

        return 0;
    }
}
#endif //EXAMPLES_MOVE_CTOR_HPP
