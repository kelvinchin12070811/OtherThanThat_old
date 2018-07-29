#pragma once
#include <list>
#include <memory>
#include "src/OtherThanThat.hpp"

class Config
{
public:
	static Config& getInstance();
	float getZoomFactor();

public:
	std::list<std::shared_ptr<OtherThanThat>> browserWindows;
private:
	Config();
	~Config();
private:
	float zoomFactor{ 0.0f };
};

