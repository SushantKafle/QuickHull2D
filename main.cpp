#include "header.h"
QHull quickHull;

void Resize(int width,int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.,(GLdouble)width/(GLdouble)height,1,100);
}

void drawQHull()
{
    //Generate and obtain Points
    quickHull.generatePointCloud(100);
    vector<Point2D> pointCloud=quickHull.getPointCloud();

    glPointSize(5);

    //Red color for inside points
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    for(int i=0;i<pointCloud.size();i++)
    {
        glVertex2f(pointCloud[i].getX(),pointCloud[i].getY());
    }
    glEnd();

    //Generate and obtain boundary points
    quickHull.initialize();
    vector<Point2D> drawablePoints = quickHull.getDrawablePoints();

    //Green Color for boundary points
    glColor3f(0,1,0);
    glBegin(GL_POINTS);
    for(int i=0;i<drawablePoints.size();i++)
    {
        glVertex2f(drawablePoints[i].getX(),drawablePoints[i].getY());
    }
    glEnd();

}

void display()
{
    glLoadIdentity();
    glOrtho( 0,400,400,0,0.0f,100.0f);
    glClearColor( 1,1,1,1);
    glClearDepth( 1.0f);
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);

    //display the Quick hull process
    drawQHull();

    glutSwapBuffers();
}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(400,400);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutCreateWindow("Quick Hull 2d Implementation");
    glutDisplayFunc(display);
    glutReshapeFunc(Resize);

    glutMainLoop();
    return 0;
}

