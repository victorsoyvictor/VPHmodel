#include "Problema.h"
#include "../Biblioteca/aleatorio.h"
#include "../Biblioteca/Reloj.h"
#include <ctime>
#include <fstream>
#define HABITANTES_OBJETIVO       10000.0
#define BASE_HABITANTES           9874.2798798000058//9874.27987980001


double elapsedTime_2 = 0;


#define TIME_THIS(X)                                        \
  {                                                         \
    LARGE_INTEGER frequency_2;                              \
    LARGE_INTEGER t1_2, t2_2;                               \
    QueryPerformanceFrequency(&frequency_2);                \
    QueryPerformanceCounter( &t1_2 );                       \
    X;                                                      \
    QueryPerformanceCounter( &t2_2 );                       \
    printf( #X " demora: %f\n",                             \
      (float) (t2_2.QuadPart - t1_2.QuadPart) * 1000.0 / frequency_2.QuadPart );                \
  }

//# Probabilidad acumulada de ser hombre (primero) o mujer (segundo) en la CV
//
bool CProblema::EsHombre() //devuelve true si por azar es hombre, false si es mujer
{
	if (m_dado.TiraFloat() < 0.5071510541347615)
		return true;
	else
		return false;
}

int CProblema::GrupoEdadHombres() // devuelve 1 = grupo de edad 14-29, 2 = 30-39, 3 = 40-65
{
	BASE_TYPE azar = m_dado.TiraFloat();
	if (azar < 0.25220708223866295)
		return 1;
	else if (azar < 0.5045667870135917)
		return 2;
	else
		return 3;
}

/*
Delicado e importante al aniadir LSP a struct subnodo
*/
bool operator < (subNodoWeight we1, subNodoWeight we2)
{
    if (we1.weight < we2.weight)
        return true;
    else return false;

}

bool operator < (subNodoLSP LSPe1, subNodoLSP LSPe2)
{
    if (LSPe1.LSP < LSPe2.LSP)
        return true;
    else return false;

}

int CProblema::GrupoEdadMujeres() // devuelve 1 = grupo de edad 14-29, 2 = 30-39, 3 = 40-65
{
	BASE_TYPE azar = m_dado.TiraFloat();
	if (azar < 0.24879465797192987)
		return 1;
	else if (azar < 0.488636809805478)
		return 2;
	else
		return 3;
}

int CProblema::EdadHombres()
{
	int grupo = GrupoEdadHombres();
	BASE_TYPE azar = m_dado.TiraFloat();
	switch(grupo)
	{
	case 1: // 14 a 29 anios
		if (azar < 0.053421825221942304)
			return 14;
		else if (azar < 0.1068568058287125)
			return 15;
		else if (azar < 0.16022381694720525)
			return 16;
		else if (azar < 0.2136544124256995)
			return 17;
		else if (azar < 0.26981913538425784)
			return 18;
		else if (azar < 0.32750330529043803)
			return 19;
		else if (azar < 0.38528175545455146)
			return 20;
		else if (azar < 0.44447221692352556)
			return 21;
		else if (azar < 0.5051908955966734)
			return 22;
		else if (azar < 0.5679552366105589)
			return 23;
		else if (azar < 0.6326950779127667)
			return 24;
		else if (azar < 0.6993402574508811)
			return 25;
		else if (azar < 0.7687283347256115)
			return 26;
		else if (azar < 0.8418920074459478)
			return 27;
		else if (azar < 0.9175376627704802)
			return 28;
		else return 29;
		break;

	case 2: // 30 a 39 anios
		if (azar < 0.0881228320437897)
			return 30;
		else if (azar < 0.18146300204004268)
			return 31;
		else if (azar < 0.2789051697880854)
			return 32;
		else if (azar < 0.3821563097797148)
			return 33;
		else if (azar < 0.4874453012185475)
			return 34;
		else if (azar < 0.5929446515164464)
			return 35;
		else if (azar < 0.697501769424778)
			return 36;
		else if (azar < 0.8007989254168283)
			return 37;
		else if (azar < 0.900785120616702)
			return 38;
		else
			return 39;
		break;

	case 3: // 40 a 65 anios
		if (azar < 0.049923375966729654)
			return 40;
		else if (azar < 0.09926746754500615)
			return 41;
		else if (azar < 0.14759697432732136)
			return 42;
		else if (azar < 0.1952679497239191)
			return 43;
		else if (azar < 0.2429645966830109)
			return 44;
		else if (azar < 0.288869815041973)
			return 45;
		else if (azar < 0.33405734580599217)
			return 46;
		else if (azar < 0.3794156482683415)
			return 47;
		else if (azar < 0.42287537126102065)
			return 48;
		else if (azar < 0.46411282986562613)
			return 49;
		else if (azar < 0.5043948598834957)
			return 50;
		else if (azar < 0.5447036776187505)
			return 51;
		else if (azar < 0.5841843084248487)
			return 52;
		else if (azar < 0.6223545733888584)
			return 53;
		else if (azar < 0.659253537931966)
			return 54;
		else if (azar < 0.6930049456823222)
			return 55;
		else if (azar < 0.7263980677126526)
			return 56;
		else if (azar < 0.7577653686157335)
			return 57;
		else if (azar < 0.7890590032960054)
			return 58;
		else if (azar < 0.821331505815725)
			return 59;
		else if (azar < 0.8511283767871035)
			return 60;
		else if (azar < 0.8803336856662273)
			return 61;
		else if (azar < 0.9101796674528118)
			return 62;
		else if (azar < 0.9420726773095756)
			return 63;
		else if (azar < 0.9715291210391849)
			return 64;
		else
			return 65;
		break;

	default:
		cout << "ERROR GENERANDO EDADES DE HOMBRES" << endl;
		exit(-1);
	}
}

int CProblema::EdadMujeres()
{
	int grupo = GrupoEdadMujeres();
	BASE_TYPE azar = m_dado.TiraFloat();
	switch(grupo)
	{
	case 1: // 14 a 29 anios
		if (azar < 0.05254695490682207)
			return 14;
		else if (azar < 0.10506646417887235)
			return 15;
		else if (azar < 0.1574235867785229)
			return 16;
		else if (azar < 0.20993166036941824)
			return 17;
		else if (azar < 0.2643883740291107)
			return 18;
		else if (azar < 0.3214249773573513)
			return 19;
		else if (azar < 0.37927351404759074)
			return 20;
		else if (azar < 0.43808722222730473)
			return 21;
		else if (azar < 0.499085145507607)
			return 22;
		else if (azar < 0.5625394530999844)
			return 23;
		else if (azar < 0.6276542215960551)
			return 24;
		else if (azar < 0.6960601791285096)
			return 25;
		else if (azar < 0.7671420860512136)
			return 26;
		else if (azar < 0.8413596567465944)
			return 27;
		else if (azar < 0.9179444134410422)
			return 28;
		else
			return 29;
		break;

	case 2: // 30 a 39 anios
		if (azar < 0.08958350632866345)
			return 30;
		else if (azar < 0.1853331593494585)
			return 31;
		else if (azar < 0.2837637457146585)
			return 32;
		else if (azar < 0.38656449068197724)
			return 33;
		else if (azar < 0.4908290727054888)
			return 34;
		else if (azar < 0.5956417039348035)
			return 35;
		else if (azar < 0.6986654645962586)
			return 36;
		else if (azar < 0.8026595807779452)
			return 37;
		else if (azar < 0.9018066643732429)
			return 38;
		else
			return 39;
		break;

	case 3: // 40 a 65 anios
		if (azar < 0.0457613652296414)
			return 40;
		else if (azar < 0.09123229868404362)
			return 41;
		else if (azar < 0.13649625776988455)
			return 42;
		else if (azar < 0.18154879142547475)
			return 43;
		else if (azar < 0.2270063716948085)
			return 44;
		else if (azar < 0.2705767018077987)
			return 45;
		else if (azar < 0.3137453236033125)
			return 46;
		else if (azar < 0.3579944406239498)
			return 47;
		else if (azar < 0.3995640185075145)
			return 48;
		else if (azar < 0.4405360413592652)
			return 49;
		else if (azar < 0.4805455221206638)
			return 50;
		else if (azar < 0.5210913558156459)
			return 51;
		else if (azar < 0.5607903750242027)
			return 52;
		else if (azar < 0.5992831565149077)
			return 53;
		else if (azar < 0.6368812746060254)
			return 54;
		else if (azar < 0.6719222577565314)
			return 55;
		else if (azar < 0.7066327495765927)
			return 56;
		else if (azar < 0.7396874464481641)
			return 57;
		else if (azar < 0.7728022326525434)
			return 58;
		else if (azar < 0.8065601972710541)
			return 59;
		else if (azar < 0.8383730479312578)
			return 60;
		else if (azar < 0.869951105087341)
			return 61;
		else if (azar < 0.9028177446025313)
			return 62;
		else if (azar < 0.9369473728721143)
			return 63;
		else if (azar < 0.9691686084423287)
			return 64;
		else
			return 65;
		break;

	default:
		cout << "ERROR GENERANDO EDADES DE MUJERES" << endl;
		exit(-1);
	}
}

int CProblema::ParejasHombres(int edad)
	{
//Probabilidad ACUMULADA de tener 0, 1, 2, 3-4, 5-9 o mas de 10 parejas sexuales por grupo de edad.
/*	* 1er elemento -> 0 parejas
	* 2o elemento -> 1 pareja
	* 3er elemento -> 2 parejas
	* 4o elemento -> 3 - 4 parejas
	* 5o elemento -> 5 - 9 parejas
	* 6o elemento -> mas de 10 parejas
"""*/
	BASE_TYPE azar = m_dado.TiraFloat();
	if (edad >= 14 && edad <= 29)
	{
		if (azar < 0.107)
			return 0;
		else if (azar < 0.314)
			return 1;
		else if (azar < 0.445)
			return 2;
		else if (azar < 0.67)
			return m_dado.TiraRangoInt(3,4);
		else if (azar < 0.838)
			return m_dado.TiraRangoInt(5,9);
		else
			return 10;
	}
	else if (edad >= 30 && edad <=39)
	{
		if (azar < 0.027)
			return 0;
		else if (azar < 0.252)
			return 1;
		else if (azar < 0.38)
			return 2;
		else if (azar < 0.59)
			return m_dado.TiraRangoInt(3,4);
		else if (azar < 0.76)
			return m_dado.TiraRangoInt(5,9);
		else
			return 10;
	}
	else if (edad >= 40 && edad <= 65)
	{
		if (azar < 0.019)
			return 0;
		else if (azar < 0.287)
			return 1;
		else if (azar < 0.427)
			return 2;
		else if (azar < 0.62)
			return m_dado.TiraRangoInt(3,4);
		else if (azar < 0.783)
			return m_dado.TiraRangoInt(5,9);
		else
			return 10;
	}
	else
	{
		cout << "ERROR GENERANDO RELACIONES DE HOMBRES" << endl;
		exit(-1);
	}
}

/*
Modificador para los pesos de los homos, para que suba un poco
*/
int CProblema::PesoHomos(unsigned int edad1, unsigned int edad2)
{
    int grupo1 = 0;
    int grupo2 = 0;

	if (edad1 >= 14 && edad1 <= 29)
	{
		grupo1 = 1;
	}
	else if (edad1 >= 30 && edad1 <=39)
	{
		grupo1 = 2;
	}
	else if (edad1 >= 40 && edad1 <= 65)
	{
		grupo1 = 3;
	}

	if (edad2 >= 14 && edad2 <= 29)
	{
		grupo2 = 1;
	}
	else if (edad2 >= 30 && edad2 <=39)
	{
		grupo2 = 2;
	}
	else if (edad2 >= 40 && edad2 <= 65)
	{
		grupo2 = 3;
	}

	return abs(grupo1 - grupo2);
}


int CProblema::ParejasMujeres(int edad)
	{
//Probabilidad ACUMULADA de tener 0, 1, 2, 3-4, 5-9 o mas de 10 parejas sexuales por grupo de edad.
/*	* 1er elemento -> 0 parejas
	* 2o elemento -> 1 pareja
	* 3er elemento -> 2 parejas
	* 4o elemento -> 3 - 4 parejas
	* 5o elemento -> 5 - 9 parejas
	* 6o elemento -> mas de 10 parejas
"""*/
	BASE_TYPE azar = m_dado.TiraFloat();
	if (edad >= 14 && edad <= 29)
	{
		if (azar < 0.138)
			return 0;
		else if (azar < 0.568)
			return 1;
		else if (azar < 0.754)
			return 2;
		else if (azar < 0.912)
			return m_dado.TiraRangoInt(3,4);
		else if (azar <0.968)
			return m_dado.TiraRangoInt(5,9);
		else
			return 10;
	}
	else if (edad >= 30 && edad <=39)
	{
		if (azar < 0.029)
			return 0;
		else if (azar < 0.53)
			return 1;
		else if (azar < 0.698)
			return 2;
		else if (azar < 0.875)
			return m_dado.TiraRangoInt(3,4);
		else if (azar < 0.952)
			return m_dado.TiraRangoInt(5,9);
		else
			return 10;
	}
	else if (edad >= 40 && edad <= 65)
	{
		if (azar < 0.017)
			return 0;
		else if (azar < 0.669)
			return 1;
		else if (azar < 0.807)
			return 2;
		else if (azar < 0.925)
			return m_dado.TiraRangoInt(3,4);
		else if (azar < 0.964)
			return m_dado.TiraRangoInt(5,9);
		else
			return 10;
	}
	else
	{
		cout << "ERROR GENERANDO RELACIONES DE MUJERES" << endl;
		exit(-1);
	}
}

//entre 18-56
int CProblema::ParejasHombresHomosexuales(int edad)
	{
	//BASE_TYPE azar = m_dado.TiraFloat();
	if (edad >= 14 && edad <= 19)
	{
        return 18;
	}
	else if (edad >= 20 && edad <=24)
	{
        return 25;
	}
	else if (edad >= 25 && edad <= 29)
	{
        return 33;
	}
    else if (edad >= 30 && edad <= 39)
	{
        return 45;
	}
    else if (edad >= 40 && edad <= 49)
	{
        return 59;
	}
    else if (edad >= 50 && edad <= 59)
	{
        return 50;
	}
    else if (edad >= 60 )
	{
        return 56;
	}
	else
	{
		cout << "ERROR GENERANDO RELACIONES DE HOMBRES HOMOSEXUALES" << endl;
		exit(-1);
	}
}




BASE_TYPE const reparto_de_poblaciones[]={
	    120,
		1,		121.920000,
		2,		122.380000,
		3,		123.850000,
		4,		124.270000,
		5,		123.810000,
		6,		123.390000,
		7,		125.020000,
		8,		123.480000,
		9,		123.100000,
		10,		122.040000,
		11,		123.200000,
		12,		123.490000,
		13,		122.460000,
		14,		123.040000,
		15,		122.800000,
		16,		123.650000,
		17,		121.920000,
		18,		123.110000,
		19,		122.690000,
		20,		123.840000,
		21,		123.890000,
		22,		123.960000,
		23,		123.230000,
		24,		122.630000,
		25,		124.070000,
		26,		121.680000,
		27,		123.400000,
		28,		122.620000,
		29,		120.580000,
		30,		123.470000,
		31,		122.590000,
		32,		122.810000,
		33,		122.650000,
		34,		121.970000,
		35,		121.760000,
		36,		122.230000,
		37,		123.010000,
		38,		121.700000,
		39,		121.760000,
		40,		121.100000,
		41,		122.190000,
		42,		120.800000,
		43,		122.510000,
		44,		120.490000,
		45,		121.540000,
		46,		119.570000,
		47,		120.750000,
		48,		119.840000,
		49,		119.330000,
		50,		118.480000,
		51,		118.180000,
		52,		118.200000,
		53,		118.260000,
		54,		117.080000,
		55,		116.720000,
		56,		115.550000,
		57,		116.860000,
		58,		115.470000,
		59,		112.940000,
		60,		115.450000,
		61,		114.020000,
		62,		110.580000,
		63,		111.330000,
		64,		110.610000,
		65,		110.690000,
		66,		108.900000,
		67,		105.860000,
		68,		106.640000,
		69,		103.540000,
		70,		103.240000,
		71,		100.810000,
		72,		100.900000,
		73,		99.160010,
		74,		93.749970,
		75,		92.529990,
		76,		90.270000,
		77,		87.280000,
		78,		82.939990,
		79,		80.339990,
		80,		76.999990,
		81,		72.109990,
		82,		68.679990,
		83,		63.490000,
		84,		58.629990,
		85,		53.100000,
		86,		44.339990,
		87,		37.020000,
		88,		31.950000,
		89,		27.400000,
		90,		22.650000,
		91,		18.759990,
		92,		16.020000,
		93,		13.710000,
		94,		11.520000,
		95,		9.570002,
		96,		8.340001,
		97,		6.740000,
		98,		5.150001,
		99,		4.299998,
		100,		4.139998,
		101,		3.819998,
		102,		2.869998,
		103,		2.359998,
		104,		1.929999,
		105,		1.849999,
		106,		1.539999,
		107,		1.120000,
		108,		1.140000,
		109,		9.999996E-01,
		110,		6.299998E-01,
		111,		7.199997E-01,
		112,		4.699999E-01,
		113,		4.599999E-01,
		114,		3.799999E-01,
		115,		3.400000E-01,
		116,		2.600000E-01,
		117,		2.300000E-01,
		118,		1.500000E-01,
		119,		1.300000E-01,
		120,		9.000000E-02};

