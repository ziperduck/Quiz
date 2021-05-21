#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <array>
#include <map>
#include <cctype>
#include <stdexcept>
#include <memory>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <initializer_list>
#include <type_traits>
#include <regex>
#include <random>
#include <iomanip>
#include <ctime>
#include <filesystem>
#include <optional>
#include <variant>
#include <tuple>
#include <queue>
#include <stack>


//local time는 위험하기때문에 warning을 뿝는다. 그래서 이걸사용하면 경고가 안나온다.
//filesystem에서 warning이 터진다.
#pragma warning(disable : 4996)

class TestClass {
public :
	static int public_static_val;
	static int public_static_fun() { return 0; }

	void printthis();

	TestClass& Reference_rturn();
private:
	int num = 0;
	static int pri_static_val;
	static int pri_static_fun() { return 0; }
};

class Int {
	int num;

public:
	Int(int n) : num(n) {}

	operator int() {
		return num;
	}

};

class Duble_Increase {
	int num;

public:
	Duble_Increase(int n) : num(n){}
	Duble_Increase(const Duble_Increase& cd) : num(cd.num) {}

	Duble_Increase& operator++() { 
		++num;
		printf("전위 연산자\n");
		return *this;
	}
	Duble_Increase operator++(int) {
		Duble_Increase temp(*this);
		printf("후위 연산자\n");
		num++;
		return temp;
	}
};

void Test_WrapperOperator();


class InfiniteArray{
	
	//무한 배열의 배열
	int* Array;
	//리턴하는 배열
	int* Array_Point;
	//배열사이의 폭
	int* Array_Width;

	//첨자들의 배열
	const int* Subscripts_Array;
	//첨자 위치
	int Subscripts_Point;


public:
	/*
	문제들

	인트값을 어떻게 리턴할것인가?
	배열이 몇번호출되었는지 확인할것인가?

	*/


	InfiniteArray(int* Arr,const int ArrSize) : Subscripts_Array(Arr),Subscripts_Point(0){

		//무한 배열의 N배열 사이즈
		if (ArrSize == 0) return;

		Array_Width = new int[ArrSize];
		Array_Width[ArrSize - 1] = 1;
		
		for (int i = ArrSize - 2; i >= 0; i--){
			Array_Width[i] = Arr[i + 1] * Array_Width[i + 1];
		}
		Array = new int[Array_Width[0] * Arr[0]];
		for (int i = 0; i < Array_Width[0] * Arr[0]; i++)
		{
			Array[i] = i;
		}
		Array_Point = Array;
	}
	~InfiniteArray() {
		delete[](Array);
	}

	InfiniteArray& operator[](int num) {
		printf("In to operator[]\n");
		if (num >= Subscripts_Array[Subscripts_Point])
			return *this;
		Array_Point += Array_Width[Subscripts_Point] * num;
		
		Subscripts_Point++;
		return *this; 
	}

	const int& operator=(int num) {
		*Array_Point = num;
		return *Array_Point;
	}

	operator int*() const {
		printf("pointer int\n");
		return Array_Point;
	}


	void Reest_Array_Position() {
		Subscripts_Point = 0;
		Array_Point = Array;
	}
};

std::ostream& operator<<(std::ostream& os, const InfiniteArray& Arr) {
	os << *Arr;
	return os;
}


//따로 아래에서부터 위로 메모리해체함수를 만들어야하는이유
class RecursiveDestructor {
	struct RecursiveArray {
		void* Array;
		int num;
		~RecursiveArray() {
			printf("Array Count %d\n", Array);
			delete[](Array);
		}
	};


	RecursiveDestructor() {
		Recursive_Count = 3;
		RecursiveFunction(Recursive);
	}

	RecursiveArray* Recursive;

	int Recursive_Count;

	void RecursiveFunction(RecursiveArray* ReArray) {
		if (Recursive_Count == 0) {
			return;
		}
		ReArray->num = Recursive_Count;
		ReArray->Array = new RecursiveArray[Recursive_Count];
		--Recursive_Count;
		RecursiveFunction(static_cast<RecursiveArray*>(ReArray->Array));
	}

};

class Base {
	std::string num;
public:
	Base() : num("기본"){
		printf("Base class constructor %s \n", num.c_str());
	};

	virtual void what() { std::cout << num << std::endl; }
};
class Derived : public Base {
	std::string num;
public:
	Derived() : Base(),num("파생") {
		printf("Derived class constructor %s \n",num.c_str());
	};

