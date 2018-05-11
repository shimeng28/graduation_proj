#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QtOpenGL>
#include <QMouseEvent>
#include <QKeyEvent>

class OpenglWidget : public QGLWidget
{
public:
  OpenglWidget(QWidget* parent = 0);

protected:
  bool fullScreen;
  GLfloat angle;

  void getScreenInfo();

  void initializeGL();
  void initWidget();
  void paintGL();
  void resizeGL(int width, int height);

  void mousePressEvent(QMouseEvent *event);
  void mouseEventHandle();

  void keyPressEvent(QKeyEvent *event);
};

#endif // OPENGLWIDGET_H