BASE_TYPE const mortalidades[]={
	        85,
			0, 0.003362123, 0.003633522, 0.0030736,
			1, 0.000324682, 0.000354526, 0.000292973,
			2, 0.000303699, 0.000432271, 0.000167056,
			3, 0.000126617, 0.000163706, 8.71346E-05,
			4, 0.000192423, 0.000249221, 0.000132176,
			5, 0.000196172, 0.000169981, 0.000223754,
			6, 0.000112007, 0.000219993, 0,
			7, 0.000138396, 0.000223994, 4.75466E-05,
			8, 0.000187135, 0.00031772, 4.82672E-05,
			9, 4.66941E-05, 4.53823E-05, 4.80839E-05,
			10, 0.000186077, 0.000135465, 0.000239843,
			11, 9.18E-05, 8.89996E-05, 9.47822E-05,
			12, 4.51243E-05, 4.38347E-05, 4.64922E-05,
			13, 2.21587E-05, 0.0     , 4.56038E-05,
			14, 0.000108797, 0.000211622, 0,
			15, 0.000300236, 0.000333806, 0.000264737,
			16, 0.000297259, 0.000412916, 0.000174833,
			17, 0.000458352, 0.000526358, 0.000386266,
			18, 0.000404973, 0.000669608, 0.00012501,
			19, 0.000368674, 0.000528501, 0.000199633,
			20, 0.000406534, 0.000541184, 0.000265162,
			21, 0.000502452, 0.00084809, 0.000141648,
			22, 0.000371357, 0.000568146, 0.000165273,
			23, 0.000465661, 0.000586304, 0.000338879,
			24, 0.000351242, 0.00046546, 0.00023086,
			25, 0.000433788, 0.000509944, 0.000352743,
			26, 0.000523286, 0.000673773, 0.00036171,
			27, 0.000538961, 0.000784278, 0.000274027,
			28, 0.000527377, 0.000719538, 0.000318199,
			29, 0.00042828, 0.00062098, 0.000217907,
			30, 0.000604468, 0.000912125, 0.000267796,
			31, 0.000682377, 0.000899645, 0.000444061,
			32, 0.000633941, 0.000891918, 0.000351071,
			33, 0.000680595, 0.000861387, 0.000483129,
			34, 0.000581187, 0.000829718, 0.00031019,
			35, 0.000901544, 0.001251233, 0.000522139,
			36, 0.000897008, 0.001242297, 0.000524948,
			37, 0.000895507, 0.001213262, 0.000555835,
			38, 0.001064051, 0.001461878, 0.0006419,
			39, 0.001230947, 0.001431237, 0.00102049,
			40, 0.001208291, 0.001427459, 0.000978713,
			41, 0.001342409, 0.001674463, 0.000996567,
			42, 0.001550946, 0.002153938, 0.00092861,
			43, 0.00158018, 0.002232517, 0.000913138,
			44, 0.002011723, 0.002693487, 0.001315943,
			45, 0.002051418, 0.002612882, 0.001483856,
			46, 0.00219318, 0.003024495, 0.001356402,
			47, 0.002337715, 0.002941723, 0.0017338,
			48, 0.002674867, 0.003660299, 0.00169394,
			49, 0.002538792, 0.003696361, 0.001394793,
			50, 0.002981504, 0.004378744, 0.001612793,
			51, 0.003315685, 0.00513117, 0.001548042,
			52, 0.003466647, 0.004822316, 0.002154399,
			53, 0.004341724, 0.006484095, 0.002277988,
			54, 0.004664514, 0.007001393, 0.002435334,
			55, 0.00474943, 0.006878695, 0.00272239,
			56, 0.005058179, 0.008076969, 0.002206597,
			57, 0.006008517, 0.008376082, 0.003777148,
			58, 0.006049725, 0.009196886, 0.003100072,
			59, 0.00620809, 0.00872105, 0.003853862,
			60, 0.007336517, 0.011199253, 0.00372661,
			61, 0.00815557, 0.012230532, 0.004371451,
			62, 0.008503026, 0.012720426, 0.004595354,
			63, 0.008464752, 0.012525621, 0.004713011,
			64, 0.009146198, 0.012479733, 0.006071866,
			65, 0.011177967, 0.015982788, 0.006787436,
			66, 0.01127415, 0.016352266, 0.0066411,
			67, 0.011135966, 0.015802976, 0.006932249,
			68, 0.013575826, 0.020241148, 0.00761347,
			69, 0.014897349, 0.021632718, 0.00893938,
			70, 0.017053541, 0.025374552, 0.009817414,
			71, 0.0169148, 0.025248412, 0.009792092,
			72, 0.021113588, 0.029091318, 0.014419679,
			73, 0.022027006, 0.03157224, 0.014218009,
			74, 0.02330537, 0.031653629, 0.016616461,
			75, 0.029248029, 0.040422926, 0.020527269,
			76, 0.033972619, 0.046255201, 0.024702988,
			77, 0.036440281, 0.05058624, 0.026050693,
			78, 0.041905528, 0.053277365, 0.033828336,
			79, 0.048141377, 0.063545151, 0.037556698,
			80, 0.053093905, 0.067706315, 0.043300441,
			81, 0.063816502, 0.084582893, 0.050302364,
			82, 0.067244719, 0.088480801, 0.053850782,
			83, 0.077582202, 0.097674419, 0.065406615,
			84, 0.096095561, 0.116026576, 0.084553303,
			85, 0.157009521, 0.172712667, 0.149730524};


CProblema::CProblema()
    {

    }

CProblema::~CProblema(void)
    {
    }

bool CProblema::LeeProblema(string problema_de_entrada,string solucion_de_salida)
    {
        CArchivoTexto archivo;
        string buffer;

        m_problema_de_entrada = problema_de_entrada;
        m_solucion_de_salida = solucion_de_salida;

        if (archivo.AbreArchivoLectura(problema_de_entrada) == false)
         return false;

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos identificador
        m_identificador_de_prueba  = buffer;

        if (solucion_de_salida == "") //nombre de salida no definido
        {
            m_solucion_de_salida = m_identificador_de_prueba;
            m_solucion_de_salida += ".sol";
        }

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos RAM
        m_consumo_RAM = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos generador de red
        m_generador_de_red = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos turnos a simular
        m_turnos_a_simular = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos realizaciones
        m_realizaciones = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos nodos
        m_numero_de_nodos = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos grado medio
        m_grado_medio = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos T desplazado o no
        m_T_desplazado = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos T, el multiplicador del contagio
        m_T0 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos T, el multiplicador del contagio
        m_T1 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos T, el multiplicador del contagio
        m_T2 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer); // Leemos T, el multiplicador del contagio
        m_T3 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_meanDuration_H_16_18 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_meanDuration_M_16_18 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_meanDuration_H_6_11 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_meanDuration_M_6_11 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_probabilidad_de_contagio_M_6_11 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_probabilidad_de_contagio_H_6_11 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_probabilidad_de_contagio_M_16_18 = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_probabilidad_de_contagio_H_16_18 = texto_a_TipoBase(buffer);

        //VACUNACION
        // return ((( - m_pp ) / m_tp - tini ) * t ) + m_pv;
        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_pv = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_cv_ninias = texto_a_TipoBase(buffer);
        //CASO DANES
        ifstream in("cobertura.cov");
        string line;
        std::getline (in,line);

        BASE_TYPE f;
        while (in >> f)
        {
            m_cv_ninias_vector.push_back(f);
        }
        //cout << TipoBase_a_texto(m_cv_ninias_vector[2]);




        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_pp = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_tp = texto_a_TipoBase(buffer);

//        archivo.LeeLinea(buffer);
//        archivo.LeeLinea(buffer);
//        m_tini = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_mes_vacunacion_ini = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_14_17__HR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_14_17__LR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_14_17__AMBOS = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_18_29__HR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_18_29__LR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_18_29__AMBOS = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_30_39__HR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_30_39__LR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_30_39__AMBOS = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_40_65__HR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_40_65__LR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_40_65__AMBOS = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_dinamica_ini = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_dinamica_fin = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_mes_vacunacion_fin = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_homosexuales = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_verrugable = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_oncogenico = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_cv_ninios = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_proteccion_de_vacuna_LR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_proteccion_de_vacuna_HR = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_mes_catchup_ini = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_mes_catchup_fin = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_edad_catchup_ini = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_edad_catchup_fin = texto_a_entero(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_cv_catchup = texto_a_TipoBase(buffer);

        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_alpha_1 = texto_a_TipoBase(buffer);
        //TURISMO
//        archivo.LeeLinea(buffer);
//        archivo.LeeLinea(buffer);
//        m_ei = texto_a_entero(buffer);
//
//
//        archivo.LeeLinea(buffer);
//        archivo.LeeLinea(buffer);
//        m_ef = texto_a_entero(buffer);
//
//
//        archivo.LeeLinea(buffer);
//        archivo.LeeLinea(buffer);
//        m_por = texto_a_TipoBase(buffer);


        archivo.LeeLinea(buffer);
        archivo.LeeLinea(buffer);
        m_alpha_2 = texto_a_TipoBase(buffer);


        m_tiempo_CPU = 0;

        return true;
    }


void CProblema::IniciaContabilidad()
{

    unsigned int turno = 0;
    unsigned int numEdades = 52; // de 14-65

    m_contabilidad.resize(m_turnos_a_simular + 1);

    for (turno = 0; turno <= m_turnos_a_simular; turno++)
    {
		m_contabilidad[turno].poblacion_por_edad_H.resize(numEdades,0);
        m_contabilidad[turno].poblacion_por_edad_H.resize(numEdades,0);
        m_contabilidad[turno].poblacion_por_edad_M.resize(numEdades,0);
        m_contabilidad[turno].poblacion_por_edad_H_VERRUGABLE.resize(numEdades,0);
        m_contabilidad[turno].poblacion_por_edad_H_VERRUGABLE_HOMO.resize(numEdades,0);
        m_contabilidad[turno].poblacion_por_edad_H_ONCOGENICO.resize(numEdades,0);
        m_contabilidad[turno].poblacion_por_edad_H_ONCOGENICO_HOMO.resize(numEdades,0);
        m_contabilidad[turno].poblacion_por_edad_M_VERRUGABLE.resize(numEdades,0);
        m_contabilidad[turno].poblacion_por_edad_M_ONCOGENICO.resize(numEdades,0);
        m_contabilidad[turno].poblacion_por_edad_HOMO.resize(numEdades,0);
        m_contabilidad[turno].infectados_por_edad_HR_H.resize(numEdades,0);
        m_contabilidad[turno].infectados_por_edad_HR_M.resize(numEdades,0);
        m_contabilidad[turno].infectados_por_edad_HR_H_HOMO.resize(numEdades,0);
        m_contabilidad[turno].infectados_por_edad_LR_H.resize(numEdades,0);
        m_contabilidad[turno].infectados_por_edad_LR_M.resize(numEdades,0);
        m_contabilidad[turno].infectados_por_edad_LR_H_HOMO.resize(numEdades,0);
        m_contabilidad[turno].infectados_por_edad_HR_LR_H.resize(numEdades,0);
        m_contabilidad[turno].infectados_por_edad_HR_LR_M.resize(numEdades,0);
        m_contabilidad[turno].infectados_por_edad_HR_LR_H_HOMO.resize(numEdades,0);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_H.resize(numEdades,0);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_M.resize(numEdades,0);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_H_HOMO.resize(numEdades,0);
        m_contabilidad[turno].infectados_vacunados_por_edad_LR_H.resize(numEdades,0);
        m_contabilidad[turno].infectados_vacunados_por_edad_LR_M.resize(numEdades,0);
        m_contabilidad[turno].infectados_vacunados_por_edad_LR_H_HOMO.resize(numEdades,0);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_H.resize(numEdades,0);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_M.resize(numEdades,0);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_H_HOMO.resize(numEdades,0);
        m_contabilidad[turno].vacunados_hombres_por_edad.resize(numEdades,0);
        m_contabilidad[turno].vacunados_mujeres_por_edad.resize(numEdades,0);
        m_contabilidad[turno].vacunados_homo_por_edad.resize(numEdades,0);
    }
}


