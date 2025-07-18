#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimerEvent>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void timerEvent(QTimerEvent *event) override;
  
  void tcpConnect();
public slots:
    void putData();
    void updateMax();
    void updateMin();
    void updateTimer();
private slots:
    void IPConnect();

    void stopButton_clicked();

    void connectButton_clicked();

    void startButton_clicked();

    void disconnectButton_clicked();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int timerId;
  int intervaloTimer;
  int min, max;
  QString ip_servidor;
};

#endif // MAINWINDOW_H
