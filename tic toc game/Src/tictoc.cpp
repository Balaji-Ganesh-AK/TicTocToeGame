#pragma once 
#include "tictoc.h"
using namespace tictoc;

void mat::set_mat()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			strmat[i][j] = std::to_string(count);
			count++;
		}
		
		}
	}

void mat::print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << strmat[i][j]<<" " ;
		}
		std::cout << "" << std::endl;
	}
}

void tictoc::mat::run()
{
	int i = 0;
	int val = 0;
	
	set_mat();
	while (val == 0)

	{

		print();
		get_input(i);

		val = win_check();
		i++;

		if (i == 9)
		{
			std::cout << "Its a draw!!!" << std::endl;
			val = -1;
		}

	}
}

int tictoc::mat::win_check()
{
	win_flag = 0;
	win_condition_row();
	win_condition_column();
	win_condition_diagonal_LR();
	win_condition_diagonal_RL();
	
	return win_flag;
}

void tictoc::mat::win_condition_row()
{
	for (int i = 0; i < 3; i++)
	{
		if (strmat[i][0] == strmat[i][1]&&strmat[i][1] == strmat[i][2])
		{

			std::cout << "winner is " << strmat[i][0] << "!!!" << std::endl;
			win_flag = -1;
			break;
		}
	}
}

void tictoc::mat::win_condition_column()
{
	for (int i = 0; i < 3; i++)
	{
		if (strmat[0][1] == strmat[1][i] && strmat[1][i] == strmat[2][i])
		{

			std::cout << "winner is " << strmat[i][0] << "!!!" << std::endl;
			win_flag = -1;
			break;
		}
	}
}

void tictoc::mat::win_condition_diagonal_LR()
{
	if (strmat[0][0] == strmat[1][1] && strmat[1][1] == strmat[2][2])
	{

		std::cout << "winner is " << strmat[1][1] << "!!!" << std::endl;
		win_flag = -1;
	}
}

void tictoc::mat::win_condition_diagonal_RL()
{

	if (strmat[0][2] == strmat[1][1] && strmat[1][1] == strmat[2][0])
	{

		std::cout << "winner is " << strmat[1][1] << "!!!" << std::endl;
		win_flag = -1;
	}
}

void mat::get_input(int round_turn)// Getting the place from the user to change it.
{

	static int ch;
	temp = round_turn;
	
	if (round_turn % 2 == 0)
	{

		std::cout << "Enter the position to place X";
		std::cin >> ch;
		check(ch, 'x');
	}
	else
	{

		std::cout << "Enter the position to place O";
		std::cin >> ch;
		check(ch, 'O');

	}

}

void mat::check(int ch, char var)
{
	
	static int index_cout=-1;
	int flag = 0;
	for (int i = 0; i < 9; i++)
	{
		//std::cout << listarr[i] << std::endl;
		if (listarr[i]==ch)
		{
			flag = -1;
			break;
			
		}
		
	}
	if (flag == -1)
	{
		std::cout << "The value has been changed already. Please select a new value" << std::endl;
		get_input(temp);
	}
	else
	{
		index_cout++;
		listarr[index_cout] = ch;

		//std::cout << "The value is changed now !!" << ch << std::endl;
		change(ch, var);

	}
	}
		
void mat::change(int ch, char var)
{
	int c = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c++;
			if (ch == c)
			{
				strmat[i][j] = var;
			}
		}
	}

}






		







