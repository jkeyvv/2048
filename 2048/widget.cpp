#include "widget.h"

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
}

Widget::~Widget()
{
	delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Up:
		ui->tableWidget->dealup();
		break;
	case Qt::Key_Down:
		ui->tableWidget->dealdown();
		break;
	case Qt::Key_Left:
		ui->tableWidget->dealleft();
		break;
	case Qt::Key_Right:
		ui->tableWidget->dealright();
		break;
	default:
		QWidget::keyPressEvent(event);
	}
}