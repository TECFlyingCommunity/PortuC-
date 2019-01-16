/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exemplo_saude2.cpp
 * Author: pedro marinho <pedro.marinho238@gmail.com>
 *
 * Created on 16 de Janeiro de 2019, 00:27
 */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pedro marinho <pedro.marinho238@gmail.com>
 *
 * Created on 30 de Abril de 2017, 12:35
 */

#include "portuC.h"
//#include<locale>
vazio imc_padrao(real imc);
vazio tbm_h();
vazio tbm_m();
vazio iac_h(real iac);
vazio iac_m(real iac);
vazio cal_tmb_h(real tmb, real peso, real alturacentimetros, real idade, real naf);
vazio cal_tmb_m(real tmb, real peso, real alturacentimetros, real idade, real naf);
real cal_iac(real iac, real quadril, real altura, real altura_raiz);
real cal_imc( real peso, real altura);
vazio imc_resultado(real imc, real idade, caractere sexo);
vazio imc_homens_acima_de_65_anos(real imc);
vazio imc_mulheres_acima_de_65_anos(real imc);

inteiro inicio(inteiro argc, caractere** argv) {
    inteiro alturacentimetros;
    real imc, peso, altura, altura_raiz, idade, pesonormal, pesoideal, tmb, naf, quadril, iac;
    caractere nome[20], opcao, sexo, c;

    sistema("color e0");
    escreva << pular << "\aBEM VINDO\a" << pular;
    escreva << pular << "Digite o seu nome " << pular;
    leia>>nome;
    sistema("cls");
    escreva << pular << "Muito obrigado por utlizar o nosso aplicativo senhor(a)  " << pular << pular << pular;
    faca{
        escreva << pular << "\aVocê deseja ver o tutorial ? " << pular << "Digite s se sim\a " << pular << "Digite n se nao\a" << pular;
        leia>>opcao;
        sistema("cls");
        } enquanto(opcao diferente 's' e opcao diferente 'n');

    escolha(opcao) {
        caso 's' :
                escreva << pular << "O programa fuciona de maneira bem simples " << pular << "Basta vc digita os dados coretamente " << pular << "E espera pelo resultado" << pular << pular;
        caso 'n' :
                escreva << pular << "Vamos começa " << pular << pular;
        pare;
    }
    sistema("pause");
    sistema("cls");
    faca{
        faca{
            escreva << pular << "\aPor favor digite " << pular << "h Se voce for homem\a " << pular << "m Se for mulher\a" << pular;
            leia>>sexo;
            } enquanto(sexo diferente 'h' e sexo diferente 'm');
        sistema("cls");
        escreva << pular << "Digite o seu peso";
        leia>>peso;
        sistema("cls");
        escreva << pular << "Digite a sua altura (ex:1,65)";
        leia>>altura;
        sistema("cls");
        escreva << pular << "Digite a sua idade";
        leia>>idade;
        sistema("cls");
        altura_raiz = sqrt(altura);
        faca{
            faca{
                escreva << pular << "Qual calculo você deseja executa" << pular << pular << "a-Todos os calculos de uma vez só" << pular << "b-TBM:Taxa Metabólica Basal" << pular << "c-IMC:Índice de Massa Corporal" << pular << "d-Peso Normal" << pular << "e-Peso Ideal" << pular << "f-Calculo IAC:Índice de Adiposidade Corporal";
                leia>>opcao;} enquanto(opcao diferente 'a' e opcao diferente 'b' e opcao diferente 'c' e opcao diferente 'd' e opcao diferente 'e' e opcao diferente 'f');
            sistema("cls");
            se(opcao == 'f' ou opcao == 'a')
            {
                escreva << "Medida faca quadril";
                leia>>quadril;
            }
            sistema("cls");
            escolha(opcao)
            {
                caso'a' :
                    escolha(sexo)
                    {
                        caso'h' :
                            tbm_h();
                            leia>>naf;
                            pare;
                        caso'm' :
                            tbm_m();
                            leia>>naf;
                            pare;
                    }
                    sistema("cls");
                    alturacentimetros = altura * 100;
                    pesonormal = alturacentimetros - 100;
                    escreva << pular << "Segundo o calculo faca Peso Normal  o seu peso normal é de " << pesonormal << pular;
                    escolha(sexo)
                    {
                        caso'h' :
                            pesoideal = (72.7 * altura) - 58;
                            pare;
                        caso'm' :
                            pesoideal = (62.1 * altura) - 44.7;
                            pare;
                    }
                    escreva << pular << pular << "Segundo o calculo faca Pesso ideal o seu peso ideal é " << pesoideal << pular;
                    escolha(sexo)
                    {
                        caso 'h' :
                            cal_tmb_h(tmb, peso, alturacentimetros, idade, naf);
                            pare;
                        caso 'm' :
                            cal_tmb_m(tmb, peso, alturacentimetros, idade, naf);
                            pare;
                    }
//                    cal_imc(imc, peso, altura);
                    imc = cal_imc(peso, altura);

                    escreva << pular << "Segundo o calculo faca IMC o seu imc é de  " << imc << pular;

                    imc_resultado(imc, idade, sexo);
                    cal_iac(iac, quadril, altura, altura_raiz);
                    iac = cal_iac(iac, quadril, altura, altura_raiz);

                    escreva << pular << "Segundo o calculo iac o seu indice de gordura é de " << iac << pular;

                    escolha(sexo)
                    {
                        caso'h' :
                            iac_h(iac);
                            pare;
                        caso'm' :
                            iac_m(iac);
                            pare;
                    }
                pare;
                caso'b' :
                    escolha(sexo)
                    {
                        caso'h' :
                            tbm_h();
                            leia>>naf;
                            pare;
                        
                        caso'm' :
                            tbm_m();
                            leia>>naf;
                            pare;
                    }
                    sistema("cls");
                    escolha(sexo)
                    {
                        caso 'h' :
                            cal_tmb_h(tmb, peso, alturacentimetros, idade, naf);
                            pare;
                        
                        caso 'm' :
                            cal_tmb_m(tmb, peso, alturacentimetros, idade, naf);
                            pare;
                    }
                    pare;
                caso'c' :
                // cal_imc( peso, altura);
                imc = cal_imc( peso, altura);
                escreva << pular << pular << "Segundo o calculo faca IMC o seu imc é de " << imc << pular;
                imc_resultado(imc, idade, sexo);
                pare;
                caso'd' :
                pesonormal = alturacentimetros - 100;
                escreva << pular << "Segundo o calculo faca Peso Normal o seu peso normal é de " << pesonormal << pular;
                pare;
                caso'e' :
                escolha(sexo)
                {
                    caso'h' :
                    pesoideal = (72.7 * altura) - 58;
                    pare;
                    caso'm' :
                    pesoideal = (62.1 * altura) - 44.7;
                    pare;
                }
                escreva << pular << pular << "Segundo o calculo faca Pesso ideal o seu peso ideal é " << pesoideal << pular;
                pare;
                caso'f' :
                cal_iac(iac, quadril, altura, altura_raiz);
                iac = cal_iac(iac, quadril, altura, altura_raiz);
                escreva << pular << "Segundo o calculo IAC o seu indice de gordura é de " << iac << pular;
                escolha(sexo)
                {
                    caso'h' :
                    iac_h(iac);
                    pare;
                    caso'm' :
                    iac_m(iac);
                    pare;
                }
                pare;
            }
            sistema("pause");
            sistema("cls");
            faca{
                escreva << pular << pular << "\aVocê deseja executar outro calculo?" << pular << "\as para sim" << pular << "\an para nao";
                leia>>opcao;} enquanto(opcao diferente 's' e opcao diferente 'n');
            sistema("cls");} enquanto(opcao == 's');
        faca{
            escreva << pular << "\aVocê deseja executar o programa novamente " << pular << "s para sim\a " << pular << "n para nao\a ";
            leia>>opcao;} enquanto(opcao diferente 's' e opcao diferente 'n');} enquanto(opcao == 's');
    sistema("cls");
    sistema("pause");
}

