#include <Sinbyen.h>
#include <item.h>
#include <autonomon.h>
#include <Enchysi_Daktylion.h>
#include <autonomon.h>
#include <directions.h>
#include <instructor.h>
#include <speech.h>

inherit "/std/item";


private descriptor att_mod;


void ring_do_equip(mapping args) {
	att_mod = args["who"]->add_special_attack(([
		Special_Attack_Name			: "Enraged Arc",
		Special_Attack_Vector       : Vector_Arc,
		Special_Attack_Message		: ({ 0, ({ "sidestep", 0 }), "and", ({ "swing", 0 }), ({ 'r', 0, "axe" }), "with incredible speed and might", }),
		Special_Attack_Type         : ({ "cutting", "fire", "force", }),
		Special_Attack_Skill        : ({ Skill_Axe, Skill_Massive_Blow }),
		Special_Attack_Power        : Special_Attack_Power_Overwhelming,
		Special_Attack_Condition    : Hand_Required,
		Special_Attack_Chance       : Special_Attack_Chance_Profuse,
		Special_Attack_Size			: Special_Attack_Size_Huge,
		Special_Attack_Activity		: 15,
	]));
	
}

void ring_do_unequip(mapping args) {
	args["who"]->remove_special_attack(([
	Special_Attack_Name			: ({ "Enraged Arc" }),
	]));
}

void configure() {
	::configure();
	armour()->set_race("dakshin");
	add_description(({
	
	"The glossy",
	
		Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : Element(([
                    Element_Type                        : Material_Leather,
                    Element_Color                       : "black",
                ])),
		])),
	
	"thigh boots appear to be comfortable and stylish. ",
	"Covering the feet and legs from toe to thigh, the boots magically adjust to",
	"fit the wearer.  For additional protection,",

		Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : Element(([
                    Element_Type                        : Material_Adamantite,
                    Element_Color                       : "black",
                ])),
		])),
	"plates have been inserted between the lining and the leather.",
	
	}));
	armour()->set_armour_type(Armour_Type_Ring);
	armour()->set_armour_style(Armour_Style_Simple);
	set_craft(Craft_Exquisite);
	add_proportion(([
		Element_Type       : Material_Leather,
		Element_Proportion : 0.7,
		Element_Color	   : "black",
	]));
	add_proportion(([
		Element_Type       : Material_Adamantite,
		Element_Proportion : 0.2,
		Element_Part       : Part_Embedment,
		Element_Form       : Form_Plates,
	]));
	add_proportion(([
		Element_Type       : Material_Dweomer,
		Element_Proportion : 0.1,
	]));
	add_property(Prop_Slippery);
	add_hook(Do_Equip_Item, #'ring_do_equip);
	add_hook(Do_Unequip_Item, #'ring_do_unequip);

}
