#include "edge2D.h"

class QHull
{
    private:
    //Random points
    vector<Point2D> pointCloud;
    //Final boundary Point
    vector<Point2D> drawablePoints;

    public:
    void initialize();
    vector<Point2D> getPointCloud();
    vector<Point2D> getDrawablePoints();
    void generatePointCloud(int limit);
    void generateHull(edge2D);
    float sign(Point2D p1, Point2D p2, Point2D p3);
    bool pointInTriangle(Point2D v1, Point2D v2, Point2D v3,Point2D pt);
    void removePoints(edge2D e,Point2D p);
    bool isLeft(edge2D e, Point2D p);
};
