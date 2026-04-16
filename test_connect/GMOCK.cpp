#include "connect.h"
#include <gmock/gmock.h>

class MockA: public A {
public:
	MOCK_METHOD(int, connect, (), (override));
};

TEST(connect, send) {
	MockA a;
	EXPECT_CALL(a, connect());
	send(a);
}