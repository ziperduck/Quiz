#include <sstream>
#include "Programers.h"
#include <cctype>
#include <bitset>
#include <unordered_set>


vector<int> pull_two_number() {

	std::vector<int> numbers = { 2,1,3,4,1 };
	vector<int> answer;

	for (auto& i = numbers.begin(); i < numbers.end() - 1; i++) {
		for (auto& k = i + 1; k < numbers.end(); k++) {
			answer.push_back(*i + *k);
		}
	}


	for (auto& i = answer.begin(); i < answer.end(); i++)
	{
		for (auto& k = i + 1; k < answer.end(); )
		{
			if (*i > *k)
			{
				std::swap(*i, *k);
			}
			else if (*i == *k)
			{
				k = answer.erase(k);
				continue;
			}
			k++;
		}
	}
	for (auto i = answer.begin(); i < answer.end(); i++)
	{
		std::cout << "numbers = " << *i << std::endl;
	}
	return answer;
}

vector<int> pull_two_number2() {
	std::vector<int> numbers = { 2,1,3,4,1 };
	vector<int> answer;
	bool check[201] = { false, };

	for (int i = 0; i < numbers.size(); i++)
	{
		for (int k = i+1; k < numbers.size(); k++)
		{
			if (check[numbers.at(i) + numbers.at(k)] == false) {
				answer.push_back(numbers.at(i) + numbers.at(k));
				check[numbers.at(i) + numbers.at(k)] = true;
			}
		}
	}
	std::sort(answer.begin(), answer.end());
	std::cout << "numbers = {";
	for (auto i = answer.begin(); i < answer.end(); i++)
	{
		std::cout << *i << ", ";
	}
	std::cout <<"}"<<std::endl;
	return answer;
}
int kakaojorudy() {
	vector<vector<int>> board = 
	{{0, 0, 0, 0, 0},
{ 0, 0, 1, 0, 3},
{ 0, 2, 5, 0, 1},
{ 4, 2, 4, 4, 2},
{ 3, 5, 1, 3, 1}};
	vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
	int answer = 0;
	const int Board_Row = board.front().size();
	std::vector<int> Basket(0);
	std::vector<int> has_moves(Board_Row);
	
	for (int i = board.size()-1; i >= 0; i--)
	{
		for (int k = 0; k != Board_Row; k++)
		{
			if (board.at(i).at(k) != 0) {
				has_moves.at(k) = i;
			}
		}
	}

	for (auto i = moves.begin(); i != moves.end(); i++)
	{
		if (has_moves.at(*i - 1) < Board_Row) {
			const int board_vluae = board.at(has_moves.at(*i - 1)).at(*i - 1);
			has_moves.at(*i - 1) += 1;
			if (Basket.empty());
			else if (Basket.back() == board_vluae){
				Basket.pop_back();
				answer += 2;
				continue;
			}
			Basket.push_back(board_vluae);
		}
	}

	std::cout << "answer Size = " << answer << std::endl;
	return answer;
}

std::string Marathon() {
	std::vector<std::string> participant = { "leo", "kiki", "eden" };
	std::vector<std::string> completion = { "eden", "kiki" };
	std::string answer{};
	
	std::multiset<std::string> partiset(participant.begin(), participant.end());
	std::multiset<std::string> complset(completion.begin(), completion.end());

	for (auto&& i = complset.begin(); i != complset.end(); i++)
	{
		const auto& par_it = partiset.find(i->c_str());
		if (par_it != partiset.end()) {
			partiset.erase(par_it);
		}
		else {
			break;
		}
	}
	answer = *partiset.begin();
	
	std::cout << "no count completion : " << answer.c_str() << std::endl;
	return answer;
}

std::vector<int> Chekc_count(std::vector<int>& ans) {
	std::vector<int> answer;

	if (ans.at(0) > ans.at(1)) {
		if (ans.at(0) > ans.at(2)) {
			answer.push_back(1);
		}
		else if (ans.at(0) == ans.at(2)) {
			answer.push_back(1);
			answer.push_back(3);
		}
	}
	else if (ans.at(0) < ans.at(1))
	{
		if (ans.at(1) > ans.at(2)) {
			answer.push_back(2);
		}
		else if (ans.at(1) < ans.at(2)) {
			answer.push_back(3);
		}
		else {
			answer.push_back(2);
			answer.push_back(3);
		}
	}
	else {
		if (ans.at(0) > ans.at(2)) {
			answer.push_back(1);
			answer.push_back(2);
		}
		else if (ans.at(0) == ans.at(2)) {
			answer.push_back(1);
			answer.push_back(2);
			answer.push_back(3);
		}
	}
	
	answer.push_back(0);
	for (size_t i = 0; i < 2; i++)
	{
		if (ans.at(answer.back()) > ans.at(i + 1)) {
		}
		else if (ans.at(answer.back()) < ans.at(i + 1)) {
			answer.back() += 1;
		}
		else {
			answer.push_back(i+1);
		}
	}

	for (auto& answer : answer)
	{
		answer +=1;
	}

	return answer;
}
void Mock_Test() {
	std::vector<int> answers = { 1,1,3,4,2,4};

	//chul_su 0번, Young_Hee 1번, Min_Ji 2번
	int supoja_pattern[3] = { 5,8,10 };
	std::vector<int> an_count(3);

	std::vector<int> Chul_Su =		{ 1,2,3,4,5 };
	std::vector<int> Young_Hee =	{ 2,1,2,3,2,4,2,5 };
	std::vector<int> Min_Ji =		{ 3,3,1,1,2,2,4,4,5,5 };

	for (int i = 0; i < answers.size(); i++)
	{
		if (answers.at(i) == Chul_Su.at(i % supoja_pattern[0]))
		{
			++an_count.at(0);
		}
		if (answers.at(i) == Young_Hee.at(i % supoja_pattern[1]))
		{
			++an_count.at(1);
		}
		if (answers.at(i) == Min_Ji.at(i % supoja_pattern[2]))
		{
			++an_count.at(2);
		}

	}

	std::vector<int> answer = { 1 };

	for (size_t i = 0; i < 2; i++)
	{
		int num = answer.back() - 1;
		if (an_count.at(num) < an_count.at(i + 1)) {
			answer.back() = i + 2;
		}
		else if (an_count.at(num) == an_count.at(i + 1)) {
			answer.push_back(i + 2);
		}
	}

	for (const auto& answer : answer) {
		std::cout << "answer = " << answer << std::endl;
	}

}

void Programers_Update() {

	std::vector<int> progresses = { 17,75,23 };
	std::vector<int> speeds = {89,56,17};

	std::vector<int> answer;

	int days = 0;
	
	for (auto i = progresses.begin(), k = speeds.begin();
		i != progresses.end(); ++i,++k) {
		
		if (*i  + *k * days < 100) {
			answer.push_back(1);
			double pro = 100 - *i;
			double spe = *k;
			days = std::ceil(pro / spe);
			continue;
		}
		
		++answer.back();
	}
	std::cout << "[";
	for (auto& an : answer)
	{
		std::cout << " "<< an ;
	}
	std::cout << " ]" <<std::endl;
}

void Fine_Rectangle() {
	std::vector<int> Width = { 13,12,11,10,9,8,7,6,5,4,3,2,1};
	for (auto& W = Width.begin(); W != Width.end() - 1; W++)
	{
		std::cout << *W << " = [";
		for (auto H = W; H != Width.end(); H++)
		{

			int w = *W;
			int h = *H;

			long long width= w;
			long long hight = h;
			
			long long answer = width * hight;

			long long diagonal = 0;

			long long left = width;
			long long right = hight;
			long long remain = 0;

			while (true)
			{
				remain = left % right;
				left = right;
				right = remain;

				if (remain == 0) {
					diagonal = ((width + hight) / left - 1) * left;
					answer -= ((width + hight) / left - 1) * left;
					break;
				}
			}

			std::cout << " " << diagonal;

		}
		std::cout << " ]" << std::endl;
	}
}