unsigned int CProblema::CuentaPersonas(EVENTO_CONTABLE tipo, unsigned int p_edad)
{
    unsigned int cuenta = 0;

    for (unsigned int nodo = 0; nodo < m_numero_de_nodos; nodo++)
    {
        CPersona &persona = m_grafo.Nodo(nodo);
        if (persona.m_edad == p_edad)
        {
            switch (tipo)
            {
                case C_TOTALINDIVIDUOS_HOMO:
                    if ((persona.m_sexo == HOMBRE) && (persona.m_homosexual))
                        ++cuenta;
                    break;
                case C_TOTALINDIVIDUOS_H_VERRUGABLE:
                    if ((persona.m_sexo == HOMBRE) && (persona.m_verrugable))
                        ++cuenta;
                    break;
                case C_TOTALINDIVIDUOS_H_VERRUGABLE_HOMO:
                    if ((persona.m_sexo == HOMBRE) && (persona.m_verrugable) && (persona.m_homosexual))
                        ++cuenta;
                    break;
                case C_TOTALINDIVIDUOS_H_ONCOGENICO:
                    if ((persona.m_sexo == HOMBRE) && (persona.m_oncogenico))
                        ++cuenta;
                    break;
                case C_TOTALINDIVIDUOS_H_ONCOGENICO_HOMO:
                    if ((persona.m_sexo == HOMBRE) && (persona.m_oncogenico) && (persona.m_homosexual))
                        ++cuenta;
                    break;
                case C_TOTALINDIVIDUOS_M_VERRUGABLE:
                    if ((persona.m_sexo == MUJER) && (persona.m_verrugable))
                        ++cuenta;
                    break;
                case C_TOTALINDIVIDUOS_M_ONCOGENICO:
                    if ((persona.m_sexo == MUJER) && (persona.m_oncogenico))
                        ++cuenta;
                    break;
                case C_TOTALINDIVIDUOS_H:
                    if (persona.m_sexo == HOMBRE)
                        ++cuenta;
                    break;
                case C_TOTALINDIVIDUOS_M:
                    if (persona.m_sexo == MUJER)
                        ++cuenta;
                    break;
                case C_INFECTADO_16_18:
                    if (persona.m_estado_salud_HR == INFECTADO_16_18)
                        ++cuenta;
                    break;
                case C_INFECTADO_16_18_H:
                    if ((persona.m_estado_salud_HR == INFECTADO_16_18)&&
                            (persona.m_sexo == HOMBRE))
                        ++cuenta;
                    break;
                case C_INFECTADO_16_18_M:
                    if ((persona.m_estado_salud_HR == INFECTADO_16_18)&&
                            (persona.m_sexo == MUJER))
                        ++cuenta;
                    break;
                case C_INFECTADO_16_18_H_HOMO:
                    if ((persona.m_estado_salud_HR == INFECTADO_16_18)&&
                            (persona.m_sexo == HOMBRE) && (persona.m_homosexual))
                        ++cuenta;
                    break;
               case C_INFECTADO_6_11:
                    if (persona.m_estado_salud_LR == INFECTADO_6_11)
                        ++cuenta;
                    break;
                case C_INFECTADO_6_11_H:
                    if ((persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == HOMBRE))
                        ++cuenta;
                    break;
                case C_INFECTADO_6_11_M:
                    if ((persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == MUJER))
                        ++cuenta;
                    break;
                case C_INFECTADO_6_11_H_HOMO:
                    if ((persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == HOMBRE) && (persona.m_homosexual))
                        ++cuenta;
                    break;
                case C_INFECTADO_16_18_6_11:
                    if ( (persona.m_estado_salud_HR == INFECTADO_16_18) &&
                            (persona.m_estado_salud_LR == INFECTADO_6_11))
                        ++cuenta;
                    break;
                case C_INFECTADO_16_18_6_11_H:
                    if ( (persona.m_estado_salud_HR == INFECTADO_16_18) &&
                            (persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == HOMBRE))
                        ++cuenta;
                    break;
                case C_INFECTADO_16_18_6_11_M:
                    if ( (persona.m_estado_salud_HR == INFECTADO_16_18) &&
                            (persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == MUJER))
                        ++cuenta;
                    break;
                case C_INFECTADO_16_18_6_11_H_HOMO:
                    if ( (persona.m_estado_salud_HR == INFECTADO_16_18) &&
                            (persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == HOMBRE) && (persona.m_homosexual))
                        ++cuenta;
                    break;
                case C_VACUNADOS_HOMO:
                    if ( (persona.m_vacunado)  &&
                            (persona.m_sexo == HOMBRE) && persona.m_homosexual)
                        ++cuenta;
                    break;
                case C_VACUNADOS_HOMBRES:
                    if ( (persona.m_vacunado)  &&
                            (persona.m_sexo == HOMBRE))
                        ++cuenta;
                    break;
                case C_VACUNADOS_MUJERES:
                    if ( (persona.m_vacunado) &&
                            (persona.m_sexo == MUJER) )
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_16_18://new para abajo
                    if ((persona.m_estado_salud_HR == INFECTADO_16_18)&&
                        (persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_16_18_H:
                    if ((persona.m_estado_salud_HR == INFECTADO_16_18)&&
                            (persona.m_sexo == HOMBRE) && (persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_16_18_M:
                    if ((persona.m_estado_salud_HR == INFECTADO_16_18)&&
                            (persona.m_sexo == MUJER)&&(persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_16_18_H_HOMO:
                    if ((persona.m_estado_salud_HR == INFECTADO_16_18)&&
                            (persona.m_sexo == HOMBRE) && (persona.m_homosexual)&&(persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_6_11:
                    if ((persona.m_estado_salud_LR == INFECTADO_6_11)&&
                        (persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_6_11_H:
                    if ((persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == HOMBRE)&&(persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_6_11_M:
                    if ((persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == MUJER)&&(persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_6_11_H_HOMO:
                    if ((persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == HOMBRE) && (persona.m_homosexual)&&(persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_16_18_6_11:
                    if ( (persona.m_estado_salud_HR == INFECTADO_16_18) &&
                            (persona.m_estado_salud_LR == INFECTADO_6_11)&&(persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_16_18_6_11_H:
                    if ( (persona.m_estado_salud_HR == INFECTADO_16_18) &&
                            (persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == HOMBRE)&&(persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_16_18_6_11_M:
                    if ( (persona.m_estado_salud_HR == INFECTADO_16_18) &&
                            (persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == MUJER)&&(persona.m_vacunado))
                        ++cuenta;
                    break;
                case C_INFECTADO_VACUNADO_16_18_6_11_H_HOMO:
                    if ( (persona.m_estado_salud_HR == INFECTADO_16_18) &&
                            (persona.m_estado_salud_LR == INFECTADO_6_11)  &&
                            (persona.m_sexo == HOMBRE) && (persona.m_homosexual)&&(persona.m_vacunado))
                        ++cuenta;
                    break;
                default:
                    cout << "ERROR en CuentaPersona. Tipo desconocido";
                    while(1);
            }
        }
    }
    return cuenta;
}

unsigned int CProblema::GeneraRed(int p_num_nodos)
{
    m_dado.Inicia(m_generador_de_red);
    m_grafo.Inicia(m_identificador_de_prueba, p_num_nodos);
    //Hace falta para generar la red, algoritmo GRASP o VORAZ
    m_pesos = m_dado.TiraRangoInt(0,40);

    unsigned int tot_mujeres = 0;
    int phh             = 0; //hombres homo
    int ph              = 0; //cantidad de parejas de hombres con LSP < 10
    int pm              = 0; //cantidad de parejas de mujeres con LSP < 10
    int h10             = 0; //cantidad de parejas de hombres con LSP >= 10
    int m10             = 0; //cantidad de parejas de hombres con LSP >= 10
    BASE_TYPE par_h_10  = 0; //cantidad media de parejas de hombres con LSP >= 10
    int mojigato        = 0; //hombre con LSP = 0
    int mojigata        = 0; //mujer con LSP = 0
    int quo             = 0; //Cociente para calcular las parejas de mujeres con LSP >= 10
    int res             = 0; //Resto para calcular las parejas de mujeres con LSP >= 10

    //Elementos para GRAPS
    BASE_TYPE peso_aux    = 0;

    //Estructuras auxiliares para el manejo de nodos donde nos interesa solo la tupla[ID,LSP]
    std::vector<subNodoLSP> subNodosMujeres;
    std::vector<subNodoWeight> subNodosHombres;
    std::vector<subNodoLSP> subNodosHombresHomo;

    m_tot_homo = 0;

    //esta variable pinta el porcentaje de progreso al iterar sobre subNodosMujeres
    string subNodosMujeres_progreso = "";
    string subNodosHombresHomo_progreso = "";

    //tiradas para asignacion de parejas
    int tirada = 0;

    cout << "[Generation random network of ("<< m_numero_de_nodos <<") nodes...]" << endl;
    // Generamos a hombres y mujeres
    for (unsigned int i = 0 ; i < m_numero_de_nodos; i++)
    {
        CPersona persona;
        if (EsHombre())
        {
            persona.m_sexo              = HOMBRE;
            persona.m_edad              = EdadHombres();
            persona.m_homosexual        = ( m_dado.TiraFloat() < m_homosexuales? true : false );
            if (persona.m_homosexual)
            {
                persona.m_LSP           = ParejasHombresHomosexuales(persona.m_edad);
                m_tot_homo++;
            }
            else
            {
                persona.m_LSP           = ParejasHombres(persona.m_edad);
            }
            //Guardamos por el principio los nodos hombres
            persona.m_id = m_tot_hombres;
            m_tot_hombres++;
        }
        else
        {
            persona.m_sexo       = MUJER;
            persona.m_edad       = EdadMujeres();
            persona.m_LSP        = ParejasMujeres(persona.m_edad);
            //Metemos las mujeres desde el final del grafo
            persona.m_id         = m_numero_de_nodos - tot_mujeres - 1;
            tot_mujeres++;
        }
        //COMUN a ambos sexos
        persona.m_mes_nacimiento        = m_dado.TiraRangoInt(0,11);
        //Ingenio para cumplir con el requisitos de vacunacion
        persona.m_edad_meses            = persona.m_edad * 12 + persona.m_mes_nacimiento;
        persona.m_T                     = asigna_T(persona.m_edad);
        //Guardo el nodo
        m_grafo.GuardaNodo(persona, persona.m_id);
    }

    cout << "Calculated no. couples before assigment (<k>param * #men): " << (int) (BASE_TYPE)m_tot_hombres * m_grado_medio <<endl;

    //Validamos la generacion,
    //hay una ligera diferencia
    //en como asigna valores LSP Rafa, cuando LSP es 10, el dice 0,
    //se facilita la vida con Pyhton (operaciones sobre listas)
    for (unsigned int cnt = 0; cnt < m_grafo.m_numnodos; cnt++)
    {
        if ((m_grafo.Nodo(cnt).m_sexo == HOMBRE) && (!m_grafo.Nodo(cnt).m_homosexual))
        {
            //Parejas de hombres con menos de 10 parejas
            if ((m_grafo.Nodo(cnt).m_LSP > 0) && (m_grafo.Nodo(cnt).m_LSP < 10))
            {
                ph+=m_grafo.Nodo(cnt).m_LSP;
            }
            else if (m_grafo.Nodo(cnt).m_LSP == 10)
            {
                ++h10;
            }
            else if ((m_grafo.Nodo(cnt).m_LSP) == 0)
            {
                ++mojigato;//No tiene pareja, es mojigato
                //cout << "Nodo [" << m_grafo.Nodo(cnt).m_sexo <<","<< m_grafo.Nodo(cnt).m_edad<<","<< m_grafo.Nodo(cnt).m_LSP<<"]"<< endl;
            }
        }
        else if (m_grafo.Nodo(cnt).m_sexo == MUJER)
        {
            if ((m_grafo.Nodo(cnt).m_LSP > 0) && (m_grafo.Nodo(cnt).m_LSP < 10))
            {
                pm+=m_grafo.Nodo(cnt).m_LSP;
            }
            else if ((m_grafo.Nodo(cnt).m_LSP) == 10)
            {
                ++m10;
            }
            else if ((m_grafo.Nodo(cnt).m_LSP) == 0)
            {
                ++mojigata;//No tiene pareja, es mojigato
                //cout << "Nodo [" << m_grafo.Nodo(cnt).m_sexo <<","<< m_grafo.Nodo(cnt).m_edad<<","<< m_grafo.Nodo(cnt).m_LSP<<"]"<< endl;
            }
        }
        else if ((m_grafo.Nodo(cnt).m_sexo == HOMBRE) && (m_grafo.Nodo(cnt).m_homosexual))
        {
           true;//no hago nada, no hago comprobaciones de momento
        }
    }
    //Si no hay por lo menos un hombre y una mujer con mas de 10 parejas, la red no sera construible.
    if ( ( h10 == 0 ) || ( m10 == 0 ) )
    {
        cout << "NO ES POSIBLE UNA ASIGNACION CONSISTENTE. No hay individuos con mas de 10 parejas." << endl;
		GuardaEstadoInicialRedParaGrafoWeb(false);
        exit(-1);
    }

    //Numero medio de parejas que tienen los hombres con mas de 10 parejas. Redondeado
    BASE_TYPE tempBASE_TYPE =  (BASE_TYPE)(((BASE_TYPE)m_tot_hombres * m_grado_medio) - ph ) / (BASE_TYPE)h10;
    par_h_10 = (int)( tempBASE_TYPE + 0.5);

    if ( par_h_10 < 10 )
    {
        cout << "NO ES POSIBLE UNA ASIGNACION CONSISTENTE. Los hombres con mas de 10 parejas no tienen mas de 10 parejas: " << par_h_10 <<endl;
		GuardaEstadoInicialRedParaGrafoWeb(false);
        exit(-1);
    }

    // Asignamos valores aleatorios que siguen una distribucion uniforme de media par_h_10 a los hombres
    // con mas de 10 parejas (si es 10 se queda en 10 dado que
    // nosotros no hemos puesto 0 a los que son 10 como hace Rafa en Python)
    if (par_h_10 == 10)
    {
        NULL; //Nada porque ya esta el LSP en 10;
    }
    else
    {
        for (unsigned int cnt = 0; cnt < m_tot_hombres; cnt++)
        {
          if ( (m_grafo.Nodo(cnt).m_sexo == HOMBRE) && (m_grafo.Nodo(cnt).m_LSP == 10) )
            //Distribucion uniforme entre parejas de LSP 10 para darles 10 o más
          {
            tirada = m_dado.TiraRangoInt(10, 2 * par_h_10 - 10);
            m_grafo.Nodo(cnt).m_LSP = tirada;
          }
        }
    }

    // Sumamos las parejas de hombres que hay tras la nueva asignacion.
    // Tendran que ser iguales a las de las mujeres.
    //NUEVA ASIGNACION DE HOMOSEXUALES
    ph = 0;
    for (unsigned int cnt = 0; cnt < m_tot_hombres; cnt++)
        if ((m_grafo.Nodo(cnt).m_sexo == HOMBRE) && !(m_grafo.Nodo(cnt).m_homosexual))
        {
            ph+= m_grafo.Nodo(cnt).m_LSP;
            phh+= m_grafo.Nodo(cnt).m_LSP;//para contar el <k> con homosexuales
        }
        else if (m_grafo.Nodo(cnt).m_LSP)
             phh+= m_grafo.Nodo(cnt).m_LSP;//para contar el <k> con homosexuales


    //Hacemos la asignacion en las mujeres, repartiendo las parejas de forma equitativa
    //Calculamos el cociente y el resto de la division
    //( ph - pm ) / m10
    quo = ( ph - pm ) / m10;
    res = ( ph - pm ) % m10;

    //Si el numero medio de parejas de mujeres con mas de 10 parejas NO es mayor que 10, la red no sera coherente
    if (quo <= 10)
    {
        cout <<  "NO ES POSIBLE UNA ASIGNACION CONSISTENTE. Las mujeres con mas de 10 parejas no tienen mas de 10 parejas: " << quo << endl;
		GuardaEstadoInicialRedParaGrafoWeb(false);
        exit(-1);
    }


    // Ahora asignaremos a res mujeres quo + 1 parejas y quo parejas a las restantes de LSP 10
    // (importante a las de LSP 10)
    int i = 0;
    for (unsigned int cnt = m_tot_hombres; cnt < m_grafo.m_numnodos; cnt++)
    {
        //A las MUJERES LSP 10 les subimos equitativamente su LSP acorde al boost de HOMBRES LSP 10
        if ( (m_grafo.Nodo(cnt).m_sexo == MUJER) && (m_grafo.Nodo(cnt).m_LSP == 10) )
            if ( i < res)
            {
                m_grafo.Nodo(cnt).m_LSP = quo + 1;
                ++i;
            }
            else
            {
                m_grafo.Nodo(cnt).m_LSP = quo;
            }

    }

    // Sumamos las parejas de mujeres que hay tras la nueva asignacion.
    // Tendran que ser iguales a las de los hombres.
    pm = 0;
    for (unsigned int cnt = m_tot_hombres; cnt < m_grafo.m_numnodos; cnt++)
        if (m_grafo.Nodo(cnt).m_sexo == MUJER)
            pm+= m_grafo.Nodo(cnt).m_LSP;


    //verifico lo que he hecho
    cout << "No. men                        : " << m_tot_hombres << endl;
    cout << "No. women                      : " << tot_mujeres << endl;
    cout << "Men couples                    : " << ph << endl;
    cout << "Women couples                  : " << pm << endl;
    cout << "No. h10                        : " << h10 << endl;
    cout << "No. m10                        : " << m10 << endl;
    cout << "Men without couples            : " << mojigato << endl;
    cout << "Women without couples          : " << mojigata << endl;
    cout << "No. homosexual men             : " << m_tot_homo << endl;
    cout << "Sexual active couples          : " << m_tot_hombres - mojigato + tot_mujeres - mojigata << endl;
    cout << "<k>param                       : " << m_grado_medio << endl;
    cout << "<k>generated (excluding gays)  : " << (BASE_TYPE)(ph/(BASE_TYPE)(m_tot_hombres - mojigato)) << endl;
    cout << "<k>generated (including gays)  : " << (BASE_TYPE)(phh/(BASE_TYPE)(m_tot_hombres - mojigato)) << endl;
    cout << "GRASP/GREEDY                   : " << m_pesos << endl;
    cout << "-------------------------------------------------" << endl;


 //Ahora Rafa organiza las mujeres.
    //Las ordena por orden descendente LSP
    subNodoLSP *tuplaM = new subNodoLSP[tot_mujeres];
    int cntMSubnodo = 0;
    subNodosMujeres.clear();
    subNodosMujeres.reserve(tot_mujeres);
    //Empezamos en la primera mujer hasta el final (i = tot_hombres)
    for (unsigned int i = m_tot_hombres; i < m_grafo.m_numnodos; i++)
    {
        CPersona &persona = m_grafo.Nodo(i);
        //Si es mujer y tiene relaciones (LSP > 0)
        if ((persona.m_sexo == MUJER) && (persona.m_LSP > 0))
        {
            tuplaM[cntMSubnodo].pos = i;
            tuplaM[cntMSubnodo].LSP = persona.m_LSP ;
            subNodosMujeres.push_back(tuplaM[cntMSubnodo]);
            cntMSubnodo++;
        }
    }
    delete [] tuplaM;
    //Orden por orden descendente
    std::sort(subNodosMujeres.rbegin(), subNodosMujeres.rend());

    int contTotalParejas = 0;
    int AristaDuplicadas = 0;

// COMIENZA LA CONECTIVADAD HETERO (se excluyen hombres homo)
    // Asignamos la conectividad.
    // El numero de aristas a insertar
    // se rige por el algoritmo GRASP si alfa > 0, si no es GREEDY
    // Itero sobre las mujeres ordenadas por LSP decrecientes
    // (almacenado en estructura vector auxiliar subNodosMujeres de elementos subNodoLSP[pos,LSP])

    //Inicializamos el contador de parejas restantes de los hombres
    for (unsigned int cnt = 0; cnt < m_grafo.m_numnodos; cnt++)
    {
         m_grafo.Nodo(cnt).m_relaciones_pendientes = m_grafo.Nodo(cnt).m_LSP;
    }
    //Inicializamos la variable donde guardaremos los candidatos
	subNodoWeight *tuplaH = new subNodoWeight[m_tot_hombres];

	//esta variable pinta el porcentaje de progreso al iterar sobre subNodosMujeres
    subNodosMujeres_progreso =  porcentaje(0, 0, subNodosMujeres.size() );
    for ( unsigned int i = 0; i < subNodosMujeres.size(); i++ )
    {
        int cnt = 0;
        subNodosHombres.clear();
		subNodosHombres.reserve(m_tot_hombres);
        for ( unsigned int j = 0; j < m_tot_hombres; j++ )
        {
			CPersona &persona = m_grafo.Nodo(j);
            if ((persona.m_sexo == HOMBRE) &&
                (persona.m_relaciones_pendientes > 0) &&
                !(persona.m_homosexual))
            {
                // calculamos el peso entre la mujer i y el hombre j ...
  				//ATENCION CAMBIO 20160309 NUEVA FUNCION DE PESOS
  				//peso_aux = PesoEdades( persona.m_edad,  m_grafo.Nodo(subNodosMujeres[i].pos).m_edad );
  				peso_aux = PesoParejas( persona.m_LSP, subNodosMujeres[i].LSP ) +
                            PesoEdades( persona.m_edad, m_grafo.Nodo(subNodosMujeres[i].pos).m_edad);
                // y lo aniadimos a la lista
                tuplaH[cnt].pos = j;
                tuplaH[cnt].weight = peso_aux;
                subNodosHombres.push_back(tuplaH[cnt]);
                cnt++;
            }
        }
        //Se ordenan por pesos crecientes los hombres
        std::sort(subNodosHombres.begin(), subNodosHombres.end());
        // Tomamos para cada mujer(i) de LSP decreciente los LSP + alfa menores pesos de entre los hombres
        int tope1 = std::min<int> (subNodosHombres.size(), subNodosMujeres[i].LSP + m_pesos);
        int tope2 = std::min<int> (subNodosHombres.size(), subNodosMujeres[i].LSP );
        //Si alfa > 0 es GRASP, si no es GREEDY
        bool masTiradas     = true;
        int tiradasBuenas   = 0;
        int tiradaPos       = 0;
        while (masTiradas)
        {
            tiradaPos = m_dado.TiraRangoInt(0, tope1 - 1);// -1 para no desbordar
            //Si no le he escogido ya y le quedan parejas por asignar
            if (!subNodosHombres[tiradaPos].usado)
            {
                //le marco como escogido para que no salga otra vez
                subNodosHombres[tiradaPos].usado = true;
                //lo cuento como tirada buena
                tiradasBuenas++;
                //emparejo!
                bool no_existe = true;
                no_existe = m_grafo.GuardaAristaDoble(subNodosHombres[tiradaPos].pos, subNodosMujeres[i].pos, TRUE);
                if (no_existe == false)
                    AristaDuplicadas++;
                contTotalParejas++;
                //le quito una pareja al hombre //OJO PIOJO REVISAR
                m_grafo.Nodo(subNodosHombres[tiradaPos].pos).m_relaciones_pendientes--;
            }
            if (tiradasBuenas >= tope2 )
                masTiradas = false;
        }
        //Traza de bucle
//        if (!(i%100))
//        {
//           if (subNodosMujeres_progreso != porcentaje(0, i, subNodosMujeres.size()))
//            {
//                subNodosMujeres_progreso = porcentaje(0, i, subNodosMujeres.size());
//                cout << subNodosMujeres_progreso << "pinta\n";
//                backline();
//                colea();
//            }
//        }
    }
	delete [] tuplaH;
    //Limpiamos estructuras
    subNodosMujeres.clear();
    subNodosHombres.clear();
	cout << "-> edges generated in: "<< m_reloj.segundos_transcurridos() << "(s)"<< endl;

 //Ahora Victor organiza los homosexuales.
    //Los ordena por orden descendente por numero de parejas
    subNodoLSP *tuplaHomo = new subNodoLSP[m_tot_homo];
    int numAristasHomo = 0;
    int cntHomoSubnodo = 0;
    subNodosHombresHomo.clear();
    subNodosHombresHomo.reserve(m_tot_homo);
    //Empezamos en la primera mujer hasta el final (i = tot_hombres)
    for  (unsigned int i = 0; i < m_tot_hombres; i++)
    {
        //Si es homo y tiene relaciones (LSP > 0)
        if ((m_grafo.Nodo(i).m_sexo == HOMBRE) &&
            (m_grafo.Nodo(i).m_LSP > 0) &&
            (m_grafo.Nodo(i).m_homosexual))
        {
            tuplaHomo[cntHomoSubnodo].pos = i;
            tuplaHomo[cntHomoSubnodo].LSP = m_grafo.Nodo(i).m_LSP ;
            subNodosHombresHomo.push_back(tuplaHomo[cntHomoSubnodo]);
            cntHomoSubnodo++;
        }
    }
    delete [] tuplaHomo;
    //Orden por orden descendente por lsp
    std::sort(subNodosHombresHomo.rbegin(), subNodosHombresHomo.rend());


// COMIENZA LA CONECTIVADAD HOMOSEXUAL
    //string trazaHomo ="";
    // Asignamos la conectividad
    //, el numero de aristas a insertar
    // se rige por el algoritmo GRASP si alfa > 0, si no es greedy
    //Itero sobre las mujeres ordenadas por LSP decrecientes

    //Inicializamos el contador de parejas restantes de los hombres
    for (unsigned int cnt = 0; cnt < m_grafo.m_numnodos; cnt++)
    {
         m_grafo.Nodo(cnt).m_relaciones_pendientes = m_grafo.Nodo(cnt).m_LSP;
    }
    //Inicializamos la variable donde guardaremos los candidatos
	subNodoWeight *tuplaHomoCandidato = new subNodoWeight[m_tot_hombres];

    //esta variable pinta el porcentaje de progreso al iterar sobre subNodosHomo
    subNodosHombresHomo_progreso =  porcentaje(0, 0, subNodosHombresHomo.size() );
    for (unsigned int i = 0; i < subNodosHombresHomo.size(); i++)
    {
        int cnt = 0;
        subNodosHombres.clear();
        subNodosHombres.reserve(m_tot_hombres);
        for (unsigned int j = 0; j < m_tot_hombres; j++)
        {
            CPersona &persona = m_grafo.Nodo(j);
            if ((persona.m_sexo == HOMBRE) &&
                (persona.m_relaciones_pendientes > 0) &&
                (persona.m_homosexual) &&
                (subNodosHombresHomo[i].pos != j) )//y no eres tu mismo
            {
                // calculamos el peso entre el homo i y el homo j ...
                //ATENCION CAMBIO 20160309 NUEVA FUNCION DE PESOS
                //peso_aux = PesoEdades( persona.m_edad,  m_grafo.Nodo(subNodosHombresHomo[i].pos).m_edad );
                peso_aux = PesoParejas( persona.m_LSP, subNodosHombresHomo[i].LSP ) +
                            PesoHomos(persona.m_edad, m_grafo.Nodo(subNodosHombresHomo[i].pos).m_edad ) +
                            PesoEdades( persona.m_edad,  m_grafo.Nodo(subNodosHombresHomo[i].pos).m_edad );;
                // y lo aniadimos a la lista
                tuplaHomoCandidato[cnt].pos = j;
                tuplaHomoCandidato[cnt].weight = peso_aux;
                subNodosHombres.push_back(tuplaHomoCandidato[cnt]);
                cnt++;
            }
        }
        std::sort(subNodosHombres.begin(), subNodosHombres.end());
        // Tomamos para cada hombre homosexual(i) de LSP decreciente los LSP + alfa menores pesos de entre los hombres
        int tope1 = std::min<int> (subNodosHombres.size(), subNodosHombresHomo[i].LSP + m_pesos);
        int tope2 = std::min<int> (subNodosHombres.size(), subNodosHombresHomo[i].LSP );
        //Si alfa > 0 es GRASP, si no es greedy
        bool masTiradas     = true;
        int tiradasBuenas   = 0;
        int tiradaPos       = 0;
        while (masTiradas)
        {
            if (tope1 == 0) break;
            tiradaPos = m_dado.TiraRangoInt(0, tope1 - 1 );// -1 para no desbordar
            //Si no le he escogido ya y le quedan parejas por asignar
            if (!subNodosHombres[tiradaPos].usado)
            {
                //le marco como escogido para que no salga otra vez
                subNodosHombres[tiradaPos].usado = true;
                //lo cuento como tirada buena
                tiradasBuenas++;
                //emparejo!
                numAristasHomo++;
                bool no_existe = true;
                no_existe = m_grafo.GuardaAristaDoble(subNodosHombres[tiradaPos].pos, subNodosHombresHomo[i].pos, TRUE);
                if (no_existe == false)
                    AristaDuplicadas++;
                contTotalParejas++;
                //le quito una pareja al hombre //OJO PIOJO REVISAR
                m_grafo.Nodo(subNodosHombres[tiradaPos].pos).m_relaciones_pendientes--;
            }
            if (tiradasBuenas >= tope2 )
                masTiradas = false;
        }
        //cout << "tiradas: " << tiradasMalas << " | " << tiradasBuenas << endl;
        //Traza de bucle
//        if (!(i%100))
//        {
//           if (subNodosHombresHomo_progreso != porcentaje(0, i, subNodosHombresHomo.size()))
//            {
//                subNodosHombresHomo_progreso = porcentaje(0, i, subNodosHombresHomo.size());
//                cout << subNodosHombresHomo_progreso;
//                backline();
//                colea();
//            }
//        }
    }//end bucle personaBuscona

	delete [] tuplaHomoCandidato;

	cout << "-> No. gay edges generated: " << numAristasHomo << endl;
	//TRAZA(trazaHetero + trazaHomo + "\n");

///////////////////// fin asignacion


//Guinda al pastel
    //Asignar una mujer de mas de cuatro parejas a cada homo
    tuplaM = new subNodoLSP[tot_mujeres];
    cntMSubnodo = 0;
    subNodosMujeres.clear();
    subNodosMujeres.reserve(tot_mujeres);
    //Empezamos en la primera mujer hasta el final (i = tot_hombres)
    for (unsigned int i = m_tot_hombres; i < m_grafo.m_numnodos; i++)
    {
        //Si es mujer y tiene relaciones (LSP > 0 ojo con m_LSP, el m_relaciones_pendientes esta a 0)
        if ((m_grafo.Nodo(i).m_sexo == MUJER) && (m_grafo.Nodo(i).m_LSP > 4))
        {
            tuplaM[cntMSubnodo].pos = i;
            subNodosMujeres.push_back(tuplaM[cntMSubnodo]);
            cntMSubnodo++;
        }

    }
    //free de la estructura
    delete [] tuplaM;

    //Guardo y no ordeno subNodosMujeres porque me interesan mujeres aleatorias con LSP>4
    for (unsigned int i = 0; i < subNodosHombresHomo.size(); i++)
    {
        m_grafo.GuardaAristaDoble(subNodosMujeres[m_dado.TiraRangoInt(0, subNodosMujeres.size())].pos, subNodosHombresHomo[i].pos, TRUE);
    }

    //Clear de las estructuras
    subNodosMujeres.clear();
    subNodosHombres.clear();
    subNodosHombresHomo.clear();

    cout << "----------> Network generated in: "<< m_reloj.segundos_transcurridos() << "(s) <---------"<< endl;
    cout << endl;
    //cout << "generando media y desviacion (ver ficheros)..." << endl;
    //DesviacionEdadRed(MediaEdadRed(ph), ph);
    //TrazaPesos();
    return m_tot_homo;
}

bool CProblema::TrazaPesos()
{
    unsigned int vecinas = 0;
    string  traza;
    //Recorremos los hombres
    for (unsigned int persona = 0; persona < m_tot_hombres; persona++)
    {
        CPersona &sujeto_actual = m_grafo.Nodo(persona);
        if (!sujeto_actual.m_homosexual)
        {


            vecinas = m_grafo.CuantosVecinos(persona);
            //Recorremos las aristas vecinas mujeres
            for (unsigned int i = 0; i < vecinas ; i++)
            {
                traza+= entero_a_texto( sujeto_actual.m_edad_meses) + ", ";
                traza+= entero_a_texto(m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_edad_meses) + "\n";
            }
        }
    }
    TRAZA("edades" + entero_a_texto((int)time(NULL)) , traza);

    return true;
}

BASE_TYPE CProblema::MediaEdadRed(int contTotalParejas)
{
    int peso_aux = 0;int cont = 0;
    BASE_TYPE media = 0;
    string traza = "";
    unsigned int vecinas = 0;
    for (unsigned int persona = 0; persona < m_tot_hombres; persona++)
    {
        CPersona &sujeto_actual = m_grafo.Nodo(persona);
        vecinas = m_grafo.CuantosVecinos(persona);
        if (!sujeto_actual.m_homosexual)
        {
            //Recorremos las aristas vecinas
            for (unsigned int i = 0; i < vecinas ; i++)
            {
                peso_aux = sujeto_actual.m_edad - m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_edad;
                media += peso_aux;
                cont++;
            }
        }
    }
    traza += "\n" + TipoBase_a_texto(m_alpha_1) +
                "\n" + TipoBase_a_texto(m_alpha_2) +
                "\n";
    media = media / contTotalParejas;
    traza += TipoBase_a_texto(media);
    TRAZA("Media" + entero_a_texto((int)time(NULL)) , traza);
    return media;
}

BASE_TYPE CProblema::DesviacionEdadRed(BASE_TYPE media, int contTotalParejas)
{
    int peso_aux = 0;
    int cont = 0;
    BASE_TYPE desviacion_tipica = 0;
    BASE_TYPE aux = 0.0;
    string traza = "";
    unsigned int vecinas = 0;
    for (unsigned int persona = 0; persona < m_tot_hombres; persona++)
    {
        CPersona &sujeto_actual = m_grafo.Nodo(persona);
        vecinas = m_grafo.CuantosVecinos(persona);
        if (!sujeto_actual.m_homosexual)
        {
            //Recorremos las aristas vecinas
            for (unsigned int i = 0; i < vecinas ; i++)
            {
                peso_aux = sujeto_actual.m_edad - m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_edad;
                aux = (BASE_TYPE)peso_aux - media;
                aux = aux * aux;
                desviacion_tipica += aux;
                cont++;
            }
        }
    }

    desviacion_tipica = (  desviacion_tipica / ((BASE_TYPE)contTotalParejas - 1) );
    desviacion_tipica = sqrt(  desviacion_tipica );
    traza += "\n tot parejas:" + entero_a_texto(contTotalParejas) +
            "\n" + TipoBase_a_texto(m_alpha_1) +
            "\n" + TipoBase_a_texto(m_alpha_2) +
            "\n";
    traza += TipoBase_a_texto(desviacion_tipica);
    TRAZA("Desviacion" + entero_a_texto((int)time(NULL)) , traza);
    return desviacion_tipica;
}

bool CProblema::GuardaRed(string archivo)
{
    CArchivoTexto salida;
    bool resultado = false;
    unsigned int arista = 0;
    unsigned int vertice = 0;
    unsigned int cuantosVecinos = 0;
    string linea = "";
    string separador = "\t";
    unsigned int porcentaje = 0;

    cout << "GuardaRed_INI... " << m_reloj.segundos_transcurridos() << "s" << endl;

    resultado = salida.AbreArchivoEscritura(archivo);

    if (resultado)
    {
        // Guardamos ID
        salida.GuardaTexto("m_identificador_de_prueba\n");
        salida.GuardaTexto(m_identificador_de_prueba);
        salida.GuardaTexto("\n");
        // Guardamos consumo RAM
        salida.GuardaTexto("m_consumo_RAM\n");
        salida.GuardaTexto(entero_a_texto(m_consumo_RAM));
        salida.GuardaTexto("\n");
        // Guardamos generador de red
        salida.GuardaTexto("m_generador_de_red\n");
        salida.GuardaTexto(TipoBase_a_texto(m_generador_de_red));
        salida.GuardaTexto("\n");
        // Guardamos turnos a simular
        salida.GuardaTexto("m_turnos_a_simular\n");
        salida.GuardaTexto(entero_a_texto(m_turnos_a_simular));
        salida.GuardaTexto("\n");
        // Guardamos numero de realizaciones
        salida.GuardaTexto("m_realizaciones\n");
        salida.GuardaTexto(entero_a_texto(m_realizaciones));
        salida.GuardaTexto("\n");
        // Guardamos numero de habitantes
        salida.GuardaTexto("Habitantes actuales\n");
        salida.GuardaTexto(entero_a_texto(m_numero_de_nodos));
        salida.GuardaTexto("\n");
        // Guardamos grado medio K
        salida.GuardaTexto("Grado Medio K\n");
        salida.GuardaTexto(TipoBase_a_texto(m_grado_medio));
        salida.GuardaTexto("\n");
        // Guardamos desplazamiento T
        salida.GuardaTexto("Desplazamiento T\n");
        salida.GuardaTexto(entero_a_texto(m_T_desplazado));
        salida.GuardaTexto("\n");
        // Guardamos parametros del factor de infeccion
        salida.GuardaTexto("Factor de contagio T0\n");
        salida.GuardaTexto(TipoBase_a_texto(m_T0));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("Factor de contagio T1\n");
        salida.GuardaTexto(TipoBase_a_texto(m_T1));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("Factor de contagio T2\n");
        salida.GuardaTexto(TipoBase_a_texto(m_T2));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("Factor de contagio T3\n");
        salida.GuardaTexto(TipoBase_a_texto(m_T3));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_meanDuration_H_16_18\n");
        salida.GuardaTexto(TipoBase_a_texto(m_meanDuration_H_16_18));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_meanDuration_M_16_18\n");
        salida.GuardaTexto(TipoBase_a_texto(m_meanDuration_M_16_18));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_meanDuration_H_6_11\n");
        salida.GuardaTexto(TipoBase_a_texto(m_meanDuration_H_6_11));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_meanDuration_M_6_11\n");
        salida.GuardaTexto(TipoBase_a_texto(m_meanDuration_M_6_11));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_probabilidad_de_contagio_M_6_11\n");
        salida.GuardaTexto(TipoBase_a_texto(m_probabilidad_de_contagio_M_6_11));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_probabilidad_de_contagio_H_6_11\n");
        salida.GuardaTexto(TipoBase_a_texto(m_probabilidad_de_contagio_H_6_11));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_probabilidad_de_contagio_M_16_18\n");
        salida.GuardaTexto(TipoBase_a_texto(m_probabilidad_de_contagio_M_16_18));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_probabilidad_de_contagio_H_16_18\n");
        salida.GuardaTexto(TipoBase_a_texto(m_probabilidad_de_contagio_H_16_18));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_pv\n");
        salida.GuardaTexto(TipoBase_a_texto(m_pv));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_cv\n");
        salida.GuardaTexto(TipoBase_a_texto(m_cv_ninias));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_pp\n");
        salida.GuardaTexto(TipoBase_a_texto(m_pp));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_tp\n");
        salida.GuardaTexto(TipoBase_a_texto(m_tp));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_mes_vacunacion\n");
        salida.GuardaTexto(entero_a_texto(m_mes_vacunacion_ini));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_14_17__HR\n");
        salida.GuardaTexto(TipoBase_a_texto(m_14_17__HR));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_14_17__AMBOS\n");
        salida.GuardaTexto(TipoBase_a_texto(m_14_17__AMBOS));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_18_29__HR\n");
        salida.GuardaTexto(TipoBase_a_texto(m_18_29__HR));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_18_29__AMBOS\n");
        salida.GuardaTexto(TipoBase_a_texto(m_18_29__AMBOS));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_30_39__HR\n");
        salida.GuardaTexto(TipoBase_a_texto(m_30_39__HR));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_30_39__AMBOS\n");
        salida.GuardaTexto(TipoBase_a_texto(m_30_39__AMBOS));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_40_65__HR\n");
        salida.GuardaTexto(TipoBase_a_texto(m_40_65__HR));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("m_40_65__AMBOS\n");
        salida.GuardaTexto(TipoBase_a_texto(m_40_65__AMBOS));
        salida.GuardaTexto("\n");
        salida.GuardaTexto("(Edad)\t(EdadMes)\t(MesNac)\t(T)\t(sex)\t(LSPresto)\t(LSP)\t(16_18)\t(6_11)\t(t_16_18)\t(t_6_11)\t(Vecinos...\n");
        for (vertice = 0; vertice < m_numero_de_nodos; vertice++)
        {
            // Guardamos datos de cada nodo
            linea = "";
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_edad);
            linea += separador;
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_edad_meses);
            linea += separador;
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_mes_nacimiento);
            linea += separador;
            linea += TipoBase_a_texto(m_grafo.Nodo(vertice).m_T);
            linea += separador;
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_sexo);
            linea += separador;
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_relaciones_pendientes);
            linea += separador;
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_LSP);
            linea += separador;
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_estado_salud_HR);
            linea += separador;
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_estado_salud_LR);
            linea += separador;
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_tiempo_estado_salud_16_18);
            linea += separador;
            linea += entero_a_texto(m_grafo.Nodo(vertice).m_tiempo_estado_salud_6_11);
            linea += separador;
            cuantosVecinos = m_grafo.CuantosVecinos(vertice);
            linea += entero_a_texto(cuantosVecinos);
            linea += separador;
            for (arista = 0; arista < cuantosVecinos; arista++)
            {
                linea += entero_a_texto(m_grafo.Vecino(vertice, arista));
                linea += separador;
            }

            linea += "\n";
            salida.GuardaTexto(linea);

            unsigned int divisor = (unsigned int)(m_numero_de_nodos/100.0);
            if (divisor < 1)
                divisor = 1;
            if (!(vertice % divisor))
            {
                cout << "Guardando red " << porcentaje << "%";
                backline();
                ++porcentaje;
            }
        }

      linea += "FIN DE ARCHIVO";

      salida.GuardaTexto(linea);
      salida.CierraArchivo();
      cout <<  "GuardaRed_FIN..." << m_reloj.segundos_transcurridos() << "s" << endl;
      return true;
    }

  return false;
}

bool CProblema::LeeRed(string archivo)
{
    CArchivoTexto entrada;
    bool resultado = false;
    unsigned int arista = 0;
    unsigned int vertice = 0;
    unsigned int numVecinos = 0;
    string linea = "";

    cout << "LeeRed_INI..." << m_reloj.segundos_transcurridos() << "s" <<  endl;
    resultado = entrada.AbreArchivoLectura(archivo);
    if (resultado)
    {
        // Leer ID
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_identificador_de_prueba = linea;
        // Leer ID
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_consumo_RAM = texto_a_entero(linea);
        // Leer ID
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_generador_de_red = texto_a_TipoBase(linea);
        // Leer ID
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_turnos_a_simular = texto_a_entero(linea);
        // Leer ID
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_realizaciones = texto_a_entero(linea);
        // Leemos numero de habitantes
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_numero_de_nodos = texto_a_entero(linea);
        m_grafo.Inicia(m_identificador_de_prueba,m_numero_de_nodos);

        // Guardamos grado medio K
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_grado_medio = texto_a_TipoBase(linea);
        // Leemos parametros del factor de infeccion
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_T_desplazado = texto_a_entero(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_T0 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_T1 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_T2 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_T3 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_meanDuration_H_16_18 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_meanDuration_M_16_18 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_meanDuration_H_6_11 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_meanDuration_M_6_11 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_probabilidad_de_contagio_M_6_11 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_probabilidad_de_contagio_H_6_11 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_probabilidad_de_contagio_M_16_18 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_probabilidad_de_contagio_H_16_18 = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_pv = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_cv_ninias = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_pp = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_tp = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_mes_vacunacion_ini = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_14_17__HR = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_14_17__AMBOS = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_18_29__HR = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_18_29__AMBOS = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_30_39__HR = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_30_39__AMBOS = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_40_65__HR = texto_a_TipoBase(linea);
        entrada.LeeLinea(linea);
        entrada.LeeLinea(linea);
        m_40_65__AMBOS = texto_a_TipoBase(linea);

        // Leemos malla de relaciones
        entrada.LeeLinea(linea);
        for (vertice = 0; vertice < m_numero_de_nodos; vertice++)
        {
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_edad = texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_edad_meses = texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_mes_nacimiento = texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_T = texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_sexo = (SEXOSUJETO) texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_relaciones_pendientes = texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_LSP = texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_estado_salud_HR = (ESTADO_SALUD_TIPO) texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_estado_salud_LR = (ESTADO_SALUD_TIPO) texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_tiempo_estado_salud_16_18 = texto_a_entero(linea);
            entrada.LeePalabra(linea);
            m_grafo.Nodo(vertice).m_tiempo_estado_salud_6_11 = texto_a_entero(linea);
            entrada.LeePalabra(linea);
            numVecinos = texto_a_entero(linea);
            m_grafo.m_nodos.erase(m_grafo.m_nodos.begin(),m_grafo.m_nodos.end());
            for (arista = 0; arista < numVecinos; arista++)
            {
                entrada.LeePalabra(linea);
                m_grafo.GuardaArista(vertice, texto_a_entero(linea));
            }
            entrada.LeeLinea(linea);
        }

        entrada.CierraArchivo();
        cout << "LeeRed_FIN..." << m_reloj.segundos_transcurridos() << "s" <<  endl;
        return true;
    }
    return false;

}

bool CProblema::GuardaEstadoInicialRedParaGrafoWeb(bool valida)
{
    CArchivoTexto salida;
    string cadena;
    string parMujAntes = "parMujAntes = {";
    string parHomAntes = "parHomAntes = {";
    string edadesH = "edadesH = {";
    string edadesM = "edadesM = {";
    string matching = "matching = {";
    string hombresSinPareja = "hombresSinPareja = ";
    string mujeresSinPareja = "mujeresSinPareja = ";
    unsigned int mojigatos = 0;
	unsigned int mojigatas = 0;
	unsigned int tot_hombres = 0;
	unsigned int tot_mujeres = 0;
	unsigned int aristas = 0;
	unsigned int ph = 0;
	string PobTotal = "PobTotal = " + entero_a_texto(m_numero_de_nodos) + "\n";
    string tiempoEjec = "tiempoEjec = ";


    CCRC32 crc;

    if (salida.AbreArchivoEscritura( "net_" + entero_a_texto((int)time(NULL)) + m_solucion_de_salida ) == false)
        return false;

    if (valida == false)
    {
        cadena = "ERROR";
    }
    else
    {
		cadena = " (* ID de prueba, RAM, generador de red, turnos, realizaciones, nodos, grado medio, alfa *)\n";
        cadena += "problema={" + m_identificador_de_prueba + ",";
        cadena += entero_a_texto(m_consumo_RAM)+",";
        cadena += TipoBase_a_texto(m_generador_de_red)+",";
        cadena += entero_a_texto(m_turnos_a_simular)+",";
        cadena += entero_a_texto(m_realizaciones)+",";
        cadena += entero_a_texto(m_numero_de_nodos)+",";
        cadena += TipoBase_a_texto(m_grado_medio)+",";
        cadena += entero_a_texto(m_pesos);
		cadena += "}; \n";
		cadena += "(* poblacion, hombresSinPareja, mujeresSinPareja, edadesH, edadesM, parHomAntes, parMujAntes, tiempoEjec, auxililares, CRC... *)\n";

        for (unsigned int cnt = 0; cnt < m_grafo.m_numnodos; cnt++)
        {
            if (m_grafo.Nodo(cnt).m_sexo == HOMBRE)
            {
                tot_hombres++;
                aristas = m_grafo.CuantosVecinos(cnt);
                ph+=aristas;
                if (aristas > 0)
                    parHomAntes +=  entero_a_texto(aristas) + ",";
                else
                    mojigatos++;
                edadesH += entero_a_texto(m_grafo.Nodo(cnt).m_edad) + ",";
            }

            else//MUJER
            {
                tot_mujeres++;
                aristas = m_grafo.CuantosVecinos(cnt);
                if (aristas > 0)
                    parMujAntes +=  entero_a_texto(aristas) + ",";
                else mojigatas ++;
                edadesM += entero_a_texto(m_grafo.Nodo(cnt).m_edad) + ",";
            }

        }
        hombresSinPareja += entero_a_texto(mojigatos) + ";\n";
        mujeresSinPareja += entero_a_texto(mojigatas) + ";\n";
        edadesH.erase(edadesH.size() - 1);//apanio el final del string
        edadesM.erase(edadesM.size() - 1);//apanio el final del string
        parHomAntes.erase(parHomAntes.size() - 1);//apanio el final del string
        parMujAntes.erase(parMujAntes.size() - 1);//apanio el final del string
        edadesH += "};\n";
        edadesM += "};\n";
        parHomAntes += "};\n";
        parMujAntes += "};\n";
        cadena += PobTotal + hombresSinPareja + mujeresSinPareja + edadesH+ edadesM + parHomAntes + parMujAntes;

        //recorre mujeres
        for (unsigned int i = tot_hombres; i < m_numero_de_nodos ; i++ )
        {
            aristas = m_grafo.CuantosVecinos(i);
            for (unsigned int j = 0; j < aristas ; j++)//{id_hombre,id_mujer}
                matching+="{" + entero_a_texto( m_grafo.Vecino(i, j) )+ "," + entero_a_texto(i)  + "},";
        }

        //Pintar traza homo a continuacion
        matching += m_traza;

        matching.erase(matching.size() - 1);//apanio el final del string la coma de "},"
        matching += "}; ";
        cadena += matching;


        BASE_TYPE k_network = (BASE_TYPE)(ph/(BASE_TYPE)(tot_hombres - mojigatos));

        cadena += "auxiliares={"+ entero_a_texto(m_numero_de_nodos) +
        "," + TipoBase_a_texto (m_grado_medio) +
        "," + entero_a_texto (m_pesos) +
        "," + entero_a_texto((unsigned int)m_reloj.segundos_transcurridos()) +
        ","  + TipoBase_a_texto( k_network ) +
        "," +  entero_a_texto( tot_hombres - mojigatos + tot_mujeres - mojigatas ) +
        "," +  entero_a_texto( tot_hombres  ) +
        "," +  entero_a_texto( tot_mujeres );
        cadena += "}; ";
        cadena += tiempoEjec + entero_a_texto((unsigned int)m_reloj.segundos_transcurridos()) + "\n";
        crc.InsertaCRCASCII(cadena);
    }

    if (salida.GuardaTexto(cadena) == false)
        return false;
    if (salida.CierraArchivo() == false)
        return false;

    return true;
}

/**
*
*/
bool CProblema::existe500Error()
{
    CArchivoTexto salida;
    if (salida.AbreArchivoEscritura(m_identificador_de_prueba + "_500.error") == false)
        return false;
}


/**
 * It saves the .sol file
 *
 * @param valida tells is ERROR generated
 * @return tells if there was an error
 */
bool CProblema::GuardaSimulacion(bool valida)
{
    CArchivoTexto salida;
    string cadena;
    unsigned int turno;
	unsigned int edad;
    CCRC32 crc;

    string err500 = m_solucion_de_salida;

    if (valida == false)
    {
       err500 = m_identificador_de_prueba + "_500.sol";
    }

    if (salida.AbreArchivoEscritura(err500) == false)
        return false;

    cadena = " (* RAM, generador de red, turnos, realizaciones, nodos, grado medio M LSP, pesos P , T desplazado, T0, T1, T2, T3 *)\n";
    cadena += "problema={";
    cadena += m_identificador_de_prueba +",";
    cadena += entero_a_texto(m_consumo_RAM)+",";
    cadena += TipoBase_a_texto(m_generador_de_red)+",";
    cadena += entero_a_texto(m_turnos_a_simular)+",";
    cadena += entero_a_texto(m_realizaciones)+",";
    cadena += entero_a_texto(m_numero_de_nodos)+",";
    cadena += TipoBase_a_texto(m_grado_medio)+",";
    cadena += entero_a_texto(m_pesos)+",";
    cadena += entero_a_texto(m_T_desplazado)+",";
    cadena += TipoBase_a_texto(m_T0)+",";
    cadena += TipoBase_a_texto(m_T1)+",";
    cadena += TipoBase_a_texto(m_T2)+",";
    cadena += TipoBase_a_texto(m_T3);
    cadena += "};\n";
    cadena += "(* {{turno,{edad, poblacion_por_edad_H, poblacion_por_edad_M, poblacion_por_edad_Homo, infectados_por_edad_HR_H, infectados_por_edad_HR_M ,infectados_por_edad_HR_H_HOMO, infectados_por_edad_LR_H, infectados_por_edad_LR_M, infectados_por_edad_LR_H_HOMO, infectados_por_edad_HR_LR_H, infectados_por_edad_HR_LR_M, infectados_por_edad_HR_LR_H_HOMO, vacunados_hombres_por_edad, vacunados_mujeres_por_edad, vacunados_homo_por_edad, infectados_vacunados_por_edad_HR_H, infectados_vacunados_por_edad_HR_M, infectados_vacunados_por_edad_HR_H_HOMO, infectados_vacunados_por_edad_LR_H, infectados_vacunados_por_edad_LR_M, infectados_vacunados_por_edad_LR_H_HOMO, infectados_vacunados_por_edad_HR_LR_H, infectados_vacunados_por_edad_HR_LR_M, infectados_vacunados_por_edad_HR_LR_H_HOMO}}}, auxililares, CRC...*)\n";
    cadena += " solucion={ ";

    for (turno = 0; turno < m_contabilidad.size() ; turno++)  //1-600
    {
        cadena += "{";
        cadena += entero_a_texto(turno)+",{";
        for (edad = 14; edad <= 65; edad++)
        {
            cadena += "{";
    /*1*/	cadena += entero_a_texto(edad)+",";
            cadena += entero_a_texto(m_contabilidad[turno].poblacion_por_edad_H[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].poblacion_por_edad_M[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].poblacion_por_edad_HOMO[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_por_edad_HR_H[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_por_edad_HR_M[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_por_edad_HR_H_HOMO[edad-14])+",";//NEW
            cadena += entero_a_texto(m_contabilidad[turno].infectados_por_edad_LR_H[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_por_edad_LR_M[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_por_edad_LR_H_HOMO[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_por_edad_HR_LR_H[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_por_edad_HR_LR_M[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_por_edad_HR_LR_H_HOMO[edad-14])+",";
/*14*/  		cadena += entero_a_texto(m_contabilidad[turno].vacunados_hombres_por_edad[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].vacunados_mujeres_por_edad[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].vacunados_homo_por_edad[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_vacunados_por_edad_HR_H[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_vacunados_por_edad_HR_M[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_vacunados_por_edad_HR_H_HOMO[edad-14])+",";//NEW
            cadena += entero_a_texto(m_contabilidad[turno].infectados_vacunados_por_edad_LR_H[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_vacunados_por_edad_LR_M[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_vacunados_por_edad_LR_H_HOMO[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_H[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_M[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_H_HOMO[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].poblacion_por_edad_H_VERRUGABLE[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].poblacion_por_edad_M_VERRUGABLE[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].poblacion_por_edad_H_VERRUGABLE_HOMO[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].poblacion_por_edad_H_ONCOGENICO[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].poblacion_por_edad_M_ONCOGENICO[edad-14])+",";
            cadena += entero_a_texto(m_contabilidad[turno].poblacion_por_edad_H_ONCOGENICO_HOMO[edad-14])+"}";
            if (edad <= 65 - 1)
                cadena += ",";
        }
        if (turno < m_contabilidad.size() -1 )
            cadena += "}},";
        else
            cadena +="}";
    }
    cadena += "}};";
    cadena += "auxiliares={";
    cadena += entero_a_texto((unsigned int)m_reloj.segundos_transcurridos());
    cadena += "};";
    crc.InsertaCRCASCII(cadena);


    if (salida.GuardaTexto(cadena) == false)
        return false;
    if (salida.CierraArchivo() == false)
        return false;

    return true;
}

//Assortativity actual
BASE_TYPE CProblema::PesoParejas(int parejas1, int parejas2)
{
    BASE_TYPE ret = -1;
    // Si las parejas de cada uno son menores que 5, consideraremos el minimo entre la suma de parejas y 6.
    // De esta forma para pocas parejas se relacionan entre ellos y con mas parejas, mas mezcla
    if ((parejas1 <= 4) && (parejas2 <= 4))
    {
        ret = abs(parejas1 - parejas2);
    }
    else if ((parejas1 >= 5) && (parejas2 >= 5))
    {
        ret = 0;
    }
    else
        ret = 100;

    ret = m_alpha_1 * ret;
    //cout << "peso por parejas: "+TipoBase_a_texto(ret) << endl;
    return ret;
}

//20170305
BASE_TYPE CProblema::PesoEdades(int edadH, int edadM)
{
    BASE_TYPE ret = -1.0;
    // Si las parejas de cada uno son menores que 5, consideraremos el minimo entre la suma de parejas y 6.
    // De esta forma para pocas parejas se relacionan entre ellos y con mas parejas, mas mezcla
    if ((edadH <= 18) && (edadH < 20))
    {
        ret = abs(edadH - edadM + 3);
    }
    else if ((edadH <= 20) && (edadH < 40))
    {
        ret = abs(0.8 * edadH - edadM + 5.7);
    }
    else
    {
        ret = abs(edadH - edadM - 1.8);
    }

    ret = m_alpha_2 * ret;
    //cout << TipoBase_a_texto(ret) << endl;
    return ret;

}

//p_tiempo_estado_salud esta en meses y las mean duration en anios
bool CProblema::seRecupera(CPersona p1, bool HR)
{
    bool res = false;
    float aux = (float)(HR ? p1.m_tiempo_estado_salud_16_18 : p1.m_tiempo_estado_salud_6_11) / 12.0;
    if (HR && ( aux > (p1.m_sexo == HOMBRE ? m_meanDuration_H_16_18 : m_meanDuration_M_16_18)))
    {
        res = true;
    }//LR
    else if  (!HR && ( aux > (p1.m_sexo == HOMBRE ? m_meanDuration_H_6_11 : m_meanDuration_M_6_11)))
    {
        res = true;
    }
    return res;
}


//Asignar una mujer de mas de cuatro parejas a cada homo
bool CProblema::asignaMujer2Homo(unsigned int p_tot_hombres, unsigned int id_nodo_homo)
{
    bool salir = false;
    int dado = 0;
    while (not salir)
    {
        dado = m_dado.TiraRangoInt(p_tot_hombres, m_grafo.m_numnodos - 1);
        if (m_grafo.Nodo(dado).m_LSP > 4)
        {
            salir = true;
            m_grafo.GuardaAristaDoble(dado, id_nodo_homo, TRUE);
        }
    }

    return salir;
}



void CProblema::SimulaPoblacion()
{
    //comprobaciones dinamicas
    unsigned int contAristasDinamicasHeteroBorradas = 0;
    unsigned int contAristasDinamicasHetero = 0;
    unsigned int contAristasDinamicasHomo = 0;
    unsigned int contAristasDinamicasHomoBorradas = 0;
    bool realizadoVerrugableOncogenico = false;
    unsigned int turno              = 0;
    unsigned int persona            = 0;
    unsigned int vecinas            = 0;
    int contVacHombres              = 0;
    int contVacMujeres              = 0;
    int contVacMujeresCatchtup      = 0;

    BASE_TYPE azar                  = 0;
//  vacunas catch up pongo por turno
    BASE_TYPE gvac                  = 0.0;
    BASE_TYPE vacXturno             = 0.0;
    unsigned int edad = 0;

	cout << "IN : " << m_problema_de_entrada << endl;
	cout << "OUT: " << m_solucion_de_salida << endl;
	cout << "ID : " << m_identificador_de_prueba << endl;
	//cout << "Extra (alpha): "	<< m_pesos << endl;
	cout << "(T0): " << m_T0 << endl;
	cout << "(T1): " << m_T1 << endl;
	cout << "(T2): " << m_T2 <<	endl;
	cout << "(T3): " << m_T3 << endl;
	cout << "T fixed (T): " << m_T_desplazado << endl;
	//cout <<"Time since generation: " << m_reloj.segundos_transcurridos() << "(s) elapsed" << endl;

    // IDEA DE INFECCION SELECTIVA
    std::vector<subNodoLSP> pos_LSP_Muj;
    std::vector<subNodoLSP> pos_LSP_Hom;
    std::vector<subNodoWeight> subNodosDinamica;

    subNodoLSP *tuplaH = new subNodoLSP[m_tot_hombres];
    subNodoLSP *tuplaM = new subNodoLSP[m_numero_de_nodos - m_tot_hombres];//total mujeres
    int cntHtuplas = 0;
    int cntMtuplas = 0;
    pos_LSP_Muj.clear();
    pos_LSP_Hom.clear();
    //Empezamos en la primera mujer hasta el final (i = tot_hombres)
    for (unsigned int i = 0; i < m_grafo.m_numnodos; i++)
    {
        //Si es mujer y tiene relaciones (LSP > 0)
        if (m_grafo.Nodo(i).m_sexo == MUJER)
        {
            tuplaM[cntMtuplas].pos = i;
            tuplaM[cntMtuplas].LSP = m_grafo.Nodo(i).m_LSP;
            pos_LSP_Muj.push_back(tuplaM[cntMtuplas]);
            cntMtuplas++;
        }
        //Si es hombre y tiene relaciones (LSP > 0)
        else if (m_grafo.Nodo(i).m_sexo == HOMBRE)
        {
            tuplaH[cntHtuplas].pos = i;
            tuplaH[cntHtuplas].LSP = m_grafo.Nodo(i).m_LSP;
            pos_LSP_Hom.push_back(tuplaH[cntHtuplas]);
            cntHtuplas++;
        }
    }
    delete [] tuplaM;
    delete [] tuplaH;
    std::sort(pos_LSP_Muj.rbegin(), pos_LSP_Muj.rend());
    std::sort(pos_LSP_Hom.rbegin(), pos_LSP_Hom.rend());
    //RECORRO MUJERES ORDENADAS DECRECIENTE POR NUMERO DE PAREJAS
    float rand = 0;
    for (unsigned int i = 0; i < pos_LSP_Muj.size(); i++)
    {
        CPersona &sujeto_actual = m_grafo.Nodo(pos_LSP_Muj[i].pos);
        if ( (sujeto_actual.m_edad >= 14) && (sujeto_actual.m_edad <= 17) )
        {
            rand = m_dado.TiraFloat();

            if (rand < m_14_17__HR)
            {
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_M_16_18 * 12);
            }

            else if ( (rand > m_14_17__HR) && (rand < m_14_17__HR + m_14_17__LR) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_M_6_11 * 12);
            }
            else if ( (rand > m_14_17__HR) && (rand < m_14_17__HR + m_14_17__LR + m_14_17__AMBOS) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_M_6_11 * 12);
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_M_16_18 * 12);
            }
        }
        else if ( (sujeto_actual.m_edad >= 18) && (sujeto_actual.m_edad <= 29) )
        {
            rand = m_dado.TiraFloat();

            if (rand < m_18_29__HR)
            {
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_M_16_18 * 12);
            }

            else if ( (rand > m_18_29__HR) && (rand < m_18_29__HR + m_18_29__LR) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_M_6_11 * 12);
            }

            else if ( (rand > m_18_29__HR) && (rand < m_18_29__HR + m_14_17__LR + m_18_29__AMBOS) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_M_6_11 * 12);
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_M_16_18 * 12);
            }

        }
        else if ( (sujeto_actual.m_edad >= 30) && (sujeto_actual.m_edad <= 39) )
        {
           rand = m_dado.TiraFloat();

            if (rand < m_30_39__HR)
            {
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_M_16_18 * 12);
            }

            else if ( (rand > m_30_39__HR) && (rand < m_30_39__HR + m_30_39__LR) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_M_6_11 * 12);
            }

            else if ( (rand > m_30_39__HR) && (rand < m_30_39__HR + m_14_17__LR + m_30_39__AMBOS) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_M_6_11 * 12);
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_M_16_18 * 12);
            }

        }
        else if ( (sujeto_actual.m_edad >= 40) && (sujeto_actual.m_edad <= 65) )
        {
            rand = m_dado.TiraFloat();

            if (rand < m_40_65__HR)
            {
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_M_16_18 * 12);
            }

            else if ( (rand > m_40_65__HR) && (rand < m_40_65__HR + m_40_65__LR) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_M_6_11 * 12);
            }

            else if ( (rand > m_40_65__HR) && (rand < m_40_65__HR + m_14_17__LR + m_40_65__AMBOS) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_M_6_11 * 12);
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_M_16_18 * 12);
            }

        }
    }
    //RECORRO HOMBRES ORDENADOS DECRECIENTE POR NUMERO DE PAREJAS
    for (unsigned int i = 0; i < pos_LSP_Hom.size(); i++)
    {
        CPersona &sujeto_actual = m_grafo.Nodo(pos_LSP_Hom[i].pos);
        if ( (sujeto_actual.m_edad >= 14) && (sujeto_actual.m_edad <= 17) )
        {
            rand = m_dado.TiraFloat();

            if (rand < m_14_17__HR)
            {
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_H_16_18 * 12);
            }

            else if ( (rand > m_14_17__HR) && (rand < m_14_17__HR + m_14_17__LR) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_H_6_11 * 12);
            }

            else if ( (rand > m_14_17__HR) && (rand < m_14_17__HR + m_14_17__LR + m_14_17__AMBOS) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_H_6_11 * 12);
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_H_16_18 * 12);
            }
        }
        else if ( (sujeto_actual.m_edad >= 18) && (sujeto_actual.m_edad <= 29) )
        {
            rand = m_dado.TiraFloat();

            if (rand < m_18_29__HR)
            {
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_H_16_18 * 12);
            }

            else if ( (rand > m_18_29__HR) && (rand < m_18_29__HR + m_18_29__LR) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_H_6_11 * 12);
            }

            else if ( (rand > m_18_29__HR) && (rand < m_18_29__HR + m_14_17__LR + m_18_29__AMBOS) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_H_6_11 * 12);
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0,m_meanDuration_H_16_18 * 12);
            }
        }
        else if ( (sujeto_actual.m_edad >= 30) && (sujeto_actual.m_edad <= 39) )
        {
            rand = m_dado.TiraFloat();

            if (rand < m_30_39__HR)
            {
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_H_16_18 * 12);
            }

            else if ( (rand > m_30_39__HR) && (rand < m_30_39__HR + m_30_39__LR) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_H_6_11 * 12);
            }

            else if ( (rand > m_30_39__HR) && (rand < m_30_39__HR + m_14_17__LR + m_30_39__AMBOS) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_H_6_11 * 12);
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_H_16_18 * 12);
            }

        }
        else if ( (sujeto_actual.m_edad >= 40) && (sujeto_actual.m_edad <= 65) )
        {
            rand = m_dado.TiraFloat();

            if (rand < m_40_65__HR)
            {
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_H_16_18 * 12);
            }

            else if ( (rand > m_40_65__HR) && (rand < m_40_65__HR + m_40_65__LR) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_H_6_11 * 12);
            }

            else if ( (rand > m_40_65__HR) && (rand < m_40_65__HR + m_14_17__LR + m_40_65__AMBOS) )
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = m_dado.TiraRangoInt(0, m_meanDuration_H_6_11 * 12);
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = m_dado.TiraRangoInt(0, m_meanDuration_H_16_18 * 12);
            }

        }
    }

