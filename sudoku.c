#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

//ejercicio 2

int is_valid(Node* n){
   int i, j;
   for(i=0; i<9; i++){
      int row[10] = {0};
      for (j = 0; j < 9; j++){
         int num = n->sudo[i][j];
         if(num != 0){
            if (row[num] == 1){
               return 0;
            }
            row[num] = 1;
         }
      }
   }

   // realmente se podia hacer con esa y daban los 20 puntos pero no se me ocurrio en el momento y hice las demas xd
   
   for (j = 0; j < 9; j++){
      int col[10] = {0};
      for (i = 0; i < 9; i++){
         int num = n ->sudo[i][j];
         if (num != 0){
            if (col[num] == 1){
               return 0;
            }
            col[num] = 1;
         }
      }
   }

   int k, l;

   for (i = 0; i < 9; i += 3){

      for (j = 0; j < 9; j+= 3){
         int block[10] = {0};
         for (k = 0; k < 3; k++ ){
            for (l = 0; l < 3; l++){
               int num = n->sudo[i + k][j + l];
               if (num != 0){
                  if (block[num] == 1){
                     return 0;
                  }
                  block[num] = 1;
               }
            }
         }
      }
   }

    return 1;
}

//Ejercicio 1
// vaya ejercicio 3 tambien xd

List* get_adj_nodes(Node* n){
   List* list = createList();
   int found = 0;

   for (int i = 0; i < 9 && !found; i++){
      for (int j = 0; j < 9 && !found; j++){


         if (n->sudo[i][j] == 0){
            for (int k = 1; k <= 9; k++){
               Node* new_node = copy(n);
               new_node->sudo[i][j] = k;
               if (is_valid(new_node)){
                  pushBack(list, new_node);
               } // de verdad era solo colocar el isvalid..... -.-
               
            }
            found = 1;
         }
      }


      
   }

   
    
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/