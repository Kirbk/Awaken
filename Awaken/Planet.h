#pragma once

#include <map>
#include <string>
#include <vector>
#include <algorithm>

#include <PolyEngine\SpriteBatch.h>

#include "Entity.h"

class Planet
{
public:
	Planet();
	~Planet();

	template<class T>
	void registerEntity(std::string key)
	{
		m_registeredEntities[make_lowercase(key)] = new T();
	}

	Entity* spawnEntity(std::string key, 
		const glm::vec2& position,
		const glm::vec2& drawDims,
		glm::vec2& collisionDims,
		PolyEngine::ColorRGBA8 tint = PolyEngine::ColorRGBA8(255, 255, 255, 255));

	void init();
	void update();
	void render(PolyEngine::SpriteBatch& spriteBatch);

	std::string make_lowercase(const std::string& in)
	{
		std::string out;

		std::transform(in.begin(), in.end(), std::back_inserter(out), ::tolower);
		return out;
	}

private:
	std::map<std::string, Entity*> m_registeredEntities;
	std::vector<Entity*> m_entities;
};

