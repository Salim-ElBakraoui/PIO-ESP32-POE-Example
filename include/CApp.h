#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include "sdkconfig.h"
#include <Arduino.h>

#include <ETH.h>

#include "macros.h"

enum e_Status{
    ST_ALL_CLEARED =                    0x0,
    ST_ETHERNET_INITIALIZED =           0x1,
    ST_ETHERNET_STATIC_IP   =           0x2,
};

class CApp{
private:
    ETHClass*   m_pEthernet;
    uint16_t    m_uStatus;
public:
    CApp();
    CApp(const char* strStaticIP, const char* strGatewayIP, const char* strDnsIP, int iNetMask);
    ~CApp();
    void Run();
};