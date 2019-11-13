#pragma once

#include <array>
#include <ofImage.h>

#include <glm/vec2.hpp>


enum class BodyPart
{
	ARM_LEFT = 0,
	ARM_RIGHT = 1,
	CHEST = 2,
	FOREARM_LEFT = 3,
	FOREARM_RIGHT = 4,
	HAND_LEFT = 5,
	HAND_RIGHT = 6,
	HEAD = 7,
	SHIN_LEFT = 8,
	SHIN_RIGHT = 9,
	THIGH_LEFT = 10,
	THIGH_RIGHT = 11,
};



class Character
{
public:

	Character(const std::string& name);

	const ofImage& get(BodyPart body_part) const;

	void draw(BodyPart body_part, glm::vec2 position, float rotation) const;

private:

	std::array<ofImage, 12> body_parts;

};
