#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include<qcustomplot.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

public slots:
    void OnPushButtonHelloClick();

  //  void slotMousePress(QMouseEvent * event); // слот для нажатия мыши
  //  void slotMouseMove(QMouseEvent * event); // слот для передвижения мыши
private:
    Ui::MainWindow *m_ui;
  //  QCustomplot *wGraphic; // объявляем объект QCustomplot
  //  QCPCurve *verticalLine; // объявляем объект для вертикальной линии
   // QGPItemTrecer *tracer; // трасировщик по точкам графика
};

#endif // MAINWINDOW_H
