#ifndef CALCULATOR__CALCULATOR_H_
#define CALCULATOR__CALCULATOR_H_

#include "Stack.h"
#include <string>
#include "ShuntingYard.h"

template<typename T>
class Calculator{
 private:
  string expression_;
 public:
  Calculator(string expression){
    string form;
    if (!infixToPostfix(form, expression)){
      expression_ = form;
    }else{
      std::cout <<"Wrong expression\n";
    }
  };

  ~Calculator() = default;

  T calculate(){
    T answer;
    getAnExpressionValue(expression_, answer);
    return answer;
  }
};

#endif //CALCULATOR__CALCULATOR_H_
