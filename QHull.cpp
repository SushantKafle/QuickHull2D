#include "QHull.h"

void QHull::initialize()
{
    drawablePoints.clear();
    int minIndex=0;
    int maxIndex=0;
    float minX=pointCloud[0].getX();
    float maxX=pointCloud[0].getX();

    for(int i=0;i<pointCloud.size();i++)
    {
            Point2D temp=pointCloud[i];
            if(temp.getX() > maxX)
            {
                maxIndex=i;
                maxX=temp.getX();
            }else if(temp.getX() < minX)
            {
                minIndex=i;
                minX=temp.getX();
            }
    }

    drawablePoints.push_back(pointCloud[maxIndex]);
    drawablePoints.push_back(pointCloud[minIndex]);

    generateHull(edge2D(pointCloud[maxIndex],pointCloud[minIndex]));
}

vector<Point2D> QHull::getPointCloud()
{
    return pointCloud;
}


vector<Point2D> QHull::getDrawablePoints()
{
    return drawablePoints;
}

void QHull::generatePointCloud(int limit)
{
    pointCloud.clear();

    for(int i=0;i<limit;i++)
    {
            srand (i*time(NULL));
            float randX = (rand()%350);
            float randY = (rand()%350);

            pointCloud.push_back(Point2D(randX,randY));
    }
}


void QHull::generateHull(edge2D seg)
{
    if(pointCloud.size() == 0)
        return;

    vector<Point2D> left;
    vector<Point2D> right;

    for(int i=0;i<pointCloud.size();i++)
    {
        if(isLeft(seg,pointCloud[i]))
            left.push_back(pointCloud[i]);
        else
            right.push_back(pointCloud[i]);
    }

    if(left.size() != 0)
    {
            Point2D p1 = seg.getMax(left);
            removePoints(seg,p1);
            drawablePoints.push_back(p1);

            generateHull(edge2D(p1,seg.getPoint(1)));
            generateHull(edge2D(p1,seg.getPoint(2)));
    }


    if(right.size() !=0)
    {
            Point2D p2 = seg.getMax(right);
            removePoints(seg,p2);
            drawablePoints.push_back(p2);


            generateHull(edge2D(p2,seg.getPoint(1)));
            generateHull(edge2D(p2,seg.getPoint(2)));
    }

}


float QHull::sign(Point2D p1, Point2D p2, Point2D p3)
{
  return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool QHull::pointInTriangle(Point2D v1, Point2D v2, Point2D v3,Point2D pt)
{
  bool b1, b2, b3;
  b1 = sign(pt, v1, v2) < 0.0f;
  b2 = sign(pt, v2, v3) < 0.0f;
  b3 = sign(pt, v3, v1) < 0.0f;

  return ((b1 == b2) && (b2 == b3));
}

void QHull::removePoints(edge2D e,Point2D p)
{
    vector<Point2D> temp;

        for(int i=0;i<pointCloud.size();i++)
        {
            if(!pointInTriangle(e.getPoint(1),e.getPoint(2),p,pointCloud[i]))
            {
                        temp.push_back(pointCloud[i]);
            }
        }

        pointCloud=temp;
}

bool QHull::isLeft(edge2D e, Point2D p)
{
        return ((e.getPoint(2).getX() - e.getPoint(1).getX())*(p.getY() - e.getPoint(1).getY())) >
        ((e.getPoint(2).getY() - e.getPoint(1).getY())*(p.getX() - e.getPoint(1).getX()));
}
