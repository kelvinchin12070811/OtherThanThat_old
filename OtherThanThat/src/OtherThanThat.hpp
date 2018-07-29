#pragma once

#include <QtWidgets/QMainWindow>
#include "webpage_viewer/WebPageViewer.hpp"

class OtherThanThat : public QMainWindow
{
	Q_OBJECT

public:
	OtherThanThat(const QUrl& url, bool mainWindow = false, QWidget *parent = Q_NULLPTR);
	QWebEngineView* getViewer();
protected:
	void closeEvent(QCloseEvent* closeEv) override;
private:
	void setupUI();
	void connectSignals();
private slots:
	void on_titleChanger(const QString& newTitle);
private:
	WebPageViewer * content{ nullptr };
	QUrl url;
	bool mainWindow{ false };
};
