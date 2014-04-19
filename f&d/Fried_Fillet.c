#include <Sinbyen.h>
#include <item.h>

inherit "/std/comestible";

void configure() {
        ::configure();
        set_creator(({ "kenobi" }));
        set_comestible_type("food");
        set_pleasure(0.30);
        set_food(30);
        set_portable(True);
        set_consume_message("Crispy and delicious!");
        add_proportion(([
            Element_Type        : Material_Bread,
            Element_Proportion  : 0.2,
            Element_Part        : Part_Coat,
            Element_Flags       : Element_Flag_Secondary | Element_Flag_Provide_Default_Color,
            Element_Color       : "yellow",
        ]));
        add_proportion(([
            Element_Type        : Material_Flesh,
            Element_Proportion  : 1.0,
            Element_Flags       : Element_Flag_Secondary,
        ]));
        add_proportion(([
            Element_Type        : Material_Vinegar,
            Element_Proportion  : 0.01,
            Element_Part        : Part_Coat,
            Element_Flags       : Element_Flag_Secondary,
        ]));
        add_proportion(([
            Element_Type        : Material_Fat,
            Element_Proportion  : 0.3,
            Element_Part        : Part_Infusion,
            Element_Flags       : Element_Flag_Secondary,
        ]));
        add_proportion(([
            Element_Type        : Material_Oil,
            Element_Proportion  : 0.01,
            Element_Part        : Part_Coat,
            Element_Flags       : Element_Flag_Secondary,
            Element_Color       : "clear",
        ]));
}
