/*
 * Copyright (C) 2013-2014 Dmitry Marakasov
 *
 * This file is part of openstrike.
 *
 * openstrike is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * openstrike is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with openstrike.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cassert>
#include <iostream>

#include <game/game.hh>
#include <graphics/spritemanager.hh>

#include <gameobjects/heli.hh>
#include <gameobjects/bullet.hh>
#include <gameobjects/hydra.hh>
#include <gameobjects/hellfire.hh>

#include <graphics/renderer.hh>

Renderer::Renderer(SpriteManager& spriteman)
	: sprite_heli_(spriteman, "AP0000"), // XXX: only Desert Strike for now
	  sprite_shadow_(spriteman, "SHADOWS"),
	  sprite_rotor_(spriteman, "ROTOR", 0, 8, 30.0), // XXX: this means all rotors on screen will be synchorized for now
	  sprite_bullet_(spriteman, "WEAPONS", 0),
	  sprite_hydra_(spriteman, "WEAPONS", 1),
	  sprite_hellfire_(spriteman, "WEAPONS", 14) {
}

void Renderer::Render(Game& game) {
	// XXX: this should be split into two phases:
	// - get all (renderable? visible?) objects from game
	// - sort them
	// - render each
	game.Accept(*this);
}

void Renderer::Update(unsigned int deltams) {
	// process animations
	sprite_rotor_.Update(deltams);
}

void Renderer::Visit(GameObject& obj) {
	static bool warning_displayed = false;
	if (!warning_displayed)
		std::cerr << "Warning: Renderer::Visit() not implemented for some objects" << std::endl;
	warning_displayed = true;
}

void Renderer::Visit(Heli& heli) {
	int shadow_offset = 16 + heli.GetPos().z; // sprite offset from Desert Strike

	// XXX: shadow should be transparent
	sprite_shadow_.Render(40, 100, heli.GetDirection().yaw);
	sprite_heli_.Render(40, 100 - shadow_offset, heli.GetDirection().yaw);
	sprite_rotor_.Render(40, 100 - shadow_offset);
}

void Renderer::Visit(Bullet& bullet) {
	Vector3f pos = bullet.GetPos();
	sprite_bullet_.Render(40 + pos.x, 100 - pos.y / 2 - pos.z);
}

void Renderer::Visit(Hydra& hydra) {
	Vector3f pos = hydra.GetPos();
	sprite_hydra_.Render(40 + pos.x, 100 - pos.y / 2 - pos.z, hydra.GetDirection().yaw);
}

void Renderer::Visit(Hellfire& hellfire) {
	Vector3f pos = hellfire.GetPos();
	sprite_hellfire_.Render(40 + pos.x, 100 - pos.y / 2 - pos.z, hellfire.GetDirection().yaw);
}
