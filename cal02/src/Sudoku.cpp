/*
 * Sudoku.cpp
 *
 */

#include "Sudoku.h"

/** Inicia um Sudoku vazio.
 */
Sudoku::Sudoku()
{
	this->initialize();
}

/**
 * Inicia um Sudoku com um conteúdo inicial.
 * Lança excepção IllegalArgumentException se os valores
 * estiverem fora da gama de 1 a 9 ou se existirem números repetidos
 * por linha, coluna ou bloc 3x3.
 *
 * @param nums matriz com os valores iniciais (0 significa por preencher)
 */
Sudoku::Sudoku(int nums[9][9])
{
	this->initialize();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (nums[i][j] != 0)
			{
				int n = nums[i][j];
				bool acceptance = accepts(i,j,n);

				if (n < 1 || n > 9 || !acceptance)
					throw IllegalArgumentException;
				else
					place(i, j, n);
			}
		}
	}
}

void Sudoku::initialize()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int n = 0; n < 10; n++)
			{
				numbers[i][j] = 0;
				lineHasNumber[i][n] = false;
				columnHasNumber[j][n] = false;
				block3x3HasNumber[i / 3][j / 3][n] = false;
			}
		}
	}

	this->countFilled = 0;
}

/**
 * Verifica se uma posição aceita um número
 */
bool Sudoku::accepts(int i, int j, int n)
{
	int id = i / 3;
	int jd = j / 3;
	bool l = !lineHasNumber[i][n];
	bool c = !columnHasNumber[j][n];
	bool b = !block3x3HasNumber[id][jd][n];

	return l && c && b;
}

/**
 * Preenche a linha i, coluna j com o número n
 */
void Sudoku::place(int i, int j, int n)
{
	if (numbers[i][j] != 0)
		return;

	numbers[i][j] = n;
	lineHasNumber[i][n] = true;
	columnHasNumber[j][n] = true;
	block3x3HasNumber[i / 3][j / 3][n] = true;
	countFilled++;
}

/**
 * Apaga a linha i, coluna j.
 * Devolve o nº que lá se encontrava anteriormente.
 */
int Sudoku::clear(int i, int j)
{
	int n = numbers[i][j];

	//if (n == 0)
	//	return 0;

	numbers[i][j] = 0;
	lineHasNumber[i][n] = false;
	columnHasNumber[j][n] = false;
	block3x3HasNumber[i / 3][j / 3][n] = false;
	countFilled--;

	return n;
}

/**
 * Verifica se o Sudoku já está completamente resolvido
 */
bool Sudoku::isComplete()
{
	return countFilled == 9 * 9;
}

/**
 * Obtem o conteúdo actual (só para leitura!).
 */
int** Sudoku::getNumbers()
{
	int** ret = new int*[9];

	for (int i = 0; i < 9; i++)
	{
		ret[i] = new int[9];

		for (int a = 0; a < 9; a++)
			ret[i][a] = numbers[i][a];
	}

	return ret;
}

/**
 * Representa conteúdo em string em formato
 * semelhante a um array de arrays em Java.
 */
string Sudoku::toString()
{
	string s = "{";
	for (int i = 0; i < 9; i++)
	{
		s += "{";
		for (int j = 0; j < 9; j++)
		{
			stringstream ss;
			ss << numbers[i][j];

			s += ss.str();
			if (j < 8)
				s += ", ";
		}

		s += "}";
		if (i < 8)
			s += ", \n";
	}

	s += "}";
	return s;
}

/**
 * Resolve o Sudoku.
 * Retorna indicação de sucesso ou insucesso (sudoku impossível).
 */
