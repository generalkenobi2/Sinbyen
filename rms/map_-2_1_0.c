#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");
inherit Sinbyen_Definition("Map_Area_Base");

void configure() {
	Map_Base::configure();
	set_short("Fontaine's Fishery loading bay");
	remove_exit(Direction_Up);
	remove_exit(Direction_East);
	add_exit(Direction_West);
	add_exit(Direction_North);
	remove_exit(Direction_South);
	set_map_feature_access(Move_Access_Tunnel);
	
}
