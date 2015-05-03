Avaliação da Linguagem de Programação Céu para Robótica
=======================================================

Introdução/Justificativa
------------------------

A programação de robôs envolve leituras do ambiente por sensores, processamento 
das informações recebidas e ativação de atuadores como resposta ao ambiente.
As leituras dos sensores devem ser processadas concorrentemente e em tempo 
real, de modo a obter as informações necessárias para escolher a próxima ação 
do robô dentro de um tempo limite aceitável de resposta.
Essa característica reativa, concorrente e de tempo real impõe grandes desafios 
para os programadores de robótica.

A linguagem C ainda é predominante no desenvolvimento de robótica e sistemas 
embarcados em geral.
Apesar de ser eficiente em termos de uso de recursos, C não oferece facilidades 
para o desenvolvimento de aplicações concorrentes ou garantias de respostas em 
tempo real.
Grande parte das aplicações são modeladas por máquinas de estados, que usam 
variáveis de estado globais, dificultando o entendimento e manutenção do 
código.

Céu é uma linguagem reativa e concorrente desenvolvida no LabLua do
Departamento de Informática da PUC-Rio.
A linguagem Céu possui facilidades dedicadas a lidar com entradas do ambiente, 
tais como sensores e temporizadores, assim como a controlar múltiplas linhas de 
execução simultâneas.
Dessa maneira, acreditamos que Céu seja uma alternativa mais apropriada para o 
desenvolvimento de robôs.

Objetivos
---------

* Programar aplicações para robôs em C.
* Programar as mesmas aplicações em Céu.
* Comparar as implementações nos seguintes termos:
    * facilidade de implementação e depuração;
    * tamanho do código fonte (e.g., número de linhas);
    * tamanho do objeto (executável);
    * tempo de execução e processamento.
* Relatar o processo      
    
 
Metodologia 
-----------

As aplicações C serão implementadas usando a biblioteca para Arduino, 
atualmente a plataforma de software e hardware mais popular para pesquisa.
As aplicações Céu serão implementadas usando o bind nativo da linguagem para 
Arduino.
O aluno já possui familiaridade com o desenvolvimento de aplicações na área de 
robótica, em Arduino.

Como hardware alvo, utilizaremos um carro e um quadricóptero, desenvolvendo 
múltiplas aplicações para cada um deles.
Variando o número de sensores, atuadores, e software de controle, esperamos 
desenvolver pelo menos três aplicações simples, duas médias e uma complexa.
Como a linguagem Céu pode executar código C diretamente, a funcionalidade 
básica do código fonte será reutilizada entre as aplicações.

Para analisarmos os resultados em termos de processamento, uso de memória e 
tamanho de código usaremos a seguinte abordagem:

* tempo médio entre a leitura de um sensor até a ativação dos atuadores;
* tamanho em bytes da região de código e dados dos programas;
* quantidade de linhas de código, uso de variáveis globais e máquinas de estado 
  explícitas.

<!--
As seguintes características da linguagem Céu serão exploradas no processo de 
desenvolvimento:

* O conceito preciso de tempo:

"Céu is grounded on a precise definition of time as a discrete sequence of 
external input events: a sequence because only a single input event is handled 
at a time; discrete because reactions to events are guaranteed to execute in 
bounded time."

É interessante a ideia sequencial de tempo porque para cada input, o robô 
reagirá diretamente, desta forma, esperamos criar uma alternativa reativa a 
maquina de estados e ser discreto também é interessante por em muitos sistemas 
de robótica existirem tempos limites para determinadas ações.	

"The synchronous execution model of Céu is based on the hypothesis that 
internal reactions run infinitely faster in comparison to the rate of external 
events." 

Controle de tempo:

O controle de tempo em C é de dificil implementação e asserção.

"The await statement of Céu supports wall-clock time and handles deltas 
automatically, resulting in more robust applications."

* Eventos internos:
 Útil para tratar exceções.
 "Internal events also provide means for describing more elaborate control 
structures, such as exceptions."

A fim de analisar o reaproveitamento de codigo e tempo de depuração usaremos o 
git, para versionar o código e analisar sua evolução com o tempo, podendo ver 
erros interessantes e como foram solucionados.
-->
