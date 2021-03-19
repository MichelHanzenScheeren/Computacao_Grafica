//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matriz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
vector<vector<double>> Matriz::Multiplicar(
	vector<vector<double>> mat1, vector<vector<double>> mat2)
{
    int m = mat1.size();
	int n = mat1[0].size();
	int j = mat2.size();
	int k = mat2[0].size();
	vector<vector<double>> result;

	// Inicialização da matriz resultante
	for (int i = 0; i < m; i++) {
        result.push_back(vector<double>());
		for (int j = 0; j < k; j++) {
			result[i].push_back(0);
		}
	}

    // Multiplicação das matrizes
	for (int l = 0; l < m; l++) {
		for (int c = 0; c < k; c++) {
			for (int x = 0; x < k; x++) {
				result[l][c] = result[l][c] + mat1[l][x] * mat2[x][c];
			}
		}
	}
	return result;
}
