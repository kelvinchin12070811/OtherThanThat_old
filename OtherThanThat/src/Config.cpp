#include <qapplication.h>
#include <qdesktopwidget.h>
#include "Config.hpp"

Config & Config::getInstance()
{
	static Config instance;
	return instance;
}

float Config::getZoomFactor()
{
	return zoomFactor;
}

Config::Config()
{
	zoomFactor = static_cast<float>(QApplication::desktop()->logicalDpiX()) / 96.0f;
}

Config::~Config()
{
}
