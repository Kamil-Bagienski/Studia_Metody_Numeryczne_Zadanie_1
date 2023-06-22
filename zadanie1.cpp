// Kamil Bagieñski, grupa D1, numer indeksu 155623
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double eps = 1e-12;

bool gauss ( int n, double ** Macierz, double * X );


int main( )
{
  double **Macierz, *X;
  int      n, i, j;

  cout << setprecision ( 1 ) << fixed;
cout << "Obliczenie ukladow rownan liniowych metoda dokladna za pomoca eliminacji Gaussa\n";

  cout << "Podaj ile stopni ma miec uklad rownan:";

  cin >> n;


  Macierz = new double * [ n ];
  X  = new double [ n ];

  for( i = 0; i < n; i++ ) Macierz [ i ] = new double [ n + 1 ];


  for( i = 0; i < n; i++ )
    {
        cout<< "STOPIEN "<<i+1<<" UKLADU ROWNAN "<<endl;
    for( j = 0; j <= n; j++ )

    {
        if (j<n)
        {
        cout<< "Podaj A" << j+1<<"=";
        }
        else if (j=n)
        {
        cout<< "Podaj b" << i+1<<"=";
        }
        cin >> Macierz [ i ][ j ];
        }
cout << endl;
    }



  if( gauss ( n, Macierz, X ) )
  {
    for( i = 0; i < n; i++ )
      cout << "x" << i + 1 << " = "  << X [i]<< endl;
  }
  else
    cout << "DZIELNIK ZERO\n";

  for( i = 0; i < n; i++ ) delete [ ] Macierz [i];
  delete [ ] Macierz;
  delete [ ] X;

  return 0;
}
bool gauss ( int n, double ** Macierz, double * X )
{

  int i, j, k;
  double m, s;



  for( i = 0; i < n - 1; i++ )
  {
    for( j = i + 1; j < n; j++ )
    {
      if( fabs ( Macierz [ i ][ i ] ) < eps ) return false;
      m = -Macierz [ j ][ i ] / Macierz [ i ][ i ];
      for( k = i + 1; k <= n; k++ )
        Macierz [ j ][ k ] += m * Macierz [ i ][ k ];
    }
  }



  for( i = n - 1; i >= 0; i-- )
  {
    s = Macierz [ i ][ n ];
    for( j = n - 1; j >= i + 1; j-- )
      s -= Macierz [ i ][ j ] * X [ j ];
    if( fabs ( Macierz [ i ][ i ] ) < eps ) return false;
    X [ i ] = s / Macierz [ i ][ i ];
  }
  return true;
}
