#include "Point2D.h"
#include <vector.h>

class edge2D
{
  private:
  Point2D p1;
  Point2D p2;

  public:

    edge2D(Point2D P1,Point2D P2)
    {
        p1=P1;
        p2=P2;
    }

    edge2D()
    {

    }

  Point2D getPoint(int i)
  {
    if(i == 1)
        return p1;
    else
        return p2;
  }

   //return the farthest point from edge
  Point2D getMax(vector<Point2D> points)
  {
        float max=distance(points[0]);
        int index=0;

        for(int i=1;i<points.size();i++)
        {
            float temp=distance(points[i]);
            if(temp > max)
            {
                max= temp;
                index=i;
            }

        }

        return points[index];
   }

    //distance of edge and point
    float distance(Point2D p)
    {
        const float length=distance(p1,p2);
        if (length == 0.0)
            return distance(p1, p);

        const float t = dot(p.sub(p1), p2.sub(p1)) / length;
        if (t < 0.0)
            return distance(p, p1);
        else if (t > 1.0)
            return distance(p, p2);

        const Point2D projection = p1.add(p2.sub(p1).mul(t));  // Projection falls on the segment
        return distance(p, projection);
    }

    //distance between two points
    float distance(Point2D x, Point2D y)
    {
        return sqrt(pow((x.getX()-y.getX()),2)+pow((x.getY()-y.getY()),2));
    }

    //dot product of two vectors
    float dot(Point2D x ,Point2D y)
    {
        return (x.getX()*y.getX()) + (x.getY()*y.getY());
    }

};
