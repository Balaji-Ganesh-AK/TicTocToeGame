#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

namespace tictoc {
	
class mat
	{
	
	public :
	
		 std::string strmat[3][3];
		 int listarr[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
		 int win_flag;
		int count = 1;
		char ch;
		
		int temp;
		
		void set_mat();// setting the values of the first matrix
		void print();// print the values;
		void run();
		int win_check();
		void win_condition_row();
		void win_condition_column();
		void win_condition_diagonal_LR();
		void win_condition_diagonal_RL();
		
		void  get_input(int round_turn);
		void check(int ch_p,char var_p);
		void change(int ch_pp, char var_pp);
	
		
	};

}
		 
			
	
		

