#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

const double pi = (atan(1) * 4);

class Circle
{
private:
    double radius;

public:
    Circle() : radius(0) {}

    Circle(double r)
    {
        if (r <= 0)
        {
            throw invalid_argument("Радiус повинен бути додатним.");
        }
        radius = r;
    }

    void setRadius(double r)
    {
        if (r <= 0)
        {
            throw invalid_argument("Радiус повинен бути додатним.");
        }
        radius = r;
    }

    double getRadius() const
    {
        return radius;
    }

    double getArea() const
    {
        return pi * radius * radius;
    }

    double getCircumference() const
    {
        return 2 * pi * radius;
    }

    friend ostream& operator<<(ostream& out, const Circle& k)
    {
        out << "Коло з радiусом: " << k.radius << endl;
        out << "Площа: " << k.getArea() << endl;
        out << "Довжина кола: " << k.getCircumference() << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Circle& k)
    {
        double r;
        cout << "Введiть радiус кола: ";
        in >> r;
        if (in.fail() || r <= 0)
        {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Некоректне значення радiуса. Радiус повинен бути додатним числом.");
        }
        k.setRadius(r);
        return in;
    }
};

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    try
    {
        Circle circle;
        cin >> circle;
        cout << circle;
    }
    catch (const exception& e)
    {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}