#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h> //biblioteca para funcao sleep, OBS: "talvez so funcione no windows"
#define TAM 5

int score(int x){ //funcao para calcular o score(x recebe o valor do cont, e cada acerto vale 200 pontos\ para cada cont 200 pontos) 
	if(x == 0){
		return 0;
	}else{
		return 200 + score(x-1);
	}
}

void delay(int x){ //funcao para limpar a tela(o sleep retarda 1 segundo, o x controla quantos segundos)
	while(x > 0){
		x--;
		Sleep(1000);
	}
	system("cls");	
}

int main(){
	srand(time(NULL));
	char nome[50] = {};
	int x, jogo[TAM], num[TAM], a = 0, fleg = 0;
	do{
		int cont = 0; // o cont eh zerado a cada volta no laco
		printf(" ------------------------------------ \n");
		printf(" --------------ESCOLHA--------------- \n");
		printf(" 1.jogar \n 2.ranking \n 3.regras \n 4.sair \n");
		printf(" ------------------------------------ \n");
		scanf("%i", &x);
		switch(x){
			case 1:
				fleg = 1; //fleg para controle(se tiver entrado no case 1 mudar a fleg)
				printf("nome do jogador: \n");
				setbuf(stdin,NULL);
				gets(nome); //nome do jogador 
				printf("decore os numeros abaixo: \n");
					for(int i = 0; i < TAM; i++){ //laco para guardar e printar na tela os numeros 
					jogo[i]= rand()%100; //random para lan?ar numeros aleatorios entre 0 e 99
					printf("%i ", jogo[i]);
					}
					printf("\n");
					delay(5);
				printf("digite os numeros decorados: \n");
				for(int i = 0; i < TAM; i++){ // laco para receber os numeros do usuario 
					printf("numero %i: ", i+1);
					scanf("%i", &num[i]);
					printf("\n");
				}
				for(int i = 0; i < TAM; i++){ // laco de comparacao dos numeros printados com os digitados
					if(jogo[i] == num[i]){
						cont++; //variavel para controle de acertos
					}
				}
				a = score(cont);
				printf("jogador\t score\t\n");
				printf("%s\t %i\t", nome, a);	
				printf("\n");
				system("pause");
				delay(1);		
				break;
			case 2:
				if(fleg == 1){ //so printara o ranking do ultimo jogador(se tiver entrado no case 1)
					printf("score da ultima rodada: \n");
					printf("jogador\t score\t\n");
					printf("%s\t %i\t", nome, a);	
					printf("\n");
					delay(5);		
				}else{
					printf("voce nao jogou ainda!! \n");
					delay(2);
				}
				break;
			case 3:
				printf(" O jogo eh simples\n O jogador vai decorar em 5 segundos os numeros na tela\n Depois vai digitar em ordem os numeros decorados. \n Cada acerto vale 200 pontos!! \n");
				printf(" jogue e divirta-se!!!!!!!!!!! \n");
				printf(" feito por Clara Nadini \n");
				system("pause");
				delay(1);
				break;
			case 4:
				break;
			default:
				printf("opcao invalida \n");				
		}
	}while(x != 4);
	system("pause");
	return 0;
}

