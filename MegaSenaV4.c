#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define linhas 5
#define colunas 6

int i,j; //usar apenas para loopings do SorteioPrincipal

int PreencherMatriz();
int OrganizarLinhas(int SorteioPrincipal[linhas][colunas]);
int busca[60]; // usado para realizar a busca de numeros repetidos

int main(){

	   PreencherMatriz();
	   busca_repete();
	

      //OrganaizarLinhas(SorteioPrincipal); <- essa função so vai ser chamada quando os numeros não se repetirem numa mesma linha, ela esta ok;
       // usar SorteioPrincipal para nomear a matriz principal do programa
}



int PreencherMatriz(){
  int pg;
 int SorteioPrincipal[linhas][colunas];
 int count=1,x=0,temp=0,n,aux=0;

	   srand(time(NULL));

	   //gerar o Sorteio
	   printf("Sorteio Original sem modificacoes: \n\n");

	   for(i=0;i<linhas;i++){
            printf("%.2d Sorteio: ", count++);   //para beneficios de comparação visual
	   	for(j=0;j<colunas;j++){
	   		SorteioPrincipal[i][j] = 1 + rand()%10;

	   		printf("%.2d ", SorteioPrincipal[i][j] ); //para beneficios de comparação visual

             }
            printf("\n");      //para beneficios de comparação visual
         }

         system("pause");

//remover repetiçoes de cada linha do sorteio, por em quanto consigo apenas zerar os numeros repetidos

          for(i=0;i<linhas;i++){
            for(j=0;j<colunas;j++){
                for(x=j+1;x<colunas;x++){
                   if(SorteioPrincipal[i][j] == SorteioPrincipal[i][x]){
                        SorteioPrincipal[i][x] = rand()%10+1;
                        i =0;
                        j = 0;

                        SorteioPrincipal[i][j] = SorteioPrincipal[i][j];

                  }
                }
              }
            }


 // printar a matriz sem repetições..
printf("Sorteio sem repeticoes de numeros:\n\n");
         count=1;
         for(i=0;i<linhas;i++){
                printf("%.2d Sorteio: ", count++);
         	for(j=0;j<colunas;j++){
         		printf("%.2d ",SorteioPrincipal[i][j]);
         			pg=SorteioPrincipal[i][j]; //CONTAR NUMEROS REPETIDOS
                     busca[pg]+=1;
			 }
			 printf("\n");
		 }
            system("pause");
             OrganizarLinhas(SorteioPrincipal); //chamar a função para organizar as linhas
        
        
}


int OrganizarLinhas(int SorteioPrincipal[linhas][colunas]){

        int MatrizAux[linhas][colunas];
        int x,temp=0;

       //igualando o SorteioPrincipal com uma matriz auxiliar para facilitar a ordenção...
        for(i=0;i<linhas;i++){
        	for(j=0;j<colunas;j++){
        		MatrizAux[i][j] = SorteioPrincipal[i][j];
			}
		}


//ordenando as linhas da matriz de forma crescente...

      for(i=0;i<linhas;i++){
          for(j=colunas-1;j>=0;j--){
             for(x=j-1;x>=0;x--){

                if(MatrizAux[i][j] < MatrizAux[i][x]){
                   temp = MatrizAux[i][j];
                     MatrizAux[i][j] = MatrizAux[i][x];
                        MatrizAux[i][x] = temp;
              }
           }
         }
      }


      //printar a matriz ordenada
      int count=1;
     printf("Sorteio ordenado:\n\n");
      for(i=0;i<linhas;i++){
      	printf("%.2d Sorteio: ",count++);
      	for(j=0;j<colunas;j++){
      		SorteioPrincipal[i][j] = MatrizAux[i][j];
      		printf("%.2d ", SorteioPrincipal[i][j]);
		  }
		  printf("\n");
	  }
}

int busca_repete(){
	
	 printf("\n");
	printf("Numeros Repetidos\n");
	for(j=1;j<=colunas;j++){
		printf("Numeros %d = %d vezes\n",j,busca[j]);
	}
}

 
