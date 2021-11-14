// -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class ClientObj
{
    
    public: 

        // sf::RenderWindow window;
        int clientID = 0;

        ClientObj(){    
            // sf::RenderWindow* window = new window(sf::VideoMode(400, 400), "GAME X");
            sf::RenderWindow window(sf::VideoMode(400, 400), "GAME X");
        };
    
        void gameLoop()
        {

            while(window.isOpen())
            {
                sf::Event Event;

                while(window.pollEvent(Event))
                {
                    if(Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    else if(Event.key.code == sf::Keyboard::Space)
                    {
                        cout << clientID << endl;
                    }
                }
            
                // window->draw();
                window.display();
                window.clear();
            }

        };
};


int main(){

    sf::TcpListener listener;
    listener.listen(53000);

    bool running = true;
    // ClientObj* clients[10];
    int totalClients = 0;
    int clientNum = 0;

    while (running)
    {
        sf::TcpSocket client;
        if (listener.accept(client) == sf::Socket::Done)
        {   
            std::cout << "New connection received from " << client.getRemoteAddress() << std::endl;
            totalClients += 1;
            clientNum += 1;        
            ClientObj* client = new ClientObj();
            client->clientID = clientNum;
            client->gameLoop();
        }
    }

    if (listener.listen(53000) != sf::Socket::Done){
        cout << "ERROR" << endl;
    }

    return 0;

};