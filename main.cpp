#include <iostream>
#include "Class.h"

#define MAX 3

using namespace std;

int main()
{
	Context* context = new Context(new Bus_Traffic(1, "name", 20, 100, 2, 11));
	cout << "First strategy" << endl;
	context->DoSomeBusinessLogic();
	context->set_strategy(new Freight_Transportation(2, "Oleg", 3, 45, 41, 12));
	cout << "Second strategy" << endl;
	context->DoSomeBusinessLogic();
	delete context;
}


