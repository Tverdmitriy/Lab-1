#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f(double x)
{
    return x - 1 / (3 + sin(3.6 * x));
}

double d(double x)
{
    return (18 * cos(3.6 * x)) / (5 * (pow(sin(3.6 * x), 2) + 6 * sin(3.6 * x) + 9)) + 1;
}

double g(double x)
{
    return x - (f(x) / d(x));
}

int main()
{
    setlocale(LC_ALL, "RU");
    double a, b, epsi, x, x0;
    cout << "¬ведите точность:";
    cin >> epsi;
    cout << "¬ведите интервал (a,b):";
    cin >> a >> b;
    cout << "¬ведите x0:";
    cin >> x0;
    x = g(x0);
    while (fabs(x-x0)> epsi)
    {
        x0 = x;
        cout << x << endl;
        x = g(x0);
    } 
    cout << "ќтвет = " << x << endl;
    return 0;
}