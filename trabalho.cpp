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
    return limparNosTipo2(primeiro);
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

    NO* no1 = (NO*)malloc(sizeof(NO));
    no1->tipo = 1;
    no1->chave = 1;
    NO* no2 = (NO*)malloc(sizeof(NO));
    no2->tipo = 2;
    NO* no3 = (NO*)malloc(sizeof(NO));
    no3->tipo = 1;
    no3->chave = 2;
    NO* no4 = (NO*)malloc(sizeof(NO));
    no4->tipo = 2;
    NO* no5 = (NO*)malloc(sizeof(NO));
    no5->tipo = 1;
    no5->chave = 3;
    NO* no6 = (NO*)malloc(sizeof(NO));
    no6->tipo = 2;
    NO* no7 = (NO*)malloc(sizeof(NO));
    no7->tipo = 1;
    no7->chave = 4;
    NO* no8 = (NO*)malloc(sizeof(NO));
    no8->tipo = 1;
    no8->chave = 5;
    NO* no9 = (NO*)malloc(sizeof(NO));
    no9->tipo = 2;
    NO* no10 = (NO*)malloc(sizeof(NO));
    no10->tipo = 1;
    no10->chave = 6;
    NO* no11 = (NO*)malloc(sizeof(NO));
    no11->tipo = 2;
    NO* no12 = (NO*)malloc(sizeof(NO));
    no12->tipo = 1;
    no12->chave = 7;
    NO* no13 = (NO*)malloc(sizeof(NO));
    no13->tipo = 1;
    no13->chave = 8;
    NO* no14 = (NO*)malloc(sizeof(NO));
    no14->tipo = 2;
    NO* no15 = (NO*)malloc(sizeof(NO));
    no15->tipo = 1;
    no15->chave = 9;
    NO* no16 = (NO*)malloc(sizeof(NO));
    no16->tipo = 1;
    no16->chave = 10;

    no1->prox= no2;
    no2->prox = no3;
    no2->sublista = no8;
    no3->prox = no4;
    no4->prox = no5;
    no4->sublista = no10;
    no5->prox=no6;
    no6->prox=no7;
    no6->sublista=no12;
    no7->prox=nullptr;
    no8->prox=no9;
    no9->prox=nullptr;
    no9->sublista=no13;
    no10->prox=no11;
    no11->prox=nullptr;
    no11->sublista=no14;
    no12->prox=nullptr;
    no13->prox=nullptr;
    no14->prox=no15;
    no14->sublista=no16;
    no15->prox=nullptr;
    no16->prox=nullptr;


    NO* xx = reordenarLista(no1);

    listarChavesComSubniveis(limparNosTipo2(xx));






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
