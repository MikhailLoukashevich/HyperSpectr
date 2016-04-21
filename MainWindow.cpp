#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QLabel>
#include <QString>
#include <QFileDialog>
#include "HyperCube.h"
#include "ParseAviris.h"
//#include "qcursor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    QObject::connect(m_ui->pushButton_hello, SIGNAL(clicked()), this, SLOT(OnPushButtonHelloClick()));
    // video
    // инициализируем объект полотна для графика
   // wGraphic = new QCustomPlot();
   // ui->gridLayout->addWidget(wGraphic, 1,0,1,1);
    // инициализируем вертикальную линию
   // verticalLine = new QCPCurve(wGraphic->xAxis, wGraphic->yAxis);
    // подключаем
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::OnPushButtonHelloClick()
{
//   HyperCube cube;
//    cube.SetWavelength(365.7584);
//    cube.SetWavelength(375.7584);

//    m_ui->label_hello->setText(QString::number(cube.GetListOfWavelength().at(0)));

    //QLabel* label = new QLabel(this);
    //label->setGeometry(0, 0, 70,  70);
   //label->setText("Dynamic");
   //label->show();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", "");

    HyperCube cube;
    ParseAviris parsing;
    parsing.Parse(fileName, cube);
    m_ui->label_hello->setText(QString::number(cube.GetBands()));
}

