#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

private descriptor attr_mod;


void gloves_do_equip(mapping args) {
	attr_mod = args["who"]->add_attribute_modifier(([
		Modifier_Index  : Attr_Cha,
		Modifier_Amount : 20,
	]));
	args["who"]->message(({"As",0,({"pull",0}), ({'r', 0, this_object() }),
		"on, they slowly shape themselves to blend with", ({'r', 0, "arms"}),
		"and enhance", ({'r',0,"natural beauty" })}));
}

void gloves_do_unequip(mapping args) {
	args["who"]->remove_attribute_modifier(&attr_mod);
}

void configure() {
	::configure();
	armour()->set_race("kielleth");
	add_description(({
	
	"The glossy",
	
		Description(([
                Description_Type                        : Description_Type_Element_Name,
                Description_Index                       : Element(([
                    Element_Type                        : Material_Leather,
                    Element_Color                       : "black",
                ])),
		])),
	
	"gloves appear to be rather comfortable. ",
	"Covering the hands and forearms from elbow to finger tip, the gloves magically adjust to",
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
	armour()->set_armour_type(Armour_Type_Pair_of_Gloves);
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
	add_hook(Do_Equip_Item, #'gloves_do_equip);
	add_hook(Do_Unequip_Item, #'gloves_do_unequip);

}
