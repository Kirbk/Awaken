#include "ENTITY_TEST.h"

#include <PolyEngine\ResourceManager.h>

ENTITY_TEST::ENTITY_TEST()
{
	PolyEngine::GLTexture texture = PolyEngine::ResourceManager::getTexture("Assets/textures/placeholder.png");
	m_texture.init(texture, glm::ivec2(0));
}

ENTITY_TEST::~ENTITY_TEST()
{

}

void ENTITY_TEST::update()
{

}

//void ENTITY_TEST::draw(PolyEngine::SpriteBatch & spriteBatch)
//{
//}
