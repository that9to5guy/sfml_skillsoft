#include<string>
#include<iostream>

#include "tic_tac_toe.h"

using std::string;

bool TicTacToe::load_board() {
	if (!board_texture.loadFromFile("../assets/game/board.png")) {
		return false;
	}

	board.setTexture(board_texture);
    board.setOrigin(sf::Vector2f(board.getGlobalBounds().width / 2, 
								 board.getGlobalBounds().height / 2));
	board.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

	return true;
}

bool TicTacToe::load_pieces() {
	if (!texture_o.loadFromFile("../assets/game/O.png")) {
		return false;
	}

	if (!texture_x.loadFromFile("../assets/game/X.png")) {
		return false;
	}

	if (!texture_blank.loadFromFile("../assets/game/blank.png")) {
		return false;
	}

	return true;
}

bool TicTacToe::load_fonts_and_text() {
	if (!font.loadFromFile("../assets/font/PressStart2P-Regular.ttf")) {
		return false;
	}
    
	text.setFont(font);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::Black);
	text.setPosition(sf::Vector2f(130.0f, 75.0f));

    title.setFont(font);
	title.setCharacterSize(45);
	title.setFillColor(sf::Color::Blue);
	title.setPosition(sf::Vector2f(75.0f, 15.0f));
    title.setString("Tic-Tac-Toe");

    reset.setFont(font);
    reset.setCharacterSize(35);
	reset.setFillColor(sf::Color(153, 0, 153));
	reset.setPosition(sf::Vector2f(40.0f, 700.0f));
    reset.setString("RESET");

    exit.setFont(font);
    exit.setCharacterSize(35);
	exit.setFillColor(sf::Color(34, 153, 84));
	exit.setPosition(sf::Vector2f(470.0f, 700.0f));
    exit.setString("EXIT");

	return true;
}

bool TicTacToe::load_sounds() {
    if (!click_buffer.loadFromFile("../assets/audio/click.wav")) {
        return false;
	}
    click_sound.setBuffer(click_buffer);

    if (!win_buffer.loadFromFile("../assets/audio/winner.wav")) {
        return false;
	}
    win_sound.setBuffer(win_buffer);

	return true;
}

bool TicTacToe::load_assets() {
	
	if (!load_board() ||
		!load_pieces() ||
		!load_fonts_and_text() ||
		!load_sounds()) {
	  return false;		
	}

	return true;
}


bool TicTacToe::initialize_game(int start_player) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			board_model[row][col] = BLANK;
		}
	}

	this->wait_for_reset = false;

	this->pieces[0][0].setPosition(sf::Vector2f(33.0f, 141.0f));
	this->pieces[0][1].setPosition(sf::Vector2f(231.0f, 141.0f));
	this->pieces[0][2].setPosition(sf::Vector2f(428.0f, 141.0f));
	this->pieces[1][0].setPosition(sf::Vector2f(33.0f, 316.0f));
	this->pieces[1][1].setPosition(sf::Vector2f(231.0f, 316.0f));
	this->pieces[1][2].setPosition(sf::Vector2f(428.0f, 316.0f));
	this->pieces[2][0].setPosition(sf::Vector2f(33.0f, 491.0f));
	this->pieces[2][1].setPosition(sf::Vector2f(231.0f, 491.0f));
	this->pieces[2][2].setPosition(sf::Vector2f(428.0f, 491.0f));
	for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
			this->pieces[i][j].setTexture(texture_blank);
        	this->pieces[i][j].setScale(sf::Vector2f(1.89f, 1.68f));
		}
    }

	current_player = start_player;

	if (current_player == PLAYER_X) {
		text.setString("X playing");
		text.setFillColor(sf::Color::Black);
	} else {
		text.setString("0 playing");
		text.setFillColor(sf::Color::Red);
	}

	return true;
}

void TicTacToe::draw(sf::RenderWindow& window) {
	window.draw(title);
	window.draw(board);
	window.draw(text);
	window.draw(reset);
	window.draw(exit);
	
	for (int row = 0; row < 3; row++)
		for (int column = 0; column < 3; column++)
			window.draw(pieces[row][column]);
}


bool TicTacToe::is_win() {

	// Check rows for a win
	for (int row = 0; row < 3; row++) {
		if (board_model[row][0] == board_model[row][1] && 
			board_model[row][1] == board_model[row][2]) {
			if (board_model[row][0] != BLANK) {
				return true;
			}
		}
	}

	// Check cols for a win
	for (int col = 0; col < 3; col++) {
		if (board_model[0][col] == board_model[1][col] && 
			board_model[1][col] == board_model[2][col]) {
			if (board_model[0][col] != BLANK) {
				return true;
			}
		}
	}

	// Check main diagonal for a win
	if (board_model[0][0] == board_model[1][1] && 
		board_model[1][1] == board_model[2][2]) {
		if (board_model[0][0] != BLANK) {
			return true;
		}
	}

	// Check off-diagonal for a win
	if (board_model[0][2] == board_model[1][1] && 
		board_model[1][1] == board_model[2][0]) {
		if (board_model[0][2] != BLANK) {
			return true;
		}
	}

	return false;
}

bool TicTacToe::are_slots_available() {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			// Slots still available to play
			if (board_model[row][col] == 0) {
				return true;
			}
		}
	}

	return false;
}

void TicTacToe::keyPress(sf::Vector2f pos, sf::RenderWindow& window) {

	// Reset hit?
	if (reset.getGlobalBounds().contains(pos)) {
        win_sound.stop();
        initialize_game(current_player == PLAYER_X ? PLAYER_0 : PLAYER_X);
    }
    
	// Exit hit?
    if (exit.getGlobalBounds().contains(pos)) {
		window.close();
	}

	// All slots played, only reset or exit possible
	if (wait_for_reset) {
		return;
	}
	
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {

			// Check if this piece was clicked
			if (!pieces[row][col].getGlobalBounds().contains(pos)) {
				continue;
			}

			if (board_model[row][col] == 0) {
				pieces[row][col].setTexture(current_player == PLAYER_X ? texture_x : texture_o);

				board_model[row][col] = current_player;

				if (is_win()) {
					wait_for_reset = true;
					text.setString(current_player == PLAYER_X ? "X wins!" : "0 wins!");
					win_sound.play();
				}
				else {
					if (are_slots_available()) {
						// Toggle player
						current_player = current_player == PLAYER_X ? PLAYER_0 : PLAYER_X;
						
						if (current_player == PLAYER_X) {
							text.setString("X playing");
							text.setFillColor(sf::Color::Black);
						} else {
							text.setString("0 playing");
							text.setFillColor(sf::Color::Red);
						}
	
						click_sound.play();
					}
					else {
						wait_for_reset = true;
						text.setString("Draw. Play Again.");
					}
				}
			}
			
		}
	}
}

