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

#ifndef VISITOR_HH
#define VISITOR_HH

class Bullet;
class Heli;
class Hellfire;
class Hydra;

class Visitor {
public:
	virtual void Visit(Bullet&) {}
	virtual void Visit(Heli&) {}
	virtual void Visit(Hellfire&) {}
	virtual void Visit(Hydra&) {}
};

#endif // VISITOR_HH