	void what() override { std::cout << num << std::endl; }
};


template<typename Cont,typename Comp>
void bubble_sort(Cont& cont, Comp& comp) {
	for (int i = 0; i < cont.size(); i++)
	{
		for (int k = i+1; k < cont.size(); k++)
		{
			if (!comp(cont[i], cont[k])) {
				int num = cont[i];
				cont[i] = cont[k];
				cont[k] = num;
			}
		}
	}
}

class Comp1{
public:
	bool operator()(int i, int k) { return i < k; }
};
class Comp2 {
public:
	bool operator()(int i, int k) { return i > k; }
};

template<typename T>
std::string StrCat (T& String){
	return std::string(String);
};

template<typename T, typename... Ts>
std::string StrCat(T& String,Ts... Strings) {
	std::cout << sizeof...(Strings) << std::endl;
	return std::string(String) + StrCat(Strings...);
};

template<typename... Ts>
int AddNumber(Ts... addNum) {
	//std::cout << addNum << std::endl;
	//std::cout << addNum... << std::endl;
	//신텍스 에러가 뜬다. 내가 c++버전이 낮은가보다.
	//return (... + addNum);
	return 0;
}

template<int N>
struct Tem_Int {
public:
	static const int Num = N;
};

template<int T>
struct Factorial {
	static const int result = T * Factorial<T - 1>::result;
};

template<>
struct Factorial<1> {
	static const int result = 1;
};

template<int N, int D>
struct _gcd {
	static const int result = _gcd<D, N%D>::result;
};

template<int N>
struct _gcd<N,0> {
	static const int result = N;
};

template<int N, int D>
struct Ratio {
	typedef _gcd<N, D> type;
	static const int Num = N;
	static const int Den = D;
};

template<class R1, class R2>
struct _Ratio_Add {
	typedef Ratio<R1::Num*R2::Den + R2::Num*R1::Den, R1::Den*R2::Den> type;
};

template<class R1, class R2>
struct Ratio_Add : _Ratio_Add<R1,R2>::type{};

template<int C>
struct Fibonacci {
	static const int result = Fibonacci<C-1>::result +Fibonacci<C-2>::result;
};

template<>
struct Fibonacci<0> {
	static const int result = 0;
};

template<>
struct Fibonacci<1> {
	static const int result = 1;
};


template<int N>
struct TEST_INT {
	static const int Num = N;
};

template<int N,int D>
struct Test_Pr {
	static const int Num = N;
};
//template<int N>
//struct Test_Pr<N,TEST_INT<5>::Num> {
//	static const int Num = N;
//};

#if false

template<int N>
struct INT {
	static const int Num = N ;
};

template<int N,int D>
struct div {
	typedef INT<N/D> result;
};

template<int N>
struct check_div<N, typename div<N, 2>::result> {
	static const bool result = (N % (N / 2) == 0);
};

template<int N,typename D>
struct check_div {
	static const bool result 
		= (N%D::Num == 0)|| check_div<N,INT<D::Num+1>>::result;
};

template<>
struct _is_prime<2> {
	static const bool result = true;
};

template<>
struct _is_prime<3> {
	static const bool result = true;
};

template<int N>
struct _is_prime {
	static const bool result = !check_div<N, INT<2>>::result;
};

#endif // false

class OnePunchMan_Character{
	int Lnak;
	std::string name;
public:
	OnePunchMan_Character(int lank, std::string name) : Lnak(lank),name(name) {}
	
	bool operator<(const OnePunchMan_Character& oc) const{
		if (Lnak == oc.Lnak)
		{
			return name < oc.name;
		}
		return Lnak < oc.Lnak;
	}

	friend std::ostream& operator<<(std::ostream& os, const OnePunchMan_Character & ch);
};

std::ostream& operator<<(std::ostream& os, const OnePunchMan_Character & ch) {
	
	os << "[ Lank : " << ch.Lnak << " ]" <<"\n"
		<< "[ Name : " << ch.name<< " ]" << std::endl;
	return os;
}

template<typename A>
void Print_Vector(const std::vector<A>& m) {

	for (const auto& i : m)
	{
		std::cout << i << std::endl;
	}

}

template<typename A, typename B>
void Print_Map(const std::map<A, B>& m) {

	for (const auto& i : m)
	{
		std::cout << i.first<< std::endl;
		std::cout << i.second << std::endl;
	}

}
template<typename A, typename B>
void Print_MultiMap(const std::multimap<A, B>& m) {

	for (const auto& i : m)
	{
		std::cout << i.first << std::endl;
		std::cout << i.second << std::endl;
	}

}

