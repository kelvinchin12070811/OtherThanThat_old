#include <qmessagebox.h>
#include <qaction.h>
#include <qfile.h>
#include "OtherThanThat.hpp"
#include "Config.hpp"

OtherThanThat::OtherThanThat(const QUrl& url, bool mainWindow, QWidget *parent)
	: QMainWindow(parent), url(url), mainWindow(mainWindow)
{
	this->setWindowTitle("OtherThanThat - Unofficial Google Drive Client");
	setupUI();
	connectSignals();
	setupShortcuts();
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
	//Pre-init
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

	//Create GUI elements
	content = new WebPageViewer(this);

	//Create shortcuts
	helpShortcut = new QShortcut(this);
	helpShortcut2 = new QShortcut(this);
	zoomInSc = new QShortcut(this);
	zoomOutSc = new QShortcut(this);
	resetZoomSc = new QShortcut(this);
	refreshSc = new QShortcut(this);

	//GUI initializing
	content->load(url);
	
	//Layout initializing
	this->setCentralWidget(content);
}

void OtherThanThat::connectSignals()
{
	//Gui elements
	connect(content, &QWebEngineView::titleChanged, this, &OtherThanThat::on_titleChanger);
	
	//Shortcuts
	connect(helpShortcut, &QShortcut::activated, this, &OtherThanThat::on_helpActionTriggered);
	connect(helpShortcut2, &QShortcut::activated, [&]() {
		QMessageBox::about(this, "OtherThanThat, an unofficial Google Drive Client By Kelvin Chin",
			"<h1>OtherThanThat v1.0</h1>\n\nOtherThanThat is an unofficial Google Drive client by Kelvin Chin");
	});
	connect(zoomInSc, &QShortcut::activated, [&]() {
		this->getViewer()->setZoomFactor(this->getViewer()->zoomFactor() + 0.01f);
	});
	connect(zoomOutSc, &QShortcut::activated, [&]() {
		this->getViewer()->setZoomFactor(this->getViewer()->zoomFactor() - 0.01f);
	});
	connect(zoomOutSc, &QShortcut::activated, [&]() {
		this->getViewer()->setZoomFactor(Config::getInstance().getZoomFactor());
	});
	connect(refreshSc, &QShortcut::activated, [&]() {
		this->getViewer()->reload();
	});
}

void OtherThanThat::setupShortcuts()
{
	helpShortcut->setKey(Qt::CTRL + Qt::SHIFT + Qt::Key_F12);
	helpShortcut2->setKey(Qt::CTRL + Qt::Key_F12);
	zoomInSc->setKey(Qt::CTRL + Qt::Key_Equal);
	zoomOutSc->setKey(QKeySequence::StandardKey::ZoomOut);
	resetZoomSc->setKey(Qt::CTRL + Qt::Key_F5);
	refreshSc->setKey(QKeySequence::StandardKey::Refresh);
}

void OtherThanThat::on_helpActionTriggered()
{
	QMessageBox::aboutQt(this, "OtherThanThat, an unofficial Google Drive Client By Kelvin Chin");
}

void OtherThanThat::on_titleChanger(const QString& newTitle)
{
	this->setWindowTitle(newTitle + " on OtherThanThat");
}