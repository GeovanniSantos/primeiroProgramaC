#include <stdio.h>
#include <stdlib.h>

main(){
	float notas[4][10],p1,p2,p3,a,media,mediatotal;
	int op=0,l=0,c=0,num=0,contadoraprovado,contadorreprovado;
	char aluno[10][30],curso[30],disciplina[30];
	
			for(l=0;l<10;l++){
				aluno[c][l]=0;
				for(c=0;c<4;c++){
				notas[c][l]=0;
			}
	}
	
	do{
	printf("\n\tControle de notas \n\n");

            printf("Digite o numero de uma das opcoes: \n");
            printf("1- Entrada de dados do Curso e disciplina \n");
            printf("2- Cadastro de alunos e notas (P1, P2 e P3) \n");
            printf("3- Alteracao de notas \n");
            printf("4- Exibir notas e media de um aluno especifico \n");
            printf("5- Exibir notas e media de todos os alunos da aturma \n");
            printf("6- Encerrar \n\n");
	scanf("%d",&op);
		
	switch(op){
		
		case 1:
			printf("\tEntrada de dados do Curso e disciplina\n");
			printf("\nDigite o curso: ");
			scanf("%s", curso);
			printf("Digite a disciplina: ");
			scanf("%s", disciplina);
			printf("Cadastrado com sucesso!");
			
			system("cls");
		break;
		
		case 2:
			if((curso[0] == '\0' || disciplina[0] == '\0')){
					printf("CADASTRE A DISCIPLINA E CURSO ANTES DE PROSSEGUIR\n\n");
				}
				else{
			printf("\n\tEntrada de notas\n\n");
			printf("Curso: %s\t", curso);
			printf("Disciplina: %s", disciplina);
			
			for(l=0;l<10;l++){
					
					printf("\n\nDigite o nome do aluno %d: ", l+1);
					scanf("%s", aluno[l]);
					printf("Digite na sequencia as notas do aluno(a) %s (P1 P2 P3 A): ", aluno[l]);
					scanf("%f %f %f %f",&p1,&p2,&p3,&a);
					notas[0][l]=p1;
					notas[1][l]=p2;
					notas[2][l]=p3;
					notas[3][l]=a;
			}
	}
			
		break;
		
		case 3:
				printf("\n\tAlteracao de Notas");
				printf("\nDigite o numero do aluno: ");
				scanf("%d",&num);
				l=num-1;
					printf("\n Digite na sequencia as notas do aluno %d %s (P1 P2 P3 A): ",num,aluno[l]);
					scanf("%f %f %f %f",&p1,&p2,&p3,&a);
					notas[0][num-1]=p1;
					notas[1][num-1]=p2;
					notas[2][num-1]=p3;
					notas[3][num-1]=a;
				
		break;
		case 4:
			media=0;
				printf("\n\tExibicao de nota individual");
				printf("\nDigite o numero do aluno:");
				scanf("%d",&num);
				num--;
				l=num;
				printf("\nNotas do aluno %s:", aluno[l]);
				if(notas[0][num]<notas[2][num]){
						media=((notas[2][num])*0.4)+((notas[1][num])*0.4)+((notas[3][num])*0.2);
					}else if(notas[1][l]<notas[2][l]){
						media=((notas[2][num])*0.4)+((notas[0][num])*0.4)+((notas[3][num])*0.2);
					}else{
						media=((notas[1][num])*0.4)+((notas[0][num])*0.4)+((notas[3][num])*0.2);
					}
					printf("\nP1   P2   P3   A    Media Situacao\n");
				for(c=0;c<4;c++){
					printf("%.2f ",notas[c][num]);
				}
				if(media>=6){
					printf("%.2f  Aprovado",media);
				}else{
					printf("%.2f  Reprovado",media);	
				}							
		break;
		
		case 5:
			printf("Aluno \t\t     P1 \t     P2 \t     P3 \tAtividade \tMedia \t Situacao\n");
			contadoraprovado=0;
			contadorreprovado=0;
			mediatotal=0;
			media=0;
				for(l=0;l<10;l++){
				printf("\n %d\t %.15s: ",l+1,aluno[l]);
				for(c=0;c<4;c++){
					printf("\t%.1f\t",notas[c][l]);
				}
			if(notas[0][l]<notas[2][l]){
						media=((notas[2][l])*0.4)+((notas[1][l])*0.4)+((notas[3][l])*0.2);
					}else if(notas[1][l]<notas[2][l]){
						media=((notas[2][l])*0.4)+((notas[0][l])*0.4)+((notas[3][l])*0.2);
					}else{
						media=((notas[1][l])*0.4)+((notas[0][l])*0.4)+((notas[3][l])*0.2);
					}
					if(media>=6){contadoraprovado++;
					printf("\t%.2f  Aprovado",media);
				}else{contadorreprovado++;
					printf("\t%.2f  Reprovado",media);
				}
				mediatotal=mediatotal+media;
			}
			mediatotal=mediatotal/l;
					printf("\n\nTotal de aprovados: %d\n",contadoraprovado);
					printf("Total de reprovados: %d\n",contadorreprovado);
					printf("Media da sala : %.1f",mediatotal);
					printf("\n\n\n");
		break;
		
		case 6:
		printf("FIM DO PROGRAMA\n\n");
		break;
		
		default:
		printf("OPCAO INVALIDA, TENTE NOVAMENTE\n\n");
		system("pause");
		system("cls");
		break;
	}	
	
}while(op!=6);
}