void One_Two_Four() {
	/*
	{10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
	{100,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700};
	{ 10,20,30,40,50,60,70,80,90,100 };

	*/
	std::vector<long long> n(1000000,0);
	int num = 0;
	std::transform(n.begin(), n.end(), n.begin(), [&num](int i) {return ++num; });
	long long value = 0;
	std::vector<long long> vv = {0};
	for (auto& n : n)
	{
		for (long long i = n, Times = 1; i > 0; i /= 3, Times *= 10)
		{
			value += (i % 3)*Times ;
			if (i % 3 == 0) {
				value += 3 * Times;
				i -= 1;
			}
		}
		long long Minus = value - vv.back();
		if (Minus != 1
			&& Minus != 8
			&& Minus != 78
			&& Minus != 778
			&& Minus != 7778
			&& Minus != 77778
			&& Minus != 777778
			&& Minus != 7777778
			&& Minus != 77777778
			&& Minus != 777777778
			&& Minus != 7777777778
			&& Minus != 77777777778
			&& Minus != 777777777778
			&& Minus != 7777777777778
			&& Minus != 77777777777778) {
			std::cout << vv.back() << " : "<< value << std::endl;
		}
		
		vv.push_back(value);

		//std::cout <<"["<< n << " : " << value << "]  ";
		
		value = 0;
	
	}
	std::string answer = std::to_string(value);
}

void catch_phone_num() {
	std::vector<std::string> phone_book = {"12","5987","66666","123"};
	bool answer = true;
	for (auto& i = phone_book.begin(); i != phone_book.end()-1; i++)
	{
		for (auto& k = i+1; k != phone_book.end(); k++)
		{
			if (i->size() < k->size())
			{
				if (k->find(*i) == 0) {
					std::cout << "is false" << std::endl;
					return;
				}
			}
			else {
				if (i->find(*k) == 0) {
					std::cout << "is false" << std::endl;
					return;
				}
			}
		}
	}

}

void triangle_snail() {
	int n = 5;
	int max_num = (n + 1)*n / 2;
	std::vector<int> answer(max_num);
	
	int add = 0;
	
	int ch_count = 0;
	int change = n;

	int sequence = 0;
	int floors = 0;
	for (int i = 0; i < max_num; ++i, ++ch_count)
	{
		
		if (ch_count == change)
		{
			++sequence %= 3;
			--change;
			ch_count = 0;
		}

		switch (sequence)
		{
		case 0:
			add += floors;
			++floors;
			break;
		case 1:
			++add;
			break;
		case 2:
			add -= floors;
			--floors;
			break;
		default:
			break;
		}
		
		answer.at(add) = i+1;

	}

	for (auto answer : answer)
	{
		std::cout << answer << " ";
	}
	std::cout << std::endl;
}
void joy_stick() {
	// 몇글자-1
	std::string name = "JAN";
	int answer = 0;
	std::vector<std::tuple<bool, int>> is_A = { {true,0} };
	if (name.front() != 'A')
	{
		is_A.back() = { false,0 };
	}

	
	for (auto ch : name)
	{
		answer += ch - 'A';
		if (ch > 'N')
		{
			answer -= (ch - 'N') * 2;
		}
		if (ch == 'A' && !std::get<bool>(is_A.back())) {
			is_A.push_back({ true, 0 });
		}
		else if (ch != 'A' && std::get<bool>(is_A.back())) {
			is_A.push_back({ false, 0 });
		}
	}
	auto iterator_end = is_A.end();
	for (auto a = is_A.begin(); a < iterator_end; a++)
	{

	}

	std::cout << "answer" << answer << std::endl;
	//직진 15
	//123456789ABCDEFG
	//oooooooooooooooo
	//ooxxxxxxxxoooooooo	17	16	14	12
	//ooooxxxxxooooooo	15	13	
	//ooooooxxxxxooooo	15	15	
	//oooooxxxxxxooooo	15	14	
	//oooooxxooxxooooo	15	14	
	//xxxoxxxxxoooxxoo	15	13	
	//xxxoxoxxxoooxxoo	15	13	
	//oxoxoxoxoxoxoxox	15	14	
	//oxoooooooooooooo	15	14
	//ooxxoooooooooooo	15	14
	//oooxxxoooooooooo	15
	//ooooxxxxoooooooo	15
	//ooooxxxxooooxxxo	15
	//oooxooooooooooo	14	14
	//ooxxooooooooooo	14	13
	//ooxoooooooooooo	14	14
	//oooxxxooooooooo	15	14
	//oooxoooooooooo	15	14
	//oooxooooooooo		15	14
	//oooxoooooooo		15	14

}

void Seconds_prices() {
	std::vector<int> prices = { 2, 1, 2, 3, 1 };
	std::stack<std::pair<int, int>> descending;
	descending.push(std::pair<int, int>(prices.front(),0));
	std::vector<int> Answer(prices.size());

	int Fall = 0;
	for (int i = 0; i + 1 < prices.size(); i++)
	{
		if (prices[i] > prices[i + 1])
		{
			while (!descending.empty())
			{
				std::pair<int, int> top = descending.top();
				descending.pop();
				if (top.first > prices[i + 1])
				{
					Answer.at(top.second) = i - top.second + 1;
				}
				else
				{
					descending.push(top);
					break;
				}
			}
		}
	
		descending.push(std::pair<int,int>(prices[i + 1], i + 1));
	}
	while (!descending.empty())
	{
		Answer.at(descending.top().second) = prices.size() - descending.top().second - 1;
		descending.pop();
	}

	std::cout << "Anser = ";
	for (int i = 0; i < Answer.size(); i++)
	{
		printf(",%d ", Answer[i]);
	}
	std::cout << std::endl;

}


void Disguise() {
	std::vector<std::vector<std::string>> clothes 
		= { {"yellow_hat", "headgear"}, {"blue_sunglasses", "face"}, {"blue_sunglasses", "glasses"} };
	/*
	crow_mask, face], [blue_sunglasses, face], [smoky_makeup, face
	*/
	std::map<std::string, int> sortclothes;

	int answer = 1;

	for (auto i = clothes.begin(); i != clothes.end(); i++)
	{
		auto clothe = sortclothes.find(i->back());
		if (clothe != sortclothes.end())
		{
			clothe->second++;
		}
		else
		{
			sortclothes.insert(std::make_pair(i->back(), 1));
		}
	}
	std::vector<int> clothepos;
	const int sortsize = sortclothes.size();
	for (int i = 0; i < sortsize; i++)
	{
		for (int k = 0; k < sortsize - i; k++)
		{
			for (int m = 0; m < sortsize;m++)
			{
			}
		}
	}
	/*
	옷을 종류별로 매칭해야한다.
	모든 옷의 종류를 다 입을 필요가 없다.
	옷을 다 모두 매칭하여 입었을때 경우의 수를 말하시오

	옷을 한종류부터 모든 종류간의 매칭을하여 곱하고 그 곱한것을 모두 더해준다.
	현재 매칭중인 옷종류가 모두 연산이 끝이나면 종류를 늘려서 다시 매칭해준다.


	*/
	if (sortclothes.size() > 1)
	{
		answer += clothes.size();
	}
	std::cout << answer;
}

void Priority_Printer() {
	vector<int> priorities = {2,1,3,2};
	int location = 2;
	const int size = priorities.size();



	for(;location > -1;--location)
	{
		auto begin = priorities.begin();
		
		for (auto pos = priorities.begin(); pos != priorities.end(); pos++)
		{
			if (*begin < *pos)
			{
				if (location == 0)
					location = priorities.size();

				priorities.push_back(*begin);
				break;
			}
		}
		priorities.erase(priorities.begin());
	}

	int answer = size - priorities.size();

	printf("answer = %d\n", answer);
}

void Min_Number() {
	vector<int> arr = {1,1,1};
	int min = *std::min_element(arr.begin(), arr.end());
	arr.erase(std::remove(arr.begin(), arr.end(), min), arr.end());
	if (arr.empty()) arr.push_back(-1);
	printf("num = %d\n", min);
}

void K_Sequence() {
	std::vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
	std::vector<std::vector<int>> commands = { {2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 }};
	
	std::vector<int> answer;

	for (auto i = commands.begin(); i != commands.end(); i++)
	{
		std::vector<int> copy = std::vector<int>(array);
		int com[3] = { (*i).at(0) - 1 ,(*i).at(1),(*i).at(2) - 1 };
		std::sort(copy.begin() + com[0], copy.begin() + com[1]);
		answer.push_back(copy.at(com[0] + com[2]));
	}

	for (auto i = answer.begin(); i < answer.end(); i++)
	{
		std::cout << " " << *i;
	}
	std::cout << std::endl;
	
}

