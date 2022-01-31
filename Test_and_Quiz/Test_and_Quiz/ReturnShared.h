#pragma once
#include <cstdio>
#include <memory>

class OneShared
{
public:
	OneShared(int One) : One(One) {};
	~OneShared() {};

	void printone() const { printf("One %d\n", One); };

private:
	const int One;
};

class TwoShared
{
public:
	TwoShared() {};
	~TwoShared() {};

	void printtwo() const { printf("Two %d\n", Two); };
private:
	int Two = 2;
};

class SharedClass {
public:
	SharedClass(const OneShared* One, const TwoShared* Two) :one(One),two(Two){};
	~SharedClass() {};

	void printnum() { one->printone(); two->printtwo(); };

private:

	const OneShared* one;

	const TwoShared* two;

};

std::shared_ptr<SharedClass> GetShared_ptr();

void TestReturnMakeShared();