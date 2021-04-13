//---------------------------------------------------------------------------
#ifndef ArquivoH
#define ArquivoH
#include <stdio.h>
#include <vector>
using std::vector;
//---------------------------------------------------------------------------
class Arquivo {
	char _caminhoArquivo[50];
	FILE *_arquivo = NULL;
    vector<vector<double>> _resultado;
	public:
		vector<vector<double>> Ler(char *caminho);
};
#endif
