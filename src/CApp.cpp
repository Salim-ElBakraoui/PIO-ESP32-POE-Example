#include <CApp.h>

CApp::CApp():
    m_pEthernet(&ETH),
    m_uStatus(ST_ALL_CLEARED)
{
    const char* strTag = "CApp::CApp()";

    m_pEthernet->begin();

    ESP_LOGI(strTag, "Connecting to network through Ethernet (DHCP)");

    while(m_pEthernet->localIP()==IPAddress(0,0,0,0));
    mBitsSet(m_uStatus, ST_ETHERNET_INITIALIZED);

    ESP_LOGI(strTag, "Connected to network ! - Local IP: %s", m_pEthernet->localIP().toString().c_str());
}

CApp::CApp(const char* strStaticIP, const char* strGatewayIP, const char* strDnsIP, int iNetMask):
    m_pEthernet(&ETH),
    m_uStatus(ST_ALL_CLEARED)
{

    const char* strTag = "CApp::CApp()";
    IPAddress staticIP;
    staticIP.fromString(strStaticIP);

    IPAddress gatewayIP;
    gatewayIP.fromString(strGatewayIP);

    IPAddress dnsIP;
    dnsIP.fromString(strDnsIP);

    m_pEthernet->begin();
    m_pEthernet->config(
        staticIP,
        gatewayIP,
        IPAddress(iNetMask),
        dnsIP
    );

    ESP_LOGI(strTag, "Connecting to network through Ethernet (Static)");
    while(!m_pEthernet->isConnected());
    mBitsSet(m_uStatus, ST_ETHERNET_INITIALIZED|ST_ETHERNET_STATIC_IP);

    ESP_LOGI(strTag, "Connected to network ! - Local IP: %s", m_pEthernet->localIP().toString().c_str());
}

CApp::~CApp(){

}
void CApp::Run(){
    const char* strTag = "CApp::Run()";

    ESP_LOGI(strTag, "Running App...");
    Serial.printf("Connected to network ! - Local IP: %s", m_pEthernet->localIP().toString().c_str());
    for(;;){
        vTaskDelay(20);
    }
}