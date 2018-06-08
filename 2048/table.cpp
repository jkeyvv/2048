#include "table.h"

Table::Table(QWidget *parent)
    : QTableWidget(parent)
{
    inittable();
}

Table::~Table()
{
}

void Table::inittable()
{
    int i,j;

    this->setRowCount(4);
    this->setColumnCount(4);
    blocknum = 0;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            matrix[i][j] = 0;
        }
    }

    dealmatrix(matrix);
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            QTableWidgetItem *newItem = this->item(i, j);
            newItem->setTextAlignment(Qt::AlignCenter);
            newItem->setBackground(Qt::gray);
            newItem->setText(QString::number(matrix[i][j]));
            setItem(i, j, newItem);
        }
    } 
    addcolor();
}


void Table::dealup()
{
    int i,j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            matrix[i][j] = item(j,i)->text().toInt();
        }
    }

    dealmatrix(matrix);

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            item(i,j)->setText(QString::number(matrix[j][i]));
        }
    }

    addcolor();
}

void Table::dealdown()
{
    int i,j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            matrix[i][j] = item(3-j, 3-i)->text().toInt();
        }
    }

    dealmatrix(matrix);

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            item(i,j)->setText(QString::number(matrix[3-j][3-i]));
        }
    }
    addcolor();
}

void Table::dealleft()
{
    int i,j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            matrix[i][j] = item(i, j)->text().toInt();
        }
    }

    dealmatrix(matrix);

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            item(i, j)->setText(QString::number(matrix[i][j]));
        }
    }
    addcolor();
}

void Table::dealright()
{
    int i,j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            matrix[i][j] = item(i, 3-j)->text().toInt();
        }
    }

    dealmatrix(matrix);

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            item(i, j)->setText(QString::number(matrix[i][3-j]));
        }
    }
    addcolor();
}

void Table::dealmatrix(int tmpmatrix[][4])
{
    int i,j,a;

    for(i=0; i<4; i++){
        dealarry(tmpmatrix[i]);
    }

    srand((int)time(0));
    a = rand() % blocknum;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(tmpmatrix[i][j] == 0){
                if(a-- == 0){
                    tmpmatrix[i][j] = 2;
                    break;
                }
            }
        }
    }
    blocknum = 0;
}

void Table::dealarry(int tmparry[4])
{
    int i,j=0;
    for(i=0; i<4; i++){
        if(tmparry[i] == 0){
            continue;
        }else if(j == 0 ){
            tmparry[j++] = tmparry[i];
            continue;
        }else if(tmparry[j-1] == tmparry[i]){
            tmparry[j-1] = tmparry[j-1]*2;
            continue;
        }else{
            tmparry[j++] = tmparry[i];
        }
    }

    while(j<4){
        tmparry[j++] = 0;
        blocknum++;
    }
}

void Table::addcolor()
{
    int i,j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            QTableWidgetItem *newitem = item(i, j);
            switch (newitem->text().toInt()) {
            case 0:
                newitem->setText("");
                newitem->setBackgroundColor(Qt::blue);
                break;
            case 2:
                newitem->setBackgroundColor(Qt::yellow);
                break;
            case 4:
                newitem->setBackgroundColor(Qt::green);
                break;
            case 8:
                newitem->setBackgroundColor(Qt::cyan);
                break;
            case 16:
                newitem->setBackgroundColor(Qt::yellow);
                break;
            case 32:
                newitem->setBackgroundColor(Qt::green);
                break;
            case 64:
                newitem->setBackgroundColor(Qt::cyan);
                break;
            case 128:
                newitem->setBackgroundColor(Qt::yellow);
                break;
            case 256:
                newitem->setBackgroundColor(Qt::green);
                break;
            case 512:
                newitem->setBackgroundColor(Qt::cyan);
                break;
            case 1024:
                newitem->setBackgroundColor(Qt::yellow);
                break;
            case 2048:
                newitem->setBackgroundColor(Qt::green);
                break;
            default:
                newitem->setBackgroundColor(Qt::cyan);
                break;
            }
            setItem(i, j, newitem);
        }
    }
}
