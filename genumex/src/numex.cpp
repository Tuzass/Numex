#include "../include/tree.hpp"

int main() {
    std::string expression{};
    std::cout << "Enter the numerical expression: ";
    std::cin >> expression;

    Tree t{ expression };
    t.build();

    return 0;
}
