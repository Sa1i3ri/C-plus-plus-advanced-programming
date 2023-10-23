class Shape
{
private:
    /* data */
public:
    Shape(/* args */);
    ~Shape();
    virtual double getArea() = 0;
};

class Rectangle : public Shape
{
private:
    /* data */
public:
    Rectangle(/* args */);
    ~Rectangle();
    double getArea();
};

class Square : Rectangle
{
private:
    /* data */
public:
    Square(/* args */);
    ~Square();
    double getArea();
};


class Circle : Shape
{
private:
    /* data */
public:
    Circle(/* args */);
    ~Circle();
    double getArea();
};


