// Exercise 12.14
// Write your own version of a function that uses a shared_ptr to manage a connection.
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

void end_connection(connection *con) {
	disconnect(*con);
}

void f(destination &des) {
	cout << "Entering f()...\n" ;
	connection c = connect(&des);
	shared_ptr<connection> p(&c, end_connection);
}

int main() {
	destination des("123.456.789.00");
	f(des);
	return 0;
}