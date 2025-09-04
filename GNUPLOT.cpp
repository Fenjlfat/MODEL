#include "header.h"

//рисование графиков
double GNUPLOT(std::vector<std::vector<double>>& vectorSPH, std::vector<std::vector<double>>& vectorModel,std::string graph1, std::string graph2)
{
	FILE* pipe = _popen("C:\\gnuplot\\bin\\gnuplot.exe", "w");
	if (pipe != NULL)
	{

		std::string message{ "plot 'E:\\WORK\\SPH\\PROGRAMMS\\C++\\MODEL_C++\\MODEL_C++\\DataGnuplot.txt' using " + graph1 + " title 'SPH'  with lines linecolor 1 lw 3, 'E:\\WORK\\SPH\\PROGRAMMS\\C++\\MODEL_C++\\MODEL_C++\\DataGnuplot.txt' using "+graph2+" title 'MODEL' with lines linecolor 3 lw 3\n" };
		const char* WAY_TO_DATA = message.c_str();  // преобразуем в указатель
		std::ofstream DATAGNUPLOT;
		DATAGNUPLOT.open("DataGnuplot.txt");
		for (int i = 0; i < vectorSPH.size()-1; i++)
		{
			DATAGNUPLOT << i << " " << vectorSPH[i][5] << " " << vectorModel[i][0] << " " << vectorSPH[i][9] << " " << vectorModel[i][2] << std::endl;   //SIG11
			//DATAGNUPLOT << i << " " << vectorMD[i][4] << " " << vectorGnuplot[i][1] << endl; //SIG22
			//DATAGNUPLOT << i << " " << vectorMD[i][5] << " " << vectorGnuplot[i][2] << endl; //RhoD
			//DATAGNUPLOT << i << " " << vectorMD[i][6] << " " << vectorGnuplot[i][3] << endl; //VOL
		}
		DATAGNUPLOT.close();
		fprintf(pipe, WAY_TO_DATA);
		fflush(pipe);

		// ожидание нажатия клавиши
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();

#ifdef WIN32
		_pclose(pipe);
#else
		_pclose(pipe);
#endif
	}
	else puts("Could not open the file\n");
	//getchar();
	_pclose(pipe);
	return 0;
}