// Xiaoyan Wang 10/21/2016
#include <iostream>
#include <vector>
#include <cmath> // for std::fabs()
#include <algorithm> // for std::sort()
#include <iomanip> // for std::setprecision()
using namespace std;


struct Point {
	int x;
	int y;
	Point() = default;
	Point(const int& x_, const int& y_): x(x_), y(y_) { }
	Point(istream& is) {
		is >> x >> y;
	}
};

istream& operator>>(istream& is, Point& p);
bool operator<(const Point& a, const Point& b);
int ccw(const Point& a, const Point& b, const Point& c);
double find_area(const vector<Point>& pvec);

void printvec(const vector<Point>& pvec); // DEBUG

int main() {
	ios::sync_with_stdio(false);
	int N, tileNo = 0;
	cout << fixed << setprecision(2);
	while(cin >> N && N) {
		vector<Point> points;
		points.reserve(N+1);
		points.emplace_back(cin);
		int begnode = 0, begx = points[0].x, begy = points[0].y;
		for(int i = 1; i < N; ++i) {
			points.emplace_back(cin);
			if(points[i].x < begx || (points[i].x == begx && points[i].y < begy)) {
				begnode = i;
				begx = points[i].x;
				begy = points[i].y;
			}
		}
		points.push_back(points[0]);

		double ori_size = find_area(points);
		points.pop_back();
		for(Point& p : points) {
			p.x -= begx;
			p.y -= begy;
		}
		sort(points.begin(), points.end());
		points.push_back(points[0]);
		// printvec(points);
		vector<Point> cpoints;
		cpoints.reserve(N+1);

		cpoints.push_back(points[0]);
		cpoints.push_back(points[1]);
		for(int i = 2; i <= N; ++i) {
			int last = cpoints.size() - 1;
			while(ccw(cpoints[last - 1], cpoints[last], points[i]) < 0) {
				cpoints.pop_back();
				if(!--last)
					break;
			}
			cpoints.push_back(points[i]);
		}
		// printvec(cpoints);
		// // checking the last node
		// int last = cpoints.size() - 1;
		// while(ccw(cpoints[last - 1], cpoints[last], cpoints[0]) <= 0) {
		// 	cpoints.pop_back();
		// 	if(!--last)
		// 		break;
		// }
		// cpoints.push_back(cpoints[0]);
		double new_size = find_area(cpoints);
		// cout << "original size = " << ori_size << ", new size = "
		// 	<< new_size << ".\n";

		cout << "Tile #" << ++tileNo << "\nWasted Space = "
			<< (new_size - ori_size) * 100 / new_size << " %\n\n";
	}
	cout << flush;
	return 0;
}

void printvec(const vector<Point>& pvec) {
	for(const auto& p : pvec)
		cout << p.x << ' ' << p.y << '\n';
	cout << endl;
}

inline int ccw(const Point& a, const Point& b, const Point& c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

istream& operator>>(istream& is, Point& p) {
	is >> p.x >> p.y;
	return is;
}

bool operator<(const Point& a, const Point& b) {
	// a.y/a.x < b.y/b.x
	// if(a.y * b.x == b.y * a.x) {
	// 	if(a.x == b.x)
	// 		return a.y > b.y;
	// 	if(a.y == b.y)
	// 		return a.x < b.x;
	// 	return a.x > b.x;
	// }
	if(a.x == 0 && b.x == 0)
		return a.y > b.y;
	if(a.x == 0)
		return true;
	if(b.x == 0)
		return false;
	if(a.y * b.x == b.y * a.x) {
		if(a.y == b.y)
			return a.x < b.x;
		return a.x > b.x;
	}

	return a.y * b.x < b.y * a.x;
}

inline double find_area(const vector<Point>& pvec) {
	int result = 0;
	for(int i = 0; i < pvec.size() - 1; ++i)
		result += pvec[i].x * pvec[i+1].y - pvec[i].y * pvec[i+1].x;
	return fabs(result)/2;
}