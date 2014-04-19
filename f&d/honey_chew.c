#include <Sinbyen.h>
#include <item.h>

inherit "/std/comestible";

void configure() {
        ::configure();
        set_creator(({ "Kenobi" }));
		alter_identity(([
			Identity_Nouns          : ({ "honey chew", "honey", "chew" }),
		]));
        add_description("A large stick of chewy honey candy.");
        set_comestible_type("food");
        set_food(10);
        set_heal(5);
        set_pleasure(2.00);
        set_portable(True);
        set_consume_message("The firm texture and sweet {{yellow}honey} flavour is enjoyable.");
        set_servings(8);
		add_proportion(([
			Element_Type		: Material_Honey,
			Element_Proportion	: 1.0,
			Element_Part		: Part_Bulk,
			Element_Flags		: Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
		]));
		add_proportion(([
			Element_Type		: Material_Sugar,
			Element_Proportion	: 0.5,
			Element_Part		: Part_Infusion,
			Element_Flags		: Element_Flag_Secondary,
		]));
		add_proportion(([
			Element_Type		: Material_Wheat,
			Element_Proportion	: 0.5,
			Element_Part		: Part_Infusion,
			Element_Flags		: Element_Flag_Secondary,
		]));
}