bool Sudoku::solve()
{
	if (isComplete())
		return true;

	// 1ª Fase: Procurar uma célula com um nº mínimo
	// de números candidatos
	int best_i = -1, best_j = -1, best_num_choices = -1;
	bool getOut = false;

	for (int i = 0; i < 9 ; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (numbers[i][j] == 0)
			{
				int num_choices = 0;

				for (int n = 1; n <= 9; n++)
					if (accepts(i, j, n))
						num_choices++;

				if (num_choices == 0)
					return false; // impossível

				if (best_num_choices == -1
					|| num_choices < best_num_choices) {
					best_num_choices = num_choices;
					best_i = i;
					best_j = j;
				}

				if (best_num_choices == 1)
				{
					getOut = true;
					break;
				}
			}
		}

		if (getOut)
			break;
	}

	// 2ª fase: tentar os vários nºs candidatos
	// na célula escolhida
	for (int n = 1; n <= 9; n++)
	{
		if (accepts(best_i, best_j, n))
		{
			place(best_i, best_j, n);
			if (solve())
				return true;
			clear(best_i, best_j);
		}
	}

	return false;
}

/**
 * Determina a multiplicidade de soluções do Sudoku, com
 * base numa variante do método solve.
 * Não altera o estado do jogo.
 * Retorna
 *   0 se não tiver nenhuma solução,
 *   1 se tiver uma e uma só solução,
 *   >1 se tiver duas ou mais soluções (por razões
 *    de eficiência, não chega a contar todas, parando na segunda)
 */
int Sudoku::countSolutions()
{
	if (isComplete())
		return 1;

	// 1ª Fase: Procurar uma célula com um nº mínimo
	// de números candidatos
	int best_i = -1, best_j = -1, best_num_choices = -1;
	bool getOut = false;

	for (int i = 0; i < 9 ; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (numbers[i][j] == 0) {
				int num_choices = 0;

				for (int n = 1; n <= 9; n++)
					if (accepts(i, j, n))
						num_choices++;

				if (num_choices == 0)
					return 0; // impossível

				if (best_num_choices == -1
					|| num_choices < best_num_choices) {
					best_num_choices = num_choices;
					best_i = i;
					best_j = j;
				}

				if (best_num_choices == 1)
				{
					getOut = true;
					break;
				}
			}
		}

		if (getOut)
			break;
	}

	// 2ª fase: tentar os vários nºs candidatos
	// na célula escolhida
	int count = 0;
	for (int n = 1; n <= 9; n++)
		if (accepts(best_i, best_j, n)) {
				place(best_i, best_j, n);
				count += countSolutions();
				clear(best_i, best_j);
				if (count > 1)
					break;
			}

	return count;
}

/**
 * Apaga todo o Sudoku
 */
void Sudoku::clear()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (numbers[i][j] != 0)
				clear(i, j);
}

void Sudoku::generate()
{
	clear();
	completeProblem();
	reduce();
}

/**
 * Coloca números aleatoriamente até o
 * Sudoku ter uma e uma só solução.
 */
bool Sudoku::completeProblem()
{
	// Vai preenchendo posições aleatoriamente,
	// verificando em cada passo que não fica impossível,
	// até ter uma e uma só solução.
	int countSolut = countSolutions();
	if (countSolut == 0)
		return false; // impossível, tem é de reduzir
	bool changed  = false;
	while (countSolut > 1) {
		int i = (int) (rand() % 9);
		int j = (int) (rand() % 9);
		int n = 1 + (int) (rand() * 9);
		if (numbers[i][j] == 0 && accepts(i, j, n)) {
			place(i, j, n);
			int count = countSolutions();
			if (count == 0)
				clear(i, j);
			else {
				countSolut = count;
				changed= true;
			}
		}
	}
	return changed;
}

/**
 * Apaga o maior nº de casas possível sem tornar
 * o Sudoku indeterminado
 */
bool Sudoku::reduce()
{
	bool changed = false;

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (numbers[i][j] != 0) {
				int n = numbers[i][j];
				clear(i, j);
				int c = countSolutions();
				if (c > 1)
					place(i, j, n);
				else // 0 ou 1
					changed = true;
			}

	return changed;
}

/**
 * Imprime o Sudoku.
 */
void Sudoku::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int a = 0; a < 9; a++)
			cout << this->numbers[i][a] << " ";

		cout << endl;
	}
}
