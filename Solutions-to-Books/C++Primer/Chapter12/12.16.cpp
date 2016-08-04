// Exercise 12.16
// Compilers don’t always give easy-to-understand error messages if we attempt to copy
// or assign a unique_ptr. Write a program that contains these errors to see how your
// compiler diagnoses them.
#include <memory>
using std::unique_ptr;

int main() {
	unique_ptr<int> up1(new int(100));
	unique_ptr<int> up2 = up1;
	unique_ptr<int> up3(up1);
	// ...\12.16.cpp: In function 'int main()':
	// ...\12.16.cpp:13:25: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]'
	//   unique_ptr<int> up3(up1);
	//                          ^
	// In file included from ...\mingw\lib\gcc\mingw32\4.8.1\include\c++\memory:81:0,
	//                  from ...\12.16.cpp:5:
	// ...\mingw\lib\gcc\mingw32\4.8.1\include\c++\bits\unique_ptr.h:273:7: error: declared here
	//        unique_ptr(const unique_ptr&) = delete;
	return 0;
}