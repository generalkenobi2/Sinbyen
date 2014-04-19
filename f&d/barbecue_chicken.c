#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Barbecue");

void configure() {
        ::configure();
		add_description("a large barbecued chicken leg");
		alter_identity(([
			Identity_Nouns          : ({ "barbecued chicken leg", "chicken", "leg"}),
		]));
        set_food(24);
        set_heal(5);
		set_shape(([
			Shape_Type              : Geometry_Block,
			Shape_Length            : 1.0,
			Shape_Width				: 0.5,
			Shape_Height			: 0.5,
		]));
        set_servings(1);
}
