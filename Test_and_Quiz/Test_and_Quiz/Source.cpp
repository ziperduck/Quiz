#include <iostream>
#include <fstream>
#include "MyThreadPool.h"
#include "Header.h"
#include "MyString.h"
#include "MyComplex.h"
#include "MyExcel.h"
#include "Programers.h"
#include "ReturnShared.h"
#include "TestProject.h"
#include "TestTemplate.h"

int TestClass::public_static_val = 0;
int TestClass::pri_static_val = 0;

void TestClass::printthis() {
	printf("this = %p\n", this);
	printf("*this = %d\n", *this);
	printf("&public_static_val  = %p\n", &public_static_val);
	printf("public_static_val  = %d\n", public_static_val);

}
TestClass& TestClass::Reference_rturn() {
	printf("Reference Return %d\n", num);
	num++;
	return *this;
}

void version_check() {
	if (__cplusplus == 201703L) std::cout << "C++17\n";

	else if (__cplusplus == 201402L) std::cout << "C++14\n";

	else if (__cplusplus == 201103L) std::cout << "C++11\n";

	else if (__cplusplus == 199711L) std::cout << "C++98\n";

	else std::cout << "pre-standard C++\n";
}
enum PointEnum {A};

void Test_MyString_Fun() {

	MyString mys_c('5');
	MyString mys_s("Naver");

	printf("mys_c.size = %d\n mys_s.size = %d\n", mys_c.get_Size(), mys_s.get_Size());
	//문자열더하기
	mys_c.add_String("6789");
	mys_s.add_String("A");

	mys_c.printer_String();
	mys_s.printer_String();

	//문자열 찾기
	printf("mys_c find %d\n", mys_c.find_String("ver"));
	printf("mys_s find %d\n", mys_s.find_String("ADS"));

	//사이즈 비교
	printf("mys_c com \"88651\" or %d\n", mys_c.size_comparison_String("86651"));
	printf("mys_s com \"ABC\" or %d\n", mys_s.size_comparison_String("ABC"));

	mys_c.printer_String();
	mys_s.printer_String();

}

void Test_Point_And_Array() {

	int num[] = { 1,2,3,4,5 };
	char* name = "asdf";
	int* pnum = num;
	printf("배열의 포인터의 사이즈%d 배열의 사이즈%d\n", sizeof(&num), sizeof(num));
	printf("&num = %p, num = %p, &num[0] %p, &num[1] %p\n"
		,&num, num, &num[0], &num[1]);
	printf("&name = %p, name = %p, &name[0] %p, &name[1] %p\n"
		,&name, name, &name[0], &name[1]);
	printf("pnum = %p\n", pnum);
	
	int val = 0;
	int * pval = &val;
	int** ppval = &pval;
	printf("val = %p, *pval = %p, **ppval = %p\n", val, *pval, **ppval);
	printf("&val = %p, pval = %p, *ppval = %p\n", &val, pval, *ppval);
	printf("&val = %p, &pval = %p, &ppval = %p\n", &val, &pval, &ppval);
	printf("&*pval = %p, &**ppval = %p\n", &*ppval, &**ppval);
	printf("***&pval = %p, **&ppval = %p\n", ***&ppval, **&ppval);
}

void Test_Point_Of_Array() {
	/*
	배열은 첫번째 원소를 가리키는 포인터변수을 가지고있다.
	배열의 이름을 사용할경우에는 이 포인터 변수를 가지고온다.
	그러나 이 포인터 변수는 임시적인것인 우측값이다.
	그런데 왜 포인터 배열은 (*)를 붙여야하는 것이지?
	배열 포인터에 *를 붙일경우 포인터가 된다.
	배열 포인터는 배열의 값을 받을경우 배열과 동일하게 임시 포인터값을 만든다.

	Arr = int*
	*Arr = int
	&Arr = int(*)[]

	Parr = int(*)[]
	*Parr = int*
	&Parr = int(**)[]
	
	*/

	int Arr[5] = {1,2,3,4,5};
	int(*Parr)[5] = &Arr;

	printf("&Arr = %p, Arr = %p, &Arr[0] = %p\n",&Arr,Arr,&Arr[0] );
	printf("&Parr= %p, *Parr= %p, *Parr= %p, &(*Parr)[0] = %p\n"
		, &Parr,Parr, *Parr, &(*Parr)[0]);
	float* b;
}

void Test_Complex() {


	MyComplex a(1.0, 2.0);
	MyComplex b(3.0, -2.0);
	a += b;
	a.println();
	b.println();
}

void Test_WrapperOperator() {
	Int a = 5;
	int b = a + 7;
	printf("a = %d b = %d\n", a, b);
}
void Test_Duble_Increase() {

	Duble_Increase Di = 4;
	printf("Di++ = %d\n",Di++);
	printf("++Di = %d\n", ++Di);

}
void Test_infinite_Array() {
	int* _3Dimensional_Array = new int[3]{ 2,3,4 };
	InfiniteArray Arr = {_3Dimensional_Array,3};
	Arr[0][2][1] = 100;
	Arr.Reest_Array_Position();
	std::cout << "Arr = " << Arr[0][2][1] << std::endl;

}

void Class_TypeCast() {
	Base bs;
	Derived dv;

	Base* upcast = dynamic_cast<Base*>(&dv);
	Derived* downcast  = static_cast<Derived*>(&bs);
	


	downcast->what();
}

