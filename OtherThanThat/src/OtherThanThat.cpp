#include "OtherThanThat.hpp"

OtherThanThat::OtherThanThat(QWidget *parent)
	: QMainWindow(parent)
{
	setupUI();
}

void OtherThanThat::setupUI()
{
	content = new QWebEnginePage(this);
	content->load(QUrl("drive.google.com"));

	this->setCentralWidget(content);
}
