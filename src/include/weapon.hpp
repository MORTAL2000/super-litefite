/*
 * weapon
 * stabby stab
 * 
 * Josh Chandler
*/

#pragma once

#include <vector>

#include "../shoehorn/include/gameobject.hpp"

class HurtPolygon;

class Weapon : public shoe::GameObject {
public:
    Weapon(shoe::GameState *state, shoe::GameObject &owner);

    void setPosition(sf::Vector2f position);
    void setRotation(float rotation);

    virtual void activate();
    
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

protected:
    std::vector<std::shared_ptr<HurtPolygon>> mHurtPolygons;
};