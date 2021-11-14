#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

main(){

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("192.168.0.47", 53000);
    sf::RenderWindow window(sf::VideoMode(400, 400), "Client");

    bool chatting = true;
    string x;

    cout << "Connected to host" << endl;

    while(chatting)
    {
        cout << "Send a message: ";
        cin >> x;
        cout << x << endl;
        sf::Packet packet;
        packet << x ;
        socket.send(packet);
        packet.clear();

    };
    
};
