#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("the foyer of Sinbyen's Jailhouse");
	add_exit(Direction_East);
	add_exit(Direction_West);
	
	add_description(([
		Description_Type                                : Description_Type_Simple,
		Description_Content                             : ({
			"this is a corridor in the Sinbyen jail house",
		}),
		Description_Order                               : Description_Order_Early,
	]));
	
}
