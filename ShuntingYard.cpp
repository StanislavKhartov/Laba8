#include "ShuntingYard.h"
#include <cmath>
#include <cctype>
#include <cstring>
#include "Stack.h"

bool isOperator(char operator_)
{
  return operator_ == '*' || operator_ == '-' || operator_ == '/' || operator_ == '+';
}

void addSymbol(char string[], int* index, const char symbol)
{
  string[(*index)] = symbol;
  (*index)++;
  string[*index] = ' ';
  (*index)++;
}

bool infixToPostfix(char output[], char string[])
{
  StackOnNodes<char> s;
  int index = 0;
  for (int i = 0; string[i] != '\0' && string[i] != '\n'; i++)
  {
    if (isdigit(string[i]))
    {
      addSymbol(output, &index, string[i]);
    }
    else if (string[i] == '(')
    {
      s.push('(');
      if (s.is_empty())
      {
        strcpy(output, "An error occured");
        return true;
      }
    }
    else if (string[i] == '*' || string[i] == '/')
    {
      while (!s.is_empty() && (s.top() == '*' || s.top() == '/'))
      {
        addSymbol(output, &index, s.pop());
      }
      s.push(string[i]);
      if (s.is_empty())
      {
        strcpy(output, "An error occured");
        return true;
      }
    }
    else if (string[i] == '+' || string[i] == '-')
    {
      while (!s.is_empty() && isOperator(s.top()))
      {
        addSymbol(output, &index, s.pop());
      }
      s.push(string[i]);
      if (s.is_empty())
      {
        strcpy(output, "An error occured");
        return true;
      }
    }
    else if (string[i] == ')')
    {
      while (s.top() != '(')
      {
        if (s.is_empty())
        {
          strcpy(output, "Invalid expression");
          return true;
        }
        addSymbol(output, &index, s.pop());
      }
      s.pop();
    }
    else if (string[i] != ' ')
    {
      strcpy(output, "Invalid expression");
      return true;
    }
  }
  while (!s.is_empty())
  {
    char token = s.pop();
    if (token == '(')
    {
      strcpy(output, "Invalid expression");
      return true;
    }
    addSymbol(output, &index, token);
  }
  return false;
}


bool getValues(int* a, int* b, StackOnNodes<int> s)
{
  if (s.is_empty())
  {
    return false;
  }
  *a = s.pop();
  if (s.is_empty())
  {
    return false;
  }
  *b = s.pop();
  return true;
}

bool getAnExpressionValue(char string[], int *result)
{
  StackOnNodes<int> s;
  for (int i = 0; string[i] != '\0'; i++)
  {
    int a = 0;
    int b = 0;
    if (isdigit(string[i]))
    {
      s.push(string[i] - '0');
      continue;
    }
    if (isOperator(string[i]) && !getValues(&a, &b, s))
    {
      return true;
    }
    switch (string[i])
    {
      case '+':
         s.push(b + a);
        break;
      case '-':
        s.push(b- a);
        break;
      case '*':
        s.push(b*a);
        break;
      case '/':
        s.push(b/a);
        break;
      default:
        break;
    }
  }
  *result = s.pop();
  if (!s.is_empty())
  {
    return true;
  }
  return false;
}