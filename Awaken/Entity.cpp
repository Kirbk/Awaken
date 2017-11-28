#include "Entity.h"

Entity::Entity()
{
}

void Entity::update()
{
}

void Entity::draw(PolyEngine::SpriteBatch & spriteBatch)
{
	glm::vec4 destRect;
	destRect.x = m_position.x - m_drawDims.x / 2.0f;
	destRect.y = m_position.y - m_drawDims.y / 2.0f;
	destRect.z = m_drawDims.x;
	destRect.w = m_drawDims.y;

	spriteBatch.draw(destRect, glm::vec4(0, 0, 1, 1), m_texture.texture.id, 0.0f, m_tint);
}

Entity* Entity::clone()
{
	Entity* temp = new Entity();

	*temp = *this;

	return temp;
}
