#include "DynamicEntity.h"

DynamicEntity::DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Texture* texture, sf::Vector2u imgCounter, float times) : Entity (size,pos,texture), Animation (texture,imgCounter,times)
{
}
