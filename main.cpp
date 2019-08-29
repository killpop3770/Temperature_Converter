#include <iostream>
#include <string>
#include <windows.h>

namespace flag
{
	bool flag = true;
}

void switchFoo(char);

int WINAPI WinMain(HINSTANCE hInstance,
				HINSTANCE hPrevInstance, 
				LPSTR lpCmdLine, 
				int nCmdShow) 
{
	char CF;
	std::cout << "Input 'q' for quit." << std::endl;
	std::cout << "Input mode of compute(F / C) : ";
	
	while(true)
	{
		std::cin >> CF;
		if(CF == 'C' || CF == 'F') while(flag::flag) switchFoo(CF);
		if(CF == 'q') break;
	}
	
	MessageBox(NULL, "Congratulations!", "Temperature_Converter", MB_OK);
	
	system("pause");
	return 0;
}

void switchFoo(char CF)
{
	std::string tempF, tempC;
	
	switch (CF)
	{
		case 'C':
			std::cout << "Input value in Fahrenheit: ";
			while(true)
			{

					std::cin >> tempF;
					int _tempF = std::stoi(tempF);
					std::cout << "tempF : " << tempF << "\n_tempF : " << _tempF << std::endl;

					if(isdigit(_tempF) == true)
					{
						double _tempC = (_tempF - 32.0) * 5.0 / 9.0;
						std::cout << "Value in Celsius: "<< _tempC << std::endl;
					}
					if(tempF == "break") break;
					if(tempF == "quit") flag::flag = false;
			}
		break;
			
		case 'F':
			std::cout << "Input value in Celsius: ";
			while(true)
			{
				std::cin >> tempC;
				int _tempC = std::stoi(tempC);
				if(tempC == "break") break;
				if(tempC == "quit") flag::flag = false;
				
				if(isdigit(_tempC))
				{
					double _tempF = _tempC * 9.0 / 5.0 + 32.0;
					std::cout << "Value in Fahrenheit: "<< _tempF << std::endl;
				}
			}
		break;	
	}
};
