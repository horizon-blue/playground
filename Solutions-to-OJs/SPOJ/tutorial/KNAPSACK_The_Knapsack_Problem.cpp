// Xiaoyan Wang 11/9/2016
#include <iostream>
// #include <vector>
using namespace std;

int max_value[2001][2001];
int sizes[2001];
int value[2001];
int capacity, num_item;

// struct Item {
//   int size;
//   int value;
//   Item() = default;
//   Item(int s, int v) : size(s), value(v) {}
//   Item(istream& is) { is >> size >> value; }
// };

// vector<Item> collection;

int main() {
  ios::sync_with_stdio(false);
  cin >> capacity >> num_item;
  // collection.reserve(num_item + 1);
  // collection.emplace_back(0, 0);
  // while (--num_item) collection.emplace_back(cin);
  // num_item = collection.size();
  for (int i = 1; i <= num_item; ++i) cin >> sizes[i] >> value[i];

  for (int i = 1; i <= num_item; ++i)
    for (int j = 1; j <= capacity; ++j) {
      max_value[i][j] = max_value[i - 1][j];
      if (j - sizes[i] >= 0 &&
          max_value[i][j] < max_value[i - 1][j - sizes[i]] + value[i])
        max_value[i][j] = max_value[i - 1][j - sizes[i]] + value[i];
    }

  cout << max_value[num_item][capacity] << endl;
  return 0;
}