vazio imc_resultado(real imc, real idade, caractere sexo) {
    se(idade < 65)
        imc_padrao(imc);
    se(idade >= 65 e sexo == 'h')
        imc_homens_acima_de_65_anos(imc);
    se(idade >= 65 e sexo == 'm')
        imc_mulheres_acima_de_65_anos(imc);

}

vazio imc_homens_acima_de_65_anos(real imc) {
    se(imc < 21.9)
        escreva << "Segundo o calculo faca IMC Você esta Abaixo faca peso";
    se(imc >= 22 e imc <= 27)
        escreva << "Segundo o calculo faca IMC Você esta com o Peso normal ";
    se(imc >= 27.1 e imc <= 30)
        escreva << "Segundo o calculo faca IMC Você esta Acima faca peso ";
    se(imc >= 30.1 e imc <= 35)
        escreva << "Segundo o calculo faca IMC Você esta com Obesidade I";
    se(imc >= 35.1 e imc <= 39.9)
        escreva << "Segundo o calculo faca IMC Você esta com Obesidade II (severa) ";
    se(imc >= 40)
        escreva << "Segundo o calculo faca IMC Você esta com Obesidade III (morbida)";
}

vazio imc_mulheres_acima_de_65_anos(real imc) {
    se(imc < 21.9)
        escreva << "Segundo o calculo faca IMC Você esta Abaixo faca peso";
    se(imc >= 22 e imc <= 27)
        escreva << "Segundo o calculo faca IMC Você esta com o Peso normal ";
    se(imc >= 27.1 e imc <= 32)
        escreva << "Segundo o calculo faca IMC Você esta Acima faca peso ";
    se(imc >= 32.1 e imc <= 37)
        escreva << "Segundo o calculo faca IMC Você esta com Obesidade I";
    se(imc >= 37.1 e imc <= 41.9)
        escreva << "Segundo o calculo faca IMC Você esta com Obesidade II (severa) ";
    se(imc >= 42)
        escreva << "Segundo o calculo faca IMC Você esta com Obesidade III (morbida)";
}

