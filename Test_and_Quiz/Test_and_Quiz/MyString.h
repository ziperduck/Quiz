#pragma once
#include <iostream>
class AAAAA {
public:
	AAAAA() {
		name = new char[5];
		name[0] = 'a';
		name[4] = '\0';
	}
	~AAAAA() {
		delete[] name;
	}
private:
	char* name;
};

class MyString {


public:
	MyString();
	MyString(const char c);
	MyString(const char* pc);
	MyString(const MyString& my) {
		code = 1;
		Len = my.Len;
		String= new char[Len];
		String[0] = 'T';
		String[1] = '\0';

		std::cout << "복사 생성자 호출" << std::endl;
		throw String;
	}
	MyString(MyString&& my) : Len(my.Len), String(my.String) {
		my.String = nullptr;
		std::cout << "이동 생성자 호출" << std::endl;
	}

	~MyString();

	void add_String( const char* pc);
	int find_String(const char* pc) const;
	bool same_String( const char* pc) const;
	int size_comparison_String(const char* pc) const;

	int get_Size() const;
	
	void printer_String();

private:
	int code;
	char* String;
	int Len;
};
