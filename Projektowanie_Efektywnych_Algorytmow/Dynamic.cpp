#include "stdafx.h"
#include "Dynamic.h"


Dynamic::Dynamic()
{

}


Dynamic::~Dynamic()
{
	delete[] route_table;
	route_table = NULL;
}

void Dynamic::initialize_route_table() 
{
	route_table = new long long **[1 << get_size()];
	for (int line = 0; line < (1 << get_size()); line++) {
		route_table[line] = new long long *[get_size()];
		for (int column = 0; column< get_size() ; column++) {
			route_table[line][column] = new long long[3];
			route_table[line][column][0] = -1;
			route_table[line][column][1] = -1;
			route_table[line][column][2] = -1;
		}
	}
}

int Dynamic::dynamic() {
	visited_all = (1 << get_size()) - 1;
	initialize_route_table();
	return  dynamic(1, 0);
}

int  Dynamic::dynamic(int visited, int current_city) {
	if (visited == visited_all) {
		route_table[visited][current_city][1] = 0;
		route_table[visited][current_city][2] = 0;
		return get_distance(current_city, 0);
	}
	if (route_table[visited][current_city][0] > 0) {
		return route_table[visited][current_city][0];
	}

	for (int city = 0; city < get_size(); city++) {
		if ((visited&(1 << city)) == 0) {
			int new_answer = get_distance(current_city,city) + dynamic(visited | (1 << city), city);
			if (route_table[visited][current_city][0] == -1) {
				route_table[visited][current_city][0] = new_answer;
				route_table[visited][current_city][1] = city;
				route_table[visited][current_city][2] = visited | (1 << city);
			}
			else if (new_answer < route_table[visited][current_city][0]){
				route_table[visited][current_city][0] = new_answer;
				route_table[visited][current_city][1] = city;
				route_table[visited][current_city][2] = visited | (1 << city);
			}
		}

	}
	return  route_table[visited][current_city][0];
}

void Dynamic::draw_route_table(int info_type) {
	for (int line = 0; line < std::min(1 << get_size(), 1<<8); line++) {
		std::cout << std::setw(4) << line << ": ";
		for (int column = 0; column < get_size(); column++) {
			std::cout << std::setw(4) << route_table[line][column][1];
		}
		std::cout << " || " << std::setw(4) << line << ": ";
		for (int column = 0; column < get_size(); column++) {
			std::cout << std::setw(4) << route_table[line][column][2];
		}
		std::cout << std::endl;
	}
}

std::string Dynamic::get_route() {
	std::string answer ="";
	int mask = 1, vertex = 0, new_mask,new_vertex;
	do {
		answer += " ";
		if (vertex >= 10) {
			answer += (vertex - (vertex % 10)) / 10 + '0';
			answer += (vertex % 10) + '0';
		}
		else {
			answer += vertex + '0';
		}
		new_mask   = route_table[mask][vertex][2];
		new_vertex = route_table[mask][vertex][1];
		mask = new_mask;
		vertex = new_vertex;
	} while (vertex != 0);
	return answer;
}