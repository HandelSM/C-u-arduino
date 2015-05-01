# Ceu-arduino

Introdução/Justificativa
------------------------

A programação de jogos eletrônicos envolve a coordenação de objetos de cena
(centenas ou milhares deles), tais como personagens, itens, projéteis e mapas.
Cada ação do usuário pode gerar uma reação em múltiplos objetos que devem ser
processados concorrentemente e em tempo real, de modo a não afetar a
experiência do usuário.
Além disso, o próprio passar do tempo físico deve ser prontamente processado
como fonte para o movimento contínuo de objetos animados.
Como se espera, a característica reativa, concorrente e de tempo real impõe
grandes desafios para o programadores de jogos eletrônicos.

A linguagem de programação predominante para o desenvolvimento de jogos é C++,
que possui suporte à orientação a objetos e é bastante eficiente.
No entanto, sendo uma linguagem de propósito geral, ela não possui facilidades
dedicadas a lidar com entradas do usuário e tampouco com concorrência em tempo
real.

Acreditamos que Céu é uma alternativa viável para a atual forma de desenvolver jogos, visto as garantias de sincronismo e 
concorrencia que a linguagem oferece e as facilidades em fazer um software que reage com o jogador.

Céu é uma linguagem reativa e concorrente desenvolvida no LabLua do
Departamento de Informática da PUC-Rio.

O aluno teve seu primeiro contato com Céu em seu último projeto, em que utilizou a linguagem para escrever aplicações de redes de sensores sem fio. 
Neste projeto estaremos explorando um outro nicho de aplicações para a linguagem.

Objetivos
---------


O projeto teria 4 etapas principais: 

A reimplementaçao de jogos open source de C++ para Céu,
A comparaçao de tempo, memoria e tamanho de objeto,
A comparação de legibilidade, reaproveitamento de código e o relatório da depuração,
e por fim, a seleção de trechos de codigo C++ que garantam as características reativas e síncronas que Céu já garante.

Metodologia 
-----------

Todos os jogos seriam implementados usando a biblioteca gratuita e multi-plataforma SDL2 (Simple Direct Layer 2).

Apesar do aluno já possuir familiaridade com a linguagem, havería um período de familiarização entre o aluno e a biblioteca SDL2, já suportada por Céu.

Imaginamos implementar algo como 5-10 jogos simples (até 5000 LOC), 2-5 médios (até 15000 LOC), e 1-2 grandes (por volta de 50000 LOC).
Como diversos jogos compartilham semelhanças, acreditamos que boa parte da base de código será reutilizado durante o projeto, podendo servir de base para trabalhos futuros.

Pretendemos utilizar de forma extensa as seguintes características da linguagem:

O conceito de tempo utilizado:

"Céu is grounded on a precise definition of time as a discrete sequence of external input events: a sequence because only a single input event is handled at a time; discrete because reactions to events are guaranteed to execute in bounded time"

É interessante a ideia sequencial de tempo, já que entre dois frames nunca haverá mais de um input do usuario, pela implementação da SDL e pelo fato de que o jogador precisa de uma série de frames para reagir ao jogo. 

Ao mesmo tempo, o processamento de um frame nunca pode ser visível ao usuario, de forma que a contagem de frames por segundo seja suficientemente baixa para o jogador não perceber, onde o modelo síncrono se encaixa.

"The synchronous execution model of Céu is based on the hypothesis that internal reactions run infinitely faster in comparison to the rate of external events"

"Time and sequencing are often a core part of a game’s architecture. Things must happen in the right order, and at the right time." [Game programming patterns](http://gameprogrammingpatterns.com/)

Uso concorrente de memoria:

Por exemplo, quando há varios agentes modificando o estado do jogo em paralelo.

Finalizadores:

Finalizadores são declarações de como uma construção deve ser removida de memória, muito útil para impedir memory leaks.

Controle de tempo:

O controle de tempo em C++ é de dificil implementação e asserção.
"The await statement of Céu supports wall-clock time and handles deltas automatically, resulting in more robust applications."

Eventos internos:

Útil para tratar exceções.
"Internal events also provide means for describing more elaborate control structures, such as exceptions"

Para analisarmos os resultados em termos de processamento, uso de memória e tamanho de código usaremos os seguintes programas: 

gprof, para sabermos quanto tempo foi gasto em cada trecho de codigo.
time, para sabermos o tempo total gasto.
top, para analisarmos o uso de memória.
sloccount, para contarmos as linhas de código.

A fim de analisar o reaproveitamento de codigo e tempo de depuração usaremos o git, para versionar o código e analisar sua evolução com o tempo, podendo ver erros interessantes e como foram solucionados.

