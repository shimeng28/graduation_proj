#include "mainwindow.h"
#include "controlpanel.h"
#include <QApplication>
#include <QKeySequence>
#include <QAction>
#include <QMenu>
#include <QLabel>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QToolBar>
#include <QCloseEvent>
#include <QString>
#include <QFile>
#include <QStringList>
#include <QFileInfo>
#include <QMutableStringListIterator>
MainWindow::MainWindow()
{
  ControlPanel *panel = new ControlPanel();
  setCentralWidget(panel);
  createActions();
  createMenus();
  createToolBar();
  createStatusBar();

  setWindowIcon(QIcon(""));
  setCurrentFile("");
}
bool MainWindow::okToContinue()
{
  if(isWindowModified()){
    int r = QMessageBox::warning(this, tr("Data Renderer"), tr("this data has  been modified.\n Do you want to save your changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if(r == QMessageBox::Yes){
      return save();
    }
    else if(r == QMessageBox::Cancel) {
      return false;
    }
  }
  return true;
}


void MainWindow::newFile()
{
  if(okToContinue()){
    setCurrentFile("");
  }
}
void MainWindow::open()
{
  if(okToContinue()){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open a new data"), ".", tr("xlm  files (*.xls)"));
    if(!fileName.isEmpty())
      loadFile(fileName);
  }
}
// file load
bool MainWindow::loadFile(const QString &fileName)
{
  //TODO read data file
  if(fileName.isEmpty()){
    statusBar()->showMessage(tr("Loading canceled"), 2000);
    return false;
  }
  statusBar()->showMessage(tr("file loaded"), 2000);
  return true;
}

bool MainWindow::save()
{
  if(curFile.isEmpty()) {
    return saveAs();
  }
  else {
    return saveFile(curFile);
  }
}
bool MainWindow::saveFile(const QString &fileName)
{
  //TODO call saveFile function
  if(fileName.isEmpty()){
    statusBar()->showMessage(tr("Saving canceled"), 2000);
    return false;
  }
  setCurrentFile(fileName);
  statusBar()->showMessage(tr("file saved"), 2000);
  return true;
}
bool MainWindow::saveAs()
{
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save Data"), ".", tr("xml files(*.xls)"));
  if(fileName.isEmpty())
    return false;
  return saveFile(fileName);
}
void MainWindow::about()
{
  QMessageBox::about(this, tr("About Data"), tr("<h2>Circle Fitting 1.1</h2>"
               "<p>Copyright &copy; 2018 Software Inc."
               "<p>Circle Fitting is a small application that "
               "demonstrates a circle based on the measurement data "));
}

void MainWindow::find()
{

}

void MainWindow::createActions()
{
  newAction = new QAction(tr("&New"), this);
  newAction->setIcon(QIcon());
  newAction->setShortcut(QKeySequence::New);
  newAction->setStatusTip(tr("Create a new data demo"));
  connect(newAction, SIGNAL(triggered(bool)), this, SLOT(newFile()));

  openAction = new QAction(tr("&Open..."), this);
  openAction->setIcon(QIcon(""));
  openAction->setShortcut(QKeySequence::Open);
  openAction->setStatusTip(tr("Open an existing spreadsheet file"));
  connect(openAction, SIGNAL(triggered(bool)), this, SLOT(open()));

  saveAction = new QAction(tr("&Save"), this);
  saveAction->setIcon(QIcon(""));
  saveAction->setShortcut(QKeySequence::Save);
  connect(saveAction, SIGNAL(triggered(bool)), this, SLOT(save()));

  saveAsAction = new QAction(tr("Save &As..."), this);
  saveAsAction->setStatusTip(tr("Save the data under a new name"));
  connect(saveAsAction, SIGNAL(triggered(bool)), this, SLOT(saveAs()));

  for(int i = 0; i < MaxRecentFiles; ++i) {
    recentFileActions[i] = new QAction(this);
    recentFileActions[i]->setVisible(false);
    connect(recentFileActions[i], SIGNAL(triggered(bool)), this, SLOT(openRecentFile()));
  }

  exitAction = new QAction(tr("E&xit"), this);
  exitAction->setShortcut(tr("Ctrl+Q"));
  exitAction->setStatusTip("Exit the application");
  connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
// TODO
//  cutAction = new QAction(tr("Cu&t"), this);
//  cutAction->setIcon(QIcon(""));
//  cutAction->setShortcut(QKeySequence::Cut);
//  cutAction->setStatusTip(tr("Cut the current selection's contents to the clipboard"));
//  connect(cutAction, SIGNAL(triggered(bool)), this, );

//    pasteAction = new QAction(tr("&Paste"), this);
//    pasteAction->setIcon(QIcon(":/images/paste.png"));
//    pasteAction->setShortcut(QKeySequence::Paste);
//    pasteAction->setStatusTip(tr("Paste the clipboard's contents into the current selection"));
//    connect(pasteAction, SIGNAL(triggered()), spreadsheet, SLOT(paste()));

//    deleteAction = new QAction(tr("&Delete"), this);
//    deleteAction->setShortcut(QKeySequence::Delete);
//    deleteAction->setStatusTip(tr("Delete the current selection's contents"));
//    connect(deleteAction, SIGNAL(triggered()), spreadsheet, SLOT(del()));

  findAction = new QAction("&Find...", this);
  findAction->setIcon(QIcon());
  findAction->setShortcut(QKeySequence::Find);
  findAction->setStatusTip(tr("Find a matching cell"));
  connect(findAction, SIGNAL(triggered(bool)), this, SLOT(find()));

  aboutAction = new QAction(tr("&About"), this);
  aboutAction->setStatusTip(tr("Show the application's About box"));
  connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(about()));

  aboutQtAction = new QAction(tr("About &Qt"), this);
  aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
  connect(aboutQtAction, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
  fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(newAction);
  fileMenu->addAction(openAction);
  fileMenu->addAction(saveAction);
  fileMenu->addAction(saveAsAction);
  separatorAction = fileMenu->addSeparator();
  for(int i = 0; i < MaxRecentFiles; ++i) {
    fileMenu->addAction(recentFileActions[i]);
  }
  fileMenu->addSeparator();
  fileMenu->addAction(exitAction);

//  editMenu = menuBar()->addMenu(tr("&Edit"));
//  editMenu->addAction(cutAction);
//  editMenu->addAction(copyAction);
//  editMenu->addAction(pasteAction);
//  editMenu->addAction(deleteAction);

  menuBar()->addSeparator();

  helpMenu = menuBar()->addMenu("&Help");
  helpMenu->addAction(aboutAction);
  helpMenu->addAction(aboutQtAction);
}

// ToDo mouse click in the widget
//void MainWindow::createContextMenu()
//{
//}

void MainWindow::createToolBar()
{
  fileToolBar = addToolBar(tr("&File"));
  fileToolBar->addAction(newAction);
  fileToolBar->addAction(openAction);
  fileToolBar->addAction(saveAction);
  fileToolBar->addAction(aboutAction);
  fileToolBar->addAction(aboutQtAction);
  editToolBar = addToolBar(tr("&Edit"));
  editToolBar->addAction(findAction);
  fileToolBar->addAction(exitAction);
}
void MainWindow::createStatusBar()
{
  locationLabel = new QLabel("data is detecting");
  locationLabel->setAlignment(Qt::AlignHCenter);
  locationLabel->setMinimumSize(locationLabel->sizeHint());

  formulaLabel = new QLabel();
  formulaLabel->setIndent(3);

  statusBar()->addWidget(locationLabel);
  statusBar()->addWidget(formulaLabel, 1);

//Todo event emit when status is changing
//  connect(widget, , this, SLOT(updateStatusBar()));
}
void MainWindow::updateStatusBar(){

}

void MainWindow::closeEvent(QCloseEvent *event)
{
  if(okToContinue()){
    event->accept();
  }
  else {
    event->ignore();
  }
}
void MainWindow::setCurrentFile(const QString &fileName)
{
  curFile = fileName;
  setWindowModified(false);
  QString shownName = tr("圆柱度拟合");
  if(!curFile.isEmpty()) {
    shownName = strippedName(curFile);
    recentFiles.removeAll(curFile);
    recentFiles.prepend(curFile);
    updateRecentFileActions();
  }
  setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("郑州大学机械工程学院")));
}

QString MainWindow::strippedName(const QString &fullFileName)
{
  return QFileInfo(fullFileName).fileName();
}
void MainWindow::updateRecentFileActions()
{
  QMutableStringListIterator i(recentFiles);
  while(i.hasNext()){
    if(!QFile::exists(i.next()))
      i.remove();
  }
  for(int j = 0; j < MaxRecentFiles; ++j) {
    if(j < recentFiles.count()) {
      QString text = tr("&%1 %2").arg(j + 1).arg(strippedName(recentFiles[j]));
      recentFileActions[j]->setText(text);
      recentFileActions[j]->setData(recentFiles[j]);
      recentFileActions[j]->setVisible(true);
    }
    else {
      recentFileActions[j]->setVisible(false);
    }
  }
  separatorAction->setVisible(!recentFiles.isEmpty());
}
void MainWindow::openRecentFile()
{
  if(okToContinue()){
    QAction *action = qobject_cast<QAction *>(sender());
    if(action)
      loadFile(action->data().toString());
  }
}