void prime_num() {
	int n = 100000;
	int answer;
	std::vector<int> prime_num = {2};
	for (int i = 3; i <= n; i++)
	{
		for (auto k = prime_num.begin();; k++)
		{
			if (k == prime_num.end() || *k * *k > i)
			{
				prime_num.push_back(i);
				break;
			}
			else if (i % *k == 0)
			{
				break;
			}
		}
	}
	answer = prime_num.size();
	int num = 0;
	for (auto k = prime_num.begin(); k != prime_num.end(); k++, num++)
	{
		if (num % 10 == 0)
		{
			std::cout << std::endl;
		}
		std::cout << *k << " ";
	}
	std::cout << std::endl;
	std::cout << "answer = " << answer << std::endl;

}

void lost_training_clothes() {
	std::vector<int> lost = { 2,4 };
	std::vector<int> reserve = {3};
	int n = 5;
	int answer = n;

	std::vector<int> students(n + 2,1 );
	students[0] = 0;
	students[n+1] = 0;
	std::sort(lost.begin(), lost.end());

	for (auto i : reserve)
	{
		++students[i];
	}
	for (auto i : lost)
	{
		--students[i];
		--answer;
	}
	for (auto i : lost)
	{
		if (students[i] > 0)
		{
			++answer;
		}
		else
		{
			if (students[i - 1] > 1)
			{
				++answer;
				--students[i - 1];
			}
			else if (students[i + 1] > 1)
			{
				++answer;
				--students[i + 1];
			}
		}
	}
	std::cout << "answer = " << answer;

	return;
	for (auto i = lost.begin(); i != lost.end(); i++)
	{
		--answer;
		for (auto k = reserve.begin(); k != reserve.end();)
		{
			
			int search = *k - *i;
			if (search > 1) {
				break;
			}
			else if (search < -1) {
				k = reserve.erase(k);
				continue;
			}
			else {
				++answer;
				reserve.erase(k);
				break;
			}
			k++;
		}

	}
	std::cout << "answer = " << answer;
}

