 Exercicios da disciplina de Estrutura de Dados - IFSP ARARAQUARA
**Prof Gislaine C. M. Rosales**
1. Crie um Tipo Abstrato de Dados (TAD) que represente os números racionais e que contenha as seguintes funções: (a) Cria racional; (b) Soma racionais; (c) Multiplica racionais; (d) Testa se são iguais; 

 2. Sabe-se que um número complexo é escrito da forma sendo x a sua parte real e y a parte imaginária, ambas representadas por valores reais. Crie um Tipo Abstrato de Dados (TAD) que represente os números complexos com as seguintes funções: (a) criar um número complexo (b) destruir um número complexo (c) soma de dois números complexos; (d) subtração de dois números complexos; (e) mutiplicação de dois números complexos; (f) divisão de dois números complexos. 

 3. Fazer uma função para verificar se uma lista de inteiros (use conceito de lista sequencial) está ordenada ou não (a ordem pode ser crescente ou decrescente).  

4. Implemente uma função que copia uma lista L1 de elementos inteiros em uma outra lista L2 eliminando elementos repetidos. Os dados devem estar ordenados decrescentemente em L2. Use conceito de lista sequencial.  

5. Considere uma lista com n valores do tipo struct (campos indicados abaixo), faça uma TAD com as seguintes operações: - cadastrar produto; - buscar o produto de menor preço; - buscar produto com estoque inferior a determinado valor informado; - apagar produto do cadastro; - atualizar cadastro de produto (código não pode ser alterado); - gerar relatório de produtos (geral) em estoque (ordem crescente da quantidade em estoque); - gerar relatório de produtos (geral) em estoque (ordem decrescente da quantidade em estoque). Campos para cadastro: codigo do produto; descrição/nome do produto; valor do produto; quantidade em estoque; data da última compra do produto para reposição de estoque.  

6. Crie um programa para realizar merge entre duas listas ordenadas.

 7. Dadas duas listas encadeadas e dinâmicas L1 e L2, implemente uma operação UNION, que cria uma terceira lista L3 com a união entre as duas listas.

8. Desenvolva um programa para armazenar um conjunto de retângulos em uma lista. Cada retângulo é definido pela base b e pela altura h. Além das operações tradicionais, crie uma operação que calcula a área do retângulo (fique à vontade para definir os parâmetros). 

9. Implemente uma variação do programa escrito no exercício anterior, mas desta vez você deverá trabalhar com o conceito de “listas heterogêneas”. Neste caso, você deverá armazenar objetos geométricos planos para cálculos de área. Para simplificar, considere o armazenamento de apenas 3 tipos de objetos: retângulos, triângulos e círculos. Implemente a operação de cálculo de área do objeto.

10. Implemente um código para controle de pouso de aviões em um aeroporto. Utilize o conceito de fila dinâmica e considere uma característica adicional em relação à fila comum: prioridade. Faça o controle de prioridade de acordo com o combustível disponível nos aviões que aguardam na fila. Observe que as operações de inserção, remoção e consulta deverão considerar a prioridade do elemento para ordenação. Implemente utilizando lista dinâmica encadeada. 2 Prof.ª Gislaine Cristina Micheloti Rosales.

11. Implemente um código para controle de inserção e remoção em pilha compartilhada - uso de duas pilhas armazenadas sequencialmente e que compartilham memória de dimensão n. Verifique overflow (estouro da pilha – tentativa de inserir em pilha cheia) e underflow (tentativa de remover de pilha vazia).  

12. Implemente uma calculadora pós-fixada usando lista dinâmica. Valide operadores válidos: + - * /. Determine caractere de finalização da execução: usuário continua fazendo operações até desejar parar ou selecionar opção para cálculo de nova expressão.  

13. Em uma LISTA CIRCULAR ENCADEADA, o último nó aponta para o primeiro (e não para NULL). Dessa forma, se queremos implementar uma fila, basta um ponteiro para o FIM, pois o COMEÇO será o seu próximo. Implemente uma fila circular, com as operação: cria, vazia?, entra, e sai.  

14. Idem ao exercício anterior, mas para pilha. 

15. Considere um sistema de armazenamento temporário de ligações 0800 em espera. Em uma central de atendimento a ligações de clientes as chamadas são colocadas em espera segundo o custo da chamada (primeiro critério) e segundo a ordem de chegada (segundo critério). Utiliza-se, para armazenamento das chamadas, um Tipo Abstrato de Dado (TAD) do tipo lista ordenada, circular, com elementos repetidos, conforme o diagrama abaixo. L é um ponteiro para o início da lista. A lista vazia é composta pelo ponteiro L apontando para Null. Ligações mais caras são inseridas antes das mais baratas. Ligações de um custo X são inseridas após todas as outras ligações de mesmo custo X. Implemente, da forma mais apropriada para o contexto de um TAD, as operações de inserção, remoção e imprimir. Faça todas as validações necessárias. 

 16. Desenvolva um código que inverte as letras de cada palavra de um texto terminado por ponto (.) preservando a ordem das palavras. Por exemplo, dado o texto: ESTE EXERCiCIO EH MUITO FACIL. A saída deve ser: ETSE OICICREXE HE OTIUM LICAF.  

17. Suponha que no desenvolvimento de um programa você e seu grupo de trabalho decidem utilizar uma estrutura de armazenamento do tipo FILA. O Tipo Abstrato de dados Fila é então projetado, com suas operações (Insere, Elimina, Vazia, Cria, FindFirst e FindNext). O trabalho é então dividido e a você coube a tarefa de implementar uma operação que compara se duas filas (F1 e F2) são ou não iguais. Tendo em vista proporcionar maior portabilidade e reusabilidade de código, que estratégia você consideraria mais apropriada para implementar essa operação, e por que? Ilustre sua escolha. Não há necessidade de implementação. 
