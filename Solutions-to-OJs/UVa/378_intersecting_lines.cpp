// Xiaoyan Wang 10/19/2016
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define EPSILON 0.00001

struct Point {
	int x;
	int y;
};

istream& operator>>(istream& is, Point& p);

int ccw(const Point& a, const Point& b, const Point& c);

int main() {
	ios::sync_with_stdio(false);
	int numlines;
	Point a, b, c, d;
	cin >> numlines;
	cout << "INTERSECTING LINES OUTPUT\n" << fixed << setprecision(2);
	while(numlines--) {
		cin >> a >> b >> c >> d;
		int ccwabc = ccw(a, b, c);
		int ccwabd = ccw(a, b, d);
		int ccwcda = ccw(c, d, a);
		int ccwcdb = ccw(c, d, b);
		if(!ccwabc && !ccwabd && !ccwcda && !ccwcdb) {
			cout << "LINE\n";
			continue;
		}
		if(a.x == b.x && c.x == d.x) {
			cout << "NONE\n";
			continue;
		}

		// double a1, m1, a2, m2;
		double intersecx, intersecy;

		if(a.x == b.x) {
				double m2 = (static_cast<double>(d.y - c.y))/(d.x - c.x);
				double a2 = d.y - m2 * d.x;
				intersecx = a.x;
				intersecy = (intersecx * m2) + a2;
		}
		else if(c.x == d.x) {
			double m1 = (static_cast<double>(b.y - a.y))/(b.x - a.x);
			double a1 = b.y - m1 * b.x;
			intersecx = c.x;
			intersecy = (intersecx * m1) + a1;
		}
		else {
			double m1 = (static_cast<double>(b.y - a.y))/(b.x - a.x);
			double a1 = b.y - m1 * b.x;
			double m2 = (static_cast<double>(d.y - c.y))/(d.x - c.x);
			double a2 = d.y - m2 * d.x;
			if(fabs(m1 - m2) < EPSILON) {
				cout << "NONE\n";
				continue;
			}
			intersecx = (a2 - a1) / (m1 - m2);
			intersecy = (intersecx * m1) + a1;
		}
		cout << "POINT " << intersecx << ' ' << intersecy << '\n';
		// if(ccwabc * ccwabd < 0 && ccwcda * ccwcdb < 0) {
		// 	cout << "POINT " << intersecx << ' ' << intersecy << '\n';
		// 	continue;			
		// }
		// // if((fabs(intersecx - a.x) < 0.01 && fabs(intersecy - a.y) < 0.01) ||
		// // 	(fabs(intersecx - b.x) < 0.01 && fabs(intersecy - b.y) < 0.01) ||
		// // 	(fabs(intersecx - c.x) < 0.01 && fabs(intersecy - c.y) < 0.01) ||
		// // 	(fabs(intersecx - d.x) < 0.01 && fabs(intersecy - d.y) < 0.01)) {
		// // 	cout << "POINT " << intersecx << ' ' << intersecy << '\n';
		// // 	continue;	
		// // }

		// cout << "NONE\n";
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

inline int ccw(const Point& a, const Point& b, const Point& c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

istream& operator>>(istream& is, Point& p) {
	is >> p.x >> p.y;
	return is;
}