void RecommendNewId()
{
	std::string new_id = "123asd";
	std::string answer;

	/*
O	1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
O	2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
O	3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
O	4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
	 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/
	for (auto i = new_id.begin(); i < new_id.end();)
	{
		if (('0' <= *i && *i <= '9') || ('a' <= *i && *i <= 'z'));
		else if ('A' <= *i && *i <= 'Z')
		{
			*i += 32;
		}
		else if (*i == '.')
		{
			if (i == new_id.begin() || *(i - 1) == '.')
			{
				i = new_id.erase(i);
				continue;
			}
			else if (i == new_id.end() - 1)
			{
				i = new_id.erase(i);
				--i;
				continue;
			}
		}
		else if (*i != '-' && *i != '_')
		{
			i = new_id.erase(i);
			continue;
		}
		i++;
	}
	if (new_id.size() > 15)
	{
		new_id.erase(new_id.begin() + 15, new_id.end());
	}
	else if (new_id.empty())
	{
		new_id = "aaa";
	}
	if (*(new_id.end() - 1) == '.')
	{
		new_id.pop_back();
	}
	while (new_id.size() < 3)
	{
		new_id.push_back(*(--new_id.end()));
	}

	answer = new_id;

	std::cout << "answer : " << answer.c_str() << std::endl;

}

void Rebers_Base3() {
	int n = 4;
	for (long long i = 90000000; i < 90000100; i++)
	{
		n = i;
		long long answer = 0;

		long long base_3 = 0;
		while (n > 0) {
			base_3 *= 10;
			base_3 += n % 3;
			n = n / 3;
		}
		std::cout << "n : " << i << " base_3 : " << base_3 << " = ";

		int square = 1;
		while (base_3 > 0) {
			answer += (base_3 % 10) * square;
			base_3 /= 10;
			square *= 3;
		}

		std::cout << "answer : " << answer << std::endl;
	}

	//3
	//7
	//2....1
}

void Remove_Sort() {
	vector<int> arr = { 2, 36, 1, 3 ,5,3,7,8};
	int divisor;
	vector<int> answer;
	arr.erase(std::remove_if(arr.begin(), arr.end(), [](int num) { return num % 2; }), arr.end());
	std::sort(arr.begin(), arr.end());
	answer.assign(arr.begin(), arr.end());
	if (answer.empty())
	{
		answer.push_back(-1);
	}

	for (auto i : answer)
	{
		std::cout << "[" << i <<"], ";
	}
	std::cout << std::endl;
	
}

void Mind_Sort() {

	using namespace std;
	vector<string> strings = { "sun", "bed", "car" };
	int n = 1;

	vector<string> answer;

	map<char, set<string>> mind_str;
	for (auto i : strings)
	{
		mind_str[i[n]].insert(i);
	}

	for (auto i : mind_str)
	{
		answer.insert(answer.end(),i.second.begin(), i.second.end());
	}

	for (auto i : answer)
	{
		std::cout << i << std::endl;
	}
}

void P_Y_Count() {
	std::string s = "PpowerFule Yellow ";
	bool answer = 
		std::count_if(s.begin(), s.end(), [](int num) {return num == 'p' || num == 'P'; })
		== std::count_if(s.begin(), s.end(), [](int num) {return num == 'y' || num == 'Y'; });
		
	std::cout << "answer = " << answer << std::endl;
	s = "PPAP YyY";
	answer = 
		std::count_if(s.begin(), s.end(), [](int num) {return num == 'p' || num == 'P'; })
		== std::count_if(s.begin(), s.end(), [](int num) {return num == 'y' || num == 'Y'; });
	
	std::cout << "answer = " << answer << std::endl;

}

void PhoneCatMon() 
{
	std::vector<int> nums{ 3,1,2,3 };
	int answer = (std::set<int>(nums.begin(), nums.end())).size();
	bool bo = answer < nums.size() / 2;
	std::cout << answer << "<" << nums.size() / 2 << std::boolalpha << bo << std::endl;
}


void descending() 
{
	std::string s = "CBAcba";
	std::sort(s.begin(), s.end());
	std::string answer(s.rbegin(), s.rend());
	std::cout << "s = " << answer.c_str() << std::endl;

}
void inner_product() {
	std::vector<int> a, b;
	int answer = std::inner_product(a.begin(), a.end(), b.begin(), 0);
}

void partial_sum() {
	vector<int> absolutes;
	vector<bool> signs;

	int answer = 0;

	for (int i = 0; i < absolutes.size(); i++)
	{
		if (!signs.at(i))
		{
			absolutes.at(i) *= -1;
		}
		answer += absolutes.at(i);
	}

}

void company_budget() {
	vector<int> d = {2,2,3,3};
	int budget = 11;
	int Sum = 0;
	int answer = 0;

	std::sort(d.begin(), d.end());
	while(answer < d.size() && budget >= Sum + d.at(answer))
	{
		Sum += d.at(answer++);
	}
	std::cout << "Sum = " << Sum << "answer = " << answer << std::endl;
}

void control_string() {
	std::string s = "015915";
	bool answer = false;
	//isdigit은 문자가 숫자일경우 0을 리턴한다.
	//digit은 자릿수 0~9를 의미한다.
	if (s.length() >= 4 && s.length() <= 6) {
		answer = !std::any_of(
			s.begin(), s.end(), &isdigit);
	}
	std::cout << s.c_str() << " = "<< std::boolalpha << answer << std::endl;
	s = "avd5g";
	if (s.length() >= 4 && s.length() <= 6) {
		answer = !std::any_of(
			s.begin(), s.end(), [](char c) { return c < '0' || c > '9'; });
	}
	std::cout << s.c_str() << " = " << std::boolalpha << answer << std::endl;

}

void find_kim() {
	std::vector<std::string> seoul = { "Jane", "asd","Kim" };
	std::string answer;
	for (int i = 0; i < seoul.size(); i++)
	{
		if (seoul.at(i) == "Kim")
		{
			answer = "김서방 " + std::to_string(i) + "에 있다";
			break;
		}
	}
	//distance는 iterator의 길이를 인트형으로 반환한다.
	int num = std::distance(seoul.begin(),std::find(seoul.begin(), seoul.end(), "Kim"));
	answer = "김서방 " + std::to_string(num) + "에 있다";

	std::cout << answer.c_str() << std::endl;
}

void minun_lottor() {
	std::vector<int> lottos;
	std::vector<int> win_nums;
	bool win_bool[46] = { false, };

	std::vector<int> answer = {0,0};

	for (auto i = win_nums.begin(); i != win_nums.end(); i++){
		win_bool[*i] = true;
	}
	for (auto i = lottos.begin(); i != lottos.end(); i++) {
		if (*i == 0) {
			++answer.front();
		}
		else if (win_bool[*i]) {
			++answer.front();
			++answer.back();
		}
	}

	answer.front() = 7 - answer.front();
	answer.back() = 7 - answer.back();

	if (answer.front() > 6)
		answer.front() = 6;
	if (answer.back() > 6)
		answer.back() = 6;

}


void keypad() {
	std::vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	std::string hand = "right";

	constexpr int LEFT = 0;
	constexpr int RIGHT = 2;

	char keypad[3] = { 'L','\0','R' };
	int keynumber[12][2] = {
		{1,1},{1,2},{1,3},
		{2,1},{2,2},{2,3},
		{3,1},{3,2},{3,3},
		{4,1},{4,2},{4,3}
	};
	int hands[3] = { 9, 0, 11 };
	const int main_hand = hand == "left" ? LEFT : RIGHT;
	std::string answer = "";

	for (auto i = numbers.begin(); i != numbers.end(); i++)
	{
		if (*i == 0)
		{
			*i = 11;
		}
		*i -= 1;
		int remainder = *i % 3;
		if (keypad[remainder] == '\0')
		{
			int l_interval = std::abs(keynumber[*i][0] - keynumber[hands[LEFT]][0])
				+ std::abs(keynumber[*i][1] - keynumber[hands[LEFT]][1]);
			int r_interval = std::abs(keynumber[*i][0] - keynumber[hands[RIGHT]][0])
				+ std::abs(keynumber[*i][1] - keynumber[hands[RIGHT]][1]);
			remainder = l_interval == r_interval ? main_hand : 
				l_interval < r_interval ? LEFT : RIGHT;
			
		}

		hands[remainder] = *i;
		answer.push_back(keypad[remainder]);
	}

	std::cout << answer << std::endl;
}

void CaesarPassword() {
	std::string s = {"A BCD Z"};
	int n = 1;
	
	std::string answer = "";
	for (auto i : s)
	{
		if (i != ' ')
		{
			char alpha = isupper(i) ? 'A' : 'a';
			answer.push_back((i - alpha + n) % 26 + alpha);
			continue;
		}
		answer.push_back(i);
	}

	std::cout << answer << std::endl;
}

void MakeStrangeLetters() {
	std::string s = "try hello world";
	std::string answer = "";

	int count = 0;
	for (auto c : s) {
		answer.push_back(c);
		if (c == ' ')
		{
			count = 0;
			continue;
		}

		answer.back() = count % 2? std::tolower(c) : std::toupper(c);
		count++;
	}
	std::cout << answer << std::endl;
}

void DigitSum() {
	int n = 12345;

	int answer = 0;

	std::string s = std::to_string(n);

	for (int i = 0; i < s.size(); i++) answer += (s[i] - '0');

	std::cout << "answer = " << answer << std::endl;
}

void Ascending() {

	long long n = 12345;

	long long answer = 0;

	std::string s = std::to_string(n);
	std::sort(s.begin(), s.end(), std::greater<char>());

	for (int i = 0; i < s.size(); i++) {
		answer *= 10;
		answer += (s[i] - '0');
	}

	std::cout << "answer = " << answer << std::endl;

}

void FailureRate() {

	int N = 500;
	std::vector<int> stages = {1,200,62,97,48,231,54,99,122,333,501,1,200,62,97,48,231,54,99,48,231,54 };

	std::sort(stages.begin(), stages.end());

	int challengers = stages.size();
	int staystage = 0;

	std::set<std::pair<float, int>> failurerate;

	std::vector<int> answer;

	for (auto i = stages.begin(); i != stages.end();)
	{
		staystage = *i;
		auto next = std::find(stages.rbegin(), std::vector<int>::reverse_iterator(i), staystage);

		float staypersons = std::distance(i, next.base());
		failurerate.insert(std::pair<float, int>(challengers / staypersons, staystage));

		challengers -= staypersons;
		i = next.base();
	}
	bool visit[501] = { 0, };
	for (auto i : failurerate)
	{
		if (i.second < N + 1)
		{
			visit[i.second] = true;
			answer.push_back(i.second);
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (!visit[i]) {
			answer.push_back(i);
		}
	}
	for (auto i = failurerate.begin(); i != failurerate.end(); i++)
	{
		std::cout << i->first << " " << i->second << std::endl;
	}

	std::cout << "answer" << std::endl;
	for (auto i = 0; i < N; i++)
	{
		std::cout << answer[i] << " ";
		if (i%10 < 1)
		{
			std::cout << std::endl;
		}
	}

}

void Common_Number() {
	int n = 2;
	int m = 5;

	int left = n, right = m;

	int gcm, lcd = 0;

	while (left != 0) {
		int temp = left;
		left = right % left ;
		right = temp;
	}
	gcm = right;
	lcd = n * m / gcm;

	std::cout << "gcm = " << gcm << "lcd = " << lcd << std::endl;
}

void DivisorCound() {
	int left = 13, right = 17;
	int answer = 0;
	for (int i = left; i <= right; i++)
	{
		float sqrt_i = std::sqrt(i);
		answer += sqrt_i == std::floor(sqrt_i) ? sqrt_i : -sqrt_i;
	}
	std::cout << "anwer = " << answer << std::endl;
}

void Hidden_Phonenumber() {
	std::string Phonenumber = "1234";
	std::fill_n(Phonenumber.begin(), Phonenumber.size() - 4, '*');
	std::cout << Phonenumber << std::endl;
}

void Test_stlMap() {
	std::multimap<float, int> fi;
	fi.insert(std::pair<float, int>(0.5f, 1));
	fi.insert(std::pair<float, int>(0.1f, 3));
	fi.insert(std::pair<float, int>(0.7f, 2));
	fi.insert(std::pair<float, int>(1.0f, 1));
	fi.insert(std::pair<float, int>(1.0f, 0));

	for (auto i = fi.begin(); i != fi.end(); i++)
	{
		std::cout << " " << i->first << " " << i->second << std::endl;
	}
}

void SecretMap() {
	int n = 5;
	std::vector<int> arr1 = { 9, 20, 28, 18, 11 };
	std::vector<int> arr2 = { 30, 1, 21, 17, 28 };
	std::vector<std::string> answer(n,std::string(n,'#'));

	for (int i = 0; i < n; i++)
	{
		int width = arr1[i] | arr2[i];
		for (auto k = answer[i].rbegin(); k != answer[i].rend(); k++)
		{
			if (width % 2 == 0)
			{
				*k = ' ';
			}
			width = width >> 1;
		}
	}

}

void SequenceNumber() {
	int x = 2;
	int n = 5;
	vector<long long> answer(n);
	std::generate(answer.begin(), answer.end(), [&n,x]() {
		return x* n--; });
	std::partial_sum(answer.begin(), answer.end(), answer.begin());
	
}

void MatricAddcation() {
	vector<vector<int>> arr1; 
	vector<vector<int>> arr2;

	vector<vector<int>> answer;
	for (auto a1 = arr1.begin(), a2 = arr2.begin();a1 != arr1.end() ; ++a1,++a2) {
		for (auto ab1 = a1->begin(), ab2 = a2->begin(); ab1 != a1->end(); ++ab1, ++ab2) {
			*ab1 += *ab2;
		}
	}
	for (int i = 0; i < arr1.size(); ++i)
	{
		for (int k = 0; k < arr1[i].size(); k++)
		{
			arr1[i][k] += arr2[i][k];
		}
	}
}

void DartGame() {

	std::string dartResult = "10T2D3D#";
	//100 4 -9
	std::vector<int> value;
	int answer = 0;
	int val_size = 0;

	//stringstream은 문자열을 자료형에 맞게 적용해준다.

	for (auto i = dartResult.begin(); i != dartResult.end(); i++)
	{
		switch (*i)
		{
		case 'S':
			break;
		case 'D':
			value.back() = std::pow(value.back(), 2);
			break;
		case 'T':
			value.back() = std::pow(value.back(), 3);
			break;
			
		case '*':
			value.back() *= 2;
			if (val_size > 1)
			{
				value[val_size - 2] *= 2;
			}
			break;
		case '#':
			value.back() *= -1;
			break;
			
		default:
			value.push_back(*i - '0');
			if (isdigit(*(i + 1)))
			{
				value.back() *= 10;
				i++;
			}
			val_size++;
			break;
		}


	}
	answer = std::accumulate(value.begin(), value.end(), 0);
	std::cout <<"answer = "<< answer << std::endl;
}

void MoreSpicy() {
	std::vector<int> scoville = { 1, 2, 3, 1, 1, 1 };
	int K = 30;
	
	int answer = 0;
	//priority_queue 우선순위 큐 
	std::multiset<int> sort_scoville = { scoville.begin(), scoville.end() };

	for (auto i = sort_scoville.begin(); i != std::prev(sort_scoville.end());)
	{
		if (*i >= K)
		{
			break;
		}

		sort_scoville.insert(*i + *std::next(i) * 2);
		i = sort_scoville.erase(i, std::next(i,2));
		answer++;
	}
	if (*sort_scoville.begin() < K)
	{
		answer = -1;
	}
	std::cout << "answer size = " << answer << std::endl;
}


void FibonacciRemainder() {
	int n = 1000;
	int answer = 1;
	
	int one = 1;
	int two = 1;

	for (int i = 2; i < n; i++) {
		two = one;
		one = answer;
		answer = one + two;
		answer %= 1234567;
	}

	std::cout << "n = " << n << "answer = " << answer << std::endl;
}

matrix operator* (matrix &a, matrix &b) {
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
	return c;
}

long long fibonacci(int n)
{
	matrix res = { {1, 0},{0, 1} };
	matrix fib = { {1, 1},{1, 0} };
	while (n) {
		if (n % 2 == 1) res = res * fib;
		fib = fib * fib;
		n *= 0.5;
	}
	return res[0][1];
}

void FibonacciRemainderMatrix() {
	int n = 20;
	std::cout << "n = " << n << fibonacci(n);
}
/*
* vector for 안 사용하기 
* std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, " "));
*/

/*
* 스텍 하나를 준비하고 문자열의 값을 하나씩 넣으면서 비교해본다.
* 만약 같은 것들이 있을 경우 따로 저장해놓고 아니면 스텍이 넣는다.
* 그냥 문자열을 분활해서 찾아보는게 현명하다.
*/
/*
* ababccccababccccccc
* abccabccc
* ababcababc
* 
*/
void CompressionString() {
	std::string s = "asdc";

	int answer = s.size();

	int range = s.size();
	// i는 vi의 약수를 찾고 그 약수를 
	for (int i = 1; i * i <= range; i++)
	{
		if (range % i != 0) {
			continue;
		}

		int common[2] = {i, range / i};

		for (int k = 0; k < common[0]; k++)
		{
		}

		for (int k = 0; k < common[1]; k++)
		{

		}
	}


}

//브루트 포스(해싱 알고리즘)
int Programmers_StringToHash(std::string String)
{

	constexpr int P = 2;
	constexpr int M = 100;

	int Hash_Value = 0;
	int Pow_P = 1;

	for (auto i : String)
	{
		Hash_Value = (Hash_Value + (i - 'a' + 1) * Pow_P) % M;
		Pow_P = (P * Pow_P) % M;
	}

	printf("%s Hash Key = %d\n", String.c_str(), Hash_Value);

	return Hash_Value;
}

//해시를 이용한 미완주자 찾기
void Programmers_UncompletedParticipant()
{
	std::vector<std::string> participant = {"kim","jin","hyeong"};
	std::vector<std::string> completion = { "kim","jin" } ;

	std::string answer;

	bool Hash[100] = {false, };

	constexpr int P = 2;
	constexpr int M = 100;

	for (auto i : completion)
	{
		Hash[Programmers_StringToHash(i)] = true;
	}

	for (auto i : participant)
	{
		if (!Hash[Programmers_StringToHash(i)])
		{
			printf("Find Participant %s\n", i.c_str());
			return;
		}
	}
	/*
	* 해시를 이용해 participant(참가자)들의 정보들을 저장해 complention(완주자)들의 정보를 key값으로 입력해 찾자
	*/

}

//프로그램 기능개발
void Programmers_FunctionalDevelopment()
{

	vector<int> progresses = { 93, 30, 55 };
	vector<int> speeds = { 1, 30, 5 };

	vector<int> answer;

	for (int i = 0; i < progresses.size();)
	{
		float Remading = 100 - progresses.at(i);
		int Days = ceil(Remading / speeds.at(i));

		int PushProgress = 0;
		while (i < progresses.size())
		{
			if (progresses.at(i) + speeds.at(i) * Days < 100)
			{
				break;
			}
			++i;
			++PushProgress;
		}

		answer.push_back(PushProgress);
	}


}

void Programmers_MoreSpicy()
{
	std::vector<int> scoville = { 1000, 200000, 30000, 9000, 10000, 120000 };
	int K = 1000000000;
	int answer = 0;

	std::priority_queue<int,std::vector<int>,std::greater<int>> scoville_queue(scoville.begin(),scoville.end());

	while (K < scoville_queue.top())
	{

		if (scoville_queue.size() == 1)
		{
			answer = -1;
			break;
		}
		int smallest = scoville_queue.top();
		scoville_queue.pop();

		int second = scoville_queue.top();
		scoville_queue.pop();

		scoville_queue.push(smallest + second * 2);

		++answer;

	}

	printf("answer = %d ", answer);

	printf("\n");	
	
	for (int i = 0; !scoville_queue.empty(); i++)
	{
		printf("%lu, ", scoville_queue.top());
		scoville_queue.pop();
	}
	printf("\n");

}


bool Programmers_CompareCombineNumber(int i,int j)
{
	int JI = 0;
	if (i == 1000)
	{
		JI += j * 10000;
		JI += i;
	}
	else if (i < 10)
	{
		JI += j * 10;
		JI += i;
	}
	else if (i < 100)
	{
		JI += j * 100;
		JI += i;
	}
	else if (i < 1000)
	{
		JI += j * 1000;
		JI += i;
	}

	int IJ = 0;
	if (j == 1000)
	{
		IJ += i * 10000;
		IJ += j;
	}
	else if (j < 10)
	{
		IJ += i * 10;
		IJ += j;
	}
	else if (j < 100)
	{
		IJ += i * 100;
		IJ += j;
	}
	else if (j < 1000)
	{
		IJ += i * 1000;
		IJ += j;
	}
	return JI < IJ;
}

void Programmers_BiggestNumber()
{
	/*
	* 우선순위 priority
	* 999
	* 99
	* 9
	* 998~990
	* 98
	* 989 988
	* 97
	* 899
	* 89
	* 898
	* 자리수가 높으면 우선순위가 낮고
	* 자리수가 다르지만 앞에 숫자가 같으면 
	* 두수의 앞자리가 같아도 두 앞자리보다 큰 뒷자리수가 있으면 우선순위가 높아진다.
	* 768, 76
	* 768.76
	* 76.768
	* 78, 7, 
	* 78.7
	* 7.78
	* 기수정렬을 해야하나?
	* 321 4
	* 322 3
	* 324 1
	* 32  2
	* 31  5
	* 
	*/

	vector<int> numbers = {0,0,0};
	if (std::all_of(numbers.begin(), numbers.end(), [](int i) {return i == 0;}))
	{

	}

	std::string answer = "";

	std::sort(numbers.begin(), numbers.end(), Programmers_CompareCombineNumber);

	std::stringstream NumbersStream;

	for (auto i = numbers.begin(); i < numbers.end(); i++)
	{
		NumbersStream << *i;
	}
	printf("%s\n", NumbersStream.str().c_str());
	
	std::sort(numbers.begin(), numbers.end(), Programmers_CompareCombineNumber);
}


//소수 찾기
//자리수에 맞게 소수만 찾으면 되지 않을까 싶다.
//0일때 체크

void Programmers_FindPrimeNumber()
{
	std::string numbers;
	int answer = 0;
	
	std::vector<int> intnumbers;
	
	std::set<int> PrimeNumberCount;

	for (int i = 0; i < numbers.size(); i++)
	{
		intnumbers.push_back(numbers[i] - '0');
	}
	
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int k = 0; k < numbers.size(); k++)
		{

		}
	}

	answer = PrimeNumberCount.size();

}

