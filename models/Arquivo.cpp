//---------------------------------------------------------------------------
#pragma hdrstop
#include "Arquivo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//Arquivo::Arquivo(char * caminho) {
//	//_caminhoArquivo = caminho;
//}

vector<vector<double>> Arquivo::Ler(char *caminho)
{
	 _arquivo = fopen(caminho, "r");
	 if(_arquivo != NULL) {
		float x, y, z;
		while (!feof(_arquivo)) {
			fscanf(_arquivo, "%f, %f, %f", &x, &y, &z);
			vector<double> points = {x, y, z};
            _resultado.push_back(points);
		}
        fclose(_arquivo);
	 }
	 return _resultado;
}
