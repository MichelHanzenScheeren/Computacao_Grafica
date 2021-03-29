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
	int o = mat2.size();
	int p = mat2[0].size();
	vector<vector<double>> result;

	// Inicialização da matriz resultante
	for (int i = 0; i < m; i++) {
        result.push_back(vector<double>());
		for (int j = 0; j < p; j++) {
			result[i].push_back(0);
		}
	}

    // Multiplicação das matrizes
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < n; k++) {
				result[i][j] = result[i][j] + mat1[i][k] * mat2[k][j];
			}
		}
	}

	return result;
}

