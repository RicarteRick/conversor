/**
 * @file Conversor.c
 * @brief Um menu de conversões de unidades de medida e moedas. O usuário tem a liberdade
 *  de escolher as opções e valores de conversão.
 * @author Mateus Ferreira Silva
 * @author Rick Gomes Ricarte
 * @date 10/06/2019
 * @bugs Nenhum conhecido
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Para compilar e executar corretamente o código utilizando o GCC, no terminal do linux:
 * 1º > gcc -std=c11 -c Conversor.c
 * 2º > gcc -std=c11 -o Conversor.exe Conversor.o
 * 3º > ./Conversor.exe
 */

/**
 * Cabeçalhos das funções utilizadas que serão executadas posteriormente nesse programa.
 * Por enquanto há somente um breve resumo sobre as funções, elas serão melhor explicadas
 *  na documentação própria de cada uma ao longo do programa.
 */

/**
 * @brief Funções de validação e conversão que serão utilizadas em quase todos os menus abaixo.
 *
 */
int validaOpcao (int opcao, int const OPC_MAX);
double validaNegativo (int tipo, double unidade);
double conversao(int tipo, int origem, int destino, double unidade1);

/**
 * @brief Como quase todos os menus funcionam de maneira semelhante, só fora separado o submenu de moeda e ângulo.
 *
 */
void unidades_submenu(int tipo, int origem, int destino);
void unidades_opcoes(int tipo, int opcao, int cont);

/**
 * @brief Menus e funções para os menus de Ângulo devido a função ângulo ter uma implementação mais fácil
 *  e seu funcionamento ser um pouco diferente das demais.
 */
void menuAngulo(void);
void menuAngulo1(void);
void menuAngulo2(void);
void menuAngulo3(void);
void menuAngulo4(void);

/**
 * @brief Menus e funções para os menus de Área.
 *
 */
void menuArea1(void);
void menuArea2(int origem);
double area_conversao(int origem, int destino, double unidade1);

/**
 * @brief Menus e funções para Comprimento.
 *
 */
void menuComprimento1(void);
void menuComprimento2(int origem);
double comprimento_conversao(int origem, int destino, double unidade1);

/**
 * @brief Menus e funções para Força.
 *
 */
void menuForca1(void);
void menuForca2(int origem);
double forca_conversao(int origem, int destino, double unidade1);

/**
 * @brief Menus e funções para Massa.
 *
 */
void menuMassa1(void);
void menuMassa2(int origem);
double massa_conversao(int origem, int destino, double unidade1);

/**
 * @brief Menus e funções para os menus de Moedas.
 *
 */
void menuMoeda1(void);
void menuMoeda2(int origem);
void moeda_submenu(int origem, int destino);
void moeda_opcoes(int opcao);
double moeda_conversao(double moeda1, double moeda2);

/**
 * @brief Menus e funções para os menus de Pressão.
 *
 */
void menuPressao1(void);
void menuPressao2(int origem);
double pressao_conversao (int origem, int destino, double unidade1);

/**
 * @brief Menus e funções para os menus de Temperatura.
 *
 */
void menuTemp1(void);
void menuTemp2(int origem);
double temp_conversao (int origem, int destino, double unidade1);

/**
 * @brief Menus e funções para os menus de Velocidade.
 *
 */
void menuVelo1(void);
void menuVelo2(int origem);
double velo_conversao (int origem, int destino, double unidade1);

 /**
 * @brief Menus e funções para os menus de Volume.
 *
 */
void menuVolume1(void);
void menuVolume2(int origem);
void menuSolido1();
void menuSolido2(int origem);
void menuLiquido1();
void menuLiquido2(int origem);
double volume_conversao (int origem, int destino, double unidade1);


int main(void){
	// Declarações locais
	int const OPC_MAX = 10; // número máximo de opções do menu
	int opcao = 0; // escolhe opção no menu
	system("clear");
	printf("=============================================================\n");
	printf("\t       Conversor de unidades e moedas\n");
	printf("=============================================================\n\nOpções:\n\n");
	printf("   1 - Ângulo\n   2 - Área\n   3 - Comprimento\n   4 - Força\n   5 - Massa\n");
	printf("   6 - Moeda\n   7 - Pressão\n   8 - Temperatura\n   9 - Velocidade\n  10 - Volume\n   0 - Sair\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch (opcao){
		case 0:
            printf("Agradecemos por usar nosso serviço de conversão.\n");
            break;
		case 1:
            menuAngulo(); // Ângulo é um caso diferente, por ser mais simples
            break;
		case 2:
            menuArea1();
            break;
		case 3:
            menuComprimento1();
            break;
		case 4:
            menuForca1();
            break;
		case 5:
		    menuMassa1();
		    break;
		case 6:
		    menuMoeda1();
		    break;
		case 7:
		    menuPressao1();
		    break;
		case 8:
		    menuTemp1();
		    break;
		case 9:
		    menuVelo1();
		    break;
		case 10:
		    menuVolume1();
		    break;
		default:
		    printf("Opção inválida");
	} // switch

    return 0;
} // main

/**
 * @brief Mostra o menu de conversão de ângulo, lê um número inteiro e escolhe outro menu com base nesse número.
 *
 */
void menuAngulo(void){
	// Declarações locais
	int const OPC_MAX = 4;  // número máximo de opções do menu
	int opcao = 0; // escolhe opção no menu

	printf("=============================================================\n");
	printf("\t\t   Conversão de ângulo\n");
	printf("=============================================================\n\nOpções:\n\n");
	printf("   1 - Converter de radiano para grau\n   2 - Converter de grau para radiano\n");
	printf("   3 - Imprimir tabela de radianos para graus\n   4 - Imprimir tabela de graus para radianos\n   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch(opcao){
		case 0:
		    main();
		    break;
		case 1:
		    menuAngulo1();
		    break;
		case 2:
		    menuAngulo2();
		    break;
		case 3:
		    menuAngulo3();
		    break;
		case 4:
		    menuAngulo4();
		    break;
		default:
		    printf("Opção inválida");
	} // switch

    return;
} // menuAngulo

/**
 * @brief Mostra o menu conversão de radianos para graus, lê um número real para efetuar a conversão,
 *	um número inteiro como opção e entra em outro menu com base no número inteiro escolhido.
 *
 */

void menuAngulo1(void){
	// Declarações locais
	int const OPC_MAX = 1; // número máximo de opções do menu
	int opcao = 0; // escolhe opção no menu
	double rad = 0.0;

	printf("=============================================================\n");
	printf("\t\t   Conversão de radiano para grau\n");
	printf("=============================================================\n\n");
	printf("Digite o ângulo em radianos: ");
	scanf("%lf",&rad);
	printf("\nÂngulo em graus:\n     %.2lf\n", rad*57.2958); // faz o cálculo e mostra na tela o resultado
	printf("\n\nOpções:\n 1 - Converter outro ângulo\n 0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch(opcao){
		case 0:
		    menuAngulo();
		    break;
		case 1:
		    menuAngulo1();
		    break;
	} // switch

    return;
} // menuAngulo1

/**
  * @brief Mostra o menu conversão de graus para radianos, lê um número real para efetuar a conversão,
 *	um número inteiro como opção e entra em outro menu com base no número inteiro escolhido.
 *
 */

void menuAngulo2(void){
	// Declarações locais
	int const OPC_MAX = 1; // número máximo de opções do menu
	int opcao = 0; // escolhe opção no menu
	double graus = 0.0;

	printf("=============================================================\n");
	printf("\t\t   Conversão de grau para radiano\n");
	printf("=============================================================\n\n");
	printf("Digite o ângulo em graus: ");
	scanf("%lf",&graus);
	printf("\nÂngulo em radianos:\n     %.2lf\n", graus*0.0174533); // faz o cálculo e mostra na tela o resultado
	printf("\n\nOpções:\n 1 - Converter outro ângulo\n 0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch(opcao){
		case 0:
		    menuAngulo();
		    break;
		case 1:
		    menuAngulo2();
		    break;
	} // switch

    return;
} // menuAngulo2

/**
 * @brief Mostra a tabela de conversão de radianos para graus, lê um número real para efetuar a conversão,
 *  um número inteiro como opção e entra em outro menu com base no número inteiro escolhido.
 *
 */

void menuAngulo3(void){
	// Declarações locais
	int const OPC_MAX = 1; // número máximo de opções do menu
	int opcao = 0; // escolhe opção no menu
	double rad = 0.0;

	printf("=============================================================\n");
	printf("\t\t   Tabela de conversão de radianos para graus\n");
	printf("=============================================================\n\n");
	printf("Digite o incremento em radianos.\n");
	printf("Digite um número real no intervalo [0.01, 6.28]: ");
	scanf("%lf", &rad);
	double aux = rad;
	printf("\n\n\n");
	printf("---------------\n");
	printf("Radianos Graus\n");
	printf("---------------\n");
	for(int i=0; i<=10; i++){
		if(i==0)
			printf("%1.4lf\t%6.1lf\n", rad*0.0, rad*0.0); // faz cálculo e mostra na tela o resultado de modo que forme uma tabela
		else{
			printf("%1.4lf\t%6.1lf\n",rad,rad*57.2958); // faz cálculo e mostra na tela o resultado de modo que forme uma tabela
			rad += aux;
		} // else
	} // for
	printf("---------------\n\n");
	printf("Opções:\n");
	printf("\t1 - Criar outra tabela de radianos para graus\n");
	printf("\t0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch(opcao){
		case 0:
			menuAngulo();
			break;
		case 1:
			menuAngulo3();
		 	break;
	} // switch

	return;
} // menuAngulo3

