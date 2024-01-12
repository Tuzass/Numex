class NumberToken {
    friend class NumberNode;
    double value;

public:
    NumberToken(double);
    ~NumberToken() = default;
};

class OperationToken {
    friend class OperationNode;
    enum Operation { Addition = '+', Subtraction = '-', Multiplication = '*', Division = '/' };
    Operation operation;

public:
    OperationToken(char);
    ~OperationToken() = default;
};
