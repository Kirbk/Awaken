#pragma once

#include <PolyEngine\SpriteBatch.h>

#include <glm.hpp>

#include <PolyEngine\Camera2D.h>
#include <PolyEngine\Vertex.h>
#include <PolyEngine\TileSheet.h>


class Entity
{
public:
	virtual void init(const glm::vec2& position,
		const glm::vec2& drawDims,
		glm::vec2& collisionDims,
		PolyEngine::ColorRGBA8 tint = PolyEngine::ColorRGBA8(255, 255, 255, 255)) = 0;

	virtual void update() = 0;
	virtual void draw(PolyEngine::SpriteBatch& spriteBatch);

protected:
	glm::vec2 m_position, m_direction, m_drawDims, m_collisionsDims;
	
	float m_speed;

	PolyEngine::Camera2D* m_cameraPointer;
	PolyEngine::ColorRGBA8 m_tint;
	PolyEngine::TileSheet m_texture;
};

