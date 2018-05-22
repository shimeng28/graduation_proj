/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CircleFiting
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CircleFiting)
    {
        if (CircleFiting->objectName().isEmpty())
            CircleFiting->setObjectName(QStringLiteral("CircleFiting"));
        CircleFiting->resize(400, 300);
        menuBar = new QMenuBar(CircleFiting);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        CircleFiting->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CircleFiting);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CircleFiting->addToolBar(mainToolBar);
        centralWidget = new QWidget(CircleFiting);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CircleFiting->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CircleFiting);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CircleFiting->setStatusBar(statusBar);

        retranslateUi(CircleFiting);

        QMetaObject::connectSlotsByName(CircleFiting);
    } // setupUi

    void retranslateUi(QMainWindow *CircleFiting)
    {
        CircleFiting->setWindowTitle(QApplication::translate("CircleFiting", "CircleFiting", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CircleFiting: public Ui_CircleFiting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