void test_stream() {
	fclose(stdout);
	printf("stdout");
}
void test_stream2() {
	char name[5];
	fgets(name, 5, stdin);
	printf("name is %s\n", name);
}

void test_filestream() {
	FILE* file;
	fopen_s(&file,"Text.txt", "r+");
	
	if (file == NULL) {
		printf("file is EOF\n");
		return;
	}
	char c;
	while ((c = fgetc(file)) != EOF) {
		if (65 <= c && c <= 90) {
			fseek(file, -1, SEEK_CUR);
			fputc(c + 32, file);
			fseek(file, 0, SEEK_CUR);
		}
		else if(97 <= c&& c <= 122) {
			fseek(file, -1, SEEK_CUR);
			fputc(c - 32, file);
			fseek(file, 0, SEEK_CUR);
		}

	}
	fclose(file);
}

void test_writebinaryfile() {
	std::ofstream by("binary.bin", std::ios::binary);

	if (by.is_open() == false) {
		return;
	}

	int bynum = 75;
	by.write((char*)(&bynum), sizeof(int));
	std::cout << bynum << std::endl;

}

void test_readbinaryfile() {
	std::ifstream by("binary.bin", std::ios::binary);
	
	if (by.is_open()== false) {
		return;
	}

	int bynum = 0;
	by.read((char*)(&bynum), sizeof(int));
	std::cout << bynum << std::endl;

	by.read((char*)(&bynum), sizeof(int));
	std::cout << bynum << std::endl;

	by.seekg(4, std::ios::beg);

	by.read((char*)(&bynum), sizeof(int));
	std::cout << bynum << std::endl;

}

void test_Stack() {
	MyStack mstack;
	mstack.pushi(1);
	mstack.pushi(2);
	printf("peek = %d\n", mstack.peek());
	mstack.pop();
	printf("peek = %d\n", mstack.peek());
	mstack.pushi(3);
	printf("peek = %d\n", mstack.peek());
	mstack.remove();
	printf("peek = %d\n", mstack.peek());

}

void Test_Intbit() {
	int num = 0;

	num |= 1 << 0;
	printf("num = %d\n", num);

	num |= 1 << 1;
	printf("num = %d\n", num);

	num |= 1 << 5;
	printf("num = %d\n", num);

}

void Test_Functor() {
	std::array<int,5> vi1 = { 3,1,2,5,4 };
	Comp1 c1;
	std::array<int, 5> vi2 = { 10,8,6,7,9};
	Comp2 c2;
	bubble_sort(vi1, c1);
	bubble_sort(vi2, c2);
	for (int i = 0; i < vi1.size(); i++) {
		printf("%d", vi1[i]);
	}
	printf("\n");
	for (int i = 0; i < vi2.size(); i++) {
		printf("%d", vi2[i]);
	}
	printf("\n");
}

void Test_StrCat() {
	std::string name = StrCat("kim", "J","in", "Hyoeng");
	std::cout << name << std::endl;
	std::cout << AddNumber(1, 2, 3, 4, 5, 6) << std::endl;
}
void Test_TemplateInt() {
	Tem_Int<1> num1;
	Tem_Int<1> num1_1;
	Tem_Int<2> num2;
	std::cout << typeid(num1).name() << std::endl;
	std::cout << typeid(num1_1).name() << std::endl;
	std::cout << typeid(num2).name() << std::endl;
	bool same_tem = typeid(num1_1) == typeid(num2);
	std::cout << same_tem << std::endl;
	same_tem = typeid(num1_1) == typeid(num1);
	std::cout << same_tem << std::endl;

	std::cout << "&num1 = " << &num1 << "&num1.Num = " << &num1.Num << std::endl;
	std::cout << "&num1_1 = " << &num1_1 << "&num1_1.Num = " << &num1_1.Num << std::endl;
	std::cout << "&num2 = " << &num2 << "&num2.Num = " << &num2.Num << std::endl;
	std::cout << "num1 = " << num1.Num << std::endl;
	std::cout << "num2 = " << num2.Num << std::endl;

}

int gcd(int a, int b) {
	if (b == 0) {
		std::cout << a << b << std::endl;
		return a;
	}
	std::cout << a << b << std::endl;
	return gcd(b, a % b);
}

void Test_Gcd() {
	gcd(20, 44);
	std::cout << std::endl;
	gcd(7, 12);

}

void Test_Factorial() {
	std::cout << "Factorial" << Factorial<5>::result << std::endl;
}


void Test_Ratio() {
	using r1 = Ratio<1, 2>;
	using r2 = Ratio<2, 3>;
	using ra = Ratio_Add<r1, r2>;
}

void Test_Fibonacci() {
	Fibonacci<7>::result;
}

void Test_Prime() {
	//_is_prime<10>::result;
}

