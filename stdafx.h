// stdafx.h: archivo de inclusión de los archivos de inclusión estándar del sistema
// o archivos de inclusión específicos de un proyecto utilizados frecuentemente,
// pero rara vez modificados
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#ifdef __WIN32__
  #define SW_VERSION      "VPHS_20180522_w01"
#endif
#ifdef __UNIX__
  #define SW_VERSION      "VPHS_20180522_L01"
#endif

#include "../Biblioteca/definiciones.h"
#include "../Biblioteca/Utiles.h"

// TODO: mencionar aquí los encabezados adicionales que el programa necesita
