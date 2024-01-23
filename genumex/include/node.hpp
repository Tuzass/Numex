#include "token.hpp"

class Node {
public:
    virtual double evaluate() = 0;
    virtual ~Node();
    virtual void clear();
};

class NumberNode : public Node {
    friend class Tree;
    NumberToken token;
    Node* left;
    Node* right;

    void clear() override final;
    double evaluate() override final;

public:
    NumberNode(const NumberToken&);
    NumberNode(const double&);
};

class OperationNode : public Node {
    friend class Tree;
    OperationToken token;
    Node* left;
    Node* right;

    void clear() override final;
    double evaluate() override final;

public:
    OperationNode(const OperationToken&);
    OperationNode(const char&);
};
