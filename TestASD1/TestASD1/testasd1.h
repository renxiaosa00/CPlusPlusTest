#ifndef TESTASD1_H
#define TESTASD1_H

#include <QtWidgets/QDialog>
#include "ui_testasd1.h"

class TestASD1 : public QDialog
{
	Q_OBJECT

public:
	TestASD1(QWidget *parent = 0);
	~TestASD1();

private:
	Ui::TestASD1Class ui;
};

#endif // TESTASD1_H
