#include <item.h>
#include <energy.h>
#include <Sinbyen.h>


inherit "/std/comestible";

status drink_consumed(object who, object what) {
        who->add_energy_amount(Energy_Agonistic, 90 + random(50));
}



void configure() {
    ::configure();
    alter_identity(([
        Identity_Type           : Identity_Type_Custom,
        Identity_Nouns          : ({ "raging iyiyik", "iyiyik","alcohol"}),
        Identity_Color          : "dark red",
    ]));
    add_description(({
        ({ 'v', 0 }), ({ "are", 0 }), "a large mug full of a dark red liquid",
    }));
    add_description(({
        'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as a raging iyiyik, a powerful alcoholic beverage made by mixing demonic bloods with strong spirits",
    }));
    add_description(({
        "a raging iyiyik generally enrages the consumer and drastically increases their strength for a time",
    }));
    set_intoxication(semirandom(50, 0.75));
    set_food(15);
    set_drink(15);
    set_comestible_type("drink");
    set_shape(Common_Shape_Full_Mug);
    set_container(Sinbyen_Misc("gnoll_mug"));
    set_portable(True);
    set_speed_level(3 + random(3));
    set_speed_duration(semirandom(600));
    set_speed_type("rage");
    set_speed_description("{{dark red}demonic influences}");
    set_consume_func(#'drink_consumed);
    set_attribute_modifier(Attr_Str, 50);
    set_attribute_modifier_flags(Modifier_Flag_Automatic_Messages);
    set_consume_message(([
        Message_Content         : ({
            0, ({ "feel", 0 }), "the alcohol burns madly as it goes down, filling you with an abnormal sense of {{dark red}anger}",
        }),
        Message_Senses          : Message_Sense_Tactile,
    ]));
    add_proportion(([
        Element_Type            : Material_Blood,
        Element_Proportion      : 0.25,
        Element_Color           : "red",
        Element_Race            : "demon",
    ]));
    add_proportion(([
        Element_Type            : Material_Alcohol,
        Element_Proportion      : 0.75,
        Element_Color           : "clear",
        Element_Flags           : Element_Flag_Blend,
    ]));
    add_proportion(([
        Element_Type            : Material_Tin,
        Element_Proportion      : 0.1,
        Element_Part            : Part_Coat,
        Element_Color           : "brown",
        Element_Flags           : Element_Flag_Blend,
    ]));
}
