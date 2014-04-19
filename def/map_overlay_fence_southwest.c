#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Fence");

void configure() {
        ::configure();
		set_map_feature_name("fence southwest");
        set_fence_direction(Direction_Southwest);
		add_map_feature_exit_boundary(Direction_Southwest, "fence");
}
