#include <stdio.h>

#define LEN_TAB 8


int normaliseCapteur( int * p );

int main(void)
{
    int valCapteur[LEN_TAB] = { 56, 1020, 60, 10, 180, 65, 55, 2 };
    int moyenne;

    // Calcul et affichage de la valeur du capteur
    moyenne = normaliseCapteur(&valCapteur[0]);
    printf("Valeur du capteur = %d\n", moyenne);

    return 0;
}

// Fonction qui normalise les données lues. Ici avec une simple moyenne.
int normaliseCapteur( int* p )
{
    int i;
    int total = 0;
    int moyenne = 0;
    int max = 0;
    int min = 1024;
    int max2 = 0;
    int min2 = 1024;
    int nombre;

    for(i = 0; i < LEN_TAB; i++){
        // Valeur du pointeur
        nombre = *p++;

        // Ajouts de tous les valeurs 
        total += nombre;

        
        if(nombre < min2){
            // Si le nombre est < à min2 et min
            if(nombre < min){
                min2 = min;
                min = nombre;
            }else {
                min2 = nombre;
            }
        }
        if(nombre > max2){
            // Si le nombre est > à max2 et max
            if(nombre > max){
                max2 = max;
                max = nombre;
            }else{
                max2 = nombre;
            }
        }
    
    }

    // Calcul de la moyenne sans les 2 plus grands nombres et les 2 plus petits nombres et décalage de bits pour diviser par 4
    moyenne = (total - (max + max2 + min + min2)) >> 2 ; 

    return (moyenne);
}

