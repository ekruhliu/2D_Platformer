/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 17:32:39 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/07/02 17:32:40 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "./libSDL/SDL2.framework/Headers/SDL.h"
# include "./libSDL/SDL2_image.framework/Headers/SDL_image.h"
# include <iostream>
# include <stdio.h>

class Game
{
public:
	Game();
	Game(Game const &src);
	Game &operator=(Game const &rhs);

	void	init(const	char* title, int xpos, int ypos, int w, int h, bool fullscreen);
	void	keys();
	void	update();
	void	render();
	void	clean();
	bool	running() { return _gameRunning; };

	~Game();
private:
	bool			_gameRunning;
	SDL_Window		*_win;
	SDL_Renderer	*_rend;
};

#endif
