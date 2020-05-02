
#ifndef EXAMPLES_VECTOR_REF_HPP
#define EXAMPLES_VECTOR_REF_HPP

#include <vector>
#include <functional>
#include <iostream>
namespace vector_ref {
    /// How to put references in vector.
    int main() {
        std::vector<std::reference_wrapper<int>> references;

        int x = 1;
        int y = 2;
        references.push_back(std::ref(x));
        references.push_back(y);


        for (auto &item: references) {
            std::cout << item << std::endl;
        }


        return 0;
    }
}

#endif //EXAMPLES_VECTOR_REF_HPP
