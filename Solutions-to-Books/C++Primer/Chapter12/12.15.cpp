// Exercise 12.15
// Rewrite the first exercise to use a lambda (10.3.2, p.388) in place of the end_connection function.
// Mostly copied from 12.14.cpp
// Xiaoyan Wang 8/3/2016
#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct destination {
	destination(string s = ""):value(s) { }
	string value;
};

struct connection {
	connection(destination *des = nullptr) {
		if(des)
			port = new destination*(des);
	}
	destination** port;
};

connection connect(destination *des) {
	cout << "c is connected to " << des->value << ".\n";
	return connection(des);
}

void disconnect(connection con) {
	cout << "c is disconnected from " << (*con.port)->value << ".\n";
	delete con.port;
}


void f(destination &des) {
	cout << "Entering f()...\n" ;
	connection c = connect(&des);
	shared_ptr<connection> p(&c, [](connection *con){disconnect(*con);});
}

int main() {
	destination des("123.456.789.00");
	f(des);
	return 0;
}