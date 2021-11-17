#include "rfiddata.h"


rfiddata::rfiddata() {
    for(int cnt=0;cnt!=0x80;cnt++)
        datablocks.push_back("00000000");
}

rfiddata::~rfiddata() { }
