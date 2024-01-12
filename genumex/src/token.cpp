#include "../include/token.hpp"

NumberToken::NumberToken(double val) :
    value{ val } {}

OperationToken::OperationToken(char c) :
    operation{ (Operation)c } {}
