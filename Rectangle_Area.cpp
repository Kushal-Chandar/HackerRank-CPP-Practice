#include <iostream>

using namespace std;
/*
 Create classes Rectangle and RectangleArea
 */
class Rectangle
{
protected:
    int height;
    int width;

public:
    void display();
};

class RectangleArea : public Rectangle
{
public:
    void read_input();
    void display();
};

//Definition of Class Rectangle
void Rectangle::display()
{
    cout << width << ' ' << height << '\n';
}

//Definition of Class RectangleArea
void RectangleArea::read_input()
{
    cin >> width >> height;
}

void RectangleArea::display()
{
    cout << height * width;
}

int main()
{
    /*
     Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     Read the width and height
     */
    r_area.read_input();

    /*
     Print the width and height
     */
    r_area.Rectangle::display();

    /*
     Print the area
     */
    r_area.display();

    return 0;
}