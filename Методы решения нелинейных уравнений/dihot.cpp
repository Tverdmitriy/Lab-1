#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f(double x)
{
    return x - 1 / (3 + sin(3.6 * x));
}

bool dif(double a, double b)
{
    if (f(a) * f(b) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    setlocale(LC_ALL, "RU");
    double a, b, epsi, x, x0;
    cout << "Введите точность:";
    cin >> epsi;
    cout << "Введите интервал (a,b):";
    cin >> a >> b;
    if (dif(a, b) == true)
    {
        x0 = (a + b) / 2;
        cout << x0 << endl;
        if (dif(a, x0) == true)
        {
            b = x0;
        }
        else
        {
            a = x0;
        }
        x = (a + b) / 2;
        while (fabs(x - x0) > epsi)
        {
            cout << x << endl;
            x0 = x;
            if (dif(a, x0) == true)
            {
                b = x0;
            }
            else
            {
                a = x0;
            }
            x = (a + b) / 2;
        }
        cout << "Ответ = " << x << endl;
    }
    else
    {
        cout << "Нет решение на данном интервале" << endl;
    }
    return 0;

}