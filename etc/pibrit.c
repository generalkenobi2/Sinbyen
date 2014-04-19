#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
	::configure();
	    alter_identity(([
                Identity_Nouns          : ({ "giant fucking pibrit", "pibrit" }),


        ]));		

	add_description(({
		({ 'v', 0 }), ({ "are", 0 }), "a large",
 

                ({ 'n', 0 }), "."
	}));
	
	set_craft(Craft_Excellent);
		set_shape(([
		Shape_Type              : Geometry_Block,
		Shape_Length            : 15.0,
		Shape_Width             : 15.0,
		Shape_Height            : 15.0,
	]));

	add_proportion(([
		Element_Type            : Material_Pibrit,
		Element_Proportion      : 2.0,
	]));
}