// CONTABILIDAD del turno 0, cuando se crea la vida
    for (edad = 14; edad <= 65; edad++) //son de 14 a 64 tener en cuenta para pintar
    {
        m_contabilidad[turno].poblacion_por_edad_H[edad-14]             = CuentaPersonas(C_TOTALINDIVIDUOS_H, edad);
        m_contabilidad[turno].poblacion_por_edad_M[edad-14]             = CuentaPersonas(C_TOTALINDIVIDUOS_M, edad);
        m_contabilidad[turno].poblacion_por_edad_HOMO[edad-14]           = CuentaPersonas(C_TOTALINDIVIDUOS_HOMO, edad);
        m_contabilidad[turno].poblacion_por_edad_H_VERRUGABLE[edad-14]           = CuentaPersonas(C_TOTALINDIVIDUOS_H_VERRUGABLE, edad);
        m_contabilidad[turno].poblacion_por_edad_H_VERRUGABLE_HOMO[edad-14]           = CuentaPersonas(C_TOTALINDIVIDUOS_H_VERRUGABLE_HOMO, edad);
        m_contabilidad[turno].poblacion_por_edad_H_ONCOGENICO[edad-14]           = CuentaPersonas(C_TOTALINDIVIDUOS_H_ONCOGENICO, edad);
        m_contabilidad[turno].poblacion_por_edad_H_ONCOGENICO_HOMO[edad-14]           = CuentaPersonas(C_TOTALINDIVIDUOS_H_ONCOGENICO_HOMO, edad);
        m_contabilidad[turno].poblacion_por_edad_M_VERRUGABLE[edad-14]           = CuentaPersonas(C_TOTALINDIVIDUOS_M_VERRUGABLE, edad);
        m_contabilidad[turno].poblacion_por_edad_M_ONCOGENICO[edad-14]           = CuentaPersonas(C_TOTALINDIVIDUOS_M_ONCOGENICO, edad);
        m_contabilidad[turno].infectados_por_edad_HR_H[edad-14]       = CuentaPersonas(C_INFECTADO_16_18_H, edad);
        m_contabilidad[turno].infectados_por_edad_HR_M[edad-14]       = CuentaPersonas(C_INFECTADO_16_18_M, edad);
        m_contabilidad[turno].infectados_por_edad_HR_H_HOMO[edad-14]  = CuentaPersonas(C_INFECTADO_16_18_H_HOMO, edad);//new
        m_contabilidad[turno].infectados_por_edad_LR_H[edad-14]        = CuentaPersonas(C_INFECTADO_6_11_H, edad);
        m_contabilidad[turno].infectados_por_edad_LR_M[edad-14]        = CuentaPersonas(C_INFECTADO_6_11_M, edad);
        m_contabilidad[turno].infectados_por_edad_LR_H_HOMO[edad-14]   = CuentaPersonas(C_INFECTADO_6_11_H_HOMO, edad);
        m_contabilidad[turno].infectados_por_edad_HR_LR_H[edad-14]  = CuentaPersonas(C_INFECTADO_16_18_6_11_H, edad);
        m_contabilidad[turno].infectados_por_edad_HR_LR_M[edad-14]  = CuentaPersonas(C_INFECTADO_16_18_6_11_M, edad);
        m_contabilidad[turno].infectados_por_edad_HR_LR_H_HOMO[edad-14]       = CuentaPersonas(C_INFECTADO_16_18_6_11_H_HOMO, edad);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_H[edad-14]       = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_H, edad);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_M[edad-14]       = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_M, edad);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_H_HOMO[edad-14]  = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_H_HOMO, edad);
        m_contabilidad[turno].infectados_vacunados_por_edad_LR_H[edad-14]        = CuentaPersonas(C_INFECTADO_VACUNADO_6_11_H, edad);
        m_contabilidad[turno].infectados_vacunados_por_edad_LR_M[edad-14]        = CuentaPersonas(C_INFECTADO_VACUNADO_6_11_M, edad);
        m_contabilidad[turno].infectados_vacunados_por_edad_LR_H_HOMO[edad-14]   = CuentaPersonas(C_INFECTADO_VACUNADO_6_11_H_HOMO, edad);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_H[edad-14]  = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_6_11_H, edad);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_M[edad-14]  = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_6_11_M, edad);
        m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_H_HOMO[edad-14]  = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_6_11_H_HOMO, edad);
        m_contabilidad[turno].vacunados_hombres_por_edad[edad-14]                       = CuentaPersonas(C_VACUNADOS_HOMBRES, edad);//new
        m_contabilidad[turno].vacunados_mujeres_por_edad[edad-14]                       = CuentaPersonas(C_VACUNADOS_MUJERES, edad);//new
        m_contabilidad[turno].vacunados_homo_por_edad[edad-14]                          = CuentaPersonas(C_VACUNADOS_HOMO, edad);
    }

