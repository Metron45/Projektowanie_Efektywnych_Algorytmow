// Projektowanie_Efektywnych_Algorytmow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Test_Zad2.h"
#include "Simulated_Annealing.h"
#include <windows.h>


int main()
{
	//gr21 : 2707
	Simulated_Annealing matrix;
	matrix.load_from_file("gr21.tsp");
	matrix.Set_temperature(10, 0.997, 1, 5000);
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		std::cout << matrix.Calculate() << std::endl;
	}
	//Test test;
	//test.test_menu();

	Test_Zad2 test;
	//test.time_test_Simulated_Annealing("gr21.tsp", 50, 0.99, 10, 50);
	//std::cout << test.error_rate("att48.tsp", 10640) << std::endl;
	//test.Test_Simulated_Annealing_grid(50, 50, 50, 50);
	//test.Test_Simulated_Annealing("gr17.tsp",10, 0.999, 1, 500, 0, 500, 0.00010);

	system("pause");
}

