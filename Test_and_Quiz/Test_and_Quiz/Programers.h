#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
#include <cctype>
#include <climits>
#include <cmath>
#include <functional>
using  std::vector;

vector<int> pull_two_number();
vector<int> pull_two_number2();

int kakaojorudy();

std::string Marathon();

void Mock_Test();

void Programers_Update();

void Fine_Rectangle();

void One_Two_Four();

void catch_phone_num();

void triangle_snail();

void joy_stick();

void Seconds_prices();

void Disguise();

void Priority_Printer();

void Min_Number();

void K_Sequence();

void prime_num();

void lost_training_clothes();

void RecommendNewId();

void Rebers_Base3();

void Remove_Sort();

void Mind_Sort();

void P_Y_Count();

void PhoneCatMon();

void descending();

void inner_product();

void partial_sum();

void company_budget();

void control_string();

void find_kim();

void minun_lottor();

void keypad();

void CaesarPassword();

void MakeStrangeLetters();

void DigitSum();

void Ascending();

void FailureRate();

void Test_stlMap();

void Common_Number();

void DivisorCound();

void Hidden_Phonenumber();

void SecretMap();

void SequenceNumber();

void MatricAddcation();

void DartGame();

void MoreSpicy();

void FibonacciRemainder();

typedef vector<vector<long long>> matrix;

matrix operator* (matrix &a, matrix &b);

long long fibonacci(int n);

void FibonacciRemainderMatrix();

void CompressionString();
namespace SmartPointer {

class Parent {
public:
	Parent(int Num) : num(Num) {};
	virtual ~Parent() = 0 {};
	virtual int GetNum() = 0;

protected:
	int num = 0;
};
class Child1 :public Parent {
public:
	Child1() :Parent(1){};
	virtual ~Child1() override{};
	virtual int GetNum() override;

};
class Child2 :public Parent {
public:
	Child2() :Parent(2) {};
	virtual ~Child2() override {};
	virtual int GetNum() override;

};

class ChildManager
{
public:
	ChildManager(){}
	~ChildManager(){}

	static std::shared_ptr<Parent> GetOne() {
		static std::shared_ptr<Parent> One = std::make_shared<Child1>();
		return One;
	}
	static std::shared_ptr<Parent> GetTwo() {
		static std::shared_ptr<Parent> Two = std::make_shared<Child2>();
		return Two;
	}
private:

};

void SmartPointTest();
}
namespace SingleTon {
	class Single {
	public:
		static Single* GetInstnace();

		void UpNum();

		void PrintNum();
	private:
		Single(): num(0){}

		int num;
	};

	void SingleTonTest1();
	void SingleTonTest2();
}