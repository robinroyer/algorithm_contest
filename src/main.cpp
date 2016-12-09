#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <time.h>
#include <math.h>
#include <pthread.h>

#include "parser.hpp"
#include "company.hpp"
#include "solution.hpp"
#include "Foncteurs.hpp"
#include "table.hpp"

#define NUM_THREADS     4

static void *genetiquerecuit(Solution * arg) {

	Solution solution;
	solution = *arg;

	int iteration = 0;
	float T = 10.0;
	float diff = 0.0;
	float pi = 0.0;

	Solution bestSol = solution;
	float bestCost = solution.computeCostFunction();
	std::vector<Solution*> population;
	int arret = 0;
	while (arret<10) {
		int fin = 1;
		while (iteration < 2000) {
			Solution post = solution;
			int prob = rand() % 2;
			if (prob == 1) {
				solution.randomMove();
			}

			else {
				solution.stdMove();
			}

			diff = solution.computeCostFunction() - post.computeCostFunction();
			pi = exp(-diff / T);
			//bad solution
			if (diff > 0 && (r = ((double)rand() / (RAND_MAX))) / 100.0 < 1 - pi) {
				solution = post;
			}
			iteration++;
			T = T * 0.99;
			if (solution.computeCostFunction() < bestCost) {
				bestSol = solution;
				bestCost = solution.computeCostFunction();
				bestSol.printSolution();
				population.push_back(new Solution(bestSol));
				std::cout << "BESTCOST is : " << bestCost << std::endl;
				fin = 1;
			}

		}
		arret += fin;
		if (fin == 0) {
			arret = 0;
		}
		iteration = 0;
		T = 10;
		solution = bestSol;
	}
	int taillepop = population.size();
	while (true) {
		for (int i = 0; i < taillepop; i++) {
			population.push_back(new Solution(*population[i]));
			int prob = rand() % 2;
			if (prob == 1) {
				population[i]->randomMove();
			}

			else {
				population[i]->stdMove();
			}
		}
		std::sort(population.begin(), population.end(), FoncteurCompareCostofSolutions());
		while (population.size() > taillepop) {
			population.pop_back();
		}
		if (population[0]->computeCostFunction() < bestCost) {
			bestSol = *population[0];
			bestCost = population[0]->computeCostFunction();
			bestSol.printSolution();
		}
	}

}

static void *recuit(Solution * arg ) {

	Solution solution;
	solution = *arg;

	int iteration = 0;
	float T = 10.0;
	float diff = 0.0;
	float pi = 0.0;

	Solution bestSol = solution;
	float bestCost = solution.computeCostFunction();


	while (true) {
		while (iteration < 2000) {
			Solution post = solution;
			int prob = rand() % 2;
			if (prob == 1) {
				solution.randomMove();
			}

			else {
				solution.stdMove();
			}

			diff = solution.computeCostFunction() - post.computeCostFunction();
			pi = exp(-diff / T);
			//bad solution
			if (diff > 0 && (r = ((double)rand() / (RAND_MAX))) / 100.0 < 1-pi) {
				solution = post;
			}
			iteration++;
			T = T * 0.99;
			if (solution.computeCostFunction() < bestCost) {
				bestSol = solution;
				bestCost = solution.computeCostFunction();
				bestSol.printSolution();
				std::cout << "BESTCOST is : " << bestCost << std::endl;
			}

		}
		iteration = 0;
		T = 10;
		solution = bestSol;
	}
}



int main(int argc, char* argv[])
{
	// initialize random seed: 
	srand(time(NULL));
	// Holding our threads in an array
	pthread_t threads[NUM_THREADS];
	// input file
	std::string fileName = argv[1];
	// storing all the tables
	std::vector<Table> tables;
	// storing all the companies
	std::map<int, Company*> companies;
	// parse input file and create companies and tables
	parse(fileName, companies, tables);
	// tables and companies are now filled !!!


	// init une solution
	std::vector<Company*> vectCompanies;
	for (auto it = companies.begin(); it != companies.end(); ++it)
	{
		vectCompanies.push_back(it->second); // accede à la valeur
	}

	std::sort(vectCompanies.begin(), vectCompanies.end(), FoncteurCompareSizeOfEnnemies());
	Solution initSol;
	initSol.setTables(tables);
	initSol.initSol(vectCompanies);
	initSol.printSolution();

	

	// test
	// recuit(initSol);

	// DOCUMENTATION =>
	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
			// void *(*start_routine) (void *), void *arg);
	for( int i = 0; i < NUM_THREADS; i++ ){
      	pthread_create(&threads[i], NULL, &recuit, &initSol);	// i is the arg given
	}


	// TERMINATE

	// for( int j = 0; i < NUM_THREADS; i++ ){
 //    	pthread_join(threads[i], void **);
 //   	}


	// KERNEL PANIC => we should no end as it is a time-contest
	return EXIT_SUCCESS;
}
