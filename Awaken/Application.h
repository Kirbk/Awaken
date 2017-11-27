#pragma once

#include <PolyEngine\IMainGame.h>

#include "Screen_Main_Menu.h"

class Application : public PolyEngine::IMainGame
{
public:
	Application();
	~Application();

	// Inherited via IMainGame
	virtual void onInit() override;
	virtual void addScreens() override;
	virtual void onExit() override;

private:
	std::unique_ptr<Screen_Main_Menu> m_mainMenuScreen = nullptr;
};

