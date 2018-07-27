#pragma once

#include <QtWidgets/QMainWindow>
#include <qwebenginepage.h>

class OtherThanThat : public QMainWindow
{
	Q_OBJECT

public:
	OtherThanThat(QWidget *parent = Q_NULLPTR);
	
private:
	void setupUI();
private:
	QWebEnginePage * content{ nullptr };
};