vazio imc_padrao(real imc) {
    se(imc < 17)
        escreva << "Segundo o calculo faca IMC Você esta Muito abaixo faca peso";
    se(imc >= 17 e imc <= 18.49)
        escreva << "Segundo o calculo faca IMC Você esta Abaixo faca peso";
    se(imc >= 18.50 e imc <= 24.99)
        escreva << "Segundo o calculo faca IMC Você esta com o Peso normal ";
    se(imc >= 25 e imc <= 29.99)
        escreva << "Segundo o calculo faca IMC Você esta Acima faca peso ";
    se(imc >= 30 e imc <= 34.99)
        escreva << "Segundo o calculo faca IMC Você esta com Obesidade I";
    se(imc >= 35 e imc <= 39.99)
        escreva << "Segundo o calculo faca IMC Você esta com Obesidade II (severa) ";
    se(imc >= 40)
        escreva << "Segundo o calculo faca IMC Você esta com Obesidade III (morbida)";
}

vazio tbm_h() {
    escreva << pular << pular << "Digite o seu nivel de atividade fisica" << pular;
    escreva << "leve:1,55 " << pular << "Moderada:1,78 " << pular << "Intensa:2,10" << pular;
    escreva << "moderada " << pular << "Atividade fisica com duracao acima 30 min,2 a 4/semana" << pular;
    escreva << "Intensa " << pular << "Atividde fisica com duracao acima 1h,5 ou +/semana" << pular << pular;
}

vazio tbm_m() {
    escreva << pular << pular << "Digite o seu nivel de atividade fisica" << pular;
    escreva << "Leve:1,56 " << pular << "Moderada:1,64 " << pular << "Intensa:1,82" << pular;
    escreva << "Moderada " << pular << "Atividade fisica com duracao acima 30 min,2 a 4/semana" << pular;
    escreva << "Intensa " << pular << "Atividade fisica com duracao acima 1h,5 ou +/semana" << pular << pular;
}

vazio iac_h(real iac) {
    se(iac < 8)
        escreva << pular << "Segundo o calculo faca IAC Você esta Abaixo faca peso" << pular;
    se(iac >= 8 e iac < 21)
        escreva << pular << "Segundo o calculo faca IAC Você esta com Peso normal" << pular;
    se(iac >= 21 e iac <= 25)
        escreva << pular << "Segundo o calculo faca IAC Você esta Acima faca peso" << pular;
    se(iac > 25)
        escreva << pular << "Segundo o calculo faca IAC Você esta com Obesidade" << pular;
}

vazio iac_m(real iac) {
    se(iac < 21)
        escreva << pular << "Segundo o calculo faca IAC Abaixo faca peso" << pular;
    se(iac >= 21 e iac < 33)
        escreva << pular << "Segundo o calculo faca IAC Peso normal" << pular;
    se(iac >= 33 e iac <= 38)
        escreva << pular << "Segundo o calculo faca IAC Acima faca peso" << pular;
    se(iac > 38)
        escreva << pular << "Segundo o calculo faca IAC Obesidade" << pular;
}

vazio cal_tmb_h(real tmb, real peso, real alturacentimetros, real idade, real naf) {
    tmb = 66.5 + peso * 14 + alturacentimetros * 5 - idade * 6.7; // calculo taxa metabolica basal para homens
    tmb = tmb*naf;
    escreva << pular << "Segundo o calculo faca TBM a quantidade minima de energia(calorias) necessaria para manter as fuções vitais faca organismo em reupouso é de " << tmb << " calorias" << pular;
}

vazio cal_tmb_m(real tmb, real peso, real alturacentimetros, real idade, real naf) {
    tmb = peso * 9.6 + alturacentimetros * 1.8 - idade * 4.7; // calculo taxa metabolica basal para mulheres
    tmb = tmb*naf;
    escreva << pular << "Segundo o calculo faca TBM a quantidade minima de energia(calorias) necessaria para manter as fuções vitais faca organismo em reupouso é de " << tmb << " calorias" << pular;
}

real cal_iac(real iac, real quadril, real altura, real altura_raiz) {
    iac = quadril / (altura * altura_raiz);
    iac = iac - 18;
    retorna iac;
}
real cal_imc( real peso, real altura){
    retorna peso / (altura * altura);   
}
