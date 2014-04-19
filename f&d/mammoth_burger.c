#include <Grinning_Cat.h>
#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Mammoth");

void configure() {
        ::configure();
		alter_identity(([
			Identity_Nouns          : ({ "mammoth burger", "burger" }),
		]));
        add_description("A large mammoth burger topped with {{green}lettuce}, {{bright red}tomato}, {{yellow}cheese}, {{dark red}mammoth bacon}, and wrapped in a wheat bun");
        set_consume_message("The burger is amazing, what a blend of flavours!");
        set_servings(6);
		add_proportion(([
			Element_Type		: Material_Bread,
			Element_Proportion	: 0.5,
			Element_Part		: Part_Wrap,
		]));
		add_proportion(([
			Element_Type		: Material_Lettuce,
			Element_Proportion	: 0.5,
			Element_Flags		: Element_Flag_Secondary,
		]));
		add_proportion(([
			Element_Type		: Material_Tomato,
			Element_Proportion	: 0.5,
			Element_Flags		: Element_Flag_Secondary,
		]));
		add_proportion(([
			Element_Type		: Material_Cheese,
			Element_Proportion	: 0.5,
			Element_Flags		: Element_Flag_Secondary,
		]));
}
