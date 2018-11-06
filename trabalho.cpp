#include "ep.h"

// ######### ESCREVA O NUMERO DO SEU GRUPO AQUI, CONFORME LINK NA ESPECIFICACAO DO EP
// ignore os warning to compilador, se houver
char* grupo() {
    return("00");
}

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
// ignore os warning to compilador, se houver
char* nroUSP1() {
    return("10723795");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
// ignore os warning to compilador, se houver
char* nroUSP2() {
    return("0000000");
}


NO* reordenarLista(NO*p){
    NO* primeiro = p; //Guarda o primeiro Nó
    while(p){ //Percorre enquanto houver nó
        if(p->prox == NULL) { //Se chegar no final do nível
            NO* temp = primeiro; //Guarda o primeiro nó numa variável auxiliar
            while(temp){ //Cria um novo loop percorrendo a mesma lista do início
                if(temp->tipo == 2 && temp->sublista != NULL){ //Se o nó for um nó de sublista E TIVER sublista
                    p->prox = temp->sublista; //Aponta o PROX do ultimo do nível (que era nulo) para a sublista
                    temp->sublista = NULL; //Define como nulo a sublista
                    break; //Sai do loop
                }
                temp = temp->prox;
            }
        }
        p = p->prox;
    }
    return primeiro;
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


void adicionarListaGeneralizada(NO*p, int tipo, int chave){

}

void listarChavesApenasUmNivel(NO*p){
    while(p){
        if(p->tipo == 1) printf("%d ", p->chave);
        p = p->prox;
    }
}

void listarChavesComSubniveis(NO*p){
    while(p){
        if(p->tipo==1)printf("%d ", p->chave);
        else listarChavesComSubniveis(p->sublista);
        p = p->prox;
    }
}

// o EP consiste em implementar esta funcao
NO* listarChaves(NO* entrada) {
    NO* resp = NULL;

    // sua rotina aqui (o exemplo cria apenas um elemento de chave 1)
    resp = (NO*) malloc(sizeof(NO));
    resp->chave = 1;
    resp->prox = NULL;

    return resp;

}





//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------



int main() {
    /*
    NO* resp5 = (NO*) malloc(sizeof(NO));
    resp5->tipo = 1;
    resp5->chave = 4;
    resp5->prox = NULL;

    NO* resp4 = (NO*) malloc(sizeof(NO));
    resp4->tipo = 1;
    resp4->chave = 3;
    resp4->prox = resp5;

    NO* resp3 = (NO*) malloc(sizeof(NO));
    resp3->tipo = 1;
    resp3->chave = 2;
    resp3->prox = NULL;

    NO* resp2 = (NO*) malloc(sizeof(NO));
    resp2->tipo = 2;
    resp2->prox = resp4;
    resp2->sublista = resp3;

    NO* resp = (NO*) malloc(sizeof(NO));
    resp->tipo = 1;
    resp->chave = 1;
    resp->prox = resp2;
    */

    NO* a1 = (NO*)malloc(sizeof(NO));
    a1->tipo = 1;
    a1->chave = 1;
    NO* a2 = (NO*)malloc(sizeof(NO));
    a2->tipo = 1;
    a2->chave = 2;
    NO* a3 = (NO*)malloc(sizeof(NO));
    a3->tipo = 1;
    a3->chave = 3;
    NO* a4 = (NO*)malloc(sizeof(NO));
    a4->tipo = 1;
    a4->chave = 4;
    NO* b1 = (NO*)malloc(sizeof(NO));
    b1->tipo = 2;
    NO* b2 = (NO*)malloc(sizeof(NO));
    b2->tipo = 2;



    a1->prox = b1;
    a2->prox = nullptr;
    a3->prox = b2;
    a4->prox = nullptr;
    b1->sublista = a3;
    b1->prox = a2;
    b2->sublista = a4;
    b2->prox = nullptr;

    NO* xx = reordenarLista(a1);
    //listarChavesComSubniveis(limparNosTipo2(resp));


    listarChavesApenasUmNivel(xx);






	//NO* p = NULL;

	// aqui vc pode incluir codigo para inserir elementos
	// de teste na sua lista apontada por p

	// o EP sera testado com chamadas deste tipo
	//NO* teste = NULL;
	//teste = listarChaves(p);

	// e aqui vc deveria percorrer a lista teste para ver se ficou correta etc.

	//exibirLista(teste);

}

// por favor nao inclua nenhum código abaixo da função main()
