#include <QtWidgets/QApplication>
#include <qcoreapplication.h>
#include "OtherThanThat.hpp"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::ApplicationAttribute::AA_EnableHighDpiScaling);
	
	QApplication a(argc, argv);
	OtherThanThat w(QUrl("https://accounts.google.com/signin/v2/identifier?service=wise&passive=true&continue=http%3A%2F%2Fdrive.google.com%2F%3Futm_source%3Den_US&utm_medium=button&utm_campaign=web&utm_content=gotodrive&usp=gtd&ltmpl=drive&flowName=GlifWebSignIn&flowEntry=ServiceLogin"));
	w.show();
	return a.exec();
}
