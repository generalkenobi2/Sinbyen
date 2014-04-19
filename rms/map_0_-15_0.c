#include <Sinbyen.h>
#include <room.h>
#include <Gardagh.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	add_exit(([
                "south"	:	Gardagh_Room("m_20_32_0"),
    ]));
}
