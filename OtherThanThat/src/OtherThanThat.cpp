#include <qmessagebox.h>
#include <qaction.h>
#include <qfile.h>
#include "OtherThanThat.hpp"
#include "Config.hpp"

OtherThanThat::OtherThanThat(const QUrl& url, bool mainWindow, QWidget *parent)
	: QMainWindow(parent), url(url), mainWindow(mainWindow)
{
	setupUI();
	connectSignals();
}

QWebEngineView * OtherThanThat::getViewer()
{
	return content;
}

void OtherThanThat::closeEvent(QCloseEvent * closeEv)
{
	if (!mainWindow) return;

	QFile windowGeo("win_geo.dat");
	if (windowGeo.open(QIODevice::WriteOnly))
	{
		windowGeo.write(this->saveGeometry());
	}
	windowGeo.close();
}

void OtherThanThat::setupUI()
{
	QSize windowSize(0, 0);
	windowSize.setWidth(800 * Config::getInstance().getZoomFactor());
	windowSize.setHeight(600 * Config::getInstance().getZoomFactor());
	this->setMinimumSize(windowSize);

	if (mainWindow)
	{
		QFile winGeo("win_geo.dat");
		if (winGeo.open(QIODevice::ReadOnly))
		{
			this->restoreGeometry(winGeo.readAll());
		}
		winGeo.close();
	}

	content = new WebPageViewer(this);
	content->load(url);
	
	this->setCentralWidget(content);
}

void OtherThanThat::connectSignals()
{
	connect(content, &QWebEngineView::titleChanged, this, &OtherThanThat::on_titleChanger);
}

void OtherThanThat::on_titleChanger(const QString& newTitle)
{
	this->setWindowTitle(newTitle + " on Other Than That");
}