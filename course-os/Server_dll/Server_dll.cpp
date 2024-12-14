#include "Server_dll.h"

BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}

SOCKET CreateServerSocket()
{
    SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    listen(server_socket, 5);

    return server_socket;
}

SOCKET ConnectToClient(SOCKET server_socket)
{
    SOCKET client_socket = accept(server_socket, nullptr, nullptr);

    return client_socket;
}

void RecieveMessageFromClient(SOCKET client_socket)
{
    char msg_buffer[1024] = { 0 };
    recv(client_socket, msg_buffer, sizeof(msg_buffer), 0);
    std::cout << "Message from client: " << msg_buffer << std::endl;
}

void runServer()
{
    SOCKET socket = CreateServerSocket();
    RecieveMessageFromClient(ConnectToClient(socket));
    closesocket(socket);
}