#include "verificaciones.h"


 /// @brief muestra todos los mecanicos que no tiene servicios asignados.
 ///
 /// @param servicio array de estrcuta que se va usar como filtro para ver que mecanicos no esta en el array
 /// @param tamServicio tamaño de array servicio
 /// @param mecanicos array de estrcuta que se va a usar para el filtro y va a mostrar los que pasen por el mismo
 /// @param tamMecanicos tamaño de array de mecanicos
 /// @param especialidades array de estrcurta que va a mostrar un solo campo
 /// @param tamEspecialidades tamaño del array de estrcuturas especialidades
 /// @return devuelve -1 en caso de error o encaso de que no encuentre mecanicos sin servico, devuevl 0 en caso de exito
int ListarMecanicosSinTrabajo (eServicio *servicio,int tamServicio, eMecanico *mecanicos, int tamMecanicos, eEspecilidad *especialidades, int tamEspecialidades);

/// @brief ordena el array de la estrcutra servicio en funcion a la fecha mas reciente
///
/// @param servicio array de estructra que se va a ordenar
/// @param tamServicio tamaño del array de estructura de servicio
void OrdenarPorFecha(eServicio *servicio,int tamServicio);

/// @brief ordena el array del menor de los ids al mayor
///
/// @param servicio array de estructra que se va a ordenar
/// @param tamServicio tamaño del array de estructura de servicio
void OrdenarPorId(eServicio *servicio,int tamServicio);

/// @brief pide el ingreso de una fecha y muestra todos los servicis que tenga como diagnostico "cambio de aceite"
///
/// @param servicio array de estructra que se va a mostrar
/// @param tamServicio tamaño del array de estructura de servicio
void SumatoriaPorFecha(eServicio *servicio,int tamServicio);

/// @brief va a mostrar el promedio de la cotizacion de todos los mecanicos que tengan un servicio asignado
///
/// @param servicio array de estructura que se va a utilizar como busqueda de los mecanicos con servicio y la cotizacion de los mismos
/// @param tamServicio tamaño del array de la estrcutura servico
/// @param mecanicos array de estructura que va mostrar el mecanico y el servico
/// @param tamMecanicos tamaño del array de la estrcuta mecanicos
/// @return devuelve -1 en caso de erroy, devulve 0 en caso de exitop
int CotizacionDeMecanicos(eServicio *servicio,int tamServicio,eMecanico *mecanicos,int tamMecanicos);

/// @brief busca y compara de entre todos los mecanicos, y va a mostrar cual es el que tiene mas servicios
///
/// @param servicio array de estrcuturas que se va a utilizara para buscar los mecanicos con sus servicios
/// @param tamServicio tamaño del array de la estrcutura servico
/// @param mecanicos array de estructura que se va a utilizar para comparar todos los mecanicos
/// @param tamMecanicos tamaño del array de la estrcuta mecanicos
/// @return devuelve -1 en caso de error, devuleve 0 en caso de exito
int MecanicoConMasServicos(eServicio *servicio,int tamServicio,eMecanico *mecanicos,int tamMecanicos);
