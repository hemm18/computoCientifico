// METODO LU.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	int n,m,i,j,k;                                       // ALTA DE VARIABLES TIPO ENTERAS .
	float a[35][36],b[35][36],apoyo;                     // ALTA DE VARIABLES TIPO FLOTANTE
	do {                                                 // INICIO DE CICLO DO PARA LA EJECUCION DEL PROGRAMA
		system("cls");                                       // SYSTEM CLS COMANDO UTILIZADO PARA LIMPIAR PANTALLAS ANTERIORES DEL SISTEMA
		cout<<"\nMETODO DE LU"<<endl;              // ENCABEZADO DE PROGRAMA
		cout<<"\nIngrese el numero de Ecuaciones = ";        // INGRESO DE VALOR DE n POR USUARIO EL CUAL ES EL NUMERO DE ECUACIONES A RESOLVER EN NUESTRO PROGRAMA
		cin>>n;                                              // DATOS INGRESADOS POR EL USUARIO
		cout<<"\nIngrese coeficientes\n";                    // MENSAJE DE SOLICITUD DE COEFICIENTES DE LAS ECUACIONES
		/* Datos para iniciar método */
		for(i=1; i<=n; i++) {                                // INICIO DE REPETICIONES O BUCLE CON COMANDO FOR INDICANDO QUE LA VARIABLE I ES IGUAL A 1 E IRA EN AUMENTO HASTA QUE SEA MENOR O IGUAL A LA VARIABLE n(NUMERO DE ECUACIONES A RESOLVER
			cout<<"\nFila"<<i<<endl;                             // MENSAJE INDICANDO LA FILA DE LA POSICION MARCADA POR LA VARIABLE i PARA EL INGRESO DE DATOS
			for(j=1; j<=n+1; j++) {                              // INICIO DE CICLO CON LA VARIABLE J DONDE J HARA EL NUMERO DE REPETICIONES NECESARIAS HASTA LLEGAR AL VALO DE n
				// EN ESTE CICLO TE PEDIRA LOS DATOS DE LAS VARIABLES i Y j EPITIENDOCE ESTE CICLO HASTA HABER LLEGADO HASTA EL VALOR n
				cout<<"Ingrese a("<<i<<","<<j<<") = ";               // PETICION DE VALORES DE iY j (ESTE SE EJECUTARA DEPENDIENDO DEL VALOR N QUE NOSOTROS HAYAMOS ASIGNADO INICIANDO 1-1,1-2,1-3,2-1,2-2,2-3 SEGUN NUESTRA ECUACION
				cin>>a[i][j];                                        // INGRESO DE VALORES i Y j
			}
		}
		/* Fin Del Ciclo De Solicitud De Datos */
		/* Proceso Principal */                              // INICIO DE RESOLUCION DEL LA ECUACION
		m=n+1;                                               // ASIGNACION DEL VALOR A LA VARIABLE M EL CUAL SERA ELVALOR n(NUMERO DE ECUACIONES)
		do {                                                 // INICIO DE CICLO DO PARA RESOLUCION DE ECUACIONES
			if(a[1][1]==0) {                                     // SI LA VARIABLE a 1,1 ES IGUAL A 0 SE PROCEDERA A A DAR EL VALOR DE K=M-1 E INICIAR UN CONTADOR INDICANDO QUE LA VARIABLE i SERA IGUAL A 2 Y
				k=m-1;                                               // ESTE HARA UN CICLO HASTA QUE i SEA MENOR O IGUAL A LA VARIABLE k PERO SI A CON LA VARIABLE i 1 ES DISTINTA A 0 SE INICIARA
				for(i=2; i<=k; i++) {                                // SE INICIARA EL CICLO DONDE j TENDRA UN VALOR DE INICIO DE 1 Y SE CICLARA HASTA QUE SEA MENOR O IGUAL A LA VARIABLE m LA CUAL ES EL RESULTADO DE n+1
					if(a[i][1]!=0) {                                     // ASI TAMBIEN SE LE ASIGNARA A LA VARIABLE APOYO EN LA POSICION i EL VALOR DE 1 Y j QUEDANDO INTACTO  ESTO CON LA FINALIDAD DE PODER HACER LA RESOLUCION DE LA
						// ECUACION YA QUE EN EL DESARROLLO SI DEJAMOS ESTOS VALORES EN LA FORMULA DE SOLUCION SE REALIZARIAN OPERACIONES ENTRE 0 PO LO CUAL NOS DARIA ERROR EN NUESTRO
						for(j=1; j<=m; j++) {
							// RESULTADO.
							apoyo=a[i][j];
							a[i][j]=a[1][j];
							a[1][j]=apoyo;
						}
					}
				}
			} else {                                            //EN CASO CONTRARIO A J SE LE ASIGNARA EL VALOR DE 3 Y ESTE SE CICLARA HASTA QUE SEA j MENOR O IGUAL A m CON UN CONTADOR
				for(j=2; j<=m; j++) {
					for(i=2; i<=n; i++) {                               // SE INICIA UN CONTADOR PARA LA VARIABLE i DONDE i TENDRA UN VALOR DE 2 Y SE CICLARA HASTA QUE SEA MENOR O IGUAL A n
						b[i-1][j-1]=a[i][j]-a[1][j]*a[i][1]/a[1][1];        // APLICACION DE LA FORMULA PARA LA RESOLUCION DE LA ECUACION DONDE i-1,J-1 ES IGUAL A a(ij) - A1j*a(i1) ENTRE 1,1
					}
				}
				for(j=2; j<=m; j++) {                               // SE INICIA OTRO CICLO FOR DONDE SI j TIENE UN VALOR =2 SE INICIA EL CICLO EN (aij)HASTA QUE SEA MENOR O IGUAL A M
					b[n][j-1]=a[1][j]/a[1][1];                          //
				}
				m=m-1;
				for(j=1; j<=m; j++) {
					for(i=1; i<=n; i++) {
						a[i][j]=b[i][j];
					}
				}
			}
		} while(m>1);                                     // MIENTRAS LA VARIABLE M SEA MAYOR A 1
		cout<<"\n\nSOLUCION DEL SISTEMA"<<endl;   // IMPRIME EN PANTALLA SOLUCION DEL SISTEMA
		for(i=1; i<=n; i++) {                    // PARA CUANDO I SE INICIE EN 1, i DEVE DE SER MENOR O IGUAL A N, Y SI SE CUMPLE SE INCREMENTA i										|||||
			cout<<"\nX("<<i<<") = "<<a[i][1];
		}
		cout<<"\n\nFin del programa";     //FIN DEL PROGRAMA
		getch();
	} while(1);
}
