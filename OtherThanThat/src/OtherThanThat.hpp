#pragma once
#include <qshortcut.h>
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
	void setupShortcuts();
private slots:
	void on_titleChanger(const QString& newTitle);
	void on_helpActionTriggered();
private:
	WebPageViewer * content{ nullptr };
	QUrl url;
	bool mainWindow{ false };

	QShortcut* helpShortcut{ nullptr };
	QShortcut* helpShortcut2{ nullptr };
	QShortcut* zoomInSc{ nullptr };
	QShortcut* zoomOutSc{ nullptr };
	QShortcut* resetZoomSc{ nullptr };
	QShortcut* refreshSc{ nullptr };
};
