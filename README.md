#Campo Minado em C
-Este projeto é um jogo de Campo Minado desenvolvido em linguagem C. O jogador deve escolher uma dificuldade e tentar descobrir todas as posições seguras em uma matriz, enquanto evita bombas escondidas.

#Como Funciona
-O jogo gera um campo minado com diferentes níveis de dificuldade (fácil, médio ou difícil). O jogador insere coordenadas para "abrir" posições no campo. Se a posição contém uma bomba, o jogo acaba. Se todas as posições seguras forem descobertas, o jogador vence.

#1. Escolha da Dificuldade
-Ao iniciar o programa, você será solicitado a escolher um dos três níveis de dificuldade:

fácil: Gera uma matriz 10x10 com 3 bombas.
médio: Gera uma matriz 20x20 com 6 bombas.
difícil: Gera uma matriz 30x30 com 9 bombas.
#2. Campo de Jogo
O campo é uma matriz de n x n, onde n depende da dificuldade escolhida. A borda da matriz é reservada para evitar erros de cálculo nas verificações de bombas.
Por exemplo, se a Matriz escolhida é uma 10X10 , o programa cria uma 12X12,no entanto, ele gera bombas em coordenadas aleatorias somente na "parte" 10X10. Com isso,
evitando verificar ou somar elementos fora da matriz. Além de permitir que o usuário so escolha coordenadas correspondentes a matriz escolhida.

As posições são inicialmente mostradas com o caractere 'x'.
A cada jogada, o jogador insere coordenadas (x, y) para revelar uma posição:
Se for uma bomba (-1), o jogo termina com Game Over.
Se for uma posição segura, o número de bombas ao redor da posição será mostrado.
3. Condições de Vitória
O jogador vence o jogo ao descobrir todas as posições seguras, ou seja, todas as posições sem bombas.

#4. Controles
O jogador deve fornecer coordenadas x, y para abrir uma célula na matriz, onde x e y variam de acordo com o tamanho da matriz (dependente da dificuldade).

Se o jogador inserir uma coordenada inválida (fora dos limites do campo) ou uma célula já aberta, será solicitado que escolha outra posição.

#5. Finalização do Jogo
O jogo termina em duas condições:

#Game Over: Quando o jogador acerta uma bomba.
#Vitória: Quando todas as posições seguras são descobertas.
Instruções de Uso
#Requisitos
Compilador C (ex: GCC).
Sistema Operacional: Linux ou qualquer outro compatível com o comando clear (o código utiliza system("clear") para limpar o terminal).
Como Compilar
Baixe ou clone o repositório com o código-fonte.

No terminal, compile o programa utilizando o compilador C. Por exemplo, com gcc:

gcc campo_minado_NathaBarbosaDeSouzaPinto.c -o campo_minado

Após a compilação, execute o programa:

./campo_minado

#Como Jogar:

Escolha a dificuldade: fácil, médio, ou difícil.
O jogo exibirá o campo de jogo como uma matriz de 'x'.
Insira as coordenadas (x, y) para descobrir posições seguras no campo.
Exemplo de entrada: 3,4
O jogo revelará o conteúdo da posição escolhida:
Se for uma bomba (-1), o jogo terminará com Game Over.
Se for um número, ele indicará quantas bombas existem nas posições adjacentes.
Continue jogando até descobrir todas as posições seguras ou até acertar uma bomba.
Estrutura do Código
#Funções Principais:
seleciona_dificuldade: Define a dificuldade escolhida pelo jogador.
seleciona_Matriz_Back: Gera o tamanho da matriz de acordo com a dificuldade.
numero_de_Bombas: Define a quantidade de bombas no campo, de acordo com a dificuldade.
constroi_Matriz_Back: Constrói a matriz que armazena as bombas e os números.
matriz_front: Constrói a matriz frontal, que o jogador vê, inicialmente cheia de 'x'.
Funções de impressão (imprime_front e imprime_gameOver): Mostram o estado atual do jogo.
Funções de liberação de memória (libera_matriz_back e libera_matriz_front): Liberam a memória alocada para as matrizes ao fim do jogo.
Autor
Este projeto foi desenvolvido por Natha Barbosa de Souza Pinto para fins de estudo e prática da linguagem C.
