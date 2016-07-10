// Exercise 7.31
// Define a pair of classes X and Y, in which X has
// a pointer to Y, and Y has an object of type X
// Xiaoyan Wang 3/22/2016
struct Y;
struct X {
  // a pointer to Y
  Y *ptr;
};

struct Y {
  // an object of type X
  X obj;
};
