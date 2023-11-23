#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar números aleatorios entre 0 y 100
int generarNumeroAleatorio() {
    return rand() % 101;
}

// Función para imprimir una matriz
void imprimirMatriz(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para liberar la memoria ocupada por la matriz
void liberarMatriz(int **matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int filas, columnas;

    // Obtener dimensiones de la matriz
    printf("Ingrese el número de sadasdadadfilas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Reservar memoria para la matriz
    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    }

    // Llenar la matriz con números aleatorios entre 0 y 100
    srand(time(NULL));  // Inicializar la semilla para números aleatorios
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = generarNumeroAleatorio();
        }
    }

    // Imprimir la matriz original
    printf("Matriz original:\n");
    imprimirMatriz(matriz, filas, columnas);

    // Calcular la matriz transpuesta
    int **matrizTranspuesta = (int **)malloc(columnas * sizeof(int *));
    for (int i = 0; i < columnas; i++) {
        matrizTranspuesta[i] = (int *)malloc(filas * sizeof(int));
    }

    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            matrizTranspuesta[i][j] = matriz[j][i];
        }
    }

    // Imprimir la matriz transpuesta
    printf("\nMatriz transpuesta:\n");
    imprimirMatriz(matrizTranspuesta, columnas, filas);

    // Liberar la memoria
    liberarMatriz(matriz, filas);
    liberarMatriz(matrizTranspuesta, columnas);

    return 0;
}
