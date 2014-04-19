#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

mixed query_room_desc() {
	mixed array content = ({
		({ 'a', this_object() }), "is set against the wall near a window.",
	});
	return Description(([
	    Description_Type                                : Description_Type_Simple,
	    Description_Order                               : Description_Order_Very_Slightly_Early,
	    Description_Content                             : content,
	]));
}
void configure() {
	::configure();
	thing()->set_thing_type(Thing_Type_Bed);
	set_short(0);
	add_description(Description_Type_Generic);
	set_craft(Craft_Excellent);
	add_proportion(([
	    Element_Type                                    : Material_Pine,
	]));
	set_shape(([
		Shape_Type               : Geometry_Box,
		Shape_Length             : 22.0,
		Shape_Width              : 6.5, 
		Shape_Height             : 4.5,
		Shape_Thickness          : 1.0,
	])); 
}
