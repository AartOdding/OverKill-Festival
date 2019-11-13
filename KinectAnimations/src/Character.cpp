#include "Character.h"

#include <ofMain.h>



Character::Character(const std::string& name)
{
	body_parts[static_cast<int>(BodyPart::ARM_LEFT)]      = ofImage(name + "/arm_left.png");
	body_parts[static_cast<int>(BodyPart::ARM_RIGHT)]     = ofImage(name + "/arm_right.png");
	body_parts[static_cast<int>(BodyPart::CHEST)]         = ofImage(name + "/chest.png");
	body_parts[static_cast<int>(BodyPart::FOREARM_LEFT)]  = ofImage(name + "/forearm_left.png");
	body_parts[static_cast<int>(BodyPart::FOREARM_RIGHT)] = ofImage(name + "/forearm_right.png");
	body_parts[static_cast<int>(BodyPart::HAND_LEFT)]     = ofImage(name + "/hand_left.png");
	body_parts[static_cast<int>(BodyPart::HAND_RIGHT)]    = ofImage(name + "/hand_right.png");
	body_parts[static_cast<int>(BodyPart::HEAD)]          = ofImage(name + "/head.png");
	body_parts[static_cast<int>(BodyPart::SHIN_LEFT)]     = ofImage(name + "/shin_left.png");
	body_parts[static_cast<int>(BodyPart::SHIN_RIGHT)]    = ofImage(name + "/shin_right.png");
	body_parts[static_cast<int>(BodyPart::THIGH_LEFT)]    = ofImage(name + "/thigh_left.png");
	body_parts[static_cast<int>(BodyPart::THIGH_RIGHT)]   = ofImage(name + "/thigh_right.png");

	for (auto& img : body_parts)
	{
		img.setAnchorPoint(500, 500);
	}
}


const ofImage& Character::get(BodyPart body_part) const
{
	return body_parts[static_cast<int>(body_part)];
}

void Character::draw(BodyPart body_part, glm::vec2 position, float rotation) const
{
	ofPushMatrix();

	ofTranslate(position);
	ofRotate(rotation * 57.2957795); // convert to radians
	body_parts[static_cast<int>(body_part)].draw(0, 0);

	ofPopMatrix();
}
