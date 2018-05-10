#define RETANGULO 1
#define TRIANGULO 2
#define CIRCULO 3

struct retangulo{
    float a;
    float b;
};

struct triangulo{
    float b;
    float h;
};

struct circulo{
    float raio;
};

typedef struct retangulo Ret;
typedef struct triangulo Tri;
typedef struct circulo Cir;
typedef struct tipoNo *Lista;


Lista* criaLista();
void apagaLista(Lista* inicio);
int insereFinal(Lista* inicio, int tipo);
int removeInicio(Lista* inicio);
int removeFinal(Lista* inicio);
int tamLista(Lista* inicio);
int listaVazia(Lista* inicio);
int listaCheia(Lista* inicio);
void imprimeLista(Lista* inicio);
int calculaAreaLista(Lista *inicio); //Retorna area de todos elementos na lista. Retorna 1 no exito e 0 na falha
