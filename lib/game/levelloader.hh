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

#ifndef LEVELLOADER_HH
#define LEVELLOADER_HH

#include <string>
#include <vector>

#include <dat/datlevel.hh>

#include <game/game.hh>

class DatFile;

class LevelLoader {
private:
	std::vector<DatLevel::BuildingInstanceProcessor> building_instance_processors_;
	std::vector<DatLevel::BuildingTypeProcessor> building_type_processors_;
	std::vector<DatLevel::UnitInstanceProcessor> unit_instance_processors_;

public:
	LevelLoader();

	void AddBuildingInstanceProcessor(const DatLevel::BuildingInstanceProcessor& fn);
	void AddBuildingTypeProcessor(const DatLevel::BuildingTypeProcessor& fn);
	void AddUnitInstanceProcessor(const DatLevel::UnitInstanceProcessor& fn);

	Game Load(const DatFile& datfile, const std::string& levelname, int width_blocks, int height_blocks);
};

#endif // LEVELLOADER_HH
