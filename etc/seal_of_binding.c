#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
	::configure();
	    alter_identity(([
                Identity_Nouns          : ({ "disc" }),
				Identity_Known_Nouns 	: ({ "seal of binding", "seal", "disc", "glowing disc" }),

        ]));
		
		add_description(({
		({ 'v', 0 }), ({ "are", 0 }), "a",
 

                ({ 'n', 0 }), "."
		}));
		set_craft(Craft_Unearthly);
		set_shape(([
		Shape_Type              : Geometry_Cylinder,
		Shape_Radius			: 1.0,
		Shape_Length            : 0.1,
		
	]));
	add_proportion(([
		Element_Type            : Material_Kedusham,
		Element_Proportion      : 1.0,
		Element_Part            : Part_Bulk,
	]));
		

}