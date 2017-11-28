#include "Screen_Main_Menu.h"

#include <PolyEngine\IMainGame.h>
#include <PolyEngine\Command.h>

Screen_Main_Menu::Screen_Main_Menu(PolyEngine::Window* window) : m_window(window)
{
}


Screen_Main_Menu::~Screen_Main_Menu()
{
}

int Screen_Main_Menu::getNextScreenIndex() const
{
	return SCREEN_INDEX_NO_SCREEN;
}

int Screen_Main_Menu::getPreviousScreenIndex() const
{
	return SCREEN_INDEX_NO_SCREEN;
}

void Screen_Main_Menu::build()
{
}

void Screen_Main_Menu::destroy()
{
}

void Screen_Main_Menu::onEntry()
{
	// Initialize SpriteBatch
	m_spriteBatch.init();
	m_textSpriteBatch.init();

	// TODO: FIX FAILURE TO START WITH THIS LINE
	//m_spriteFont = new PolyEngine::SpriteFont("Assets/fonts/Oswald-SemiBold.ttf", 64);

	// Shader init
	m_textureProgram.compileShaders("Shaders/textureShading.vert", "Shaders/fragmentShading.frag");
	m_textureProgram.addAttribute("vertexPosition");
	m_textureProgram.addAttribute("vertexColor");
	m_textureProgram.addAttribute("vertexUV");
	m_textureProgram.linkShaders();

	// Init camera
	m_camera.init(m_window->getScreenWidth(), m_window->getScreenHeight());
	m_camera.setScale(1.0f);
	m_camera.setPosition(glm::vec2(0.0f, 0.0f));

	m_planet.registerEntity<ENTITY_TEST>("TEST_ENTITY");

	m_planet.spawnEntity("TEST_ENTITY", glm::vec2(0), glm::vec2(10), glm::vec2(10));
	m_planet.spawnEntity("TEST_ENTITY", glm::vec2(10), glm::vec2(10), glm::vec2(10));
	m_planet.spawnEntity("TEST_ENTITY", glm::vec2(20), glm::vec2(10), glm::vec2(10));

	//testEntity->init(glm::vec2(0), glm::vec2(10), glm::vec2(10));
}

void Screen_Main_Menu::onExit()
{
}

void Screen_Main_Menu::update()
{
	m_camera.update();
	checkInput();
	m_planet.update();
}

void Screen_Main_Menu::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.8f, 0.4f, 1.0f);

	m_textureProgram.use();

	// Upload texture uniform
	GLint textureUniform = m_textureProgram.getUniformLocation("mySampler");
	glUniform1i(textureUniform, 0);
	glActiveTexture(GL_TEXTURE0);

	// Camera matrix
	glm::mat4 projectionMatrix = m_camera.getCameraMatrix();
	GLint pUniform = m_textureProgram.getUniformLocation("P");
	glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);

	// Add items to spritebatch to be rendered
	m_spriteBatch.begin();

	m_planet.render(m_spriteBatch);

	m_spriteBatch.end();
	m_spriteBatch.renderBatch();
	m_textureProgram.unuse();
}

void Screen_Main_Menu::checkInput()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		m_game->onSDLEvent(evnt);
	}
}
