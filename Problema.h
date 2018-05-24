#pragma once
#include "../Biblioteca/DiskIO.h"
#include <string>
#include <algorithm>
#include "../Biblioteca/Utiles.h"
#include "../Biblioteca/poisson.h"
#include "../Biblioteca/grafo.h"
#include "../Biblioteca/aleatorio.h"
#include "../Biblioteca/Reloj.h"
#include "../Biblioteca/definiciones.h"
#include "Persona.h"

using namespace std;

struct REGISTRO_CONTABLE_TYPE
{
	vector<unsigned int> poblacion_por_edad_H;
	vector<unsigned int> poblacion_por_edad_M;
    vector<unsigned int> poblacion_por_edad_HOMO;
    vector<unsigned int> poblacion_por_edad_H_VERRUGABLE;
    vector<unsigned int> poblacion_por_edad_H_VERRUGABLE_HOMO;
    vector<unsigned int> poblacion_por_edad_H_ONCOGENICO;
    vector<unsigned int> poblacion_por_edad_H_ONCOGENICO_HOMO;
    vector<unsigned int> poblacion_por_edad_M_VERRUGABLE;
    vector<unsigned int> poblacion_por_edad_M_ONCOGENICO;
	vector<unsigned int> infectados_por_edad_HR;
	vector<unsigned int> infectados_por_edad_HR_H;
	vector<unsigned int> infectados_por_edad_HR_M;
	vector<unsigned int> infectados_por_edad_HR_H_HOMO;
	vector<unsigned int> infectados_por_edad_LR;
	vector<unsigned int> infectados_por_edad_LR_H;
	vector<unsigned int> infectados_por_edad_LR_M;
	vector<unsigned int> infectados_por_edad_LR_H_HOMO;
	vector<unsigned int> infectados_por_edad_HR_LR;
	vector<unsigned int> infectados_por_edad_HR_LR_H;
	vector<unsigned int> infectados_por_edad_HR_LR_M;
	vector<unsigned int> infectados_por_edad_HR_LR_H_HOMO;
    vector<unsigned int> infectados_vacunados_por_edad_HR;
	vector<unsigned int> infectados_vacunados_por_edad_HR_H;
	vector<unsigned int> infectados_vacunados_por_edad_HR_M;
	vector<unsigned int> infectados_vacunados_por_edad_HR_H_HOMO;
	vector<unsigned int> infectados_vacunados_por_edad_LR;
	vector<unsigned int> infectados_vacunados_por_edad_LR_H;
	vector<unsigned int> infectados_vacunados_por_edad_LR_M;
	vector<unsigned int> infectados_vacunados_por_edad_LR_H_HOMO;
	vector<unsigned int> infectados_vacunados_por_edad_HR_LR;
	vector<unsigned int> infectados_vacunados_por_edad_HR_LR_H;
	vector<unsigned int> infectados_vacunados_por_edad_HR_LR_M;
	vector<unsigned int> infectados_vacunados_por_edad_HR_LR_H_HOMO;
	vector<unsigned int> vacunados_hombres_por_edad;
	vector<unsigned int> vacunados_mujeres_por_edad;
    vector<unsigned int> vacunados_homo_por_edad;
};

struct subNodoWeight {
    unsigned int weight;
    unsigned int pos;
    bool usado;
    subNodoWeight()
    {
        weight  =   0;
        pos     =   0;
        usado   =   0;
    }
};

struct subNodoLSP {
    unsigned int LSP;
    unsigned int pos;
    subNodoLSP()
    {
        LSP     =   0;
        pos     =   0;
    }
};

enum EVENTO_CONTABLE
{
	C_TOTALINDIVIDUOS_HOMO,
	C_TOTALINDIVIDUOS_H_VERRUGABLE,
	C_TOTALINDIVIDUOS_H_VERRUGABLE_HOMO,
	C_TOTALINDIVIDUOS_H_ONCOGENICO,
	C_TOTALINDIVIDUOS_H_ONCOGENICO_HOMO,
    C_TOTALINDIVIDUOS_M_VERRUGABLE,
	C_TOTALINDIVIDUOS_M_ONCOGENICO,
	C_TOTALINDIVIDUOS_H,
	C_TOTALINDIVIDUOS_M,
	C_INFECTADO_16_18,
	C_INFECTADO_16_18_H,
	C_INFECTADO_16_18_M,
	C_INFECTADO_16_18_H_HOMO,
	C_INFECTADO_6_11,
	C_INFECTADO_6_11_H,
	C_INFECTADO_6_11_M,
	C_INFECTADO_6_11_H_HOMO,
	C_INFECTADO_16_18_6_11,
	C_INFECTADO_16_18_6_11_H,
	C_INFECTADO_16_18_6_11_M,
	C_INFECTADO_16_18_6_11_H_HOMO,
	C_INFECTADO_VACUNADO_16_18,
	C_INFECTADO_VACUNADO_16_18_H,
	C_INFECTADO_VACUNADO_16_18_M,
	C_INFECTADO_VACUNADO_16_18_H_HOMO,
	C_INFECTADO_VACUNADO_6_11,
	C_INFECTADO_VACUNADO_6_11_H,
	C_INFECTADO_VACUNADO_6_11_M,
	C_INFECTADO_VACUNADO_6_11_H_HOMO,
	C_INFECTADO_VACUNADO_16_18_6_11,
	C_INFECTADO_VACUNADO_16_18_6_11_H,
	C_INFECTADO_VACUNADO_16_18_6_11_M,
	C_INFECTADO_VACUNADO_16_18_6_11_H_HOMO,
	C_VACUNADOS_HOMO,
	C_VACUNADOS_HOMBRES,
	C_VACUNADOS_MUJERES
};

