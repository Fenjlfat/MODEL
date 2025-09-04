#include "header.h"

/*
double MODEL(
	std::vector<std::vector<double>>& vectorSPH,
	std::vector<std::vector<double>>& vectorMODEL,
	std::vector<double>& vectorDelta,
	double* KOEFFICIENTS,
	double* PARAM_MODELING,
	int FORMES,
	double PROBABLY)
{
	Parametrs PAR;
	int z = 0;
	double TIME = 0.00e0;
	long double VolP = 0.00e0, Vol = 0.00e0;
	long double RhoD = 0.00e12, dRhoD = 0.00e0, NUCLEATION = 0.00e0;
	long double Fp11 = 1.00e0, Fp22 = 1.00e0, dFp11 = 0.00e0, dFp22 = 0.00e0;
	long double Fd11 = 1.00e0, Fd22 = 1.00e0, dFd11 = 0.00e0, dFd22 = 0.00e0;
	long double LL11 = 0.00e0, LL22 = 0.00e0, LLa = 0.00e0, LLb = 0.00e0;
	long double F11 = 0.00e0, F22 = 0.00e0, Fe11 = 0.00e0, Fe22 = 0.00e0;
	long double Ha = 0.00e0, Hb = 0.00e0, eps1 = 0.00e0, eps2 = 0.00e0;
	long double AREA = 0.00e0, PERIMETR_11 = 0.00e0, PERIMETR_22 = 0.00e0;
	long double Tay11 = 0.00e0, Tay22 = 0.00e0, netta = 0.00e0;
	long double EE11 = 0.00e0, EE22 = 0.00e0;
	long double PRESS = 0.00e0, SIG11 = 0.00e0, SIG22 = 0.00e0;
	long double dXX = 0.00e0, dZZ = 0.00e0, dW11 = 0.00e0, dW22 = 0.00e0;
	long double dw = 0.00e0, ct = 0.00e0, Ac = 00e0, ARG = 0.00e0, n = 0.00e0;
	long double Y = 0.00e0, S = 0.00e0;
	//koefficients
	long double AMOL = 0.00e0;
	long double G = 0.00e0;
	long double K = 0.00e0;
	long double DENS = 0.00e0;
	long double MASS = 0.00e0;
	long double C_FCC = 0.00e0;
	long double BTR = 0.00e0;
	long double m1 = 0.00e0;
	long double DNC = 0.00e0;
	long double d1 = 0.00e0;
	long double BURG = 0.00e0;
	long double EpsD = 0.00e0;  // ;
	long double EpsS = 0.00e0;  //EpsS*1.6e-19/BURG;
	long double TAYLOR = 0.00e0;// TAYLOR1;
	long double gamma = 0.00e0;// GAM1;
	long double KoefAnigh = 0.00e0;


	VolP = Koefficient_PORE * XX * ZZ * ZZ;
	Vol = PAR.Ha0 * PAR.Hb0 * PAR.Hb0;

	if (PAR.metall == 1) //AL
	{
		AMOL = 26.9815386e0;
		G = 25.9e9 - 8.8e6 * TEMPERATURE;
		K = 79.9e9 + 1.9e7 * TEMPERATURE - 3.7e4 * pow(TEMPERATURE, 2);
		DENS = 2.7e3 - 8.7e-2 * TEMPERATURE - 5.41e-5 * pow(TEMPERATURE, 2);
		BTR = 0.674e-5 + 2.55e-8 * TEMPERATURE;
		C_FCC = 0.5e0 * sqrt(2.e0) * pow((4.e0), (1.e0 / 3.e0));
		m1 = AMOL * 1.e-3 / PAR.DNA;
		DNC = (DENS / m1);
		d1 = pow(DNC, (0.3333));
		BURG = C_FCC / d1;
		EpsD = (EpsD1 * (1.e0 - 3.4e-4 * TEMPERATURE)) * 1.6e-19 / BURG;  // ;
		EpsS = (EpsS1 * (1.e0 - 3.4e-4 * TEMPERATURE)) * 1.6e-19 / BURG;  //EpsS*1.6e-19/BURG;
		TAYLOR = TAYLOR1;
		gamma = gamma1;
		KoefAnigh = koefANIH;
		MASS = DENS * (Vol - VolP);
	}

	if (PAR.metall == 2) //CU
	{
		AMOL = 63.546e0;
		G = 49.79957143e9 - 2.150571429e7 * TEMPERATURE;
		K = 145.5314643e9 + 1.24547619e7 * TEMPERATURE - 1.963690476e4 * pow(TEMPERATURE, 2);
		DENS = 8.890885714e3 - 3.575e-1 * TEMPERATURE - 1.192857143e-4 * pow(TEMPERATURE, 2);
		BTR = 1.2e-5;
		C_FCC = 0.5e0 * sqrt(2.e0) * pow((4.e0), (1.e0 / 3.e0));
		m1 = AMOL * 1.e-3 / PAR.DNA;
		DNC = (DENS / m1);
		d1 = pow(DNC, (0.3333));
		BURG = C_FCC / d1;
		EpsD = (EpsD1 * (1.e0 - 4.13845369e-4 * TEMPERATURE)) * 1.6e-19 / BURG;
		EpsS = (EpsS1 * (1.e0 - 3.4e-4 * TEMPERATURE)) * 1.6e-19 / BURG;  //EpsS*1.6e-19/BURG;
		TAYLOR = TAYLOR1;// TAYLOR1;
		gamma = gamma1;// GAM1;
		KoefAnigh = koefANIH;
		MASS = DENS * (Vol - VolP);
	}


	int j = 0;

	ofstream EXIT;
	EXIT.open("BAES_" + name_File);
	double epsM = vectorSPH[numberPoint - 1][0] + 2 * vectorSPH[numberPoint - 1][1];

	while (eps1 + 2 * eps2 < epsM)
		//for (int i = 0; i < numberPoint * PAR.mnogitel; i++)
	{
		if (eps1 + 2 * eps2 > vectorSPH[j][0] + 2 * vectorSPH[j][1])
		{
			EXIT << eps1 + eps2 * 2 << "   " << -SIG11 / 1e9 << "   " << -SIG22 / 1e9 << "   " << VolP / Vol << endl;
			//cout <<endl<<"  EPS="<< eps1 + eps2 * 2 << "  SIG11=" << -SIG11 / 1e9 << "   SIG22=" << -SIG22 / 1e9 << "   POROSITY=" << VolP / Vol << endl
			//	<< "  dW11=" << dW11 << "  dw=" << dw << "  Y=" << Y << "   S=" << S << "   SDEV ="<< (4.e0 / 3.e0) * G * (EE11 - EE22)<< "  Tay11=" << Tay11 << "  RhoD=" << RhoD << endl;
			//getchar();
			vectorMODEL[j][0] = eps1;
			vectorMODEL[j][1] = eps2;
			vectorMODEL[j][8] = -SIG11 / 1e9;
			vectorMODEL[j][9] = -SIG22 / 1e9;
			vectorMODEL[j][12] = VolP / Vol;
			PROBABLY = 0.01e0 * (pow(pow(abs(((VolP / Vol) - vectorSPH[j][12]) / vectorSPH_delta[12]), 2) + abs((SIG11 * 1e-9 - vectorSPH[j][8]) / vectorSPH_delta[8]), 2) + pow(abs((SIG22 * 1e-9 - vectorSPH[j][9]) / vectorSPH_delta[9]), 2));
			if (PROBABLY < 100.00)
			{
				PROBABLY = PROBABLY * exp(-PROBABLY);
			}
			else
			{
				PROBABLY = 0.00e0;
			}
			j = j + 1;
			z = 0;
			//getchar();
		}

		TIME = TIME + PAR.dt;

		eps1 = eps1 + veps1 * PAR.dt;
		eps2 = eps2 + veps2 * PAR.dt;

		LLa = PAR.Ha0 * (1.e0 - eps1);
		LLb = PAR.Hb0 * (1.e0 - eps2);

		Ha = PAR.Ha0 - (PAR.Ha0 - LLa);
		Hb = PAR.Hb0 - (PAR.Hb0 - LLb);

		F11 = 1.00e0 - eps1;
		F22 = 1.00e0 - eps2;

		Fe11 = F11 / (Fp11 * Fd11);
		Fe22 = F22 / (Fp22 * Fd22);

		EE11 = 0.5e0 * (pow(Fe11, 2) - 1);
		EE22 = 0.5e0 * (pow(Fe22, 2) - 1);

		Vol = Ha * Hb * Hb;

		PRESS = -K * (EE11 + 2.e0 * EE22);
		S = (2.0e0 / 3.0e0) * (SIG11 - SIG22);  //mean shear stress
		/*PRES = -KK * (L11 + 2.e0 * L22);
		SDEV = (4.e0 / 3.e0) * GG * (L11 - L22);
		SIG1 = -PRES + SDEV;
		SIG2 = -PRES - SDEV * 0.5e0;
		SIG11 = (1 - (VolP / Vol)) * ((K + (4.0e0 / 3.0e0) * G) * EE11 + 2e0 * (K - (2.0e0 / 3.0e0) * G) * EE22);
		SIG22 = (1 - (VolP / Vol)) * ((K - (2.0e0 / 3.0e0) * G) * EE11 + 2e0 * (K + (1.0e0 / 3.0e0) * G) * EE22);

		if (RhoD < 0.00)
		{
			Y = TAYLOR * G * BURG * sqrt(-1 * RhoD);
		}
		else
		{
			Y = TAYLOR * G * BURG * sqrt(RhoD);
		}
		Y = TAYLOR * G * BURG * sqrt(RhoD);



		if (FORMES == 1) //sphere
		{
			AREA = 2.00 * PAR.pi * XX;
			PERIMETR_11 = PAR.pi * ZZ;
			PERIMETR_22 = PAR.pi * XX;
		}
		if (FORMES == 2) //cube
		{
			AREA = 2.00e0 * (XX * ZZ + XX * ZZ + ZZ * ZZ);
			PERIMETR_11 = 2.00e0 * (ZZ + ZZ);
			PERIMETR_22 = 2.00e0 * (XX + ZZ);
		}

		//plastic
		LL11 = MINIMUM(XX, Ha - XX);
		LL22 = MINIMUM(ZZ, Hb - ZZ);

		dXX = dW11 * LL11 * PAR.dt;
		dZZ = dW22 * LL22 * PAR.dt;

		XX = XX + dXX;
		ZZ = ZZ + dZZ;

		if (XX < 0.00)
		{
			XX = 0.00;
		}
		if (ZZ < 0.00)
		{
			ZZ = 0.00;
		}
		VolP = Koefficient_PORE * XX * ZZ * ZZ;

		//plastic                                                
		Tay11 = SIG11 * ((Koefficient_PORE * ZZ * ZZ) / (LL11 * PERIMETR_11)) - gamma / LL11;
		Tay22 = SIG22 * ((Koefficient_PORE * XX * ZZ) / (LL22 * PERIMETR_22)) - gamma / LL22;

		netta = (pow(BURG, 2) * RhoD) / (4.0e0 * BTR);


		dW11 = netta * (Tay11 - 0.5e0 * Y * SIGNUM(Tay11)) * HEVISAID(abs(Tay11) - 0.5e0 * Y);
		dW22 = netta * (Tay22 - 0.5e0 * Y * SIGNUM(Tay22)) * HEVISAID(abs(Tay22) - 0.5e0 * Y);

		// dwP = dW11 + dW22;

		//plastic deformation

		dw = netta * (0.75e0 * S - 0.5 * Y * SIGNUM(S)) * HEVISAID(0.75e0 * abs(S) - 0.5e0 * Y);
		//dw = netta * (0.75e0 * S - 0.5 * Y * SIGNUM(S)) * HEVISAID(0.75e0 * abs(S) - 0.5e0 * Y);
		DENS = MASS / (Vol - VolP);
		DNC = (DENS / m1);
		d1 = pow(DNC, (0.3333));
		BURG = C_FCC / d1;
		EpsD = (EpsD1 * (1.e0 - 3.4e-4 * TEMPERATURE)) * 1.6e-19 / BURG;  // ;
		EpsS = (EpsS1 * (1.e0 - 3.4e-4 * TEMPERATURE)) * 1.6e-19 / BURG;  //EpsS*1.6e-19/BURG;
		ct = sqrtl(G / DENS);
		//NUCLEATION = 0.00e0;
		if ((abs(Tay11) + abs(Tay22) + abs(S)) > 1e8)
		{
			//nucleation
			if (abs(Tay11) < abs(Tay22))
			{
				Ac = EpsS / (BURG * (abs(Tay11) + abs(S) * 0.75));
			}
			if (abs(Tay11) > abs(Tay22))
			{
				Ac = EpsS / (BURG * (abs(Tay22) + abs(S) * 0.75));
			}

			ARG = 0.50 * (PAR.pi * EpsS * Ac) / (PAR.kB * TEMPERATURE);
			if (ARG > 200.0) { ARG = 0.00e0; }
			else if (ARG > 0.00e0 || ARG < 200.0) { ARG = exp(-ARG); }
			else { ARG = 1.00e0; }
			n = 1 / Vol;
			if (VolP == 0) { n = 0.00e0; }
			NUCLEATION = 0.5e0 * (PAR.pi * ct) * n * ((AREA * BURG) / (Ac * Ac * Ac)) * ARG;

			//getchar();
		}

		//Density dislocation
		dRhoD = NUCLEATION + (1 / EpsD) * ((abs(Tay11 * dW11) + abs(Tay22 * dW22)) * (VolP / Vol) + (0.75e0) * S * dw) - ((abs(dW11) + abs(dW22)) * (VolP / Vol) + abs(dw)) * KoefAnigh * RhoD;
		RhoD = RhoD + PAR.dt * dRhoD;

		dFp11 = dw * Fp11 * PAR.dt;
		dFp22 = -0.5 * dw * Fp22 * PAR.dt;

		Fp11 = Fp11 + dFp11;
		Fp22 = Fp22 + dFp22;

		//plastic
		dFd11 = Fd11 * ((Koefficient_PORE * ZZ * ZZ) / (Vol - VolP)) * dXX;
		dFd22 = Fd22 * ((Koefficient_PORE * XX * ZZ) / (Vol - VolP)) * dZZ;

		Fd11 = Fd11 + dFd11;
		Fd22 = Fd22 + dFd22;

		z = z + 1;
	}
	j = 0;
	//getchar();
	EXIT.close();
	return PROBABLY;
};
*/