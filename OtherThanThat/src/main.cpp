#include "OtherThanThat.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OtherThanThat w;
	w.show();
	return a.exec();
}
