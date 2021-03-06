/*
Algoritmo: insertion_sort.c
Data: 02/05/2010

Rodar no terminal: 

$ ./insertion_sort -i -t 5 //roda o binário insertion_sort, gerando um vetor de chaves inteiras de tamanho 5
$ ./insertion_sort -s -t 5 //roda o binário insertion_sort, gerando um vetor de structs com 5 structs

*/

#include <stdio.h>
#include <stdlib.h> //rand(), srand(), atoi()
#include <unistd.h> //getopt()
#include <sys/time.h>

struct s_elemento
{
    int chave;
    int v[11];
};


int main(int argc, char *argv[])
{    int *vetor;
    struct s_elemento *vetor2; //declarado ponteiro para struct
    struct s_elemento s_chave;	
    struct timeval tinicio, tfim;
    double tdecorrido;
    int i, j, tamanho, k, chave, tipo_dado;
    char opt;
    long int comp=0, trocas=0;

    //para geração randômica	
    long int ultime;
    time (&ultime); //Captura o valor atual de tempo. O tipo do retorno é um objeto do tipo time_t. Salva o valor na variável ultimate
    srand ((unsigned)ultime); //Inicializa o gerador randômico de números, parâmetro da função deve ser um inteiro positivo, por isso unsigned

    gettimeofday (&tinicio, NULL);
    //Parâmetro: -t -> tamanho no vetor (500, 5.000, 10.000, 30.000); -s -> é 0 ou 1, se for 0, é o vetor normal, se for 1 é com um struct em cada posição do vetor
    while ((opt = getopt (argc, argv, "sit:")) != -1) //se for -1 todos os argumentos já terão sido capturados
    { 
	comp++;
    	switch (opt) 
    	{ 
               case 't': 
		   tamanho = atoi (optarg); 	//optarg pega o valor que foi colocado no terminal para o parâmetro t, de tamanho do vetor	 
                   break; //sai do switch
               case 's': 
		   tipo_dado = 1; 		//1: vetor de structs com "tamanho elementos"; a variável chave das structs é um inteiro gerado randomicamente e os vetor de 11 posições das structs também				
   		   break;
               case 'i': 
		   tipo_dado = 0; 		//0: vetor de inteiros com "tamanho" elementos; todos os elementos são números gerados randomicamente
                   break; //sai do switch
		case '?':  //cai aqui se o paramâtro digitado for diferente de 'p'  
               	   printf ("Parâmetro digitado é inválido.\n");
		   exit(EXIT_FAILURE);
		   break; //sai do switch
               default:
               	   exit(EXIT_FAILURE); //o parâmetro inserido não é "p"
                   		       //EXIT_FAILURE: Failure termination code -> contido na biblioteca stdlib.h	
        } 
    }
 
    if (tipo_dado == 0)
    {	
	comp++;	
	vetor = malloc(tamanho*sizeof(int));
	for (i=0; i<tamanho; i++)	
	{
    	    vetor[i] = rand() % (tamanho+1); //gera chaves de 0 a 500  
	    comp++;
	}	for(j = 1; j < tamanho; j++) 
	{   
	       comp++;
	       trocas++;		
	       chave = vetor[j];
	       i = j - 1; 
	       while(i >= 0 && vetor[i] > chave)
	       {
		       comp++;	
		       trocas++;	  
		       vetor[i+1] = vetor[i];
		       i = i - 1;
	       }
	       comp++;	
	       trocas++;
	       vetor[i+1] = chave;
	}
    }
    
    if (tipo_dado == 1)	
    {
	comp++;
  	vetor2 = malloc(tamanho*sizeof(struct s_elemento));
	for (i=0; i<tamanho; i++)	
        {
    	    comp++;	
    	    vetor2[i].chave = rand() % (tamanho+1); //gera chave
	    for (j=0; j<11; j++) 	 
      	    {
		comp++;	
    	        vetor2[i].v[j] = rand() % (tamanho+1); //gera vetor de 11 posições 
	    }
        }
	for(j = 1; j < tamanho; j++) 
	{   
	       comp++;
	       trocas++;	  	  
	       s_chave = vetor2[j];
	       i = j - 1; 
	       while(i >= 0 && vetor2[i].chave > s_chave.chave)
	       {
		       comp++;	
		       trocas++;
		       vetor2[i+1] = vetor2[i];
		       i = i - 1;
	       }	
               comp++;	
	       trocas++;	
	       vetor2[i+1] = s_chave;
	}
    }	
    gettimeofday (&tfim, NULL);
    tdecorrido = (double) ((tfim.tv_sec*1000000+tfim.tv_usec)-(tinicio.tv_sec*1000000+tinicio.tv_usec));
    printf ("%.lf\n", tdecorrido); 
    printf ("comp: %ld, trocas: %ld\n", comp, trocas);   
    return 0;   
}


