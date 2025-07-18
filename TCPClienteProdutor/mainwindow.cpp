#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
#include <QRandomGenerator>
#include <QTimerEvent>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  min = 25;
  max = 75;
  intervaloTimer = 1000;
  timerId = 0;

  connect(ui->sliderMax, SIGNAL(valueChanged(int)), this, SLOT(updateMax()));
  connect(ui->sliderMin, SIGNAL(valueChanged(int)), this, SLOT(updateMin()));
  connect(ui->sliderTimer, SIGNAL(valueChanged(int)), this, SLOT(updateTimer()));

  connect(ui->ipconnected, SIGNAL(editingFinished()), this, SLOT(IPConnect()));

  connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(startButton_clicked()));
  connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(stopButton_clicked()));
  connect(ui->connectButton, SIGNAL(clicked(bool)), this, SLOT(connectButton_clicked()));
  connect(ui->disconnectButton, SIGNAL(clicked(bool)), this, SLOT(disconnectButton_clicked()));


}

void MainWindow::tcpConnect(){
  socket->connectToHost(ip_servidor,1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
    ui->labelStatus->setText("Connected to server.");
    ui->labelStatus->setStyleSheet("QLabel { color : green; }");
  }
  else{
    qDebug() << "Disconnected";
    ui->labelStatus->setText("Connection failed.");
    ui->labelStatus->setStyleSheet("QLabel { color : red; }");
  }
}

void MainWindow::putData()
{
    if (socket->state() == QAbstractSocket::ConnectedState) {

        qint64 msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();

        int randomValue = QRandomGenerator::global()->bounded(min, max + 1);

        QString str = QString("set %1 %2\r\n").arg(msecdate).arg(randomValue);

        socket->write(str.toUtf8());

        ui->viewDatas->insertPlainText(str);
        qDebug() << "Sent:" << str.trimmed();
    }
}

MainWindow::~MainWindow(){
  if (timerId != 0) {
    killTimer(timerId);
  }
  delete socket;
  delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timerId) {
        putData();
    }
}

void MainWindow::updateMax()
{
    max = ui->sliderMax->value();
    if (max < min) {
        min = max;
        ui->sliderMin->setValue(min);
    }
}

void MainWindow::updateMin()
{
    min = ui->sliderMin->value();

    if (min > max) {
        max = min;
        ui->sliderMax->setValue(max);
    }


}

void MainWindow::updateTimer()
{
    intervaloTimer = ui->sliderTimer->value() * 1000;
    if (timerId != 0) {
        killTimer(timerId);
        timerId = startTimer(intervaloTimer);
    }
}



void MainWindow::IPConnect()
{
    ip_servidor = ui->ipconnected->text();
}



void MainWindow::connectButton_clicked()
{
    tcpConnect();
}

void MainWindow::disconnectButton_clicked()
{
    socket->disconnectFromHost();
    ui->labelStatus->setText("Disconnected from server.");
    ui->labelStatus->setStyleSheet("QLabel { color : red; }");
}


void MainWindow::startButton_clicked()
{
    if (timerId == 0) {
        timerId = startTimer(intervaloTimer);
        ui->labelStatus->setText("Started reading data...");
        ui->labelStatus->setStyleSheet("QLabel { color : blue; }");
    }

}

void MainWindow::stopButton_clicked()
{
    if (timerId != 0) {
        killTimer(timerId);
        timerId = 0;
        ui->labelStatus->setText("Stopped reading data.");
        ui->labelStatus->setStyleSheet("QLabel { color : gray; }");
    }
}



