#include "listados.h"

typedef struct{

	int id;
	char nombre[50];
	int idcliente;
	int idProducto;//fk
	int estado;

}eProveedor;

typedef struct{

	int id;//pk
	char producto[50];

}eProducto;

/// @brief muestra los campos de la estrucutura y un solo campo del array de estructa que se le pasa por parametro
///
/// @param proveedor estrucutura
/// @param producto array de estructa
/// @param tamProducto tamanio de array de estructura
void MostrarUnProveedor(eProveedor proveedor,eProducto *producto, int tamProducto);

/// @brief utiliazndo un for y llamando a la funcion de mostrarunprpducto va mostras la totalidad el array de estrcuras principal
/// y parte del otro array de estructuras que se le pasa por paramtro
///
/// @param proveedor array de estrucutara principal
/// @param tamProveedor tamanio del array de estructra proveedor
/// @param producto array de estructura
/// @param tamProducto tamanio del array de estructura 'producto'
/// @return devuelve -1 en caso del que los arrays esten apuntando a NULL o el tamaño de los arrays sea menor a 0, devuelve 0 en caso de exito
int ListarProveedores(eProveedor *proveedor, int tamProveedor, eProducto *producto, int tamProducto);

/// @brief carga de forma automatica el cleinte al que le va a vender el producto y el prodcuto que le va a vender
///
/// @param proveedor array de estructura al que se le van a vargas los datos de producto y cliente
/// @param tamProveedor tamaño del array de proveedor
/// @param servicio array de estructra que se va a comparar
/// @param tamServicio tamaño del array de servicio.
/// @param mecanicos array de estructra que se va a comparar
/// @param tamMecanicos tamaño del array de mecanicos
/// @return devuelve -1 en caso del que los arrays esten apuntando a NULL o el tamaño de los arrays sea menor a 0, devuelve 0 en caso de exito
int cargaDeCliente(eProveedor *proveedor, int tamProveedor,eServicio *servicio, int tamServicio, eMecanico *mecanicos, int tamMecanicos);
