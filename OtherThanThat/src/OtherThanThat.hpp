#pragma once

#include <QtWidgets/QMainWindow>
#include "webpage_viewer/WebPageViewer.hpp"

class OtherThanThat : public QMainWindow
{
	Q_OBJECT

public:
	OtherThanThat(const QUrl& url, QWidget *parent = Q_NULLPTR);
	
private:
	void setupUI();
private:
	WebPageViewer * content{ nullptr };

	QUrl url;
};
