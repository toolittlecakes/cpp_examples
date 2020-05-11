
#ifndef EXAMPLES_DYNAMIC_CAST_HPP
#define EXAMPLES_DYNAMIC_CAST_HPP


namespace simple_dynamic_cast {

    struct A {
        int a;
        virtual void foo() {
            std::cout << typeid(*this).name() ;
        }
    };

    struct B : A {
        int b;
    };
    template<typename To, typename From>
    To* cast(From* b) {
        if(typeid(To) == typeid(*b)) {
            int x = 0;
            return reinterpret_cast<To*>(b);
        }
        return nullptr;
    }
    int main() {
        B b;
        A& b_ref = b;
        A* b_ptr = &b;
        std::cout << typeid(b_ptr).name() << std::endl;
        B *b_real_ptr = cast<B>(b_ptr);
        b_real_ptr->foo();
        return 0;
    }
}
#endif //EXAMPLES_DYNAMIC_CAST_HPP
