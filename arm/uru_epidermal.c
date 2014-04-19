#include <item.h>

inherit "/std/item";

mixed uru_epidermal_can_unequip_item(mapping args, descriptor ctx) {
	return args["force"];
}

void uru_epidermal_do_unequip_item(mapping args, descriptor ctx) {
	if(!in_function("remove", this_object()))
		remove();
}

void configure() {
	::configure();
	alter_identity(Identity_Nouns, ({ "plating layer", "layer" }));
	add_description(Description_Type_Generic);
	set_craft(Craft_Exquisite);
	armour()->set_armour_type(Armour_Type_Epidermal);
	armour()->set_autonomon_adapt(True);
	armour()->set_ablative(0.01);
	add_proportion(([
		Element_Type         : Material_Uru,
		Element_Proportion   : 1.0,
		Element_Color        : Null,
	]));
	add_hook(Can_Unequip_Item, #'uru_epidermal_can_unequip_item);
	add_hook(Can_Unequip_Item, #'uru_epidermal_can_unequip_item);
	add_hook(Do_Unequip_Item, #'uru_epidermal_do_unequip_item);
}

status query_externally_visible(object who) {
	return False;
}

status query_externally_touchable(object who) {
	return False;
}
