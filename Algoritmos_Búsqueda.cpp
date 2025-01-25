/***********************************
An�lisis de algoritmos
El programa utiliza las funciones BubbleSort
y QuickSort sumado de b�squeda binaria
implementados en vectores
************************************/

// Apartado de librer�as
#include <stdio.h>
#include <stdlib.h>

// Declarar variable global
int vect[50]; // Definir tama�o m�ximo de vector

// Funci�n BubbleSort
void bubble(int vect[], int a) {
    for (int i = 0; i < a - 1; i++) { // Iterar sobre el vector
        for (int j = 0; j < a - i - 1; j++) { // Comparar elementos
            if (vect[j] > vect[j + 1]) { // Si es mayor que el siguiente
                int temp = vect[j]; // Intercambia
                vect[j] = vect[j + 1];
                vect[j + 1] = temp;
            }
        }
    }
}

// Funci�n para intercambiar dos valores
void intercamb(int *a, int *b) { // Tomar dos punteros
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funci�n de partici�n para QuickSort
int part(int vect[], int low, int high) { // Dividir el vector en partes
    int pivot = vect[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vect[j] <= pivot) { // Si es menor o igual al pivote
            i++; // Incrementar
            intercamb(&vect[i], &vect[j]); // Intercambiar
        }
    }
    intercamb(&vect[i + 1], &vect[high]);
    return i + 1;
}

// Funci�n QuickSort
void quicksort(int vect[], int low, int high) {
    if (low < high) { // Verificar si hay m�s de un elemento
        int pi = part(vect, low, high); // �ndice del pivote
        quicksort(vect, low, pi - 1);
        quicksort(vect, pi + 1, high);
    }
}

// Funci�n de b�squeda binaria
void buscar(int vect[], int tam) {
    printf("�Cu�l valor buscas?\n");
    int busca;
    scanf("%d", &busca);

    int inicio = 0, fin = tam - 1, encontrado = 0; // L�mites de b�squeda
    while (inicio <= fin) { // Mientras est� en el rango
        int medio = (inicio + fin) / 2;

        if (vect[medio] == busca) { // Si est� en medio
            printf("El n�mero %d est� en la posici�n -> %d\n", busca, medio + 1);
            encontrado = 1;
            break;
        } else if (vect[medio] > busca) { // Si es menor
            fin = medio - 1;
        } else { // Si es mayor
            inicio = medio + 1;
        }
    }

    if (!encontrado) { // Si el valor no est�
        printf("El valor %d no existe en el vector.\n", busca);
    }
}

// Llenar el vector con valores aleatorios
void llenar(int vect[], int a) {
    for (int i = 0; i < a; i++) {
        vect[i] = rand() % 100; // Asigna valor aleatorio entre 0 y 99
    }
}

// Mostrar el vector
void mostrar(int vect[], int a) {
    for (int i = 0; i < a; i++) {
        printf("| %d ", vect[i]);
    }
    printf("|\n");
}

// Programa principal
int main() {
    int a = 0, b = 0, c = 0;

    // Solicitar tama�o del vector
    do { // Mientras la longitud est� dentro del rango
        printf("Decide la longitud de tu vector\n(puede ser desde 2 hasta 50 espacios):\n ---> ");
        scanf("%d", &a);
    } while (a < 2 || a > 50);

    // Solicitar valores del vector seg�n la longitud definida
    printf("Introduce los valores del vector:\n");
    for (int i = 0; i < a; i++) {
        printf("Valor [%d]: ", i + 1);
        scanf("%d", &vect[i]);
    }

    // Men� principal
    do {
        printf("\n_____________________\n"
               "|  1. Ver vector      |\n"
               "|  2. Ordenar         |\n"
               "|  3. Buscar          |\n"
               "|  4. Llenar al azar  |\n"
               "|  5. Salir           |\n"
               "|_____________________|\n"
               "\t --> ");
        scanf("%d", &b);

        switch (b) { // Seg�n la opci�n seleccionada
        case 1: // Opci�n 1: Ver valores guardados en vector
            printf("Vector actual:\n");
            mostrar(vect, a);
            break;
        case 2: // Opci�n 2: Acomodar valores de vector, men� de opciones parte dos
            printf("Elige el metodo de ordenamiento:\n"
					"_____________________\n"
                	"|    1         2     |\n"
                	"| Bubble   QuickSort |\n"
                	"|____________________|\n"
					"\t --> ");
            scanf("%d", &c);
            if (c == 1) { // Con algoritmo de ordenamiento Bubble, llamar void
                bubble(vect, a);
                printf("Vector ordenado con BubbleSort:\n");
            } else if (c == 2) { // Con algoritmo de ordenamiento QuickSort, llamar void
                quicksort(vect, 0, a - 1);
                printf("Vector ordenado con QuickSort:\n");
            } else { // Si no hay opci�n
                printf("Esa opci�n no existe.\n"
						"Intente nuevamente.\n"
						" [ Reintentando... ] \n");
            }
            mostrar(vect, a);
            break;
        case 3: // Opci�n 3: Buscar valor en el vector
            buscar(vect, a);
            break;
        case 4: // Opci�n 4: Llenado de vector al azar
        	llenar(vect, a);
            printf("Vector llenado con valores aleatorios:\n");
            mostrar(vect, a);
        	break;
        case 5: // Opci�n 5: Terminar programa
            printf("Adios, que le vaya bien :D \n");
            break;
        default: // Si no hay opci�n
            printf("Esa opci�n no existe.\n"
					"Intente nuevamente.\n"
					" [ Reintentando... ] \n");
            break;
        }
    } while (b != 5); // Repetir hasta salir

    return 0; // Terminar programa
}