//
// Ejecutamos la simulación
//
    string m_turnos_a_simular_progreso =  porcentaje(0, 0, m_turnos_a_simular );
//LARGE_INTEGER frequency;        // ticks per second
//LARGE_INTEGER t1, t2;           // ticks
//double elapsedTime = 0;
//QueryPerformanceFrequency(&frequency);
//
//
//LARGE_INTEGER frequency_2;        // ticks per second
//LARGE_INTEGER t1_2, t2_2;           // ticks
//double elapsedTime_2 = 0;
//QueryPerformanceFrequency(&frequency_2);


int cuentaDinamicaHetero = 0;
int cuentaDinamicaHomo = 0;




    // BEGIN ON!
    //Para cada turno
    for (turno = 1; turno <= m_turnos_a_simular ; turno++)
    {
        //20170410 AUSTRALIA CATCHUP ON!
        //complies with:
        //Versión 2     domingo, 9 de abril de 2017
        //Introducción de una vacunación catch-up en el modelo de VPH
        if (turno == m_mes_catchup_ini)
        {

            gvac = ( m_numero_de_nodos/ (2*50) ) * (m_edad_catchup_fin - m_edad_catchup_ini + 1);
            cout << " gvac: " << TipoBase_a_texto(gvac) << endl;
            vacXturno = ( gvac / (m_mes_catchup_fin - m_mes_catchup_ini + 1) ) * m_cv_catchup;
            cout << " vacXturno: " << TipoBase_a_texto(vacXturno) << endl;
            vacXturno = round (vacXturno);
            cout << " vacXturno round: " <<  vacXturno << endl;
        }
        if ((turno >= m_mes_catchup_ini) and (turno <= m_mes_catchup_fin ))
        {
            int fxv = gvac - contVacMujeresCatchtup;
            BASE_TYPE P = vacXturno / (fxv);
            //cout << "probabilidad: " <<TipoBase_a_texto(P) << endl;
            //Para cada nodo mujer
            for (unsigned int cnt = m_tot_hombres; cnt < m_grafo.m_numnodos; cnt++)
            {
                CPersona &sujeto_actual = m_grafo.Nodo(cnt);

                if ( (sujeto_actual.m_sexo == MUJER) &&
                        ((sujeto_actual.m_edad >= m_edad_catchup_ini) &&
                            (sujeto_actual.m_edad <= m_edad_catchup_fin) ) &&
                        ( not sujeto_actual.m_vacunado )

                    )
                {
                    //Vacunas catch up
                    if (m_dado.TiraFloat() < P)
                    {
                        sujeto_actual.m_estado_salud_HR = VACUNADA;
                        sujeto_actual.m_estado_salud_LR = VACUNADA;
                        sujeto_actual.m_vacunado = true;
                        //La siguiente linea no se por que la puse...
                        sujeto_actual.m_tiempo_estado_salud_16_18 = 0;
                        contVacMujeresCatchtup++;
                    }
                }
            }
        }
        // start timer for turn
        //QueryPerformanceCounter(&t1);
        //Para cada nodo
        //PARACADAPERSONA //BEGIN //BUCLE PRINCIPAL
        for (persona = 0; persona < m_grafo.m_numnodos; persona++)
        {
            CPersona &sujeto_actual = m_grafo.Nodo(persona);
            //si es el mes de su cumpleanios y es dinamica empieza
            if ((turno >=  m_dinamica_ini) && (turno <= m_dinamica_fin))
            {

                sujeto_actual.m_edad_meses++;

                if (( (turno -1) % 12  == sujeto_actual.m_mes_nacimiento))
                //En 600 turnos tenemos 0 Enero y 599 el ultimo diciembre con valor de 11, la edad en meses es de 0-11
                {
                    //es tu mes de cumpleanios
                    sujeto_actual.m_edad++;
                    //sujeto_actual.m_edad_meses = sujeto_actual.m_edad * 12 + sujeto_actual.m_mes_nacimiento;

                    subNodoWeight *tuplaNodo = new subNodoWeight[m_numero_de_nodos];
    //si no es homo y tiene 65 o 30 (puesto que el tratamiento es muy parecido)
                    if ((!sujeto_actual.m_homosexual)&&
                            ((sujeto_actual.m_edad >= 65) ||
                             (sujeto_actual.m_edad == 30)))
                    {
                        cuentaDinamicaHetero++;
                        //mientras tenga aristas las borro
                        while (m_grafo.CuantosVecinos(sujeto_actual.m_id) > 0)
                        {
                            //cout <<  "2)"<<m_grafo.Nodo(m_grafo.Vecino(sujeto_actual.m_id, m_grafo.CuantosVecinos(sujeto_actual.m_id)-1)).m_id <<"->"<<m_grafo.CuantosVecinos(m_grafo.Nodo(m_grafo.Vecino(sujeto_actual.m_id, m_grafo.CuantosVecinos(sujeto_actual.m_id)-1)).m_id) << endl;
                            m_grafo.BorraAristaDoble(sujeto_actual.m_id,
                                                     m_grafo.Nodo(m_grafo.Vecino(sujeto_actual.m_id, m_grafo.CuantosVecinos(sujeto_actual.m_id)-1)).m_id,
                                                    TRUE);
                            //cout <<  "3)"<<m_grafo.Nodo(m_grafo.Vecino(sujeto_actual.m_id, i)).m_id <<"->"<<m_grafo.CuantosVecinos(m_grafo.Nodo(m_grafo.Vecino(sujeto_actual.m_id, i)).m_id) << endl;
                            contAristasDinamicasHeteroBorradas++;
                        }
                        if (sujeto_actual.m_edad >= 65)//reciclo
                        {
                            sujeto_actual.m_edad = 14;
                            sujeto_actual.m_edad_meses = 168;//Rev 20160904
                            //Reseteo
                            sujeto_actual.m_tiempo_estado_salud_16_18 = 0;
                            sujeto_actual.m_tiempo_estado_salud_6_11 = 0;
                            sujeto_actual.m_estado_salud_HR = SUSCEPTIBLE_16_18;
                            sujeto_actual.m_estado_salud_LR = SUSCEPTIBLE_6_11;
                            sujeto_actual.m_vacunado = false;
                            sujeto_actual.m_verrugable = false;
                            sujeto_actual.m_oncogenico = false;
                        }
                        //No cambia el sexo y reasigno LSP
                        unsigned int ite_ini = 0;
                        unsigned int ite_fin = 0;
                        subNodosDinamica.clear();
                        if (sujeto_actual.m_sexo == HOMBRE)
                        {
                            sujeto_actual.m_LSP = ParejasHombres(sujeto_actual.m_edad);
                            ite_ini = m_tot_hombres;
                            ite_fin = m_numero_de_nodos;
                            //guardo todos los nodos para encontrar los nodos-LSP con mejor assortativity con el renacido
                            subNodosDinamica.reserve(m_numero_de_nodos - m_tot_hombres);
                        }
                        else
                        {
                            sujeto_actual.m_LSP = ParejasMujeres(sujeto_actual.m_edad);
                            ite_ini = 0;
                            ite_fin = m_tot_hombres;
                            //guardo todos los nodos para encontrar los nodos-LSP con mejor assortativity con el renacido
                            subNodosDinamica.reserve(m_tot_hombres);
                        }
                        sujeto_actual.m_relaciones_pendientes = sujeto_actual.m_LSP;
                        //tasa de contagio de ese grupo
                        sujeto_actual.m_T = asigna_T(sujeto_actual.m_edad);
                        int peso_aux = 0;
                        int cnt = 0;
                        for ( unsigned int ite = ite_ini; ite < ite_fin; ite++ )
                        {
                            CPersona &persona = m_grafo.Nodo(ite);
                            //si no eres tu y sois de distinto sexo (preguntar a Rafa si esta bien ordenarlos
                            //tanto si es hombre como si es mujer
                            if ((persona.m_id != sujeto_actual.m_id) && (persona.m_sexo != sujeto_actual.m_sexo))//BUG 001
                            {
                                peso_aux = PesoParejas( persona.m_LSP, sujeto_actual.m_LSP ) +
                                            PesoEdades(persona.m_edad, sujeto_actual.m_edad);
                                // y lo aniadimos a la lista
                                tuplaNodo[cnt].pos = persona.m_id;
                                tuplaNodo[cnt].weight = peso_aux;
                                subNodosDinamica.push_back(tuplaNodo[cnt]);
                                cnt++;
                            }
                        }
                    // start timer for dynamic part
                    //QueryPerformanceCounter(&t1_2);
                        //Ordeno por peso (assortativity) a los nodos de pareja opuesta al sujeto que cumple anios
                        std::sort(subNodosDinamica.begin(), subNodosDinamica.end());
                    //QueryPerformanceCounter(&t2_2);
                    // compute and print the elapsed time in millisec for dynamic part
                    //elapsedTime_2 += (t2_2.QuadPart - t1_2.QuadPart) * 1000.0 / frequency_2.QuadPart;
    //                cout << (t2_2.QuadPart - t1_2.QuadPart) * 1000.0 / frequency_2.QuadPart  << endl;
                        unsigned int i = 0;
                        while (m_grafo.CuantosVecinos(sujeto_actual.m_id) < sujeto_actual.m_LSP)//and(false))
                        {
                            if ( i < subNodosDinamica.size() )
                            {
                                //cout << "tracita" << m_numero_de_nodos-1-i << "   ,"<<sujeto_actual.m_relaciones_pendientes<<endl;;
                                m_grafo.GuardaAristaDoble(subNodosDinamica[i].pos, sujeto_actual.m_id, TRUE);
                                contAristasDinamicasHetero++;
                            }
                            else
                            {
                                cout <<"emparejamiento hetero sin parejas para asignar"<< endl;
                                break;
                            }
                            i++;
                        }
                    }
    //parte dinamica para homosexuales
                    else if ((sujeto_actual.m_homosexual) &&((sujeto_actual.m_edad >= 60)
                                                        || (sujeto_actual.m_edad == 20)
                                                        || (sujeto_actual.m_edad == 25)
                                                        || (sujeto_actual.m_edad == 30)
                                                        || (sujeto_actual.m_edad == 40)))
                    {
                        cuentaDinamicaHomo++;
                        //borrar aristas
                        while (m_grafo.CuantosVecinos(sujeto_actual.m_id) > 0)
                        {
                            m_grafo.BorraAristaDoble(sujeto_actual.m_id,
                                                     m_grafo.Nodo(m_grafo.Vecino(sujeto_actual.m_id, m_grafo.CuantosVecinos(sujeto_actual.m_id)-1)).m_id,
                                                    TRUE);
                            contAristasDinamicasHomoBorradas++;
                        }
                        if (sujeto_actual.m_edad >= 60)//reciclo homo
                        {
                            sujeto_actual.m_edad = 14;
                            sujeto_actual.m_edad_meses = 168;//Rev 20160904
                            //Reseteo
                            sujeto_actual.m_tiempo_estado_salud_16_18 = 0;
                            sujeto_actual.m_tiempo_estado_salud_6_11 = 0;
                            sujeto_actual.m_estado_salud_HR = SUSCEPTIBLE_16_18;
                            sujeto_actual.m_estado_salud_LR = SUSCEPTIBLE_6_11;
                            sujeto_actual.m_vacunado = false;
                            sujeto_actual.m_verrugable = false;
                            sujeto_actual.m_oncogenico = false;
                        }
                        //No cambia el sexo y reasigno LSP, aqui todos son hombres homo
                        sujeto_actual.m_LSP = ParejasHombresHomosexuales(sujeto_actual.m_edad);
                        sujeto_actual.m_relaciones_pendientes = sujeto_actual.m_LSP;
                        //tasa de contagio de ese grupo
                        sujeto_actual.m_T = asigna_T(sujeto_actual.m_edad);

                        //Creo nuevas aristas, meto m_numero_de_nodos tuplaNodos en la estructura a ordenar subNodosDinamica
                        subNodoWeight tuplaNodo[m_tot_hombres];
                        int peso_aux = 0;
                        int cnt = 0;
                        //guardo todos los nodos para encontrar los nodos-LSP con mejor assortativity con el renacido
                        subNodosDinamica.clear();
                        subNodosDinamica.reserve(m_tot_hombres);
                        for ( unsigned int j = 0; j < m_tot_hombres; j++ )
                        {
                            CPersona &persona = m_grafo.Nodo(j);
                            //meto en una estructura para ordenar por peso (assortativity) a los homosexuales
                            if (persona.m_id != sujeto_actual.m_id)
                            {
                                peso_aux = PesoParejas( persona.m_LSP, sujeto_actual.m_LSP ) +
                                            PesoHomos(persona.m_edad, sujeto_actual.m_edad) +
                                            PesoEdades(persona.m_edad, sujeto_actual.m_edad);
                                // y lo aniadimos a la lista
                                tuplaNodo[cnt].pos = j;
                                tuplaNodo[cnt].weight = peso_aux;
                                subNodosDinamica.push_back(tuplaNodo[cnt]);
                                cnt++;
                            }
                        }
                        //Ordeno por peso ascendente (no siempre 0 debido a PesoHomos) (assortativity) a los nodos homo
                        //std::sort(subNodosDinamica.begin(), subNodosDinamica.end()); rev con Rafa 20160912
                        unsigned int i = 0;
                        while (m_grafo.CuantosVecinos(sujeto_actual.m_id) < sujeto_actual.m_LSP)
                        {
                            if ( i < subNodosDinamica.size() )
                            {
                                m_grafo.GuardaAristaDoble(subNodosDinamica[i].pos, sujeto_actual.m_id, TRUE);
                                contAristasDinamicasHomo++;
                            }
                            else
                            {
                                cout <<"emparejamiento homosexual sin parejas para asignar"<< endl;
                                break;
                            }
                            i++;
                        }
                        //Ahora se le asigna una mujer de LSP>4 de manera aleaatoria
                        asignaMujer2Homo(m_tot_hombres,  sujeto_actual.m_id);
                    }//parte dinamica gays
                    delete [] tuplaNodo;
                }
            }//cumpleanios


            //   VERRUGABLE ONCOGENICO ON!
        //Antes de empezar a vacunar
        //Cuando empieza la simulación, primero se usan unos turnos para estabilizar la red estática,
        //luego se pasa a red dinámica y se usan unos turnos para estabilizarla. Y luego se empieza a vacunar hasta el final.
        //Pero ANTES de empezar a vacunar, hay que marcar de una forma especial a los nodos infectados.
            if ((turno == m_mes_vacunacion_ini) && (! realizadoVerrugableOncogenico))
            {
                cout <<"[Infecting oncogenic and warts.................]"<< endl;
                realizadoVerrugableOncogenico = true;
                unsigned int contador_LR = 0;
                unsigned int contador_HR = 0;
                unsigned int contador_verr = 0;
                unsigned int contador_onco = 0;
                for (persona = 0; persona < m_grafo.m_numnodos; persona++)
                {
                    CPersona &sujeto_actual = m_grafo.Nodo(persona);
                    if (sujeto_actual.m_estado_salud_HR == INFECTADO_16_18)
                    {
                        sujeto_actual.m_oncogenico = ( m_dado.TiraFloat() < m_oncogenico? true : false );
                        contador_HR++;
                        if (sujeto_actual.m_oncogenico)
                            contador_onco++;

                    }
                    if (sujeto_actual.m_estado_salud_LR == INFECTADO_6_11)
                    {
                        sujeto_actual.m_verrugable = ( m_dado.TiraFloat() < m_verrugable? true : false );
                        contador_LR++;
                        if (sujeto_actual.m_verrugable)
                            contador_verr++;
                    }
                }
               cout <<"Low risk (LR) | High risk (HR) : "<< contador_LR << " | "<<contador_HR << endl;
               cout <<"warts | oncogenic : "<< contador_verr << " | "<<contador_onco << endl;
            }


            //VACUNACION ON!
            //if (true) //DANES
            if ((turno >= m_mes_vacunacion_ini) && (turno <= m_mes_vacunacion_fin))

            {
                //si es el mes de su cumpleanios y tiene 14 anios y es chica -> contador 168 (14*12)
                // m_mes_nacimiento va de 0-11
                if ((sujeto_actual.m_sexo == MUJER) && (sujeto_actual.m_edad_meses == 168))
                {
                    //Vacunas
                    azar = m_dado.TiraFloat();
                    //Escenario Danes
                    //if (azar < m_cv_ninias_vector[turno - 1] * m_pv)
                    if (azar < m_cv_ninias * m_pv)
                    {
                        sujeto_actual.m_vacunado = true; //20160920
                        contVacMujeres++;
                    }
                }
                else if ((sujeto_actual.m_sexo == HOMBRE) && (sujeto_actual.m_edad_meses == 168))
                {
                    //Vacunas
                    azar = m_dado.TiraFloat();
                    if (azar < m_cv_ninios * m_pv)
                    {
                        sujeto_actual.m_vacunado = true; //20160920
                        contVacHombres++;
                    }
                }
            }


//            // Aniadimos un mes al tiempo en el estado de salud VACUNADO
//            if ( (sujeto_actual.m_estado_salud_HR == VACUNADA) &&
//                (sujeto_actual.m_estado_salud_LR == VACUNADA) &&
//                    (sujeto_actual.m_vacunado) )
//            {
//                //Validado 20171006 en PerdidaProteccion
//                //Aumenta un mes su tiempo en el estado de saludo, que es vacunado
//                sujeto_actual.m_tiempo_estado_salud_16_18++;
//
//                //if (sujeto_actual.m_tiempo_estado_salud_16_18 == 241) //12*20anios
//                if(true)
//                {
//                    cout << "Nodo[" << entero_a_texto(sujeto_actual.m_id)
//                    << "] lleva vacunado meses: "
//                    << entero_a_texto(sujeto_actual.m_tiempo_estado_salud_16_18)
//                    << " edad: "
//                    << entero_a_texto(sujeto_actual.m_edad_meses)
//                    << " turno: " <<turno<< endl;
//                    BASE_TYPE aux = (PerdidaProteccion(sujeto_actual.m_tiempo_estado_salud_16_18 - m_tini ));
//                    cout << "PerdidaProteccion value-> " <<TipoBase_a_texto(aux) << endl;
//                }
//            }

            //SUSCEPTIBLE ON!
            //complies with: Efecto_Comunitario.pdf
            //5 de octubre de 2016
            //Para poder estudiar el efecto comunitario
            //Si el sujeto es susceptible vemos que ocurre con sus vecinos - 16_18 cancer
            if (sujeto_actual.m_estado_salud_HR == SUSCEPTIBLE_16_18)
            {
                vecinas = m_grafo.CuantosVecinos(persona);
                //Recorremos las aristas vecinas
                for (unsigned int i = 0; i < vecinas ; i++)
                {
                    //Si un vecino esta infectado
                    if (m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_estado_salud_HR == INFECTADO_16_18)
                    {
                        azar = m_dado.TiraFloat();
                        // Si es hombre comprobamos si se infecta de una pareja mujer
                        if (sujeto_actual.m_sexo == HOMBRE)
                        {
                            if (azar < m_probabilidad_de_contagio_M_16_18 * calcula_T_Asociado(sujeto_actual)) //De mujer a hombre
                            {
                                //tiene VPH cuando actualice el mundo
                                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18_NEW;
                                if(sujeto_actual.m_vacunado == false)
                                {
                                    sujeto_actual.m_oncogenico = m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_oncogenico;
                                }
                            }
                        }
                        //Si es mujer, comprobamos si se infecta de una pareja hombre
                        else
                        {
                            if (azar < m_probabilidad_de_contagio_H_16_18 * calcula_T_Asociado(sujeto_actual)) //De hombre a mujer
                            {
                                //tiene VPH cuando actualice el mundo
                                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18_NEW;
                                //nuevo de 5 de octubre de 2016
                                if (sujeto_actual.m_vacunado == false)
                                {
                                    sujeto_actual.m_oncogenico = m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_oncogenico;
                                }
                            }
                        }

                    }
                }
            }//FIN SUSCEPTIBLE 16 18

            //Si el sujeto es susceptible vemos que ocurre con sus vecinos - 6_11 Verruga genital anal
            if (sujeto_actual.m_estado_salud_LR == SUSCEPTIBLE_6_11)
            {
                vecinas = m_grafo.CuantosVecinos(persona);
                //Recorremos las aristas vecinas
                for (unsigned int i = 0; i < vecinas ; i++)
                {
                    //Si un vecino esta infectado
                    if (m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_estado_salud_LR == INFECTADO_6_11)
                    {
                        azar = m_dado.TiraFloat();
                        // Si es hombre comprobamos si se infecta de una pareja mujer
                        if (sujeto_actual.m_sexo == HOMBRE)
                        {
                            if (azar < m_probabilidad_de_contagio_M_6_11 * calcula_T_Asociado(sujeto_actual)) //De mujer a hombre
                            {
                                //tiene VPH cuando actualice el mundo
                                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11_NEW;
                                //nuevo de 5 de octubre de 2016
                                if (sujeto_actual.m_vacunado == false)
                                {
                                    sujeto_actual.m_verrugable = m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_verrugable;
                                }
                            }
                        }
                        //Si es mujer, comprobamos si se infecta de una pareja hombre
                        else
                        {
                            if (azar < m_probabilidad_de_contagio_H_6_11 * calcula_T_Asociado(sujeto_actual)) //De hombre a mujer
                            {
                                //tiene VPH cuando actualice el mundo
                                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11_NEW;
                                //nuevo de 5 de octubre de 2016
                                if (sujeto_actual.m_vacunado == false)
                                {
                                    sujeto_actual.m_verrugable = m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_verrugable;
                                }
                            }
                        }

                    }
                }
            }//FIN SUSCEPTIBLE 6 11


            //VACUNADAS ON!
            //complies with: Efecto_Comunitario.pdf
            //5 de octubre de 2016
            //Para poder estudiar el efecto comunitario
            //Si el sujeto esta vacunado de HR (actualizar los nombres algun dia)
//            if (sujeto_actual.m_vacunado == true)
//            {
//                vecinas = m_grafo.CuantosVecinos(persona);
//                //Recorremos las aristas vecinas
//                for (unsigned int i = 0; i < vecinas ; i++)
//                {
//                    //Si un vecino esta infectado
//                    if (m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_estado_salud_HR == INFECTADO_16_18)
//                    {
//                        azar = m_dado.TiraFloat();
//                        // Si es hombre comprobamos si se infecta de una pareja mujer
//                        if (sujeto_actual.m_sexo == HOMBRE)
//                        {
//                            //comprobamos si se contagia de un virus no oncogenico
//                            if (azar < m_probabilidad_de_contagio_M_16_18 *
//                                        calcula_T_Asociado(sujeto_actual) *
//                                        m_proteccion_de_vacuna_HR)
//                            {
//                                //tiene VPH cuando actualice el mundo
//                                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18_NEW;
//                                //no hago oncogenico
//                            }
//                        }
//                        //Si es mujer, comprobamos si se infecta de una pareja hombre, porque no tiene parejas mujeres
//                        else
//                        {
//                            //comprobamos si se contagia de un virus no oncogenico
//                            if (azar < m_probabilidad_de_contagio_H_16_18 *
//                                        calcula_T_Asociado(sujeto_actual) *
//                                        m_proteccion_de_vacuna_HR)
//                            {
//                                //tiene VPH cuando actualice el mundo
//                                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18_NEW;
//                                //no hago oncogenico
//                            }
//                        }
//
//                    }
//                }
//            }
//
//            //Si el sujeto es vacunado de LR
//            if (sujeto_actual.m_vacunado == true)
//            {
//                vecinas = m_grafo.CuantosVecinos(persona);
//                //Recorremos las aristas vecinas
//                for (unsigned int i = 0; i < vecinas ; i++)
//                {
//                    //Si un vecino esta infectado
//                    if (m_grafo.Nodo(m_grafo.Vecino(persona, i)).m_estado_salud_LR == INFECTADO_6_11)
//                    {
//                        azar = m_dado.TiraFloat();
//                        // Si es hombre comprobamos si se infecta de una pareja mujer
//                        if (sujeto_actual.m_sexo == HOMBRE)
//                        {
//                            //comprobamos si se contagia de un virus no verrugable
//                            if (azar < m_probabilidad_de_contagio_M_6_11 *
//                                        calcula_T_Asociado(sujeto_actual) *
//                                        m_proteccion_de_vacuna_LR)
//                            {
//                                //tiene VPH cuando actualice el mundo
//                                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11_NEW;
//                                //no hago verrugable
//                            }
//                        }
//                        //Si es mujer, comprobamos si se infecta de una pareja hombre
//                        else
//                        {
//                            //comprobamos si se contagia de un virus no verrugable
//                            if (azar < m_probabilidad_de_contagio_H_6_11 *
//                                        calcula_T_Asociado(sujeto_actual)  *
//                                        m_proteccion_de_vacuna_LR)
//                            {
//                                //tiene VPH cuando actualice el mundo
//                                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11_NEW;
//                                //no hago verrugable
//                            }
//                        }
//                    }
//                }
//            }//VACUNADAS


            //INFECTADO ON!
            //Si el sujeto esta infectado vemos si deja de estarlo
            if (sujeto_actual.m_estado_salud_HR == INFECTADO_16_18)
            {
                //Incremento su contador en ese estado de salud
                sujeto_actual.m_tiempo_estado_salud_16_18++;
                if (seRecupera(sujeto_actual, true))//HR-> true
                {
                    //pasa a ser susceptible
                    sujeto_actual.m_estado_salud_HR = RECUPERADO_16_18;
                    sujeto_actual.m_tiempo_estado_salud_16_18 = 0;
                    sujeto_actual.m_oncogenico = false;
                }
            }
            //Si el sujeto esta infectado vemos si deja de estarlo
            if (sujeto_actual.m_estado_salud_LR == INFECTADO_6_11)
            {
                //Incremento su contador en ese estado de salud
                sujeto_actual.m_tiempo_estado_salud_6_11++;
                if (seRecupera(sujeto_actual, false))//LR->false
                {
                    //pasa a ser susceptible
                    sujeto_actual.m_estado_salud_LR = RECUPERADO_6_11;
                    sujeto_actual.m_tiempo_estado_salud_6_11 = 0;
                    sujeto_actual.m_verrugable = false;
                }
            }


            //TURISMO
            //            Para todo nodo con edad entre ei y ef y con 4 LSP o más: Si rnd() < por (hay infección nueva)
            //Si rnd() < 0.7603 (infectado solo de HR) Marcar INFECTADO_HR = True Si rnd() < 0.5035
            //Marcar ONCOGENICO = True
            //Si 0.7603 <= rnd() < 0.7603 + 0.1172 (infectado solo de LR) Marcar INFECTADO_LR = True
            //Si rnd() < 0.3707
            //Marcar VERRUGABLE = True
            //Si 0.7603 + 0.1172 <= rnd() (infectado de ambos)
            //Marcar INFECTADO_HR = True y INFECTADO_LR = True Si rnd() < 0.5035
            //Marcar ONCOGENICO = True Si rnd() < 0.3707
            //Marcar VERRUGABLE = True
//            if ((turno >= m_mes_vacunacion_ini) && (turno <= m_mes_vacunacion_fin))
//            {
//                cout << "Feature turismo ON" << endl;
//                //Para cada nodo
//                for (persona = 0; persona < m_grafo.m_numnodos; persona++)
//                {
//                    CPersona &sujeto_actual = m_grafo.Nodo(persona);
//
//                    //si es el mes de su cumpleanios y es dinamica empieza
//                    if ((sujeto_actual.m_edad >=  m_ei) && (sujeto_actual.m_edad <= m_ef) && (sujeto_actual.m_LSP >= 4))
//                    {
//                        if(m_dado.TiraFloat() < m_por)
//                        {
//
//                            azar = m_dado.TiraFloat();
//                            if (azar < 0.7603)
//                            {
//                                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
//                                if (!sujeto_actual.m_vacunado)
//                                    sujeto_actual.m_oncogenico = ( m_dado.TiraFloat() < 0.5035? true : false );
//
//                            }
//                            if ((0.7603 <= azar) && (azar < 0.7603 + 0.1172))
//                            {
//                                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
//
//                                if (!sujeto_actual.m_vacunado)
//                                    sujeto_actual.m_verrugable = ( m_dado.TiraFloat() < 0.3707? true : false );
//
//                            }
//                            if (azar > 0.7603 + 0.1172)
//                            {
//                                //cout << sujeto_actual.m_id << " Infectado INFECTADO_16_18 INFECTADO_6_11" << endl;
//                                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
//                                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
//                                if (!sujeto_actual.m_vacunado)
//                                {
//                                    sujeto_actual.m_oncogenico = ( m_dado.TiraFloat() < 0.5035? true : false );
//
//                                    sujeto_actual.m_verrugable = ( m_dado.TiraFloat() < 0.3707? true : false );
//
//                                }
//
//                            }
//                        }
//
//                    }
//                }
//
//
//            }


        }//for all persona
        // FIN de iteracion por la red para cada individuo, ahora actualizo el mundo
        //Esto se hace para que no haya infectados aumentado todo el tiempo y perdujique
        //a la exploracion de los vecinos
//////////////// A C T U A L I Z A   M U N D O (se hace en dos pasos para no perder recuperados en la contabilidad,
                                                //los cuento antes de que pasen de recuperados a susceptibles)
        for (persona = 0; persona < m_grafo.m_numnodos; persona++)
        {
            CPersona &sujeto_actual = m_grafo.Nodo(persona);
			if (sujeto_actual.m_estado_salud_HR == INFECTADO_16_18_NEW)
            {
                sujeto_actual.m_estado_salud_HR = INFECTADO_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = 0;
            }
			if (sujeto_actual.m_estado_salud_LR == INFECTADO_6_11_NEW)
            {
                sujeto_actual.m_estado_salud_LR = INFECTADO_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = 0;
            }
        }//Fin actualiza mundo


// CONTABILIDAD
        for (edad = 14; edad <= 65; edad++) //son de 14 a 64 tener en cuenta para pintar
        {
            m_contabilidad[turno].poblacion_por_edad_H[edad-14]                     = CuentaPersonas(C_TOTALINDIVIDUOS_H, edad);
            m_contabilidad[turno].poblacion_por_edad_M[edad-14]                     = CuentaPersonas(C_TOTALINDIVIDUOS_M, edad);
            m_contabilidad[turno].poblacion_por_edad_HOMO[edad-14]                  = CuentaPersonas(C_TOTALINDIVIDUOS_HOMO, edad);
            m_contabilidad[turno].poblacion_por_edad_H_VERRUGABLE[edad-14]          = CuentaPersonas(C_TOTALINDIVIDUOS_H_VERRUGABLE, edad);
            m_contabilidad[turno].poblacion_por_edad_H_VERRUGABLE_HOMO[edad-14]     = CuentaPersonas(C_TOTALINDIVIDUOS_H_VERRUGABLE_HOMO, edad);
            m_contabilidad[turno].poblacion_por_edad_H_ONCOGENICO[edad-14]          = CuentaPersonas(C_TOTALINDIVIDUOS_H_ONCOGENICO, edad);
            m_contabilidad[turno].poblacion_por_edad_H_ONCOGENICO_HOMO[edad-14]     = CuentaPersonas(C_TOTALINDIVIDUOS_H_ONCOGENICO_HOMO, edad);
            m_contabilidad[turno].poblacion_por_edad_M_VERRUGABLE[edad-14]          = CuentaPersonas(C_TOTALINDIVIDUOS_M_VERRUGABLE, edad);
            m_contabilidad[turno].poblacion_por_edad_M_ONCOGENICO[edad-14]          = CuentaPersonas(C_TOTALINDIVIDUOS_M_ONCOGENICO, edad);
            m_contabilidad[turno].infectados_por_edad_HR_H[edad-14]                 = CuentaPersonas(C_INFECTADO_16_18_H, edad);
            m_contabilidad[turno].infectados_por_edad_HR_M[edad-14]                 = CuentaPersonas(C_INFECTADO_16_18_M, edad);
            m_contabilidad[turno].infectados_por_edad_HR_H_HOMO[edad-14]            = CuentaPersonas(C_INFECTADO_16_18_H_HOMO, edad);//new
            m_contabilidad[turno].infectados_por_edad_LR_H[edad-14]                 = CuentaPersonas(C_INFECTADO_6_11_H, edad);
            m_contabilidad[turno].infectados_por_edad_LR_M[edad-14]                 = CuentaPersonas(C_INFECTADO_6_11_M, edad);
            m_contabilidad[turno].infectados_por_edad_LR_H_HOMO[edad-14]            = CuentaPersonas(C_INFECTADO_6_11_H_HOMO, edad);
            m_contabilidad[turno].infectados_por_edad_HR_LR_H[edad-14]              = CuentaPersonas(C_INFECTADO_16_18_6_11_H, edad);
            m_contabilidad[turno].infectados_por_edad_HR_LR_M[edad-14]              = CuentaPersonas(C_INFECTADO_16_18_6_11_M, edad);
            m_contabilidad[turno].infectados_por_edad_HR_LR_H_HOMO[edad-14]         = CuentaPersonas(C_INFECTADO_16_18_6_11_H_HOMO, edad);
            m_contabilidad[turno].infectados_vacunados_por_edad_HR_H[edad-14]       = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_H, edad);
            m_contabilidad[turno].infectados_vacunados_por_edad_HR_M[edad-14]       = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_M, edad);
            m_contabilidad[turno].infectados_vacunados_por_edad_HR_H_HOMO[edad-14]  = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_H_HOMO, edad);
            m_contabilidad[turno].infectados_vacunados_por_edad_LR_H[edad-14]       = CuentaPersonas(C_INFECTADO_VACUNADO_6_11_H, edad);
            m_contabilidad[turno].infectados_vacunados_por_edad_LR_M[edad-14]       = CuentaPersonas(C_INFECTADO_VACUNADO_6_11_M, edad);
            m_contabilidad[turno].infectados_vacunados_por_edad_LR_H_HOMO[edad-14]  = CuentaPersonas(C_INFECTADO_VACUNADO_6_11_H_HOMO, edad);
            m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_H[edad-14]    = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_6_11_H, edad);
            m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_M[edad-14]    = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_6_11_M, edad);
            m_contabilidad[turno].infectados_vacunados_por_edad_HR_LR_H_HOMO[edad-14]  = CuentaPersonas(C_INFECTADO_VACUNADO_16_18_6_11_H_HOMO, edad);
            m_contabilidad[turno].vacunados_hombres_por_edad[edad-14]               = CuentaPersonas(C_VACUNADOS_HOMBRES, edad);//new
            m_contabilidad[turno].vacunados_mujeres_por_edad[edad-14]               = CuentaPersonas(C_VACUNADOS_MUJERES, edad);//new
            m_contabilidad[turno].vacunados_homo_por_edad[edad-14]                  = CuentaPersonas(C_VACUNADOS_HOMO, edad);
        }
