#include "ENTITY_TEST.h"

#include <PolyEngine\ResourceManager.h>

ENTITY_TEST::ENTITY_TEST()
{
}

ENTITY_TEST::~ENTITY_TEST()
{

}

void ENTITY_TEST::init(const glm::vec2 & position, const glm::vec2 & drawDims, glm::vec2 & collisionDims, PolyEngine::ColorRGBA8 tint)
{
	PolyEngine::GLTexture texture = PolyEngine::ResourceManager::getTexture("Assets/textures/placeholder.png");
	m_tint = tint;
	m_drawDims = drawDims;
	m_collisionsDims = collisionDims;
	m_texture.init(texture, glm::ivec2(0));
}

void ENTITY_TEST::update()
{

}

//void ENTITY_TEST::draw(PolyEngine::SpriteBatch & spriteBatch)
//{
//}
