Programando Robôs com Céu
==============

Introdução/Justificativa
------------------------

A programação de robôs envolve fazer leituras do ambiente por sensores, computar as informações recebidas
e ativar os atuadores necessários para tais tarefas.
Cada sensor da uma informação muitas vezes essencial para o funcionanto do robô, essas leituras devem ser
processadas concorrentemente e em tempo real, de modo a obter todas as informações necessárias para 
avaliar e escolher a ação a realizar no tempo determinado para cada aplicação.
Como se espera, a característica reativa, concorrente e de tempo real impõe grandes desafios para os 
programadores de robótica.

A linguagem de programação predominante para o desenvolvimento de aplicações em Arduino é avr-C.
Usando arv-C grande parte das aplicações são modeladas por máquinas de estados, que usam variáveis de estado
e o código é de difícil manutenção.
A linguagem Céu possui facilidades dedicadas a lidar com entradas de sensores, resolvendo um dos grandes
problemas de avr-C de controlar o tempo de execução de cada sensor,  e tampouco com concorrência em tempo real
resolvendo o problema de precisar acionar varios atuadores ao mesmo tempo.

Como se espera, a característica reativa, concorrente e de tempo real impõe
grandes desafios para o programadores de robos.

Céu é uma linguagem reativa e concorrente desenvolvida no LabLua do
Departamento de Informática da PUC-Rio.

Objetivos
---------

    * Programar aplicações em avr-C 
    * Programar as mesmas em Céu
    * Comparar as implementações em termos de: 
        facilidade de implementação e depuração
        tamanho do codigo fonte
        tamanho do objeto
    * Relatar o processo      
    
 
Metodologia 
-----------

As aplicações C serão implementadas usando a biblioteca Arduino.

As aplicações Céu serão implementadas usando o bind nativo da linguagem.

O aluno já possui familiaridade com o desenvolvimento de aplicações na area de robotica, em Arduino.

Havería um período de familiarização entre o aluno e a linguagem Céu.
Após isso, haveria um período de familiarização do aluno com o ambiente ceu-arduino.

Imaginamos algo entre 3 aplicações simples, 2 médias e 1 complexa.

Céu tem a vantagem de poder usar as funcoes de C de forma simples.

Acreditamos que parte da base de código será reutilizada entre as aplicações.

Pretendemos utilizar de forma extensa as seguintes características da linguagem:

* O conceito de tempo utilizado:

"Céu is grounded on a precise definition of time as a discrete sequence of external input events: a sequence because only a single input event is handled at a time; discrete because reactions to events are guaranteed to execute in bounded time"

É interessante a ideia sequencial de tempo porque para cada input, o robô reagirá diretamente, desta forma, esperamos criar uma alternativa reativa a maquina de estados e ser discreto também é interessante por em muitos sistemas de robótica existirem
tempos limites para determinadas ações.	

"The synchronous execution model of Céu is based on the hypothesis that internal reactions run infinitely faster in comparison to the rate of external events"


Controle de tempo:

O controle de tempo em C é de dificil implementação e asserção.
"The await statement of Céu supports wall-clock time and handles deltas automatically, resulting in more robust applications."

* Eventos internos:
 Útil para tratar exceções.
 "Internal events also provide means for describing more elaborate control structures, such as exceptions"

A fim de analisar o reaproveitamento de codigo e tempo de depuração usaremos o git, para versionar o código e analisar sua evolução com o tempo, podendo ver erros interessantes e como foram solucionados.

