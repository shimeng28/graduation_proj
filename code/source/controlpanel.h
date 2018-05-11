#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H
#include <QWidget>

class ControlPanel : public QWidget
{
Q_OBJECT
public:
    ControlPanel(QWidget *parent = 0);
    ~ControlPanel();
public slots:
    void choseFile();
};

#endif // CONTROLPANEL_H
