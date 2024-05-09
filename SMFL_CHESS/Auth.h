#pragma once
class Auth
{

private: 
	bool isAuthenticated = false;

public: 

	bool getAuthStatus() {
		return isAuthenticated;
	}


};

