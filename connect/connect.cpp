#include "connect.h"

A::~A() {};

int A::connect() {return 1;}

int send(A& a) {
	return a.connect();
}