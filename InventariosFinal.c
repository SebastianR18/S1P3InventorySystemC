#include "Inventario.h"

// Función principal (main)
int main() {
    int UserSelect, respuesta, NumProductos = 0;
    struct Producto inventario[CapacidadMaxima];

    do {
        // Despliegue del Menu
        printf("\nSISTEMA DE INVENTARIO\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Vaciar inventario\n");        
        printf("6. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &UserSelect);

        switch (UserSelect) {
            case 1:
                ingresarProducto(inventario, &NumProductos);
                break;
            case 2:
                editarProducto(inventario, NumProductos);
                break;
            case 3:
                eliminarProducto(inventario, &NumProductos);
                break;
            case 4:
                listarProductos(inventario, NumProductos);
                break;
            case 5:
                printf("¿Realmente desea vaciar el inventario? (S: 1 / N: 0): ");
                scanf("%d", &UserSelect);

                if (UserSelect == 1)
                {
                    crearNuevoInventario(inventario, &NumProductos);
                }

                break;

            case 6:
                guardarInventario(inventario, NumProductos); // Guardar antes de salir del programa
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (UserSelect != 6);

    return 0;
}
