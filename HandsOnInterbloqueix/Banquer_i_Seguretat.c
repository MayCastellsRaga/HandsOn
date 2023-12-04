# include <stdio.h>

#define MAX_PROCESOS 5  // Número máximo de procesos
#define MAX_RECURSOS 3  // Número máximo de tipos de recursos

int Disponible[MAX_RECURSOS] = {3, 3, 2};   // Vector de recursos disponibles
int Assignat[MAX_PROCESOS][MAX_RECURSOS] = {  // Matriu de recursos assignats
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int Necessitat[MAX_PROCESOS][MAX_RECURSOS] = {  // Matriu de recursos necessaris
    {7, 4, 3},
    {1, 2, 2},
    {6, 0, 0},
    {0, 1, 1},
    {4, 3, 1}
};
int Fet[MAX_PROCESOS];  // Vector de processos compleats

int compararVectors(int vector1[], int vector2[], int longitud) {
    for (int i = 0; i < longitud; i++) {
        switch (vector1[i] - vector2[i]) {
            case -1:
                return -1;  // vector1 és menor que vector2
            case 1:
                return 1;   // vector1 és major que vector2
        }
    }
    return 0;  // Vectors són iguals
}

void actualitzarVectors(int vector1[], int vector2[], int longitud, char operacio) {
  for (int i = 0; i < longitud; i++) {
    switch (operacio) {
      case '+':
        vector1[i] += vector2[i];
        break;
      case '-':
        vector1[i] -= vector2[i];
        break;
      default:
        vector1[i] = vector2[i];
        break;
    }
  }
}

void banquer(int proces, int Solicitud[MAX_RECURSOS]) {
    // Verificar si la solicitud és menor o igual a la Necessitat
    if (compararVectors(Solicitud, Necessitat[proces], MAX_RECURSOS) <= 0) {
        // Verificar si la solicitud és menor o igual als recursos disponibles
        if (compararVectors(Solicitud, Disponible, MAX_RECURSOS) <= 0) {
            // Actualitzar les estructures
            actualitzarVectors(Disponible, Solicitud, MAX_RECURSOS, '-');
            actualitzarVectors(Assignat[proces], Solicitud, MAX_RECURSOS, '+');
            actualitzarVectors(Necessitat[proces], Solicitud, MAX_RECURSOS, '-');
        } else {
            // Error: No hi ha prou recursos disponibles
            printf("Error: No hi ha prou recursos disponibles.\n");
        }
    } else {
        // Error: La sol·licitud supera la Necessitat
        printf("Error: La sol·licitud supera la Necessitat.\n");
    }
}

int seguretat() {
    int Treball[MAX_RECURSOS];
    actualitzarVectors(Treball, Disponible, MAX_RECURSOS, '+');
    
    for (int i = 0; i < MAX_PROCESOS; i++) {
        Fet[i] = 0;
    }

    for (int i = 0; i < MAX_PROCESOS; i++) {
        // Trobar un procés no completat que pugui executar-se
        if (Fet[i] == 0 && compararVectors(Necessitat[i], Treball, MAX_RECURSOS) <= 0) {
            // Assignar recursos i marcar el procés com a completat
            actualitzarVectors(Treball, Assignat[i], MAX_RECURSOS, '+');
            Fet[i] = 1;
            i = -1;  // Reiniciar el bucle per tornar a comprovar des del principi
        }
    }

    // Verificar si tots els processos estan compleats
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (Fet[i] == 0) {
            // El sistema no està en un estat segur
            return 0;
        }
    }

    // El sistema està en un estat segur
    return 1;
}

int main() {
    int Solicitud[MAX_RECURSOS] = {1, 0, 2};

    banquer(1, Solicitud);
    if (seguretat()) {
        printf("El sistema es troba en un estat segur.\n");
    } else {
        printf("El sistema no es troba en un estat segur.\n");
    }

    return 0;
}