class CProblema
{
public:

    string       m_identificador_de_prueba;
    unsigned int m_consumo_RAM;
    BASE_TYPE    m_generador_de_red;
    unsigned int m_turnos_a_simular;
    unsigned int m_realizaciones;
    unsigned int m_numero_de_nodos;
    BASE_TYPE    m_grado_medio; //M
    unsigned int m_T_desplazado;
    BASE_TYPE    m_T0; //T1 Es el parametro desconocido
    BASE_TYPE    m_T1; //T1 Es el parametro desconocido
    BASE_TYPE    m_T2; //T2 Es el parametro desconocido
    BASE_TYPE    m_T3; //T3 Es el parametro desconocido
    BASE_TYPE    m_14_17__HR;
    BASE_TYPE    m_14_17__LR;
    BASE_TYPE    m_14_17__AMBOS;
    BASE_TYPE    m_18_29__HR;
    BASE_TYPE    m_18_29__LR;
    BASE_TYPE    m_18_29__AMBOS;
    BASE_TYPE    m_30_39__HR;
    BASE_TYPE    m_30_39__LR;
    BASE_TYPE    m_30_39__AMBOS;
    BASE_TYPE    m_40_65__HR;
    BASE_TYPE    m_40_65__LR;
    BASE_TYPE    m_40_65__AMBOS;
    BASE_TYPE m_meanDuration_H_16_18;
    BASE_TYPE m_meanDuration_H_6_11;
    BASE_TYPE m_meanDuration_M_16_18;
    BASE_TYPE m_meanDuration_M_6_11;
    BASE_TYPE m_probabilidad_de_contagio_M_6_11;
    BASE_TYPE m_probabilidad_de_contagio_H_6_11;
    BASE_TYPE m_probabilidad_de_contagio_M_16_18;
    BASE_TYPE m_probabilidad_de_contagio_H_16_18;
    BASE_TYPE m_proteccion_de_vacuna_HR;
    BASE_TYPE m_proteccion_de_vacuna_LR;
    BASE_TYPE m_homosexuales;
    BASE_TYPE m_verrugable;
    BASE_TYPE m_oncogenico;
    //Vacunas
    unsigned int m_mes_vacunacion_ini;
    unsigned int m_mes_vacunacion_fin;
    unsigned int m_dinamica_ini;
    unsigned int m_dinamica_fin;
    unsigned int m_mes_catchup_ini;
    unsigned int m_mes_catchup_fin;
    unsigned int m_edad_catchup_ini;
    unsigned int m_edad_catchup_fin;
    unsigned int m_ei;
    unsigned int m_ef;
    BASE_TYPE m_pv;
    //Escenario Danes
    std::vector<float> m_cv_ninias_vector;
    BASE_TYPE m_cv_ninias;
    BASE_TYPE m_cv_ninios;
    BASE_TYPE m_cv_catchup;
    BASE_TYPE m_pp;
    BASE_TYPE m_tp;
    BASE_TYPE m_tini;
    BASE_TYPE m_alpha_1;
    BASE_TYPE m_alpha_2;
    BASE_TYPE m_por;


    //Variables globales
    string       m_solucion_de_salida;
    string       m_problema_de_entrada;
    string       m_traza; //Traza global
    unsigned int m_realizacion_actual;
    unsigned int m_tot_hombres; //se calcula en ejecucion por la aleatoriedad de la red
    unsigned int m_tot_homo; //se calcula en ejecucion por la aleatoriedad de la red
    unsigned int m_pesos; //P se genera aleatorio, se llama alpha por el codigo
    CReloj       m_reloj;
    unsigned int m_tiempo_CPU;
    CDadoTAUS88  m_dado;

    CGrafo <CPersona> m_grafo;

    CProblema();

    ~CProblema(void);

    //Methods
    bool LeeProblema(string problema_de_entrada,string solucion_de_salida);
    unsigned int GeneraRed(int p_num_nodos);
    void IniciaContabilidad();
    void SimulaPoblacion();
    bool GuardaSimulacion(bool valida = false);
    bool GuardaEstadoInicialRedParaGrafoWeb(bool valida = false);
    bool GuardaRed(string archivo);
    bool LeeRed(string archivo);
    void Soluciona(string entrada, string salida);
    unsigned int CuentaPersonas(EVENTO_CONTABLE tipo, unsigned int edad);
	BASE_TYPE calcula_T_Asociado(CPersona &sujeto_actual);
	BASE_TYPE asigna_T(unsigned int edad);
	BASE_TYPE PerdidaProteccion( int t);
    vector <REGISTRO_CONTABLE_TYPE> m_contabilidad;
	bool EsHombre();
	int GrupoEdadHombres();
	int GrupoEdadMujeres();
	int EdadHombres();
	int EdadMujeres();
	int ParejasHombres(int edad);
	int ParejasMujeres(int edad);
	int ParejasHombresHomosexuales(int edad);
	BASE_TYPE PesoParejas(int parejas1, int parejas);
	int PesoHomos(unsigned int edad1, unsigned int edad2);
	BASE_TYPE MediaEdadRed(int contTotalParejas);
	BASE_TYPE DesviacionEdadRed(BASE_TYPE media, int contTotalParejas);
	bool TrazaPesos();
	BASE_TYPE PesoEdades(int edadH, int edadM);
    bool seRecupera(CPersona p1, bool HR);
    bool asignaMujer2Homo(unsigned int p_tot_hombres, unsigned int id_nodo_homo);
    bool existe500Error();
};


	extern bool operator < (CPersona p1, CPersona p2);

