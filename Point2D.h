#include <math.h>
#include <vector.h>
#include <cstdlib>
#include <cmath>

class Point2D
{
    private:
    float x;
    float y;

    public:
    Point2D(float x,float y)
    {
        setX(x);
        setY(y);
    }

    Point2D()
    {
        x=0;
        y=0;
    }

    float getX()
    {
        return x;
    }

    float getY()
    {
        return y;
    }

    void  setX(float X)
    {
        x=X;
    }

    void setY(float Y)
    {
        y=Y;
    }

    Point2D sub(Point2D p)
    {
        p.setX(x-p.getX());
        p.setY(y-p.getY());

        return p;
    }

    Point2D add(Point2D p)
    {
        p.setX(x+p.getX());
        p.setY(y+p.getY());

        return p;
    }

    Point2D mul(float val)
    {
        Point2D p;
        p.setX(x*val);
        p.setY(y*val);

        return p;
    }

};
