#include "Programers.h"


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