#include <Grinning_Cat.h>
#include <item.h>

inherit "/std/comestible";

void configure() {
        ::configure();
        set_creator(({ "Kenobi" }));
        set_restore_endurance(1);
        set_comestible_type("drink");
        set_drink(30);
        set_pleasure(0.50);
        set_container(LS_Container("bottle"));
        set_servings(4);
        set_portable(True);
		add_proportion(([
			Element_Type		: Material_Sugar,
			Element_Proportion	: 0.3,
			Element_Part		: Part_Infusion,
		]));
		add_proportion(([
			Element_Type		: Material_Glass,
			Element_Proportion	: 0.1,
			Element_Flags		: Element_Flag_Suppress_Material_Adjectives | Element_Flag_Secondary,
		]));
		set_readable(({ 0, "label" }), Skill_Norska, 
			"//  Thank you for purchasing a Fizzy. //\n"
			"//  All of us at Fizzy LTD hope that  //\n"
			"//  you enjoy our product as much as  //\n"
			"//       we enjoyed making it!        //");
}
