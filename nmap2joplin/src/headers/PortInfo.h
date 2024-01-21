#pragma once

#include <string>

class PortInfo {
private:
    std::string port_id;
    std::string service_info;

public:
    std::string getPortId() const;
    void setPortId(const std::string& id);
    std::string getServiceInfo() const;
    void setServiceInfo(const std::string& info);
};
