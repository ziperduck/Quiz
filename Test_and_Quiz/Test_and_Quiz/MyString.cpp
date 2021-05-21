#include "MyString.h"

MyString::MyString() : String(NULL),Len(0){
}
MyString::MyString(const char c){
	Len = 1;
	String = new char[Len+1];
	String[0] = c;
	String[1] = '\0';
}
MyString::MyString(const char* pc){
	code = 0;

	for (Len = 0; pc[Len] != '\0'; Len++);
	
	String = new char[Len + 1];

	for (int i = 0; i < Len; i++)
		String[i] = pc[i];
	String[Len] = '\0';

}
MyString::~MyString() {

	std::cout <<"code" << code << "소멸자 호출" << std::endl;
	if (String) {
		printer_String();
		std::cout << "String 제거" << std::endl;
		delete[] String;
	}
}

void MyString::add_String(const char* pc){
	
	const char* After_String = String;
	
	int pc_Len = 0;
	for (; pc[pc_Len] != '\0'; pc_Len++);

	int All_String_Len = Len + pc_Len; 
	
	String = new char[All_String_Len + 1];
	for (int i = 0; After_String[i] != '\0'; i++)
		String[i] = After_String[i];

	
	for (int i = 0; i<pc_Len; i++)
		String[i+Len] = pc[i];
	String[All_String_Len] = '\0';

	delete[] After_String;
}
int MyString::find_String(const char* pc) const{
	int point_find = -1;	
	bool is_same = false;
	int k = 0;

	for (int i = 0; i < Len; i++) {
		if (String[i] == pc[k]) {
			point_find = i;
			k++;
		}
		else if (pc[k] == '\0')
			is_same = true;
		else {
			point_find = -1;
			k = 0;
		}
	}
	return point_find;
}
bool MyString::same_String(const char* pc) const {
	bool is_same = false;
	int k = 0;

	for (int i = 0; i < Len; i++) {
		if (String[i] == pc[k])
			k++;
		else if (pc[k] == '\0') 
			is_same = true;
		else 
			k = 0;
	}
	return is_same;
}
int  MyString::size_comparison_String(const char* pc) const { 

	int pc_Len = 0;
	for (pc_Len = 0; pc[pc_Len] != '\0'; pc_Len++);

	int is_Comparison = 0;
	if (Len < pc_Len)
	{
		is_Comparison = -1;
	}
	else if (Len > pc_Len) 
	{
		is_Comparison = 1;
	}
	else
	{
		is_Comparison = 0;
	}

	return is_Comparison;

}

int MyString::get_Size() const{ return Len; }

void MyString::printer_String() {
	printf("%s\n", String);
}
