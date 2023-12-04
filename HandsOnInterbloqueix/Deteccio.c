 #include <stdio.h>

#define MAX_PROCESOS 4 
#define MAX_RECURSOS 4  

void multipicarMatriu(int A[MAX_PROCESOS][MAX_PROCESOS], 
                      int B[MAX_PROCESOS][MAX_PROCESOS], 
                      int C[MAX_PROCESOS][MAX_PROCESOS]) {
    for (int i = 0; i < MAX_PROCESOS; i++) {
        for (int j = 0; j < MAX_PROCESOS; j++) {
            C[i][j] = 0;
            for (int k = 0; k < MAX_PROCESOS; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void detectarInterbloqueig(int A[MAX_PROCESOS][MAX_PROCESOS]) {
    int interbloqueig = 0;
    for (int i = 0; i < MAX_PROCESOS; i++) {
        if (A[i][i] != 0) 
        {
            if (interbloqueig == 0) {
                printf("El sistema es troba en un interbloqueix.\n");
                interbloqueig = 1;
            }
            printf("El procés p%d està involucrat en el interbloqueix.\n", i);
        }
    }
        if (interbloqueig == 0)
        {
            printf("El sistema no es troba en un interbloqueix.\n");
        }
}

int main() 
{
    int A[MAX_PROCESOS][MAX_PROCESOS] = {  // Matriu de recursos assignats
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 0}
    };
    int A2[MAX_PROCESOS][MAX_PROCESOS];
    int A3[MAX_PROCESOS][MAX_PROCESOS];
    int A4[MAX_PROCESOS][MAX_PROCESOS];

    // A^2
    multipicarMatriu(A, A, A2);
    printf("Detectant interbloqueig de longitud 2...\n");
    detectarInterbloqueig(A2);

    // A^3
    multipicarMatriu(A2, A, A3);
    printf("Detectant interbloqueig de longitud 3...\n");
    detectarInterbloqueig(A3);

    // A^4
    multipicarMatriu(A3, A, A4);
    printf("Detectant interbloqueig de longitud 4...\n");
    detectarInterbloqueig(A4);
}