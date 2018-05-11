#ifndef PAINTCIRCLE_H
#define PAINTCIRCLE_H

#include <QtOpenGL>


class PaintCircle : public QGLWidget
{
public:
    PaintCircle(QWidget* parent = 0);
protected:
  bool fullScreen;
  GLfloat angle;

  void getScreenInfo();

  void initializeGL();
  void initWidget();
  void paintGL();
  void resizeGL(int width, int height);
};

#endif // PAINTCIRCLE_H
