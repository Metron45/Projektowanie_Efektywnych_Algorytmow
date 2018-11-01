// Projektowanie_Efektywnych_Algorytmow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Distance_Graph.h"
#include "Bruteforce.h"
#include "Dynamic.h"

int main()
{
	//Bruteforce matrix;
	Dynamic matrix;
	
	//matrix.load_from_file("test8.tsp");
	matrix.load_from_file("gr24.tsp");
	//matrix.load_from_file("gr17.tsp");

	matrix.draw_distance_table();
	std::cout << matrix.dynamic() << std::endl;
	//matrix.draw_route_table(2);
	std::string route = matrix.get_route();
	std::cout << route << std::endl;

	//matrix.bruteforce();
	int a;
	std::cin >> a;
}

