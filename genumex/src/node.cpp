#include "../include/node.hpp"

NumberNode::NumberNode(const NumberToken& nToken) :
    token{ nToken }, left{ nullptr }, right{ nullptr } {}

NumberNode::NumberNode(const double& d) :
    token{ NumberToken{d} }, left{ nullptr }, right{ nullptr } {}

NumberNode::~NumberNode() { clear(); }

void NumberNode::clear() {
    if (left) left->clear();
    delete left;
    if (right) right->clear();
    delete right;
}

double NumberNode::evaluate() {
    return token.value;
}

OperationNode::OperationNode(const OperationToken& nToken) :
    token{ nToken }, left{ nullptr }, right{ nullptr } {}

OperationNode::OperationNode(const char& c) :
    token{ OperationToken{c} }, left{ nullptr }, right{ nullptr } {}

OperationNode::~OperationNode() { clear(); }

double OperationNode::evaluate() {
    switch (token.operation) {
    case OperationToken::Addition:
        return left->evaluate() + right->evaluate();
    case OperationToken::Subtraction:
        return left->evaluate() - right->evaluate();
    case OperationToken::Multiplication:
        return left->evaluate() * right->evaluate();
    case OperationToken::Division:
        return left->evaluate() / right->evaluate();
    }

    return 0.0;
}

void OperationNode::clear() {
    if (left) left->clear();
    delete left;
    if (right) right->clear();
    delete right;
}
