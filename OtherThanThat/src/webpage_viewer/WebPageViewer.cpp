#include <qmessagebox.h>
#include "WebPageViewer.hpp"

WebPageViewer::WebPageViewer(QWidget* parrent):
	QWebEngineView(parrent)
{
}


WebPageViewer::~WebPageViewer()
{
}

QWebEngineView * WebPageViewer::createWindow(QWebEnginePage::WebWindowType type)
{
	return this;
}