/**
 * @brief Mostra a tabela de conversão de graus para radianos, lê um número real para efetuar a conversão,
 *  um número inteiro como opção e entra em outro menu com base no número inteiro escolhido.
 *
 */

void menuAngulo4(void){
	// Declarações locais
	int const OPC_MAX = 1; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu
	double graus = 0.0;

	printf("=============================================================\n");
	printf("\t\t   Tabela de conversão de graus para radianos\n");
	printf("=============================================================\n\n");
	printf("Digite o incremento em graus.\n");
	printf("Digite um número real no intervalo [0.1, 359.9]: ");
	scanf("%lf", &graus);
	double aux = graus;
	printf("\n\n\n");
	printf("---------------\n");
	printf("Graus Radianos\n");
	printf("---------------\n");
	for(int i=0; i<=10; i++){
		if(i==0)
			printf("%6.1lf\t%1.4lf\n", graus*0.0, graus*0.0); // faz cálculo e mostra na tela o resultado de modo que forme uma tabela
		else{
			printf("%6.1lf\t%1.4lf\n", graus, graus*0.0174533); // faz cálculo e mostra na tela o resultado de modo que forme uma tabela
			graus += aux;
		} // else
	} // for
	printf("---------------\n\n");
	printf("Opções:\n");
	printf("\t1 - Criar outra tabela de graus para radianos\n");
	printf("\t0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch(opcao){
		case 0:
		 	menuAngulo();
			break;
		case 1:
		 	menuAngulo4();
		 	break;

	} // switch

	return;
} // menuAngulo4

/**
 * @brief Mostra o menu Conversão de unidades de área, lê um número inteiro
 *	e escolhe outro menu com base nesse número.
 *
 */
void menuArea1(void){
	// Declarações locais
	int const OPC_MAX = 16; // número máximo de opções do menu
	int opcao = 0; // escolhe opção no menu

	printf("=============================================================\n");
	printf("\t\t   Conversão de unidades de área\n");
	printf("=============================================================\n\n");
	printf("Converter de uma das seguintes opções:\n\n");
	printf("Sistema Internacional de Unidades\n");
	printf("---------------------------------\n");
	printf("   1 - quilômetro quadrado (km²)\n");
	printf("   2 - hectare (ha)\n");
	printf("   3 - are (a)\n");
	printf("   4 - metro quadrado (m²)\n");
	printf("   5 - decímetro quadrado (dm²)\n");
	printf("   6 - centímetro quadrado (cm²)\n");
	printf("   7 - milímetro quadrado (mm²)\n\n");
	printf("Sistema Inglês\n");
	printf("--------------------------------\n");
	printf("   8 - polegada quadrada (in²)\n");
	printf("   9 - pé quadrado (ft²)\n");
	printf("  10 - jarda quadrada (yd²)\n");
	printf("  11 - rod quadrado\n");
	printf("  12 - rood\n");
	printf("  13 - acre (ac)\n");
	printf("  14 - homestead\n");
	printf("  15 - milha quadrada (mi²)\n");
	printf("  16 - légua quadrada\n");
	printf("-------------------------------\n");
	printf("   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch(opcao){
		case 0:
		    main();
		    break;
		default:
		    menuArea2(opcao);
	} // switch

    return;
} // menuArea1


/**
 * @brief Mostra o segundo menu conversão de unidades de área, lê um número inteiro
 *	e escolhe outro menu com base nesse número e no número do parâmetro.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuArea2(int origem){
	// Declarações locais
	int tipo = 2; // a identidade do menu
	int const OPC_MAX = 16; // número máximo de opções do menu
	int opcao_origem = origem;
	int opcao_destino = 0; // escolhe opção no menu
	int cont = 0; // uma forma encontrada para hora imprimir (km²) e hora imprimir quilômetro quadrado, por exemplo.

	printf("=============================================================\n");
	printf("\t\t   Conversão de unidades de área em ");
	cont++;
	unidades_opcoes(tipo, origem, cont); // nome da unidade de origem
	printf("\n");
	cont = 0;
	printf("=============================================================\n\n");
	printf("Converter para uma das seguintes opções:\n\n");
	printf("Sistema Internacional de Unidades\n");
	printf("---------------------------------\n");
	printf("   1 - quilômetro quadrado (km²)\n");
	printf("   2 - hectare (ha)\n");
	printf("   3 - are (a)\n");
	printf("   4 - metro quadrado (m²)\n");
	printf("   5 - decímetro quadrado (dm²)\n");
	printf("   6 - centímetro quadrado (cm²)\n");
	printf("   7 - milímetro quadrado (mm²)\n\n");
	printf("Sistema Inglês\n");
	printf("--------------------------------\n");
	printf("   8 - polegada quadrada (in²)\n");
	printf("   9 - pé quadrado (ft²)\n");
	printf("  10 - jarda quadrada (yd²)\n");
	printf("  11 - rod quadrado\n");
	printf("  12 - rood\n");
	printf("  13 - acre (ac)\n");
	printf("  14 - homestead\n");
	printf("  15 - milha quadrada (mi²)\n");
	printf("  16 - légua quadrada\n");
	printf("-------------------------------\n");
	printf("   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao_destino);
	opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
	system("clear");
	switch(opcao_destino){
		case 0:
		    menuArea1();
		    break;
		default:
		     unidades_submenu(tipo, opcao_origem, opcao_destino);
	} // switch

    return;
}// menuArea2

/**
 * @brief Mostra o menu Conversão de unidades de comprimento, lê um número inteiro
 *	e escolhe outro menu com base nesse número.
 *
 */
void menuComprimento1(void){
	// Declarações locais
	int const OPC_MAX = 16; // número máximo de opções do menu
	int opcao = 0; // escolhe opção no menu

	printf("=============================================================\n");
	printf("\t\t   Conversão de unidades de comprimento\n");
	printf("=============================================================\n\n");
	printf("Converter de uma das seguintes opções:\n\n");
	printf("Sistema Internacional de Unidades\n");
	printf("---------------------------------\n");
	printf("   1 - quilômetro (km)\n");
	printf("   2 - hectômetro (hm)\n");
	printf("   3 - decâmetro (dam)\n");
	printf("   4 - metro (m)\n");
	printf("   5 - decímetro (dm)\n");
	printf("   6 - centímetro (cm)\n");
	printf("   7 - milímetro (mm)\n\n");
	printf("Sistema Inglês\n");
	printf("--------------------------------\n");
	printf("   8 - polegada (in)\n");
	printf("   9 - pé (ft)\n");
	printf("  10 - jarda (yd)\n");
	printf("  11 - rod\n");
	printf("  12 - furlong\n");
	printf("  13 - corrente\n");
	printf("  14 - mil\n");
	printf("  15 - milha (mi)\n");
	printf("  16 - légua\n");
	printf("-------------------------------\n");
	printf("   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch(opcao){
		case 0:
		    main();
		    break;
		default:
		    menuComprimento2(opcao);
	} // switch

    return;
} // menuComprimento1


/**
 * @brief Mostra o segundo menu conversão de unidades de comprimento, lê um número inteiro
 *	e escolhe outro menu com base nesse número e no número do parâmetro.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuComprimento2(int origem){
	// Declarações locais
	int tipo = 3; // a identidade do menu
	int const OPC_MAX = 16; // número máximo de opções do menu
	int opcao_origem = origem;
	int opcao_destino = 0; // escolhe opção no menu
	int cont = 0; // contador será usado da forma explicada acima na função menuArea2

	printf("=============================================================\n");
	printf("\t\t   Conversão de unidades de comprimento em ");
	cont++;
	unidades_opcoes(tipo, origem,  cont); // nome da unidade de origem
	printf("\n");
	cont = 0;
	printf("=============================================================\n\n");
	printf("Converter para uma das seguintes opções:\n\n");
	printf("Sistema Internacional de Unidades\n");
	printf("---------------------------------\n");
	printf("   1 - quilômetro (km)\n");
	printf("   2 - hectômetro (hm)\n");
	printf("   3 - decâmetro (dam)\n");
	printf("   4 - metro (m)\n");
	printf("   5 - decímetro (dm)\n");
	printf("   6 - centímetro (cm)\n");
	printf("   7 - milímetro (mm)\n\n");
	printf("Sistema Inglês\n");
	printf("--------------------------------\n");
	printf("   8 - polegada (in)\n");
	printf("   9 - pé (ft)\n");
	printf("  10 - jarda (yd)\n");
	printf("  11 - rod\n");
	printf("  12 - furlong\n");
	printf("  13 - corrente\n");
	printf("  14 - mil\n");
	printf("  15 - milha (mi)\n");
	printf("  16 - légua\n");
	printf("-------------------------------\n");
	printf("   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao_destino);
	opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
	system("clear");
	switch(opcao_destino){
		case 0:
		    menuComprimento1();
		    break;
		default:
		     unidades_submenu(tipo, opcao_origem, opcao_destino);
	} // switch

    return;
}// menuComprimento2

/**
 * @brief Mostra o menu Conversão de unidades de força, lê um número inteiro
 *	e escolhe outro menu com base nesse número.
 *
 */
