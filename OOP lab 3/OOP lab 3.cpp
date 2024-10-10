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
            throw invalid_argument("���i�� ������� ���� ��������.");
        }
        radius = r;
    }

    void setRadius(double r)
    {
        if (r <= 0)
        {
            throw invalid_argument("���i�� ������� ���� ��������.");
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
        out << "���� � ���i����: " << k.radius << endl;
        out << "�����: " << k.getArea() << endl;
        out << "������� ����: " << k.getCircumference() << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Circle& k)
    {
        double r;
        cout << "����i�� ���i�� ����: ";
        in >> r;
        if (in.fail() || r <= 0)
        {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("���������� �������� ���i���. ���i�� ������� ���� �������� ������.");
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
        cerr << "�������: " << e.what() << endl;
    }

    return 0;
}