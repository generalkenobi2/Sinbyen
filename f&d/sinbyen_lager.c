#include <Sinbyen.h>
#include <item.h>

inherit "/std/comestible";

void configure() {
    ::configure();
    alter_identity(([
        Identity_Nouns           : ({ "mug of sinbyen lager", "mug", "beer", "alcohol","lager" }),
    ]));
    add_description("An ice cold mug of sinbyen lager.");
    set_intoxication(4);
    set_heal(1);
    set_drink(10);
    set_servings(4);
    set_comestible_type("drink");
    set_container(Sinbyen_Misc("gnoll_mug"));
    set_consume_message("Ahh, that feels incredible.");
    set_portable(True);
    add_proportion(([
        Element_Type           : Material_Beer,
        Element_Proportion     : 2.0,
    ]));
    add_proportion(([
        Element_Type           : Material_Tin,
        Element_Proportion     : 0.1,
        Element_Flags          : Element_Flag_Secondary,
    ]));
}
