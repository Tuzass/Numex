#include "../include/tree.hpp"

Tree::Tree(std::string str) :
    root{ nullptr }, expression{ str } {}

Tree::~Tree() { clear(); }

void Tree::clear() {
    root->clear();
    delete root;
}

void Tree::parse() {
    // bool infix_possible{ true };

    std::cout << "test 0" << std::endl;
    infixReading();
    for (const std::string& token : string_tokens) std::cout << token << std::endl;

    // try { infixReading(); }
    // catch (Bad_expression& e) { infix_possible = false; }

    // if (infix_possible) return;

    // try { postfixReading(); }
    // catch (Bad_expression& e) { std::cout << "Invalid expression!" << std::endl; }
}

std::string Tree::getToken(unsigned int& index) {
    using std::string;
    string operators_string{ "+-*/()" };
    string current_token{};

    for (; index < expression.size(); index++) {
        char c{ expression[index] };

        if (c == ' ') {
            if (!current_token.empty()) break;
        } else if (operators_string.find(c) != string::npos) {
            if (current_token.empty()) {
                current_token += c;
                index++;
                break;
            } else {
                if (!current_token.empty()) break;
            }
        } else current_token += c;

    }

    return current_token;
}

bool Tree::validateToken(const std::string& token_string) {
    bool seenDot{ false };
    std::string operators_string{ "+-*/()" };

    if (token_string.size() == 1 && operators_string.find(token_string)) return true;

    for (char c : token_string) {
        if (c == '.') {
            if (seenDot) return false;
            else seenDot = true;
        } else if (c < 48 && c > 57) return false;
    }

    return true;
}

void Tree::infixReading() {
    std::vector<std::string> tokens{};
    // bool number_last{ false };
    // bool seenDot{ false };
    unsigned int index{ 0 };
    std::string token_string = getToken(index);

    while (!token_string.empty()) {
        token_string = getToken(index);
        if (validateToken(token_string)) tokens.push_back(token_string);
    }

    string_tokens = tokens;
}

void Tree::postfixReading() {

}

void Tree::build() {
    parse();
}
