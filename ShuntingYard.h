#ifndef CALCULATOR__SHUNTINGYARD_H_
#define CALCULATOR__SHUNTINGYARD_H_
#include "Stack.h"

bool isOperator(char operator_);

void addSymbol(char string[], int* index, const char symbol);

bool infixToPostfix(char output[], char string[]);

bool getAnExpressionValue(char string[], int *result);

bool getValues(int* a, int* b, StackOnNodes<int> s);


#endif //CALCULATOR__SHUNTINGYARD_H_
