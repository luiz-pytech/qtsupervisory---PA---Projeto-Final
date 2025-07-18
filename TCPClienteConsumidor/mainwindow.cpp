#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);


  connect(this, SIGNAL(enviarDados(qint64, QString)), ui->widget, SLOT(receberDados(qint64, QString)));

  intervalo_timer = 1000;
  connect(ui->sliderTimer, SIGNAL(valueChanged(int)), this, SLOT(updateTimer())); // -- mudar o tempo de acordo com o slider

  connect(ui->widget,SIGNAL(updateX(int)),ui->XFeedback,SLOT(display(int)));
  connect(ui->widget,SIGNAL(updateY(int)),ui->YFeedback,SLOT(display(int)));

  connect(ui->ipconnected, SIGNAL(editingFinished()), this, SLOT(IPConnect()));

  connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(startButton_clicked()));
  connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(stopButton_clicked()));
  connect(ui->connectButton, SIGNAL(clicked(bool)), this, SLOT(connectButton_clicked()));
  connect(ui->disconnectButton, SIGNAL(clicked(bool)), this, SLOT(disconnectButton_clicked()));

}
MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}

void MainWindow::tcpConnect(){
  socket->connectToHost(ip_servidor, 1234);
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

void MainWindow::getData(){
    QString str;
    QStringList list;
    qint64 thetime;
    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            socket->write("get 127.0.0.1 1\r\n");
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");
                if(list.size() == 2){
                    bool ok;
                    str = list.at(0);
                    thetime = str.toLongLong(&ok);
                    str = list.at(1);
                    qDebug() << thetime << ": " << str;
                    // Emite os dados para o Widget Plotter
                    emit enviarDados(thetime, str);
                }
            }
        }
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


void MainWindow::itemClicked(QListWidgetItem *item)
{
    Q_UNUSED(item);
    ui->ipconnected->setText(ui->listIPs->currentItem()->text());
    ip_servidor = ui->listIPs->currentItem()->text();
}


void MainWindow::updateButton_clicked()
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        if(socket->isOpen())
        {
            socket->write("list");
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable())
            {
                QString ip = socket->readLine().replace("\n","").replace("\r","");
                ui->listIPs->addItem(ip);
            }
        }
    }

}


void MainWindow::startButton_clicked()
{
    get_data_timer = startTimer(intervalo_timer);
    ui->labelStatus->setText("Started reading data...");
    ui->labelStatus->setStyleSheet("QLabel { color : blue; }");
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    getData();
    ui->labelData->setText("Reading...");
}

void MainWindow::stopButton_clicked()
{
    killTimer(get_data_timer);
    ui->labelStatus->setText("Stopped reading data.");
    ui->labelStatus->setStyleSheet("QLabel { color : gray; }");
    ui->labelData->setText("Waiting datas...");
}

void MainWindow::updateTimer()
{
    intervalo_timer = ui->sliderTimer->value() * 1000;
}


