/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 17:32:49 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/07/02 17:32:49 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

SDL_Texture	*playerText;
SDL_Rect	srcR, dstR;

Game::Game(){}

Game::Game(Game	const &src) { *this = src; }

Game	&Game::operator=(Game const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void	Game::init(const	char* title, int xpos, int ypos, int w, int h, bool fullscreen)
{
	int flags = 0;
	dstR.x = 0; 
	dstR.y = 939;

	(fullscreen ? flags = SDL_WINDOW_FULLSCREEN : 0);
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		_win = SDL_CreateWindow(title, xpos, ypos, w, h, flags);
		if (!_win)
		{
			std::cout << "Error! Problem with creating window!" << std::endl;
			exit(1);
		}
		_rend = SDL_CreateRenderer(_win, -1, 0);
		if (!_rend)
		{
			std::cout << "Error! Problem with creating render!" << std::endl;
			exit(1);
		}
		else
			SDL_SetRenderDrawColor(_rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
		_gameRunning = true;
	}
	else { _gameRunning = true; }
	
	SDL_Surface	*surf = IMG_Load("./player.png");
	playerText = SDL_CreateTextureFromSurface(_rend, surf);
	SDL_FreeSurface(surf);
}

void	Game::keys()
{
	SDL_Event		event;
	const Uint8		*keyboard_state = SDL_GetKeyboardState(NULL);;
	SDL_PollEvent(&event);

	(keyboard_state[SDL_SCANCODE_ESCAPE]) ? _gameRunning = false : (0);
	(event.type == SDL_QUIT) ? _gameRunning = false : (0);
	// (keyboard_state[SDL_SCANCODE_S] && dstR.y < 939 ? dstR.y += 3 : (0));
	// (keyboard_state[SDL_SCANCODE_W] && dstR.y > -5 ? dstR.y -= 3 : (0));
	(keyboard_state[SDL_SCANCODE_A] && dstR.x > 0 ? dstR.x -= 3 : (0));
	(keyboard_state[SDL_SCANCODE_D] && dstR.x < 1143 ? dstR.x += 3 : (0));
	if (keyboard_state[SDL_SCANCODE_SPACE])
	{
		for(;dstR.y != dstR.y + 50; dstR.y++);

		// for(;dstR.y != dstR.y - 50; dstR.y--);		
	}
}

void	Game::update()
{
	dstR.h = 64;
	dstR.w = 64;
	// std::cout << "X = "<< dstR.x << std::endl;
	// std::cout << "Y = "<< dstR.y << std::endl;
}

void	Game::render()
{
	SDL_RenderClear(_rend);
	SDL_RenderCopy(_rend, playerText, NULL, &dstR);
	SDL_RenderPresent(_rend);
}

void	Game::clean()
{
	SDL_DestroyWindow(_win);
	SDL_DestroyRenderer(_rend);
	SDL_Quit();
}

Game::~Game(){}