void menuForca1(void){
	// Declarações locais
	int const OPC_MAX = 4; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu

    printf("=============================================================\n");
	printf("\t\t   Conversão de unidades de força\n");
	printf("=============================================================\n\n");
	printf("Converter de uma das seguintes opções:\n\n");
	printf("   1 - Newton (N)\n");
	printf("   2 - Quilograma força (kgf)\n");
	printf("   3 - Dina (dyn)\n");
	printf("   4 - Libra-força (lbf)\n");
	printf("   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch(opcao){
		case 0:
		    main();
		    break;
		default:
		    menuForca2(opcao);
	} // switch

	return;
} // menuForca1


/**
 * @brief Mostra o segundo menu conversão de unidades de força, lê um número inteiro
 *	e escolhe outro menu com base nesse número e no número do parâmetro.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuForca2(int origem){
	// Declarações locais
	int tipo = 4; // a identidade do menu
	int const OPC_MAX = 4; // número máximo de opções do menu
	int opcao_origem = origem;
	int opcao_destino = 0; // escolhe opção no menu
	int cont = 0; // contador será usado da forma explicada acima na função menuArea2

	printf("=============================================================\n");
	printf("\t\t   Conversão de unidades de força em ");
	cont++;
	unidades_opcoes(tipo, origem,  cont); // nome da unidade de origem
	printf("\n");
	cont = 0;
	printf("=============================================================\n\n");
	printf("Converter para uma das seguintes opções:\n\n");
	printf("   1 - Newton (N)\n");
	printf("   2 - Quilograma força (kgf)\n");
	printf("   3 - Dina (dyn)\n");
	printf("   4 - Libra-força (lbf)\n");
	printf("   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao_destino);
	opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
	system("clear");
	switch(opcao_destino){
		case 0:
		    menuForca1();
		    break;
		default:
            unidades_submenu(tipo, opcao_origem, opcao_destino);
	} // switch

    return;
}// menuForca2

/**
 * @brief Mostra o menu Conversão de unidades de massa, lê um número inteiro
 *	e escolhe outro menu com base nesse número.
 *
 */
void menuMassa1(void){
	// Declarações locais
	int const OPC_MAX = 15; // número máximo de opções do menu
	int opcao = 0; // escolhe opção no menu

	printf("=============================================================\n");
	printf("\t\t   Conversão de unidades de massa\n");
	printf("=============================================================\n\n");
	printf("Converter de uma das seguintes opções:\n\n");
	printf("Sistema Internacional de Unidades\n");
	printf("---------------------------------\n");
	printf("   1 - quilograma (kg)\n");
	printf("   2 - hectograma (hg)\n");
	printf("   3 - decagrama (dag)\n");
	printf("   4 - grama (g)\n");
	printf("   5 - decigrama (dg)\n");
	printf("   6 - centigrama (cg)\n");
	printf("   7 - miligrama (mg)\n\n");
	printf("Sistema imperial de medidas (Estados Unidos)\n");
	printf("--------------------------------\n");
	printf("   8 - Tonelada curta\n");
	printf("   9 - Quarto curto\n");
	printf("  10 - Quintal curto\n");
	printf("  11 - Arroba\n");
	printf("  12 - Libra avoirdupois\n");
	printf("  13 - Onça avoirdupois\n");
	printf("  14 - Dracma avoirdupois\n");
	printf("  15 - Grão\n");
	printf("-------------------------------\n");
	printf("   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	switch(opcao){
		case 0:
		    main();
		    break;
		default:
		    menuMassa2(opcao);
	} // switch

    return;
} // menuMassa1


/**
 * @brief Mostra o segundo menu conversão de unidades de massa, lê um número inteiro
 *	e escolhe outro menu com base nesse número e no número do parâmetro.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuMassa2(int origem){
	// Declarações locais
	int tipo = 5; // a identidade do menu
	int const OPC_MAX = 15; // número máximo de opções do menu
	int opcao_origem = origem;
	int opcao_destino = 0; // escolhe opção no menu
	int cont = 0; // contador será usado da forma explicada acima na função menuArea2

	printf("=============================================================\n");
	printf("\t\t   Conversão de unidades de massa em ");
	cont++;
	unidades_opcoes(tipo, origem, cont); // nome da unidade de origem
	printf("\n");
	cont = 0;
	printf("=============================================================\n\n");
	printf("Converter de uma das seguintes opções:\n\n");
	printf("Sistema Internacional de Unidades\n");
	printf("---------------------------------\n");
	printf("   1 - quilograma (kg)\n");
	printf("   2 - hectograma (hg)\n");
	printf("   3 - decagrama (dag)\n");
	printf("   4 - grama (g)\n");
	printf("   5 - decigrama (dg)\n");
	printf("   6 - centigrama (cg)\n");
	printf("   7 - miligrama (mg)\n\n");
	printf("Sistema imperial de medidas (Estados Unidos)\n");
	printf("--------------------------------\n");
	printf("   8 - Tonelada curta\n");
	printf("   9 - Quarto curto\n");
	printf("  10 - Quintal curto\n");
	printf("  11 - Arroba\n");
	printf("  12 - Libra avoirdupois\n");
	printf("  13 - Onça avoirdupois\n");
	printf("  14 - Dracma avoirdupois\n");
	printf("  15 - Grão\n");
	printf("-------------------------------\n");
	printf("   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao_destino);
	opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
	system("clear");
	switch(opcao_destino){
		case 0:
		    menuMassa1();
		    break;
		default:
            unidades_submenu(tipo, opcao_origem, opcao_destino);
	} // switch

    return;
}// menuMassa2

/**
 * @brief Mostra o menu Conversão de unidades de moeda, lê um número inteiro
 *	e escolhe outro menu com base nesse número.
 *
 */
