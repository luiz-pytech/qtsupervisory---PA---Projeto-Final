#include "plotter.h"
#include <QPainter>
#include <QPainterPath>
#include <algorithm>
#include <QMouseEvent>

Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{
    r = 173;
    g = 216;
    b = 230;
    maxPontos = 50;
}

void Plotter::receberDados(qint64 thetime, QString str)
{
    tempos.push_back(thetime);
    dados.push_back(str.toDouble());

    while (dados.size() > maxPontos)
    {
        dados.removeFirst();
        tempos.removeFirst();
    }
    update();
}

void Plotter::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QLinearGradient gradient(0, 0, 0, height());
    gradient.setColorAt(0.0, QColor(r, g, b));
    gradient.setColorAt(1.0, QColor(r, g, b).darker(150));
    painter.fillRect(rect(), gradient);

    if (dados.size() < 2) {
        return;
    }

    auto it_minmax_y = std::minmax_element(dados.constBegin(), dados.constEnd());
    double minY = *it_minmax_y.first;
    double maxY = *it_minmax_y.second;

    double paddingY = (maxY - minY) * 0.1;
    minY -= paddingY;
    maxY += paddingY;
    if (maxY == minY) {
        maxY += 1;
    }

    QPainterPath path;
    double x0 = 0;
    double y0 = height() - ((dados.first() - minY) / (maxY - minY)) * height();
    path.moveTo(x0, y0);

    for (int i = 1; i < dados.size(); ++i)
    {
        double x_coord = ((double)i / (dados.size() - 1)) * width();
        double y_coord = height() - ((dados[i] - minY) / (maxY - minY)) * height();
        path.lineTo(x_coord, y_coord);
    }

    QPen pen;
    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);
    painter.setPen(pen);

    painter.drawPath(path);
}

void Plotter::mousePressEvent(QMouseEvent *event)
{
    emit updateX(event->position().x());
    emit updateY(event->position().y());
}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    emit updateX(event->position().x());
    emit updateY(event->position().y());
}
