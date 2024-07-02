#include <stdio.h>
#include <string.h>

#define CapacidadMaxima 100
#define MaxNombre 50

// Definición de la estructura producto
struct Producto {
    char nombre[MaxNombre];
    int cantidad;
    float precio;
};

// Función para guardar el inventario en un archivo de texto
void guardarInventario(struct Producto inventario[], int NumProductos) {
    FILE * archivo;
    archivo = fopen("inventario.txt", "w"); // Abrir archivo en modo escritura

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "Nombre\tCantidad\tPrecio\n");

    for (int i = 0; i < NumProductos; i++) {
        fprintf(archivo, "%s\t%d\t\t%.2f\n", inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }

    fclose(archivo);
    printf("Inventario guardado en el archivo 'inventario.txt' exitosamente.\n");
}

// Función para ingresar un nuevo producto al inventario
void ingresarProducto(struct Producto inventario[], int *NumProductos) {
    char respuesta;

    do {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", inventario[*NumProductos].nombre);

        printf("Ingrese la cantidad del producto: ");
        scanf("%d", &inventario[*NumProductos].cantidad);

        printf("Ingrese el precio del producto: ");
        scanf("%f", &inventario[*NumProductos].precio);

        (*NumProductos)++;

        printf("¿Desea ingresar otro producto? (S/N): ");
        scanf(" %c", &respuesta);

    } while (respuesta == 'S' || respuesta == 's');

    guardarInventario(inventario, *NumProductos); // Guardar después de agregar producto
}

// Función para editar un producto del inventario
void editarProducto(struct Producto inventario[], int NumProductos) {
    if (NumProductos == 0) {
        printf("No hay productos para editar.\n");
        return;
    }

    int ProductToEdit, UserSelect;

    printf("Ingrese el número del producto que desea editar (1-%d): ", NumProductos);
    scanf("%d", &ProductToEdit);

    printf("Seleccione el valor que desea editar:\n");
    printf("1. Editar nombre\n");
    printf("2. Editar cantidad\n");
    printf("3. Editar precio\n");
    scanf("%d", &UserSelect);

    ProductToEdit--;

    switch (UserSelect) {
        case 1:
            printf("Ingrese el nuevo nombre del producto: ");
            scanf("%s", inventario[ProductToEdit].nombre);
            break;
        case 2:
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &inventario[ProductToEdit].cantidad);
            break;
        case 3:
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &inventario[ProductToEdit].precio);
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    guardarInventario(inventario, NumProductos); // Guardar después de editar producto
}

// Función para eliminar un producto del inventario
void eliminarProducto(struct Producto inventario[], int *NumProductos) {
    if (*NumProductos == 0) {
        printf("No hay productos para eliminar.\n");
        return;
    }

    int DelProduct, i;

    printf("Ingrese el número del producto que desea eliminar (1-%d): ", *NumProductos);
    scanf("%d", &DelProduct);

    for (i = DelProduct - 1; i < *NumProductos - 1; i++) {
        strcpy(inventario[i].nombre, inventario[i + 1].nombre);
        inventario[i].cantidad = inventario[i + 1].cantidad;
        inventario[i].precio = inventario[i + 1].precio;
    }

    (*NumProductos)--;

    printf("Producto eliminado exitosamente.\n");

    guardarInventario(inventario, *NumProductos); // Guardar después de eliminar producto
}


// Función para listar todos los productos del inventario
void listarProductos(struct Producto inventario[], int NumProductos) {
    FILE *archivo;
    int c;

    archivo = fopen("inventario.txt", "r");

    if (archivo == NULL) {
        printf("Error al ubicar el archivo!!!\n");
        return;
    }

    printf("\n");

    while ((c = fgetc(archivo)) != EOF) {
        if (c == '\n') {
            printf("\n");
        } else {
            putchar(c);
        }
    }
    fclose(archivo);
}

void crearNuevoInventario(struct Producto inventario[], int *NumProductos) {
    FILE *archivo;
    
    archivo = fopen("inventario.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear nuevo inventario.\n");
        return;
    }
    fclose(archivo);

    *NumProductos = 0;
    printf("Nuevo inventario creado exitosamente.\n");

}


