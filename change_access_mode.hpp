
#ifndef EXAMPLES_CHANGE_ACCESS_MODE_HPP
#define EXAMPLES_CHANGE_ACCESS_MODE_HPP

#include <iostream>

namespace change_access_mode {
    class Parent {
    protected:
        static void protected_method() {
            std::cout << "parent's protected method" << std::endl;
        }
    public:
        static void public_method() {
            std::cout<< "parent's public method" << std::endl;;
        }
        virtual ~Parent() = default;
    };

    class Child final : public Parent {
    private:
        using Parent::public_method; // Not a public method anymore
    public:
        using Parent::protected_method; // It's open for everybody!!!
    };



    int main() {
        Parent::public_method();
//        Parent::protected_method(); // compilation error
        Child::protected_method();
//        Child::public_method(); // compilation error
        return 0;
    }
}

#endif //EXAMPLES_CHANGE_ACCESS_MODE_HPP
