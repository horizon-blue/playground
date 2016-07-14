// Exercise 9.52
// Use a stack to process parenthesized expressions.
// When you see an open parenthesis, not that it was
// seen. When you see a close parenthesis after an
// open parenthesis, pop elements down to and including
// the open parenthesis off the stack. push a value onto
// the stack to indicate that a parenthesized expression
// was replaced
// Xiaoyan Wang 7/15/2016
// I was thinking about making this a calculator... But it
// seems to be kind of stupid (and extremely inefficient)
#include <string>
#include <iostream>
#include <stack>
using std::string;
using std::stack;
using std::cout;
using std::stoi;
using std::to_string;

void evaluation(string& expr);

int main() {
  string expr = "";
  cout << "Please enter an expression:\n";
  std::getline(std::cin, expr);

  int numparen = 0; // number of parenthesis
  stack<char> stck;
  for(char c : expr) {
    if(c == '(') {
      ++numparen;
      stck.push(c);
    }
    else if(c == ')') {
      if(numparen == 0) {
	std::cerr << "Mismatched parenthesis." << std::endl;
	return 1;
      }
      else {
	--numparen;
	string subexpr = "";
	while(stck.top() != '(') {
	  subexpr = stck.top() + subexpr;
	  stck.pop();
	}
	stck.pop();
	evaluation(subexpr);
	for(char subc : subexpr)
	  stck.push(subc);
      }
    }
    else if(c != ' ')
      stck.push(c);
  }

  if(numparen != 0) {
    std::cerr << "Mismatched parenthesis." << std::endl;
    return 1;
  }

  string subexpr = "";
  while(!stck.empty()) {
    subexpr = stck.top() + subexpr;
    stck.pop();
  }
  evaluation(subexpr);
  
  cout << expr << " = " << subexpr << std::endl;
  return 0;
}

void evaluation(string& expr) {

  string first = "*/";
  string second = "+-";
  string num = "-0123456789";

  for(string::size_type pos = 0;
      (pos = expr.find_first_of(first)) != string::npos;) {
    auto posa = expr.substr(0, pos).find_last_not_of(num) + 1;
    auto posb = expr.find_first_not_of(num, pos+1);
    if(posa == string::npos)
      posa = 0;
    if(posb == string::npos)
      posb = expr.size();
    int numa = stoi(expr.substr(posa, pos - posa));
    int numb = stoi(expr.substr(pos+1, posb-pos-1));
    int result = 0;
    if(expr[pos] == '*')
      result = numa * numb;
    else
      result = numa / numb;
    expr.replace(posa, posb - posa, to_string(result));
  }

  for(string::size_type pos = 0;
      (pos = expr.find_first_of(second, 1)) != string::npos;) {
    auto posa = expr.substr(0, pos).find_last_not_of(num) + 1;
    auto posb = expr.find_first_not_of(num, pos+1);
    if(posa == string::npos)
      posa = 0;
    if(posb == string::npos)
      posb = expr.size();
    int numa = stoi(expr.substr(posa, pos - posa));
    int numb = stoi(expr.substr(pos+1, posb-pos-1));
    int result = 0;
    if(expr[pos] == '+')
      result = numa + numb;
    else
      result = numa - numb;
    expr.replace(posa, posb - posa, to_string(result));
  }

}
