#pragma once

#include <PolyEngine\SpriteBatch.h>

#include <glm.hpp>

#include <PolyEngine\Camera2D.h>
#include <PolyEngine\Vertex.h>
#include <PolyEngine\TileSheet.h>


class Entity
{
public:
	Entity();

	virtual void update();
	virtual void draw(PolyEngine::SpriteBatch& spriteBatch);

	Entity* clone();

	glm::vec2 m_position, m_direction, m_drawDims, m_collisionsDims;
	
	float m_speed;

	PolyEngine::Camera2D* m_cameraPointer;
	PolyEngine::ColorRGBA8 m_tint;
	PolyEngine::TileSheet m_texture;
};

