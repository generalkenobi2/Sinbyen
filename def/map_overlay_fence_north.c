#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Fence");

void configure() {
        ::configure();
		set_map_feature_name("fence north");
        set_fence_direction(Direction_North);
		set_fence_direction(Direction_Northwest);
		set_fence_direction(Direction_Northeast);
		add_map_feature_exit_boundary(Direction_North, "fence");
		add_map_feature_exit_boundary(Direction_Northeast, "fence");
		add_map_feature_exit_boundary(Direction_Northwest, "fence");
}
