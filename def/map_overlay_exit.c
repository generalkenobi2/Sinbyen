#include <Sinbyen.h>
#include <room.h>
#include <Gardagh.h>

inherit Sinbyen_Definition("Map_Overlay_Base");

void configure() {
        ::configure();
        set_map_feature_name("exit");
		add_map_feature_exits(([
			"south"	:	Gardagh_room("m_20_32_0"),
		]));
}
