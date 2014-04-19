#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Base");

void configure() {
	::configure();
	set_map_feature_name("crimson barracks");
	add_map_feature_realm("CRIMSON_BARRACKS");
}
