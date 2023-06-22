// Kamil Bagieñski, grupa D1, numer indeksu 155623
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double eps = 1e-12;
const int iteracje = 100000000;

bool gauss(int n, double** A, double* b, double* x);


int main()
{
    double** A;
    double* b;
    double* x;
    int n;
    cout << "Obliczenie ukladow rownan liniowych metoda iteracji za pomoca eliminacji Gaussa\n";

    cout << "Podaj ile stopni ma miec uklad rownan: ";
    cin >> n;

    A = new double*[n];
    b = new double[n];
    x = new double[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
    }

    cout << "Wprowadz wspolczynniki A oraz wektor b:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "STOPIEN " << i+1 <<" UKLADU ROWNAN"<< endl;
        for (int j = 0; j < n; j++)
        {
            cout << "A" << j + 1 << "=";
            cin >> A[i][j];
        }
        cout << "b" << i + 1 << "=";
        cin >> b[i];
        cout <<endl;
    }


    if (gauss(n, A, b, x))
    {
        cout << "Rozwiazanie:\n";
        for (int i = 0; i < n; i++)
        {
            cout << "x" << i + 1 << "=" << x[i] << endl;
        }
    }
    else
    {
        cout << "Blad: Nie udalo sie znalezc rozwiazania w " << iteracje<< " iteracjach:\n";
    }


    return 0;
}
bool gauss(int n, double** A, double* b, double* x)
{
    int k = 0;
    double* x0 = new double[n];
    double sum = 0.0;
    double odchylenie = 0.0;
    for (int i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }
    while (k < iteracje)
    {
        odchylenie = 0.0;
        for (int i = 0; i < n; i++)
        {
            x0[i] = x[i];
            sum = b[i];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum -= A[i][j] * x[j];
                }
            }
            x[i] = sum / A[i][i];
            if (fabs(x[i] - x0[i]) > odchylenie)
            {
                odchylenie = fabs(x[i] - x0[i]);
            }
        }
        if (odchylenie < eps)
        {
            delete[] x0;
            return true;
        }
        k++;
    }
    delete[] x0;
    return false;
}
