#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>

double GNUPLOT(std::vector<std::vector<double>>& vectorSPH, std::vector<std::vector<double>>& vectorModel, std::string graph1, std::string graph2);

void processingFile(std::string nameFile, std::vector<std::vector<double>>& vectorSPH, std::vector<double>& vectorDelta, int columnsFile);

double MODEL(
	std::vector<std::vector<double>>& vectorSPH,
	std::vector<std::vector<double>>& vectorMODEL,
	std::vector<double>& vectorDelta,
	double* KOEFFICIENTS,
	double* PARAM_MODELING,
	int FORMES,
	double PROBABLY);


double MODEL_FIX(
	std::vector<std::vector<double>>& vectorSPH,
	std::vector<std::vector<double>>& vectorMODEL,
	std::vector<double>& vectorDelta,
	double* KOEFFICIENTS,
	double* PARAM_MODELING,
	int FORMES,
	double PROBABLY);


struct PARAMETRS
{
	int columnsFile = 10;
	int metall{ 2 }; //1=al; 2=cu
	
	double veps{ 1.0e5 };

	long double deltaTime = 1.00e-12;
	long double AMOL = 26.9815386e0;
	long double pi = 3.14159265358979323846264;
	long double kA = 20e0; // annihilation koefficient
	long double kB = 1.38e-23;
	long double Ha0 = 3 * 1e-3;
	long double Hb0 = 3 * 1e-3;
	long double DNA = 6.022045000e23; //Avogadro
};
