/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exemplo_saude.cpp
 * Author: oo
 *
 * Created on 15 de Janeiro de 2019, 22:57
 */


#include "portuC.h"



inteiro inicio(inteiro argc, caractere *argv[]) {


	inteiro alturacentimetros;
	real imc,peso,altura,altura_raiz,idade,pesonormal,pesoideal,tmb,naf,quadril,iac;//nivel de atividade fisica
	caractere nome[20],opcao,sexo,c;
	//setlocale(LC_ALL,"");
	escreva<<""<<pular<<"\aBEM VINDO\a"<<pular<<" "<<pular;
	escreva<<""<<pular<<"digite o seu nome "<<pular<<""<<pular;
	leia>>nome;
        sistema("cls");
	escreva<<""<<pular<<"Muito obrigado por utlizar o nosso aplicativo senhor(a) %s "<<pular<<""<<pular<<""<<pular<<" " <<pular;

		faca{
	    	escreva<<""<<pular<<"\aVoce deseja ver o tutorial ? "<<pular<<"Digite s se sim\a "<<pular<<"Digite n se nao\a"<<pular<<" "<<pular;
	    	leia>>opcao;
	    	sistema("cls");
	    }enquanto(opcao!='s' e opcao!='n');
	    escolha(opcao){
	    	caso 's':
	        	escreva<<""<<pular<<"oprograma fuciona de maneira bem simples "<<pular<<"basta vc digita os dados coretamente "<<pular<<"e espera pelo resultado"<<pular<<""<<pular<<""<<pular;

	        caso 'n':
	        	escreva<<""<<pular<<"vamos começa "<<pular<<""<<pular<<""<<pular;
	        	pare;
	 	}
	 	sistema("pause");
	 	sistema("cls");
	 	faca{//repete o programa
		 	faca {
		    	escreva<<""<<pular<<"\apor favor digite "<<pular<<"h se voce for homem\a "<<pular<<"m se for mulher\a"<<pular<<""<<pular;
		    	leia>>sexo;
		    }enquanto (sexo!='h' e sexo!='m');
		    sistema("cls");
		    escreva<<""<<pular<<"digite o seu peso"<<pular;
		    leia>>peso;
		    sistema("cls");
		    escreva<<""<<pular<<"digite a sua altura (ex:1,65)"<<pular;
		    leia>>altura;
		    sistema("cls");
		    escreva<<""<<pular<<"digite a sua idade"<<pular;
		    leia>>idade;
		    sistema("cls");
		    altura_raiz=sqrt(altura); //raiz da altura
		    faca{ //repepe os qual calcula o usuario vai querer executa
		    	faca{
			    escreva<<""<<pular<<"qual calculo você deseja executa"<<pular<<"a-todos os calculos de um vez só"<<pular<<"b-tmb"<<pular<<"c-imc"<<pular<<"d-peso normal"<<pular<<"e-peso ideal"<<pular<<"f-calculo iac"<<pular;
			    leia>>opcao;
			    }enquanto(opcao!='a' e opcao!='b' e opcao!='c' e opcao!='d' e opcao!='e' e opcao!='f');
			    sistema("cls");
				se(opcao=='f' ou opcao=='a'){//medida do quadril calculo iac
					escreva<<"medida do quadril"<<pular;
					leia>>quadril;
					}

					sistema("cls");
			    escolha(opcao){
				caso'a':// primeira opcao faça todos os calculos
				    	escolha(sexo){
					    	caso'h':
                                                    escreva<<""<<pular<<""<<pular<<"\tdigite o seu nivel de atividdade fisica"<<pular<<""<<pular;
                                                    escreva<<"\tleve:1,55 "<<pular<<"\tmoderada:1,78 "<<pular<<"\tintensa:2,10"<<pular<<""<<pular;
                                                    escreva<<"\tmoderada "<<pular<<" atividade fisica com duracao acima 30 min,2 a 4/semana"<<pular<<""<<pular;
                                                    escreva<<"\tintensa "<<pular<<" atividde fisica com duracao acima 1h,5 ou +/semana"<<pular<<""<<pular<<""<<pular;
                                                    leia>>naf;
						    pare;
					    	caso'm':
						        escreva<<""<<pular<<""<<pular<<"digite o seu nivel de atividdade fisica"<<pular<<" "<<pular;
						        escreva<<"\tleve:1,56 "<<pular<<"\tmoderada:1,64 "<<pular<<"\tintensa:1,82"<<pular<<""<<pular;
						        escreva<<"moderada "<<pular<<" \tatividade fisica com duracao acima 30 min,2 a 4/semana"<<pular<<""<<pular;
						        escreva<<"intensa "<<pular<<" \tatividde fisica com duracao acima 1h,5 ou +/semana"<<pular<<""<<pular<<""<<pular;
						        leia>>naf;
						        pare;
				        }
				    sistema("cls");
				    imc=peso/(altura*altura);//calculo do imc
                                    escreva<<""<<pular<<""<<pular<<"seu imc é de %.1f "<<pular<<""<<imc;
                                    alturacentimetros=altura*100;//tranformando altura em metros em centimetro
				    pesonormal=alturacentimetros-100;//calculo peso normal
				    escreva<<""<<pular<<"o seu peso normal é de %.1f"<<pesonormal;

				    escolha(sexo){
				    	caso'h':
				    		pesoideal=(72.7*altura)-58;//calculo peso ideal para homens
				    		pare;
				    	caso'm':
				        	pesoideal=(62.1*altura)-44.7;//calculo peso ideal para mulheres
				        	pare;
				        }
				    escreva<<""<<pular<<""<<pular<<"o seu peso ideal é %.1f"<<pular<<""<<pular<<""<<pesoideal;

				    escolha(sexo){
				    	caso 'h':
				        	tmb=66.5+peso*14+alturacentimetros*5-idade*6.7;// calculo taxa metabolica basal para homens
				        	tmb=tmb*naf;
				        	pare;
				    	caso 'm':
				        	tmb=peso*9.6+alturacentimetros*1.8-idade*4.7;// calculo taxa metabolica basal para mulheres
				        	tmb=tmb*naf;
				        	pare;
				                }
				    se( imc<17){
				        escreva<<"você esta Muito abaixo do peso"<<pular;
				    }
					se( imc>=17 e imc<=18.49){
				        escreva<<"você esta Abaixo do peso"<<pular;
						 }
				    se ( imc>=18.50 e imc<=24.99){
				        escreva<<"você esta com o Peso normal "<<pular;
				    }
				    se( imc>=25 e imc<=29.99){
				        escreva<<"você esta Acima do peso "<<pular;
				    }
				    se( imc>=30 e imc<=34.99){
				        escreva<<"você esta com Obesidade I"<<pular;
				    }
				    se( imc>=35 e imc<=39.99){
				        escreva<<"você esta com Obesidade II (severa) "<<pular;
				    }
				    se( imc>=40){
				        escreva<<"você esta com Obesidade III (morbida)"<<pular;
				    }
				    escreva<<""<<pular<<"a quantidade minima de energia(calorias) necessaria para manter as fucoes vitas do organismo em reupouso e de %.0f calorias"<<pular<<""<<tmb;
					iac=quadril/(altura*altura_raiz);
					iac=iac-18;
					escreva<<""<<pular<<"seu indice de gordura é de "<<iac<<pular;
					escolha(sexo){
						caso'h':
							se( iac<8){
								escreva<<""<<pular<<"abaixo do peso"<<pular<<""<<pular;
							}
							se( iac>=8 e iac<21){
								escreva<<""<<pular<<"peso normal"<<pular<<""<<pular;
							}
							se( iac>=21 e iac<=25){
								escreva<<""<<pular<<"acima do peso"<<pular<<""<<pular;
							}
							se( iac>25){
								escreva<<""<<pular<<"obesidade"<<pular<<""<<pular;
							}
							pare;
						caso'm':
							se( iac<21){
								escreva<<""<<pular<<"abaixo do peso"<<pular<<""<<pular;
							}
							se( iac>=21 e iac<33){
								escreva<<""<<pular<<"peso normal"<<pular<<""<<pular;
							}
							se( iac>=33 e iac<=38){
								escreva<<""<<pular<<"acima do peso"<<pular<<""<<pular;
							}
							se( iac>38){
								escreva<<""<<pular<<"obesidade"<<pular<<""<<pular;
							}
						pare;
					}
					pare;
				caso'b':  // sengunda opcao taxa metabolica basal
				    	escolha(sexo){
				    	caso'h':
					        escreva<<""<<pular<<""<<pular<<"\tdigite o seu nivel de atividdade fisica"<<pular<<""<<pular;
					        escreva<<"\tleve:1,55 "<<pular<<"\tmoderada:1,78 "<<pular<<"\tintensa:2,10"<<pular<<""<<pular;
					        escreva<<"\tmoderada "<<pular<<" atividade fisica com duracao acima 30 min,2 a 4/semana"<<pular<<""<<pular;
					        escreva<<"\tintensa "<<pular<<" atividde fisica com duracao acima 1h,5 ou +/semana"<<pular<<""<<pular<<""<<pular;
					        leia>>naf;
					        pare;
				    	caso'm':
					        escreva<<""<<pular<<""<<pular<<"digite o seu nivel de atividdade fisica"<<pular<<" "<<pular;
					        escreva<<"leve:1,56 "<<pular<<" moderada:1,64 "<<pular<<" intensa:1,82"<<pular<<""<<pular;
					        escreva<<"moderada "<<pular<<" \tatividade fisica com duracao acima 30 min,2 a 4/semana"<<pular<<""<<pular;
					        escreva<<"intensa "<<pular<<" \tatividde fisica com duracao acima 1h,5 ou +/semana"<<pular<<""<<pular<<""<<pular;
					        leia>>naf;
					        pare;
				        	}
				        	sistema("cls");
				        escolha(sexo){
				    	caso 'h':
				        	tmb=66.5+peso*14+alturacentimetros*5-idade*6.7;
				        	tmb=tmb*naf;
				        	pare;
				    	caso 'm':
				        	tmb=peso*9.6+alturacentimetros*1.8-idade*4.7;
				        	tmb=tmb*naf;
				        	pare;
				                }
						escreva<<""<<pular<<"a quantidade minima de energia(calorias) necessaria para manter as fucoes vitas do organismo em reupouso e de "<<tmb<<" calorias"<<pular;

				    	pare;

				caso'c'://terceira opcao calculo imc
				    	imc=peso/(altura*altura);
				    	escreva<<""<<pular<<""<<pular<<"seu imc é de "<<imc<<pular;
				    	se( imc<17){
							escreva<<"você esta Muito abaixo do peso"<<pular;
						}
						se( imc>=17 e imc<=18.49){
							escreva<<"você esta Abaixo do peso"<<pular;
						}
						se ( imc>=18.50 e imc<=24.99){
							escreva<<"você esta com o Peso normal "<<pular;
						}
						se( imc>=25 e imc<=29.99){
							escreva<<"você esta Acima do peso "<<pular;
						}
						se( imc>=30 e imc<=34.99){
							escreva<<"você esta com Obesidade I"<<pular;
						}
						se( imc>=35 e imc<=39.99){
							escreva<<"você esta com Obesidade II (severa) "<<pular;
						}
						se( imc>=40){
							escreva<<"você esta com Obesidade III (morbida)"<<pular;
						}
				    	pare;

				caso'd': //quarta calculo peso normal
				    	pesonormal=alturacentimetros-100;
				    	escreva<<""<<pular<<"o seu peso normal é de "<<pesonormal;
				    	pare;

				caso'e': //quinta calculo do peso ideal
				    	escolha(sexo){
				    		caso'h':
				    			pesoideal=(72.7*altura)-58;
				    			pare;
				    		caso'm':
				        		pesoideal=(62.1*altura)-44.7;
				        		pare;
				       		}
				    	escreva<<""<<pular<<""<<pular<<"o seu peso ideal é "<<pesoideal<<pular<<pular;
				    	pare;
				caso'f': //sexto calculo do iac
					iac=quadril/(altura*altura_raiz);
					iac=iac-18;
					escreva<<""<<pular<<"seu indice de gordura é de "<<iac<<pular;
					escolha(sexo){
						caso'h':
							se( iac<8){
								escreva<<""<<pular<<"abaixo do peso"<<pular<<""<<pular;
							}
							se( iac>=8 e iac<21){
								escreva<<""<<pular<<"peso normal"<<pular<<""<<pular;
							}
							se( iac>=21 e iac<=25){
								escreva<<""<<pular<<"acima do peso"<<pular<<""<<pular;
							}
							se( iac>25){
								escreva<<""<<pular<<"obesidade"<<pular<<""<<pular;
							}
							pare;
						caso'm':
							se( iac<21){
								escreva<<""<<pular<<"abaixo do peso"<<pular<<""<<pular;
							}
							se( iac>=21 e iac<33){
								escreva<<""<<pular<<"peso normal"<<pular<<""<<pular;
							}
							se( iac>=33 e iac<=38){
								escreva<<""<<pular<<"acima do peso"<<pular<<""<<pular;
							}
							se( iac>38){
								escreva<<""<<pular<<"obesidade"<<pular<<""<<pular;
							}
						pare;
					}

					pare;
				}
				sistema("pause");
				sistema("cls");
				faca{
					escreva<<""<<pular<<""<<pular<<"\avocê deseja executa outro calculo?"<<pular<<"\as para sim"<<pular<<"\an para nao"<<pular;
					leia>>opcao;
				}enquanto(opcao!='s' e opcao!='n');
				sistema("cls");
			}enquanto(opcao=='s');
		    faca{
		    escreva<<""<<pular<<"\avocê deseja executa o programa novamente "<<pular<<"s para sim\a "<<pular<<"n para nao\a "<<pular;
		    leia>>opcao;
	    }enquanto(opcao!='s' e opcao!='n');
    }enquanto(opcao=='s');
    sistema("pause");
	retorna 0;
}

