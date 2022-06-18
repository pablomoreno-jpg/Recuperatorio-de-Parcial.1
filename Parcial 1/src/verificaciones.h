#include "mecanicos.h"
#include "Servicio.h"

/// @brief pide por cosola un numero que va a comparar y se va a guardar en los punteros
///
/// @param mensaje mensaja que se va a mostrar al inicio de la compilacion
/// @param dia puntero en el que se va a guardar el 'dia' que le corresponde al mes y al año
/// @param mes puntero en el que se va a guarar el 'mes' que le corresponde
/// @param anio puntero en el que se va guardar el 'año'
/// @return devuelve -1 en caso de error, devuelve 0 en caso de exito
int ingresarFecha(char *mensaje,int*dia, int*mes, int*anio);

 /// @brief buscar y compara si encuentra en el campo  estado de la esctructra principal si encuentra en estado ocupado
 ///
 /// @param servicio array de esctura el cual se va buscar si tiene un 1 en el campo estado
 /// @param sizeServicio tamaño del arraya de la estrcutura servico
 /// @return deuvulve un -1 en caso de no encontrar ningun 'ocupado', devulve 0 en caso de exito
int BuscarOcupado(eServicio * servicio, int sizeServicio);

/// @brief busca en el array de servicio si encuentra el mismo valor que se le pasa por paramtro
///
/// @param servicio array que se va a usar para la comparacion en el campo id
/// @param sizeServicio tamaño de la estructura servicio
/// @param id paramtro que se va a buscar en el array
/// @return devuelve un -1 en caso de no encotrar el valo que se le pasa por paramtro, devuelve el indice en el que se encuentra el el 'id'
int BuscarIdServicio(eServicio* servicio, int sizeServicio,int id);

/// @brief busca en el array de mecanico si encuentra el mismo valor que se le pasa por paramtro
///
/// @param mecanico array que se va a usar para la comparacion en el campo id
/// @param sizeMecanico tamaño de la estructura mecanico
/// @param id parametro que se va a buscar en el array
/// @return devuelve un -1 en caso de no encotrar el valo que se le pasa por paramtro, devuelve el indice en el que se encuentra el el 'id'
int buscarIdMecanico(eMecanico* mecanico, int sizeMecanico, int id);

/// @brief compara y busca entre los dos array de esctructuras si encuentra el valor que se le pasa como paramtro
///
/// @param servicio array de estructura en el que se va a usar para buscar el paramtro
/// @param sizeServicio tamaño de la estructura servicio
/// @param mecanico array de estructura en el que se va a usar para buscar el paramtro
/// @param sizeMecanico tamaño de la estructura mecanico
/// @param id parametro que se va a buscar en el array entre los dos arrays
/// @return devuelve -1 en caso de no econtrar  el paramtro o en caso de erro, devuelve el indice de la estructura mecanicos en el que se cuentre el parametro
int compararIdServicioMecanico(eServicio* servicio, int sizeServicio, eMecanico* mecanico, int sizeMecanico, int id);
