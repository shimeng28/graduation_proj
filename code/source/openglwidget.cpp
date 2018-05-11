#include "openglwidget.h"
#include <QRect>
#include <QDebug>

OpenglWidget::OpenglWidget(QWidget* parent)
    :QGLWidget(parent)
{
    fullScreen = false;
    angle = 0.0;
    initWidget();
    initializeGL();
}

void OpenglWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void OpenglWidget::initWidget()
{
    setGeometry( 0, 0, 700, 480 );
    setWindowTitle(tr("opengl demo"));
}

void OpenglWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef( 0.2,  0.0, -6.0 );
    glRotatef( angle,  1.0,  1.0,  0.0 );

    glColor3f(1.0, 0.0, 0.0);

    glBegin( GL_QUAD_STRIP );  // GL_QUADS

    for (int i = 0; i <= 390; i += 15)
    {
        float p = i * 3.14 / 180;
        glVertex3f(sin(p), 1.0f, cos(p));
        glVertex3f(sin(p), 0.0f, cos(p));
    }
    glEnd();

    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);//扇形连续填充三角形串
    glVertex3f(0.0f, 0.0f, 0.0f);
    for (int i = 0; i <= 390; i += 15)
    {
        float p = i * 3.14 / 180;
        glVertex3f(sin(p), 0.0f, cos(p));
    }
    glEnd();

    glTranslatef(0, 1, 0);

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLE_FAN);//扇形连续填充三角形串
    glVertex3f(0.0f, 0.0f, 0.0f);
    for (int i = 0; i <= 390; i += 15)
    {
        float p = i * 3.14 / 180;
        glVertex3f(sin(p), 0.0f, cos(p));
    }
    glEnd();
}

void OpenglWidget::resizeGL(int width, int height)
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


void OpenglWidget::mousePressEvent(QMouseEvent *event) {
  if(event->button() == Qt::LeftButton) {
    mouseEventHandle();
  }
}
void OpenglWidget::mouseEventHandle() {
  angle += 5;
  if( angle > 360) {
    angle -= 360;
  }
  this->updateGL();
}


void OpenglWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {

    case Qt::Key_A:
        qDebug() << "aaa";
        fullScreen = !fullScreen;
        if(fullScreen)
          showFullScreen();
        else {
          setGeometry(50, 50, 800, 600);
          showNormal();
        }
        updateGL();
        break;
    case Qt::Key_Escape:
        close();
        break;
    default:
        qDebug() << "bbb";
        break;
    }
}
