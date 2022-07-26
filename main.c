/* 
  Archivo: Main.cpp
  Autor: Juan Manuel Cuellar Rendon
  Email: juan.manuel.cuellar@correounivalle.edu.co
  Fecha creación: 2020-03-01
  Fecha última modificación: 2020-03-01
  Versión: 0.1
  Licencia: GPL
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void loop (char c [3] [3]);
void Intro_Primera (char c [3] [3]);
void tablero(char c[3][3]);
void Intro_Yo(char c[3][3]);
void Intro_IA (char c[3][3]);
int ganador (char c[3][3]);
int reinicio(char c[3][3]);


int main() {

 char c [3] [3];
  
  loop (c) ;  // llama a todas las funciones fundamentales y refresca la pantalla




return 0 ; 
}

void loop (char c [3] [3]) {
   int i,j;
   i=0;
   Intro_Primera(c);
   
   do {
      system("clear");
      tablero(c);

      if (i%2 == 0){
        Intro_Yo(c);
      }else{
        Intro_IA(c);
      } 
      j = ganador (c);

      i++;
      

   }while (i <= 9 && j== 2);
   
   system("clear");
   tablero(c);

   if (j== 0 ) {
     printf("felicidades eres el Ganador de la partida !! \n");
     reinicio(c);
   } 
   else if (j== 1){
     printf("Que mal :c , has perdido la partida, sigue intentando \n ");
     reinicio(c);
   }
   else if(j==2) {
     printf("ninguno ha ganado \n ");
     reinicio(c);
   }

}

void Intro_Primera (char c [3] [3]) {
  int i, j;

  char aux;
  aux ='1';

  for (i=0 ; i < 3; i++) {
      for (j = 0 ;  j < 3; j++ ) {
        c [i] [j] = aux++;
    }
  }
}

void Intro_Yo (char c[3][3]){
  int i, j, k ; 
  int aux; 

   do {
      do {
       printf("Coloca una ficha, ubicandola en algun numero entre 1 & 9: ");
       fflush  (stdin);
       scanf ( "%i", &aux);
      } 
      while (aux < 1 || aux > 9);

    
       
       k=0;

    
      
        switch (aux){
          case 1: {
          i = 0;
          j = 0;
            if (c [i][j] == 'X'  || c [i][j] == 'O') {
            k = 1;
              printf("la casilla esta ocupada !  Intentalo con otro numero \n\n");
              }
            break;
          }
        

          case 2: {
          i = 0;
          j = 1;
            if (c [i][j] == 'X'  || c [i][j] == 'O') {
            k = 1;
            printf("la casilla esta ocupada !  Intentalo con otro numero \n\n");
          }
            break;
          }

          case 3: {
          i = 0;
          j = 2;
            if (c [i][j] == 'X'  || c [i][j] == 'O') {
            k = 1;
            printf("la casilla esta ocupada !  Intentalo con otro numero \n\n");
            }
            break;
          }

          case 4: {
          i = 1;
          j = 0;
            if (c [i][j] == 'X'  || c [i][j] == 'O') {
            k = 1;
            printf("la casilla esta ocupada !  Intentalo con otro numero \n\n");
            }
            break;
          }

          case 5: {
          i = 1;
          j = 1;
            if (c [i][j] == 'X'  || c [i][j] == 'O') {
            k = 1;
            printf("la casilla esta ocupada !  Intentalo con otro numero \n\n");
            }
            break;
          }

          case 6: {
          i = 1;
          j = 2;
            if (c [i][j] == 'X'  || c [i][j] == 'O') {
            k = 1;
            printf("la casilla esta ocupada !  Intentalo con otro numero \n\n");
            }
            break;
          }

          case 7: {
          i = 2;
          j = 0;
            if (c [i][j] == 'X'  || c [i][j] == 'O') {
            k = 1;
            printf("la casilla esta ocupada !  Intentalo con otro numero \n\n");
            }
            break;
          }

          case 8: {
          i = 2;
          j = 1;
            if (c [i][j] == 'X'  || c [i][j] == 'O') {
            k = 1;
            printf("la casilla esta ocupada !  Intentalo con otro numero \n\n");
            }
            break;
          }

          case 9: {
          i = 2;
          j = 2;
          if (c [i][j] == 'X'  || c [i][j] == 'O') {
            k = 1;
            printf("la casilla esta ocupada !  Intentalo con otro numero \n\n");
          }
          break;
        }
        
      }

    } while (k== 1);

    c[i][j] ='X';
    
}

void Intro_IA (char c [3][3]) {
  int i, j ,k ; 
  char aux;
  srand (time (NULL));

  do {
    i = rand ()%3 ;
    j = rand ()%3 ;
    k=0;

     if (c [i] [j]== 'X'|| c [i][j]== 'O'){
      k= 1;
     }
  } while (k ==1);
  c [i] [j]= 'O';

}


void tablero (char c [3][3]) {
  int i, j ; 
    for (i =0; i < 3 ; i++) {
      for (j = 0 ; j< 3 ; j++){
        if (j < 2){
          printf ( " %c | ", c[i] [j] );
        }
         else {
          printf( " %c ", c[i] [j]);
        }
      }
       if (i<2){
       printf("\n-------------\n");
      }
    }
    printf("\n\n");
}

int ganador (char c[3][3]) {

  if (c[0][0] == 'X' || c[0][0]== 'O'){

    if (c[0][0] == c[0][1] && c[0][0] == c[0][2]){
      if (c[0][0]== 'X') {
        return 0 ; // he ganado 
      }
      else {
        return  1; //he perdido 
      }
    }

    if (c[0][0] == c[1][0] && c[0][0] == c[2][0]){
      if (c[0][0]== 'X') {
        return 0 ; // he ganado 
      }
      else {
        return  1; //he perdido 
      }
    } 
  }

  if (c[1][1] == 'X' || c[1][1]== 'O'){

    if (c[1][1] == c[1][0] && c[1][1] == c[1][2]){
      if (c[1][1]== 'X') {
        return 0 ; // he ganado 
      }
      else {
        return  1; //he perdido 
      }
    }

   if (c[1][1] == c[2][0] && c[1][1] == c[0][2]){
      if (c[1][1]== 'X') {
        return 0 ; // he ganado 
      }
      else {
        return  1; //he perdido 
      }
    }

    if (c[1][1] == c[0][1] && c[1][1] == c[2][1]){
       if (c[1][1]== 'X') {
        return 0 ; // he ganado 
        }
        else {
        return  1; //he perdido 
        }
    }

    if (c[1][1] == c[0][0] && c[1][1] == c[2][2]){
       if (c[1][1]== 'X') {
        return 0 ; // he ganado 
        }
        else {
        return  1; //he perdido 
        }
    }
   
  }

  if (c[2][2]=='X' || c[2][2]== 'O'){

    if(c[2][2]== c[2][0] && c[2][2]== c[2][1]){
      if (c[2][2]== 'X') {
        return 0 ; // he ganado 
        }
        else {
        return  1; //he perdido 
        }
      }

    if(c [2][2]== c [0][2] && c[2][2]== c[1][2]){
      if (c[2][2]== 'X') {
        return 0 ; // he ganado 
        }
        else {
        return  1; //he perdido 
        }
    }
  }
  return 2;
}

int reinicio (char c[3][3]){
  int x;
  reinicio:
  printf("quieres volver a jugar ? Si = 1 / No = 2 ");
  scanf("%i", &x);
  if (x==1) {
    system("clear");
        goto reinicio;
  }

}