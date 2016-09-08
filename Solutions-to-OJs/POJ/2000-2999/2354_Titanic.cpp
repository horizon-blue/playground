// Xiaoyan Wang 9/8/2016
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
// #include <cstdlib>
using std::cin;
using std::cout;
using std::string;
using std::cos;
using std::sin;
using std::acos;

int main() {
	// processing input
	string garbage;
	// use the 0'th index for south/north/east/west info.
	double x[3], y[3], a[3], b[3];
	char dir[3];
	const double R = 6875.0/2; // radius of earth (in mile)
	const double PI = acos(-1.0);
	// ignore the first three lines
	std::getline(cin, garbage);
	std::getline(cin, garbage);
	std::getline(cin, garbage);
	scanf("%lf^%lf'%lf\" %c", &x[0], &x[1], &x[2], &dir[0]);
	std::getline(cin, garbage); // eat the rest of line
	cin >> garbage;
	scanf("%lf^%lf'%lf\" %c", &y[0], &y[1], &y[2], &dir[1]);
	// cout << y[1] << ' ' << y[2] << ' ' << y[3] << ' ' << 
	// static_cast<char>(y[0]) << endl;
	std::getline(cin, garbage); // east the rest of line again
	std::getline(cin, garbage);
	scanf("%lf^%lf'%lf\" %c", &a[0], &a[1], &a[2], &dir[2]);
	std::getline(cin, garbage); // eat the rest of line
	cin >> garbage;
	scanf("%lf^%lf'%lf\" %c", &b[0], &b[1], &b[2], &dir[3]);
	std::getline(cin, garbage); 
	std::getline(cin, garbage);
	// ios::sync_with_stdio(false);
	// end processing input

	double phi1 = PI * (x[0] + x[1]/60 + x[2]/3600)/180 * ((dir[0] == 'N') ? 1 : -1);
	double phi2 = PI * (a[0] + a[1]/60 + a[2]/3600)/180 * ((dir[2] == 'N') ? 1 : -1);
	double lambda1 = PI * (y[0] + y[1]/60 + y[2]/3600)/180 * ((dir[1] == 'E') ? 1 : -1);
	double lambda2 = PI * (b[0] + b[1]/60 + b[2]/3600)/180 * ((dir[3] == 'E') ? 1 : -1);
	// phi1 = (dir[0] == 'N') ? phi1 : -phi1;
	// phi2 = (dir[2] == 'N') ? phi2 : -phi2;
	// lambda1 = (dir[1] == 'E') ? lambda1 : -lambda1;
	// lambda2 = (dir[3] == 'E') ? lambda2 : -lambda2;

	// cout << static_cast<char>(x[0]) << endl;
	// cout << dir[0] << dir[1] << dir[2] << dir[3] << endl;
	// cout << phi1 << ' ' << phi2 << ' ' << lambda1 << ' ' << lambda2 << endl;

	// double temp1 = sin((phi2 - phi1)/2), temp2 = sin((lambda2 - lambda1)/2);


	// // Haversine formula
	// double result = abs(sin((phi2 - phi1)/2)*sin((phi2 - phi1)/2) + cos(phi1)*cos(phi2)*sin((lambda2 - lambda1)/2)*sin((lambda2 - lambda1)/2));
	// if(result > 1)
	// 	result = 1;
	// result = abs(D * asin(sqrt(result)));


	// Great-circle distance
	double result = R * acos(sin(phi1)*sin(phi2) + cos(phi1)*cos(phi2)*cos(lambda1-lambda2));

	printf("The distance to the iceberg: %.2lf miles.\n", result);
	if(floor(result+0.005) < 100)
		printf("DANGER!\n");

	return 0;
}