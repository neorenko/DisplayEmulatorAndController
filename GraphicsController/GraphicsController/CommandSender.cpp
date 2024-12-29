#include "CommandSender.h"

namespace GraphicsController {

    void CommandSender::SendCommand(array<Byte>^ packet)
    {
        // Ініціалізація сокету
        UdpClient^ udpClient = gcnew UdpClient();
        IPEndPoint^ serverEndpoint = gcnew IPEndPoint(IPAddress::Parse("127.0.0.1"), 12345);

        try
        {
            udpClient->Send(packet, packet->Length, serverEndpoint);
        }
        finally
        {
            udpClient->Close();
        }
    }
}