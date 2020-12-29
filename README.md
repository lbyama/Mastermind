# Mastermind

>O jogo Mastermind, também conhecido como 'Super Senha' no Brasil, foi desenvolvido como projeto final da disciplina de Programação III (EMB5631) na UFSC - Campus Joinville no semestre 2019.1.

Este jogo foi desenvolvido em C++ utilizando os conceitos aprendidos durante a disciplina. Mais informações sobre o funcionamento do jogo se encontram [aqui](Relatorio.pdf).

## Como Rodar

```
make all
./Mastermind
```

## Instruções

O jogo deve ser executado no terminal em tela inteira e utiliza comandos do teclado para ser jogado.
No jogo devem ser inseridos valores numéricos ou sequências numéricas baseadas nas cores numeradas exibidas em tela. A inserção de caracteres não numericos pode causar comportamentos indesejados no jogo. Nesse jogo uma casa sem pino é representada por esse símbolo "∙", o marcador para uma cor na posição incorreta é "●" e o marcador para uma cor na posição correta é "○". 

### 2 Jogadores

Ao jogar em dois jogadores, o codebreaker deve desviar o olhar após a tela escrito  "Entre com qualquer tecla + ENTER para vez do codemaker...  " no final de sua rodada. Após inserido um caractere qualquer e apertado a tecla enter iniciará a vez do codemaker, onde o código será exibido em tela.

