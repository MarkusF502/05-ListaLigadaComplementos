#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	/*
 Explicação da solução:
 o usuário digita o elemento, depois disso há uma série de verificações.
 1- Verifica se há algum elemente igual ao novo;
 2- Se não, verifica se a lista está vazia, caso afirmativo, ele se torna o primeiro;
 3- Se não, verifica se o primeiro elemento é maior que o novo, caso afirmativo, o novo se torna o primeiro e aponta para o primeiro;
 4- Se não ele compara o novo com cada elemento da lista, caso não ache ninguém maior que ele, o novo será o último e o "ex-último" apontará para o novo;
 5- Se existe algum elemento maior que ele, o anterior apontará para o novo e o novo apontará para o próximo;
 */
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        return; 
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;

    NO* aux2 = primeiro;
    bool elementoRepetido = false;

    while (aux2 != NULL) {
        if (aux2->valor == novo->valor) {
            elementoRepetido = true;
            break; 
        }
        aux2 = aux2->prox; 
    }

    if (elementoRepetido) {
        free(novo); 
        cout << "Este elemento já existe na lista" << endl;
    }
    else {
        if (primeiro == NULL) {
            primeiro = novo;
        } 
        else if (primeiro->valor > novo->valor) {
            novo->prox = primeiro;
            primeiro = novo;
        }
        else {
            NO* aux = primeiro;
		
            while (aux->prox != NULL && aux->prox->valor < novo->valor) {
                aux = aux->prox; 
            }

            novo->prox = aux->prox;
            aux->prox = novo;    
        }
    }
}

void excluirElemento()
{

}

void buscarElemento()
{

}