void Programmers_InsufficientPrice()
{
	long price = 2500;
	long money = 100000000;
	long count = 2500;

	long long answer = count* (count + 1) / 2 ;
	answer *= price;
	answer -=money;
	if (answer	< 0)
	{
		answer = 0;
	}
}

void Programmers_ReportID()
{
	std::vector<std::string> id_list = { "muzi", "frodo", "apeach", "neo" };
	std::vector<std::string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
	int k = 2;

	std::vector<int> answer = std::vector<int>(id_list.size());

	std::map<std::string, std::set<std::string>> Distribut_ID;

	/*

	누가누구를 신고했는가?
	신고당한 사람은 K를 넘겼는가?
	누구한테 메일을 보내야하는지?
	*/
	for (auto i : report )
	{
		std::stringstream StreamReportId;
		StreamReportId.str(i);

		std::string id;
		std::string reportid;
		StreamReportId >> id;
		StreamReportId >> reportid;

		Distribut_ID[reportid].insert(id);
	}

	for (auto i : Distribut_ID)
	{
		if (k > i.second.size())
		{
			continue;
		}
		for (auto n : i.second)
		{
			auto id_element = std::find(id_list.begin(), id_list.end(), n);
			++answer.at(std::distance(id_list.begin(), id_element));
		}

	}

}

