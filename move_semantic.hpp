#ifndef EXAMPLES_MOVE_SEMANTIC_HPP
#define EXAMPLES_MOVE_SEMANTIC_HPP
namespace move_semantic {
#include <iostream>

    struct A {
        A() {
            std::cout << "A def" << std::endl;
        }
        A(const A& a) {
            std::cout << "A copy" << std::endl;
        }
        A(A&& a)  {
            std::cout << "A move" << std::endl;
        }
    };


    struct B {
        A a;
        B() {
            std::cout << "B def" << std::endl;
        }
        B(const B& b): a(b.a) {
            std::cout << "B copy" << std::endl;
        }
        B(B&& b): a(std::move(b.a)) {
            std::cout << "B move" << std::endl;
        }
        B(const A& a): a(a){
            std::cout << "B from copied a" << std::endl;
        }
        B(A&& a): a(std::move(a)){
            std::cout << "B from moved a" << std::endl;
        }
        B(A a): a(std::move(a)){
            std::cout << "B from a" << std::endl;
        }

    };

    int main() {

        B b{};
//    A&&a = std::move(b.a);
//    A a1(std::move(a));
        A a2(std::move(b.a));
        B b2 (b);
        B b3 (std::move(b));
        B b4 (B{});
        B b5(b2.a);
        B b6(std::move(b2.a));
        return 0;
    }
}
#endif //EXAMPLES_MOVE_SEMANTIC_HPP
