#include <qdesktopwidget.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qaction.h>
#include "OtherThanThat.hpp"

OtherThanThat::OtherThanThat(const QUrl& url, QWidget *parent)
	: QMainWindow(parent), url(url)
{
	setupUI();
}

void OtherThanThat::setupUI()
{
	QSize windowSize(640, 480);
	this->setMinimumSize(windowSize);
	content = new WebPageViewer(this);
	content->load(url);
	
	this->setCentralWidget(content);
}
