#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("The Raging Gnoll Tavern");
	add_exit(Direction_East);
	add_exit(Direction_West);
	add_exit(Direction_South);
	add_exit(Direction_Southwest);	
	add_exit(Direction_Southeast);
}