void menuMoeda1(void) {
	// Declarações locais
	int const OPC_MAX = 9; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre moedas\n");
    printf("=============================================================\n\nConverter de uma das opções:\n\n");
    printf("   1 - Dólar Americano (USD)\n   2 - Libra Esterlina (GBP)\n   3 - Euro (EUR)\n");
	printf("   4 - Iene Japonês (JPY)\n   5 - Franco Suíço (CHF)\n   6 - Dólar Australiano (AUD)\n");
    printf("   7 - Dólar Canadense (CAD)\n   8 - Real (BRL)\n   9 - Renmibi (RMB)\n   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);
    opcao = validaOpcao(opcao, OPC_MAX);
    system("clear");
    switch(opcao){
		case 0:
		    main();
		    break;
		default:
		    menuMoeda2(opcao);
	} // switch

    return;
} // menuMoeda1

/**
 * @brief Mostra o segundo menu conversão de unidades de moeda, lê um número inteiro
 *	e escolhe outro menu com base nesse número e no número do parâmetro.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuMoeda2(int origem) {
	// Declarações locais
    int const OPC_MAX = 9; // número máximo de opções do menu
    int opcao_origem = origem;
    int opcao_destino = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre moedas\n");
    printf("=============================================================\n\nConverter para uma das opções:\n\n");
    printf("   1 - Dólar Americano (USD)\n   2 - Libra Esterlina (GBP)\n   3 - Euro (EUR)\n");
	printf("   4 - Iene Japonês (JPY)\n   5 - Franco Suíço (CHF)\n   6 - Dólar Australiano (AUD)\n");
    printf("   7 - Dólar Canadense (CAD)\n   8 - Real (BRL)\n   9 - Renmibi (RMB)\n   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao_destino);
    opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
    system("clear");
    switch(opcao_destino){
		case 0:
		    menuMoeda1();
		    break;
		default:
		    moeda_submenu(opcao_origem, opcao_destino);
	} // switch

    return;
} // menuMoeda2

/**
 * @brief O menu onde será mostrada a conversão de cada caso, tomando como argumento o tipo, as opções de
 * 	moeda origem e moeda destino.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 */
void moeda_submenu(int origem, int destino) {
	// Declarações locais
	int tipo = 5; // a identidade do menu
	int const OPC_MAX = 1; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu
    double moeda1 = 0.0;
	double moeda2 = 0.0;

    printf("=============================================================\n");
    printf("\t\t   Conversão de ");
    moeda_opcoes(origem);
    printf(" para ");
    moeda_opcoes(destino);
    printf("\n=============================================================\n\n");
    printf("Digite a cotação de 1 ");
    moeda_opcoes(origem);
    printf(" em ");
    moeda_opcoes(destino);
    printf("\nDigite um número real positivo: ");
    scanf("%lf", &moeda2);
    moeda2 = validaNegativo(tipo,moeda2);
    printf("\n\nDigite a quantidade, em ");
    moeda_opcoes(origem);
    printf(" a ser convertida.\n");
    printf("Digite um número real positivo: ");
    scanf("%lf", &moeda1);
    moeda1 = validaNegativo(tipo, moeda1);
    printf("\n\n%.2lf ", moeda1);
    moeda_opcoes(origem);
    printf(" equivalem a %.2lf ", moeda_conversao(moeda1, moeda2));
    moeda_opcoes(destino);
    printf("\nOpções:\n");
    printf("   1 - Converter novamente de ");
    moeda_opcoes(origem);
    printf(" para ");
    moeda_opcoes(destino);
	printf("\n   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");

	while (opcao == 1) {
        printf("=============================================================\n");
        printf("\t\t   Conversão de ");
        moeda_opcoes(origem);
        printf(" para ");
        moeda_opcoes(destino);
        printf("\n=============================================================\n\n");
        printf("\n\nDigite a quantidade, em ");
        moeda_opcoes(origem);
        printf(" a ser convertida.\n");
        printf("Digite um número real positivo: ");
        scanf("%lf", &moeda1);
        moeda1 = validaNegativo(tipo, moeda1);
        printf("\n\n%.2lf ", moeda1);
        moeda_opcoes(origem);
        printf(" equivalem a %.2lf ", moeda_conversao(moeda1, moeda2));
        moeda_opcoes(destino);
        printf("\nOpções:\n");
        printf("   1 - Converter novamente de ");
        moeda_opcoes(origem);
        printf(" para ");
        moeda_opcoes(destino);
        printf("\n   0 - Retornar ao menu anterior\n\n");
        printf("Digite uma opção: ");
        scanf("%d", &opcao);
        opcao = validaOpcao(opcao, OPC_MAX);
        system("clear");
	} // while

	system("clear");
	menuMoeda2(origem);

	return;
} // moeda_submenu

/**
 * @brief Para maior praticidade, esta função associa o nome de cada moeda com suas respectivas opções nos menus.
 *
 * @param opcao número inteiro que indica o menu e as configurações que serão exibidos
 */
void moeda_opcoes(int opcao) {
	switch (opcao){
		case 1:
			printf("USD");
            break;
        case 2:
            printf("GBP");
            break;
        case 3:
            printf("EUR");
            break;
        case 4:
            printf("JPY");
            break;
        case 5:
            printf("CHF");
            break;
        case 6:
            printf("AUD");
            break;
        case 7:
            printf("CAD");
            break;
        case 8:
            printf("BRL");
            break;
        case 9:
            printf("RMB");
            break;
	} // switch

    return;
} // moeda_opcoes

/**
 * @brief Função para o cálculo das conversões de moeda.
 *
 * @param moeda1 primeiro valor
 * @param moeda2 segundo valor
 * @return O produto de moeda1 por moeda2 (cotação)
 */
double moeda_conversao(double moeda1, double moeda2) {
	return moeda1 * moeda2;
} // moeda_conversao

/**
 * @brief Mostra o menu Conversão de unidades de pressão, lê um número inteiro
 *	e escolhe outro menu com base nesse número.
 *
 */
void menuPressao1(void){
	// Declarações locais
	int const OPC_MAX = 5; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão de unidades de pressão\n");
    printf("=============================================================\n\n");
    printf("Converter de uma das seguintes opções:\n\n");
    printf("Sistema Internacional de Unidades\n");
    printf("---------------------------------\n");
    printf("   1 - Megapascal (MPa)\n");
    printf("   2 - Quilopascal (kPa)\n");
    printf("   3 - Pascal (Pa)\n\n");
    printf("Sistema Inglês\n");
    printf("--------------------------------\n");
    printf("   4 - KSI\n");
    printf("   5 - Libra por polegada quadrada (PSI ou lbf/in²)\n");
    printf("-------------------------------\n");
    printf("   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);
    opcao = validaOpcao(opcao, OPC_MAX);
    system("clear");
    switch(opcao){
		case 0:
			main();
            break;
        default:
            menuPressao2(opcao);
	} // switch

    return;
} // menuPressao1

/**
 * @brief Mostra o segundo menu conversão de unidades de pressão, lê um número inteiro
 *	e escolhe outro menu com base nesse número e no número do parâmetro.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuPressao2(int origem){
	// Declarações locais
	int tipo = 7; // a identidade do menu
    int const OPC_MAX = 5; // número máximo de opções do menu
    int opcao_origem = origem;
    int opcao_destino = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão de unidades de pressão\n");
    printf("=============================================================\n\n");
    printf("Converter para uma das seguintes opções:\n\n");
    printf("Sistema Internacional de Unidades\n");
    printf("---------------------------------\n");
    printf("   1 - Megapascal (MPa)\n");
    printf("   2 - Quilopascal (kPa)\n");
    printf("   3 - Pascal (Pa)\n\n");
    printf("Sistema Inglês\n");
    printf("--------------------------------\n");
    printf("   4 - KSI\n");
    printf("   5 - Libra por polegada quadrada (PSI ou lbf/in²)\n");
    printf("-------------------------------\n");
    printf("   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao_destino);
    opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
    system("clear");
    switch(opcao_destino){
		case 0:
			menuPressao1();
            break;
        default:
            unidades_submenu(tipo, opcao_origem, opcao_destino);
	} // switch

    return;
} // menuPressao2

/**
 * @brief Mostra o menu Conversão de escalas de temperaturas, lê um número inteiro
 *	e escolhe outro menu com base nesse número.
 *
 */
void menuTemp1(void){
	// Declarações locais
	int const OPC_MAX = 7; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu

   	printf("=============================================================\n");
    printf("\t\t   Conversão de escalas de temperaturas\n");
    printf("=============================================================\n\nConverter de uma das opções:\n\n");
    printf("   1 - Kelvin (K)\n   2 - Grau Celsius (ºC)\n   3 - Grau Fahrenheit (ºF)\n   4 - Grau Rankine (ºRa)\n");
    printf("   5 - Grau Reaumur (ºRe)\n   6 - Grau Newton (ºN)\n   7 - Grau Delisle (ºD)\n   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
   	scanf("%d", &opcao);
    opcao = validaOpcao(opcao, OPC_MAX);
    system("clear");
    switch(opcao){
		case 0:
			main();
            break;
        default:
            menuTemp2(opcao);
	} // switch

    return;
} // menuTemp1

/**
 * @brief Mostra o segundo menu conversão de escalas de temperatura, lê um número inteiro
 *	e escolhe outro menu com base nesse número e no número do parâmetro.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuTemp2(int origem) {
	// Declarações locais
	int tipo = 8; // a identidade do menu
    int const OPC_MAX = 7; // número máximo de opções do menu
    int opcao_origem = origem;
    int opcao_destino = 0; // escolhe opção no menu

   	printf("=============================================================\n");
    printf("\t\t   Conversão de escalas de temperaturas\n");
   	printf("=============================================================\n\nConverter para uma das opções:\n\n");
    printf("   1 - Kelvin (K)\n   2 - Grau Celsius (ºC)\n   3 - Grau Fahrenheit (ºF)\n   4 - Grau Rankine (ºRa)\n");
    printf("   5 - Grau Reaumur (ºRe)\n   6 - Grau Newton (ºN)\n   7 - Grau Delisle (ºD)\n   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao_destino);
    opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
    system("clear");
    switch(opcao_destino){
		case 0:
			menuTemp1();
			break;
        default:
            unidades_submenu(tipo, opcao_origem, opcao_destino);
	} // switch

    return;
} // menuTemp2

/**
 * @brief Mostra o menu Conversão entre velocidades, lê um número inteiro
 *	e escolhe outro menu com base nesse número.
 *
 */
void menuVelo1(void) {
	// Declarações locais
	int const OPC_MAX = 6; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre velocidades\n");
    printf("=============================================================\n\nConverter de uma das opções:\n\n");
    printf("   1 - Quilômetro por hora (km/h)\n   2 - Metro por segundo (m/s)\n");
	printf("   3 - Quilômetro por segundo (km/s)\n   4 - Pé por segundo (ft/s)\n");
    printf("   5 - Milha por hora (mph)\n   6 - Milha por segundo (mps)\n   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);
    opcao = validaOpcao(opcao, OPC_MAX);
    system("clear");
    switch(opcao){
		case 0:
			main();
            break;
        default:
            menuVelo2(opcao);
	} // switch

    return;
} // menuVelo1

/**
 * @brief Mostra o segundo menu conversão entre velocidades, lê um número inteiro
 *	e escolhe outro menu com base nesse número e no número do parâmetro.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuVelo2(int origem) {
	// Declarações locais
	int tipo = 9; // a identidade do menu
    int const OPC_MAX = 6; // número máximo de opções do menu
    int opcao_origem = origem;
    int opcao_destino = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre velocidades\n");
    printf("=============================================================\n\nConverter para uma das opções:\n\n");
    printf("   1 - Quilômetro por hora (km/h)\n   2 - Metro por segundo (m/s)\n");
	printf("   3 - Quilômetro por segundo (km/s)\n   4 - Pé por segundo (ft/s)\n");
    printf("   5 - Milha por hora (mph)\n   6 - Milha por segundo (mps)\n   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao_destino);
    opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
    system("clear");
    switch(opcao_destino){
		case 0:
			menuVelo1();
			break;
        default:
            unidades_submenu(tipo, opcao_origem, opcao_destino);
	} // switch

    return;
} // menuVelo2

/**
 * @brief Mostra o menu Conversão entre unidades de volume, lê um número inteiro
 *	e escolhe outro menu com base nesse número.
 *
 */
void menuVolume1(void) {
	// Declarações locais
	int const OPC_MAX = 2; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre unidades de volume\n");
    printf("=============================================================\n\nConverter de uma das opções:\n\n");
    printf("   1 - Unidades de volume sólido\n   2 - Unidades de volume líquido\n   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);
    opcao = validaOpcao(opcao, OPC_MAX);
    system("clear");
    switch(opcao){
		case 0:
			main();
            break;
        case 1:
            menuSolido1();
            break;
        case 2:
            menuLiquido1();
	} // switch

    return;
} // menuVolume1

/**
 * @brief Possuindo como argumento a opção escolhida do menu anterior como origem, o usuário
 *	agora escolhe a opção  entre as unidades de volume sólido.
 *
 */
void menuSolido1(void) {
	// Declarações locais
	int const OPC_MAX = 10; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre unidades de volume sólido\n");
    printf("=============================================================\n\n");
    printf("Converter de uma das seguintes opções:\n\n");
    printf("Sistema Internacional de Unidades\n");
    printf("---------------------------------\n");
    printf("   1 - Quilômetro cúbico\n");
    printf("   2 - Hectômetro cúbico\n");
    printf("   3 - Decâmetro cúbico\n");
    printf("   4 - Metro cúbico\n");
    printf("   5 - Decímetro cúbico\n\n");
    printf("Sistema de medidas imperiais (Estados Unidos)\n");
    printf("--------------------------------\n");
    printf("   6 - Polegada cúbica\n");
    printf("   7 - Pé cúbico\n");
    printf("   8 - Jarda cúbica\n");
    printf("   9 - Acre-pé\n");
    printf("  10 - Milha cúbica\n\n");
    printf("-------------------------------\n");
    printf("   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);
    opcao = validaOpcao(opcao, OPC_MAX);
    system("clear");
    switch(opcao){
		case 0:
			menuVolume1();
            break;
        default:
            menuVolume2(opcao);
	} // switch

    return;
} // menuSolido1

/**
 * @brief Possuindo como argumento a opção escolhida do menu anterior como origem, o usuário
 *	agora escolhe a opção  entre as unidades de volume líquido.
 *
 */
void menuLiquido1(void) {
	// Declarações locais
	int const OPC_MAX = 13; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre unidades de volume líquido\n");
    printf("=============================================================\n\n");
    printf("Converter de uma das seguintes opções:\n\n");
    printf("Sistema Internacional de Unidades\n");
    printf("---------------------------------\n");
    printf("   1 - Quilolitro\n");
    printf("   2 - Hectolitro\n");
    printf("   3 - Decalitro\n");
    printf("   4 - Litro\n");
    printf("   5 - Decilitro\n");
    printf("Sistema de medidas imperiais (Estados Unidos)\n");
    printf("--------------------------------\n");
    printf("   6 - Barril\n");
    printf("   7 - Galão\n");
    printf("   8 - Quarto\n");
    printf("   9 - Pinto\n");
    printf("  10 - Gill\n");
    printf("  11 - Onça líquida ou fluida\n");
    printf("  12 - Dracma líquido ou fluido\n");
    printf("  13 - Minim\n\n");
    printf("-------------------------------\n");
    printf("   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao);
    opcao = validaOpcao(opcao, OPC_MAX);
    system("clear");
    switch(opcao){
		case 0:
			menuVolume1();
            break;
        default:
            opcao += 10;
            menuVolume2(opcao);
	} // switch

    return;
} // menuLiquido1

/**
 * @brief Mostra o segundo menu conversão entre unidades de volume, lê um número inteiro
 *	e escolhe outro menu (sólido ou líquido) com base nesse número e no número do parâmetro.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuVolume2(int origem) {
	// Declarações locais
	int const OPC_MAX = 2; // número máximo de opções do menu
    int opcao_origem = origem;
    int opcao = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre unidades de volume\n");
    printf("=============================================================\n\nConverter para uma das opções:\n\n");
    printf("   1 - Unidades de volume sólido\n   2 - Unidades de volume líquido\n   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
   	scanf("%d", &opcao);
    opcao = validaOpcao(opcao, OPC_MAX);
    system("clear");
    switch(opcao){
		case 0:
			if (origem <= 10)
				menuSolido1();
            else
				menuLiquido1();
            break;
        case 1:
            menuSolido2(opcao_origem);
            break;
        case 2:
            menuLiquido2(opcao_origem);
    } // switch

    return;
} // menuVolume2

/**
 * @brief Possuindo como argumento a opção escolhida como origem, o usuário
 *	agora escolhe a opção destino dentre os sólidos.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuSolido2(int origem) {
	// Declarações locais
	int tipo = 10; // a identidade do menu
    int const OPC_MAX = 10; // número máximo de opções do menu
    int opcao_origem = origem;
    int opcao_destino = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre unidades de volume sólido\n");
    printf("=============================================================\n\n");
    printf("Converter para uma das seguintes opções:\n\n");
    printf("Sistema Internacional de Unidades\n");
    printf("---------------------------------\n");
    printf("   1 - Quilômetro cúbico\n");
    printf("   2 - Hectômetro cúbico\n");
    printf("   3 - Decâmetro cúbico\n");
    printf("   4 - Metro cúbico\n");
    printf("   5 - Decímetro cúbico\n");
    printf("Sistema de medidas imperiais (Estados Unidos)\n");
    printf("--------------------------------\n");
    printf("   6 - Polegada cúbica\n");
    printf("   7 - Pé cúbico\n");
    printf("   8 - Jarda cúbica\n");
    printf("   9 - Acre-pé\n");
    printf("  10 - Milha cúbica\n");
    printf("-------------------------------\n");
    printf("   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao_destino);
    opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
    system("clear");
    switch(opcao_destino){
		case 0:
			menuVolume2(origem);
            break;
        default:
            unidades_submenu(tipo, opcao_origem, opcao_destino);
	} // switch

    return;
} // menuSolido2

/**
 * @brief Possuindo como argumento a opção escolhida como origem, o usuário
 *	agora escolhe a opção destino dentre os líquidos.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 */
void menuLiquido2(int origem) {
	// Declarações locais
	int tipo = 10; // a identidade do menu
    int const OPC_MAX = 13; // número máximo de opções do menu
    int opcao_origem = origem;
    int opcao_destino = 0; // escolhe opção no menu

    printf("=============================================================\n");
    printf("\t\t   Conversão entre unidades de volume líquido\n");
    printf("=============================================================\n\n");
    printf("Converter para uma das seguintes opções:\n\n");
    printf("Sistema Internacional de Unidades\n");
    printf("---------------------------------\n");
    printf("   1 - Quilolitro\n");
    printf("   2 - Hectolitro\n");
    printf("   3 - Decalitro\n");
    printf("   4 - Litro\n");
    printf("   5 - Decilitro\n");
    printf("Sistema de medidas imperiais (Estados Unidos)\n");
    printf("--------------------------------\n");
    printf("   6 - Barril\n");
    printf("   7 - Galão\n");
    printf("   8 - Quarto\n");
    printf("   9 - Pinto\n");
    printf("  10 - Gill\n");
    printf("  11 - Onça líquida ou fluida\n");
    printf("  12 - Dracma líquido ou fluido\n");
    printf("  13 - Minim\n\n");
    printf("-------------------------------\n");
    printf("   0 - Retornar ao menu anterior\n\n");
    printf("Digite uma opção: ");
    scanf("%d", &opcao_destino);
    opcao_destino = validaOpcao(opcao_destino, OPC_MAX);
    system("clear");
    switch(opcao_destino){
		case 0:
			menuVolume2(origem);
            break;
        default:
            opcao_destino += 10;
            unidades_submenu(tipo, opcao_origem, opcao_destino);
    	} // switch

    return;
} // menuLiquido2

/**
 * @brief O menu onde será mostrada a conversão de cada caso, tomando como argumento o tipo(área, volume etc), as opções de
 *	unidade origem e unidade destino.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param tipo número inteiro que serve como identificação do menu de conversão no momento (massa, volume etc).
 */
void unidades_submenu(int tipo, int origem, int destino){
	// Declarações locais
	int const OPC_MAX = 1; // número máximo de opções do menu
    int opcao = 0; // escolhe opção no menu
    int cont = 0; // contador será usado da forma explicada acima na função menuArea2
    double unidade1 = 0.0;

    printf("=============================================================\n");
    printf("\t\t   Conversão de ");
    unidades_opcoes(tipo, origem, cont);
    cont++;
    printf(" para ");
    unidades_opcoes(tipo, destino, cont);
    cont = 0;
    printf("\n=============================================================\n\n");
    printf("Digite a quantidade, em ");
    unidades_opcoes(tipo, origem, cont);
    if(tipo ==  6)
        printf(" a ser convertida.\n");
    else
        printf(".\n");

    if (tipo == 8)
        printf("Digite um número real: ");
    else
        printf("Digite um número real positivo: ");
    scanf("%lf", &unidade1);
    unidade1 = validaNegativo(tipo, unidade1);
    switch(tipo){
		case 1:
			printf("\n\nÂngulo em ");
			break;
        case 2:
			printf("\n\nÁrea em ");
			break;
        case 3:
			printf("\n\nComprimento em ");
			break;
        case 4:
			printf("\n\nForça em ");
			break;
        case 5:
			printf("\n\nMassa em ");
			break;
        case 7:
			printf("\n\nPressão em ");
			break;
        case 8:
			printf("\n\nTemperatura em ");
			break;
        case 9:
			printf("\n\nVelocidade em ");
			break;
        case 10:
			printf("\n\nVolume em ");
		  	break;
    }
    unidades_opcoes(tipo, destino, cont);
    printf(":\n");
    printf("\t %.2lf\n", conversao(tipo, origem, destino, unidade1));

    printf("\nOpções:\n");
    printf("   1 - Converter novamente de ");
    unidades_opcoes(tipo, origem, cont);
    printf(" para ");
    unidades_opcoes(tipo, destino, cont);
	printf("\n   0 - Retornar ao menu anterior\n\n");
	printf("Digite uma opção: ");
	scanf("%d", &opcao);
	opcao = validaOpcao(opcao, OPC_MAX);
	system("clear");
	cont = 0;
	switch(opcao){
		case 0:
			switch(tipo){
				case 2:
                    menuArea2(origem);
                    break;
				case 3:
                    menuComprimento2(origem);
                    break;
				case 4:
                    menuForca2(origem);
                    break;
				case 5:
                    menuMassa2(origem);
                    break;
				case 7:
                    menuPressao2(origem);
                    break;
                case 8:
                    menuTemp2(origem);
                    break;
                case 9:
                    menuVelo2(origem);
                    break;
                case 10:
                    if (destino <= 10)
						menuSolido2(origem);
                    else
						menuLiquido2(origem);
                    break;
            } // switch
            break;
        case 1:
            unidades_submenu(tipo, origem, destino);
            break;
        default:
            printf("Opção inválida");
	} // switch
	return;
} // unidades_submenu

/**
 * @brief Tomando como argumento o tipo(área, volume etc) e a opção, retorna o nome de tal opção para determinado tipo.
 *
 * @param tipo número inteiro que serve como identificação do menu de conversão no momento (massa, volume etc).
 * @param opcao número inteiro que indica a opção escolhida.
 * @param cont númento inteiro que define o tipo de mensagem que deve ser impressa (abreviada ou por extenso)
 *  no menu em certas ocasiões
 */
void unidades_opcoes(int tipo, int opcao, int cont){
	switch(tipo){
		case 2: // caso seja área
			switch(opcao){
				case 1:
					if(cont == 1)
						printf("quilômetro quadrado");
                    else
						printf("km²");
                    break;
				case 2:
                    if(cont == 1)
						printf("hectare");
                    else
						printf("ha");
                    break;
                case 3:
                    if(cont == 1)
                        printf("are");
                    else
                        printf("a");
                    break;
				case 4:
                    if(cont == 1)
						printf("metro quadrado");
                    else
						printf("m²");
                    break;
				case 5:
                    if(cont == 1)
						printf("decímetro quadrado");
                    else
						printf("dm²");
                    break;
				case 6:
                    if(cont == 1)
						printf("centímetro quadrado");
                    else
						printf("cm²");
                    break;
				case 7:
                    if(cont == 1)
						printf("milímetro quadrado");
                    else
						printf("mm²");
                    break;
				case 8:
                    if(cont == 1)
						printf("polegada quadrada");
                    else
						printf("in²");
                    break;
				case 9:
                    if(cont == 1)
						printf("pé quadrado");
                    else
						printf("ft²");
                    break;
				case 10:
                    if(cont == 1)
						printf("jarda quadrada");
                    else
						printf("yd²");
                    break;
				case 11:
					printf("rod quadrado");
                    break;
				case 12:
                    printf("rood");
                    break;
				case 13:
                    if(cont == 1)
						printf("acre");
                    else
						printf("ac");
                    break;
				case 14:
                    printf("homestead");
                    break;
				case 15:
                    if(cont == 1)
						printf("milha quadrada");
                    else
						printf("mi²");
                    break;
				case 16:
					printf("légua quadrada");
					break;
            } // switch
            break; // fim caso seja área
		case 3: // caso seja comprimento
            switch(opcao){
				case 1:
                    if(cont == 1)
						printf("quilômetro");
                    else
						printf("km");
                    break;
				case 2:
                    if(cont == 1)
						printf("hectômetro");
                    else
						printf("hm");
                    break;
				case 3:
                    if(cont == 1)
						printf("decâmetro");
                    else
						printf("dam");
                    break;
				case 4:
                    if(cont == 1)
						printf("metro");
                    else
						printf("m");
                    break;
				case 5:
                    if(cont == 1)
						printf("decímetro");
                    else
						printf("dm");
                    break;
				case 6:
                    if(cont == 1)
						printf("centímetro");
                    else
						printf("cm");
                    break;
				case 7:
                    if(cont == 1)
						printf("milímetro");
                    else
						printf("mm");
                    break;
				case 8:
                    if(cont == 1)
						printf("polegada");
				   	else
						printf("in");
				   	break;
				case 9:
                    if(cont == 1)
						printf("pé");
                    else
						printf("ft");
                    break;
				case 10:
                    if(cont == 1)
						printf("jarda");
                    else
						printf("yd");
                    break;
				case 11:
                    printf("rod");
                    break;
				case 12:
                    printf("furlong");
                    break;
				case 13:
                    printf("corrente");
                    break;
				case 14:
                    printf("mil");
                    break;
				case 15:
                    if(cont == 1)
                        printf("milha");
                    else
						printf("mi");
                    break;
				case 16:
                    printf("légua");
                    break;
            } // switch
            break; // fim caso seja comprimento
		case 4: // caso seja força
			switch(opcao){
				case 1:
                    if(cont == 1)
						printf("Newton");
                    else
						printf("N");
                    break;
				case 2:
                    if(cont == 1)
						printf("Quilograma força");
                    else
						printf("kgf");
                    break;
				case 3:
                    if(cont == 1)
                        printf("Dina");
                    else
						printf("dyn");
                    break;
				case 4:
                    if(cont == 1)
						printf("Libra-força");
                    else
						printf("lbf");
                    break;
            } // switch
            break; // fim caso seja força
		case 5: // caso seja massa
            switch(opcao){
                case 1:
                    if(cont == 1)
						printf("quilograma");
                    else
						printf("kg");
                    break;
                case 2:
                    if(cont == 1)
						printf("hectograma");
                    else
						printf("hg");
                    break;
				case 3:
                    if(cont == 1)
						printf("decagrama");
                    else
						printf("dag");
                    break;
				case 4:
                    if(cont == 1)
						printf("grama");
                    else
						printf("g");
                    break;
				case 5:
                    if(cont == 1)
						printf("decigrama");
                    else
						printf("dg");
				   	break;
				case 6:
                    if(cont == 1)
						printf("centigrama");
                    else
						printf("cg");
				   	break;
				case 7:
                    if(cont == 1)
						printf("miligrama");
                    else
						printf("mg");
                    break;
				case 8:
                    printf("Tonelada curta");
                    break;
				case 9:
                    printf("Quarto curto");
                    break;
				case 10:
                    printf("Quintal curto");
                    break;
				case 11:
                    printf("Arroba");
                    break;
				case 12:
                    printf("Libra avoirdupois");
                    break;
				case 13:
                    printf("Onça avoirdupois");
                    break;
				case 14:
                    printf("Dracma avoirdupois");
                    break;
				case 15:
                    printf("Grão");
                    break;
            } // switch
            break; // fim caso seja massa
        case 7: // caso seja pressão
            switch(opcao){
                case 1:
                    if(cont == 1)
						printf("Megapascal");
                    else
						printf("MPa");
                    break;
                case 2:
                    if(cont == 1)
						printf("Quilopascal");
                    else
						printf("kPa");
                    break;
                case 3:
                    if(cont == 1)
						printf("Pascal");
                    else
						printf("Pa");
                    break;
                case 4:
                    printf("KSI");
                    break;
                case 5:
                    printf("PSI");
                    break;
            } // switch
            break; // fim caso seja pressão
        case 8: // caso seja temperatura
            switch(opcao){
                case 1:
                    if(cont == 1)
						printf("Kelvin");
                    else
						printf("K");
                    break;
                case 2:
                    if(cont == 1)
						printf("Grau Celsius");
                    else
						printf("ºC");
                    break;
                case 3:
                    if(cont == 1)
						printf("Grau Fahrenheit");
                    else
						printf("ºF");
                    break;
                case 4:
                    if(cont == 1)
						printf("Grau Rankine");
                    else
						printf("ºRa");
                    break;
                case 5:
                    if(cont == 1)
						printf("Grau Réaumur");
                    else
						printf("ºRé");
                    break;
                case 6:
                    if(cont == 1)
						printf("Grau Newton");
                    else
						printf("ºN");
                    break;
                case 7:
                    if(cont == 1)
						printf("Grau Delisle");
                    else
						printf("ºD");
                    break;
            } // switch
            break; // fim caso seja temperatura
        case 9: // caso seja velocidade
            switch(opcao){
                case 1:
                    if(cont == 1)
						printf("Quilômetro por hora");
                    else
						printf("km/h");
                    break;
                case 2:
                    if(cont == 1)
						printf("Metro por segundo");
                    else
						printf("m/s");
                    break;
                case 3:
                    if(cont == 1)
						printf("Quilômetro por segundo");
                    else
						printf("km/s");
                    break;
                case 4:
                    if(cont == 1)
						printf("Pé por segundo");
                    else
						printf("ft/s");
                    break;
                case 5:
                    if(cont == 1)
						printf("Milha por hora");
                    else
						printf("mph");
                    break;
                case 6:
                    if(cont == 1)
						printf("Milha por segundo");
                    else
						printf("mps");
                    break;
            } // switch
            break; // fim caso seja velocidade
        case 10: // caso seja volume
            switch(opcao){
                case 1:
                    printf("Quilômetro cúbico");
                    break;
                case 2:
                    printf("Hectômetro cúbico");
                    break;
                case 3:
                    printf("Decâmetro cúbico");
                    break;
                case 4:
                    printf("Metro cúbico");
                    break;
                case 5:
                    printf("Decímetro cúbico");
                    break;
                case 6:
                    printf("Polegada cúbica");
                    break;
                case 7:
                    printf("Pé cúbico");
                    break;
                case 8:
                    printf("Jarda cúbica");
                    break;
                case 9:
                    printf("Acre-pé");
                    break;
                case 10:
                    printf("Milha cúbica");
                    break;
                case 11:
                    printf("Quilolitro");
                    break;
                case 12:
                    printf("Hectolitro");
                    break;
                case 13:
                    printf("Decalitro");
                    break;
                case 14:
                    printf("Litro");
                    break;
                case 15:
                    printf("Decilitro");
                    break;
                case 16:
                    printf("Barril");
                    break;
                case 17:
                    printf("Galão");
                    break;
                case 18:
                    printf("Quarto");
                    break;
                case 19:
                    printf("Pinto");
                    break;
                case 20:
                    printf("Gill");
                    break;
                case 21:
                    printf("Onça líquida ou fluida");
                    break;
                case 22:
                    printf("Dracma líquido ou fluido");
                    break;
                case 23:
                    printf("Minim");
                    break;
            } // switch
            break; // fim caso seja volume
    } // switch
    return;
} // unidades_opcoes

/**
 * @brief Principal função de conversão que, dado o tipo, opção de origem e opção de destino, pode-se calcular suas unidades
 *	por meio de outra função específica;
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param tipo número inteiro que serve como identificação do menu de conversão no momento (massa, volume etc).
 * @param unidade1 número real que é a unidade de medida a ser convertida.
 * @return A conversão da unidade.
 */
double conversao(int tipo, int origem, int destino, double unidade1){
	if (origem == destino)
		return unidade1;
    switch(tipo){
        case 2:
            return area_conversao(origem, destino, unidade1);
            break;
        case 3:
            return comprimento_conversao(origem, destino, unidade1);
            break;
        case 4:
            return forca_conversao(origem, destino, unidade1);
            break;
        case 5:
            return massa_conversao(origem, destino, unidade1);
            break;
        case 7:
            return pressao_conversao(origem, destino, unidade1);
            break;
        case 8:
            return temp_conversao(origem, destino, unidade1);
            break;
        case 9:
            return velo_conversao (origem, destino, unidade1);
            break;
        case 10:
            return volume_conversao(origem, destino, unidade1);
            break;
    } // switch
} // conversao

/**
 * @brief Função para o cálculo das conversões de área.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param unidade1 número real que é a unidade de medida a ser convertida.
 * @return A conversão da unidade.
 */
double area_conversao(int origem, int destino, double unidade1) {
// Nota: como o resultado é printando com duas casas decimais, números que são muito pequenos são arredondados.
    switch(origem){
		case 1:
			switch(destino){
                case 1:
                    return unidade1;
                    break;
				case 2:
                    return unidade1 * 100;
                    break;
				case 3:
                    return unidade1 * 10000;
                    break;
				case 4:
                    return unidade1 * 1000000;
                    break;
				case 5:
                    return unidade1 * 100000000;
                    break;
				case 6:
                    return unidade1 * 10000000000;
                    break;
				case 7:
                    return unidade1 * 10000000000000;
                    break;
				case 8:
                    return unidade1 * 1550003000;
                    break;
				case 9:
                    return unidade1 * 10763910;
                    break;
				case 10:
                    return unidade1 * 1195990.0463011;
                    break;
				case 11:
                    return unidade1 * 39536.87;
                    break;
				case 12:
                    return unidade1 * 988.42;
                    break;
				case 13:
                    return unidade1 * 247.11;
                    break;
				case 14:
                    return unidade1 * 1.544;
                    break;
				case 15:
                    return unidade1 * 0.386102;
                    break;
				case 16:
                    return unidade1 * 0.05725;
                    break;
            } // switch
			break;
// agora que já sabemos converter de km para qualquer outro graças as funções acima, basta converter para km e fazer o cálculo
		case 2:
			unidade1 = unidade1 * 0.01;
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 3:
			unidade1 = unidade1 * 0.0001;
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 4:
			unidade1 = unidade1 * 0.000001;
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 5:
			unidade1 = unidade1 * (3*0.000001);
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 6:
			unidade1 = unidade1 * (3*0.0000000001);
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 7:
			unidade1 = unidade1 * (3*0.000000000001);
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 8:
			unidade1 = unidade1 * 0.0000000929;
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 9:
			unidade1 = unidade1 * (2.79*0.0000001);
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 10:
			unidade1 = unidade1 * 0.0000008361;
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 11:
			unidade1 = unidade1 * (7.59*0.00001);
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 12:
			unidade1 = unidade1 * (3.04*0.001);
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 13:
			unidade1 = unidade1 * 0.01;
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 14:
			unidade1 = unidade1 * 0.6475;
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 15:
			unidade1 = unidade1 * 2.58999;
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
		case 16:
			unidade1 = unidade1 * 17.47;
			origem = 1;
			area_conversao(origem, destino, unidade1);
			break;
	} // switch
} // area_conversao

/**
 * @brief Função para o cálculo das conversões de comprimento.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param unidade1 número real que é a unidade de medida a ser convertida.
 * @return A conversão da unidade.
 */
double comprimento_conversao(int origem, int destino, double unidade1) { // como é pritado com duas casa número muito pequenos não são vistos
	switch(origem){
		case 1:
			switch(destino){
                case 1:
                    return unidade1;
                    break;
				case 2:
                    return unidade1 * 10.000;
                    break;
				case 3:
                    return unidade1 * 100.00;
                    break;
				case 4:
                    return unidade1 * 1000;
                    break;
				case 5:
                    return unidade1 * 10000;
                    break;
				case 6:
                    return unidade1 * 100000;
                    break;
				case 7:
                    return unidade1 * 1000000;
                    break;
				case 8:
                    return unidade1 * 39370.08;
                    break;
				case 9:
                    return unidade1 * 3280.84;
                    break;
				case 10:
                    return unidade1 * 1093.61;
                    break;
				case 11:
                    return unidade1 * 198.839;
                    break;
				case 12:
                    return unidade1 * 4.971;
                    break;
				case 13:
                    return unidade1 * 49.71;
                    break;
				case 14:
                    return unidade1 * 39370078.74;
                    break;
				case 15:
                    return unidade1 * 0.62;
                    break;
				case 16:
                    return unidade1 * 0.207124;
                    break;
            } // switch
			break;
		case 2:
			unidade1 = unidade1 * 0.1;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 3:
			unidade1 = unidade1 * 0.01;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 4:
			unidade1 = unidade1 * 0.001;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 5:
			unidade1 = unidade1 * 0.0001;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 6:
			unidade1 = unidade1 * 0.00001;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 7:
			unidade1 = unidade1 * 0.000001;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 8:
			unidade1 = unidade1 * (2.54*0.00001);
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 9:
			unidade1 = unidade1 * (3.05*0.0001);
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 10:
			unidade1 = unidade1 * (9.14*0.0001);
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 11:
			unidade1 = unidade1 * 0.0050292;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 12:
			unidade1 = unidade1 * 0.2;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 13:
			unidade1 = unidade1 * 0.02;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 14:
			unidade1 = unidade1 * (2.54*0.00000001);
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 15:
			unidade1 = unidade1 * 1.61;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
		case 16:
			unidade1 = unidade1 * 4.82803;
			origem = 1;
			comprimento_conversao(origem, destino, unidade1);
			break;
	} // switch
} // comprimento_conversao

/**
 * @brief Função para o cálculo das conversões de força.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param unidade1 número real que é a unidade de medida a ser convertida.
 * @return A conversão da unidade.
 */
double forca_conversao(int origem, int destino, double unidade1) { // como é pritado com duas casa número muito pequenos não são vistos
	switch(origem){
		case 1:
			switch(destino){
                case 1:
                    return unidade1;
                    break;
				case 2:
                    return unidade1 * 0.101972;
                    break;
				case 3:
                    return unidade1 * 100000;
                    break;
				case 4:
                    return unidade1 * 0,224809;
                    break;
            } // switch
			break;
		case 2:
            unidade1 = unidade1 * 9.80665;
			origem = 1;
			forca_conversao(origem, destino, unidade1);
			break;
		case 3:
			unidade1 = unidade1 * 0.00001;
			origem = 1;
			forca_conversao(origem, destino, unidade1);
			break;
		case 4:
			unidade1 = unidade1 * 4.448222;
			origem = 1;
			forca_conversao(origem, destino, unidade1);
			break;
	} // switch
} // forca_conversao

/**
 * @brief Função para o cálculo das conversões de massa.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param unidade1 número real que é a unidade de medida a ser convertida.
 * @return A conversão da unidade.
 */
double massa_conversao(int origem, int destino, double unidade1) { // como é pritado com duas casa número muito pequenos não são vistos
	switch(origem){
		case 1:
			switch(destino){
                case 1:
                    return unidade1;
                    break;
				case 2:
                    return unidade1 * 10;
                    break;
				case 3:
                    return unidade1 * 100;
                    break;
				case 4:
                    return unidade1 * 1000;
                    break;
				case 5:
                    return unidade1 * 10000;
                    break;
				case 6:
                    return unidade1 * 100000;
                    break;
				case 7:
                    return unidade1 * 1000000;
                    break;
				case 8:
                    return unidade1 * 0.001102;
                    break;
				case 9:
                    return unidade1 * 0.004409245243;
                    break;
				case 10:
                    return unidade1 * 0.022046;
                    break;
				case 11:
                    return unidade1 * 0.0681;
                    break;
				case 12:
                    return unidade1 * 2.204623;
                    break;
				case 13:
                    return unidade1 * 35.273962;
                    break;
				case 14:
                    return unidade1 * 564.383391;
                    break;
				case 15:
                    return unidade1 * 15432.358353;
                    break;
            } // switch
			break;
		case 2:
			unidade1 = unidade1 * 0.1;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 3:
			unidade1 = unidade1 * 0.01;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 4:
			unidade1 = unidade1 * 0.001;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 5:
			unidade1 = unidade1 * 0.0001;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 6:
			unidade1 = unidade1 * 0.00001;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 7:
			unidade1 = unidade1 * 0.000001;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 8:
			unidade1 = unidade1 * 907.18474;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 9:
			unidade1 = unidade1 * 226.796185;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 10:
			unidade1 = unidade1 * 45.359237;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 11:
			unidade1 = unidade1 * 14.6890;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 12:
			unidade1 = unidade1 * 0.453592;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 13:
			unidade1 = unidade1 * 0.02835;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 14:
			unidade1 = unidade1 * 0.001772;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
		case 15:
			unidade1 = unidade1 * 0.000065;
			origem = 1;
			massa_conversao(origem, destino, unidade1);
			break;
    } // switch
} // massa_conversao


/**
 * @brief Função para o cálculo das conversões de pressão.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param unidade1 número real que é a unidade de medida a ser convertida.
 * @return A conversão da unidade.
 */
double pressao_conversao (int origem, int destino, double unidade1){
	switch(origem){
        case 1:
            unidade1 *= 1000000;
            break;
		case 2:
			unidade1 *= 1.000;
			break;
		case 3:
			unidade1 *= 1;
			break;
		case 4:
			unidade1 *= 6894759.0868;
			break;
		case 5:
			unidade1 *= 6894.7590868;
			break;
	} // switch
	switch(destino){
        case 1:
        	return unidade1 * 0.000001;
        	break;
		case 2:
			return unidade1 * 0.001;
			break;
		case 3:
			return unidade1 * 1;
			break;
		case 4:
			return unidade1 * 0.000000145038;
			break;
		case 5:
			return unidade1 * 0.0001450377;
			break;
	} // switch
} // pressao_conversao

/**
 * @brief Função para o cálculo das conversões de temperatura.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param unidade1 número real que é a unidade de medida a ser convertida.
 * @return A conversão da unidade.
 */
double temp_conversao (int origem, int destino, double unidade1){
	switch(origem){
        case 1:
            unidade1 -= 273.15;
            break;
		case 2:
			unidade1 *= 1;
			break;
		case 3:
			unidade1 = (unidade1 - 32) * 0.55555555556;
			break;
		case 4:
			unidade1 = (unidade1 - 491.67) * 0.55555555556;
			break;
		case 5:
			unidade1 *= 1.25;
			break;
		case 6:
			unidade1 /= 0.33000;
			break;
        case 7:
			unidade1 = (unidade1 + 100)/1.5000;
			break;
	} // switch
	switch(destino){
        case 1:
        	return unidade1 + 273.15;
        	break;
		case 2:
			return unidade1 * 1;
			break;
		case 3:
			return unidade1 * 1.8 + 32;
			break;
		case 4:
			return unidade1 * 1.8 + 491.67;
			break;
		case 5:
			return unidade1 * 0.8;
			break;
		case 6:
			return unidade1 * 0.33000;
			break;
        case 7:
			return unidade1 * 1.5000 - 100;
			break;
	} // switch
} // temp_conversao

/**
 * @brief Função para o cálculo das conversões de velocidade.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param unidade1 número real que é a unidade de medida a ser convertida.
 * @return A conversão da unidade.
 */
double velo_conversao (int origem, int destino, double unidade1){
	switch(origem){
        case 1:
            unidade1 *= 0.277778;
            break;
		case 2:
			unidade1 *= 1;
			break;
		case 3:
			unidade1 *= 1000;
			break;
		case 4:
			unidade1 *= 0.3048;
			break;
		case 5:
			unidade1 *= 0.44704;
			break;
		case 6:
			unidade1 *= 1609.344;
			break;
	} // switch
	switch(destino){
        case 1:
        	return unidade1 * 3.6;
        	break;
		case 2:
			return unidade1 * 1;
			break;
		case 3:
			return unidade1 * 0.001;
			break;
		case 4:
			return unidade1 * 3.2808399;
			break;
		case 5:
			return unidade1 * 2.23693629;
			break;
		case 6:
			return unidade1 * 0.00062137;
			break;
	} // switch
} // velo_conversao

/**
 * @brief Função para o cálculo das conversões de volume.
 *
 * @param origem número inteiro que escolhe a opção de um valor de entrada para o cálculo de conversão.
 * @param destino número inteiro que escolhe a opção de um valor de saída para o cálculo de conversão.
 * @param unidade1 número real que é a unidade de medida a ser convertida.
 * @return A conversão da unidade.
 */
double volume_conversao(int origem, int destino, double unidade1){
	switch(origem){
        case 1:
        	unidade1 *= 1000000000;
        	break;
		case 2:
			unidade1 *= 1000000;
			break;
		case 3:
			unidade1 *= 1000;
			break;
		case 4:
			unidade1 *= 1;
			break;
		case 5:
			unidade1 *= 0.001;
			break;
		case 6:
			unidade1 *= 0.0000163871;
			break;
		case 7:
			unidade1 *= 0.0283168359;
			break;
		case 8:
			unidade1 *= 0.7646;
			break;
		case 9:
			unidade1 *= 1233.48184;
			break;
		case 10:
			unidade1 *= 4168181843.0585;
			break;
		case 11:
			unidade1 *= 1;
			break;
		case 12:
			unidade1 *= 0.1;
			break;
		case 13:
			unidade1 *= 0.01;
			break;
		case 14:
			unidade1 *= 0.001;
			break;
		case 15:
			unidade1 *= 0.0001;
			break;
		case 16:
			unidade1 *= 0.1636499972;
			break;
		case 17:
			unidade1 *= 0.0045460993;
			break;
		case 18:
			unidade1 *= 0.0011365249;
			break;
		case 19:
			unidade1 *= 0.0005506105;
			break;
		case 20:
			unidade1 *= 0.0001376526;
			break;
		case 21:
			unidade1 *= 0.0000284131 ;
			break;
		case 22:
			unidade1 *= 0.0000036967;
			break;
		case 23:
			unidade1 *= 0.000000061611523326;
			break;
	} // switch
	switch(destino){
        case 1:
            return unidade1 * 0.000000001;
            break;
		case 2:
			return unidade1 * 0.000001;
			break;
		case 3:
			return unidade1 * 0.001;
			break;
		case 4:
			return unidade1;
			break;
		case 5:
			return unidade1 * 1000;
			break;
		case 6:
			return unidade1 * 61023.76;
			break;
		case 7:
			return unidade1 * 35.31468;
			break;
		case 8:
			return unidade1 * 1.307950613786;
			break;
		case 9:
			return unidade1 * 0.0008107131;
			break;
		case 10:
			return unidade1 * 0.00000000024;
			break;
		case 11:
			return unidade1;
			break;
		case 12:
			return unidade1 * 10;
			break;
		case 13:
			return unidade1 * 100;
			break;
		case 14:
			return unidade1 * 1000;
			break;
		case 15:
			return unidade1 * 10000;
			break;
		case 16:
			return unidade1 * 8.648492;
			break;
		case 17:
			return unidade1 * 227.0208;
			break;
		case 18:
			return unidade1 * 1056.688;
			break;
		case 19:
			return unidade1 * 2113.376;
			break;
		case 20:
			return unidade1 * 8453.507;
			break;
		case 21:
			return unidade1 * 33814.02;
			break;
		case 22:
			return unidade1 * 270512.2;
			break;
		case 23:
			return unidade1 * 16230730;
			break;
	} // switch
} // volume_conversao

/**
 * @brief Função para validar se o usuário escolheu alguma opção existente.
 *
 * @param opcao número inteiro que indica a opção escolhida pelo usuário.
 * @param OPC_MAX número inteiro que indica a quantidade máximo de opções no menu em questão.
 * @return A opção validada.
 */
int validaOpcao (int opcao, int const OPC_MAX) {
	while (opcao < 0 || opcao > OPC_MAX){
        printf("Opção inválida. Tente novamente: ");
        scanf("%d", &opcao);
    } // while

    return opcao;
} // validaOpcao

/**
 * @brief Função para validar se os valores são positivos(em alguns casos pode ser negativo).
 *
 * @param tipo número inteiro que serve como identificação do menu de conversão no momento (massa, volume etc).
 * @return A opção válidada.
 */
double validaNegativo (int tipo, double unidade) {
    if (tipo == 8)
		return unidade;
    while (unidade < 0) {
        printf("Número negativo(inválido). Tente novamente: ");
        scanf("%lf", &unidade);
    } // while

    return unidade;
} // validaNegativo
