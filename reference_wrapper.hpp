

#ifndef EXAMPLES_REFERENCE_WRAPPER_HPP
#define EXAMPLES_REFERENCE_WRAPPER_HPP

namespace reference_wrapper {

    #include <iostream>
    #include <vector>
    #include <functional>

    template <typename T>
    void foo(const std::vector<T> &strings) {
        for (const std::string &str: strings) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    int main() {
        std::vector<std::string> strings{"a", "b", "c"};
        std::vector<std::reference_wrapper<std::string>> string_refs{strings.begin(), strings.end()};
        std::vector<std::reference_wrapper<std::string>> string_refs2{
                std::ref(strings[0]),
                std::ref(strings[1]),
                std::ref(strings[2]),

        };
        foo(strings);
        foo(string_refs);
        foo(string_refs2);
        return 0;
    }
}
#endif //EXAMPLES_REFERENCE_WRAPPER_HPP
