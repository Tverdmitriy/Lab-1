#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f(double x)
{
    return x - 1 / (3 + sin(3.6 * x));
}

double fi(double x)
{
    return 1 / (3 + sin(3.6 * x));
}

double pr_fi(double x)
{
    return -(18 * cos(3.6 * x)) / (5 * (pow(sin(3.6 * x), 2) + 6 * sin(3.6 * x) + 9));
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
    if (pr_fi(a) < 1 && pr_fi(b) < 1)
    {
        x = fi(x0);
        while (fabs(x - x0) > epsi)
        {
            cout << x << endl;
            x0 = x;
            x = fi(x0);
        }
        cout << "ќтвет = " << x << endl;
    }
    else
    {
        cout << "—ходимость не верна";
    }
    return 0;

}