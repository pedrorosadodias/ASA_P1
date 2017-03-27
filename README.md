# Proj1_ASA
### Descrição do Problema
O Sr. João decidiu fazer um album de fotografias. Ao abrir uma gaveta num móvel da arrecadação o Sr. João encontrou uma grande quantidade de fotografias que tinha acumulado ao longo dos anos. As fotografias não eram digitais, tinham sido obtidas a partir de rolo fotográfico. O Sr. João pensou que seria uma boa oportunidade para organizar um album de família que poderia partilhar com os filhos e os netos.

O objectivo seria organizar as fotografias por data, contudo ele já não se lembra das datas de todas as fotografias e a máquina que tinha usado também não guardava datas. Como as fotografias não são digitais também não é possível ordenar pela data do ficheiro, ou pela metadata. Tudo o que o Sr. João consegue fazer é comparar duas fotos, em alguns casos pensa que sabe qual delas ocorreu primeiro.

O objectivo deste projeto é desenvolver um sistema que ajude o Sr. João com a sua tarefa. Ele vai começar por numerar as fotografias e para alguns pares indicar qual das duas fotografias acha que ocorreu primeiro. O objectivo do software é indicar qual é a ordem temporal das fotografias. Contudo podem surgir alguns problemas. Pode acontecer que a informação fornecida pelo Sr. João seja insuficiente e exista mais do que uma organização possível. O software deve indicar esse problema. Também pode acontecer que o Sr. João se tenha enganado nalgumas das relações que indicou e que portanto não é possível indicar uma ordem coerente. O software também deve indicar esse problema.


### Input
O ficheiro de entrada contém a informação sobre a ordem relativa de alguns pares de fotografias.
 
O input é definido da seguinte forma:

• Uma linha com o número de fotografias N (N ≥ 2) e o número de pares para os quais é
conhecida a ordem L separados por um espaço em branco.

• Uma lista de L linhas, em que cada linha contém dois inteiros u e v (separados por um
espaço em branco) indicando que a primeira fotografia ocorreu antes da segunda. Assume-se que a identificação das fotografias é um inteiro entre 1 e N.


### Output
O seu programa deverá escrever no output a seguinte informação:

• Caso não seja possível determinar uma organização temporal das fotografias porque há relações inconsistentes, o output deve consistir de uma linha com a palavra Incoerente, seguida de um caracter de fim de linha.

• Caso não seja possível determinar uma única organização temporal das fotografias porque a informação é insuficiente, o output deve consistir de uma linha com a palavra Insuficiente, seguida de um caracter de fim de linha.

• Se ambos os problemas ocorrerem simultaneamente deve ser apresentado o output do caso Incoerente.

• Caso seja possível organizar as fotografias, então o output deverá consistir numa linha de números correspondendo à organização temporal das fotografias, em que cada par de números está separado por um espaço em branco. A linha termina com um caracter de fim de linha.



### Exemplos
#### input 1
4 4

1 2

2 3

3 2

3 4

#### output 1
Incoerente



#### input 2
4 4

1 2

3 1

3 4

4 2

#### output 2
Insuficiente



#### input 3
5 6

1 2

2 3

3 2

3 4

1 5

5 4

#### output 3
Incoerente



#### input 4
5 4

1 2

2 3

3 4

4 5

#### output 4
1 2 3 4 5
