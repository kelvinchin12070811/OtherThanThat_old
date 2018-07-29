#pragma once
#include <qwebengineview.h>
#include <qwebenginepage.h>

class WebPageViewer : public QWebEngineView
{
public:
	WebPageViewer(QWidget* parrent = nullptr);
	~WebPageViewer();

protected:
	QWebEngineView* createWindow(QWebEnginePage::WebWindowType type) override;
};

