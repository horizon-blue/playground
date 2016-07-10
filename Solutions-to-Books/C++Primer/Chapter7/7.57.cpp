// Exercise 7.57
// Write your own version of the Account class.
// Xiaoyan Wang 3/25/2016

class Account {
public:
  static double rate() { return interestRate; }
  static void rate(double);
private:
  static constexpr int period = 30;
  double daily_tbl[period];
}
