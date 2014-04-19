#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Fence");

void configure() {
        ::configure();
		set_map_feature_name("fence west");
        set_fence_direction(Direction_West);
		set_fence_direction(Direction_Southwest);
		set_fence_direction(Direction_Northwest);
		add_map_feature_exit_boundary(Direction_North, "fence");
		add_map_feature_exit_boundary(Direction_Southwest, "fence");
		add_map_feature_exit_boundary(Direction_Northwest, "fence");
}