void Test_Map() {
	using One_Char = OnePunchMan_Character;
	
	std::map<One_Char, std::string> SLank;
	SLank.insert(std::make_pair(One_Char(3, "실버팽"), "유수암살권"));
	SLank.insert(std::make_pair(One_Char(1, "블레스트"), "실종"));
	SLank.insert(std::make_pair(One_Char(7, "킹"), "킹부스터"));
	SLank.insert(std::make_pair(One_Char(4, "아토믹 사무라이"), "검술"));
	SLank.insert(std::make_pair(One_Char(2, "타츠마키"), "염동력"));
	SLank.insert(std::make_pair(One_Char(2, "타츠마키"), "염동력"));


	Print_Map(SLank);

	SLank.erase(One_Char(3, "실버팽"));
	SLank.erase(SLank.begin());
	SLank.insert(
		std::pair<One_Char,std::string>(One_Char(0, "사이타마"), "진심시리즈"));
	Print_Map(SLank);

}

void multy_map() {
	std::multimap<int, std::string> mm ;
	mm.insert(std::make_pair(2, "B"));
	mm.insert(std::make_pair(1, "A"));
	mm.insert(std::make_pair(3, "C"));
	mm.insert(std::make_pair(4, "D"));
	mm.insert(std::make_pair(4, "D"));
	mm.insert(std::make_pair(4, "E"));

	for (auto& i = mm.begin(); i != mm.end(); i++){
		std::cout << " " << i->first << " " << i->second << std::endl;
	}

	printf("\n");
	auto& a = mm.equal_range(4);
	for (auto& i = a.first; i != a.second; i++) {
		std::cout << " " << i->first << " " << i->second << std::endl;
	}

}

void Test_algorithm() {
	std::vector<std::string> m;
	m.push_back("ac");
	m.push_back("ee");
	m.push_back("bb");
	m.push_back("hh");
	m.push_back("ac");
	m.push_back("jh");
	m.push_back("tt");
	m.push_back("ac");

	//m.insert(std::make_pair(1,"ac"));
	//m.insert(std::make_pair(9,"ee"));
	//m.insert(std::make_pair(2,"bb"));
	//m.insert(std::make_pair(7,"dd"));
	//m.insert(std::make_pair(1,"aa"));
	//m.insert(std::make_pair(1,"ab"));

	[=]()->void{
		std::vector<std::string> temp = m;
		std::sort(temp.begin(), temp.end(),std::greater<std::string>());
		Print_Vector(temp);
		std::cout << std::endl;
	}();

	[=]()->void {
		std::vector<std::string> temp = m;
		std::partial_sort(temp.begin(), temp.begin() + 3, temp.end());
		Print_Vector(temp);
		std::cout << std::endl;
	}();

	[=]()->void {
		std::vector<std::string> temp = m;
		std::stable_sort(temp.begin(), temp.end());
		Print_Vector(temp);
		std::cout << std::endl;
	}();

	[=]()->void {
		std::vector<std::string> temp = m;
		temp.erase(std::remove(temp.begin(), temp.end(),"tt"),temp.end());
		Print_Vector(temp);
		std::cout << std::endl;
		temp.erase(std::remove_if(temp.begin(), temp.end(), is_string_a()), temp.end());
		Print_Vector(temp);
		std::cout << std::endl;
	}();

	[=]()->void {
		std::vector<std::string> temp = m;
		std::vector<std::string> bin_temp(temp.size(),"");
		std::transform(temp.begin(), temp.end(), bin_temp.begin(), from_resize());
		Print_Vector(bin_temp);
		std::cout << std::endl;
	}();

	[=]()->void {
		std::vector<std::string> temp = m;
		std::cout <<"vector in the a?"<< std::all_of(temp.begin(), temp.end(), 
			[](const std::string s) {return s.at(0) == 'a'; }) << std::endl;
		std::cout << "vector in the t?" << std::any_of(temp.begin(), temp.end(),
			[](const std::string s) {return s.at(0) == 't'; }) << std::endl;
		std::cout << std::endl;
	}();

}

void Test_DetailedString() {

	std::basic_string<char, my_traits> my_s1 = "1a";
	std::basic_string<char, my_traits> my_s2 = "a1";

	std::cout << "숫자의 우선순위가 더 낮은 문자열 : " << std::boolalpha
		<< (my_s1 < my_s2) << std::endl;

	std::string s1 = "1a";
	std::string s2 = "a1";

	std::cout << "일반 문자열 : " << std::boolalpha << (s1 < s2) << std::endl;

	std::string Rs = R"foo(
이런식으로
사용할수있다
이걸쓰는 이유는 내가볼때
파싱용인것같다.
); 이거는 무시된다 ;가 있어서 쓸수있다
)foo"; 

	std::cout << Rs << std::endl;

}

void Test_Throw1() {

	MyString m1("asd");

	int&& a = 5;
	std::cout <<"&a = "<< &a << "a = " << a << std::endl;

	try
	{
		MyString m2(m1);
	}
	catch (const char* c)
	{
		std::cout << c << std::endl;
	}

}

void Test_Throw2() {

	MyVector<int> mv(3);
	try
	{
	mv.at(4);
	}
	catch (const std::out_of_range& oo)
	{
		std::cout <<oo.what() << std::endl;
	}
}

