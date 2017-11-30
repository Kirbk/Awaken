#include "Planet.h"

Planet::Planet()
{
}


Planet::~Planet()
{
}

Entity* Planet::spawnEntity(std::string key,
	const glm::vec2& position,
	const glm::vec2& drawDims,
	glm::vec2& collisionDims,
	PolyEngine::ColorRGBA8 tint)
{
	std::string newKey = make_lowercase(key);

	try {
		Entity* cloned = m_registeredEntities.at(newKey);
		Entity* t = cloned->clone();
		t->m_position = position;
		t->m_drawDims = drawDims;
		t->m_collisionsDims = collisionDims;
		t->m_tint = tint;
		t->m_texture = cloned->m_texture;
		t->m_cameraPointer = cloned->m_cameraPointer;

		m_entities.push_back(t);
		return t;
	} catch(...) {
		printf_s("Unable to spawn [%s], %s is not a registered entity.\n", newKey.c_str(), newKey.c_str());
		return nullptr;
	}
}

void Planet::update()
{
	for (Entity* e : m_entities) {
		e->update();
	}
}

void Planet::render(PolyEngine::SpriteBatch & spriteBatch)
{
	for (Entity* e : m_entities) {
		e->draw(spriteBatch);
	}
}
