// -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;


int main(){

    sf::TcpListener listener;
    listener.listen(53000);


    bool running = true;
    while (running)
    {
        sf::TcpSocket client;
        sf::TcpSocket client1;
        sf::TcpSocket client2;
        
        if (listener.accept(client) == sf::Socket::Done)
        {   
            cout << "New connection received from " << client.getRemoteAddress() << endl;
            while (running)
            {   
                string data;
                sf::Packet packet;
                client.receive(packet);
                packet >> data;	
                cout << data << endl;
                packet.clear();
            }
        }
        if (listener.accept(client1) == sf::Socket::Done)
        {   
            cout << "New connection received from " << client.getRemoteAddress() << endl;
            while (running)
            {   
                string data;
                sf::Packet packet;
                client.receive(packet);
                packet >> data;	
                cout << data << endl;
                packet.clear();
            }
        }
    }

    if (listener.listen(53000) != sf::Socket::Done){
        cout << "ERROR" << endl;
    }

    return 0;

};

//crtl b 0 to swap window 
//ctrl b c to creat a window
//~/.tmux.conf

// void* message {new std::string};
// sf::Packet packet;
// client.receive(packet);
// static_cast<std::string>(*message) = packet.getData();
// std::cout << packet.getData() << std::endl;
// std::cout << static_cast<std::string>(*message) << std::endl; // prints the data
// std::cout << message << std::endl; // prints the memory location
// packet.clear();


// sf::Socket::Status status = client.recieve(packet);
// if(status != sf::Socket::Status::Done){
//   std::cout << "Socket was not done." << '\n' << status;
// }
// else{
//   std::string str;
//   if(!(packet >> str))
//     std::cout << "Failed to read string into packet. Packet size: " << packet.getDataSize(); 
//   else
//     std::cout << str;
// }


// sf::Packet packet;
// client.receive(packet);
// std::string message((char*)packet.getData(),packet.getDataSize());
// std::cout<<message;
// packet.clear();

// sf::Packet packet;
// client.receive(packet);
// std::string message((char*)packet.getData(),packet.getDataSize());
// std::cout<<message;
// packet.clear();


// const void* message;
// (string*)message;

// string data;
// sf::Packet packet;
// client.receive(packet);
// cout << packet <<   endl;
// // message = 
// packet.getData();
// cout << packet.getData() << endl;

// packet >> data;	
// cout << data << endl;
// // cout << message << endl;
// // cout << *message << endl;
// packet.clear();
};
