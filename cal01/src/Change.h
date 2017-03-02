/*
 * Change.h
 */

#ifndef CHANGE_H_
#define CHANGE_H_

#include "Defs.h"

/* Calcula o troco para n c�ntimos, utilizando o n�mero m�nimo de moedas, tendo apenas dispon�veis
 * moedas de 1, 2 e 5 c�ntimos.
 *
 * Devolve:
 * Uma string que cont�m com a indica��o, para cada n, a combina��o de moedas a utilizar.
 * Por exemplo: troco de 1 c�ntimo: 1 moeda de 1
 * 				troco de 2 c�ntimos: 1 moeda de 2
 * 				troco de 3 c�ntimos: 1 moeda de 1, 1 moeda de 2
 * 				(...)
 * A string devolvida representar os valores das moedas (separadas por virgula) para cada n (separado por ponto e v�rgula)
 * Exemplo: 1;2;1,2;2,2;5;1,5;...
 * */
string calcChange(int n);

#endif /* CHANGE_H_ */
