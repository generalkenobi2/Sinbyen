#include <Grinning_Cat.h>
#include <Sinbyen.h>
#include <item.h>

inherit Sinbyen_Comestible("Mammoth");

void configure() {
        ::configure();
		alter_identity(([
			Identity_Nouns          : ({ "mammoth salad", "salad" }),
		]));
		add_description(({"a large salad with",

							Description(([
								Description_Type    : Description_Type_Element_Name,
								Description_Index   : Material_Lettuce,
								Description_Flags   : Description_Flag_Noun,
							])),
						",",
							Description(([
								Description_Type    : Description_Type_Element_Name,
								Description_Index   : Material_Tomato,
								Description_Flags   : Description_Flag_Noun,
							])),
						", and",
							Description(([
								Description_Type    : Description_Type_Element_Name,
								Description_Index   : Material_Cheese,
								Description_Flags   : Description_Flag_Noun,
							])),
						", mixed in.",
		}));
		add_description(({"it is topped with hard",
		
							Description(([
								Description_Type    : Description_Type_Element_Name,
								Description_Index   : Material_Bread,
								Description_Flags   : Description_Flag_Noun,
							])),
						"and bits of {{dark red}mammoth steak}",
		}));
        set_consume_message("The salad is crisp and refreshing.");
        set_servings(6);
		add_proportion(([
			Element_Type		: Material_Bread,
			Element_Proportion	: 0.5,
			Element_Flags		: Element_Flag_Secondary,
		]));
		add_proportion(([
			Element_Type		: Material_Lettuce,
			Element_Proportion	: 1.5,
			Element_Flags		: Element_Flag_Provide_Default_Color | Element_Flag_Suppress_Material_Adjectives,
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
		add_proportion(([
			Element_Type		: Material_Ceramic,
			Element_Proportion	: 0.5,
			Element_Part		: Part_Backing,
			Element_Flags		: Element_Flag_Secondary,
		]));
}