void Programmers_StringNumber()
{
	std::string s = "one4seveneight";

	std::map<std::string, int> stingnummap
		= { {"zero",0},{"one",1}, {"two",2}, {"three",3}, {"four",4}, {"five",5}, {"six",6}, {"seven",7}, {"eight",8}, {"nine",9} };

	int answer = 0;

	for (int i = 0; i < s.size(); i++)
	{
		int num = 0;
		if ('9' >= s.at(i))
		{
			num = s.at(i) - '0';
		}
		else
		{
			std::string stringnum;
			while (true)
			{
				stringnum.push_back(s.at(i));
				if (stingnummap.find(stringnum) != stingnummap.end())
				{
					num = stingnummap[stringnum];
					break;
				}
				i++;
			}
		}
		answer = answer * 10 + num;
	
	}
	printf("answer %d \n", answer);
}


//없는 숫자
void Programmers_WithoutNumber()
{
	vector<int> numbers = { 1,2,3,4,6,7,8,0 };

	// 0~9 = 45
	int answer = std::accumulate(numbers.begin(), numbers.end(), 0);
	printf("%d\n", answer);
}

//문자열 압축
void Programmers_CompressionString()
{
	std::string s = "abcabcdede";
	std::string compressstring;

	int answer = s.size();
	
	int halflength = s.size() / 2;
	for (int i = 1;i<= halflength;i++)
	{

		std::string substring = s.substr(0, i);
		int repetitioncount = 0;

		for (int k = i; k < s.size() ;k += i)
		{

			if (s.substr(k, i).compare(substring) == 0)
			{
				++repetitioncount;
				continue;
			}

			if (repetitioncount > 0)
			{
				compressstring.append(std::to_string(repetitioncount + 1));
			}

			compressstring.append(substring);
			substring = s.substr(k, i);
			repetitioncount = 0;
		}

		if (repetitioncount > 0)
		{
			compressstring.append(std::to_string(repetitioncount + 1));
		}
		compressstring.append(substring);

		printf("Candidate %d : %s\n", i, compressstring.c_str());
	
		if (answer > compressstring.size())
		{
			answer = compressstring.size();
		}

		compressstring.clear();

	}
	
}

void Programmers_OpenChatting()
{
	/*
	* Change를 찾아서 id 번호의 닉네임을 매칭해놓는다.
	* change를 찾을경우 문자열에서 뺀다.
	* enter와 leave도 매칭을 해놓는다.
	* change에서 닉네임이 변하지 않은 나중에 enter와 leave를 매칭할때 id변화와 닉네임을 매칭해놓은 map에 추가해놓는다.
	*/

	std::vector<std::string> record{ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	std::vector<std::string> answer{};

	std::vector<std::string> ActionList{};
	std::vector<std::string> IDList{};

	std::map<std::string, std::string> MapNickname{};
	std::map<std::string, std::string> MapAction{ {"Enter","님이 들어왔습니다."}, {"Leave","님이 나갔습니다."} };

	for (auto i : record)
	{
		std::stringstream RecordStream{i};
		
		std::string Action{};
		std::string UserID{};
		std::string Nickname{};

		RecordStream >> Action;
		RecordStream >> UserID;

		if (MapAction.find(Action) != MapAction.end())
		{
			IDList.push_back(UserID);
			ActionList.push_back(MapAction[Action]);
		}
		
		RecordStream >> Nickname;
		if (Nickname.compare("") != 0)
		{
			MapNickname[UserID] = Nickname;
		}
	
	}
	for (int i = 0; i < ActionList.size();i++)
	{
		answer.push_back(MapNickname[IDList.at(i)] + ActionList.at(i));
	}

	for (auto i : answer)
	{
		printf("%s\n", i.c_str());
	}

}

//짝지어 제거하기
void Programmers_PairDelete()
{
	std::string s{ "ca" };
	int answer = -1;

	/*
	* 문자열에서 같은 알파벳이 2개 붙어있는 짝을 찾아서 문자열 모두를 제거가능하지 리턴해야한다.
	* 문자열 쌍을 찾는 방법은 for문이 생각난다.
	* unique의 경우 문자가 하나 남기 때문에 소용없다.
	* 모두 같은 문자일경우
	* list를 이용했지만 이게 아닌것 같다.
	* 에러도 뜨고 시간초과도 된다.
	*/
	//erase를이용한 s제거
	//for (auto i = s.begin(); i < s.end()-1;)
	//{
	//
	//	if (*i == *(i+1))
	//	{
	//		printf("%c == %c\n", *i, *(i + 1));
	//		std::swap(s.back(),i)
	//		i = s.erase(std::remove(i , i + 1,*i),s.end());
	//		--i;
	//		continue;
	//	}
	//
	//	++i;
	//
	//	printf("s = %s\n", s.c_str());
	//}
	//
	//if (s.size() > 0)
	//{
	//	answer = 0;
	//}
	/*
	list를 이용한 방법
	std::list<char> li { s.begin(),s.end() };
	auto after = li.begin();
	auto befor = after;
	++after;

	for (; after != li.end();)
	{
		if (*befor == *after)
		{
			li.
			std::remove(befor, ++after,*befor);
			continue;
		}
	for (auto k = li.begin(); k != li.end();k++)
	{
		printf("%c", *k);
	}
	printf("\n");

		befor = after;
		++after;
	}
	*/

	/*굳이 지울필요 없이 befor과 after의 가장 멀리 간 위치를 확인하고 좌우 끝일경우 true를 리턴하자
	for (auto after = s.begin() + 1, previous = s.begin(); after < s.end();)
	{
		if (*previous == *after)
		{
			if (previous != s.begin())
			{
				--previous;
			}
			++after;
			continue;
		}


		previous = after;
		++after;
	}
	printf("Left = %d, Right = %d\n", std::distance(s.begin(), LeftMost), std::distance(s.begin(), RightMost));
	*/

	/*
	std::string::iterator  previous = s.begin();
	std::string::iterator after = previous + 1;
	while (after < s.end())
	{

		if (*previous == *after)
		{
			*previous = ' ';
			*after = ' ';
		}

		if (*previous != ' ')
		{
			previous = after;
		}
		++after;
		while (*previous == ' ' && previous != s.begin())
		{
			--previous;
		}
	}

	if (previous != s.begin() || after != s.end())
	{
		answer = 0;
	}
	*/

	std::vector<char> clist;
	clist.push_back(s.back());
	s.pop_back();
	
	while (s.size() > 0)
	{
		char ch = clist.back();
		clist.push_back(s.back());
		s.pop_back();
		if(ch == clist.back())
		{
			clist.pop_back();
			clist.pop_back();
		}

	}

}

void MinimumRectangle()
{
	vector<vector<int>> sizes{ {60, 50} ,{30, 70},{60, 30},{80, 40} };
	int answer = 0;
	int Bigger[2] = { 0,0 };
	for (auto i : sizes)
	{
		if (i.front() < i.back())
		{
			std::swap(i[0], i[1]);
		}
		Bigger[0] = Bigger[0] < i.front() ? i.front() : Bigger[0];
		Bigger[1] = Bigger[1] < i.back() ? i.back() : Bigger[1];
	}
	answer = Bigger[0] * Bigger[1];
}

//최대값 최소값문제
void Programmers_MaxMin()
{
	std::string s = { "-1 -2 -3 -4" };

	std::stringstream TransNumber{ s };

	std::set<int> numbers;

	while (!TransNumber.fail())
	{
		int number;
		TransNumber >> number;
		numbers.insert(number);
	}

	std::string answer = std::to_string(*numbers.begin()) + ' ' + std::to_string(*numbers.rbegin());

	printf("answer = %s", answer.c_str());
}

//삼총사 문제
void Programmers_ThreeMusketeer()
{
	std::vector<int> number{ -1, 0, 1, 1,1,1 };

	int answer = 0;

	std::sort(number.begin(), number.end());
	for (int i = 0; i < number.size() - 2; i++)
	{
		for (int k = i + 1; k < number.size() - 1; k++)
		{
			for (int m = k + 1; m < number.size(); m++)
			{
				int sum = (number.at(i)) + (number.at(k)) + (number.at(m));
				if (sum > 0)
				{
					break;
				}
				else if (sum == 0)
				{
					++answer;
				}

			}
		}
	}
	std::cout << "answer = " << answer << std::endl;
	return;
	//프로그래머스 다른 정답

	std::vector<bool> check(number.size());

	std::fill_n(check.begin(), 3, false);
	std::fill_n(check.begin() + 3, number.size() - 3, true);
	do {
		int sum = 0;
		for (int i = 0; i < check.size(); i++) {
			if (!check[i])
				sum += number[i];
		}
		if (sum == 0)
			answer++;
	} while (std::next_permutation(check.begin(), check.end()));

}
//최소값 만들기
void Programmers_MakeMinValue()
{
	std::vector<int> A = { 1,2 };
	std::vector<int> B = { 3,4 };
	int answer = 0;

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end(), std::greater<int>());

	for (int i = 0; i < A.size(); i++)
	{
		answer += A[i] * B[i];
	}

	std::cout << answer << std::endl;
}

