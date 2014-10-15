#ifndef CS_H
#define CS_H
//Includes
#include <vector>
#include <map>
#include <iostream>
#include <typeindex>
#include <typeinfo>
#include "../include/system.h"
#include "../include/components.h"


class CS {
public:
	static std::map<eId, MoveComponent*> moveCS;
	static std::map<eId, SpriteComponent*> spriteCS;
	static std::map<eId, ControllerComponent*> controllerCS;
	static std::map<eId, CollisionComponent*> collisionCS;
	static std::map<eId, PropertiesComponent*> propCS;
	static std::map<eId, FuncQComponent*> funcQCS;
	static std::map<const char*, std::vector<eId>> groups; 
	static std::map<const std::string, SDL_Texture*> textures;
	static std::map<eId, Camera*> cameras;
	static std::vector<eId> deletedEntities;
	static QuadTree qt;
	static Grid grid;

	static eId createEntityID();
	static eId createCameraID();
	static void deleteEntity(eId id);

	static void eventUpdate(SDL_Event &e);
	static void update();
	static void draw();
	static void collisionUpdate();
	static void cameraUpdate();
	static void clear();

	static SpriteComponent* getSpriteC(eId e);
	static CollisionComponent* getCollisionC(eId e);

	static eId _E_INDEX; //entities index
	static eId _C_INDEX; //cameras index
};




#endif