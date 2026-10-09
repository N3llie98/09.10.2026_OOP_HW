#include<iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        cout << "Construct\n";
        x = y = 0;
    }
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void Output()
    {
        cout << "X: " << x << "\tY: " << y << endl;
    }
    void SetX(int a) { x = a; }
    void SetY(int a) { y = a; }
    int GetX() { return x; }
    int GetY() { return y; }

    Point operator+(Point& obj2) // obj+obj1
    {
        Point rez(this->x + obj2.x, this->y + obj2.y);
        return rez;
    }
    Point operator+(int a) // obj+int
    {
        Point s(x + a, y + a);
        //s.x = x + a;
        //s.y = y + a;
        return s;
    }

    Point& operator++() // ++a
    {
        x += 10;
        y += 10;
        return *this;
    }
    Point operator++(int) // a++
    {
        Point res = *this;
        x += 10;
        y += 10;
        return res;
    }
    Point& operator--() // --a
    {
        x -= 10;
        y -= 10;
        return *this;
    }
    Point operator--(int) // a--
    {
        Point res = *this;
        x -= 10;
        y -= 10;
        return res;
    }

    bool operator>(Point& obj2)
    {
        if (x > obj2.x && y > obj2.y) {
            return true;
        }
        return false;
    }
    bool operator<(Point& obj2)
    {
        if (x < obj2.x && y < obj2.y) {
            return true;
        }
        return false;
    }
    bool operator>=(Point& obj2)
    {
        if (x >= obj2.x && y >= obj2.y) {
            return true;
        }
        return false;
    }
    bool operator<=(Point& obj2)
    {
        if (x <= obj2.x && y <= obj2.y) {
            return true;
        }
        return false;
    }

    Point& operator+=(int a)
    {
        x += a;
        y += a;
        return *this;
    }
    Point& operator-=(int a)
    {
        x -= a;
        y -= a;
        return *this;
    }
    Point& operator*=(int a)
    {
        x *= a;
        y *= a;
        return *this;
    }
    Point& operator/=(int a)
    {
        x /= a;
        y /= a;
        return *this;
    }
};


int main()
{
    Point obj1(10, 20);
    Point obj2(1, 2);

    Point sum = obj1 + obj2;
    // sum = obj1.operator+(obj2);
    sum = obj1 + 5;
    sum.Output();

    cout << endl;

    obj1.Output();
    (++obj1).Output();
    obj1.Output();

    cout << endl;

    obj2.Output();
    (obj2++).Output();
    obj2.Output();

    cout << endl;

    // >
    if (obj1 > obj2) {
        cout << "yes\n"; // yes
    }
    else {
        cout << "no\n";
    }
    // <
    if (obj1 < obj2) {
        cout << "yes\n";
    }
    else {
        cout << "no\n"; // no
    }
    // >=
    if (obj1 >= obj2) {
        cout << "yes\n"; // yes
    }
    else {
        cout << "no\n";
    }
    // <=
    if (obj1 <= obj2) {
        cout << "yes\n";
    }
    else {
        cout << "no\n"; // no
    }

    cout << endl;

    obj1.Output();
    obj1 += 5;
    obj1.Output();

    cout << endl;

    obj1.Output();
    obj1 -= 5;
    obj1.Output();

    cout << endl;

    obj1.Output();
    obj1 *= 5;
    obj1.Output();

    cout << endl;

    obj1.Output();
    obj1 /= 5;
    obj1.Output();
}