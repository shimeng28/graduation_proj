#include "paintcircle.h"
#include <QRect>
PaintCircle::PaintCircle(QWidget* parent)
    :QGLWidget(parent)
{
  fullScreen = false;
  angle = 0.0;
  initWidget();
  initializeGL();
}

void PaintCircle::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void PaintCircle::initWidget()
{
    setGeometry( 0, 0, 200, 280 );
    setWindowTitle(tr("opengl circle demo"));
}

void PaintCircle::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef( -1.5,  0.0, -6.0 );
    glRotatef( angle,  1.0,  1.0,  0.0 );

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f);
    for (int i = 0; i <= 390; i += 15)
    {
        float p = i * 3.14 / 180;
        glVertex3f(sin(p), cos(p), 0.0f);
    }
    glEnd();
}

void PaintCircle::resizeGL(int width, int height)
{
    if(0 == height) {
        height = 1;
    }

    glViewport(0, 0, (GLint)width, (GLint)height);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

  //  gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);

    GLdouble aspectRatio = (GLfloat)width/(GLfloat)height;
    GLdouble zNear = 0.1;
    GLdouble zFar = 100.0;

    GLdouble rFov = 45.0 * 3.14159265 / 180.0;
     glFrustum( -zNear * tan( rFov / 2.0 ) * aspectRatio,
               zNear * tan( rFov / 2.0 ) * aspectRatio,
               -zNear * tan( rFov / 2.0 ),
               zNear * tan( rFov / 2.0 ),
               zNear, zFar );

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
}


