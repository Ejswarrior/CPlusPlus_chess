#pragma once
#include "TextInput.h"
#include "Button.h"
#include "Text.h"
#include <SFML/Network.hpp>
#include <format>
#include "HTTPService.h"
#include <sstream>
#include <nlohmann/json.hpp>


struct CreateAccountValues
{
	std::string email;
	std::string name;
	std::string password;
};

class AccountCreatePage
{

private:
	int middleOfPage = 1280 / 2 - 150;

public: 
	TextInput emailInput;
	TextInput passwordInput;
	TextInput nameInput;
	Text createAccountTitle;
	Text emailInputHelperText;
	Text nameInputHelperText;
	Text passwordInputHelperText;
	Button createAccountButton;
	HTTPService httpService;

	bool isCreateAccountPageOpen = true;


	AccountCreatePage() : emailInput{ sf::Vector2f(middleOfPage, 200) }, nameInput{ sf::Vector2f(middleOfPage, 290) }, passwordInput{ sf::Vector2f(middleOfPage, 380) }, 
		createAccountTitle{ 32, sf::Vector2f(middleOfPage + 40, 60), "Create Account" }, emailInputHelperText{16, sf::Vector2f(middleOfPage, 175), "Email"}, 
		nameInputHelperText{ 16, sf::Vector2f(middleOfPage, 265), "Name" }, passwordInputHelperText{ 16, sf::Vector2f(middleOfPage, 355), "Password" }, 
		createAccountButton{ "Submit", sf::Vector2f(middleOfPage, 470), sf::Vector2f(300,48), "Primary" } {

	}

	void checkForKeyboardInput(sf::Event sfmlEvent) {
		emailInput.voidCheckForKeyboardInput(sfmlEvent);
		emailInput.checkForClick(sfmlEvent);
		nameInput.voidCheckForKeyboardInput(sfmlEvent);
		nameInput.checkForClick(sfmlEvent);
		passwordInput.voidCheckForKeyboardInput(sfmlEvent);
		passwordInput.checkForClick(sfmlEvent);

		if (emailInput.inputString.size() == 0 || passwordInput.inputString.size() == 0 || nameInput.inputString.size() == 0) {
			createAccountButton.disableButton();
		}
		else createAccountButton.enableButton();
	}

	void onSubmit() {
			std::string body = std::format("email={}&name={}&password={}", emailInput.inputString, nameInput.inputString, passwordInput.inputString);
			std::ostringstream stream;
			stream << "name=" << nameInput.inputString << "&email=" << emailInput.inputString << "&password=" << passwordInput.inputString;
			sf::Http::Response createAccountResult = httpService.post("/Auth", stream.str());
			if (createAccountResult.getStatus() == sf::Http::Response::Ok)
			{
				// check the contents of the response
				std::cout << createAccountResult.getBody() << std::endl;
			}
			else 
			{ 
				std::cout << "fuck me" << std::endl;
			}
			std::cout << createAccountResult.getStatus() << std::endl;
			std::cout << createAccountResult.getBody() << std::endl;
	}

	void drawPage(sf::RenderWindow& window) {
		emailInput.draw(window);
		passwordInput.draw(window);
		nameInput.draw(window);
		emailInputHelperText.draw(window);
		nameInputHelperText.draw(window);
		passwordInputHelperText.draw(window);
		createAccountTitle.draw(window);
		createAccountButton.draw(window);
	}
};

