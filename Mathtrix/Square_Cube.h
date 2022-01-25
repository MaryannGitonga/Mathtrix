#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


class Square_Cube
{
public:
	Square_Cube();
	~Square_Cube();

	int op1;
	string operation;
	string ans, ans1, ans2;
	string randomised_ans[3];
	string output_ans;
	int get_operands();
	int get_square();
	int get_cube();

private:

};

Square_Cube::Square_Cube()
{
}

int Square_Cube::get_operands() {
	srand(time(0));
	Square_Cube::op1 = 1 + rand() % 8;
	return 0;
}


int Square_Cube::get_square() {
	get_operands();

	Square_Cube::operation = to_string(op1) + " ^2 ";

	Square_Cube::ans = to_string(op1 * op1);
	Square_Cube::ans1 = to_string(op1 * op1 + 1);
	Square_Cube::ans2 = to_string(op1 * op1 - 1);

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

	Square_Cube::output_ans = "(1) " + randomised_ans[0] + "    (2) " + randomised_ans[1] + "    (3) " + randomised_ans[2];

	return 0;
}

int Square_Cube::get_cube() {
	get_operands();

	Square_Cube::operation = to_string(op1) + " ^3 ";

	Square_Cube::ans = to_string(op1 * op1 * op1);
	Square_Cube::ans1 = to_string(op1 * op1 * op1 + 1);
	Square_Cube::ans2 = to_string(op1 * op1 * op1 - 1);

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

	Square_Cube::output_ans = "(1) " + randomised_ans[0] + "    (2) " + randomised_ans[1] + "    (3) " + randomised_ans[2];

	return 0;
}

Square_Cube::~Square_Cube()
{
}