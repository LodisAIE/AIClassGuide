#pragma once
#include <type_traits>
class Transform2D;
class Collider;
class Component;

class Actor
{
public:
    Actor();
    ~Actor();

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="name">The name of this actor.</param>
    Actor(float x, float y, const char* name);

    /// <summary>
    /// </summary>
    /// <returns>If the actors start function has been called.</returns>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor.</returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider
    /// </summary>
    /// <param name="collider">The new collider to attach to the actor</param>
    void setCollider(Collider* collider) { m_collider = collider; }

    /// <summary>
    /// Gets the name of this actor
    /// </summary>
    const char* getName() { return m_name; }

    /// <summary>
    /// Sets the name of this actor
    /// </summary>
    /// <param name="name">The new actor name</param>
    void setName(const char* name) { m_name = name; }

    /// <summary>
    /// Gets the first component instance attached to this actor
    /// that matches the name
    /// </summary>
    /// <param name="componentName">The name of the component instance</param>
    template<typename T>
    T* getComponent();

    /// <summary>
    /// Adds a component to the end of the component array
    /// </summary>
    /// <param name="component">The new component to attach to the actor</param>
    /// <returns>A reference to the component added to the array</returns>
    template<typename T>
    T* addComponent();

    Component* addComponent(Component* component);

    /// <summary>
    /// Called when a new component is added to the actor
    /// </summary>
    /// <param name="component"></param>
    virtual void onAddComponent(Component* component);

    /// <summary>
    /// Removes the first instance found that matches the component reference
    /// </summary>
    /// <param name="component">The component to remove from the array</param>
    /// <returns>False if the component is not in the array</returns>
    
    bool removeComponent(Component* component);

    /// <summary>
    /// Removes the first instance found that matches the component name
    /// </summary>
    /// <param name="component">The name of the component to remove from the array</param>
    /// <returns>False if the component is not in the array</returns>
    template<typename T>
    bool removeComponent();

    /// <summary>
    /// Called during the first update after an actor is added to a scene
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame
    /// </summary>
    /// <param name="deltaTime">The time that has passed from the previous frame to the current</param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed 
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another
    /// </summary>
    /// <param name="other">The actor to check collision against</param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param name="other">The actor this actor collided with.</param>
    virtual void onCollision(Actor* other);

protected:
    const char* m_name;

private:
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    Component** m_components;
    unsigned int m_componentCount;
};

template<typename T>
inline T* Actor::getComponent()
{
    //Iterate through the component array
    for (int i = 0; i < m_componentCount; i++)
    {
        T* temp = dynamic_cast<T*>(m_components[i]);
        //Return the comoponent if the name is the same as the current component
        if (temp)
            return (T*)m_components[i];
    }

    //Return nullptr if the component is not in the list
    return nullptr;
}

template<typename T>
inline T* Actor::addComponent()
{
    T* component = new T();
    //Return null if this component has an owner already
    Actor* owner = component->getOwner();
    if (owner)
        return nullptr;

    component->assignOwner(this);

    //Create a new array with a size one greater than our old array
    Component** appendedArray = new Component * [m_componentCount + 1];
    //Copy the values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        appendedArray[i] = m_components[i];
    }

    //Set the last value in the new array to be the actor we want to add
    appendedArray[m_componentCount] = component;
    if (m_componentCount > 1)
        //Set old array to hold the values of the new array
        delete[] m_components;
    else if (m_componentCount == 1)
        delete m_components;

    m_components = appendedArray;
    m_componentCount++;

    onAddComponent(component);

    return (T*)component;
}

template<typename T>
inline bool Actor::removeComponent()
{
    bool componentRemoved = false;
    //Create a new array with a size one less than our old array
    Component** newArray = new Component * [m_componentCount - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componentCount; i++)
    {
        T* temp = dynamic_cast<T*>(m_components[i]);
        if (!temp)
        {
            newArray[j] = m_components[i];
            j++;
        }
        else
        {
            componentRemoved = true;
        }
    }

    if (componentRemoved)
    {
        delete[] m_components;
        //Set the old array to the new array
        m_components = newArray;
        m_componentCount--;
    }
    else
        delete[] newArray;

    //Return whether or not the removal was successful
    return componentRemoved;
}
