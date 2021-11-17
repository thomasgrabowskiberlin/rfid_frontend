#include "misc.h"



void msgHandler( QtMsgType type, const char* msg )
{
    const char symbols[] = { 'I', 'E', '!', 'X' };
    QString output = QString("[%1] %2").arg( symbols[type] ).arg( msg );


    std::cerr << output.toStdString() << std::endl;
    if( type == QtFatalMsg ) abort();
}