//cout << m_reloj.segundos_transcurridos() << "(s) tras contabilidad" << endl;
        //Actualizo los recuperados a susceptibles, una vez contabilizados
        for (persona = 0; persona < m_grafo.m_numnodos; persona++)
        {
            CPersona &sujeto_actual = m_grafo.Nodo(persona);
            if (sujeto_actual.m_estado_salud_HR == RECUPERADO_16_18)
            {
                sujeto_actual.m_estado_salud_HR = SUSCEPTIBLE_16_18;
                sujeto_actual.m_tiempo_estado_salud_16_18 = 0;
            }
            if (sujeto_actual.m_estado_salud_LR == RECUPERADO_6_11)
            {
                sujeto_actual.m_estado_salud_LR = SUSCEPTIBLE_6_11;
                sujeto_actual.m_tiempo_estado_salud_6_11 = 0;
            }
        }//Fin actualiza mundo
//cout << m_reloj.segundos_transcurridos() << "(s) tras recuperados a susceptibles una vez contabilizados" << endl;

        if (!(turno%100))
        {
            if (m_turnos_a_simular_progreso != porcentaje(0, turno, m_turnos_a_simular))
            {
                m_turnos_a_simular_progreso = porcentaje(0, turno, m_turnos_a_simular);
                cout << m_turnos_a_simular_progreso << std::flush;
                //Make sure you flush the stream.
                //This is required because the output streams are buffered and
                //you have no guarantee over when the buffer will be flushed
                //unless you manually flush it yourself.
                backline();
                colea();
            }
        }
