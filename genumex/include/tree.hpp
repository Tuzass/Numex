#include "node.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <exception>

class Tree {
    Node* root;
    std::string expression;
    std::vector<std::string> string_tokens;

    class Bad_expression {};
    void clear();
    std::string getToken(unsigned int&);
    bool validateToken(const std::string&);
    void infixReading();
    void postfixReading();
    void parse();

public:
    Tree(std::string);
    ~Tree();
    void build();
};
