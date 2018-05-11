#include "controlpanel.h"
#include "openglwidget.h"
#include "paintcircle.h"
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

#include <QDoubleValidator>
#include <QRect>

#include <QDebug>
ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent){
  QWidget *headerWrap = new QWidget(this);
  QLabel *header = new QLabel("header", headerWrap);
  header->setText(QObject::tr("               圆柱度拟合"));
  header->setFixedHeight(50);

  PaintCircle *circleLeft = new PaintCircle();

  QVBoxLayout *headerLayout = new QVBoxLayout();
  headerLayout->addWidget(circleLeft);
  headerLayout->addWidget(headerWrap);

  OpenglWidget *opengl = new OpenglWidget();
  QVBoxLayout *openglLayout = new QVBoxLayout();
  openglLayout->addWidget(opengl);

  QHBoxLayout *wrapLayout = new QHBoxLayout();
  wrapLayout->addLayout(headerLayout);
  wrapLayout->addLayout(openglLayout);

  this->setLayout(wrapLayout);
}

void ControlPanel::choseFile() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("choose a file"), "./", tr("excel(*xlsx)"));
  qDebug() << "fileName: " << fileName;
}



ControlPanel::~ControlPanel(){
}
