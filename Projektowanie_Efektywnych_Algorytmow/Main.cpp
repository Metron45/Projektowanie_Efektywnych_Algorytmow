// Projektowanie_Efektywnych_Algorytmow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Test_Zad3.h"
#include "Genetic.h"
#include <windows.h>


int main()
{
	Test_Zad3 test;
	//Genetic matrix;

	std::string name = "gr24.tsp";
	//matrix.load_from_file(name);
	
	//matrix.Initialize(50, 4, 0.6, 0.01);

	//matrix.reset();
	//matrix.Calculate(1);
	//std::cout << matrix.error_rate(name) << " " << std::endl;

	//test.set_amount_of_tests(1, 1, 10, 2);
	//test.test_population(name, 50, 50);
	//test.test_mating_pool(name, 2, 1);
	//test.test_tournament(name, 0.05, 0.05);
	//test.test_mutation(name, 0.01, 0.01);

	//test.Mass_test_population(20, 20);
	//test.Mass_test_Tournament(0.25, 0.03);
	//test.Mass_test_Mutation(0.005, 0.005);
	//test.Mass_test_Mating(4, 4);

	test.Mass_test_Final();

	//system("pause");
}

