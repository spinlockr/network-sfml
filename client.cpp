#include <SFML/Network.hpp>

main(){

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("192.168.0.47", 53000);
    sf::RenderWindow window(sf::VideoMode(400, 400), "GAME X");

    
};