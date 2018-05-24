#pragma once
#ifndef __NEURONA_H__
#define __NEURONA_H__
#include <string>
#include "../Biblioteca/definiciones.h"

enum SEXOSUJETO
{
  HOMBRE = 0,
  MUJER = 1
};

#define ESTADOS_DE_SALUD 12

enum ESTADO_SALUD_TIPO
{
    SUSCEPTIBLE_16_18       = 1,
    INFECTADO_16_18         = 2,
    SUSCEPTIBLE_6_11        = 3,
    INFECTADO_6_11          = 4,
    RECUPERADO_16_18        = 5,
    INFECTADO_16_18_NEW     = 6,
    RECUPERADO_6_11         = 7,
    INFECTADO_6_11_NEW      = 8,
    VACUNADA                = 9,
    ULTIMO_ESTADO           = 10
};

extern char ESTADO_SALUD_NOMBRE[ULTIMO_ESTADO +1 ][24];

class CPersona
{
public:
	CPersona();
	CPersona(BASE_TYPE T,
          unsigned int edad,
          unsigned int edad_meses,
          unsigned int mes_nacimiento,
          SEXOSUJETO sexo,
          unsigned int relaciones,
          unsigned int relaciones_bk,
          ESTADO_SALUD_TIPO estado_salud_6_11,
          ESTADO_SALUD_TIPO estado_salud_16_18,
          unsigned short tiempo_estado_salud_16_18,
          unsigned short tiempo_estado_salud_6_11,
          bool homosexual,
          bool verrugable,
          bool oncogenico,
          bool vacunado,
          unsigned int id);
    //void Inicia(unsigned int edad, SEXOSUJETO sexo, unsigned int relaciones);

	~CPersona(void);

	unsigned int                m_edad; // edad
	unsigned int                m_edad_meses;// meses de edad
	unsigned int                m_mes_nacimiento; // mes de nacimiento
	BASE_TYPE                   m_T; //Para cuando no se desplaza T
	SEXOSUJETO                  m_sexo;
	unsigned int                m_relaciones_pendientes;
	unsigned int                m_LSP;
	ESTADO_SALUD_TIPO           m_estado_salud_HR;
	ESTADO_SALUD_TIPO           m_estado_salud_LR;
	unsigned short              m_tiempo_estado_salud_16_18;
	unsigned short              m_tiempo_estado_salud_6_11;
	bool                        m_homosexual;
	bool                        m_verrugable;
	bool                        m_oncogenico;
	bool                        m_vacunado;
	unsigned int                m_id;

    friend void operator<<(std::string& cadena, CPersona & persona);
    friend void operator<<(CPersona & persona, std::string& cadena);
};


#endif
