#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loop(char c[3][3]);
void intropri(char c[3][3]);
void introyo(char c[3][3]);
void ia (char c[3][3]);
void tabler(char c[3][3]);
int ganador(char c[3][3]);

int main() {
    char c[3][3];
    loop(c);
    getchar(); // Espera a que el usuario presione Enter antes de salir
    return 0;
}

void loop(char c[3][3]) {
    int i = 0;
    intropri(c);
    
    do {
        system("cls");
        tabler(c);
        if (i % 2 == 0) {
            introyo(c);
        } else {
            ia(c);
        }
        i++;

        if (ganador(c)) {
            printf("¡Tenemos un ganador!\n");
            break; // Salir del bucle si hay un ganador
        }

    } while (i <= 9); // Verificar el número de turnos
}

void intropri(char c[3][3]) {
    int i, j;
    char aux = '1';
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = aux++;
        }
    }
}

void introyo(char c[3][3]) {
    char yo;
    int i, j, k;
    do {
        do {
            printf("Ingrese un número del 1 al 9: ");
            fflush(stdin);
            scanf(" %c", &yo);
        } while (yo < '1' || yo > '9');
        
        k = 0;
        
        switch (yo) {
            case '1':
                i = 0; j = 0; break;
            case '2':
                i = 0; j = 1; break;
            case '3':
                i = 0; j = 2; break;
            case '4':
                i = 1; j = 0; break;
            case '5':
                i = 1; j = 1; break;
            case '6':
                i = 1; j = 2; break;
            case '7':
                i = 2; j = 0; break;
            case '8':
                i = 2; j = 1; break;
            case '9':
                i = 2; j = 2; break;
        }

        if (c[i][j] == 'X' || c[i][j] == 'O') {
            k = 1;
            printf("Casilla ocupada! Intenta de nuevo ;)\n");
        }
    } while (k == 1);
    
    c[i][j] = 'X'; // Coloca 'X' en la posición seleccionada
}

void ia (char c[3][3]) {
    int i, j, k;
    k = 0;
    srand(time(NULL));
    do {
        i = rand() % 3;
        j = rand() % 3;
        if (c[i][j] == 'X' || c[i][j] == 'O') {
            k = 1;
        }
    } while (k == 1);

    c[i][j] = 'O'; // Coloca 'O' en la posición seleccionada
}

void tabler(char c[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (j < 2) {
                printf(" %c |", c[i][j]);
            } else {
                printf(" %c ", c[i][j]);
            }
        }
        if (i < 2) {
            printf("\n---+---+---\n");
        } else {
            printf("\n");
        }
    }
}

int ganador(char c[3][3]) {
    // Verificar filas
    for (int i = 0; i < 3; i++) {
        if (c[i][0] == c[i][1] && c[i][1] == c[i][2]) {
            if (c[i][0] == 'X' || c[i][0] == 'O') {
                return 1; // Hay un ganador
            }
        }
    }

    // Verificar columnas
    for (int j = 0; j < 3; j++) {
        if (c[0][j] == c[1][j] && c[1][j] == c[2][j]) {
            if (c[0][j] == 'X' || c[0][j] == 'O') {
                return 1; // Hay un ganador
            }
        }
    }

    // Verificar diagonales
    if ((c[0][0] == c[1][1] && c[1][1] == c[2][2]) ||
        (c[0][2] == c[1][1] && c[1][1] == c[2][0])) {
        if (c[1][1] == 'X' || c[1][1] == 'O') {
            return 1; // Hay un ganador
        }
    }

    // No hay ganador
    return 0;
}

