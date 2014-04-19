#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

mixed query_room_desc() {
	mixed array content = ({
		({ 'a', this_object() }), "is nearby.",
	});
	return Description(([
	    Description_Type                                : Description_Type_Simple,
	    Description_Order                               : Description_Order_Very_Slightly_Early,
	    Description_Content                             : content,
	]));
}
void configure() {
	::configure();
    alter_identity(([
        Identity_Nouns              : ({ "pew" }),
    ]));
	add_description(Description_Type_Generic);
	set_craft(Craft_Excellent);
	add_proportion(([
		Element_Type                : Material_Oak,
		Element_Proportion          : 1.0,
        Element_Color               : "black",
	]));
	set_shape(([
		Shape_Type                  : Geometry_Box,
		Shape_Length                : 55.0,
		Shape_Width                 : 7.5, 
		Shape_Height                : 11.0,
		Shape_Thickness             : 1.0,
	])); 
}