//        cout << "vacunados en turno: " << turno << " -> " << contVacHombres << endl;
//        contVacHombres = 0;
//        cout << "vacunadas en turno: " << turno << " -> " << contVacMujeres << endl;
//        contVacMujeres = 0;
//        cout << "cuentaDinamicaHetero en turno: " << turno << " -> " << cuentaDinamicaHetero << endl;
//        cout << "cuentaDinamicaHomo en turno: " << turno << " -> " << cuentaDinamicaHomo << endl;
//        cuentaDinamicaHomo = 0;
//        cuentaDinamicaHetero = 0;
//
//        cout << "tiempo de turno: " << elapsedTime_2 << endl;
//        elapsedTime_2 = 0;

    }//for all turnos

    cout << "Simulation elapsed time               :" << m_reloj.segundos_transcurridos() << "(s)" << endl;
    cout << "contVacMujeresCatchtup: " << contVacMujeresCatchtup << endl;
//    cout << endl;
//    if (m_dinamica)
//    {
//        cout << "Nodes are getting old (dynamic network), edges created and destroyed ->" << endl;
//        cout << "HeteroCreadas     :" << contAristasDinamicasHetero << endl;
//        cout << "HeteroBorradas    :" << contAristasDinamicasHeteroBorradas << endl;
//        cout << "HomoCredas        :" << contAristasDinamicasHomo << endl;
//        cout << "HomoBorradas      :" << contAristasDinamicasHomoBorradas << endl;
//    }
//    else
//        cout << "Nodes do NOT get old (static network)" << endl;


}


