#include "token.hpp"

class Node {
public:
    virtual double evaluate() = 0;
    virtual ~Node() = 0;
    virtual void clear() = 0;
};

class NumberNode : public Node {
    friend class Tree;
    NumberToken token;
    Node* left;
    Node* right;

    void clear() override;
    double evaluate() override;

public:
    NumberNode(const NumberToken&);
    NumberNode(const double&);
    ~NumberNode() override;
};

class OperationNode : public Node {
    friend class Tree;
    OperationToken token;
    Node* left;
    Node* right;

    void clear() override;
    double evaluate() override;

public:
    OperationNode(const OperationToken&);
    OperationNode(const char&);
    ~OperationNode() override;
};
