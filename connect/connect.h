class A {
public:
	virtual int connect();
	virtual ~A();
};

int send(A& a);