#pragma once
#include "GenericList.h"
#include "Collision.h"
#include "AbstractEntitys.h"
using namespace AbstractEntitys;
namespace Lists {
	class DynamicList {
	private:
		List <AbstractEntitys::DynamicEntity> ListofDinamics;
	public:
		List<AbstractEntitys::DynamicEntity>::Iterator<AbstractEntitys::DynamicEntity> it;
		List<AbstractEntitys::DynamicEntity> getList() { return ListofDinamics; }
		~DynamicList() { ListofDinamics.clean(); }
		void operator+(DynamicEntity* data) { ListofDinamics.add(data); }
		void drawAll(sf::RenderWindow* window);
	};

	class EntityList {
	private:
		List <AbstractEntitys::Entity> ListofEntitys;
	public:
		//EntityList();
		List<AbstractEntitys::Entity>::Iterator<AbstractEntitys::Entity> it;
		List<AbstractEntitys::Entity> getList() { return ListofEntitys; }
		~EntityList() { ListofEntitys.clean(); }
		void operator+(Entity* data) { ListofEntitys.add(data); }
		void drawAll(sf::RenderWindow* window);

	};

	class StaticList {
	private:
		List <AbstractEntitys::StaticEntity> ListofStatics;
	public:
		~StaticList() { ListofStatics.clean(); }
		List <AbstractEntitys::StaticEntity> getList() { return ListofStatics; }
		List<AbstractEntitys::StaticEntity>::Iterator<AbstractEntitys::StaticEntity> it;
		void operator+(StaticEntity* data) { ListofStatics.add(data); }
		void drawAll(sf::RenderWindow* window);
	};

}