#include "proveedor.h"

void MostrarUnProveedor(eProveedor proveedor,eProducto *producto, int tamProducto){

	if(producto != NULL && tamProducto >= 0){

		printf("|%4d|%20s|",proveedor.id,proveedor.nombre);

		for(int i = 0; i < tamProducto; i++){

			if(proveedor.idProducto == producto[i].id){

				printf("%20s|",producto[i].producto);
				break;
			}

		}

		printf("%15d|\n",proveedor.idcliente);
	}

}

int ListarProveedores(eProveedor *proveedor, int tamProveedor, eProducto *producto, int tamProducto){

	int rtn = -1;

	if(proveedor != NULL && producto != NULL && tamProducto >= 0 && tamProveedor >= 0){

		printf("+----+--------------------+--------------------+---------------+\n");
		printf("|  ID|           Proveedor|            Producto|     id cliente|\n");
		printf("+----+--------------------+--------------------+---------------+\n");

		for(int i = 0; i < tamProveedor; i++){

			MostrarUnProveedor(proveedor[i], producto, tamProducto);

		}
		printf("+----+--------------------+--------------------+---------------+\n");
		rtn = 0;
	}

	return rtn;
}

int cargaDeCliente(eProveedor *proveedor, int tamProveedor,eServicio *servicio, int tamServicio, eMecanico *mecanicos, int tamMecanicos){

	int j;
	int rtn = -1;

	if(proveedor != NULL && servicio != NULL && mecanicos!= NULL && tamMecanicos >= 0 && tamServicio >= 0 && tamProveedor >= 0){

		for( int i = 0; i < tamServicio; i++){

			for(int k = 0; k < tamProveedor; k++){

				j = compararIdServicioMecanico(servicio, tamServicio, mecanicos, tamMecanicos, i);

				if(j != -1 && servicio[i].diagnostico > 0 && proveedor[k].estado == LIBRE){

					proveedor[k].idProducto = servicio[i].diagnostico;
					proveedor[k].idcliente = mecanicos[j].idMecanico;
					proveedor[k].estado = OCUPADO;
					break;
				}
			}
		}
	}

	return rtn;
}
