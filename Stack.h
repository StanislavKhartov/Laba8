#ifndef CALCULATOR__STACK_H_
#define CALCULATOR__STACK_H_

#include <vector>

template<typename T>
struct Node {
  T value_;
  Node *next_;
};

template<typename T>
class StackOnNodes {
 private:
  Node<T> *head_;
  int size_;
 public:
  StackOnNodes() : size_(0) {
    head_ = nullptr;
  }
  ~StackOnNodes(){
    while(head_ != nullptr){
      pop();
    }
  }

  StackOnNodes& operator =(const StackOnNodes& right){
    std::vector<T> numbers;
    Node<T>* tmp = right.head_;
    while(tmp != nullptr){
      numbers.push_back(tmp->value_);
      tmp = tmp->next_;
    }
    for(int i = numbers.size()- 1; i >= 0; --i){
      push(numbers[i]);
    }
    return *this;
  }

  void push(T value) {
    Node<T> *a = new(Node<T>);
    a->next_ = head_;
    a->value_ = value;
    size_++;
    head_ = a;
  }

  T pop() {
    if(size_!= 0) {
      Node<T> *tmp = head_;
      head_ = tmp->next_;
      T answer = tmp->value_;
      size_--;
      delete tmp;
      return answer;
    }
    throw std::runtime_error("Stack is empty");
  }

  T top() {
    return head_->value_;
  }

  void operator <<(T value){
    push(value);
  }

  T operator >>(StackOnNodes right){
    return ;
  }

  bool operator <(const StackOnNodes& right){
    return (top() < right.top());
  }

  bool operator == (const StackOnNodes& right){
    return (top() == right.top());
  }

  T operator [](int index){
    Node<T>* tmp;
    for(int i = 0; i<index; i++){
      tmp = tmp->next_;
    }
    return tmp->value_;
  }

  bool is_empty(){
    return head_ == nullptr;
  }

};

#endif //CALCULATOR__STACK_H_
