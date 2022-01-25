#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Square_Root
{
public:
	Square_Root();
	~Square_Root();

	int op1;
	string operation;
	string ans, ans1, ans2;
	string randomised_ans[3];
	string output_ans;
	int get_operands();
	int get_root();

private:

};

Square_Root::Square_Root()
{
}

int Square_Root::get_operands() {
	srand(time(0));
	int x = (1 + rand() % 11);
	Square_Root::op1 = x * x;
	return 0;
}


int Square_Root::get_root() {
	get_operands();

	Square_Root::operation = "Square root of " + to_string(op1);

	Square_Root::ans = to_string((int)sqrt(op1));
	Square_Root::ans1 = to_string((int)sqrt(op1) + 1);
	Square_Root::ans2 = to_string((int)sqrt(op1) - 1);

	srand(time(0));
	int n = 1 + rand() % 3;
	if (n == 1)
	{
		randomised_ans[2] = ans;
		randomised_ans[1] = ans1;
		randomised_ans[0] = ans2;
	}
	else if (n == 2)
	{
		randomised_ans[0] = ans;
		randomised_ans[2] = ans1;
		randomised_ans[1] = ans2;
	}
	else {
		randomised_ans[1] = ans;
		randomised_ans[0] = ans1;
		randomised_ans[2] = ans2;
	}

	Square_Root::output_ans = "(1) " + randomised_ans[0] + "    (2) " + randomised_ans[1] + "    (3) " + randomised_ans[2];

	return 0;
}

Square_Root::~Square_Root()
{
}
