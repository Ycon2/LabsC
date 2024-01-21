#include "PortInfo.h"

std::string PortInfo::getPortId() const {
    return port_id;
}

void PortInfo::setPortId(const std::string& id) {
    port_id = id;
}

std::string PortInfo::getServiceInfo() const {
    return service_info;
}

void PortInfo::setServiceInfo(const std::string& info) {
    service_info = info;
}
