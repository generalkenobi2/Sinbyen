#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
	::configure();
	add_description(Description_Type_Generic);
	add_description(([
			Description_Type    : Description_Type_Subject_Description,
			Description_Index   : Sinbyen_Definition("subject_crimson_craftmark"),
			Description_Order   : Description_Order_Early,
		]));
	set_craft(Craft_Exquisite);
	add_proportion(([
		Element_Type              : Material_Steel,
		Element_Proportion        : 3.0,
		Element_Color             : "black",
	]));
	add_proportion(([
		Element_Type              : Material_Uru,
		Element_Proportion        : 1.0,
		Element_Flags			  : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
	]));
	add_proportion(([
		Element_Type              : Material_Leather,
		Element_Proportion        : 0.15,
		Element_Part			  : Part_Underlayer,
	]));
}
