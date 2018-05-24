#include "Persona.h"
#include "../Biblioteca/Utiles.h"
#include <string>

CPersona::CPersona()
{
    m_edad                          = 0;
    m_edad_meses                    = 0;
    m_mes_nacimiento                = 0;
    m_sexo                          = HOMBRE;
    m_relaciones_pendientes         = 0;
    m_LSP                           = 0;
    m_estado_salud_LR               = SUSCEPTIBLE_6_11;
    m_estado_salud_HR               = SUSCEPTIBLE_16_18;
    m_tiempo_estado_salud_16_18     = 0;
    m_tiempo_estado_salud_6_11      = 0;
    m_T                             = 1; //es un multiplicador que si es 1 no hace nada
    m_homosexual                    = false;
    m_verrugable                    = false;
    m_oncogenico                    = false;
    m_vacunado                      = false;
    m_id                            = 0;
}

char ESTADO_SALUD_NOMBRE[ULTIMO_ESTADO +1 ][24] =
   {"SUSCEPTIBLE_16_18      ",
    "INFECTADO_16_18        ",
    "SUSCEPTIBLE_6_11       ",
    "INFECTADO_6_11         ",
    "SUSCEPTIBLE_16_18_NEW  ",
    "INFECTADO_16_18_NEW    ",
    "SUSCEPTIBLE_6_11_NEW   ",
    "INFECTADO_6_11_NEW     ",
    "VACUNADA     ",
    "ULTIMO_ESTADO          "
	};

CPersona::~CPersona(void)
{

}

CPersona::CPersona( BASE_TYPE T,
                   unsigned int edad,
                   unsigned int edad_meses,
                   unsigned int mes_nacimiento,
                   SEXOSUJETO sexo,
                   unsigned int relaciones_pendientes,
                   unsigned int LSP,
                   ESTADO_SALUD_TIPO estado_salud_6_11,
                   ESTADO_SALUD_TIPO estado_salud_16_18,
                   unsigned short tiempo_estado_salud_16_18,
                   unsigned short tiempo_estado_salud_6_11,
                   bool homosexual,
                   bool verrugable,
                   bool oncogenico,
                   bool vacunado,
                   unsigned int id)
{
    m_edad                      = edad;
    m_edad_meses                = edad_meses;
    m_mes_nacimiento            = mes_nacimiento;
    m_sexo                      = sexo;
    m_relaciones_pendientes     = relaciones_pendientes;
    m_LSP                       = LSP;
    m_estado_salud_LR           = estado_salud_6_11;
    m_estado_salud_HR           = estado_salud_16_18;
    m_tiempo_estado_salud_16_18 = tiempo_estado_salud_16_18;
    m_tiempo_estado_salud_6_11  = tiempo_estado_salud_6_11;
    m_T                         = T;
    m_homosexual                = homosexual;
    m_verrugable                = verrugable;
    m_oncogenico                = oncogenico;
    m_vacunado                  = vacunado;
    m_id                        = id;

}

void operator<<(std::string &cadena, CPersona & persona)
{
    cadena = "{";
    cadena += meses_a_string(persona.m_edad) + ",";
	cadena += entero_a_texto(persona.m_sexo) + ",";
	cadena += entero_a_texto(persona.m_LSP) + "}";
}

void operator<<(CPersona & persona, std::string &cadena)
{

 // No usada de momento

}
