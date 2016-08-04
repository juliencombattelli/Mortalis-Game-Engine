//============================================================================
// Name        : AutotilerVXAce.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Aug 4, 2016
// Version     : 1.0.0
// Copyright   : This file is part of AutotileDecompressor project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef AUTOTILERVXACE_HPP_
#define AUTOTILERVXACE_HPP_

#include <MUL/SFE/Autotiler.hpp>

namespace mul { namespace sfe
{

class AutotilerVXAce : Autotiler
{
public:
	virtual ~AutotilerVXAce() = default;
	virtual MinitileArray generateTile(int tileId, const sf::Vector2i& autotileTopLeftCorner = {0,0}) override
	{
		std::array<sf::IntRect,4> minitiles;

		Tile t = static_cast<Tile>(tileId);

		for(int i = 0 ; i < 4 ; i++)
			minitiles[i] = sf::IntRect(
					(m_minitilesMaps.at(t)[i]%4)*16 + autotileTopLeftCorner.x,
					(m_minitilesMaps.at(t)[i]/4)*16 + autotileTopLeftCorner.y,
					16, 16);

		return minitiles;
	}

private:

	enum Tile
	{
		borderNone,
		borderAll,

		borderTop,
		borderBottom,
		borderLeft,
		borderRight,

		borderNoTop,
		borderNoBottom,
		borderNoLeft,
		borderNoRight,

		borderHorizontal,
		borderVertical,

		borderTopLeft,
		borderTopRight,
		borderBottomRigth,
		borderBottomLeft,

		cornerCenter,
		cornerAll,

		cornerTop,
		cornerBottom,
		cornerLeft,
		cornerRight,

		cornerNoTopLeft,
		cornerNoBottomLeft,
		cornerNoTopRight,
		cornerNoBottomRight,

		cornerFirstDiag,
		cornerSecondDiag,

		cornerTopLeft,
		cornerTopRight,
		cornerBottomRigth,
		cornerBottomLeft,

		turnTopLeft,
		turnTopRight,
		turnBottomLeft,
		turnBottomRight,

		borderRightCornerTopLeft,
		borderBottomCornerTopLeft,
		borderLeftCornerTopRight,
		borderBottomCornerTopRight,
		borderLeftCornerBottomRight,
		borderTopCornerBottomRight,
		borderRightCornerBottomLeft,
		borderTopCornerBottomLeft,

		borderTopCornerBottom,
		borderBottomCornerTop,
		borderLeftCornerRight,
		borderRightCornerLeft
	};

	const std::map<Tile,std::array<int,4>> m_minitilesMaps
	{
		{ borderNone, 					{18,17,14,13} },
		{ borderAll, 					{8,11,20,23} },
		{ borderTop, 					{9,10,13,14} },
		{ borderBottom, 				{17,18,21,22} },
		{ borderLeft, 					{12,13,16,17} },
		{ borderRight,		 			{14,15,18,19} },
		{ borderNoTop, 					{16,19,20,23} },
		{ borderNoBottom, 				{8,11,12,15} },
		{ borderNoLeft,			 		{10,11,22,23} },
		{ borderNoRight, 				{8,9,20,21} },
		{ borderHorizontal, 			{10,9,22,21} },
		{ borderVertical, 				{16,19,12,15} },
		{ borderTopLeft, 				{8,9,12,13} },
		{ borderTopRight, 				{10,11,14,15} },
		{ borderBottomRigth, 			{18,19,22,23} },
		{ borderBottomLeft, 			{16,17,20,21} },
		{ cornerCenter, 				{7,6,3,2} },
		{ cornerAll, 					{2,3,6,7} },
		{ cornerTop, 					{2,3,14,13} },
		{ cornerBottom, 				{18,17,6,7} },
		{ cornerLeft, 					{2,17,6,13} },
		{ cornerRight, 					{18,3,14,7} },
		{ cornerNoTopLeft,				{18,3,6,7} },
		{ cornerNoBottomLeft, 			{2,3,6,13} },
		{ cornerNoTopRight, 			{2,3,14,7} },
		{ cornerNoBottomRight,			{2,17,6,7} },
		{ cornerFirstDiag,	 			{2,17,14,7} },
		{ cornerSecondDiag, 			{18,3,6,13} },
		{ cornerTopLeft, 				{2,17,14,13} },
		{ cornerTopRight, 				{18,3,14,13} },
		{ cornerBottomRigth, 			{18,17,14,7} },
		{ cornerBottomLeft, 			{18,17,6,13} },
		{ turnTopLeft,					{2,19,22,23} },
		{ turnTopRight,					{16,3,20,21} },
		{ turnBottomLeft,				{10,11,6,15} },
		{ turnBottomRight,				{8,9,12,7} },
		{ borderRightCornerTopLeft,		{2,19,14,15} },
		{ borderBottomCornerTopLeft,	{2,17,22,21} },
		{ borderLeftCornerTopRight,		{16,3,12,13} },
		{ borderBottomCornerTopRight,	{18,3,22,21} },
		{ borderLeftCornerBottomRight,	{16,17,12,7} },
		{ borderTopCornerBottomRight,	{10,9,14,7} },
		{ borderRightCornerBottomLeft,	{18,19,6,15} },
		{ borderTopCornerBottomLeft,	{10,9,6,13} },
		{ borderTopCornerBottom,		{10,9,6,7} },
		{ borderBottomCornerTop,		{2,3,22,1} },
		{ borderLeftCornerRight,		{16,3,12,7} },
		{ borderRightCornerLeft,		{2,19,6,15} }
	};
};

} // namespace sfe
} // namespace mul


#endif // AUTOTILERVXACE_HPP_
