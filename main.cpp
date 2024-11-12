#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main() {
	list<const char*> lst = { 
		"Tokyo", "Kanda", "Akihabara","Okachimachi","Ueno",
	     "Uguisudani","Noppori","Tabata","Komagome","Sugamo",
		 "Otuka","Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo",
	     "shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu",
	     "Meguro","Gotanda","Osaki","Shinagawa","Tamachi",
	     "Hamamathucho","Shimbashi","Yurakucho"
	};

	printf("1970\n");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		cout << *itr << ",";
	}
	std::cout << std::endl;

	for (list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == "Tabata") {
			itr = lst.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}
	printf("2019\n");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		cout << *itr << ",";
	}
	std::cout << std::endl;

	for (list<const char*>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == "Tamachi") {
			itr = lst.insert(itr, "Takanawa-Gateway");
			++itr;
		}
	}
	printf("2022\n");
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		cout << *itr << ",";
	}
	std::cout << std::endl;

	return 0; 
}