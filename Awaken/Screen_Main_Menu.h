#pragma once

#include <vector>

#include <PolyEngine\IGameScreen.h>
#include <PolyEngine\Window.h>
#include <PolyEngine\GLSLProgram.h>
#include <PolyEngine\Camera2D.h>
#include <PolyEngine\SpriteBatch.h>
#include <PolyEngine\SpriteFont.h>

#include "Planet.h"
#include "ENTITY_TEST.h"

class Screen_Main_Menu : public PolyEngine::IGameScreen
{
public:
	Screen_Main_Menu(PolyEngine::Window* window);
	~Screen_Main_Menu();

	// Inherited via IGameScreen
	virtual int getNextScreenIndex() const override;
	virtual int getPreviousScreenIndex() const override;
	virtual void build() override;
	virtual void destroy() override;
	virtual void onEntry() override;
	virtual void onExit() override;
	virtual void update() override;
	virtual void draw() override;

private:
	void checkInput();

	PolyEngine::Window* m_window;
	PolyEngine::GLSLProgram m_textureProgram;
	PolyEngine::Camera2D m_camera;
	PolyEngine::Camera2D m_displayCamera;
	PolyEngine::SpriteBatch m_spriteBatch;
	PolyEngine::SpriteBatch m_textSpriteBatch;
	PolyEngine::SpriteFont* m_spriteFont;

	Planet m_planet;
};

