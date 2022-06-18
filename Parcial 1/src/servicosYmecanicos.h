#include "proveedor.h"

/// @brief carga los campos de la esctura servico
///
/// @param mecanicos array de estructra que se va a utilizar para mostar los mecanicos
/// @param cantidadDeMecanicos tamaño del array de esctructa mecanicos
/// @param id valor numerico que se va a cargar en el campo 'id' del la esctructura servicio
/// @param especialidad array de esctura que se va a utilizar para mostar las especialidades de los mecanicos
/// @param tamEspecialidad tamaño del array de la esctructura
/// @return va a devolver la esctrcura servico cargada
eServicio AgregarUnServico(eMecanico *mecanicos, int cantidadDeMecanicos, int id, eEspecilidad *especialidad, int tamEspecialidad);

/// @brief utilzando un for y el llamado de la funcio agregar un servico, va a cargar el array de la esctructura principal
///
/// @param servicio array de esctructura que se va a cargar
/// @param sizeServicio tamaño del array de la estructura servicio
/// @param mecanicos array de esctura que se va a utilzar para mostrar una lista de mecanicos
/// @param cantidadDeMecanicos tamaño del array de la esctructra mecanicos
/// @param especialidad array de esctura que se va a utilzar para mostrar la lista de mecanicos
/// @param tamEspecialidad tamaño del array de la esctura especialidad
/// @param idUto valor numerico que se utilizar para cargar el campo id del array de esctructura principal
/// @return devuelve un -1 en caso de error, devuelve un 0 en caso de exito
int CargarServico(eServicio* servicio, int sizeServicio, eMecanico *mecanicos, int cantidadDeMecanicos, eEspecilidad *especialidad, int tamEspecialidad, int idUto);

/// @brief pide el ingreso del id del array de la esctructura principal para luego ingresar a un submenu para elegir que campo se quiere modificar
///
/// @param servicio array de estructura que se va a modificar
/// @param sizeServicio tamaño del array de la esctructra servico
/// @param mecanicos array de esctura que se va a utilzar para mostrar una lista de mecanicos
/// @param cantidadDeMecanicos amaño del array de la esctructra mecanicos
/// @param especialidad array de esctura que se va a utilzar para mostrar la lista de mecanicos
/// @param tamEspecialidad tamaño del array de la esctura especialidad
/// @return devuelve -1 en caso de error o no encontrar el id ingresado por consola, devuelve 0 en caso de exito
int ModificarServico(eServicio* servicio, int sizeServicio, eMecanico *mecanicos, int cantidadDeMecanicos, eEspecilidad *especialidad, int tamEspecialidad);

/// @brief pide por consola el id de un mecanico, luego mustra los servicios que tiene ese mecanico. para luego cargar el campso diagnostico
/// de la esctura servico, y luego el campo cotizacion de la misma esctructura
///
/// @param servicio array de sctructura que se va a cargar los campos faltantes
/// @param sizeServicio tamaño del array de estructra servico
/// @param mecanicos array de esctructura que se va a utilizar para comparar los mecanicos que tiene cargado la estructura servicio
/// @param cantidadDeMecanicos tamaño array de la esctructura mecanicos
/// @param diagnostico array de esctrutra que se va a utlizar los diagnosticos
/// @param tamDiagnostico tamaño del array de estructra daignostico
/// @return devuelve un -1 en caso de erro o de que no se encuentre ni el mecanico; ni el servico pedidos por cosola. devuelve un 0 en caso de exito
int diagnosticar (eServicio* servicio, int sizeServicio, eMecanico *mecanicos, int cantidadDeMecanicos,eDiagnostico *diagnostico, int tamDiagnostico);
