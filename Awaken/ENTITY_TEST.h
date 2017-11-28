#pragma once

#include "Entity.h"

class ENTITY_TEST : public Entity
{
public:
	ENTITY_TEST();
	~ENTITY_TEST();

	// Inherited via Entity
	virtual void update() override;
	//virtual void draw(PolyEngine::SpriteBatch & spriteBatch) override;
};

