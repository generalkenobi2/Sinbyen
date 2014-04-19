#include <Sinbyen.h>
#include <item.h>

inherit "/std/comestible";

void configure() {
    ::configure();
    alter_identity(([
        Identity_Nouns           : ({ "mug of beer", "mug", "beer", "alcohol" }),
    ]));
    add_description("An ice cold mug of refreshing beer.");
    set_intoxication(4);
    set_heal(1);
    set_servings(4);
    set_drink(8);
    set_comestible_type("drink");
    set_container(Sinbyen_Misc("gnoll_mug"));
    set_consume_message("Ahh, that feels good.");
    set_portable(True);
    add_proportion(([
        Element_Type           : Material_Beer,
        Element_Proportion     : 1.0,
    ]));
    add_proportion(([
        Element_Type           : Material_Tin,
        Element_Proportion     : 0.1,
        Element_Flags          : Element_Flag_Secondary,
    ]));
}
