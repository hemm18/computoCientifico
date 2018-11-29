#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void determinante(vector<vector<double> >); 



int main(){
	int N = 4; //filas
	int M = 4; //columnas

//Añadimos este Comentario a Git


	vector<vector<double> > Mat(N,vector<double>(M));
	vector<double> b(N);
	
		
	Mat[0][0] = 8;
	Mat[0][1] = -2;
	Mat[0][2] = 0;
	Mat[0][3] = 2;
	Mat[1][0] = -2;
	Mat[1][1] = 7;
	Mat[1][2] = 1;
	Mat[1][3] = 3;
	Mat[2][0] = 3;
	Mat[2][1] = 1;
	Mat[2][2] = 9;
	Mat[2][3] = 1;
	Mat[3][0] = 2;
	Mat[3][1] = 3;
	Mat[3][2] = 2;
	Mat[3][3] = 6;
	
	b[0] = 1;
	b[1] = 3;
	b[2] = -1;
	b[3] = 2;

	
	//IMprimimos Matriz INicial
	cout<<"\n\n\n";
	cout<<"Matriz Inicial";
	cout<<"\n\n\n";
	for(int i = 0; i < Mat.size(); i++)
	{
		for(int j = 0; j < Mat.size(); j++)
		{
			cout<<Mat[i][j];
			cout<<"\t";
		}	
		cout<<"\n";
	}
	
	cout<<"\n";
	cout<<"\n";
	determinante(Mat);
	
	

	return 0;

}


void determinante( vector<vector<double> > Mat) //iniciamos la definicion de nuestro metodo de calculo de Determinante
{
	int icol = 0; 
	int col = Mat.size()-1;
	int fcol = col-1;
	
	int irow = 1;
	int row = Mat.size();
	int frow = row;
	
	double mult;
	
	vector<double> piv(row);
	vector<double> fcero(row);
	vector<vector<double> > result((row),vector<double>(row));
	
	//Iniciamos Ciclo, para metodo de Gauss
	
	
	while(icol <= fcol)
	{
		
		/*cout<<"\n";
		cout<<"\n";
		cout<<"\n";
		cout<<"\n";
		cout<<"Iteracion-----------------------------"<<icol<<"--------------------------------------------"<<endl;
		cout<<"\n";
		cout<<"\n";
		cout<<"\n";
		cout<<"\n";*/
		
		
		irow = irow + icol;
		
		
		
		while(irow < frow)
		{
			
			//cout<<"\nPivote"<<icol<<endl;
			for	(int i = 0 ; i < row; i++)
			{
				piv[i] = Mat[icol][i];
				//cout<<"\t"<<Mat[icol][i];
			}
			
			
			//cout<<"\nFila Para Convertir"<<icol+1<<endl;
			for	(int i = 0 ; i < row; i++)
			{
				fcero[i] = Mat[irow][i];
				//cout<<"\t"<<Mat[irow][i];
			}
			
			
			mult = (-1) * (fcero[icol] / piv[icol]);
			
			//cout<<"Multiplicador: \t"<<mult<<endl;
			double aux = 0;
			for (int i = 0; i < row; i++)
			{
				aux = (piv[i] * mult) + fcero[i];
				fcero[i] = aux;
			}
			
			/*cout<<"\nFila Convertida"<<icol+1<<endl;
			for	(int i = 0 ; i < row; i++)
			{
				cout<<"\t"<<fcero[i];
			}
			cout<<"\n";*/
			
			for (int i = 0; i < row; i++)
			{
				Mat[irow][i] = fcero[i];
			}
			irow++;
		}
		
		irow = 1;
		icol++;
	}
	
	
	//Imprimimos la matriz tras Aplicar Metodo de Gauss
	
	cout<<"Resultado tras aplicar Gauss";
	cout<<"\n\n\n";
	for(int i = 0; i < Mat.size(); i++)
	{
		for(int j = 0; j < Mat.size(); j++)
		{
			cout<<Mat[i][j];
			cout<<"\t";
		}	
		cout<<"\n";
	}
	
	//calculamos el determinante 
	
	double detMat = Mat[0][0];
	
	for(int i = 1; i < row; i ++)
	{
		detMat = detMat * Mat[i][i];
	}
	
	cout<<"\n\n\n";
	cout<<"El determinante de la matriz es: \t"<<detMat;
	
	
	
	
}


