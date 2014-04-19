#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Definition("Map_Overlay_Fence");

void configure() {
        ::configure();
		set_map_feature_name("fence south");
        set_fence_direction(Direction_South);
		set_fence_direction(Direction_Southwest);
		set_fence_direction(Direction_Southeast);
		add_map_feature_exit_boundary(Direction_South, "fence");
		add_map_feature_exit_boundary(Direction_Southwest, "fence");
		add_map_feature_exit_boundary(Direction_Southeast, "fence");
}
