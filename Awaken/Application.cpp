#include "Application.h"

#include <PolyEngine\ScreenList.h>
#include <PolyEngine\Command.h>

Application::Application()
{
	m_width = 1024;
	m_height = 768;
	m_windowName = "Awaken v0.0.0";
}


Application::~Application()
{
}

void Application::onInit()
{
	this->addCommand("exit", new Command([this](std::vector<std::string> args) {SDL_Quit(); exit(0); }));
}

void Application::addScreens()
{
	m_mainMenuScreen = std::make_unique<Screen_Main_Menu>(&m_window);

	m_screenList->addScreen(m_mainMenuScreen.get());

	m_screenList->setScreen(m_mainMenuScreen->getScreenIndex());
}

void Application::onExit()
{
}
