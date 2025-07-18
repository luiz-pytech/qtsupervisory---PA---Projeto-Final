#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QListWidgetItem>
#include <vector>
#include <plotter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void tcpConnect();
  void timerEvent(QTimerEvent *event);
public slots:
  void getData();
  void updateTimer();

private slots:
    void IPConnect();
    void connectButton_clicked();
    void disconnectButton_clicked();
    void itemClicked(QListWidgetItem *item);
    void updateButton_clicked();
    void startButton_clicked();
    void stopButton_clicked();



signals:
    void enviarDados(qint64 thetime, QString str);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QString ip_servidor;
  int get_data_timer;
  int intervalo_timer;
};

#endif // MAINWINDOW_H
