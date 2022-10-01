#include "FStreamAdaptor.h"
#include <iostream>

int main() {

	FStreamAdaptor fStreamAdaptor("test.txt");
	//std::cout << fStreamAdaptor.read();
	std::string test1 = fStreamAdaptor.read();
	std::string test2 = fStreamAdaptor.read();
	bool test5 = fStreamAdaptor.write("ABCD4");
	std::string test3 = fStreamAdaptor.read();
	std::string test4 = fStreamAdaptor.read();

	return 0;
}