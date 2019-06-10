#include "DynamicEntity.h"



DynamicEntity::DynamicEntity()
{
}


DynamicEntity::DynamicEntity(sf::Vector2f size, sf::Vector2f pos, sf::Texture * texture) : Entity(size,pos,texture) , Animator ()
{
}

DynamicEntity::~DynamicEntity()
{
}
