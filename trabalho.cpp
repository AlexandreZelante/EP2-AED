#include "ep.h"

// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
char* grupo() {
    return("20");
}

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
// ignore os warning to compilador, se houver
char* nroUSP1() {
    return("10723795");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
// ignore os warning to compilador, se houver
char* nroUSP2() {
    return("10687509");
}

NO* limparNosTipo2(NO*p){
    NO* primeiro = p;
    NO* ant = NULL;
    if(p->tipo == 2){
        NO* temp = p->prox;
        free(p);
        p = temp;
        primeiro = p;
    }
    while(p){
        if(p->tipo == 2){
            NO* temp = p->prox;
            ant->prox = p->prox;
            free(p);
            p = temp;
            continue;
        }
        ant = p;
        p = p->prox;
    }
    return primeiro;
}

// o EP consiste em implementar esta funcao
NO* listarChaves(NO* entrada) {
    NO* primeiro = entrada; //Guarda o primeiro Nó
    while(entrada){ //Percorre enquanto houver nó
        if(entrada->prox == NULL) { //Se chegar no final do nível
            NO* temp = primeiro; //Guarda o primeiro nó numa variável auxiliar
            while(temp){ //Cria um novo loop percorrendo a mesma lista do início
                if(temp->tipo == 2 && temp->sublista != NULL){ //Se o nó for um nó de sublista E TIVER sublista
                    entrada->prox = temp->sublista; //Aponta o PROX do ultimo do nível (que era nulo) para a sublista
                    temp->sublista = NULL; //Define como nulo a sublista
                    break; //Sai do loop
                }
                temp = temp->prox;
            }
        }
        entrada = entrada->prox;
    }
    return limparNosTipo2(primeiro);
}

void exibirChavesComSubniveis(NO*p){
    while(p){
        if(p->tipo==1)printf("%d ", p->chave);
        else exibirChavesComSubniveis(p->sublista);
        p = p->prox;
    }
}

//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------



int main() {

	NO* p = NULL;

	// aqui vc pode incluir codigo para inserir elementos
	// de teste na sua lista apontada por p

	// o EP sera testado com chamadas deste tipo
	NO* teste = NULL;
	teste = listarChaves(p);

	// e aqui vc deveria percorrer a lista teste para ver se ficou correta etc.
	//exibirChavesComSubniveis(teste);

}

// por favor nao inclua nenhum código abaixo da função main()
