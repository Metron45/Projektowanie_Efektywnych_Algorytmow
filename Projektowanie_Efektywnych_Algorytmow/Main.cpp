// Projektowanie_Efektywnych_Algorytmow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Distance_Graph.h"
#include "Bruteforce.h"
#include "Dynamic.h"
#include "Bound_And_Branch.h"

int main()
{
	//Bruteforce matrix;
	//Dynamic matrix;
	Bound_And_Branch matrix;

	//matrix.load_from_file("test8.tsp");
	matrix.load_from_file("test10.tsp");
	//matrix.load_from_file("gr24.tsp");
	//matrix.load_from_file("gr17.tsp");
	matrix.write_results();

	int a;
	std::cin >> a;
}

