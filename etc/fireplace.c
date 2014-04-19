#include <Lobaan_a_Aislynn.h>
#include <item.h>

inherit "/std/item";

mixed query_room_desc() {
	mixed array content = ({
		({ 'a', this_object() }), ", of a piece with a chimney and stone area of the floor,", ({ "are", this_object() }), "set into the wall",
	});
	descriptor fireplace_fire_element = this_object()->query_info("Fireplace_Fire_Element");
	if(fireplace_fire_element && this_object()->query_info("Fireplace_Is_Lit"))
		content += ({
			"roaring with", 'a', Description(({ Description_Type_Element_Name, 0, fireplace_fire_element })),
		});
	return Description(([
	    Description_Type                                : Description_Type_Simple,
	    Description_Order                               : Description_Order_Very_Slightly_Early,
	    Description_Content                             : content,
	]));
}

void configure() {
	::configure();
	thing()->set_thing_type(Thing_Type_Fireplace);
	set_short(0);
	add_description(Description_Type_Generic);
	set_craft(Craft_Good);
	add_proportion(([
	    Element_Type                                    : Material_Brick,
	    Element_Color                                   : "brown",
	]));
}