void Test_LeftReference(int&& n) {

}
void Test_Reference() {
	int a;
	int& r_a = a;
	//int&&& error
	typedef int&& left_int;
	left_int& lf_a = a;
	left_int&& lf_b = 5;

	Emply_Class e;
	const Emply_Class ce;

	if (1) {
		Emply_Class& Em_c = std::move(Emply_Class());
	}
	else {
		Emply_Class&& Em_c = std::move(e);
	}
	if (1) {
		Emply_Class a;
		Emply_Class&& b = std::forward<Emply_Class&&>(a);
	}
	
	Reference_Check(e);
	Reference_Check(ce);
	Reference_Check(Emply_Class());
	std::cout << "-----------------------" << std::endl;
	Check_Nomal_T(e);
	Check_Nomal_T(ce);
	Check_Nomal_T(Emply_Class());
	std::cout << "-----------------------" << std::endl;
	Check_Left_T(e);
	Check_Left_T(ce);
	Check_Left_T(Emply_Class());

}

void Test_refence_Destructor_vector() {
	Basic Left;
	std::cout << "Refence---------" << std::endl;

	[](Basic&)->void {
		std::cout << "Left call" << std::endl;
	}(Left);
	std::cout << "----------------" << std::endl;

	[](Basic*)->void {
		std::cout << "Point call" << std::endl;
	}(&Left);
	std::cout << "----------------" << std::endl;

	[](Basic&&)->void {
		std::cout << "Right call" << std::endl;
	}(Basic());
	std::cout << "end-------------" << std::endl;

	std::cout << "vector----------"<< std::endl;
	std::vector<Basic> bs;
	std::cout << "----------------" << std::endl;
	bs.resize(0);
	bs.push_back(Left);
	std::cout << "----------------" << std::endl;
	bs.push_back(Basic());
	std::cout << "emplace_back----"<< std::endl;
	bs.emplace_back(Basic());
	std::cout << "end-------------" << std::endl;
}

void Test_Unique_ptr() {
	std::unique_ptr<Basic> un = std::make_unique<Basic>();
	std::cout << "----------------" << std::endl;
	//std::unique_ptr<Basic> themp = un; error
	//themp = un; error
	std::unique_ptr<Basic> themp = std::move(un);
	std::cout << "----------------" << std::endl;
	std::vector<std::unique_ptr<Basic>> vu;
	std::cout << "----------------" << std::endl;
	//
	//vu.push_back(new Basic()); error
	vu.emplace_back(new Basic());
	std::cout << "----------------" << std::endl;

}

void Test_Shared() {
	std::shared_ptr<Basic> sh = std::make_shared<Basic>();
	std::cout << "sh count = " << sh.use_count() << std::endl;
	std::shared_ptr<Basic> copy_sh = sh;
	std::cout << "copty_sh = sh " << std::endl;
	std::cout << "sh count = " << sh.use_count() << std::endl;
	std::cout << "copy_sh count = " << sh.use_count() << std::endl;
	std::cout << "-------------------------" << std::endl;

	//Basic* ba = new Basic;
	//std::shared_ptr<Basic> sb1 = std::make_shared<Basic>(ba);
	//std::shared_ptr<Basic> sb2 = std::make_shared<Basic>(ba);
	//std::cout << "sb1 count = " << sb1.use_count() << std::endl;
	//std::cout << "sb2 count = " << sb2.use_count() << std::endl;
	/*
	en이 count값이 상승하지 않는다.
	*/
	Enable_Sh* en = new Enable_Sh;
	std::shared_ptr<Enable_Sh> se1 = std::make_shared<Enable_Sh>(en);
	std::shared_ptr<Enable_Sh> se2 = std::make_shared<Enable_Sh>(en);
	std::shared_ptr<Enable_Sh> se3 = se2->getShared();
	//se1은 증가하지 않음
	std::cout << "se1 count = " << se1.use_count() << std::endl;
	std::cout << "se2 count = " << se2.use_count() << std::endl;
	std::cout << "se3 count = " << se3.use_count() << std::endl;

}
void Get_Weard(std::shared_ptr<Basic> sh) {
	std::cout << "sh count = " << sh.use_count() << std::endl;
	std::weak_ptr<Basic> wp = sh;
	std::cout << "wp count = " << wp.use_count() << std::endl;
}
void Test_Weard() {
	std::shared_ptr<Basic> sh = std::make_shared<Basic>();
	std::cout << "sh count = " << sh.use_count() << std::endl;
	std::shared_ptr<Basic> copy = sh;
	std::cout << "sh count = " << sh.use_count() << std::endl;
	Get_Weard(sh);
	std::cout << "sh count = " << sh.use_count() << std::endl;
}

void Basic_AddFun(Basic& bs, Basic& cbs) 
{ 
	bs.public_int = cbs.public_int + 2;
	cbs.public_int = bs.public_int + 3;
};

void Test_Function() {

	std::function<bool(const std::string&)> fn = is_string_a();
	std::cout << "fn = " << fn("asdaaa") << std::endl;
	std::cout << "-------------------------" << std::endl;

	Basic bs(5),cbs(2);
	std::function<int(Basic&)> mfr = &Basic::getnum;
	std::cout << "mfr = " << mfr(bs) << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::function<int(Basic const&)> mvr = &Basic::public_int;
	bs.public_int = 7;
	std::cout << "mvr = "<< mvr(bs) << std::endl;
	std::cout << "-------------------------" << std::endl;

	
	std::function<int(Basic&)> memf = std::mem_fn(&Basic::getnum);
	std::cout << "memf = " << memf(Basic(2)) << std::endl;
	std::cout << "-------------------------" << std::endl;

	auto lamref = std::bind(Basic_AddFun, std::ref(bs),std::placeholders::_1);
	std::cout << "bs.public_int = " << bs.public_int << std::endl;
	std::cout << "cbs.public_int = " << cbs.public_int << std::endl;
	lamref(cbs);
	std::cout << "bs = " << bs.public_int << std::endl;
	std::cout << "cbs = " << cbs.public_int << std::endl;

	std::cout << "-------------------------" << std::endl;
}

