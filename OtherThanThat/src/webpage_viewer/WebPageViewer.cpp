#include <memory>
#include <thread>
#include "WebPageViewer.hpp"
#include "src/Config.hpp"
#include "src/OtherThanThat.hpp"

WebPageViewer::WebPageViewer(QWidget* parrent):
	QWebEngineView(parrent)
{
	this->setZoomFactor(Config::getInstance().getZoomFactor());
	connectSignals();
}


WebPageViewer::~WebPageViewer()
{
}

QWebEngineView * WebPageViewer::createWindow(QWebEnginePage::WebWindowType type)
{
	OtherThanThat* newWindow = new OtherThanThat(QUrl("about:blank"));
	newWindow->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
	newWindow->show();
	return newWindow->getViewer();
}

void WebPageViewer::connectSignals()
{
	connect(this, &WebPageViewer::urlChanged, this, &WebPageViewer::on_zoomFactorChecker);
}

void WebPageViewer::on_zoomFactorChecker()
{
	auto factor = Config::getInstance().getZoomFactor();
	if (this->zoomFactor() != factor)
		this->setZoomFactor(factor);
}