//코크 문제
void Programmers_Coke()
{
	int a = 3;
	int b = 2;
	int n = 20;

	int answer = 0;

	while (n >= a)
	{
		answer += n / a * b;
		n = (n / a * b) + n % a;
	}

	return;

	//프로그래머스 또 다른 정답 이게 정답이라고 생각합니다.
	answer = (n > b ? n - b : 0) / (a - b) * b;
}

//레벨 1 첫번째 문제
void Programmers_Level1()
{
	vector<vector<int>> arr1{ { 1,2 }, { 2, 3 } };
	vector<vector<int>> arr2{ { 3,4 }, { 5,6 } };

	vector<vector<int>> answer;

	for (int i = 0; i < arr1.at(0).size(); i++)
	{

		int sum = 0;
		answer.push_back(std::vector<int>());
		for (int k = 0; k < arr1.size(); k++)
		{
			answer.back().push_back(arr1[i][k] + arr2[i][k]);
		}

	}

}

//레벨 1 두번째 문제
void Programmers_Level1_2()
{

	std::string s = "Zbcdefg";
	std::sort(s.begin(), s.end(), std::greater<>());

	std::cout << s << std::endl;

	std::string answer = "";

}

//숫자의 표현
void Programmers_NumberExpression()
{
	int n = 0;
	int answer = 1;
	
	if (n < 3)
	{
		answer = 1;
		return;
	}

	int num = n - 3;
	if (num % (2) == 0)
	{
		++answer;
	}

	for (int i = 3; n >= i; i++)
	{
		num -= i;
		if (num %(i) == 0)
		{
			++answer;
		}
	}
}
//다음 큰 숫자
void Programmers_NextBetterNumber()
{
	int n = 78;
	int answer = n;

	int add = 1;
	int one = 0;

	while (n > 0)
	{
		if (n % 2 == 1)
		{
			one = one << 1;
			++one;
		}
		else
		{
			if (one == 0)
			{
				add = add << 1;
			}
			else
			{
				break;
			}
		}

		n = n >> 1;
	}

	one = one >> 1;
	answer += add + one;

	std::cout << "answer = " << answer << std::endl;
}

//카펫
void Programmers_Carpet()
{
	int brown = 8;
	int yellow = 1;
	vector<int> answer;
	int halfRow = std::ceil(std::sqrt(yellow));

	for (int i = 1; i <= halfRow; i++)
	{
		if (yellow % i > 0)
			continue;
		int total = (yellow / i + i) * 2 + 4;
		if (total == brown)
		{
			int Columns = yellow / i + 2 ;
			int Row = i + 2;
			
			answer.push_back(Columns);
			answer.push_back(Row);

			break;
		}
	}
}

