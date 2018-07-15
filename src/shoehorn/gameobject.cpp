/* gameobject.cpp
 * a game object is anything in a game that can change during gameplay
 * 
 * Josh Chandler
*/

#include <iostream>
#include <cmath>
#include <memory>

#include "include/gameobject.hpp"
#include "include/collisionpolygon.hpp"

const double pi = std::acos(-1);

namespace shoe {

GameObject::GameObject(GameState *state) 
: mState {state}
, mCollisionPolygon (new CollisionPolygon()) // shared_ptr
{
    //
}

GameObject::~GameObject() {
    //
}

void GameObject::handleInput(const sf::Time &dTime) {
    //
}

void GameObject::update(const sf::Time &dTime) {

}

CollisionPolygon GameObject::collisionPolygon() const {
    return *mCollisionPolygon;
}

sf::Vector2f GameObject::collidesWith(const GameObject &other) const {
    return mCollisionPolygon->collidesWith(other.collisionPolygon());
}

sf::Vector2f GameObject::collidesWith(const CollisionPolygon &other) const {
    return mCollisionPolygon->collidesWith(other);
}

void GameObject::makeIntoRegularShape(uint sides, uint radius) {
    mCollisionPolygon->makeIntoRegularShape(sides, radius);
}

void GameObject::makeIntoRect(sf::Vector2f size) {
    mCollisionPolygon->clear();
    mCollisionPolygon->resize(4);
    mCollisionPolygon->setPrimitiveType(sf::PrimitiveType::LineStrip);

    (*mCollisionPolygon)[0] = sf::Vector2f(0, 0);
    (*mCollisionPolygon)[1] = sf::Vector2f(size.x, 0);
    (*mCollisionPolygon)[2] = sf::Vector2f(size.x, size.y);
    (*mCollisionPolygon)[3] = sf::Vector2f(0, size.y);
}

}