#include "connect.h"

int A::connect() {return 1;}

int send(A& a) {
	return a.connect();
}

