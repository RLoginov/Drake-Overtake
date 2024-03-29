/*
 * GxfMgr.h
 *
 *  Created on: Mar 9, 2017
 *      Author: sushil
 */

#ifndef GFXMGR_H_
#define GFXMGR_H_

#include <OgreRoot.h>
#include <OgreConfigFile.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <OgreViewport.h>
#include <OgreEntity.h>
#include <OgreWindowEventUtilities.h>


#include "../Inc/mgr.h"
#include "../Inc/Terrain.h"


class GfxMgr : public Mgr {

private:
	Ogre::String resources;
	Ogre::String plugins;
	Ogre::ConfigFile cf;
	void loadConfig(Ogre::ConfigFile cf);
	void configureRenderSystem();
	void initResources();

	void createSceneManager();
	void createCamera();
	Ogre::Viewport *ogreViewport;
	void createViewport();

public:

	GfxMgr(Engine *eng);
	~GfxMgr();

	virtual void tick(float dt);
	virtual void init();
	virtual void loadLevel();
	virtual void stop();
	void testScene();

	Ogre::Camera* ogreCamera;
	Ogre::RenderWindow* ogreRenderWindow;
	Ogre::SceneManager* ogreSceneManager;
	Ogre::SceneNode *cameraNode, *pitchNode;
	Ogre::Root *ogreRoot;
	Ogre::Light* ogreLight;

	Terrain* ground;
};


#endif /* GFXMGR_H_ */
