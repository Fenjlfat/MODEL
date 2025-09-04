#include "header.h"

//обработка файла
void processingFile(std::string nameFile, std::vector<std::vector<double>>& vectorSPH, std::vector<double>& vectorDelta, int columnsFile)
{
	int  l = 0;
	double q = 0;

	std::fstream FILE;

	//считываем данные с файла в вектор‘айл
	FILE.open(nameFile, std::ios::in);
	if (!FILE.is_open())
	{
		std::cout << "File not open" << std::endl;
	}
	else
	{
		std::cout << "File open" << std::endl;
		while (!FILE.eof())
		{
			std::vector<double> vectorLine;
			for (int i = 0; i < columnsFile; i++)
			{
				FILE >> q;
				vectorLine.push_back(q);
			}
			vectorSPH.push_back(vectorLine);
			vectorLine.clear();
		}
	}
	FILE.close();

	//функци€ дл€ нахождени€ дельты

	std::vector<double> vectorMax(columnsFile, 0);
	std::vector<double> vectorMin(columnsFile, 0);
	
	for (int i = 0; i < vectorSPH.size(); i++)
	{
		for (int n = 0; n < columnsFile; n++)
		{
			if (vectorMax[n] < vectorSPH[i][n])
			{
				vectorMax[n] = vectorSPH[i][n];
			}

			if (vectorMin[n] > vectorSPH[i][n])
			{
				vectorMin[n] = vectorSPH[i][n];
			}
		}
	}

	for (int j = 0; j < columnsFile; j++)
	{
		vectorDelta.push_back(abs(vectorMin[j] - vectorMax[j]));
	}
}