void Test_Thread() {

	std::function<void(const int,int*)> addfun = [](const int start, int* num)
	{
		for (int i = start; i < start + 3; i++) {
			*num += i;
		}
		std::thread::id thread_id = std::this_thread::get_id();
		std::cout << "thread id" << thread_id << "result = " << *num << std::endl;
		printf("\n thread id %x result = %d\n",thread_id ,*num);
	};

	std::vector<int> result(3);
	std::vector<std::thread> thr(0);
	
	thr.push_back(std::thread(addfun, 0, &result.at(0)));
	thr.push_back(std::thread(addfun, 100, &result.at(1)));
	thr.push_back(std::thread(addfun, -4, &result.at(2)));

	if (true) {
		for (auto i = thr.begin(); i < thr.end(); i++)
		{
			i->join();
		}
	}
	else {
		for (auto i = thr.begin(); i < thr.end(); i++)
		{
			i->detach();
		}
	}

	int alladd = 0;
	for (auto i = result.begin(); i < result.end(); i++)
	{
		alladd += *i;
	}
	std::cout << "result add value = " << alladd << std::endl;

}
void Test_Mutex() {
	std::function<void(std::mutex& , int*,bool)> fn 
		= [](std::mutex& mu, int* num, bool check){
		if (check) {
			mu.lock();
		}

		for (int i = 0; i < 1000; i++) {
			*num += 1;
		}

		if (check) {
			mu.unlock();
		}

		std::thread::id thread_id = std::this_thread::get_id();
		printf("\n thread id %x result = %d\n", thread_id, *num);
	};

	std::mutex mu;
	int num = 0;

	std::vector<std::thread> vt;
	vt.push_back(std::thread(fn, std::ref(mu), &num, false));
	vt.push_back(std::thread(fn, std::ref(mu), &num, false));
	
	for (auto i = vt.begin(); i < vt.end(); i++){
		i->join();
	}
	printf("after join printf\n");
	vt.pop_back();
	vt.pop_back();
	
	std::cout << "total num = " << num << std::endl;
	printf("--------------------------\n");

	num = 0;
	vt.push_back(std::thread(fn, std::ref(mu), &num, true));
	vt.push_back(std::thread(fn, std::ref(mu), &num, true));

	for (auto i = vt.begin(); i < vt.end(); i++) {
		i->join();
	}
	
	std::cout << "total num = " << num << std::endl;
	printf("--------------------------\n");

}

void test_Atomic() {
	
	std::atomic<bool> ai(0);
	int num = 0;

	std::function<void(std::atomic<bool>&, int*)> producer
		= [](std::atomic<bool>& ai, int* num) {
		*num = 10;
		ai.store(true, std::memory_order_release);
	};

	std::function<void(std::atomic<bool>&, int*)> consumer
		= [](std::atomic<bool>& ai, int* num) {
		while (!ai.load(std::memory_order_acquire)) {
		}
		std::cout << "num = " << *num << std::endl;
	};

	std::vector<std::thread> vi;
	vi.push_back(std::thread(producer, std::ref(ai), &num));
	vi.push_back(std::thread(consumer, std::ref(ai), &num));

	for (auto& i = vi.begin(); i < vi.end(); i++){
		i->join();
	}
	
}

void Test_Nomal_Futuer() {

	std::function<void(std::promise<std::string>*)> fn 
		= [](std::promise<std::string>* p) {
		p->set_value("p->set_value");
	};

	std::promise<std::string> ps;

	std::future<std::string> ft = ps.get_future();

	std::thread th = std::thread(fn, &ps);

	ft.wait();

	std::cout << "ft = " << ft.get().c_str() << std::endl;

	th.join();
}

void Test_exception_Future() {

	std::function<void(std::promise<int>&)> fn = [](std::promise<int>& p ) {
		try {
			throw std::runtime_error("run time Error (;");
		}
		catch (...) {
			p.set_exception(std::current_exception());
		}
	};

	std::promise<int> pr;

	std::future<int> fu = pr.get_future();

	std::thread th = std::thread(fn, std::ref(pr));

	fu.wait();

	try {
		fu.get();
	}
	catch (const std::exception& ex) {
		std::cout << "exceptiont = " << ex.what() <<std::endl;
	}


	th.join();
}

void Test_wiat_for_future() {

	std::function<void(std::promise<void>&)> fn = [](std::promise<void>& p) {
		std::this_thread::sleep_for(std::chrono::seconds(10));
		p.set_value();
	};

	std::promise<void> pr;

	std::future<void> fu = pr.get_future();

	std::thread th = std::thread(fn, std::ref(pr));

	while (true)
	{
		std::future_status fs = fu.wait_for(std::chrono::seconds(1));
		if (fs == std::future_status::timeout) {
			std::cout << "<" << std::endl;
		}
		else if (fs == std::future_status::ready) {
			break;
		}

	}
	th.join();
}
void Test_packaged_task_futuer() {

	std::function<int(int)> fn = [](int x) {
		return 10 + x;
	};

	std::packaged_task<int(int)> pa(fn);

	std::future<int> fu = pa.get_future();

	std::thread th = std::thread(std::move(pa),10);

	std::cout <<"fu = "<< fu.get() << std::endl;

	th.join();

}

