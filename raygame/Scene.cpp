#include "Scene.h"
#include "Transform2D.h"
#include <string.h>
#include "Engine.h"
#include <exception>
DynamicArray<Actor*> Scene::m_actorsToDelete = DynamicArray<Actor*>();
bool hasNotPushed = true;
Scene::Scene()
{
    m_actorCount = 0;
    m_actors = DynamicArray<Actor*>();
    m_world = new MathLibrary::Matrix3();
}

MathLibrary::Matrix3* Scene::getWorld()
{
    return m_world;
}

void Scene::addUIElement(Actor* actor)
{
    m_UIElements.addItem(actor);

    //Adds all children of the UI to the scene
    for (int i = 0; i < actor->getTransform()->getChildCount(); i++)
    {
        addUIElement(actor->getTransform()->getChildren()[i]->getOwner());
    }
}

bool Scene::removeUIElement(int index)
{
    return m_UIElements.remove(m_actors.getItem(index));
}

bool Scene::removeUIElement(Actor* actor)
{
    return m_UIElements.remove(actor);
}

void Scene::addActor(Actor* actor)
{
    m_actors.addItem(actor);

    //Adds all children of the actor to the scene
    for (int i = 0; i < actor->getTransform()->getChildCount(); i++)
    {
        addActor(actor->getTransform()->getChildren()[i]->getOwner());
    }

}

bool Scene::removeActor(int index)
{
    return m_actors.remove(m_actors.getItem(index));
}

bool Scene::removeActor(Actor* actor)
{
    return m_actors.remove(actor);
}

void Scene::addActorToDeletionList(Actor* actor)
{
    //return if the actor is already going to be deleted
    if (m_actorsToDelete.contains(actor))
        return;

    //Add actor to deletion list
    m_actorsToDelete.addItem(actor);

    //Add all the actors children to the deletion list
    for (int i = 0; i < actor->getTransform()->getChildCount(); i++)
    {
        addActorToDeletionList(actor->getTransform()->getChildren()[i]->getOwner());
    }
}

void Scene::destroy(Actor* actor)
{
    addActorToDeletionList(actor);
}

void Scene::destroyActorsInList()
{
    //Iterate through deletion list
    for (int i = 0; i < m_actorsToDelete.getLength(); i++)
    {
        //Remove actor from the scene
        Actor* actorToDelete = m_actorsToDelete.getItem(i);
        if (!removeActor(actorToDelete))
            removeUIElement(actorToDelete);

        //Call actors clean up functions


        for (int i = 0; i < actorToDelete->getTransform()->getChildCount(); i++)
            actorToDelete->getTransform()->getChildren()[i]->setParent(actorToDelete->getTransform()->getParent());

        actorToDelete->end();
        actorToDelete->onDestroy();

        //Delete the actor
        delete actorToDelete;
    }

    //Clear the array
    m_actorsToDelete = DynamicArray<Actor*>();
}


Actor* Scene::getActor(int index)
{
    return m_actors.getItem(index);
}

void Scene::start()
{
    m_started = true;
}

void Scene::update(float deltaTime)
{
    //Clean up actors marked for destruction
    destroyActorsInList();

    //Updates all actors
    for (int i = 0; i < m_actors.getLength(); i++)
    {
        if (!m_actors.getItem(i)->getStarted())
            m_actors.getItem(i)->start();

        m_actors.getItem(i)->update(deltaTime);
    }

    //Checks collision for all actors
    for (int i = 0; i < m_actors.getLength(); i++)
    {
        for (int j = 0; j < m_actors.getLength(); j++)
        {
            if (m_actors.getItem(i)->checkForCollision(m_actors.getItem(j)) && j != i && m_actors.getItem(j)->getStarted())
                m_actors.getItem(i)->onCollision(m_actors.getItem(j));
        }
    }
}

void Scene::updateUI(float deltaTime)
{
    //Calls update for all actors in UI array
    for (int i = 0; i < m_UIElements.getLength(); i++)
    {
        if (!m_UIElements.getItem(i)->getStarted())
            m_UIElements.getItem(i)->start();

        m_UIElements.getItem(i)->update(deltaTime);
    }
}

void Scene::draw()
{
    //Calls draw for all actors in the array
    for (int i = 0; i < m_actors.getLength(); i++)
    {
        m_actors.getItem(i)->draw();
    }
}

void Scene::drawUI()
{
    //Calls draw for all actors in UI array
    for (int i = 0; i < m_UIElements.getLength(); i++)
    {
        m_UIElements.getItem(i)->draw();
    }
}

void Scene::end()
{
    //Calls end for all actors in the array
    for (int i = 0; i < m_actors.getLength(); i++)
    {
        if (m_actors.getItem(i)->getStarted())
            m_actors.getItem(i)->end();
    }

    m_started = false;
}