struct is_string_a {
	bool operator()(const std::string& s) { return s.at(0) == 'a'; }
};

struct from_resize {
	const std::string operator()(std::string& s) { s.at(0) += 1; return s; };
};

class my_traits : public std::char_traits<char> {
public:

	static int get_real_rank(char c) {
		if (isdigit(c)) {
			return c + 256;
		}
		return c;
	}
	static bool lt(char _Left, char _Right) {
		return get_real_rank(_Left) < get_real_rank(_Right);
	}
	static int compare(const char* s1, const char* s2, size_t n) {
		while (n-- != 0) {
			if (get_real_rank(*s1) < get_real_rank(*s2)) {
				return -1;
			}
			if (get_real_rank(*s1) > get_real_rank(*s2)) {
				return 1;
			}
			++s1;
			++s2;
		}
		return 0;
	}
		
};

template<typename T>
class MyVector {
public:

	MyVector(std::size_t sz) : size(sz) {
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = 3;
		}
	}

	const T at(const int index) {
		if (index > size)
		{
			throw std::out_of_range("My Vector에서 버그가 났습니다.");
		}
		return data[index];
	}

private:
	T* data;
	std::size_t size;
};
class Emply_Class{};

template<typename T>
void Check_Nomal_T(T t) {
	Reference_Check(t);
}

template<typename T>
void Check_Left_T(T&& t) {
	Reference_Check(t);
}

void Reference_Check(Emply_Class&) { std::cout << "좌측값 레퍼런스 호출" << std::endl; }
void Reference_Check(const Emply_Class&) { std::cout << "좌측값 상수 레퍼런스 호출" << std::endl; }
void Reference_Check(Emply_Class&&) { std::cout << "우측값 레퍼런스 호출" << std::endl; }

class Enable_Sh : public std::enable_shared_from_this<Enable_Sh> {
public:

	Enable_Sh()
	{
		data = 5;
		std::cout << "기본 생성자" << std::endl;
	}
	Enable_Sh(Enable_Sh* sh)
	{
		data = 1;
		std::cout << "포인터 복사 생성자" << std::endl;
	}
	~Enable_Sh()
	{
		std::cout << "기본 소멸자" << std::endl;
	}

	std::shared_ptr<Enable_Sh> getShared() {
		return shared_from_this();
	}

	int data;
};


class Basic
{
public:
	Basic();
	Basic(int num);
	Basic(Basic* bs);
	Basic(const Basic&);
	Basic(Basic&&);
	~Basic();

	int getnum();

	void operator=(Basic&);

	int public_int;
private:
	int num;
};

Basic::Basic() : num(0), public_int(0)
{
	std::cout << "기본 생성자" << std::endl;
}
Basic::Basic(int num) : num(num), public_int(num) {
	std::cout << "인자 생성자" << std::endl;
}
Basic::Basic(Basic* bs) : num(bs->num), public_int(bs->public_int)
{
	std::cout << "포인터 복사 생성자" << std::endl;
}
Basic::Basic(const Basic& bs) : num(bs.num), public_int(bs.public_int)
{
	std::cout << "복사 생성자" << std::endl;
}
Basic::Basic(Basic&& bs) : num(bs.num), public_int(bs.public_int)
{
	std::cout << "이동 생성자" << std::endl;
}

Basic::~Basic()
{
	std::cout << "소멸자" << std::endl;
}

int Basic::getnum() {
	return num;
}

void Basic::operator=(Basic& bs) {
	num = bs.num;
	public_int = bs.public_int;
	std::cout << "대입연산자" << std::endl;
}

namespace Initializer {
	class only_const {
	public:
		only_const()
		{
			std::cout << "nomal const" << std::endl;
		}
		only_const(int, float)
		{
			std::cout << "int float const" << std::endl;
		}
		only_const(std::string) 
		{
			std::cout << "std::string const" << std::endl;
		}
		only_const(std::initializer_list<int>) 
		{
			std::cout << "std::initializer const" << std::endl;
		}
	};
}

template <typename T>
decltype(std::declval<T>().getnum()) tem_declfun(T& t) {
	return t.getnum();
}
template< typename T,
	typename = typename std::enable_if<std::is_integral<T>::value>::type>
void Test_Template_Enable(const T& t) {
	std::cout << "t : " << t << std::endl;
}