void Test_async_fun() {
	std::this_thread::sleep_for(std::chrono::seconds(5));
	printf("second 3\n");

}
void Test_async_future() {

	std::function<void()> fns = [=]() {
		Test_async_fun();
		Test_async_fun();
		Test_async_fun();
	};

	std::function<void()> asumc_fns = [=]() {
		auto asyn1 = std::async([]() {return Test_async_fun(); });
		auto asyn2 = std::async([]() {return Test_async_fun(); });
		auto asyn3 = std::async([]() {return Test_async_fun(); });
		asyn1.get();
		asyn2.get();
		asyn3.get();
	};

	printf("asumc_fns\n");
	asumc_fns();
	printf("\nfns\n");
	fns();

}
void Test_ThreadAssistance(int t, int id) {
	printf("%d start \n", id);
	std::this_thread::sleep_for(std::chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
}
int	 Test_ThreadTypenameAssistance(int t, int id) {
	printf("%d start \n", id);
	std::this_thread::sleep_for(std::chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
	return t + id;
}
void Test_ThreadPool() {
	if (false) {
		ThreadPool::ThreadPool th(3);

		for (size_t i = 0; i < 10; i++)
		{
			th.EnqueueJob([i]() {Test_ThreadAssistance(i % 3 + 1, i); });
		}
	}
	else {

		ThreadPool::ThreadPool pool(3);

		std::vector<std::future<int>> futures;
		for (int i = 0; i < 10; i++) {
			futures.emplace_back(pool.EnqueueJob(Test_ThreadTypenameAssistance, i % 3 + 1, i));
		}
		for (auto& f : futures) {
			printf("result : %d \n", f.get());
		}
	}

}


void Test_Initializer_List() {
	
	auto in{ 4 };
	auto ini = { 4,2 };
	
	//error
	//auto in{ 4,2 };

	Initializer::only_const a{};
	Initializer::only_const b{ 1,2 };
	Initializer::only_const d{ "string" };
	Initializer::only_const c( 1,2.5f );

}
void Test_constexpr() {
	int num;
	constexpr int a = 5;
	constexpr int b = a;

 }

auto decl_fun(int num,float fnum)->decltype(num+ fnum) {
	return num + fnum;
}

void Test_decltype(){
	const int coni = 5;
	decltype(coni) deconi= 4;
	auto aut = 4;

	int&& refnum = 5;
	decltype(refnum) derenum = 2;
	decltype(decl_fun(2, 0.5)) defl = 0.5;
	
	std::cout<< "Basic  = " <<tem_declfun(Basic())<<std::endl;
	
}
void Test_Enable() {
	Test_Template_Enable(5);
	Test_Template_Enable('c');
}

void Test_regex() {
	std::vector<std::string> re_ma = { "db-123-log.txt","db-12-log.txt",
		"not-db-log.txt", "db-12-log.jpg",
		"db-s13d-log.txt" ,"db-12-logatxt" };
	std::regex re("db-\\d*-log\\.txt");
	
	
	for (const auto& re_ma : re_ma)
	{
		std::cout << re_ma.c_str() << " : " << std::boolalpha << std::regex_match(re_ma, re) << std::endl;
	}

	std::vector<std::string> phone_numbers = { "010-1234-5678", "010-123-4567",
											  "011-1234-5567", "010-12345-6789",
											  "123-4567-8901", "010-1234-567" };
	
	printf("------------------------\n");

	re = "[01]{3}-\\d{3,4}-\\d{4}";

	for (const auto& phone_numbers : phone_numbers)
	{
		std::cout << phone_numbers.c_str() << " : "
			<< std::boolalpha << std::regex_match(phone_numbers, re) << std::endl;
	}

	printf("------------------------\n");

	re = "[01]{3}-(\\d{3,4})-\\d{4}";
	std::smatch sm;

	for (const auto& phone_numbers : phone_numbers) {
		if (std::regex_match(phone_numbers, sm, re)) {
			for (size_t i = 0; i < sm.size(); i++)
			{
				std::cout << "match : " << sm[i].str() << std::endl;
			}
			printf("------------------------\n");
		}
	}
	
	std::string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
  )";
	enum class html_kind : char { search ,iterator,replace};
	re = R"(<div class="sk[\w -]*">\w*</div>)";
	html_kind hk = html_kind::replace;
	switch (hk)
	{
	case html_kind::search: {

		printf("----------search-----------\n");
		while (std::regex_search(html, sm, re)) {
			std::cout << sm.str() << "\n";
			html = sm.suffix();
		}
			break;
	}
	case html_kind::iterator:
	{
		printf("----sregex_iterator----\n");
		auto start = std::sregex_iterator(html.begin(), html.end(), re);
		auto end = std::sregex_iterator();

		while (start != end) {
			std::cout << start->str() << std::endl;
			++start;
		}
		break;
	}
	case html_kind::replace: {
		re = R"r(sk-circle(\d))r";
		std::string modified_html = std::regex_replace(html, re, "$1-sk-circle");
		std::cout << modified_html <<std::endl;

	}
		break;
	default:
		break;
	}

	printf("------------------------\n");



}
void Test_random_chrono() {
	enum class random_chrono : char {
		uniform_dis, nomal_dis, timepoint, real_time
	};
	
	std::random_device rd;
	std::mt19937 mt(rd());
	
	switch (random_chrono::real_time)
	{
	case random_chrono::uniform_dis: {

		std::uniform_int_distribution<int> uid(0, 99);

		std::cout << "random : " << uid(mt) << std::endl;

		break;
	}
	case random_chrono::nomal_dis: {

		std::normal_distribution<double> nd(0, 1);
		std::map<int, int> mii{};
		for (size_t i = 0; i < 10000; ++i)
		{
			++mii[std::round(nd(mt))];
		}
		for (const auto& i : mii)
		{
			std::cout << std::setw(2) << i.first << ' '
				<< std::string(i.second / 100, '*') << " " << i.second << std::endl;
		}

		break;
	}

	case random_chrono::timepoint: {
		std::uniform_int_distribution<int> uid(0, 99);
		for (size_t i = 10; i < 1000000; i *= 10)
		{
			std::vector<int> vc;
			vc.reserve(i);

			std::chrono::time_point<std::chrono::high_resolution_clock> start
				= std::chrono::high_resolution_clock::now();
			for (size_t k = 0; k < i; k++)
			{
				vc.push_back(uid(mt));
			}

			std::chrono::time_point<std::chrono::high_resolution_clock> end
				= std::chrono::high_resolution_clock::now();

			auto diff = end - start;
			namespace ch = std::chrono;
			std::cout << "vc size = " << vc.size()
				<< " time = " << diff.count() << ", micro second" 
				<< ch::duration_cast<ch::microseconds>(diff).count()<< std::endl;

		}

		break;
	}
	case random_chrono::real_time: {
		auto now = std::chrono::system_clock::now();
		std::time_t t = std::chrono::system_clock::to_time_t(now);
		
		std::cout << "현재 시간 :" << std::put_time(std::localtime(&t), "%F %T %z")
			<< "\n";
		break;
	}
	default:

		break;
	}

}

void Curious_random_chrono() {
	std::random_device rd;
	std::mt19937 m(100);
	std::mt19937 mm(100);
	std::uniform_int_distribution<int> mi(0, 99);

	std::cout << "m random uniform : " << mi(m) << std::endl;
	std::cout << "m random uniform : " << mi(m) << std::endl;
	std::cout << "mm random uniform : " << mi(mm) << std::endl;
	std::cout << "mm random uniform : " << mi(mm) << std::endl;

}

void Test_FileSystem() {
	enum class file_system :char {
		filesystem,path,derectory, create_derectory, copy_derectory, remove_derectory
		,for_remove
	};
	std::filesystem::path pa("./some_file");
	switch (file_system::for_remove)
	{
	case file_system::filesystem: {
		std::cout << "Does" << pa << "exist? [" << std::boolalpha
			<< std::filesystem::exists(pa) << "]"<< std::endl;
		std::cout << "Is" << pa << "file? [" 
			<< std::filesystem::is_regular_file(pa) << "]" << std::endl;
		std::cout << "is" << pa << "directory? [" 
			<< std::filesystem::is_directory(pa) << "]" << std::endl;
		break;
	}
	case file_system::path: {
		std::cout << "current path = " << std::filesystem::current_path() <<"\n";
		std::cout << "pa relative path = " << pa.relative_path() << "\n";
		std::cout << "absolute path = " << std::filesystem::absolute(pa) << "\n";
		std::cout << "pa canonical path = " << std::filesystem::canonical(pa) << std::endl;
		break;
	}
	case file_system::derectory: {
		namespace fs = std::filesystem;
		fs::directory_iterator di(fs::current_path()/"some_file");
		while (di != fs::end(di))
		{
			const fs::directory_entry& entry = *di;
			std::cout << entry.path() << std::endl;
			++di;
		}
		//range for
		for (const fs::directory_entry& de :
			fs::recursive_directory_iterator(fs::current_path() / "some_file"))
		{
			std::cout << de.path() << std::endl;
		}
		break;
	}
	case file_system::create_derectory: {
		std::filesystem::path pat("./some_file/create");
		std::cout << pat << " is exeists? [" << std::boolalpha
			<< std::filesystem::exists(pat) << "]" << std::endl;

		std::filesystem::create_directory(pat);
		std::cout << pat << " is exeists? [" << std::boolalpha
			<< std::filesystem::exists(pat) << "]" << std::endl;
		std::cout << pat << " is directory? ["
			<< std::filesystem::is_directory(pat) << "]" << std::endl;
		break;
	}
	case file_system::copy_derectory: {
		//derectory만 복사시 안에 내용물이 복사된다.
		std::filesystem::path from("./some_file/create");
		std::filesystem::path to("./copy_file");
		std::filesystem::path copy_place("./copy_file/copy");


		std::cout << copy_place << " is exeists? [" << std::boolalpha
			<< std::filesystem::exists(copy_place) << "]" << std::endl;
		std::cout << from << " copy from " << to << std::endl;
		
		std::filesystem::copy(
			from, to, std::filesystem::copy_options::recursive);

		std::cout << copy_place << " is exeists? [" << std::boolalpha
			<< std::filesystem::exists(copy_place) << "]" << std::endl;
		
		break;
	}
	case file_system::remove_derectory: {
		std::filesystem::path pa("./copy_file/copy");

		std::cout << pa << " is exeists? [" << std::boolalpha
			<< std::filesystem::exists(pa) << "]" << std::endl;
		std::cout << "remove " << pa << std::endl;

		std::filesystem::remove(pa);

		std::cout << pa << " is exeists? [" << std::boolalpha
			<< std::filesystem::exists(pa) << "]" << std::endl;

		pa = "./copy_file/error.txt";
		std::error_code err;
		std::filesystem::remove(pa, err);
		std::cout <<"error massage : "<< err.message() << std::endl;

		break;
	}
	case file_system::for_remove : {
		namespace fs = std::filesystem;
		fs::path pa("./some_file/bin");
		while (true) {
			bool is_modified = false;
			for (const auto& entry : fs::directory_iterator(pa))
			{
				const std::string ext = entry.path().extension().string();
				if (ext == ".txt") {
					fs::remove(entry.path());
					is_modified = true;
					break;
				}
			}
			if (!is_modified) {
				break;
			}
		}

		break;
	}
	default:
		break;
	}


}

void Test_optional() {
	enum class Option_Kind : char {
		option_value,option_create,reference_option,variant_create,variant_monostate
		,tuple_birding
	};
	switch (Option_Kind::tuple_birding)
	{
	case Option_Kind::option_value: {
		std::function<std::optional<std::string>(std::map<int, std::string>&, int)> fn(
			[](std::map<int, std::string>& m, int key)->std::optional<std::string> {

			std::optional<std::string> op;

			auto itr = m.find(key);
			if (itr != m.end()) {
				return itr->second;
			}
			return std::nullopt;

		}
		);

		std::map<int, std::string> m = { {1,"Kim"},{2,"Jin"},{3,"Hungry"} };

		std::cout << "맵 2에 해당하는 값은? = " << fn(m, 2).value().c_str() << std::endl;
		std::cout << "맵 4에 해당하는 값이있나요? = " << std::boolalpha
			<< fn(m, 4).has_value() << std::endl;

		break;
	}
	case Option_Kind::option_create: {
		Basic bs;
		std::cout << "option 객체 생성---------------" << std::endl;
		std::optional<Basic> ob;
		std::cout << "복사 생성자 ob 호출" << std::endl;
		ob = bs;
		break;
	}
	case Option_Kind::reference_option: {
		Basic bs;

		std::cout << "bs public_int = " << bs.public_int << std::endl;
		
		std::cout << "op publi int = 7" << std::endl;	
		std::optional<std::reference_wrapper<Basic>> op = std::ref(bs);
		op->get().public_int = 7;


		std::cout <<"bs public_int = "<< bs.public_int << std::endl;

		break;
	}
	case Option_Kind::variant_create: {
		class A {
		public:
			void a() { std::cout << "is class A" << std::endl; };
		};
		class B {
		public:
			void b() { std::cout << "is class B" << std::endl; };
		};

		std::function<std::variant<A, B>(bool)> fn([](bool bl)->std::variant<A, B> {
			if (bl)
			{
				return A();
			}
			return B();
		});

		auto v_a = fn(true);

		std::cout << v_a.index() << std::endl;
		std::get<A>(v_a).a();

		break;
	}
	case Option_Kind::variant_monostate: {

		class A {
		public:
			A(int n){}
		};
		class B {
		public:
			B(int n){}
		};

		//std::variant<A, B> no_mon;
		std::variant<std::monostate, A, B> mon;
		
		break;
	}
	case Option_Kind::tuple_birding: {
		std::tuple<int, std::string, bool> tu;
		tu = std::make_tuple(10, "Jin", true);

		auto [num, name, is_tu] = tu;
		std::cout << "num" << num << "name" << name << "bool" 
			<< std::boolalpha << is_tu <<std::endl;

		std::map<int, std::string> m;
		m.emplace(std::make_pair(1, "baby"));
		m.emplace(std::make_pair(20, "ancle"));

		for (auto& [age,state] : m)
		{
			std::cout << "age = " << age << "," << "state = " << state << std::endl;
		}

		break;
	}
	default:
		break;
	}
	
}
void Jotkka_fun() {

#define Jot_num(b) b
#define Jot_add(a) a + Jot_num

	std::cout << "Jot_add(a)(b) = " << Jot_add(5)(7) << std::endl;

}


int main() {
	runTemplateParameters();
	return 0;
}

// a 占쏙옙占싸그뤄옙 占쏙옙占쏙옙: <Ctrl+F5> 占실댐옙 [占쏙옙占쏙옙占? > [占쏙옙占쏙옙占쏙옙占쏙옙占?占십곤옙 占쏙옙占쏙옙] 占쌨댐옙
// 占쏙옙占싸그뤄옙 占쏙옙占쏙옙占? <F5> 키 占실댐옙 [占쏙옙占쏙옙占? > [占쏙옙占쏙옙占?占쏙옙占쏙옙] 占쌨댐옙

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
