// MODEL_C++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "header.h"

double random(double min, double max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}

int main()
{
	PARAMETRS PAR;
	int FORMES = 0;
	std::string FORMS, RADIUS, DIRECT, TEMP;
	double XX = 1.2e-3;
	double ZZ = 1.2e-3;
	double VEPS1 = 0.00e0, VEPS2 = 0.00e0;
	double TEMPERATURE = 300.00, DIAMETR = 4.00e-9, KOEF_PORE = 0.00e0;
	//koefficients
	double EPSS = 0.00, EPSS_MAX = 0.00;
	double EPSD = 0.00, EPSD_MAX = 0.00;
	double GAMMA = 0.00, GAMMA_MAX = 0.00;
	double KANIH = 0.00, KANIH_MAX = 0.00;
	double TAYLOR = 0.00, TAYLOR_MAX = 0.00;
	//veroyatnost
	double PROBABLY = 1.00e0, PROBABLY_MAX = 0.00e0, P = 1.00e0;


	//подбор коэффициентов
	for (int i = 0; i < 10000; i++)
	{
		EPSS = random(0.50, 1.50);
		EPSD = random(0.50, 1.50);
		GAMMA = random(0.50, 1.50);
		KANIH = random(1.50, 20.90);
		TAYLOR = random(0.50, 1.50);
		//EPSS = 0.674251;
		//EPSD = 1.35859;
		//GAMMA = 1.21374;
		//KANIH = 12.462;
		//TAYLOR = 0.803304;
		EPSS = 0.501251;
		EPSD = 1.06359;
		GAMMA = 1.30874;
		KANIH = 12.8492;
		TAYLOR = 0.693304;
		std::cout << "i=" << i << "   EPSS=" << EPSS << "   EPSD=" << EPSD << "   TAYLOR=" << TAYLOR << "   GAMMA=" << GAMMA << "   KANIGH=" << KANIH << std::endl;

		//форма поры
		for (int FORM = 1; FORM < 2; FORM++)
		{
			if (FORM == 1)
			{
				FORMS = "SPHERE";
				FORMES = 1;
				KOEF_PORE = PAR.pi / 6;
			}

			if (FORM == 2)
			{
				FORMS = "CUBE";
				FORMES = 2;
				KOEF_PORE = 1.00e0;
			}

			// диаметр поры
			for (int d = 1; d <= 4; d++)
			{
				if (d == 1)
				{
					XX = 1.2e-3;
					ZZ = 1.2e-3;
					RADIUS = "R06";
				}
				if (d == 2)
				{
					XX = 1.6e-3;
					ZZ = 1.6e-3;
					RADIUS = "R08";
				}
				if (d == 3)
				{
					XX = 2.0e-3;
					ZZ = 2.0e-3;
					RADIUS = "R10";
				}
				if (d == 4)
				{
					XX = 2.2e-3;
					ZZ = 2.2e-3;
					RADIUS = "R11";
				}
				
				//температура системы
				for (int T = 1; T <= 1; T++)
				{
					if (T == 1)
					{
						TEMPERATURE = 300.00e0;
						TEMP = "T300";
					}
					if (T == 2)
					{
						TEMPERATURE = 500.00e0;
						TEMP = "T500";
					}
					if (T == 3)
					{
						TEMPERATURE = 700.00e0;
						TEMP = "T700";
					}
					// направления сжатия
					for (int i = 2; i <= 2; i++)
					{
						if (i == 1)
						{
							DIRECT = "V";
							VEPS1 = PAR.veps / 3;
							VEPS2 = PAR.veps / 3;
						}
						if (i == 2)
						{
							DIRECT = "X";
							VEPS1 = PAR.veps;
							VEPS2 = 0.0e0;
						}
						std::cout << FORMS << " " << "  T=" << TEMPERATURE << "   D=" << XX / 2 << "   DIRECT=" << DIRECT << std::endl;
						//std::string nameFile{ "ANN_SPH_MM_L3_CU_SPHERE_V1D5_R11_T300_X" };
						std::string nameFile{ "ANN_SPH_MM_L3_CU_" + FORMS + "_V1D5_"+RADIUS+"_"+TEMP+"_" + DIRECT + ".txt" };

						std::vector<double> vectorDelta;
						std::vector<std::vector<double>> vectorSPH;
						std::vector<std::vector<double>> vectorModel;
						
						processingFile(nameFile, vectorSPH, vectorDelta, PAR.columnsFile);

						double KOEFFICIENTS[5] = { EPSS, EPSD, GAMMA, KANIH, TAYLOR };
						double PARAM_MODELING[6] = { VEPS1, VEPS2, TEMPERATURE, KOEF_PORE, XX, ZZ };
						
						 
						//PROBABLY = MODEL(vectorSPH, vectorModel, vectorDelta, KOEFFICIENTS, PARAM_MODELING, FORMES, PROBABLY);
						PROBABLY = MODEL_FIX( vectorSPH, vectorModel, vectorDelta, KOEFFICIENTS, PARAM_MODELING, FORMES, PROBABLY);
						
						GNUPLOT(vectorSPH, vectorModel, "1:2", "1:3");
						GNUPLOT(vectorSPH, vectorModel, "1:4", "1:5");
						vectorSPH.clear();
						vectorModel.clear();
						vectorDelta.clear();
					}
				}
			}

			if (PROBABLY_MAX < PROBABLY)
			{
				PROBABLY_MAX = PROBABLY;
				EPSS_MAX = EPSS;
				EPSD_MAX = EPSD;
				GAMMA_MAX = GAMMA;
				KANIH_MAX = KANIH;
				TAYLOR_MAX = TAYLOR;
			}
			PROBABLY = 1.00e0;
		}
	}
	getchar();
	std::cout << "Hello World!\n";
}
