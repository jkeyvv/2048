#pragma once

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <math.h>


class Table : public QTableWidget
{
    Q_OBJECT

public:
    Table(QWidget *parent);
    ~Table();

    void dealup();
    void dealdown();
    void dealleft();
    void dealright();

private:
    int blocknum;
    int matrix[4][4];

    void inittable();
    void dealarry(int *);
    void dealmatrix(int (*)[4]);
    void addcolor();

signals:

public slots:
};