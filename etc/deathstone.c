#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
	::configure();
	    alter_identity(([
                Identity_Nouns          : ({ "headstone", "stone" }),

        ]));		
		add_abstract_item(([
			Abstract_Item_Identity           : ([
				Identity_Nouns               : ({ "disc" }),
				Identity_Known_Nouns		 : ({ "seal of binding", "seal", "glowing disc", "disc" }),
				Identity_Adjectives			 : ({ "glowing" }),
			]),		
			Abstract_Item_Descriptions       : ({
				({ ({ 't', 0 }), "flickers {{flickering bright white}dimly}." }),
				({ 0, "hovers less than half a dimin above the stone." }),
			}),
			Abstract_Item_Attach_Description : ([
				Description_Type             : Description_Type_Simple,
				Description_Content          : ({
				"There is",	({ 'a', 0 }), "floating just above the stone",
				}),
				Description_Order            : Description_Order_Middle,
			]),
			Abstract_Item_Elements           : ({
				([
					Element_Type             : Material_Kedusham,
					Element_Part             : Part_Bulk,
					Element_Color			 : "bright white",
				])
			}),
		]));
		
	add_description(({
		({ 'v', 0 }), ({ "are", 0 }), "a large",
 

                ({ 'n', 0 }), "."
	}));
	
	set_craft(Craft_Excellent);
	set_readable(({ 0, "writing", "word", "message" }), Skill_Norska, "DHARMA INITIATIVE\nCANNED FOOD INSIDE\nPRESS SEAL, RECEIVE BACON");
	set_shape(([
		Shape_Type              : Geometry_Block,
		Shape_Length            : 15.0,
		Shape_Width             : 8.0,
		Shape_Height            : 3.0,
	]));
	add_proportion(([
		Element_Type            : Material_Onyx,
		Element_Proportion      : 0.9,
		Element_Part             : Part_Bulk,

	]));
	
	add_proportion(([
		Element_Type            : Material_Gold,
		Element_Proportion      : 0.1,
		Element_Part             : Part_Inlay,

	]));
}
