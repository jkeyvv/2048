#pragma once

#include <QtWidgets/QWidget>
#include "ui_widget.h"
#include <QKeyEvent>

namespace Ui {
	class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

private:
	Ui::Widget *ui;

	void keyPressEvent(QKeyEvent *event);
};