void CProblema::Soluciona(string entrada, string salida)
{
    unsigned int realizacion = 0;
    LeeProblema(entrada, salida);
    for (realizacion = 0; realizacion < m_realizaciones; realizacion++)
    {
        cout << "Realizacion " << realizacion + 1 << endl;
                //LeeRed("kkkk.txt");
                m_tot_homo = GeneraRed(m_numero_de_nodos);
                //GuardaRed("kkkk.txt");
                //cout << "Comienza la simulacion de los contagios VPH" << endl;
                //cout << "Estimamos " << (int) (0.035*(BASE_TYPE)m_numero_de_nodos
                //      + 0.008*(BASE_TYPE)m_numero_de_nodos*(BASE_TYPE)m_grado_medio)/1024
                //<< " MB de RAM" << endl;
                IniciaContabilidad();
                //GuardaEstadoInicialRedParaGrafoWeb(true);
                //m_pesos += 10;
                //sleep(1);
                SimulaPoblacion();
                GuardaSimulacion(true);

    }
    cout <<" - END - " << m_reloj.segundos_transcurridos() << "(s) total elapsed" << endl;
}

BASE_TYPE CProblema::calcula_T_Asociado(CPersona &sujeto_actual)
{
    unsigned int edad = sujeto_actual.m_edad;

    if (m_T_desplazado == 0)//T no se desplaza te da el T que te toque por tu edad
    {
        if ((edad >= 14) && (edad <= 17 ))
            return m_T0;
        else if((edad >= 18) && (edad <= 29 ))
            return m_T1;
        else if((edad >= 30) && (edad <= 39 ))
            return m_T2;
        else if((edad >= 40) && (edad <= 65 ))
            return m_T3;
        else
            return 1; //no hace nada
    }
    else //T se desplaza mientras viva el sujeto
        return sujeto_actual.m_T;
}


BASE_TYPE CProblema::asigna_T(unsigned int edad)
{

    if ((edad >= 14) && (edad <= 17 ))
        return m_T0;
    else if((edad >= 18) && (edad <= 25 ))
        return m_T1;
    else if((edad >= 30) && (edad <= 39 ))
        return m_T2;
    else if((edad >= 40) && (edad <= 65 ))
        return m_T3;
    else
        return 1; //no hace nada

}


//La función lineal de pérdida de protección será f(x) = [ ( - pp ) / tp - tini] x + 1.
//Ver PDF Perdida_de_proteccion_Mayo2017.pdf
//Te dice la proteccion que tienes
BASE_TYPE CProblema::PerdidaProteccion(int t)
{
    BASE_TYPE res = 0.0;
    if (t < 0)
        res = 1;//BUG 20180521
    else
        res = ((( - m_pp ) / (m_tp - m_tini) ) * t ) + (BASE_TYPE) 1.0;
    return res;
}
