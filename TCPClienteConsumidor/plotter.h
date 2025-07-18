#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QMouseEvent>

class Plotter : public QWidget
{
    Q_OBJECT

public:
    explicit Plotter(QWidget *parent = nullptr);

public slots:
    void receberDados(qint64 thetime, QString str);

signals:
    // Sinais para atualizar os LCDs na MainWindow
    void updateX(int x);
    void updateY(int y);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QVector<qint64> tempos;
    QVector<double> dados;
    int maxPontos = 200;
    int r, g, b;
};

#endif // PLOTTER_H
