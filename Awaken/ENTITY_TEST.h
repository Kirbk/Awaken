#pragma once

#include "Entity.h"

class ENTITY_TEST : public Entity
{
public:
	ENTITY_TEST();
	~ENTITY_TEST();

	// Inherited via Entity
	virtual void init(const glm::vec2 & position, const glm::vec2 & drawDims, glm::vec2 & collisionDims, PolyEngine::ColorRGBA8 tint = PolyEngine::ColorRGBA8(255, 255, 255, 255)) override;
	virtual void update() override;
	//virtual void draw(PolyEngine::SpriteBatch & spriteBatch) override;
};

