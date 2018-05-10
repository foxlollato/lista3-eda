#define RETANGULO 1
#define TRIANGULO 2
#define CIRCULO 3

struct retangulo{
    float a;
    float b;
};
typedef struct retangulo Ret;
typedef struct tipoNo *Lista;


Lista* criaLista();
void apagaLista(Lista* inicio);
int insereFinal(Lista* inicio, int a, int b);
int removeInicio(Lista* inicio);
int removeFinal(Lista* inicio);
int tamLista(Lista* inicio);
int listaVazia(Lista* inicio);
int listaCheia(Lista* inicio);
void imprimeLista(Lista* inicio);
float calculaArea(Ret);
