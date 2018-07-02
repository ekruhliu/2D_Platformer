/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 17:32:01 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/07/02 17:32:12 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

int	main()
{
	Game		*game = new Game();
	const int	FPS = 60;
	const int	frameDelay = 1000 / FPS;
	Uint32		frameStart;
	int			frameTime;

	game->init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 1000, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();
		game->keys();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}
	game->clean();
	delete (game);
	return 0;
}