//영어 끝말잇기
void Programmers_WordRelay()
{
	int n = 3;
	std::vector<std::string> words{ "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };

	std::vector<int> answer{0,0};
	
	std::set<std::string> indexword{ words.front()};

	for (int i = 1; i < words.size(); i++)
	{

		std::string Word = words.at(i);
		if (indexword.find(Word) == indexword.end() 
			&& words.at(i - 1).back() == Word.front())
		{
			indexword.insert(Word);
		}
		else
		{
			answer.at(0) = i % n + 1;
			answer.at(1) = i / n;
			break;
		}
		

	}


}

//구명보트
void Programmers_Lifeboat()
{
	std::vector<int> people = { 70, 50, 80, 50 };
	int limit = 100;

	std::sort(people.begin(), people.end(),std::greater<int>());
	int answer = 0;

	int i = 0;
	for (int i = 0; i < people.size(); i++)
	{
		int sum = people.at(i);
		for (int k = i+1; k < people.size(); k++)
		{
			sum += people.back();
			if (sum > limit)
			{
				break;
			}
			people.pop_back();
		}
		++answer;
	}
}

void Programmers_FoodFight()
{
	std::vector<int> food = {1,2,4,8};

	std::string answer = "0";
	for (int i = food.size() - 1; i > 0; --i)
	{
		std::string Foods(food.at(i) / 2, (char)('0' + i));
		answer = Foods + answer + Foods;
	}
}

void Programmers_LongJump() {
	int n = 2000;
	long long answer = 1;

	long long a = 1, b = 1;
	for (int i = 2; i <= n; i++)
	{
		answer = (a + b) % 1234567;
		a = b;
		b = answer;
	}

	std::cout << answer << ", ";
	std::cout << std::endl;
}


//예상 대진표
void Programmers_Tournament()
{
	int n = 16;
	int a = 12;
	int b = 14;
	int answer = 0;

	std::bitset<20> bit(n - 1);

	answer = bit.count();
	
	for (int i = n / 4,k = n /2; 0 < i; i /= 2)
	{
		if (a > k && b > k)
		{
			k += i;
		}
		else if (a <= k && b <= k)
		{
			k -= i;
		}
		else
		{
			break;
		}

		--answer;
	}

	std::cout <<"answer = " << answer << std::endl;
}

void Programmers_HIndex()
{
	std::vector<int> citations = {100,100,100,100,100 };
	std::sort(citations.begin(), citations.end());
	int answer = 0;

	for (int i = 0; i < citations.size();i++)
	{
		if (citations.at(i) < citations.size() - i)
		{
			continue;
		}

		answer = citations.size() - i;
		break;
	}
}

//망할 소문자도 나오는 거냐고
void Programmers_Cach()
{
	int cacheSize = 2;
	std::vector<std::string> cities = { "Jeju", "Pangyo", "NewYork", "newyork"};
	int answer = 0;

	std::vector<std::string> caches;

	for (auto i = cities.begin(); i < cities.end(); i++)
	{
		auto cache = std::find(caches.begin(), caches.end(),*i);

		if (cache != caches.end())
		{
			++answer;
			caches.erase(cache);
			caches.push_back(*i);
		}
		else
		{
			answer += 5;
			caches.push_back(*i);
		}

		if (caches.size() > cacheSize)
		{
			caches.erase(caches.begin());
		}
	}
	std::cout << "answer = " << answer << std::endl;
}

//회전하는 괄호
void Programmers_RotatingBracket()
{
	std::string s = "[](){}";
	int answer = 0;
	const int StringSize = s.size();


	for (int i = 0; i <= StringSize; i++)
	{
		std::string stack;
		++answer;
		for (auto k = s.begin() + i; k != s.end(); k++)
		{
			if (*k == '[' || *k == '{' || *k == '(')
			{
				stack.push_back(*k);
			}
			else if (!stack.empty() && std::abs(*k - stack.back()) < 3)
			{
				stack.pop_back();
			}
			else
			{
				if (stack.empty())
				{
					--answer;
				}
				break;
			}
		}
		if (!stack.empty())
		{
			--answer;
		}
		s.push_back(s.at(i));
	}

	std::cout << " s = " << s << std::endl;
	std::cout << " answer =  " << answer << std::endl;
}

//행렬 곱셈
void Programmers_MultiplicationMatrix()
{
	vector<vector<int>> arr1 = { {1, 4}};
	vector<vector<int>> arr2 = {{1,2, 3}, { 4,5,6 }};
	
	vector<vector<int>> answer( arr1.size(), vector<int>(arr2.front().size()));

	for (size_t i = 0; i < answer.size(); i++)
	{
		for (size_t k = 0; k < answer.front().size(); k++)
		{
			int sum = 0;
			for (size_t n = 0; n < arr1.front().size(); n++)
			{
				sum += arr1[i][n] * arr2[n][k];
			}
			answer[i][k] = sum;
		}
	}


	
}

void Programmers_Tuple()
{
	std::string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	std::vector<int> answer;

	std::stringstream trans_num(s);

	int sum = 0;

	char ch;
	int num = 0;

	trans_num >> ch;
	while (true)
	{

		trans_num >> ch;
		if (ch == '}')
		{
			if (sum > 0)
			{
				answer.push_back(sum);
				sum = 0;
			}
			trans_num >> ch;
			if(ch == '}')
			{
				break;
			}
			trans_num >> ch;
		}

		trans_num >> num;
		if (num != 0)
		{
			sum += num;
		}
	}

}

//못 푼 문제

// 컬러링북
void Programmers_ColoringBook()
{
	int m = 0; int n = 0;
	vector<vector<int>> picture = { {1,2},{3,4} };
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	/*
	* 두가지 이중배열을 만든다
	* 하나는 전체를 검사하는 채크리스트
	* 두번째는 현재 검사하고여 같은색깔을 채크하는 리스트
	* 
	* for문의 경우 전체를 도는 큰 for문과 4방을 검사하는 for문을 검사합니다.
	* 
	* 반복자를 통해 서 row가 이동하면 column도 이동시키고싶었지만 안된다.
	*/
	
	for (int row = 0,column = 0; row < m && column < n;)
	{

	}

}

//단체 사진
void Programmers_GroupPoto()
{

}

int Programmers_DeepFirstSearch(std::vector<int> Numbers, int Starting,int Sub, int Accum, int Target)
{
	int SameCount = 0;
	for (int i = Starting;i< Numbers.size();i++)
	{
		//곱을 해줘야 뺄셈의 총합이 됩니다.
		int SubSum = (Sub + Numbers.at(i));

		if (Accum - SubSum * 2 > Target)
		{
			SameCount += Programmers_DeepFirstSearch(Numbers, i+1, SubSum, Accum, Target);
		}
		
		if(Accum - SubSum * 2 == Target)
		{
			++SameCount;
		}

	}
	return SameCount;
}
//타겟넘버
void Programmers_TargetNumber()
{
	/*깊이 / 너비 우선 탐색
	* numbers에 -2를 곱해 전체 주를 빼가며 값을 구하려고한다.
	*/

	std::vector<int> numbers = {4,1,2,1};
	int target = 4;
	int answer = 0;
	
	int accum = std::accumulate(numbers.begin(), numbers.end(), 0);

	/*
	* 깊이로 들어가는 로직
	* 다시 뒤로 갈수도 있어야한다
	* 
	* 한 원소를 선택한다.
	* 그 원소에서 기준으로 오른쪽수들을 합쳐서 뺸다.
	* 만약 뺀 값이 타겟과 같거나 작을경우 다음 값으로 넘어간다.
	* 
	* 지금 실행할 원소 위치
	* 
	*/

	/*
	int MinusSum = 0;
	for (int i = 0; i < numbers.size();)
	{
		for (int k =i; k < numbers.size();)
		{
			MinusSum -= numbers.at(k);

			if (NumversSum + MinusSum * 2> target)
			{
			}
			else
			{

				if (NumversSum + MinusSum * 2 == target)
				{
					++answer;
				}

				MinusSum += numbers.at(k);
				i++;
			}
			i++;
		}
	}
	*/
	printf("Count = %d \n",Programmers_DeepFirstSearch(numbers, 0, 0, accum, target));
}

//위장
void Programmers_Camouflage()
{
	/*
	* 옷들의 값을 하나씩 종류별를 구분합니다.
	* 중복된 옷의 종류가 있을경우 카운트를 샙니다.
	*/
	std::vector<std::vector<std::string>> clothes{
		{"yellow_hat", "headgear"}
	,{"blue_sunglasses", "eyewear"}
		,{"green_turban", "headgear"} };

	std::map<std::string, int> clothetype;

	int answer = 0;

	for (auto Cloth : clothes)
	{
		++clothetype[Cloth.back()];
	}

	//비트를 사용해서 해봅시다.

	int bitsize = 1 << clothetype.size();
	for (int i = 1;i < bitsize;i++)
	{
		int mull = 1;
		auto it = clothetype.begin();
		for (int k = 0;k< clothetype.size();k++)
		{
			int bit = 1 << k;
			if (i < bit)
			{
				break;
			}

			if (i & bit)
			{
				mull *= it->second;
			}
			++it;
		}
		answer += mull;

	}

	printf("answer = %d\n", answer);

}

void Pokemon() {
	std::string new_id{ "...!@BaT#*..y.abcdefghijklm" };
	std::string answer = "";

	char Previous = new_id.at(0);
	for (int i = 1; i < new_id.size(); i++)
	{
		if ('A' <= new_id.at(i) && new_id.at(i) <= 'Z')
		{
			new_id.at(i) = std::tolower(new_id.at(i));
		}
		else if ('a' <= new_id.at(i) && new_id.at(i) <= 'z')continue;
		else if ('0' <= new_id.at(i) && new_id.at(i) <= '9')continue;
		else if ('-' == new_id.at(i))continue;
		else if ('_' == new_id.at(i)) continue;
		else if ('.' == new_id.at(i) && Previous != new_id.at(i))continue;

		//문자열을 삭제한다.
		new_id.erase(new_id.begin() + i);

		Previous = new_id.at(i-1);
	}

	if (new_id.back() == '.')
	{
		new_id.pop_back();
	}

	if (new_id.size() > 15)
	{
		new_id = new_id.substr(0, 15);
	}
	else 
	{
		while (new_id.size() < 3)
		{
			new_id.push_back('a');
		}
	}
	answer = new_id;
}

void Programmers_Parenthesis()
{
	std::string s;
	bool answer = true;

	std::stack<char> Parentesis;

	for (auto& i : s)
	{
		if (i == ')')
		{
			if (Parentesis.size() > 0)
			{
				Parentesis.pop();
				continue;
			}
			else
			{
				answer = false;
				break;
			}
		}
		Parentesis.push(i);
	}
	if (Parentesis.size() > 0)
	{
		answer = false;
	}
}

void Programmers_Remainder()
{
	int n = 54;
	int answer = 0;

	if (n % 2 == 1)
	{
		answer = 2;
	}
	else
	{
		for (int i = 3; i * i <= n - 1; i += 2)
		{
			if ((n - 1) % i == 0)
			{
				answer = i;
				break;
			}
		}
	}
	if (answer == 0)
	{
		answer = n - 1;
	}
}

