#pragma once

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

namespace GraphicsController {

    public ref class CommandSender
    {
    public:
        void SendCommand(array<Byte>^ packet);
    };
}